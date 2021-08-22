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
#include <assert.h>
#include <map>
#include <tlhelp32.h>

class DebuggerThread : public MyThread
{
public:
	DebuggerThread(Debugger *debugger);
	~DebuggerThread();

	void finishAttaching();

	void updateFromSnapshot();
	void updateDebugger();

	void deactivateDebugger();

	virtual void run();

	HANDLE readyEvent;
	Debugger *debugger;
	std::map<DWORD, bool> knownThreads;
	bool debuggerActive;
	bool attached;
	bool commit_suicide;
};

Debugger::Debugger(DWORD processId_)
	: processId(processId_)
	, processHandle(NULL)
	, debuggerThread(NULL)
{
}

Debugger::~Debugger()
{
	if (processHandle)
		detach();
}

void Debugger::notifyNewThread(DWORD threadId, HANDLE threadHandle)
{
	NotifyData data;
	data.eventType = NOTIFY_NEW_THREAD;
	data.threadHandle = threadHandle;
	data.threadId = threadId;
	notifyFunc(data);
}

bool Debugger::attach(std::function<void(NotifyData const &notification)> notifyFunc_)
{
	assert(!processHandle);
	assert(!debuggerThread);
	assert(!notifyFunc);
	assert(notifyFunc_);
	assert(knownThreads.empty());

	notifyFunc = notifyFunc_;
	debuggerThread = new DebuggerThread(this);
	debuggerThread->launch(THREAD_PRIORITY_TIME_CRITICAL);

	WaitForSingleObject(debuggerThread->readyEvent, INFINITE);

	return true;
}

void Debugger::detach()
{
	assert( processHandle );

	debuggerThread->commit_suicide = true;
	debuggerThread->waitFor(INFINITE);
	delete debuggerThread;

	notifyFunc = nullptr;

	processHandle = NULL;
}

DebuggerThread::DebuggerThread(Debugger *debugger_)
	: debugger(debugger_)
	, debuggerActive(true)
	, commit_suicide(false)
	, attached(false)
{
	readyEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
}

DebuggerThread::~DebuggerThread()
{
	CloseHandle(readyEvent);
}

void DebuggerThread::finishAttaching()
{
	if (attached)
		return;

	if (!debugger->processHandle)
	{
		debugger->processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, debugger->processId);

		if (debuggerActive)
			deactivateDebugger();
	}

	// make sure notifications for existing threads have fired at this point
	if (!debuggerActive)
		updateFromSnapshot();

	attached = true;
	SetEvent(readyEvent);
}

void DebuggerThread::updateFromSnapshot()
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	THREADENTRY32 thread;
	thread.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(snapshot, &thread))
	{
		std::map<DWORD, bool> threads;
		do
		{
			if (thread.th32OwnerProcessID != debugger->processId)
				continue;

			threads.insert(std::make_pair(thread.th32ThreadID, true));
			if (knownThreads.find(thread.th32ThreadID) != knownThreads.end())
				continue;

			HANDLE threadHandle = OpenThread(THREAD_ALL_ACCESS, FALSE, thread.th32ThreadID);
			if (threadHandle)
				debugger->notifyNewThread(thread.th32ThreadID, threadHandle);

		} while (Thread32Next(snapshot, &thread));

		knownThreads = std::move(threads);
	}

	CloseHandle(snapshot);
}

void DebuggerThread::updateDebugger()
{
	assert(debuggerActive);

	DEBUG_EVENT dbgEvent;
	if (!WaitForDebugEvent(&dbgEvent, 100))
	{
		DWORD err = GetLastError();
		if (err != ERROR_SEM_TIMEOUT)
		{
			deactivateDebugger();
			finishAttaching();
		}
		return;
	}

	switch (dbgEvent.dwDebugEventCode)
	{
		case EXCEPTION_DEBUG_EVENT:
			switch (dbgEvent.u.Exception.ExceptionRecord.ExceptionCode)
			{
			case EXCEPTION_BREAKPOINT:
				// Debugger attach flow follows the sequence
				// CREATE_PROCESS_DEBUG_EVENT, where we get the process handle and the main thread,
				// CREATE_THREAD_DEBUG_EVENT for every other thread in existence
				// LOAD_DLL_DEBUG_EVENT for every loaded DLL
				// finally, EXCEPTION_DEBUG_EVENT with code EXCEPTION_BREAKPOINT as the app is stopped by the OS
				finishAttaching();
				break;
			}
			break;

		case RIP_EVENT:
			// Debugging error
			deactivateDebugger();
			finishAttaching();
			break;

		case CREATE_PROCESS_DEBUG_EVENT:
			assert(!debugger->processHandle);
			debugger->processHandle = dbgEvent.u.CreateProcessInfo.hProcess;
			debugger->notifyNewThread(dbgEvent.dwThreadId, dbgEvent.u.CreateProcessInfo.hThread);
			knownThreads.insert(std::make_pair(dbgEvent.dwThreadId, true));
			// We're not using the image file, close the handle
			CloseHandle(dbgEvent.u.CreateProcessInfo.hFile);
			break;

		case EXIT_PROCESS_DEBUG_EVENT:
			// Display the process's exit code.
			break;

		case CREATE_THREAD_DEBUG_EVENT:
			debugger->notifyNewThread(dbgEvent.dwThreadId, dbgEvent.u.CreateThread.hThread);
			break;

		case EXIT_THREAD_DEBUG_EVENT:
			knownThreads.erase(dbgEvent.dwThreadId);
			break;

		case LOAD_DLL_DEBUG_EVENT:
			// We're not using the dll file, close the handle
			CloseHandle(dbgEvent.u.LoadDll.hFile);
			break;

		case UNLOAD_DLL_DEBUG_EVENT:
			// Display a message that the DLL has been unloaded.
			break;

		case OUTPUT_DEBUG_STRING_EVENT:
			// Display the output debugging string.
			break;
	}

	ContinueDebugEvent(dbgEvent.dwProcessId, dbgEvent.dwThreadId, DBG_EXCEPTION_NOT_HANDLED);
}

void DebuggerThread::deactivateDebugger()
{
	assert(debuggerActive);
	debuggerActive = false;
	DebugActiveProcessStop(debugger->processId);
}

void DebuggerThread::run()
{
	if (DebugActiveProcess(debugger->processId))
	{
		DebugSetProcessKillOnExit(FALSE);
	}
	else
	{
		debuggerActive = false;
		updateFromSnapshot();
		SetEvent(readyEvent);
	}

	while (!commit_suicide)
	{
		if (debuggerActive)
		{
			updateDebugger();
		}
		else
		{
			updateFromSnapshot();
			Sleep(100);
		}
	}

	if (debuggerActive)
		deactivateDebugger();
}
