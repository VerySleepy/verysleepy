/*=====================================================================
symbolinfo.h
------------
File created by ClassTemplate on Sat Mar 05 19:10:20 2005

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
#ifndef __SYMBOLINFO_H_666_
#define __SYMBOLINFO_H_666_


#include <string>
#include <windows.h>
#include <vector>
#include "profiler.h"

typedef void SymLogFn(const wchar_t *text);

struct DbgHelp;

class Module
{
public:
	Module(PROFILER_ADDR base_addr_, const std::wstring& name_, DbgHelp *dbghelp_)
	{
		base_addr = base_addr_;
		name = name_;
		dbghelp = dbghelp_;
	}
	PROFILER_ADDR base_addr;
	std::wstring name;
	DbgHelp *dbghelp;
};

/*=====================================================================
SymbolInfo
----------
Wrapper around some DbgHelp API stuff.
=====================================================================*/
class SymbolInfo
{
public:
	SymbolInfo();
	~SymbolInfo();

	void loadSymbols(HANDLE process_handle, bool download);//throws SymbolInfoExcep
	std::wstring saveMinidump();

	Module *getModuleForAddr(PROFILER_ADDR addr);
	const std::wstring getModuleNameForAddr(PROFILER_ADDR addr);
	const std::wstring getProcForAddr(PROFILER_ADDR addr, std::wstring& procfilepath_out, int& proclinenum_out);

	void getLineForAddr(PROFILER_ADDR addr, std::wstring& filepath_out, int& linenum_out);

	HANDLE process_handle;

private:
	std::vector<Module> modules;
	bool is64BitProcess;

	void addModule(const Module& module);
	void sortModules();

	friend BOOL CALLBACK EnumModules(PCWSTR ModuleName, DWORD64 BaseOfDll, PVOID UserContext);
	void loadSymbolsUsing(DbgHelp* dbgHelp, const std::wstring& sympath);//throws SymbolInfoExcep
	DbgHelp* getGccDbgHelp();
};

extern SymLogFn *g_symLog;

#endif //__SYMBOLINFO_H_666_
