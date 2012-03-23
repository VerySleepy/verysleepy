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

SymLogFn *g_symLog = NULL;

BOOL CALLBACK EnumModules(
    PCWSTR   ModuleName, 
    DWORD64 BaseOfDll,  
    PVOID   UserContext )
{
	SymbolInfo* syminfo = static_cast<SymbolInfo*>(UserContext);

	HMODULE hMod;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, ModuleName, &hMod);

	Module mod((PROFILER_ADDR)BaseOfDll, ModuleName, &dbgHelpMs);
	syminfo->addModule(mod);

    return TRUE;
}


SymbolInfo::SymbolInfo()
:	process_handle(NULL)
{
}

BOOL CALLBACK symCallback(HANDLE hProcess, ULONG ActionCode, ULONG64 CallbackData, ULONG64 UserContext)
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
	if (g_symLog)
	{
		wchar_t tmp[2048];
		MultiByteToWideChar(CP_ACP, 0, msg, -1, tmp, sizeof(tmp));
		g_symLog(L"WINE: ");
		g_symLog(tmp);
	}
}

void SymbolInfo::loadSymbols(HANDLE process_handle_, bool download)
{
	process_handle = process_handle_;

	wxBusyCursor busy;

	is64BitProcess = Is64BitProcess(process_handle);

	DWORD options = dbgHelpMs.SymGetOptions(); 

#ifdef _WIN64
	if(!is64BitProcess) {
		options |= SYMOPT_INCLUDE_32BIT_MODULES; 
	}
#endif

	options |= SYMOPT_LOAD_LINES | SYMOPT_DEBUG;

	dbgHelpMs.SymSetOptions(options); 
	dbgHelpGcc.SymSetOptions(options); 
#ifdef _WIN64
	dbgHelpGccWow64.SymSetOptions(options);
#endif

	std::wstring sympath;

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

		QueryFullProcessImageNameFn *fn = (QueryFullProcessImageNameFn *)GetProcAddress(GetModuleHandle(L"kernel32"),"QueryFullProcessImageNameW");
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

	// Add the symbol server if enabled.
	if (prefs.useSymServer)
	{
		sympath += L";SRV*";
		sympath += prefs.symCacheDir;
		if ( download )
			sympath += std::wstring(L"*") + prefs.symServer;
	}


	for( int n=0;n<4;n++ )
	{
		if (!dbgHelpMs.SymInitializeW(process_handle, L"", FALSE))
		{
			DWORD error = GetLastError();
			throw SymbolInfoExcep(L"SymInitialize failed.");
		}

		// Hook the debug output, so we actually can provide a clue as to
		// what's happening.
		dbgHelpMs.SymRegisterCallbackW64(process_handle, symCallback, NULL);

		// Add our PDB search paths.
		if (!dbgHelpMs.SymSetSearchPathW(process_handle, sympath.c_str()))
		{
			DWORD error = GetLastError();
			throw SymbolInfoExcep(L"SymSetSearchPath failed.");
		}

		// Load symbol information for all modules.
		// Normally SymInitialize would do this, but we instead do it ourselves afterwards
		// so that we can hook the debug output for it.
		if (!dbgHelpMs.SymRefreshModuleList(process_handle))
		{
			DWORD error = GetLastError();
			throw SymbolInfoExcep(L"SymRefreshModuleList failed.");
		}

		if (!dbgHelpMs.SymEnumerateModulesW64(process_handle, EnumModules, this))
			throw SymbolInfoExcep(L"SymEnumerateModules64 failed.");

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
		dbgHelpMs.SymCleanup(process_handle);
	}

	DbgHelp *gcc = &dbgHelpGcc;
#ifdef _WIN64
	// We can't use the regular dbghelpw to profile 32-bit applications,
	// as it's got compiled-in things that assume 64-bit. So we instead have
	// a special Wow64 build, which is compiled as 64-bit code but using 32-bit
	// definitions. We load that instead.
	if (!is64BitProcess)
		gcc = &dbgHelpGccWow64;
#endif

	// Now that we've loaded all the modules and debug info for the regular stuff,
	// we initialize the GCC dbghelp and let it have a go at the ones we couldn't do.
	if (!gcc->SymInitializeW(process_handle, NULL, FALSE))
	{
		DWORD error = GetLastError();
		throw SymbolInfoExcep(L"SymInitialize failed.");
	}

	gcc->SymSetDbgPrint(&symWineCallback);

	for (size_t n=0;n<modules.size();n++)
	{
		Module &mod = modules[n];

		IMAGEHLP_MODULEW64 info;
		info.SizeOfStruct = sizeof(info);
		if (!dbgHelpMs.SymGetModuleInfoW64(process_handle, mod.base_addr, &info))
			continue;
		
		// If we have a module with no symbol information from the MS dbghelp,
		// let the gcc one handle it instead.
		if (info.SymType == SymNone)
		{
			gcc->SymLoadModuleExW(process_handle, NULL, 
				info.ImageName, info.ModuleName, info.BaseOfImage, info.ImageSize,
				NULL, 0);
			mod.dbghelp = gcc;
		}
	}

	if (g_symLog)
		g_symLog(L"\nFinished.\n");
	sortModules();
}

SymbolInfo::~SymbolInfo()
{
	//------------------------------------------------------------------------
	//clean up
	//------------------------------------------------------------------------
	if ( process_handle )
	{
		DbgHelp *gcc = &dbgHelpGcc;
#ifdef _WIN64
		if (is64BitProcess)
			gcc = &dbgHelpGccWow64;
#endif

		if (!gcc->SymCleanup(process_handle))
		{
			//error
		}

		if (!dbgHelpMs.SymCleanup(process_handle))
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
		DWORD err = GetLastError();
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
	getLineForAddr((PROFILER_ADDR)symbol_info->Address, procfilepath_out, proclinenum_out);

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
		DWORD err = GetLastError();
		filepath_out = L"[unknown]";
		linenum_out = 0;
	}
}



