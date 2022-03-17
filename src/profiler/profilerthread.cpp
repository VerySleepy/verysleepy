/*=====================================================================
profilerthread.cpp
------------------
File created by ClassTemplate on Thu Feb 24 19:29:41 2005

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

#include "../wxprofilergui/profilergui.h"
#include "profilerthread.h"
#include "threadinfo.h"
#include "debugger.h"
#include <wx/wfstream.h>
#include <wx/zipstrm.h>
#include <wx/txtstrm.h>

#include "../utils/stringutils.h"
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <Psapi.h>
#include "../appinfo.h"

#pragma comment(lib, "winmm.lib")

// DE: 20090325: Profiler has a list of threads to profile
// RM: 20130614: Profiler time can now be limited (-1 = until cancelled)
ProfilerThread::ProfilerThread(HANDLE target_process_, const std::vector<HANDLE>& target_threads, SymbolInfo *sym_info_, Debugger *debugger_)
:	profilers(),
	target_process(target_process_),
	sym_info(sym_info_),
	debugger(debugger_)
{
	// AA: 20210822: If we have a debugger, it will report all available threads
	//               So, only use the passed vector when we have no debugger
	if (!debugger)
	{
		// DE: 20090325: Profiler has a list of threads to profile, one Profiler instance per thread
		profilers.reserve(target_threads.size());
		for (HANDLE thread_h : target_threads)
		{
			DWORD thread_id = GetThreadId(thread_h);
			profilers.push_back(Profiler(target_process_, thread_h, thread_id, callstacks));
			thread_names[thread_id] = getThreadDescriptorName(thread_h);
		}
	}

	numsamplessofar = 0;
	done = false;
	failed = false;
	paused = false;
	cancelled = false;
	commit_suicide = false;
	symbolsPermille = 0;
	duration = 0;
	numThreadsRunning = (int)target_threads.size();
	status = L"Initializing";

	filename = wxFileName::CreateTempFileName(wxEmptyString);
}


ProfilerThread::~ProfilerThread()
{
	delete debugger;
}


void ProfilerThread::sample(const SAMPLE_TYPE timeSpent)
{
	// DE: 20090325: Profiler has a list of threads to profile, one Profiler instance per thread
	// RJM- We traverse them in random order. The act of profiling causes the Windows scheduler
	//      to re-schedule, and if we did them in sequence, it'll always schedule the first one.
	//      This starves the other N-1 threads. For lack of a better option, using a shuffle
	//      at least re-schedules them evenly.

	duration += timeSpent;

	const size_t count = profilers.size();
	if ( count == 0)
		return;

	size_t *order = (size_t *)alloca( count * sizeof(size_t) );
	for (size_t n=0;n<count;n++)
		order[n] = n;
	for (size_t n=count;n--;)
	{
		size_t i = rand() * count / (RAND_MAX+1);
		assert( i < count );
		std::swap( order[i], order[n] );
	}

	char *failedProfilers = (char *)alloca(count);
	memset(failedProfilers, 0, count);

	for (size_t n = 0;n < count; ++n)
	{
		Profiler& profiler = profilers[order[n]];
		try {
			if (profiler.sampleTarget(timeSpent, sym_info))
				++numsamplessofar;
			else
				failedProfilers[order[n]] = true;
		}
		catch (const ProfilerExcep& e)
		{
			error(_T("ProfilerExcep: ") + e.what());
			this->commit_suicide = true;
		}
	}

	for (ptrdiff_t n = (ptrdiff_t)count-1; n >= 0; --n)
	{
		if (!failedProfilers[n] || !profilers[n].targetExited())
			continue;
		profilers[n] = profilers.back();
		profilers.erase(std::prev(profilers.end()));
	}

	numThreadsRunning = (int)profilers.size();
}

class ProcPred
{
public:
	bool operator () (std::pair<std::wstring, int>& a, std::pair<std::wstring, int>& b)
	{
		return a.second > b.second;
	}
};

void ProfilerThread::sampleLoop()
{
	timeBeginPeriod(1);

	LARGE_INTEGER prev, now, start, freq;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&start);
	prev = start;

	bool minidump_saved = false;

	while(!this->commit_suicide)
	{
		if (paused)
		{
			Sleep(100);
			QueryPerformanceCounter(&prev);
			continue;
		}

		if (debugger)
			debugger->update();

		QueryPerformanceCounter(&now);

		__int64 diff = now.QuadPart - prev.QuadPart;
		double t = (double)diff / (double)freq.QuadPart;

		__int64 elapsed = now.QuadPart - start.QuadPart;
		if (!minidump_saved && prefs.saveMinidump>=0 && elapsed >= prefs.saveMinidump * freq.QuadPart)
		{
			minidump_saved = true;
			status = L"Saving minidump";
			minidump = sym_info->saveMinidump();
			status = NULL;
			continue;
		}

		sample(t);

		int ms = 100 / prefs.throttle;
		Sleep(ms);

		prev = now;
	}

	timeEndPeriod(1);
}

void ProfilerThread::saveData()
{
	//get process id of the process the target thread is running in
	//const DWORD process_id = GetProcessIdOfThread(profiler.getTarget());

	wxFFileOutputStream out(filename);
	wxZipOutputStream zip(out);
	wxTextOutputStream txt(zip, wxEOL_NATIVE, wxConvAuto(wxFONTENCODING_UTF8));

	if (!out.IsOk() || !zip.IsOk())
	{
		error(L"Error writing to file");
		return;
	}

	//------------------------------------------------------------------------

	if (!minidump.empty())
	{
		zip.PutNextEntry(_T("minidump.dmp"));
		beginProgress(L"Copying minidump", 100);
		{
			wxFFileInputStream stream(minidump);
			zip.Write(stream);
		}
		wxRemoveFile(minidump);
	}

	//------------------------------------------------------------------------
	beginProgress(L"Saving stats", 100);
	zip.PutNextEntry(_T("Stats.txt"));

	wchar_t tmp[4096] = L"?";
	GetModuleFileNameEx(target_process, NULL, tmp, 4096);
	time_t rawtime;
	time(&rawtime);
	txt << "Filename: " << tmp << "\n";
	txt << "Duration: " << duration << "\n";
	txt << "Date: " << asctime(localtime(&rawtime));
	txt << "Samples: " << numsamplessofar << "\n";

	//------------------------------------------------------------------------
	beginProgress(L"Summarizing results");

	std::map<PROFILER_ADDR, bool> used_addresses;
	std::map<DWORD, bool> used_thread_ids;

	for (auto i = callstacks.begin(); i != callstacks.end(); ++i)
	{
		const CallStack &callstack = i->first;
		used_thread_ids[callstack.thread_id] = true;
		for (size_t n=0;n<callstack.depth;n++)
		{
			used_addresses[callstack.addr[n]] = true;
		}
	}

	//------------------------------------------------------------------------
	beginProgress(L"Querying and saving symbols", used_addresses.size());
	zip.PutNextEntry(_T("Symbols.txt"));

	for (auto i = used_addresses.begin(); i != used_addresses.end(); ++i)
	{
		int proclinenum;
		std::wstring procfile;
		PROFILER_ADDR addr = i->first;

		const std::wstring proc_name = sym_info->getProcForAddr(addr, procfile, proclinenum);
		txt << ::toHexString(addr);
		txt << " ";
		writeQuote(txt, sym_info->getModuleNameForAddr(addr));
		txt << " ";
		writeQuote(txt, proc_name);
		txt << " ";
		writeQuote(txt, procfile);
		txt << " ";
		txt << ::toString(proclinenum);
		txt << '\n';

		if (updateProgress())
			return;
	}

	//------------------------------------------------------------------------
	beginProgress(L"Saving callstacks", callstacks.size());
	zip.PutNextEntry(_T("Callstacks.txt"));

	for (auto i = callstacks.begin(); i != callstacks.end();)
	{
		const CallStack &callstack = i->first;

		// write callstack addresses
		for( size_t d=0;d<callstack.depth;d++ )
			txt << " " << ::toHexString(callstack.addr[d]);
		txt << "\n";

		// write pairs of thread_id and count for each identical callstack
		do
		{
			txt << " " << (unsigned)i->first.thread_id;
			txt << " " << i->second;
			++i;
		}
		while ( i != callstacks.end() && !callstack.isBefore(i->first, false) );
		txt << "\n";

		if (updateProgress())
			return;
	}

	//------------------------------------------------------------------------
	beginProgress(L"Saving threads", used_thread_ids.size());
	zip.PutNextEntry(_T("Threads.txt"));

	for (auto &tid : used_thread_ids)
	{
		txt << (unsigned)tid.first << "\n";
		txt << thread_names[tid.first] << "\n";

		if (updateProgress())
			return;
	}

	//------------------------------------------------------------------------
	// Change FORMAT_VERSION when the file format changes
	// (and becomes unreadable by older versions of Sleepy).
	zip.PutNextEntry(L"Version " _T(FORMAT_VERSION) L" required");
	txt << FORMAT_VERSION << "\n";


	if (!out.IsOk() || !zip.IsOk())
	{
		error(L"Error writing to file");
		return;
	}
}

void ProfilerThread::run()
{
	wxLog::EnableLogging();

	if (debugger)
		debugger->attach([this](Debugger::NotifyData const &notification) {
			if (notification.eventType != Debugger::NOTIFY_NEW_THREAD)
				return;
			profilers.push_back(Profiler(target_process, notification.threadHandle, notification.threadId, callstacks));
			thread_names[notification.threadId] = getThreadDescriptorName(notification.threadHandle);
		});

	status = NULL;
	try
	{
		sampleLoop();
	} catch(ProfilerExcep& e) {
		// see if it's an actual error, or did the thread just finish naturally
		for (auto it = profilers.begin(); it != profilers.end(); ++it)
		{
			const Profiler& profiler(*it);
			if (!profiler.targetExited())
			{
				error(L"ProfilerExcep: " + e.what());
				return;
			}
		}

		numThreadsRunning = 0;
	}

	status = L"Exiting";

	if (debugger)
		debugger->detach();

	if (cancelled)
		return;

	setPriority(THREAD_PRIORITY_NORMAL);

	saveData();

	done = true;
}

void ProfilerThread::error(const std::wstring& what)
{
	failed = true;
	std::cerr << "ProfilerThread Error: " << what << std::endl;

	::MessageBox(NULL, std::wstring(L"Error: " + what).c_str(), L"Profiler Error", MB_OK);
}

void ProfilerThread::beginProgress(std::wstring stage, int total)
{
	symbolsStage = stage;
	symbolsDone = 0;
	symbolsTotal = total;
	symbolsPermille = 0;
}

bool ProfilerThread::updateProgress()
{
	symbolsDone++;
	symbolsPermille = MulDiv(symbolsDone, 1000, symbolsTotal);
	if (cancelled)
	{
		failed = true;
		return true;
	}
	return false;
}
