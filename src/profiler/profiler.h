/*=====================================================================
profiler.h
----------
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

#pragma once
#ifndef __PROFILER_H_666_
#define __PROFILER_H_666_

#include <windows.h>
#include <map>
#include <iostream>
#include <string>
#include <vector>

//64 bit mode:
#if defined(_WIN64)
typedef unsigned long long PROFILER_ADDR;
#else
//32 bit mode:
typedef unsigned int PROFILER_ADDR;
#endif

typedef double SAMPLE_TYPE;
class SymbolInfo;

#define MAX_CALLSTACK_LEVELS 256

class CallStack
{
public:
	size_t depth;
	DWORD thread_id;
	PROFILER_ADDR addr[MAX_CALLSTACK_LEVELS];

	bool isBefore(const CallStack &other, bool considerThreadId) const
	{
		if (depth != other.depth)
			return (depth < other.depth);

		for (size_t n = 0; n < depth; n++)
		{
			if (addr[n] < other.addr[n])
				return true;
			if (addr[n] > other.addr[n])
				return false;
		}

		if (considerThreadId)
			return thread_id < other.thread_id;

		return false;
	}

	bool operator < (const CallStack &other) const
	{
		return isBefore(other, true);
	}
};

class ProfilerExcep
{
public:
	ProfilerExcep(const std::wstring& s_) : s(s_) {}
	~ProfilerExcep(){}

	const std::wstring& what() const { return s; }
private:
	std::wstring s;
};

/*=====================================================================
Profiler
--------
does the EIP sampling
=====================================================================*/
class Profiler
{
public:
	/*=====================================================================
	Profiler
	--------

	=====================================================================*/
	// DE: 20090325: Profiler no longer owns callstack since it is shared between multipler profilers
	Profiler(HANDLE target_process, HANDLE target_thread, DWORD target_thread_id,
		std::map<CallStack, SAMPLE_TYPE>& callstacks);

	// DE: 20090325: Need copy constructor since it is put in a std::vector
	Profiler(const Profiler& iOther);
	// DE: 20090325: Need copy assignement since it is put in a std::vector
	Profiler& operator=(const Profiler& iOther);

	~Profiler();

	// DE: 20090325: Profiler no longer owns callstack and flatcounts since it is shared between multipler profilers
	// AA: 20210821: Removed flatcounts since their contents can be reconstructed on load by iterating over
	//               callstack top address samples and aggregating times for equal keys
	std::map<CallStack, SAMPLE_TYPE> *callstacks;
	const bool is64BitProcess;

	bool sampleTarget(SAMPLE_TYPE timeSpent, SymbolInfo *syminfo);//throws ProfilerExcep
	bool targetExited() const;

	//void saveIPs(std::ostream& stream);//write IP values to a stream

	HANDLE getTarget(){ return target_thread; }
private:
	HANDLE target_process, target_thread;
	DWORD target_thread_id;
};



#endif //__PROFILER_H_666_
