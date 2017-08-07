/*=====================================================================
threadinfo.cpp
--------------
File created by ClassTemplate on Sun Mar 20 03:22:37 2005

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
#include "threadinfo.h"

static __int64 getDiff(FILETIME before, FILETIME after)
{
	__int64 i0 = (__int64(before.dwHighDateTime) << 32) + before.dwLowDateTime;
	__int64 i1 = (__int64(after.dwHighDateTime) << 32) + after.dwLowDateTime;
	return i1 - i0;
}

static __int64 getTotal(FILETIME time)
{
	return (__int64(time.dwHighDateTime) << 32) + time.dwLowDateTime;
}


// DE: 20090325 Threads now have CPU usage
ThreadInfo::ThreadInfo(DWORD id_, HANDLE thread_handle_)
:	id(id_), thread_handle(thread_handle_)
{
	prevKernelTime.dwHighDateTime = prevKernelTime.dwLowDateTime = 0;
	prevUserTime.dwHighDateTime = prevUserTime.dwLowDateTime = 0;
  cpuUsage = -1;

}


ThreadInfo::~ThreadInfo()
{
}

bool ThreadInfo::recalcUsage(int sampleTimeDiff)
{
	cpuUsage = -1;
	totalCpuTimeMs = -1;

	HANDLE thread_handle = getThreadHandle();
	if (thread_handle == NULL)
		return false;

	FILETIME CreationTime, ExitTime, KernelTime, UserTime;

	if (!GetThreadTimes(
		thread_handle,
		&CreationTime,
		&ExitTime,
		&KernelTime,
		&UserTime
	))
		return false;
	
	__int64 kernel_diff = getDiff(prevKernelTime, KernelTime);
	__int64 user_diff = getDiff(prevUserTime, UserTime);
	prevKernelTime = KernelTime;
	prevUserTime = UserTime;

	if (sampleTimeDiff > 0) {
		__int64 total_diff = ((kernel_diff + user_diff) / 10000) * 100;
		cpuUsage = static_cast<int>(total_diff / sampleTimeDiff);
	}
	totalCpuTimeMs = (getTotal(KernelTime) + getTotal(UserTime)) / 10000;

	return true;
}
