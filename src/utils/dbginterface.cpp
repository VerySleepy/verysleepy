/*=====================================================================
dbginterface.cpp
------------

Copyright (C) Richard Mitton

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

http://www.gnu.org/copyleft/gpl.html.
=====================================================================*/
#include "dbginterface.h"
#include <wx/log.h>
#include "except.h"

DbgHelp dbgHelpMs;
DbgHelp dbgHelpDrMingw;
DbgHelp dbgHelpWine;
DbgHelp dbgHelpWineWow64;

#define IMPORT(name) *(void **)&dest->name = GetProcAddress(hMod, #name)

static bool dbgHelpTryLoad(LPCWSTR name, DbgHelp* dest)
{
	dest->Name = name;
	HMODULE hMod = LoadLibrary(name);
	if (!hMod)
		return false;
	IMPORT(StackWalk64);
	IMPORT(SymFunctionTableAccess64);
	IMPORT(SymGetModuleBase64);
	IMPORT(SymCleanup);
	IMPORT(SymEnumerateModulesW64);
	IMPORT(SymSetSearchPathW);
	IMPORT(SymInitializeW);
	IMPORT(SymSetOptions);
	IMPORT(SymGetOptions);
	IMPORT(SymGetModuleInfoW64);
	IMPORT(SymFromAddrW);
	IMPORT(SymGetLineFromAddrW64);
	IMPORT(SymRegisterCallbackW64);
	IMPORT(SymRefreshModuleList);
	IMPORT(SymLoadModuleExW);
	IMPORT(SymSetDbgPrint); // Custom Wine extension
	IMPORT(MiniDumpWriteDump);
	dest->Loaded = true;
	return true;
}

static void dbgHelpLoad(LPCWSTR name, DbgHelp* dest, const wxString& description)
{
	if (!dbgHelpTryLoad(name, dest))
		wxLogWarning("Could not load " + wxString(name) + ": " + wxSysErrorMsg() + "\n" + description + " will be unavailable.");
}

bool dbgHelpInit()
{
	// Import the Microsoft dbghelp.dll
	if (!dbgHelpTryLoad(L"dbghelpms.dll", &dbgHelpMs))
	{
		// The latest version of dbghelp.dll requires a
		// recent version of Windows to run. If loading
		// that fails, fall back to an older version.
		dbgHelpLoad(L"dbghelpms6.dll", &dbgHelpMs, "Microsoft debug information");
	}

	// Import the DrMingw dbghelp.dll
	dbgHelpLoad(L"dbghelpdr.dll", &dbgHelpDrMingw, "Dr. MinGW debug information");

	// Import the Wine dbghelp.dll
	dbgHelpLoad(L"dbghelpw.dll", &dbgHelpWine, "Wine debug information");

#ifdef _WIN64
	// Import the Wine Wow64 dbghelp.dll
	dbgHelpLoad(L"dbghelpw_wow64.dll", &dbgHelpWineWow64, "WoW64 Wine debug information");
#endif

	return true;
}
