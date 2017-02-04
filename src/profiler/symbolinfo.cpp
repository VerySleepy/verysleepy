/*=====================================================================
symbolinfo.cpp
--------------
File created by ClassTemplate on Sat Mar 05 19:10:20 2005

Copyright (C) Nicholas Chapman

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

http://www.gnu.org/copyleft/gpl.html..
=====================================================================*/
#include "symbolinfo.h"
#include "../wxProfilerGUI/profilergui.h"

#include "../utils/stringutils.h"
#include "../utils/osutils.h"
#include <windows.h>
#include <psapi.h>
#include "../utils/dbginterface.h"
#include <iostream>
#include <algorithm>
#include <shlwapi.h>
#include "../utils/except.h"
#include "../appinfo.h"

SymLogFn *g_symLog = NULL;

struct SymbolInfoContext
{
	SymbolInfo* syminfo;
	DbgHelp* dbgHelp;
};

BOOL CALLBACK EnumModules(
	PCWSTR   ModuleName,
	DWORD64 BaseOfDll,
	PVOID   UserContext )
{
	SymbolInfoContext* context = static_cast<SymbolInfoContext*>(UserContext);

	HMODULE hMod;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, ModuleName, &hMod);

	Module mod((PROFILER_ADDR)BaseOfDll, ModuleName, context->dbgHelp);
	context->syminfo->addModule(mod);

	return TRUE;
}


SymbolInfo::SymbolInfo()
:	process_handle(NULL)
{
}

BOOL CALLBACK symCallback(HANDLE WXUNUSED(hProcess), ULONG ActionCode, ULONG64 CallbackData, ULONG64 WXUNUSED(UserContext))
{
	switch(ActionCode)
	{
	case CBA_DEBUG_INFO:
		if (g_symLog)
		{
			g_symLog((const wchar_t*)CallbackData);
		}
		return TRUE;
	default:
		return FALSE;
	}
}

void symWineCallback(const char *msg)
{
#ifdef _DEBUG
	OutputDebugStringA(msg);
#endif

	if (!msg || !*msg)
		return;

	static bool newline = true;
	if (g_symLog)
	{
		if (newline)
			g_symLog(L"WINE: ");
		newline = msg[strlen(msg) - 1] == '\n';

		wchar_t tmp[2048];
		MultiByteToWideChar(CP_ACP, 0, msg, -1, tmp, sizeof(tmp));
		g_symLog(tmp);
	}
}

void SymbolInfo::loadSymbolsUsing(DbgHelp* dbgHelp, const std::wstring& sympath)
{
	if (!dbgHelp->Loaded)
	{
		if (g_symLog)
		{
			g_symLog(dbgHelp->Name); g_symLog(L" is not loaded, skipping.\n");
		}
		return;
	}

	DWORD options = dbgHelp->SymGetOptions();

#ifdef _WIN64
	if(!is64BitProcess) {
		options |= SYMOPT_INCLUDE_32BIT_MODULES;
	}
#endif

	options |= SYMOPT_LOAD_LINES | SYMOPT_DEBUG;

	dbgHelp->SymSetOptions(options);

	if (dbgHelp->SymSetDbgPrint)
		dbgHelp->SymSetDbgPrint(&symWineCallback);

	for( int n=0;n<4;n++ )
	{
		wenforce(dbgHelp->SymInitializeW(process_handle, L"", FALSE), "SymInitialize");

		// Hook the debug output, so we actually can provide a clue as to
		// what's happening.
		dbgHelp->SymRegisterCallbackW64(process_handle, symCallback, NULL);

		// Add our PDB search paths.
		if (dbgHelp == &dbgHelpMs)
			wenforce(dbgHelp->SymSetSearchPathW(process_handle, sympath.c_str()), "SymSetSearchPathW");

		if (modules.empty())
		{
			// Load symbol information for all modules.
			// Normally SymInitialize would do this, but we instead do it ourselves afterwards
			// so that we can hook the debug output for it.
			wenforce(dbgHelp->SymRefreshModuleList(process_handle), "SymRefreshModuleList");

			SymbolInfoContext context;
			context.syminfo = this;
			context.dbgHelp = dbgHelp;

			wenforce(dbgHelp->SymEnumerateModulesW64(process_handle, EnumModules, &context), "SymEnumerateModules64");
		}
		else
		{
			// This is a secondary dbgHelp, so just complement debug
			// information for modules that have none.
			
			for (size_t n=0;n<modules.size();n++)
			{
				Module &mod = modules[n];

				IMAGEHLP_MODULEW64 info;
				info.SizeOfStruct = sizeof(info);
				if (!mod.dbghelp->SymGetModuleInfoW64(process_handle, mod.base_addr, &info))
					continue;

				// If we have a module with no symbol information from the previous (MS) dbghelp,
				// let the current one handle it instead.
				if (info.SymType == SymNone)
				{
					DWORD64 ret = dbgHelp->SymLoadModuleExW(process_handle, NULL,
						info.ImageName, info.ModuleName, info.BaseOfImage, info.ImageSize,
						NULL, 0);
					if (ret)
						mod.dbghelp = dbgHelp;
				}
			}
		}

		if (!modules.empty())
			break;

		// Sometimes the module enumeration will fail (no error code, but no modules
		// will be returned). If we try again a little later it seems to work.
		// I suspect this may be if we try and enum modules too early on, before the process
		// has really had a chance to 'get going'.
		// Perhaps a better solution generally would be to manually load module symbols on demand,
		// as each sample comes in? That'd also solve the problem of modules getting loaded/unloaded
		// mid-profile. Yes, I'll probably do that some day.
		Sleep(100);
		dbgHelp->SymCleanup(process_handle);
	}
}

