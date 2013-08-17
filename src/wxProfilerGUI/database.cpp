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

Database *theDatabase;

StringSet osModules(L"osmodules.txt",false);
StringSet osFunctions(L"osfunctions.txt",true);

bool IsOsFunction(wxString function)
{
	return osFunctions.Contains(function);
}

void AddOsFunction(wxString function)
{
	osFunctions.Add(function);
	theMainWin->reload();
}

void RemoveOsFunction(wxString function)
{
	osFunctions.Remove(function);
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
	for (std::vector<Symbol *>::iterator i = symbols.begin(); i != symbols.end(); i++)
		if (*i)
			delete *i;

	symbols.clear();
	callstacks.clear();
	fileinfo.clear();
	mainList.items.clear();
	mainList.totalcount = 0;
	has_minidump = false;
	max_symbol_id = -1;
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

	wxFFileInputStream in(profilepath);
	wxZipInputStream zip(in);
	wxZipInputStream zipver(in);

	if (!in.IsOk() || !zip.IsOk() || !zipver.IsOk())
	{
		wxLogError("The profile data cannot be read.");
		return false;
	}

	// Check the version number required.
	while(true)
	{
		wxZipEntry *entry = zipver.GetNextEntry();
		if ( !entry )
			break;
		 
		wxString name = entry->GetInternalName();

		if (name.Left(8) == "Version " && name.Right(9) == " required")
		{
			wxString ver = name.Mid(8, name.Length()-(8+9));

			// Add other versions here any time the file format changes.
			const char *supportedVersions[] = {
				"0.7",
				"0.8",
				"0.81",
				"0.82",
			};

			bool isSupported = false;
			for (int n=0;n<sizeof(supportedVersions)/sizeof(char*);n++)
			{
				if (ver == supportedVersions[n])
				{
					isSupported = true;
					break;
				}
			}

			if (!isSupported)
			{
				wxLogWarning("Cannot load capture file: %s", name.c_str());
				return false;
			}
		}
	}

	while(true)
	{
		wxZipEntry *entry = zip.GetNextEntry();
		if ( !entry )
			break;
		 
		wxString name = entry->GetInternalName();

			 if (name == "Symbols.txt")		loadSymbols(zip);
		else if (name == "Callstacks.txt")	loadProcList(zip,collapseOSCalls);
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

/// Translate a symbol ID string, as it appears in a text file, to an unique numeric ID.
/// Currently, we assume the convention as currently implemented when writing the capture -
/// every symbol ID is just the string "sym" followed by a decimal number.
Database::Symbol::ID Database::translateSymbolID(const std::wstring &name)
{
	Database::Symbol::ID id;
	if (name.length() < 4 || name[0]!='s' || name[1]!='y' || name[2]!='m' || !wxString(name).substr(3).ToLong(&id))
	{
		wxLogError(L"Invalid symbol name: %s", name.c_str());
		return 0;
	}
	if (max_symbol_id < id)
		max_symbol_id = id;
	return id;
}

// read symbol table
void Database::loadSymbols(wxInputStream &file)
{
	wxTextInputStream str(file, wxT(" \t"), wxConvAuto(wxFONTENCODING_UTF8));
	while(!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());
		Symbol *sym = new Symbol;

		std::wstring idstr;
		stream >> idstr;
		sym->id = translateSymbolID(idstr);

		::readQuote(stream, sym->module);
		::readQuote(stream, sym->procname);
		::readQuote(stream, sym->sourcefile);
		stream >> sym->sourceline;

		late_sym_info.filterSymbol(sym->module, sym->procname, sym->sourcefile, sym->sourceline);

		sym->isCollapseFunction = osFunctions.Contains(sym->procname.c_str());
		sym->isCollapseModule = osModules.Contains(sym->module.c_str());

		if (symbols.size() <= (size_t)sym->id)
			symbols.resize(sym->id+1);
		symbols[sym->id] = sym;
	}
}

// read callstacks
void Database::loadProcList(wxInputStream &file,bool collapseKernelCalls)
{
	wxTextInputStream str(file);

	// Windows progress bar is limited to 0x10000 max.
	static const __int64 PROGRESS_MAX = 0x8000LL;

	int filesize = file.GetSize();
	wxProgressDialog progressdlg(APPNAME, "Loading profile database...",
		PROGRESS_MAX, theMainWin,
		wxPD_APP_MODAL|wxPD_AUTO_HIDE);

	while(!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());

		CallStack callstack;
		stream >> callstack.samplecount;

		while(true)
		{
			std::wstring idstr;
			stream >> idstr;
			if (idstr.empty())
				break;

			const Symbol *sym = symbols[translateSymbolID(idstr)];

			if(collapseKernelCalls && sym->isCollapseFunction) {
				callstack.stack.clear();
			}

			callstack.stack.push_back(sym);
		}

		if(collapseKernelCalls) {
			if(callstack.stack.size() && callstack.stack[0]->isCollapseModule) {
				while(callstack.stack.size() >= 2) {
					if(	!callstack.stack[1]->isCollapseModule )
					{
						break;
					}
					callstack.stack.erase(callstack.stack.begin());
				}
			}
		}

#if _MSC_VER >= 1600
		callstacks.push_back(std::move(callstack));
#else
		callstacks.push_back(callstack);
#endif

		wxFileOffset offset = file.TellI();
		if (offset != wxInvalidOffset && offset != filesize)
			progressdlg.Update(PROGRESS_MAX * offset / filesize);
	}

	struct Pred
	{
		bool operator () (const CallStack &a, const CallStack &b)
		{
			long l = a.stack.size() - b.stack.size();
			return l ? l<0 : a.stack < b.stack;
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
				progressdlg.Update(PROGRESS_MAX * n / callstacks.size());

			if (!filtered.empty() && filtered.back().stack == i->stack)
				filtered.back().samplecount += i->samplecount;
			else
				filtered.push_back(*i);
		}

		std::swap(filtered, callstacks);
	}
}

