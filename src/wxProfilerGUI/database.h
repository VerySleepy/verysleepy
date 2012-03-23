/*=====================================================================
database.h
----------

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
#ifndef __DATABASE_H_666_
#define __DATABASE_H_666_

#include "profilergui.h"
#include "lineinfo.h"
#include <deque>

bool IsOsFunction(wxString function);
void AddOsFunction(wxString function);
void RemoveOsFunction(wxString function);

bool IsOsModule(wxString mod);
void AddOsModule(wxString mod);
void RemoveOsModule(wxString mod);

/*=====================================================================
Database
--------

=====================================================================*/
class Database
{
public:
	struct Symbol
	{
		std::wstring id;
		std::wstring module;
		std::wstring procname;
		std::wstring sourcefile;
		bool		isCollapseFunction;
		bool		isCollapseModule;
		int         sourceline;
	};

	struct Item
	{
		const Symbol *symbol;
		double inclusive, exclusive;
	};

	struct List
	{
		List() { totalcount = 0; }

		std::vector<Item> items;
		double totalcount;
	};

	struct CallStack
	{
		std::vector<const Symbol *> stack;
		double samplecount;

		bool contains (const Symbol *s) const
		{
			for (std::vector<const Symbol *>::const_iterator it=stack.begin();it!=stack.end();++it)
			{
				const Symbol *symbol = *it;
				if (symbol==s) return true;
			}
			return false;
		}
	};

	Database();
	virtual ~Database();
	void clear();

	bool loadFromPath(const std::wstring& profilepath,bool collapseOSCalls);
	bool reload(bool collapseOSCalls);
	void scanMainList();
	void setRoot(const Symbol *root);
	const Symbol *getRoot() const { return currentRoot; }

	const List &getMainList() const { return mainList; }
	List getCallers(const Symbol *symbol) const;
	List getCallees(const Symbol *symbol) const;
	std::vector<const CallStack*> getCallstacksContaining(const Symbol *symbol) const;
	const LINEINFOMAP *getLineInfo(const std::wstring &srcfile) const;
	
	std::vector<std::wstring> stats;

	std::wstring getProfilePath() const { return profilepath; }

private:
	std::map<std::wstring, Symbol *> symbols;
	std::deque<CallStack> callstacks;
	std::map<std::wstring, LINEINFOMAP > fileinfo;
	List mainList;
	std::wstring profilepath;
	const Symbol *currentRoot;

	void loadSymbols(wxInputStream &file);
	void loadProcList(wxInputStream &file,bool collapseKernelCalls);
	void loadIpCounts(wxInputStream &file);
	void loadStats(wxInputStream &file);
};

#endif //__DATABASE_H_666_
