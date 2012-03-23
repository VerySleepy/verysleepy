/*=====================================================================
profilerthread.h
----------------
File created by ClassTemplate on Thu Feb 24 19:29:41 2005

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
#ifndef __PROFILERTHREAD_H_666_
#define __PROFILERTHREAD_H_666_

#pragma warning(disable : 4786)//disable long debug name warning


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
	ProfilerThread(HANDLE target_process, const std::vector<HANDLE>& target_threads, SymbolInfo *sym_info);

	virtual ~ProfilerThread();


	//call this to start profiling.
	virtual void run();

	int getNumThreadsRunning() const { return numThreadsRunning; }
	bool getFailed() const { return failed; }
	int getSampleProgress() const { return numsamplessofar; }
	int getSymbolsPercent() const { return symbolsPercent; }
	const std::wstring &getFilename() const { return filename; }
	void setPaused(bool paused_) { paused = paused_; }

	void sample(SAMPLE_TYPE timeSpent);//for internal use.
private:
	//std::wstring demangleProcName(const std::wstring& mangled_name);
	void error(const std::wstring& what);

	void sampleLoop();
	void saveData();

	// DE: 20090325 callstacks and flatcounts are shared for all threads to profile
	std::map<CallStack, SAMPLE_TYPE> callstacks;
	std::map<PROFILER_ADDR, SAMPLE_TYPE> flatcounts;

	// DE: 20090325 one Profiler instance per thread to profile
	std::vector<Profiler> profilers;
	double duration;
	//int numsamples;
	int numsamplessofar;
	int numThreadsRunning;
	int symbolsPercent;
	bool paused;
	bool failed;
	HANDLE target_process;
	std::wstring filename;
	SymbolInfo *sym_info;
};



#endif //__PROFILERTHREAD_H_666_




