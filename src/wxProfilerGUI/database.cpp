/*=====================================================================
Database.cpp
------------

Copyright (C) Nicholas Chapman
Copyright (C) Richard Mitton
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

http://www.gnu.org/copyleft/gpl.html.
=====================================================================*/
#include "database.h"

#include "../utils/stringutils.h"
#include "sourceview.h"
#include <wx/mstream.h>
#include <fstream>
#include <set>
#include "mainwin.h"
#include "../profiler/symbolinfo.h"
#include <algorithm>
#include "../appinfo.h"
#include "../utils/except.h"
#include "latesymbolinfo.h"

Database *theDatabase;

StringSet osModules(L"osmodules.txt",false);
StringSet osFunctions(L"osfunctions.txt",true);

bool IsOsFunction(wxString proc)
{
	return osFunctions.Contains(proc);
}

void AddOsFunction(wxString proc)
{
	osFunctions.Add(proc);
	theMainWin->reload();
}

void RemoveOsFunction(wxString proc)
{
	osFunctions.Remove(proc);
	theMainWin->reload();
}

bool IsOsModule(wxString mod)
{
	return osModules.Contains(mod);
}

void AddOsModule(wxString mod)
{
	osModules.Add(mod);
	theMainWin->reload();
}

void RemoveOsModule(wxString mod)
{
	osModules.Remove(mod);
	theMainWin->reload();
}

Database::Database()
{
	assert(!theDatabase);
	theDatabase = this;
	late_sym_info = new LateSymbolInfo();
}

Database::~Database()
{
	clear();
	delete late_sym_info;
}

void Database::clear()
{
	for (auto i = symbols.begin(); i != symbols.end(); ++i)
		if (*i)
			delete *i;

	symbols.clear();
	files.clear();
	filemap.clear();
	addrinfo.clear();
	callstacks.clear();
	mainList.items.clear();
	mainList.totalcount = 0;
	has_minidump = false;
}

void Database::reload(bool collapseOSCalls, bool loadMinidump)
{
	loadFromPath(profilepath, collapseOSCalls, loadMinidump);
}

void Database::loadFromPath(const std::wstring& _profilepath, bool collapseOSCalls, bool loadMinidump)
{
	if(_profilepath != profilepath)
		profilepath = _profilepath;
	clear();

	wxFFileInputStream input(profilepath);
	enforce(input.IsOk(), "Input stream error opening profile data.");

	// Check the version number required.
	{
		wxZipInputStream zipver(input);
		enforce(zipver.IsOk(), "ZIP error opening profile data.");

		bool versionFound = false;
		while (wxZipEntry *entry = zipver.GetNextEntry())
		{
			wxString name = entry->GetInternalName();

			if (name.Left(8) == "Version " && name.Right(9) == " required")
			{
				versionFound = true;
				wxString ver = name.Mid(8, name.Length()-(8+9));
				enforce(ver == FORMAT_VERSION, wxString::Format("Cannot load capture file: %s", name.c_str()).c_str());
			}
		}

		enforce(versionFound, "Unrecognized capture file");
	}

	wxZipInputStream zip(input);
	enforce(zip.IsOk(), "ZIP error opening profile data.");

	while (wxZipEntry *entry = zip.GetNextEntry())
	{
		wxString name = entry->GetInternalName();

			 if (name == "Symbols.txt")		loadSymbols(zip);
		else if (name == "Callstacks.txt")	loadCallstacks(zip,collapseOSCalls);
		else if (name == "Threads.txt")     loadThreads(zip);
		else if (name == "Stats.txt")		loadStats(zip);
		else if (name == "minidump.dmp")	{ has_minidump = true; if(loadMinidump) this->loadMinidump(zip); }
		else if (name.Left(8) == "Version ") {}
		else
			wxLogWarning("Other fluff found in capture file (%s)\n", name.c_str());
	}

	setRoot(NULL);
}