void SymbolInfo::loadSymbols(HANDLE process_handle_, bool download)
{
	process_handle = process_handle_;

	wxBusyCursor busy;

	is64BitProcess = Is64BitProcess(process_handle);

	std::wstring sympath;
	{
		// Add the program's own directory to the search path.
		// Useful if someone's copied the EXE and PDB to a different machine or location.
		wchar_t szExePath[MAX_PATH] = L"";
		DWORD pathsize = MAX_PATH;
		BOOL gotImageName = FALSE;
#ifdef _WIN64
		// GetModuleFileNameEx doesn't always work across 64->32 bit boundaries.
		// Use QueryFullProcessImageName if we have it.
		{
			typedef BOOL WINAPI QueryFullProcessImageNameFn(HANDLE hProcess, DWORD dwFlags, LPTSTR lpExeName, PDWORD lpdwSize);

			QueryFullProcessImageNameFn *fn = (QueryFullProcessImageNameFn *)GetProcAddress(GetModuleHandle(L"kernel32"), "QueryFullProcessImageNameW");
			if (fn)
				gotImageName = fn(process_handle, 0, szExePath, &pathsize);
		}
#endif

		if (!gotImageName)
			gotImageName = GetModuleFileNameEx(process_handle, NULL, szExePath, pathsize);

		if (gotImageName)
		{
			// Convert the EXE path to its containing folder and append the
			// resulting folder to the symbol search path.
			wchar_t *p = wcsrchr(szExePath, '\\');

			if (p != NULL)
			{
				*p = '\0';
				sympath += std::wstring(L";") + szExePath;
			}
		}

		prefs.AdjustSymbolPath(sympath, download);
	}

	loadSymbolsUsing(&dbgHelpMs, sympath);
	loadSymbolsUsing(getGccDbgHelp(), sympath);

	if (g_symLog)
		g_symLog(L"\nFinished.\n");
	sortModules();
}

DbgHelp* SymbolInfo::getGccDbgHelp()
{
	if (prefs.UseWine())
	{
#ifdef _WIN64
		// We can't use the regular dbghelpw to profile 32-bit applications,
		// as it's got compiled-in things that assume 64-bit. So we instead have
		// a special Wow64 build, which is compiled as 64-bit code but using 32-bit
		// definitions. We load that instead.
		if (!is64BitProcess)
			return &dbgHelpWineWow64;
		else
#endif
			return &dbgHelpWine;
	}
	else
		return &dbgHelpDrMingw;
}

SymbolInfo::~SymbolInfo()
{
	//------------------------------------------------------------------------
	//clean up
	//------------------------------------------------------------------------
	if ( process_handle )
	{
		DbgHelp *gcc = getGccDbgHelp();
		if (gcc->Loaded && !gcc->SymCleanup(process_handle))
		{
			//error
		}

		if (dbgHelpMs.Loaded && !dbgHelpMs.SymCleanup(process_handle))
		{
			//error
		}

		process_handle = NULL;
	}
}

