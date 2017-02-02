/*=====================================================================
latesymbolinfo.h
--------------
Copyright (C) Vladimir Panteleev

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

#include <string>
#include <windows.h>
#include "database.h"

/*=====================================================================
LateSymbolInfo
----------
Handles symbols we load after loading a profile capture,
e.g. symbols loaded from included minidumps.
=====================================================================*/
class LateSymbolInfo
{
public:
	LateSymbolInfo();
	~LateSymbolInfo();

	void loadMinidump(std::wstring &dumppath, bool delete_when_done);
	void unloadMinidump();

	void filterSymbol(Database::Address address, std::wstring &module, std::wstring &procname, std::wstring &sourcefile, unsigned &sourceline);

private:
	static wchar_t buffer[4096];
	std::wstring file_to_delete;

	// Dbgeng COM objects for minidump symbols
	struct IDebugClient5  *debugClient5;
	struct IDebugControl4 *debugControl4;
	struct IDebugSymbols3 *debugSymbols3;


};