// Windows progress bar is limited to 0x10000 max.
static const __int64 kMaxProgress = 0x8000LL;

// read symbol table
void Database::loadSymbols(wxInputStream &file)
{
	wxTextInputStream str(file, wxT(" \t"), wxConvAuto(wxFONTENCODING_UTF8));

	size_t filesize = file.GetSize();
	wxProgressDialog progressdlg(APPNAME, "Loading symbols...",
		kMaxProgress+1, theMainWin,
		wxPD_APP_MODAL|wxPD_AUTO_HIDE);

	std::unordered_map<std::wstring, const Symbol*> locsymbols;

	bool warnedDupAddress = false;
	while (!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());

		std::wstring addrstr;
		stream >> addrstr;
		Address addr = hexStringTo64UInt(addrstr);

		std::wstring sourcefilename, modulename, procname;

		bool inserted;
		AddrInfo &info = map_emplace(addrinfo, addr, &inserted);
		::readQuote(stream, modulename);
		::readQuote(stream, procname);
		::readQuote(stream, sourcefilename);
		stream >> info.sourceline;
		if (!inserted)
		{
			if (!warnedDupAddress)
				wxLogWarning("Duplicate address in symbol list:\nAddress: " + addrstr + "\nSymbol: " + procname);
			warnedDupAddress = true;
			continue;
		}
		enforce(stream.eof(), "Trailing data in line: " + line);

		// Late symbol lookup
		late_sym_info->filterSymbol(addr, modulename, procname, sourcefilename, info.sourceline);

		// Convert filename and module strings to a numeric IDs
		FileID   fileid   = map_string(files  , filemap  , sourcefilename);
		ModuleID moduleid = map_string(modules, modulemap, modulename    );

		// Build a key string for grouping addresses belonging to the same symbol
		std::wostringstream locstream;
		locstream << modulename << '/' << sourcefilename << '/' << procname;
		std::wstring loc = locstream.str();

		// Create a new symbol entry, or lookup the existing one, based on the key
		const Symbol *&sym = map_emplace(locsymbols, loc, &inserted);
		if (inserted) // new symbol, judging by its location?
		{
			Symbol *newsym = new Symbol;
			newsym->id                 = symbols.size();
			newsym->address            = addr;
			newsym->procname           = procname;
			newsym->sourcefile         = fileid;
			newsym->module             = moduleid;
			newsym->isCollapseFunction = osFunctions.Contains(procname  .c_str());
			newsym->isCollapseModule   = osModules  .Contains(modulename.c_str());
			symbols.push_back(newsym);
			sym = newsym;
		}

		info.symbol = sym;

		wxFileOffset offset = file.TellI();
		if (offset != wxInvalidOffset && offset != (wxFileOffset)filesize)
			progressdlg.Update(kMaxProgress * offset / filesize);
	}

	// The unordered_map destructor takes a very long time to run.
	progressdlg.Update(kMaxProgress, "Tidying things up...");
}

static void addSampleInfo(std::vector<Database::SampleInfo> &samples, Database::SampleInfo const &info)
{
	auto it = std::lower_bound(samples.begin(), samples.end(), info, [](auto &i0, auto &i1) { return i0.threadid < i1.threadid; });
	if (it == samples.end() || it->threadid != info.threadid) {
		samples.insert(it, info);
	} else {
		it->count += info.count;
	}
}

static void addSamplesInfo(std::vector<Database::SampleInfo> &dst, std::vector<Database::SampleInfo> const &src)
{
	for (auto &s : src)
		addSampleInfo(dst, s);
}

static double getSampleCount(std::vector<Database::SampleInfo> const &samples, std::vector<Database::ThreadID> const &filterThreads)
{
	double count = 0;
	if (filterThreads.empty())
	{
		for (auto &sample : samples)
			count += sample.count;
	}
	else
	{
		std::vector<Database::SampleInfo>::const_iterator s = samples.begin();
		for (auto tid : filterThreads)
		{
			s = std::lower_bound(s, samples.end(), tid, [](Database::SampleInfo const &si, Database::ThreadID t) { return si.threadid < t; });
			if (s == samples.end())
				break;
			if (s->threadid == tid)
				count += s->count;
		}
	}
	return count;
}

