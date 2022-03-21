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

Debugger::Debugger(DWORD processId_)
	: processId(processId_)
	, processHandle(NULL)
	, debuggingActive(true)
	, attached(false)
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
	assert(!notifyFunc);
	assert(notifyFunc_);
	assert(knownThreads.empty());

	notifyFunc = notifyFunc_;

	if (debuggingActive && DebugActiveProcess(processId))
	{
		DebugSetProcessKillOnExit(FALSE);
	}
	else
	{
		finishAttaching();
		assert(!debuggingActive);
	}

	while (!attached)
	{
		update();
	}

	return true;
}

void Debugger::detach()
{
	assert( processHandle );

	if (debuggingActive)
		deactivateDebugging();

	notifyFunc = nullptr;

	processHandle = NULL;
}

void Debugger::update()
{
	if (debuggingActive)
	{
		// While debugger is attached, update it to detect new threads
		updateDebugging();
	}
	else
	{
		// If debugging can't attach (e.g., if the target is already being debugged)
		// or fails after that, fall back to polling a Toolhelp snapshot to detect threads
		updateFromSnapshot();
	}
}

void Debugger::deactivateDebugging()
{
	assert(debuggingActive);
	debuggingActive = false;
	DebugActiveProcessStop(processId);
}

void Debugger::finishAttaching()
{
	if (attached)
		return;

	if (!processHandle)
	{
		processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

		if (debuggingActive)
			deactivateDebugging();
	}

	// make sure notifications for existing threads have fired at this point
	if (!debuggingActive)
		updateFromSnapshot();

	attached = true;
}

void Debugger::updateFromSnapshot()
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	THREADENTRY32 thread;
	thread.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(snapshot, &thread))
	{
		std::map<DWORD, bool> threads;
		do
		{
			if (thread.th32OwnerProcessID != processId)
				continue;

			threads.insert(std::make_pair(thread.th32ThreadID, true));
			if (knownThreads.find(thread.th32ThreadID) != knownThreads.end())
				continue;

			HANDLE threadHandle = OpenThread(THREAD_ALL_ACCESS, FALSE, thread.th32ThreadID);
			if (threadHandle)
				notifyNewThread(thread.th32ThreadID, threadHandle);

		} while (Thread32Next(snapshot, &thread));

		knownThreads = std::move(threads);
	}

	CloseHandle(snapshot);
}

void Debugger::updateDebugging()
{
	assert(debuggingActive);

	for (;;)
	{
		DEBUG_EVENT dbgEvent;
		if (!WaitForDebugEvent(&dbgEvent, 0))
		{
			DWORD err = GetLastError();
			if (err != ERROR_SEM_TIMEOUT)
			{
				deactivateDebugging();
				finishAttaching();
			}
			return;
		}
		ContinueDebugEvent(dbgEvent.dwProcessId, dbgEvent.dwThreadId, DBG_EXCEPTION_NOT_HANDLED);

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
				deactivateDebugging();
				finishAttaching();
				break;

			case CREATE_PROCESS_DEBUG_EVENT:
				assert(!processHandle);
				processHandle = dbgEvent.u.CreateProcessInfo.hProcess;
				notifyNewThread(dbgEvent.dwThreadId, dbgEvent.u.CreateProcessInfo.hThread);
				knownThreads.insert(std::make_pair(dbgEvent.dwThreadId, true));
				// We're not using the image file, close the handle
				CloseHandle(dbgEvent.u.CreateProcessInfo.hFile);
				break;

			case EXIT_PROCESS_DEBUG_EVENT:
				// Display the process's exit code.
				break;

			case CREATE_THREAD_DEBUG_EVENT:
				knownThreads.insert(std::make_pair(dbgEvent.dwThreadId, true));
				notifyNewThread(dbgEvent.dwThreadId, dbgEvent.u.CreateThread.hThread);
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
	}
}

