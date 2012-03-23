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

DbgHelp dbgHelpMs;
DbgHelp dbgHelpGcc;
DbgHelp dbgHelpGccWow64;

#define IMPORT(name) *(void **)&dest->name = GetProcAddress(hMod, #name)

bool dbgHelpInit()
{
	HMODULE hMod;
	DbgHelp *dest;

	// Import the Microsoft dbghelp.dll
	hMod = LoadLibrary(L"dbghelp.dll");
	if (!hMod)
	{
		::MessageBox(NULL, L"Error: Could not load dbghelp.dll.", L"Error", MB_OK);
		return false;
	}

	dest = &dbgHelpMs;
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
	IMPORT(SymEnumerateModulesW64);
	IMPORT(SymLoadModuleExW);
	dest->SymSetDbgPrint = NULL;

	// Import the Wine dbghelp.dll
	hMod = LoadLibrary(L"dbghelpw.dll");
	if (!hMod)
	{
		::MessageBox(NULL, L"Error: Could not load dbghelpw.dll.", L"Error", MB_OK);
		return false;
	}

	dest = &dbgHelpGcc;
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
	IMPORT(SymEnumerateModulesW64);
	IMPORT(SymLoadModuleExW);
	IMPORT(SymSetDbgPrint);

#ifdef _WIN64
	// Import the Wine Wow64 dbghelp.dll
	hMod = LoadLibrary(L"dbghelpw_wow64.dll");
	if (!hMod)
	{
		::MessageBox(NULL, L"Error: Could not load dbghelpw_wow64.dll.", L"Error", MB_OK);
		return false;
	}

	dest = &dbgHelpGccWow64;
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
	IMPORT(SymEnumerateModulesW64);
	IMPORT(SymLoadModuleExW);
	IMPORT(SymSetDbgPrint);
#endif

	return true;
}