// read callstacks
void Database::loadCallstacks(wxInputStream &file,bool collapseKernelCalls)
{
	wxTextInputStream str(file);

	size_t filesize = file.GetSize();
	wxProgressDialog progressdlg(APPNAME, "Loading callstacks...",
		kMaxProgress, theMainWin,
		wxPD_APP_MODAL|wxPD_AUTO_HIDE);

	while (!file.Eof())
	{
		wxString lineAddr = str.ReadLine();
		wxString lineSamples = str.ReadLine();
		if (lineAddr.IsEmpty() || lineSamples.IsEmpty())
			break;

		std::wistringstream streamAddr(lineAddr.c_str().AsWChar());

		CallStack callstack;
		AddrInfo *topAddrInfo = NULL;

		int depth = 0;
		while (true)
		{
			std::wstring addrstr;
			streamAddr >> addrstr;
			if (addrstr.empty())
				break;
			Address addr = hexStringTo64UInt(addrstr);

			if (depth == 0)
			{
				topAddrInfo = &addrinfo.at(addr);
			}

			if (collapseKernelCalls && addrinfo.at(addr).symbol->isCollapseFunction)
				callstack.addresses.clear();

			callstack.addresses.push_back(addr);
			++depth;
		}

		std::wistringstream streamSamples(lineSamples.c_str().AsWChar());
		while (true)
		{
			SampleInfo sample;
			if (!(streamSamples >> sample.threadid))
				break;

			if (!(streamSamples >> sample.count))
				break;

			callstack.samples.push_back(sample);
		}

		if (topAddrInfo)
		{
			addSamplesInfo(topAddrInfo->samples, callstack.samples);
		}

		if (collapseKernelCalls)
		{
			if (callstack.addresses.size() >= 2 && addrinfo.at(callstack.addresses[0]).symbol->isCollapseModule)
			{
				do
				{
					if (!addrinfo.at(callstack.addresses[1]).symbol->isCollapseModule)
						break;
					callstack.addresses.erase(callstack.addresses.begin());
				}
				while (callstack.addresses.size() >= 2);
			}
		}

		callstack.symbols.resize(callstack.addresses.size());
		for (size_t i=0; i<callstack.addresses.size(); i++)
			callstack.symbols[i] = addrinfo.at(callstack.addresses[i]).symbol;

		callstacks.emplace_back(std::move(callstack));

		wxFileOffset offset = file.TellI();
		if (offset != wxInvalidOffset && offset != (wxFileOffset)filesize)
			progressdlg.Update(kMaxProgress * offset / filesize);
	}

	struct Pred
	{
		bool operator () (const CallStack &a, const CallStack &b)
		{
			long l = a.addresses.size() - b.addresses.size();
			return l ? l<0 : a.addresses < b.addresses;
		}
	};

	// Sort and filter repeating callstacks
	{
		progressdlg.Update(0, "Sorting...");
		progressdlg.Pulse();

		std::stable_sort(callstacks.begin(), callstacks.end(), Pred());

		progressdlg.Update(0, "Filtering...");

		std::vector<CallStack> filtered;
		const auto total = callstacks.size();
		for (size_t i = 0; i < total; ++i)
		{
			if (i % 256 == 0)
				progressdlg.Update(kMaxProgress * i / total);

			auto& item = callstacks[i];
			if (!filtered.empty() && filtered.back().addresses == item.addresses)
				addSamplesInfo(filtered.back().samples, item.samples);
			else
				filtered.emplace_back(std::move(item));
		}

		std::swap(filtered, callstacks);
	}
}

