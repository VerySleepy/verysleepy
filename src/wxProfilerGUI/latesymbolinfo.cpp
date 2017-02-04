/*=====================================================================
latesymbolinfo.cpp
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

#include "latesymbolinfo.h"
#include <Dbgeng.h>
#include "../utils/dbginterface.h"
#include <comdef.h>
#include <sstream>
#include "../utils/except.h"

#include "profilergui.h"

void comenforce(HRESULT result, const char* where = NULL)
{
	if (result == S_OK)
		return;

	std::wostringstream message;
	if (where)
		message << where;

	_com_error error(result);
	message << ": " << error.ErrorMessage();
	message << " (error " << result << ")";

	throw SleepyException(message.str());
}


LateSymbolInfo::LateSymbolInfo()
	:	debugClient5(NULL), debugControl4(NULL), debugSymbols3(NULL)
{
}

LateSymbolInfo::~LateSymbolInfo()
{
	unloadMinidump();
}

// Send debugger output to the wxWidgets current logging facility.
// The UI implements a logging facility in the form of a log panel.
struct DebugOutputCallbacksWide : public IDebugOutputCallbacksWide
{
	HRESULT	STDMETHODCALLTYPE QueryInterface(__in REFIID WXUNUSED(InterfaceId), __out PVOID* WXUNUSED(Interface)) { return E_NOINTERFACE; }
	ULONG	STDMETHODCALLTYPE AddRef() { return 1; }
	ULONG	STDMETHODCALLTYPE Release() { return 0; }

	HRESULT	STDMETHODCALLTYPE Output(__in ULONG WXUNUSED(Mask), __in PCWSTR Text)
	{
		//OutputDebugStringW(Text);
		wxLogMessage(L"%s", Text);
		return S_OK;
	}
};

static DebugOutputCallbacksWide *debugOutputCallbacks = new DebugOutputCallbacksWide();

void LateSymbolInfo::loadMinidump(std::wstring& dumppath, bool delete_when_done)
{
	// Method credit to http://stackoverflow.com/a/8119364/21501

	if (debugClient5 || debugControl4 || debugSymbols3)
	{
		//throw SleepyException(L"Minidump symbols already loaded.");

		// maybe the user moved a .pdb to somewhere where we can now find it?
		unloadMinidump();
	}

	IDebugClient *debugClient = NULL;

	SetLastError(0);
	comenforce(DebugCreate(__uuidof(IDebugClient), (void**)&debugClient), "DebugCreate");
	comenforce(debugClient->QueryInterface(__uuidof(IDebugClient5 ), (void**)&debugClient5 ), "QueryInterface(IDebugClient5)" );
	comenforce(debugClient->QueryInterface(__uuidof(IDebugControl4), (void**)&debugControl4), "QueryInterface(IDebugControl4)");
	comenforce(debugClient->QueryInterface(__uuidof(IDebugSymbols3), (void**)&debugSymbols3), "QueryInterface(IDebugSymbols3)");
	comenforce(debugClient5->SetOutputCallbacksWide(debugOutputCallbacks), "IDebugClient5::SetOutputCallbacksWide");
	comenforce(debugSymbols3->SetSymbolOptions(SYMOPT_UNDNAME | SYMOPT_LOAD_LINES | SYMOPT_OMAP_FIND_NEAREST | SYMOPT_AUTO_PUBLICS | SYMOPT_DEBUG), "IDebugSymbols::SetSymbolOptions");

	std::wstring sympath;
	prefs.AdjustSymbolPath(sympath, true);

	comenforce(debugSymbols3->SetSymbolPathWide(sympath.c_str()), "IDebugSymbols::SetSymbolPath");
	comenforce(debugClient5->OpenDumpFileWide(dumppath.c_str(), NULL), "IDebugClient4::OpenDumpFileWide");
	comenforce(debugControl4->WaitForEvent(0, INFINITE), "IDebugControl::WaitForEvent");

	// Since we can't just enumerate all symbols in all modules referenced by the minidump,
	// we have to keep the debugger session open and query symbols as requested by the
	// profiler GUI.

	debugClient->Release(); // but keep the other ones

	// If we are given a temporary file, clean it up later
	if (delete_when_done)
		file_to_delete = dumppath;
}

void LateSymbolInfo::unloadMinidump()
{
	if (debugClient5)
	{
		debugClient5->EndSession(DEBUG_END_ACTIVE_TERMINATE);
		debugClient5->Release();
		debugClient5 = NULL;
	}
	if (debugControl4)
	{
		debugControl4->Release();
		debugControl4 = NULL;
	}
	if (debugSymbols3)
	{
		debugSymbols3->Release();
		debugSymbols3 = NULL;
	}

	if (!file_to_delete.empty())
	{
		wxRemoveFile(file_to_delete);
		file_to_delete.clear();
	}
}

wchar_t LateSymbolInfo::buffer[4096];

void LateSymbolInfo::filterSymbol(Database::Address address, std::wstring &module, std::wstring &procname, std::wstring &sourcefile, unsigned &sourceline)
{
	if (debugSymbols3)
	{
		ULONG moduleindex;
		if (debugSymbols3->GetModuleByOffset(address, 0, &moduleindex, NULL) == S_OK)
			if (debugSymbols3->GetModuleNameStringWide(DEBUG_MODNAME_MODULE, moduleindex, 0, buffer, _countof(buffer), NULL) == S_OK)
				module = buffer;

		if (debugSymbols3->GetNameByOffsetWide(address, buffer, _countof(buffer), NULL, NULL) == S_OK)
		{
			if (module.compare(buffer) != 0)
			{
				procname = buffer;

				// Remove redundant "Module!" prefix
				size_t modlength = module.length();
				if (procname.length() > modlength+1 && module.compare(0, modlength, procname, 0, modlength)==0 && procname[modlength] == '!')
					procname.erase(0, modlength+1);
			}
		}

		ULONG line;
		if (debugSymbols3->GetLineByOffsetWide(address, &line, buffer, _countof(buffer), NULL, NULL) == S_OK)
		{
			sourcefile = buffer;
			sourceline = line;
		}
	}
}
