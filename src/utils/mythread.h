/*=====================================================================
MyThread.h
----------

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

http://www.gnu.org/copyleft/gpl.html.
=====================================================================*/
#ifndef __MYTHREAD_H_666_
#define __MYTHREAD_H_666_

#include <windows.h>

/*=====================================================================
MyThread
--------
Thanks to someone from the COTD on flipcode for the code this is based on
=====================================================================*/
class MyThread
{
public:
	MyThread() : thread_handle(NULL) {}
	virtual ~MyThread();

	virtual void run() = 0;
	HANDLE launch(int priority);
	void waitFor(DWORD dwMilliseconds) { WaitForSingleObject(thread_handle, dwMilliseconds); }
	void join() { WaitForSingleObject(thread_handle, INFINITE); }
	void setPriority(int priority) { SetThreadPriority(thread_handle, priority); }

private:
	static unsigned __stdcall threadFunction(void* the_thread);

	HANDLE thread_handle;
};

#endif //__MYTHREAD_H_666_