void Database::loadThreads(wxInputStream &file)
{
	wxTextInputStream str(file);

	size_t filesize = file.GetSize();
	wxProgressDialog progressdlg(APPNAME, "Loading threads...",
		kMaxProgress, theMainWin,
		wxPD_APP_MODAL | wxPD_AUTO_HIDE);

	while (!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());

		ThreadID tid;
		stream >> tid;

		std::wstring thread_name;
		stream >> thread_name;

		threadNames[tid] = thread_name;

		wxFileOffset offset = file.TellI();
		if (offset != wxInvalidOffset && offset != (wxFileOffset)filesize)
			progressdlg.Update(kMaxProgress * offset / filesize);
	}
}

void Database::loadStats(wxInputStream &file)
{
	wxTextInputStream str(file);

	stats.clear();

	while(!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		stats.push_back(line.c_str().AsWChar());
	}
}

void Database::setRoot(const Database::Symbol *root)
{
	currentRoot = root;
	scanMainList();
}

bool Database::includeCallstack(const CallStack &callstack) const
{
	if (currentRoot)
		return std::find(callstack.symbols.begin(), callstack.symbols.end(), currentRoot) != callstack.symbols.end();
	return true;
}

void Database::scanMainList()
{
	std::vector<double> exclusive(symbols.size()), inclusive(symbols.size());

	wxProgressDialog progressdlg(APPNAME, "Scanning profile database...",
		(int)callstacks.size(), theMainWin,
		wxPD_APP_MODAL|wxPD_AUTO_HIDE);

	mainList.items.clear();
	mainList.items.reserve(symbols.size());
	mainList.totalcount = 0;

	Symbol::ID currentRootID = currentRoot ? currentRoot->id : -1;

	int progress = 0;
	for (auto it = callstacks.begin(); it != callstacks.end(); ++it)
	{
		const auto& i = *it;
		// Only use call stacks that include the current root
		if (!includeCallstack(i))
			continue;

		double iSampleCount = getFilteredSampleCount(i.samples);
		exclusive[i.symbols[0]->id] += iSampleCount;
		std::vector<bool> seen(symbols.size());
		for (size_t n = 0; n < i.symbols.size(); ++n)
		{
			Symbol::ID id = i.symbols[n]->id;

			// we filter out duplicates, to avoid getting funny numbers when
			// using recursive functions.
			if (!seen[id])
			{
				inclusive[id] += iSampleCount;
				seen[id] = true;
			}
			if (id == currentRootID) break;       // Stop handling the call stack if we encounter the root
		}
		mainList.totalcount += iSampleCount;

		progressdlg.Update(progress++);
	}

	for (Symbol::ID id = 0; id < symbols.size(); ++id)
	{
		Item item;
		item.symbol = symbols[id];
		item.address = item.symbol->address;
		item.exclusive = exclusive[id];
		item.inclusive = inclusive[id];
		mainList.items.push_back(item);
	}
}

std::vector<const Database::CallStack*> Database::getCallstacksContaining(const Database::Symbol *symbol) const
{
	std::vector<const CallStack *> ret;
	for (auto it = callstacks.begin(); it != callstacks.end(); ++it)
	{
		const auto& i = *it;
		// Only use call stacks that include the current root
		if (!includeCallstack(i)) continue;

		// Only include callstacks that have our symbol in.
		for (size_t n=0;n<i.symbols.size();n++)
		{
			if (i.symbols[n] == symbol)
			{
				ret.push_back(&i);
				break;
			}
		}
	}
	return ret;
}

