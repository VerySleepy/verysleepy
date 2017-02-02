/*=====================================================================
debugger.cpp
---------------

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

http://www.gnu.org/copyleft/gpl.html..
=====================================================================*/
#include "debugger.h"
#include "../utils/mythread.h"
#include <map>
#include <assert.h>

class DebuggerThread : public MyThread
{
public:
	DebuggerThread( Debugger *debugger );
	~DebuggerThread();

	virtual void run();

	HANDLE readyEvent;
	Debugger *debugger;
};

HANDLE hMutex = NULL;

Debugger::Debugger( DWORD processId )
{
	if ( !hMutex )
		hMutex = CreateMutex( NULL, FALSE, NULL );

	this->processId = processId;
	this->process = NULL;
	this->hProcess = NULL;
	this->debuggerThread = NULL;
}

Debugger::~Debugger()
{
	if ( process )
		Detach();
}

bool Debugger::Attach()
{
	assert( !process );
	assert( !debuggerThread );

	debuggerThread = new DebuggerThread( this );
	debuggerThread->launch( false, THREAD_PRIORITY_TIME_CRITICAL );

	WaitForSingleObject( debuggerThread->readyEvent, INFINITE );

	process = new ProcessInfo( processId, hProcess, "" );
	return true;
}

void Debugger::Detach()
{
	assert( process );

	debuggerThread->commit_suicide = true;
	debuggerThread->waitFor();
	delete debuggerThread;

	hThreads.clear();
	delete process;
	process = NULL;
}

void Debugger::getThreads( std::vector<ThreadInfo> &output ) const
{
	WaitForSingleObject( hMutex, INFINITE );
	output = hThreads;
	ReleaseMutex( hMutex );
}

DebuggerThread::DebuggerThread( Debugger *debugger_ )
: debugger( debugger_ )
{
	readyEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
}

DebuggerThread::~DebuggerThread()
{
	CloseHandle( readyEvent );
}

void DebuggerThread::run()
{
	if ( !DebugActiveProcess( debugger->processId ) )
		return;

	DebugSetProcessKillOnExit( FALSE );
	HANDLE hImageFile = NULL;
	//bool go = false;
	//HANDLE target_thread = 0;

	while( !commit_suicide )
	{
		DEBUG_EVENT dbgEvent;
		if ( !WaitForDebugEvent( &dbgEvent, 100 ) )
		{
			//if ( go )
			//{
			//	DWORD t0 = GetTickCount();
			//	CONTEXT threadcontext;
			//	threadcontext.ContextFlags = CONTEXT_i386 | CONTEXT_CONTROL;

			//	HRESULT result = SuspendThread(target_thread);

			//	if(result == 0xffffffff)
			//		__asm int 3

			//	SetThreadPriority( target_thread, THREAD_PRIORITY_TIME_CRITICAL );
			//	result = GetThreadContext(target_thread, &threadcontext);
			//	SetThreadPriority( target_thread, THREAD_PRIORITY_NORMAL );

			//	ResumeThread(target_thread);
			//
			//	DWORD t1 = GetTickCount();
			//	char buf[256];
			//	sprintf(buf, "%08x - %ims\n", t1, t1 - t0);
			//	OutputDebugString(buf);
			//}

			DWORD err = GetLastError();
			continue;
		}

		WaitForSingleObject( hMutex, INFINITE );
		switch (dbgEvent.dwDebugEventCode)
		{
		case EXCEPTION_DEBUG_EVENT:
			SetEvent( readyEvent );
			//go = true;
			break;

		case CREATE_THREAD_DEBUG_EVENT:
			debugger->hThreads.push_back( ThreadInfo( dbgEvent.dwThreadId, dbgEvent.u.CreateThread.hThread ) );
			break;

		case CREATE_PROCESS_DEBUG_EVENT:
			debugger->hProcess = dbgEvent.u.CreateProcessInfo.hProcess;
			hImageFile = dbgEvent.u.CreateProcessInfo.hFile;
			debugger->hThreads.push_back( ThreadInfo( dbgEvent.dwThreadId, dbgEvent.u.CreateProcessInfo.hThread ) );
			//target_thread = dbgEvent.u.CreateProcessInfo.hThread;
			break;

		case EXIT_THREAD_DEBUG_EVENT:
			// Display the thread's exit code.
			break;

		case EXIT_PROCESS_DEBUG_EVENT:
			// Display the process's exit code.
			break;

		case LOAD_DLL_DEBUG_EVENT:
			// Read the debugging information included in the newly
			// loaded DLL. Be sure to close the handle to the loaded DLL
			// with CloseHandle.
			break;

		case UNLOAD_DLL_DEBUG_EVENT:
			// Display a message that the DLL has been unloaded.
			break;

		case OUTPUT_DEBUG_STRING_EVENT:
			// Display the output debugging string.
			break;

		}

		ReleaseMutex( hMutex );
		ContinueDebugEvent( dbgEvent.dwProcessId, dbgEvent.dwThreadId, DBG_EXCEPTION_NOT_HANDLED );
	}

	if ( hImageFile )
		CloseHandle( hImageFile );

	DebugActiveProcessStop( debugger->processId );
}
