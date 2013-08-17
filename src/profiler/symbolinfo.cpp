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
#include <Dbgeng.h>
#include <comdef.h>

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

	prefs.AdjustSymbolPath(sympath, download);

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

template<class T>
T wenforce(T cond, const char* where = NULL)
{
	if (cond)
		return cond;

	DWORD code = GetLastError();

	std::wostringstream message;
	if (where)
		message << where;

	if (code)
	{
		wchar_t *lpMsgBuf = NULL;
		FormatMessageW(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			code,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPWSTR)&lpMsgBuf,
			0,
			NULL);

		message << ": " << lpMsgBuf;
		if (lpMsgBuf)
			LocalFree(lpMsgBuf);
		message << " (error " << code << ")";
	}
	else
		message << " failed";

	throw SymbolInfoExcep(message.str());
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

std::wstring SymbolInfo::saveMinidump()
{
#ifdef _WIN64
	if (!Is64BitProcess(process_handle))
	{
		wxLogWarning(
			L"Warning: minidumps of 32-bit processes saved by 64-bit processes will most likely not be saved correctly.\n"
			L"Use the 32-bit version of " APPNAME L" to profile 32-bit processes if a minidump needs to be included."
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


void comenforce(HRESULT result, const char* where = NULL)
{
	if (result == S_OK)
		return;

	std::wostringstream message;
	if (where)
		message << where;

	_com_error error(result);
	message << ": " << error.ErrorMessage();
	message << " (error " << result << ")";

	throw SymbolInfoExcep(message.str());
}


LateSymbolInfo::LateSymbolInfo()
:	debugClient5(NULL), debugControl4(NULL), debugSymbols3(NULL)
{
}

LateSymbolInfo::~LateSymbolInfo()
{
	unloadMinidump();
}

// Send debugger output to the wxWidgets current logging facility.
// The UI implements a logging facility in the form of a log panel.
struct DebugOutputCallbacksWide : public IDebugOutputCallbacksWide
{
	HRESULT	STDMETHODCALLTYPE QueryInterface(__in REFIID InterfaceId, __out PVOID* Interface) { return E_NOINTERFACE; }
	ULONG	STDMETHODCALLTYPE AddRef() { return 1; }
	ULONG	STDMETHODCALLTYPE Release() { return 0; }

	HRESULT	STDMETHODCALLTYPE Output(__in ULONG Mask, __in PCWSTR Text)
	{
		//OutputDebugStringW(Text);
		wxLogMessage(L"%s", Text);
		return S_OK;
	}
};

static DebugOutputCallbacksWide *debugOutputCallbacks = new DebugOutputCallbacksWide();

void LateSymbolInfo::loadMinidump(std::wstring& dumppath, bool delete_when_done)
{
	// Method credit to http://stackoverflow.com/a/8119364/21501

	if (debugClient5 || debugControl4 || debugSymbols3)
	{
		//throw SymbolInfoExcep(L"Minidump symbols already loaded.");

		// maybe the user moved a .pdb to somewhere where we can now find it?
		unloadMinidump();
	}

	IDebugClient *debugClient = NULL;

	SetLastError(0);
	comenforce(DebugCreate(__uuidof(IDebugClient), (void**)&debugClient), "DebugCreate");
	comenforce(debugClient->QueryInterface(__uuidof(IDebugClient5 ), (void**)&debugClient5 ), "QueryInterface(IDebugClient5)" );
	comenforce(debugClient->QueryInterface(__uuidof(IDebugControl4), (void**)&debugControl4), "QueryInterface(IDebugControl4)");
	comenforce(debugClient->QueryInterface(__uuidof(IDebugSymbols3), (void**)&debugSymbols3), "QueryInterface(IDebugSymbols3)");
	comenforce(debugClient5->SetOutputCallbacksWide(debugOutputCallbacks), "IDebugClient5::SetOutputCallbacksWide");
	comenforce(debugSymbols3->SetSymbolOptions(SYMOPT_UNDNAME | SYMOPT_LOAD_LINES | SYMOPT_OMAP_FIND_NEAREST | SYMOPT_AUTO_PUBLICS | SYMOPT_DEBUG), "IDebugSymbols::SetSymbolOptions");

	std::wstring sympath;
	prefs.AdjustSymbolPath(sympath, true);

	comenforce(debugSymbols3->SetSymbolPathWide(sympath.c_str()), "IDebugSymbols::SetSymbolPath");
	comenforce(debugClient5->OpenDumpFileWide(dumppath.c_str(), NULL), "IDebugClient4::OpenDumpFileWide");
	comenforce(debugControl4->WaitForEvent(0, INFINITE), "IDebugControl::WaitForEvent");

	// Since we can't just enumerate all symbols in all modules referenced by the minidump,
	// we have to keep the debugger session open and query symbols as requested by the
	// profiler GUI.

	debugClient->Release(); // but keep the other ones

	// If we are given a temporary file, clean it up later
	if (delete_when_done)
		file_to_delete = dumppath;
}

void LateSymbolInfo::unloadMinidump()
{
	if (debugClient5)
	{
		debugClient5->EndSession(DEBUG_END_ACTIVE_TERMINATE);
		debugClient5->Release();
	}
	if (debugControl4)
		debugControl4->Release();
	if (debugSymbols3)
		debugSymbols3->Release();

	if (!file_to_delete.empty())
	{
		wxRemoveFile(file_to_delete);
		file_to_delete.clear();
	}
}

bool LateSymbolInfo::isUnresolved( const std::wstring &procname )
{
	return procname[0]=='[' && procname[procname.length()-1] == ']' && procname != L"[unknown]";
}

wchar_t LateSymbolInfo::buffer[4096];

void LateSymbolInfo::filterSymbol(std::wstring &module, std::wstring &procname, std::wstring &sourcefile, int &sourceline)
{
	if (debugSymbols3 && isUnresolved(procname))
	{
		ULONG64 offset = 0;
		swscanf_s(procname.c_str(), L"[%I64x]", &offset);
		if (!offset) return;

		ULONG moduleindex;
		if (debugSymbols3->GetModuleByOffset(offset, 0, &moduleindex, NULL) == S_OK)
			if (debugSymbols3->GetModuleNameStringWide(DEBUG_MODNAME_MODULE, moduleindex, 0, buffer, _countof(buffer), NULL) == S_OK)
				module = buffer;

		if (debugSymbols3->GetNameByOffsetWide(offset, buffer, _countof(buffer), NULL, NULL) == S_OK)
			if (module.compare(buffer) != 0)
			{
				procname = buffer;

				// Remove redundant "Module!" prefix
				size_t modlength = module.length();
				if (procname.length() > modlength+1 && module.compare(0, modlength, procname, 0, modlength)==0 && procname[modlength] == '!')
					procname.erase(0, modlength+1);
			}

		filterIP(offset, sourcefile, sourceline);
	}
}

void LateSymbolInfo::filterIP(ULONG64 offset, std::wstring &sourcefile, int &sourceline)
{
	if (!sourceline)
	{
		ULONG line;
		if (debugSymbols3->GetLineByOffsetWide(offset, &line, buffer, _countof(buffer), NULL, NULL) == S_OK)
		{
			sourcefile = buffer;
			sourceline = line;
		}
	}
}

void LateSymbolInfo::filterIP(const std::wstring &memaddr, std::wstring &srcfile, int &linenum)
{
	if (debugSymbols3)
	{
		ULONG64 offset = 0;
		swscanf_s(memaddr.c_str(), L"0x%I64x", &offset);
		if (offset)
			filterIP(offset, srcfile, linenum);
	}
}