Module *SymbolInfo::getModuleForAddr(PROFILER_ADDR addr)
{
	if(modules.empty())
		return NULL;

	if(addr < modules[0].base_addr)
		return NULL;

	for(unsigned int i=1; i<modules.size(); ++i)
		if(addr < modules[i].base_addr)
			return &modules[i-1];

	//assign any addresses past the base of the last module to the last module.
	//NOTE: this is not strictly correct, but without the sizes of the modules, a decent way of doing things.
	return &modules[modules.size() - 1];
}

const std::wstring SymbolInfo::getModuleNameForAddr(PROFILER_ADDR addr)
{
	Module *mod = getModuleForAddr(addr);
	if (mod)
		return mod->name;
	else
		return L"";
}

void SymbolInfo::addModule(const Module& module)
{
	modules.push_back(module);
}

void SymbolInfo::sortModules()
{
	struct Sorter {
		bool operator() (const Module& a, const Module& b) const {
			return a.base_addr < b.base_addr;
		}
	};
	std::sort(modules.begin(), modules.end(), Sorter());
}

const std::wstring SymbolInfo::getProcForAddr(PROFILER_ADDR addr,
											  std::wstring& procfilepath_out, int& proclinenum_out)
{
	procfilepath_out = L"";
	proclinenum_out = 0;

	Module *mod = getModuleForAddr(addr);
	DbgHelp *dbgHelp = mod ? mod->dbghelp : &dbgHelpMs;

	unsigned char buffer[1024];

	//blame MS for this abomination of a coding technique
	SYMBOL_INFOW* symbol_info = (SYMBOL_INFOW*)buffer;
	symbol_info->SizeOfStruct = sizeof(SYMBOL_INFOW);
	symbol_info->MaxNameLen = ((sizeof(buffer) - sizeof(SYMBOL_INFOW)) / sizeof(WCHAR)) - 1;

	DWORD64 displacement = 0;
	BOOL result = dbgHelp->SymFromAddrW(process_handle, (DWORD64)addr, &displacement, symbol_info);

	if(!result)
	{
		wchar_t buf[256];
#if defined(_WIN64)
		if(is64BitProcess)
			swprintf(buf, 256, L"[%016llX]", addr);
		else
			swprintf(buf, 256, L"[%08X]", unsigned __int32(addr));
#else
		swprintf(buf, 256, L"[%08X]", addr);
#endif
		return buf;
	}

	//------------------------------------------------------------------------
	//lookup proc file and line num
	//------------------------------------------------------------------------
	getLineForAddr(addr, procfilepath_out, proclinenum_out);

	return symbol_info->Name;
}

void SymbolInfo::getLineForAddr(PROFILER_ADDR addr, std::wstring& filepath_out, int& linenum_out)
{
	Module *mod = getModuleForAddr(addr);
	DbgHelp *dbgHelp = mod ? mod->dbghelp : &dbgHelpMs;

	DWORD displacement;
	IMAGEHLP_LINEW64 lineinfo;
	ZeroMemory(&lineinfo, sizeof(lineinfo));
	lineinfo.SizeOfStruct = sizeof(IMAGEHLP_LINEW64);
	BOOL result = dbgHelp->SymGetLineFromAddrW64(process_handle, (DWORD64)addr, &displacement, &lineinfo);

	if(result)
	{
		filepath_out = lineinfo.FileName;
		linenum_out = lineinfo.LineNumber;
	}
	else
	{
		filepath_out = L"[unknown]";
		linenum_out = 0;
	}
}

std::wstring SymbolInfo::saveMinidump()
{
#ifdef _WIN64
	if (!Is64BitProcess(process_handle))
	{
		wxLogWarning(
			L"Warning: minidumps of 32-bit processes saved by 64-bit processes will most likely not be saved correctly.\n"
			L"Use the 32-bit version of " _T(APPNAME) L" to profile 32-bit processes if a minidump needs to be included."
		);
	}
#endif

	wxFile f;
	std::wstring dumppath = wxFileName::CreateTempFileName(wxEmptyString, &f);
	wenforce(dbgHelpMs.MiniDumpWriteDump(
		process_handle,
		GetProcessId(process_handle),
		(HANDLE)_get_osfhandle(f.fd()),
		MiniDumpNormal,
		NULL, NULL, NULL), "MiniDumpWriteDump");
	f.Close();
	return dumppath;
}
