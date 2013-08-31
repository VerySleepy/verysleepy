/*=====================================================================
Database.cpp
------------

Copyright (C) Nicholas Chapman
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
}

Database::~Database()
{
	clear();
}

void Database::clear()
{
	for (std::vector<Symbol *>::iterator i = symbols.begin(); i != symbols.end(); ++i)
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

bool Database::reload(bool collapseOSCalls, bool loadMinidump)
{
	return loadFromPath(profilepath, collapseOSCalls, loadMinidump);
}

bool Database::loadFromPath(const std::wstring& _profilepath, bool collapseOSCalls, bool loadMinidump)
{
	if(_profilepath != profilepath) {
		profilepath = _profilepath;
	}
	clear();

	wxFFileInputStream input(profilepath);
	if (!input.IsOk()) { wxLogError("Input stream error opening profile data."); return false; }

	// Check the version number required.
	{
		wxZipInputStream zipver(input);
		if (!zipver.IsOk()) { wxLogError("ZIP error opening profile data."); return false; }

		bool versionFound = false;
		while (wxZipEntry *entry = zipver.GetNextEntry())
		{
			wxString name = entry->GetInternalName();

			if (name.Left(8) == "Version " && name.Right(9) == " required")
			{
				versionFound = true;
				wxString ver = name.Mid(8, name.Length()-(8+9));
				if (ver != FORMAT_VERSION)
				{
					wxLogError("Cannot load capture file: %s", name.c_str());
					return false;
				}
			}
		}
	}

	wxZipInputStream zip(input);
	if (!zip.IsOk()) { wxLogError("ZIP error opening profile data."); return false; }

	while (wxZipEntry *entry = zip.GetNextEntry())
	{
		wxString name = entry->GetInternalName();

			 if (name == "Symbols.txt")		loadSymbols(zip);
		else if (name == "Callstacks.txt")	loadCallstacks(zip,collapseOSCalls);
		else if (name == "IPCounts.txt")	loadIpCounts(zip);
		else if (name == "Stats.txt")		loadStats(zip);
		else if (name == "minidump.dmp")	{ has_minidump = true; if(loadMinidump) this->loadMinidump(zip); }
		else if (name.Left(8) == "Version ") {}
		else {
			wxLogWarning("Other fluff found in capture file (%s)", name.c_str());
		}
	}

	setRoot(NULL);
	return true;
}

/// Add or find an entry to the map with the specified key.
/// Copies true to *pinserted if a new entry was added, false if an existing one was found.
/// Returns a reference to the new/existing value.
template<class MAP>
static typename MAP::value_type::second_type& map_emplace(MAP &map, const typename MAP::key_type &key, bool *pinserted=NULL)
{
	auto pair = map.emplace(std::make_pair(key, MAP::value_type::second_type()));
	if (pinserted) *pinserted = pair.second;
	return pair.first->second;
}

/// Add or find an entry in a string[id] vector / id[string] map pair, and return its ID.
template<typename ID>
static ID map_string(std::vector<std::wstring> &list, std::unordered_map<std::wstring, ID>&map, std::wstring key)
{
	bool inserted;
	ID &id = map_emplace(map, key, &inserted);
	if (inserted) // new entry
	{
		list.push_back(key);
		return id = list.size() - 1;
	}
	else // existing entry
		return id;
}

// Windows progress bar is limited to 0x10000 max.
static const __int64 kMaxProgress = 0x8000LL;

// read symbol table
void Database::loadSymbols(wxInputStream &file)
{
	wxTextInputStream str(file, wxT(" \t"), wxConvAuto(wxFONTENCODING_UTF8));

	std::unordered_map<std::wstring, const Symbol*> locsymbols;

	int filesize = file.GetSize();
	wxProgressDialog progressdlg(APPNAME, "Loading symbols...",
		kMaxProgress, theMainWin,
		wxPD_APP_MODAL|wxPD_AUTO_HIDE);

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
		// TODO: check if inserted is true
		::readQuote(stream, modulename);
		stream >> procname;
		::readQuote(stream, sourcefilename);
		stream >> info.sourceline;

		// Late symbol lookup
		late_sym_info.filterSymbol(modulename, procname, sourcefilename, info.sourceline);

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
		if (offset != wxInvalidOffset && offset != filesize)
			progressdlg.Update(kMaxProgress * offset / filesize);
	}
}

// read callstacks
void Database::loadCallstacks(wxInputStream &file,bool collapseKernelCalls)
{
	wxTextInputStream str(file);

	int filesize = file.GetSize();
	wxProgressDialog progressdlg(APPNAME, "Loading callstacks...",
		kMaxProgress, theMainWin,
		wxPD_APP_MODAL|wxPD_AUTO_HIDE);

	while (!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());

		CallStack callstack;
		stream >> callstack.samplecount;

		while (true)
		{
			std::wstring addrstr;
			stream >> addrstr;
			if (addrstr.empty())
				break;
			Address addr = hexStringTo64UInt(addrstr);

			if (collapseKernelCalls && addrinfo[addr].symbol->isCollapseFunction)
				callstack.addresses.clear();

			callstack.addresses.push_back(addr);
		}

		if (collapseKernelCalls)
		{
			if (callstack.addresses.size() && addrinfo[callstack.addresses[0]].symbol->isCollapseModule)
			{
				while (callstack.addresses.size() >= 2)
				{
					if (!addrinfo[callstack.addresses[1]].symbol->isCollapseModule)
						break;
					callstack.addresses.erase(callstack.addresses.begin());
				}
			}
		}

		callstack.symbols.resize(callstack.addresses.size());
		for (size_t i=0; i<callstack.addresses.size(); i++)
			callstack.symbols[i] = addrinfo[callstack.addresses[i]].symbol;

#if _MSC_VER >= 1600
		callstacks.push_back(std::move(callstack));
#else
		callstacks.push_back(callstack);
#endif

		wxFileOffset offset = file.TellI();
		if (offset != wxInvalidOffset && offset != filesize)
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

		std::sort(callstacks.begin(), callstacks.end(), Pred());

		progressdlg.Update(0, "Filtering...");

		std::vector<CallStack> filtered;
		for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); ++i)
		{
			int n = i - callstacks.begin();
			if (n % 256 == 0)
				progressdlg.Update(kMaxProgress * n / callstacks.size());

			if (!filtered.empty() && filtered.back().addresses == i->addresses)
				filtered.back().samplecount += i->samplecount;
			else
				filtered.push_back(*i);
		}

		std::swap(filtered, callstacks);
	}
}

void Database::loadIpCounts(wxInputStream &file)
{
	double totalcount = 0;
	wxTextInputStream str(file);

	str >> totalcount;

	int c = 0;
	while(!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());

		std::wstring addrstr;
		double count;

		stream >> addrstr;
		stream >> count;

		Address addr = hexStringTo64UInt(addrstr);
		AddrInfo *info = &addrinfo[addr];
		info->count += count;
		info->percentage += 100.0f * ((float)count / (float)totalcount);
	}
}

void Database::loadStats(wxInputStream &file)
{
	wxTextInputStream str(file);

	stats.clear();

	int c = 0;
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
	mainList.items.clear();
	mainList.totalcount = 0;
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
		wxPD_APP_MODAL|wxPD_REMAINING_TIME);

	mainList.items.clear();
	mainList.totalcount = 0;

	Symbol::ID currentRootID = currentRoot ? currentRoot->id : -1;

	int progress = 0;
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); ++i)
	{  
		// Only use call stacks that include the current root
		if (!includeCallstack(*i)) continue;

		exclusive[i->symbols[0]->id] += i->samplecount;
		std::vector<bool> seen(symbols.size());
		for (size_t n=0;n<i->symbols.size();n++)
		{
			Symbol::ID id = i->symbols[n]->id;

			// we filter out duplicates, to avoid getting funny numbers when 
			// using recursive functions.
			if (!seen[id])
			{
				inclusive[id] += i->samplecount;
				seen[id] = true;
			} 
			if (id == currentRootID) break;       // Stop handling the call stack if we encounter the root
		}
		mainList.totalcount += i->samplecount;

		progressdlg.Update(progress++);
	}

	for (Symbol::ID id=0; id < symbols.size(); id++)
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
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); ++i)
	{ 
		// Only use call stacks that include the current root
		if (!includeCallstack(*i)) continue;

		// Only include callstacks that have our symbol in.
		for (size_t n=0;n<i->symbols.size();n++)
		{
			if (i->symbols[n] == symbol)
			{
				ret.push_back(&*i);
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
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); ++i)
	{ 
		// Only use call stacks that include the current root
		if (!includeCallstack(*i)) continue;

		// Only include callstacks that have our symbol in.
		for (size_t n=0;n<i->symbols.size()-1;n++)
		{
			const Symbol *s = i->symbols[n];
			if (s == currentRoot) break;       // Stop handling the call stack if we encounter the root
			if (s == symbol)
			{
				Address caller = i->addresses[n+1];

				counts[caller] += i->samplecount;
				list.totalcount += i->samplecount;
			}
		}
	}

	for (std::map<Address, double>::const_iterator i = counts.begin(); i != counts.end(); ++i)
	{
		Item item;
		item.address = i->first;
		item.symbol = addrinfo.find(item.address)->second.symbol;
		item.inclusive = i->second;
		item.exclusive = i->second;
		list.items.push_back(item);
	}

	return list;
}

Database::List Database::getCallees(const Database::Symbol *symbol) const
{
	List list;
	std::map<const Symbol *, double> counts;
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); ++i)
	{ 
		// Only use call stacks that include the current root
		if (!includeCallstack(*i)) continue;

		double callstackCost = i->samplecount;

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

	for (std::map<const Symbol *, double>::const_iterator i = counts.begin(); i != counts.end(); ++i)
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
		late_sym_info.loadMinidump(dumppath, true);
	}
	catch (SymbolInfoExcep &e)
	{
		wxLogError("%ls", e.what());
	}
}

std::vector<double> Database::getLineCounts(FileID sourcefile)
{
	std::vector<double> linecounts;

	for each (auto &pair in addrinfo)
		if (pair.second.symbol->sourcefile == sourcefile)
		{
			int sourceline = pair.second.sourceline;
			if (linecounts.size() <= sourceline)
				linecounts.resize(sourceline+1);
			linecounts[sourceline] += pair.second.count;
		}

	return linecounts;
}
