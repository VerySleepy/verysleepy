/*=====================================================================
dbginterface.h
----------

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
#ifndef __DBGINTERFACE_H__
#define __DBGINTERFACE_H__

// Use our own copy of dbghelp.h, to make sure it's the latest version.
#include <windows.h>
#include "..\..\thirdparty\ms\dbghelp.h"

// We provide a wrapper around the dbghelp functions we need, so that
// we can switch to either the MS or Wine versions at runtime.

struct DbgHelp
{
	BOOL
	(WINAPI *StackWalk64)(
		__in DWORD MachineType,
		__in HANDLE hProcess,
		__in HANDLE hThread,
		__inout LPSTACKFRAME64 StackFrame,
		__inout PVOID ContextRecord,
		__in_opt PREAD_PROCESS_MEMORY_ROUTINE64 ReadMemoryRoutine,
		__in_opt PFUNCTION_TABLE_ACCESS_ROUTINE64 FunctionTableAccessRoutine,
		__in_opt PGET_MODULE_BASE_ROUTINE64 GetModuleBaseRoutine,
		__in_opt PTRANSLATE_ADDRESS_ROUTINE64 TranslateAddress
		);

	PVOID
	(WINAPI *SymFunctionTableAccess64)(
		__in HANDLE hProcess,
		__in DWORD64 AddrBase
		);

	DWORD64
	(WINAPI *SymGetModuleBase64)(
		__in HANDLE hProcess,
		__in DWORD64 qwAddr
		);

	BOOL
	(WINAPI *SymCleanup)(
		__in HANDLE hProcess
		);

	BOOL
	(WINAPI *SymEnumerateModulesW64)(
		__in HANDLE hProcess,
		__in PSYM_ENUMMODULES_CALLBACKW64 EnumModulesCallback,
		__in_opt PVOID UserContext
		);

	BOOL
	(WINAPI *SymSetSearchPathW)(
		__in HANDLE hProcess,
		__in_opt PCWSTR SearchPath
		);

	BOOL
	(WINAPI *SymInitializeW)(
		__in HANDLE hProcess,
		__in_opt PCWSTR UserSearchPath,
		__in BOOL fInvadeProcess
		);

	DWORD
	(WINAPI *SymSetOptions)(
		__in DWORD   SymOptions
		);

	DWORD
	(WINAPI *SymGetOptions)(
		VOID
		);

	BOOL
	(WINAPI *SymGetModuleInfoW64)(
		__in HANDLE hProcess,
		__in DWORD64 qwAddr,
		__out PIMAGEHLP_MODULEW64 ModuleInfo
		);

	BOOL
	(WINAPI *SymFromAddrW)(
		__in HANDLE hProcess,
		__in DWORD64 Address,
		__out_opt PDWORD64 Displacement,
		__inout PSYMBOL_INFOW Symbol
		);

	BOOL
	(WINAPI *SymGetLineFromAddrW64)(
		__in HANDLE hProcess,
		__in DWORD64 qwAddr,
		__out PDWORD pdwDisplacement,
		__out PIMAGEHLP_LINEW64 Line64
		);

	BOOL
	(WINAPI *SymRegisterCallbackW64)(
		__in HANDLE hProcess,
		__in PSYMBOL_REGISTERED_CALLBACK64 CallbackFunction,
		__in ULONG64 UserContext
		);

	BOOL
	(WINAPI *SymRefreshModuleList)(
		__in HANDLE hProcess
		);

	DWORD64
	(WINAPI *SymLoadModuleExW)(
		__in HANDLE hProcess,
		__in_opt HANDLE hFile,
		__in_opt PCTSTR ImageName,
		__in_opt PCTSTR ModuleName,
		__in DWORD64 BaseOfDll,
		__in DWORD DllSize,
		__in_opt PMODLOAD_DATA Data,
		__in_opt DWORD Flags
		);

	void
	(WINAPI *SymSetDbgPrint)(
		 void (*fn)(const char *str)
		 );

	BOOL
	(WINAPI *MiniDumpWriteDump)(
		__in HANDLE hProcess,
		__in DWORD ProcessId,
		__in HANDLE hFile,
		__in MINIDUMP_TYPE DumpType,
		__in_opt PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
		__in_opt PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
		__in_opt PMINIDUMP_CALLBACK_INFORMATION CallbackParam
		);

	LPCWSTR Name;
	bool Loaded;
	DbgHelp() : Loaded(false) {}
};

extern DbgHelp dbgHelpMs;
extern DbgHelp dbgHelpDrMingw;
extern DbgHelp dbgHelpWine;
extern DbgHelp dbgHelpWineWow64;

bool dbgHelpInit();

#endif // __DBGINTERFACE_H__