void Database::loadIpCounts(wxInputStream &file)
{
	double totallinecount = 0;
	wxTextInputStream str(file);

	str >> totallinecount;

	int c = 0;
	while(!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());

		std::wstring memaddr;
		stream >> memaddr;

		double count;
		stream >> count;

		std::wstring srcfile;
		int linenum;

		::readQuote(stream, srcfile);
		stream >> linenum;

		late_sym_info.filterIP(memaddr, srcfile, linenum);

		LineInfo& lineinfo = (fileinfo[srcfile])[linenum];
		lineinfo.count += count;
		lineinfo.percentage += 100.0f * ((float)count / (float)totallinecount);
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

void Database::scanMainList()
{
	std::map<const Symbol *, double> exclusive, inclusive;

	wxProgressDialog progressdlg(APPNAME, "Scanning profile database...",
		(int)callstacks.size(), theMainWin,
		wxPD_APP_MODAL|wxPD_REMAINING_TIME);

	mainList.items.clear();
	mainList.totalcount = 0;

	int progress = 0;
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
	{  
		// Only use call stacks that include the current root
		if (currentRoot && !i->contains(currentRoot)) continue;

		exclusive[i->stack[0]] += i->samplecount;
		std::map<const Symbol *, bool> seen;
		for (size_t n=0;n<i->stack.size();n++)
		{
			// we filter out duplicates, to avoid getting funny numbers when 
			// using recursive functions.
			if (!seen[i->stack[n]])
			{
				inclusive[i->stack[n]] += i->samplecount;
				seen[i->stack[n]] = true;
			} 
			if (i->stack[n] == currentRoot) break;       // Stop handling the call stack if we encounter the root
		}
		mainList.totalcount += i->samplecount;

		progressdlg.Update(progress++);
	}

	for (std::map<const Symbol *, double>::const_iterator i = inclusive.begin(); i != inclusive.end(); i++)
	{
		Item item;
		item.symbol = i->first;
		item.exclusive = exclusive[item.symbol];
		item.inclusive = i->second;
		mainList.items.push_back(item);
	}
}

std::vector<const Database::CallStack*> Database::getCallstacksContaining(const Database::Symbol *symbol) const
{
	std::vector<const CallStack *> ret;
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
	{ 
		// Only use call stacks that include the current root
		if (currentRoot && !i->contains(currentRoot)) continue;

		// Only include callstacks that have our symbol in.
		for (size_t n=0;n<i->stack.size();n++)
		{
			if (i->stack[n] == symbol)
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
	std::map<const Symbol *, double> counts;
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
	{ 
		// Only use call stacks that include the current root
		if (currentRoot && !i->contains(currentRoot)) continue;

		// Only include callstacks that have our symbol in.
		for (size_t n=0;n<i->stack.size()-1;n++)
		{
			if (i->stack[n] == currentRoot) break;       // Stop handling the call stack if we encounter the root
			if (i->stack[n] == symbol)
			{
				const Symbol *caller = i->stack[n+1];

				counts[caller] += i->samplecount;
				list.totalcount += i->samplecount;
			}
		}
	}

	for (std::map<const Symbol *, double>::const_iterator i = counts.begin(); i != counts.end(); i++)
	{
		Item item;
		item.symbol = i->first;
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
	for (std::vector<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
	{ 
		// Only use call stacks that include the current root
		if (currentRoot && !i->contains(currentRoot)) continue;

		double callstackCost = i->samplecount;

		// Only include callstacks that have our symbol in.
		for (size_t n=1;n<i->stack.size();n++)
		{
			if (i->stack[n] == symbol)
			{
				const Symbol *callee = i->stack[n-1];
				counts[callee] += callstackCost;
				list.totalcount += callstackCost;
			}
			if (i->stack[n] == currentRoot) break;       // Stop handling the call stack if we encounter the root
		}
	}

	for (std::map<const Symbol *, double>::const_iterator i = counts.begin(); i != counts.end(); i++)
	{
		Item item;
		item.symbol = i->first;
		item.inclusive = i->second;
		item.exclusive = i->second;
		list.items.push_back(item);
	}

	return list;
}

const LINEINFOMAP *Database::getLineInfo(const std::wstring &srcfile) const
{
	std::map<std::wstring, LINEINFOMAP >::const_iterator i = fileinfo.find(srcfile);
	if (i != fileinfo.end())
	{
		return &i->second;
	} else {
		return NULL;
	}
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
