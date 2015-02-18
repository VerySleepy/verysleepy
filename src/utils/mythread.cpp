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
//#include "lock.h"

MyThread::MyThread()
{
	thread_handle = NULL;
	autodelete = false;
	commit_suicide = false;
}


MyThread::~MyThread()
{

}



HANDLE MyThread::launch(bool autodelete_, int priority_)
{
	assert(thread_handle == NULL);

	autodelete = autodelete_;

	const int stacksize = 0;//TEMP HACK

	thread_handle = (HANDLE)_beginthread(threadFunction, stacksize, this);
	SetThreadPriority( thread_handle, priority_ );

	return thread_handle;
}


void _cdecl MyThread::threadFunction(void* the_thread_)
{
	MyThread* the_thread = static_cast<MyThread*>(the_thread_);

	assert(the_thread != NULL);

	MyThread::incrNumAliveThreads();

	the_thread->run();

	if(the_thread->autodelete)
		delete the_thread;

	MyThread::decrNumAliveThreads();
}

void MyThread::killThread()
{
	//_endthread(
}

int MyThread::getNumAliveThreads()
{
	//Lock lock(alivecount_mutex);

	return num_alive_threads;
}

void MyThread::incrNumAliveThreads()
{
	num_alive_threads++;
}

void MyThread::decrNumAliveThreads()
{
	//Lock lock(alivecount_mutex);

	num_alive_threads--;

	assert(num_alive_threads >= 0);
}

//Mutex MyThread::alivecount_mutex;
int MyThread::num_alive_threads = 0;
