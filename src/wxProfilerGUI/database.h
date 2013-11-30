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
#include "../utils/container.h"

bool IsOsFunction(wxString proc);
void AddOsFunction(wxString proc);
void RemoveOsFunction(wxString proc);

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
	typedef unsigned long long Address;
	typedef size_t FileID;
	typedef size_t ModuleID;

	/// Represents one function (as it appears in function lists).
	struct Symbol
	{
		/// Note: IDs may not persist across DB reloads
		/// (e.g. due to changes in symbol load settings).
		/// Use addresses to persistently refer to symbols in the GUI.
		typedef size_t ID;
		ID id;

		/// Points to the address of the start of the symbol
		/// (or the closest thing we have to that).
		/// Multiple addresses may belong to the same symbol.
		Address  address;

		std::wstring procname;
		FileID       sourcefile;
		ModuleID     module;

		bool isCollapseFunction;
		bool isCollapseModule;
	};

	/// Represents one address we encountered during profiling
	struct AddrInfo
	{
		AddrInfo() : symbol(NULL), sourceline(0), count(0), percentage(0) {}

		// Symbol info
		const Symbol *symbol;
		unsigned      sourceline;

		// IP counts
		double count;
		float  percentage;
	};

	struct Item
	{
		const Symbol *symbol;

		/// Might be different from symbol->address
		/// (e.g. it's the call site for callstacks).
		Address address;

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
		std::vector<Address> addresses;

		// symbols[i] == addrsymbols[addresses[i]]. For convenience/performance.
		std::vector<const Symbol *> symbols;

		double samplecount;
	};

	Database();
	virtual ~Database();
	void clear();

	void loadFromPath(const std::wstring& profilepath,bool collapseOSCalls,bool loadMinidump);
	void reload(bool collapseOSCalls, bool loadMinidump);

	const Symbol *getSymbol(Symbol::ID id) const { return symbols[id]; }
	Symbol::ID getSymbolCount() const { return symbols.size(); }
	const std::wstring &getFileName(FileID id) const { return files[id]; }
	FileID getFileCount() const { return files.size(); }
	const std::wstring &getModuleName(ModuleID id) const { return modules[id]; }
	ModuleID getModuleCount() const { return modules.size(); }

	const AddrInfo *getAddrInfo(Address addr) { return &addrinfo.at(addr); }

	void setRoot(const Symbol *root);
	const Symbol *getRoot() const { return currentRoot; }

	const List &getMainList() const { return mainList; }
	List getCallers(const Symbol *symbol) const;
	List getCallees(const Symbol *symbol) const;
	std::vector<const CallStack*> getCallstacksContaining(const Symbol *symbol) const;
	std::vector<double> getLineCounts(FileID sourcefile);

	std::vector<std::wstring> stats;

	std::wstring getProfilePath() const { return profilepath; }

	bool has_minidump;

private:
	/// Symbol::ID -> Symbol*
	std::vector<Symbol *> symbols;

	/// filename <-> FileID
	std::vector<std::wstring> files;
	std::unordered_map<std::wstring, FileID> filemap;

	/// module name <-> ModuleID
	std::vector<std::wstring> modules;
	std::unordered_map<std::wstring, ModuleID> modulemap;

	/// Address -> module/procname/sourcefile/sourceline
	std::unordered_map<Address, AddrInfo> addrinfo;

	std::vector<CallStack> callstacks;
	List mainList;
	std::wstring profilepath;
	const Symbol *currentRoot;

	void loadSymbols(wxInputStream &file);
	void loadCallstacks(wxInputStream &file,bool collapseKernelCalls);
	void loadIpCounts(wxInputStream &file);
	void loadStats(wxInputStream &file);
	void loadMinidump(wxInputStream &file);
	void scanMainList();

	bool includeCallstack(const CallStack &callstack) const;

	// Any additional symbols we can load after opening a capture
	class LateSymbolInfo *late_sym_info;
};

#endif //__DATABASE_H_666_
