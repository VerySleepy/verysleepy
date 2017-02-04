/*=====================================================================
profilerthread.h
----------------
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

#pragma once
#ifndef __PROFILERTHREAD_H_666_
#define __PROFILERTHREAD_H_666_

#include "../utils/mythread.h"
#include "profiler.h"
#include "symbolinfo.h"

// DE: 20090325 Profiler thread now has a vector of threads to profile
#include <vector>

/*=====================================================================
ProfilerThread
--------------
a thread that runs the profiler at a certain frequency
=====================================================================*/
class ProfilerThread : public MyThread
{
public:
	/*=====================================================================
	ProfilerThread
	--------------
	HANDLE target_thread:
		handle to thread to profile.

	int num_samples:
		number of samples to take.  Takes ~1000 samples per sec.
		The greater the number of samples, the more accurate the profile.
		Use at least 40000 or so.

	=====================================================================*/
	// DE: 20090325 Profiler thread now has a vector of threads to profile
	// RM: 20130614 Profiler time can now be limited (-1 = until cancelled)
	ProfilerThread(HANDLE target_process, const std::vector<HANDLE>& target_threads, SymbolInfo *sym_info);

	virtual ~ProfilerThread();


	//call this to start profiling.
	virtual void run();

	int getNumThreadsRunning() const { return numThreadsRunning; }
	bool getDone() const { return done; }
	bool getFailed() const { return failed; }
	const wchar_t* getStatus() const { return status; }
	int getSampleProgress() const { return numsamplessofar; }
	void getSymbolsProgress(int *permille, std::wstring *stage) const { *permille = symbolsPermille; *stage = symbolsStage; }
	const std::wstring &getFilename() const { return filename; }
	void setPaused(bool paused_) { paused = paused_; }
	void cancel() { cancelled = true; }

	void sample(const SAMPLE_TYPE timeSpent);//for internal use.
private:
	//std::wstring demangleProcName(const std::wstring& mangled_name);
	void error(const std::wstring& what);

	void sampleLoop();
	void saveData();

	std::wstring symbolsStage;
	int symbolsPermille, symbolsDone, symbolsTotal;
	void beginProgress(std::wstring stage, int total=0);
	bool updateProgress();

	// DE: 20090325 callstacks and flatcounts are shared for all threads to profile
	std::map<CallStack, SAMPLE_TYPE> callstacks;
	std::map<PROFILER_ADDR, SAMPLE_TYPE> flatcounts;

	// DE: 20090325 one Profiler instance per thread to profile
	std::vector<Profiler> profilers;
	double duration;
	//int numsamples;
	const wchar_t* status;
	int numsamplessofar;
	int numThreadsRunning;
	bool done;
	bool paused;
	bool failed;
	bool cancelled;
	HANDLE target_process;
	std::wstring filename;
	std::wstring minidump;
	SymbolInfo *sym_info;

	DWORD startTick;
};



#endif //__PROFILERTHREAD_H_666_
