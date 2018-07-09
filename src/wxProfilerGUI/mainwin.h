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
#include "logview.h"

#include <wx/propgrid/propgrid.h>
#include <deque>

/// Cache per-symbol view settings so we don't
/// have to compute them on every refresh.
struct ViewState
{
	std::unordered_set<Database::Address> highlighted, filtered;
};

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
	void OnNew(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);

	void OnSaveAs(wxCommandEvent& event);
	void OnExportAsCsv(wxCommandEvent& event);
	void OnExportAsCallgrind(wxCommandEvent& event);
	void OnLoadMinidumpSymbols(wxCommandEvent& event);
	void OnCollapseOS(wxCommandEvent& event);
	void OnStats(wxCommandEvent& event);
	void OnBack(wxCommandEvent& event);
	void OnBackUpdate(wxUpdateUIEvent& event);
	void OnForward(wxCommandEvent& event);
	void OnForwardUpdate(wxUpdateUIEvent& event);
	void OnResetToRoot(wxCommandEvent& event);
	void OnResetToRootUpdate(wxUpdateUIEvent& event);
	void OnResetFilters(wxCommandEvent& event);
	void OnFiltersChanged(wxPropertyGridEvent& event);

	void OnDocumentation(wxCommandEvent& event);
	void OnSupport(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	/// Called after loading a database
	/// (after construction, and in OnOpen).
	/// Initialize anything database-specific here.
	void reset();

	/// Refresh proc lists.
	/// Preserves selection.
	/// Does not reload the database.
	void refresh();

	/// Reload the database.
	/// Needed to apply any settings that are applied during
	/// database loading, such as collapsing OS calls.
	/// Does not refresh().
	void reload(bool loadMinidump=false);

	void clear();

	/// Switch selection to a given symbol.
	/// Does not repopulate the secondary views.
	/// Called when clicking on a particular symbol.
	void focusSymbol(const Database::AddrInfo *addrinfo);

	/// Inspect a given symbol.
	/// Opens the corresponding symbol properties in all related views.
	/// Implies focusSymbol(symbol).
	/// Called when double-clicking on a particular symbol.
	void inspectSymbol(const Database::AddrInfo *addrinfo, bool addtohistory=true);

	/// Called by SourceView to update the status bar.
	void setSourcePos(const std::wstring& currentfile, int currentline);

	const ViewState *getViewState() { return &viewstate; }

	void setFilter(const wxString &name, const wxString &value);
	void setHighlight(const std::vector<Database::Address> &addresses, bool set);

	/// Non-modal (status bar) progress display
	void setProgress(const wchar_t *text, int max=0);
	void updateProgress(int pos);

private:
	// any class wishing to process wxWindows events must use this macro
	DECLARE_EVENT_TABLE()

	wxPanel* panel;
	ProcList* proclist;
	ProcList* callers;
	ProcList* callees;
	CallstackView* callStack;
	SourceView* sourceview;
	LogView* log;
	Database *database;
	std::wstring profilepath;

	// Used by setSourcePos
	std::wstring currentfile;
	int currentline;

	wxAuiNotebook	*modes;

	wxAuiManager *aui;
	wxAuiManager *auiTab1;
	wxString contentString;

	wxAuiNotebook *callViews;
	wxAuiNotebook *sourceAndLog;

	wxPropertyGrid *filters;

	wxMenuItem *collapseOSCalls;

	ViewState viewstate;

	std::deque<const Database::AddrInfo*> history;
	size_t historyPos;

	wxGauge *gauge;

	void buildFilterAutocomplete();

	/// Apply the filter settings in the wxPropertyGrid to viewstate.
	void applyFilters();

	/// Called when the symbol strings have changed in one way or another.
	void symbolsChanged();

	void showSource(const Database::AddrInfo *addrinfo);

	void updateStatusBar();
};

extern MainWin *theMainWin;



#endif //__MAINWIN_H_666_
