/*=====================================================================
MyThread.cpp
------------

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
#include "mythread.h"

#include <assert.h>
#include <process.h>

MyThread::~MyThread()
{
#ifndef NDEBUG
	DWORD dwExitCode;
	BOOL res = GetExitCodeThread(thread_handle, &dwExitCode);
	assert(res != 0 && dwExitCode != STILL_ACTIVE);
#endif//NDEBUG
	CloseHandle(thread_handle);
}

HANDLE MyThread::launch(int priority_)
{
	assert(thread_handle == NULL);

	thread_handle = (HANDLE)_beginthreadex(NULL, 0, threadFunction, this, 0, NULL);
	SetThreadPriority( thread_handle, priority_ );

	return thread_handle;
}


unsigned __stdcall MyThread::threadFunction(void* the_thread_)
{
	MyThread* the_thread = static_cast<MyThread*>(the_thread_);

	assert(the_thread != NULL);

	the_thread->run();

	return 0;
}
