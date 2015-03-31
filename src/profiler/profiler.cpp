/*=====================================================================
profiler.cpp
------------
File created by ClassTemplate on Thu Feb 24 19:00:30 2005

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
#include "profiler.h"


#include "../utils/stringutils.h"
#include "../utils/osutils.h"
#include "symbolinfo.h"
#include <process.h>
#include <iostream>
#include <assert.h>
#include <winnt.h>
#include "../utils/dbginterface.h"
#include "../utils/WoW64.h"

#ifdef _WIN64
#define CONTEXT64_FLAGS		(CONTEXT_AMD64 | CONTEXT_FULL)
#define CONTEXT32_FLAGS		(WOW64_CONTEXT_i386 | WOW64_CONTEXT_FULL)
typedef CONTEXT CONTEXT64;
typedef WOW64_CONTEXT CONTEXT32;
#else
#define CONTEXT32_FLAGS		(CONTEXT_i386 | CONTEXT_FULL)
typedef CONTEXT CONTEXT32;
#endif


// DE: 20090325: Profiler no longer owns callstack and flatcounts since it is shared between multipler profilers

Profiler::Profiler(HANDLE target_process_, HANDLE target_thread_,
				   std::map<CallStack, SAMPLE_TYPE>& callstacks_, std::map<PROFILER_ADDR, SAMPLE_TYPE>& flatcounts_)
:	target_process(target_process_),
	target_thread(target_thread_),
	callstacks(callstacks_),
	flatcounts(flatcounts_),
	is64BitProcess(Is64BitProcess(target_process_))
{
}

// DE: 20090325: Need copy constructor since it is put in a std::vector

Profiler::Profiler(const Profiler& iOther)
:	target_process(iOther.target_process),
	target_thread(iOther.target_thread),
	callstacks(iOther.callstacks),
	flatcounts(iOther.flatcounts),
	is64BitProcess(iOther.is64BitProcess)
{
}

// DE: 20090325: Need copy assignement since it is put in a std::vector

Profiler& Profiler::operator=(const Profiler& iOther)
{
	target_process = iOther.target_process;
	target_thread = iOther.target_thread;
	callstacks = iOther.callstacks;
	flatcounts = iOther.flatcounts;

	return *this;
}

Profiler::~Profiler()
{

}

// There are a couple of things than can cause StackWalk64 to not produce a correct callstack,
// if we happen to have stopped the process in an unfortunate place.
//
// We can hack around them ourselves here. This isn't essential, but helps clean up some
// otherwise bad callstacks.
void applyHacks(HANDLE process_handle, CONTEXT32 &context)
{
	// If we happen to be unlucky enough to stop in a DLL import forward,
	// (for example, if you call GetLastError in KERNEL32 nowadays, it actually forwards
	// to GetLastError in KERNELBASE via a little jump routine), then we have a problem.
	// DbgHelp will not provide the necessary FPO data to traverse the callstack from there,
	// presumably because these routine were generated by a tool other than the C++ compiler,
	// and there's no EBP frame to help either. This can cause parts of the callstack to go missing.
	//
	// So what we do is to search forward a few bytes, and if we see a jump, we pretend
	// we took the sample from there instead. This hopefully will give a much better result.
	//
	// Visual Studio seems not to suffer from the same problem generally, although you can still
	// trip it up on occasion, which makes me think they also have some kind of hack in there.
	BYTE tmp[16];
	SIZE_T numRead=0;

	// First, skip over any stub functions (a useless push/mov/pop header, followed by a jump).
	// Move instead to the jump target.
	if (ReadProcessMemory(process_handle, (LPCVOID)context.Eip, tmp, 16, &numRead) && numRead >= 16)
	{
		int n = 0;

		// Sometimes there's a small function header first, skip over that.
		if (tmp[n] == 0x8b && tmp[n+1] == 0xff) // mov edi, edi
			n += 2;
		if (tmp[n] == 0x55) // push ebp
			n++;
		if (tmp[n] == 0x8b && tmp[n+1] == 0xec) // mov ebp, esp
			n += 2;
		if (tmp[n] == 0x5d) // pop ebp
			n++;

		// Look for "jmp foo", and move the IP forward to 'foo'.
		BYTE *p = &tmp[n];
		if (p[0] == 0xeb)
		{
			char offset = (char)p[1];
			context.Eip += n+2 + (int)offset;
		}
	}

	// Skip over any jmp [__imp__blah] thunks.
	if (ReadProcessMemory(process_handle, (LPCVOID)context.Eip, tmp, 16, &numRead) && numRead >= 16)
	{
		// Look for "jmp [foo]", and move the IP forward to '[foo]'.
		if (tmp[0] == 0xff && tmp[1] == 0x25)
		{
			DWORD ptr = (tmp[5] << 24) | (tmp[4] << 16) | (tmp[3] << 8) | (tmp[2] << 0);
			if (ReadProcessMemory(process_handle, (LPCVOID)ptr, tmp, 4, &numRead) && numRead >= 4)
			{
				context.Eip = (tmp[3] << 24) | (tmp[2] << 16) | (tmp[1] << 8) | (tmp[0] << 0);
			}
		}
	}
}

bool Profiler::sampleTarget(SAMPLE_TYPE timeSpent, SymbolInfo *syminfo)
{
	// DE: 20090325: Moved declaration of stack variables to reduce size of code inside Suspend/Resume thread

	CallStack stack;
	stack.depth = 0;

	STACKFRAME64 frame;
	PROFILER_ADDR ip, sp, bp;
	void *context;
	DWORD machine;

#if defined(_WIN64)
	CONTEXT64 threadcontext64;
	CONTEXT32 threadcontext32;
	if (is64BitProcess)
	{
		context = &threadcontext64;
		threadcontext64.ContextFlags = CONTEXT64_FLAGS;
		machine = IMAGE_FILE_MACHINE_AMD64;

		// Can fail occasionally, for example if you have a debugger attached to the process.
		HRESULT result = SuspendThread(target_thread);
		if(result == 0xffffffff)
			return false;

		int prev_priority = GetThreadPriority(target_thread);
		SetThreadPriority(target_thread, THREAD_PRIORITY_TIME_CRITICAL);
		result = GetThreadContext(target_thread, &threadcontext64);
		SetThreadPriority(target_thread, prev_priority);

		if(!result){
			// DE: 20090325: If GetThreadContext fails we must be sure to resume thread again
			ResumeThread(target_thread);
			return false;
		}

		ip = threadcontext64.Rip;
		sp = threadcontext64.Rsp;
		bp = threadcontext64.Rbp;
	} else {
		context = &threadcontext32;
		threadcontext32.ContextFlags = CONTEXT32_FLAGS;
		machine = IMAGE_FILE_MACHINE_I386;

		// Can fail occasionally, for example if you have a debugger attached to the process.
		HRESULT result = fn_Wow64SuspendThread(target_thread);
		if(result == 0xffffffff)
			return false;

		int prev_priority = GetThreadPriority(target_thread);
		SetThreadPriority(target_thread, THREAD_PRIORITY_TIME_CRITICAL);
		result = fn_Wow64GetThreadContext(target_thread, &threadcontext32);
		SetThreadPriority(target_thread, prev_priority);

		if(!result){
			// DE: 20090325: If GetThreadContext fails we must be sure to resume thread again
			ResumeThread(target_thread);
			return false;
		}

		ip = threadcontext32.Eip;
		sp = threadcontext32.Esp;
		bp = threadcontext32.Ebp;
	}
#else
	CONTEXT32 threadcontext32;
	context = &threadcontext32;
	threadcontext32.ContextFlags = CONTEXT32_FLAGS;
	machine = IMAGE_FILE_MACHINE_I386;

	// Can fail occasionally, for example if you have a debugger attached to the process.
	HRESULT result = SuspendThread(target_thread);
	if(result == 0xffffffff)
		return false;

	int prev_priority = GetThreadPriority(target_thread);
	SetThreadPriority(target_thread, THREAD_PRIORITY_TIME_CRITICAL);
	result = GetThreadContext(target_thread, &threadcontext32);
	SetThreadPriority(target_thread, prev_priority);

	if(!result){
		// DE: 20090325: If GetThreadContext fails we must be sure to resume thread again
		ResumeThread(target_thread);
		return false;
	}

	applyHacks(target_process, threadcontext32);

	ip = threadcontext32.Eip;
	sp = threadcontext32.Esp;
	bp = threadcontext32.Ebp;
#endif

	DbgHelp *prevDbgHelp = NULL;
	bool first = true;

	while(true)
	{
		// See which module this IP is in.
		Module *mod = syminfo->getModuleForAddr(ip);
		DbgHelp *dbgHelp = mod ? mod->dbghelp : &dbgHelpMs;

		// Use whichever dbghelp stack walker is best for this module type.
		// If we're switching between types, restart the stack walk from
		// the current place.
		if (dbgHelp != prevDbgHelp)
		{
			prevDbgHelp = dbgHelp;
			memset(&frame, 0, sizeof(frame));
			frame.AddrStack.Offset = sp;
			frame.AddrPC.Offset = ip;
			frame.AddrFrame.Offset = bp;
			frame.AddrStack.Mode = frame.AddrPC.Mode = frame.AddrFrame.Mode = AddrModeFlat;
			frame.AddrReturn.Offset = ip;
			first = true;
		}

		// Add this IP to the stack trace.
		// We skip the first one, as the first call to StackWalk64
		// simply fills in more registers for the current frame,
		// rather than walking down to the next one.
		if (!first)
			stack.addr[stack.depth++] = ip;
		first = false;

		BOOL result = dbgHelp->StackWalk64(
			machine,
			target_process,
			target_thread,
			&frame,
			context,
			NULL,
			dbgHelp->SymFunctionTableAccess64,
			dbgHelp->SymGetModuleBase64,
			NULL
		);

		if (!result || stack.depth >= MAX_CALLSTACK_LEVELS)
			break;

		ip = (PROFILER_ADDR)frame.AddrPC.Offset;
		sp = (PROFILER_ADDR)frame.AddrStack.Offset;
		bp = (PROFILER_ADDR)frame.AddrFrame.Offset;

		// Stop once we hit the end of the stack.
		if (frame.AddrReturn.Offset == 0)
		{
			stack.addr[stack.depth++] = ip;
			break;
		}
	}

	if (!ResumeThread(target_thread))
		throw ProfilerExcep(L"ResumeThread failed.");

	//NOTE: this has to go after ResumeThread.  Otherwise mem allocation needed by std::map
	//may hit a lock held by the suspended thread.
	if (stack.depth > 0)
	{
		flatcounts[stack.addr[0]]+=timeSpent;
		callstacks[stack]+=timeSpent;
	}
	return true;
}

// returns true if the target thread has finished
bool Profiler::targetExited() const
{
	DWORD code = WaitForSingleObject(target_thread, 0);
	return (code == WAIT_OBJECT_0);
}


//void Profiler::saveIPs(std::ostream& stream)
//{
//	for (auto i = counts.begin(); i != counts.end(); ++i)
//	{
//		const Sample &sample = i->first;
//		int count = i->second;
//		stream << ::toHexString(sample.addr) << " " << count << "\n";
//	}
//
//	stream.flush();
//}
//
