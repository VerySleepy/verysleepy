/*=====================================================================
threadinfo.h
------------
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
#ifndef __THREADINFO_H_666_
#define __THREADINFO_H_666_


#include <windows.h>
#include <string>


/*=====================================================================
ThreadInfo
----------
Info about a thread running on the system
=====================================================================*/
class ThreadInfo
{
public:
	/*=====================================================================
	ThreadInfo
	----------

	=====================================================================*/
	ThreadInfo(DWORD id, HANDLE thread_handle);

	~ThreadInfo();

	const DWORD getID() const { return id; }
	HANDLE getThreadHandle() const { return thread_handle; }

	const std::wstring& getLocation() const { return location; }
	void setLocation(const std::wstring &loc) { location = loc; }

	bool recalcUsage(int sampleTimeDiff);

	FILETIME prevKernelTime, prevUserTime;
	// DE: 20090325 Threads now have CPU usage
	int cpuUsage;
	__int64 totalCpuTimeMs;

private:
	std::wstring location;
	DWORD id;
	HANDLE thread_handle;
};



#endif //__THREADINFO_H_666_