Database::List Database::getCallers(const Database::Symbol *symbol) const
{
	List list;
	std::map<Address, double> counts;
	for (auto it = callstacks.begin(); it != callstacks.end(); ++it)
	{
		const auto& i = *it;
		// Only use call stacks that include the current root
		if (!includeCallstack(i)) continue;

		// Only include callstacks that have our symbol in.
		for (size_t n=0;n<i.symbols.size()-1;n++)
		{
			const Symbol *s = i.symbols[n];
			if (s == currentRoot) break;       // Stop handling the call stack if we encounter the root
			if (s == symbol)
			{
				Address caller = i.addresses[n+1];

				double iSampleCount = getFilteredSampleCount(i.samples);
				counts[caller] += iSampleCount;
				list.totalcount += iSampleCount;
			}
		}
	}

	for (auto i = counts.begin(); i != counts.end(); ++i)
	{
		Item item;
		item.address = i->first;
		item.symbol = addrinfo.at(item.address).symbol;
		item.inclusive = i->second;
		item.exclusive = i->second;
		list.items.push_back(item);
	}

	return std::move(list);
}

Database::List Database::getCallees(const Database::Symbol *symbol) const
{
	List list;
	std::map<const Symbol *, double> counts;
	for (auto i = callstacks.begin(); i != callstacks.end(); ++i)
	{
		// Only use call stacks that include the current root
		if (!includeCallstack(*i)) continue;

		double callstackCost = getFilteredSampleCount(i->samples);

		// Only include callstacks that have our symbol in.
		for (size_t n=1;n<i->symbols.size();n++)
		{
			if (i->symbols[n] == symbol)
			{
				const Symbol *callee = i->symbols[n-1];
				counts[callee] += callstackCost;
				list.totalcount += callstackCost;
			}
			if (i->symbols[n] == currentRoot) break;       // Stop handling the call stack if we encounter the root
		}
	}

	for (auto i = counts.begin(); i != counts.end(); ++i)
	{
		Item item;
		item.symbol = i->first;
		item.address = item.symbol->address;
		item.inclusive = i->second;
		item.exclusive = i->second;
		list.items.push_back(item);
	}

	return list;
}

Database::SymbolSamples Database::getSymbolSamples(const Symbol *symbol) const
{
	SymbolSamples samples;
	samples.symbol = symbol;

	for (auto i = callstacks.begin(); i != callstacks.end(); ++i)
	{
		// Only use call stacks that include the current root
		if (!includeCallstack(*i)) continue;

		// Only include callstacks that have our symbol in.
		for (size_t n = 0; n < i->symbols.size(); n++)
		{
			if (i->symbols[n] == symbol)
			{
				if (n == 0)
					addSamplesInfo(samples.exclusive, i->samples);
				addSamplesInfo(samples.inclusive, i->samples);
			}
			if (i->symbols[n] == currentRoot) break;       // Stop handling the call stack if we encounter the root
		}
	}

	samples.totalcount = getFilteredSampleCount(samples.inclusive);

	return samples;
}

void Database::loadMinidump(wxInputStream &file)
{
	wxFFile minidump_file;
	std::wstring dumppath = wxFileName::CreateTempFileName(wxEmptyString, &minidump_file);
	wxFFileOutputStream minidump_stream(minidump_file);
	minidump_stream.Write(file);
	minidump_stream.Close();
	minidump_file.Close();

	try
	{
		late_sym_info->loadMinidump(dumppath, true);
	}
	catch (SleepyException &e)
	{
		wxLogError("%ls\n", e.wwhat());
		// Continue loading database
	}
}

std::vector<double> Database::getLineCounts(FileID sourcefile)
{
	std::vector<double> linecounts;

	for each (auto &pair in addrinfo)
		if (pair.second.symbol->sourcefile == sourcefile)
		{
			unsigned sourceline = pair.second.sourceline;
			if (linecounts.size() <= size_t(sourceline))
				linecounts.resize(sourceline+1);
			double count = getSampleCount(pair.second.samples, filterThreads);
			linecounts[sourceline] += count;
		}

	return linecounts;
}

double Database::getFilteredSampleCount(std::vector<SampleInfo> const &samples) const
{
	return getSampleCount(samples, filterThreads);
}

void Database::setFilterThreads(std::vector<ThreadID> const &threads)
{
	filterThreads = threads;
	std::sort(filterThreads.begin(), filterThreads.end());
	scanMainList();
}

