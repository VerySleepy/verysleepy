/*=====================================================================
sortlist.cpp
------------

Copyright (C) Dan Engelbrecht

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

int GetCPUCores(){
	SYSTEM_INFO systemInfo;
	::GetSystemInfo(&systemInfo);
	__int64 cpuCount = systemInfo.dwNumberOfProcessors;
	return static_cast<int>(cpuCount);
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

bool Is64BitProcess(HANDLE hProcess)
{
	typedef BOOL WINAPI IsWow64Process_t(__in   HANDLE hProcess,__out  PBOOL Wow64Process);
	static bool first = true;
	static IsWow64Process_t *IsWow64ProcessPtr = NULL;

#ifndef _WIN64
	static BOOL isOn64BitOs = 0;
#endif

	if (first) {
		first = false;
		IsWow64ProcessPtr = (IsWow64Process_t *)GetProcAddress(GetModuleHandle(L"kernel32"),"IsWow64Process");
#ifndef _WIN64
		if (!IsWow64ProcessPtr)
			return false;
		IsWow64ProcessPtr(GetCurrentProcess(),&isOn64BitOs);
#endif
	}

#ifndef _WIN64
	if(!isOn64BitOs) {
		return false;
	}
#endif

	if(IsWow64ProcessPtr) {
		BOOL isWow64Process;
		if(IsWow64ProcessPtr(hProcess,&isWow64Process) && !isWow64Process) {
			return true;
		}
	}
	return false;
}

