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
	theDatabase->reload(true);
	theMainWin->Reset();
}

void RemoveOsFunction(wxString function)
{
	osFunctions.Remove(function);
	theDatabase->reload(true);
	theMainWin->Reset();
}

bool IsOsModule(wxString mod)
{
	return osModules.Contains(mod);
}

void AddOsModule(wxString mod)
{
	osModules.Add(mod);
	theDatabase->reload(true);
	theMainWin->Reset();
}

void RemoveOsModule(wxString mod)
{
	osModules.Remove(mod);
	theDatabase->reload(true);
	theMainWin->Reset();
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
	for (std::map<std::wstring, Symbol *>::iterator i = symbols.begin(); i != symbols.end(); i++)
	{
		delete i->second;
	}

	symbols.clear();
	callstacks.clear();
	fileinfo.clear();
	mainList.items.clear();
	mainList.totalcount = 0;
}

bool Database::reload(bool collapseOSCalls)
{
	return loadFromPath(profilepath, collapseOSCalls);
}

bool Database::loadFromPath(const std::wstring& _profilepath, bool collapseOSCalls)
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
		else if (name.Left(8) == "Version ") {}
		else {
			wxLogWarning("Other fluff found in capture file (%s)", name.c_str());
		}
	}

	setRoot(NULL);
	return true;
}

// read symbol table
void Database::loadSymbols(wxInputStream &file)
{
	wxTextInputStream str(file, wxT(" \t"), wxConvAuto(wxFONTENCODING_UTF8));
	int c = 0;
	while(!file.Eof())
	{
		wxString line = str.ReadLine();
		if (line.IsEmpty())
			break;

		std::wistringstream stream(line.c_str().AsWChar());
		Symbol *sym = new Symbol;

		stream >> sym->id;
		::readQuote(stream, sym->module);
		::readQuote(stream, sym->procname);
		::readQuote(stream, sym->sourcefile);
		stream >> sym->sourceline;
		sym->isCollapseFunction = osFunctions.Contains(sym->procname.c_str());
		sym->isCollapseModule = osModules.Contains(sym->module.c_str());
		symbols[sym->id] = sym;
	}
}

// read callstacks
void Database::loadProcList(wxInputStream &file,bool collapseKernelCalls)
{
	wxTextInputStream str(file);

	wxProgressDialog progressdlg("Sleepy", "Please wait while the profile database is scanned...",
		(int)file.GetSize(), theMainWin,
		wxPD_APP_MODAL|wxPD_AUTO_HIDE);

	class CallStackPtrComp
	{
		CallStack *p;
	public:
		CallStackPtrComp(CallStack *_p): p(_p) {}
		bool operator <(const CallStackPtrComp b) const { return p->stack < b.p->stack; }
		CallStack *Get() { return p; }
	};

	std::set<CallStackPtrComp> callstackSet;

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
			std::wstring id;
			stream >> id;
			if (id.empty())
				break;

			const Symbol *sym = symbols[id];

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

		std::set<CallStackPtrComp>::iterator iter = callstackSet.find(&callstack);
		if(iter != callstackSet.end()) {
			iter->Get()->samplecount += callstack.samplecount;
			continue;
		}
		callstacks.push_back(callstack);
		callstackSet.insert(&callstacks[callstacks.size()-1]);

		wxFileOffset offset = file.TellI();
		if(offset != wxInvalidOffset)
			progressdlg.Update(offset);
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

	wxProgressDialog progressdlg("Sleepy", "Please wait while the profile database is scanned...",
		(int)callstacks.size(), theMainWin,
		wxPD_APP_MODAL|wxPD_REMAINING_TIME);

	mainList.items.clear();
	mainList.totalcount = 0;

	int progress = 0;
	for (std::deque<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
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
	for (std::deque<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
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
	for (std::deque<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
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
	for (std::deque<CallStack>::const_iterator i = callstacks.begin(); i != callstacks.end(); i++)
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
