/*=====================================================================
mainwin.h
---------
File created by ClassTemplate on Sun Mar 13 21:12:40 2005

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

http://www.gnu.org/copyleft/gpl.html.
=====================================================================*/
#ifndef __MAINWIN_H_666_
#define __MAINWIN_H_666_

#include "profilergui.h"
#include "proclist.h"
#include "sourceview.h"
#include "CallstackView.h"

/*=====================================================================
MainWin
-------

=====================================================================*/
class MainWin : public wxFrame
{
public:
	/*=====================================================================
	MainWin
	-------

	=====================================================================*/
	MainWin(const wxString& title, const std::wstring& profilepath, Database *database);

	virtual ~MainWin();

	// event handlers (these functions should _not_ be virtual)
	void OnClose(wxCloseEvent& event);
	void OnQuit(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSaveAs(wxCommandEvent& event);
	void OnExportAsCsv(wxCommandEvent& event);
	void OnCollapseOS(wxCommandEvent& event);
	void OnStats(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void SetTopOfTree(wxCommandEvent& event);
	void ResetToRoot(wxCommandEvent& event);
	void ResetToRootUpdate(wxUpdateUIEvent& event);

	void Reset();
	void setCurrent(const std::wstring& currentfile, int currentline);

private:
	// any class wishing to process wxWindows events must use this macro
	DECLARE_EVENT_TABLE()

	wxPanel* panel;
	ProcList* proclist;
	ProcList* callers;
	ProcList* callees;
	CallstackView* callStack;
	SourceView* sourceview;
	Database *database;
	std::wstring profilepath;

	std::wstring currentfile;
	int currentline;

	wxAuiNotebook	*modes;

	wxAuiManager *aui;
	wxAuiManager *auiTab1;
	wxString contentString;

	wxAuiNotebook *callViews;

	wxMenuItem *collapseOSCalls;
};

extern MainWin *theMainWin;



#endif //__MAINWIN_H_666_




