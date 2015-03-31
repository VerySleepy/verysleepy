/*=====================================================================
osutils.cpp
------------

Copyright (C) Dan Engelbrecht
Copyright (C) 2015 Ashod Nakashian

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

#include "osutils.h"
#include "WoW64.h"

static bool is64BitOS = false;
static bool is64BitProfiler = false;
static int totalCpuCount = 1;

typedef BOOL WINAPI IsWow64Process_t(__in HANDLE hProcess, __out PBOOL Wow64Process);
static IsWow64Process_t *IsWow64ProcessPtr = NULL;

void InitSysInfo()
{
	SYSTEM_INFO systemInfo = { 0 };
	GetNativeSystemInfo(&systemInfo);
	totalCpuCount = systemInfo.dwNumberOfProcessors;
	is64BitOS = (systemInfo.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64);

	is64BitProfiler = (sizeof(void*) > 4);
	IsWow64ProcessPtr = (IsWow64Process_t *)GetProcAddress(GetModuleHandle(L"kernel32"), "IsWow64Process");
}

int GetCPUCores()
{
	return totalCpuCount;
}

int GetCountFromBitMask(DWORD bitMask){
	int count = 0;
	while(bitMask != 0){
		if((bitMask & 1) != 0){
			++count;
		}
		bitMask = bitMask >> 1;
	}
	return count;
}

int GetCoresForProcess(HANDLE process){
	DWORD_PTR processAffinityMask = 0;
	DWORD_PTR systemAffinityMask = 0;
	BOOL okFlag = ::GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	if((okFlag == FALSE) || (processAffinityMask == 0)){
		return GetCPUCores();
	}
	else{
		return GetCountFromBitMask(DWORD(processAffinityMask));
	}
}

void EnableDebugPrivilege()
{
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkp;

	OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken );

	LookupPrivilegeValue( NULL, SE_DEBUG_NAME, &luid );

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = luid;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges( hToken, false, &tkp, sizeof( tkp ), NULL, NULL );

	CloseHandle( hToken );
}

/*
Bitness possibility matrix.

Profiler | Profilee | OS
-----------------------------
32-bits  | 32-bits  | 32-bits   (Native)
32-bits  | 32-bits  | WOW64
32-bits  | 64-bits  | 64-bits   (Unsupported)

64-bits  | 32-bits  | WOW64
64-bits  | 64-bits  | 64-bits   (Native)
*/

bool CanProfileProcess(HANDLE hProcess)
{
	if (Is64BitProcess(hProcess))
	{
		// 64-bit with a 64-bit profiler only.
		return is64BitProfiler;
	}

	//TODO: Check security permissions?

#ifdef _WIN64
	if (fn_Wow64SuspendThread == NULL || fn_Wow64GetThreadContext == NULL)
	{
		// Skip 32 bit processes on system that does not have the needed functions (Windows XP 64).
		return false;
	}
#endif

	// Any 32-bit profilee is supported.
	return true;
}

bool Is64BitProcess(HANDLE hProcess)
{
	// If the process is running under 32-bit Windows, the value is set to FALSE.
	// If the process is a 64-bit application running under 64-bit Windows, the value is also set to FALSE.
	// Meaning, this is TRUE if, and only if, the process is 32-bits running under 64-bit Windows.
	BOOL isWow64Process;

	return (is64BitOS &&
			IsWow64ProcessPtr &&
			IsWow64ProcessPtr(hProcess, &isWow64Process) &&
			!isWow64Process);
}
