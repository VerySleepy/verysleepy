/*=====================================================================
processinfo.cpp
---------------
File created by ClassTemplate on Sun Mar 20 03:22:27 2005

Copyright (C) Nicholas Chapman
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

http://www.gnu.org/copyleft/gpl.html..
=====================================================================*/
#include "processinfo.h"

#include "../utils/osutils.h"
#include "../utils/except.h"
#include <windows.h>
#include <tlhelp32.h>

ProcessInfo::ProcessInfo(DWORD id_, const std::wstring& name_, HANDLE process_handle_)
:	id(id_),
	name(name_),
	process_handle(process_handle_)
{
	prevKernelTime.dwHighDateTime = prevKernelTime.dwLowDateTime = 0;
	prevUserTime.dwHighDateTime = prevUserTime.dwLowDateTime = 0;
	cpuUsage = -1;
#ifdef _WIN64
	is64Bits = Is64BitProcess(process_handle);
#endif
}

ProcessInfo::~ProcessInfo()
{
}

void ProcessInfo::enumProcesses(std::vector<ProcessInfo>& processes_out)
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD, 0);

	PROCESSENTRY32 processinfo = {0};
	processinfo.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(snapshot, &processinfo))
	{
		do
		{
			const DWORD process_id = processinfo.th32ProcessID;

			// Don't allow profiling our own process. Bad things happen.
			if (process_id == GetCurrentProcessId())
			{
				continue;
			}

			//------------------------------------------------------------------------
			//Get the actual handle of the process
			//------------------------------------------------------------------------
			const HANDLE process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);

			// Skip processes we don't have permission to.
			if (process_handle == NULL)
			{
				continue;
			}

			if (!CanProfileProcess(process_handle))
			{
				CloseHandle(process_handle);
				continue;
			}

			const std::wstring processname = processinfo.szExeFile;
			processes_out.push_back(ProcessInfo(process_id, processname, process_handle));

			processinfo.dwSize = sizeof(PROCESSENTRY32);
		}
		while(Process32Next(snapshot, &processinfo));
	}

	//------------------------------------------------------------------------
	//process threads
	//------------------------------------------------------------------------
	THREADENTRY32 threadinfo;
	threadinfo.dwSize = sizeof(THREADENTRY32);

	if(Thread32First(snapshot, &threadinfo))
	{
		do
		{
			const DWORD owner_process_id = threadinfo.th32OwnerProcessID;

			for(unsigned int i=0; i<processes_out.size(); ++i)
			{
				if(processes_out[i].getID() == owner_process_id)
				{
					DWORD threadID = threadinfo.th32ThreadID;
					HANDLE threadHandle = OpenThread( THREAD_ALL_ACCESS, FALSE, threadID );

					processes_out[i].threads.push_back(ThreadInfo(threadID, threadHandle));
					break;
				}
			}

			threadinfo.dwSize = sizeof(THREADENTRY32);
		}
		while(Thread32Next(snapshot, &threadinfo));
	}

	CloseHandle(snapshot);
}

ProcessInfo ProcessInfo::FindProcessById(DWORD process_id)
{
	std::vector<ProcessInfo> allProcesses;
	enumProcesses(allProcesses);
	for (size_t i=0; i < allProcesses.size(); i++)
	{
		auto process = allProcesses[i];
		if(process.getID() == process_id)
			return process;
	}
	throw SleepyException("Could not found process with specified id: " + std::to_string((unsigned long long) process_id));
}