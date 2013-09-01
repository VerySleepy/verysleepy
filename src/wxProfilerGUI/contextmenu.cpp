/*=====================================================================
launchdlg.cpp
----------------

Copyright (C) Johan Kohler

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

#include "CallstackView.h"
#include "contextmenu.h"
#include "mainwin.h"
#include <wx/menu.h>

enum {
	ID_COLLAPSE_FUNC=2001,
	ID_COLLAPSE_MOD,
	ID_SET_ROOT,
	ID_FILTER_FUNC,
	ID_FILTER_MODULE,
	ID_FILTER_SOURCE,
	ID_HIGHLIGHT,
	ID_UNHIGHLIGHT,
};

class FunctionMenuWindow: public wxWindow
{
public:
	int option;
	FunctionMenuWindow(wxWindow *parent) : wxWindow(parent,-1), option(0) {}
	DECLARE_EVENT_TABLE()
	void OnMenu(wxCommandEvent& event)
	{
		option = event.GetId();
	}
};


BEGIN_EVENT_TABLE(FunctionMenuWindow, wxWindow)
EVT_MENU(ID_COLLAPSE_FUNC, FunctionMenuWindow::OnMenu)
EVT_MENU(ID_COLLAPSE_MOD, FunctionMenuWindow::OnMenu)
EVT_MENU(ID_SET_ROOT, FunctionMenuWindow::OnMenu)
EVT_MENU(ID_FILTER_FUNC, FunctionMenuWindow::OnMenu)
EVT_MENU(ID_FILTER_MODULE, FunctionMenuWindow::OnMenu)
EVT_MENU(ID_FILTER_SOURCE, FunctionMenuWindow::OnMenu)
EVT_MENU(ID_HIGHLIGHT, FunctionMenuWindow::OnMenu)
EVT_MENU(ID_UNHIGHLIGHT, FunctionMenuWindow::OnMenu)
END_EVENT_TABLE()

void FunctionMenu(wxListCtrl *list, Database *database)
{
	FunctionMenuWindow funcWindow(list);
	wxMenu *menu = new wxMenu;

	Database::Address addr;
	const Database::Symbol* sym;
	std::vector<Database::Address> selection;

	{
		long i = list->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_FOCUSED);
		if (i < 0)
			return;
		addr = list->GetItemData(i);
		sym = database->getAddrInfo(addr)->symbol;
	}

	for (long item = -1;;)
	{
		item = list->GetNextItem(item,
			wxLIST_NEXT_ALL,
			wxLIST_STATE_SELECTED);
		if (item == -1)
			break;

		selection.push_back(list->GetItemData(item));
	}

	if (selection.size() == 0)
		return;

	// Focused symbol properties
	wxString procname       = sym->procname;
	wxString sourcefilename = database->getFileName  (sym->sourcefile);
	wxString modulename     = database->getModuleName(sym->module    );

	if (selection.size() == 1)
	{
		wxString modUpper = modulename;
		modUpper.UpperCase();

		menu->AppendCheckItem(ID_COLLAPSE_FUNC, "Collapse child calls")->Check(IsOsFunction(procname));
		menu->AppendCheckItem(ID_COLLAPSE_MOD , wxString::Format("Collapse all %s calls", modUpper))->Check(IsOsModule(modUpper));
		menu->AppendCheckItem(ID_SET_ROOT     , wxString::Format("Set root to %s", procname));
		menu->AppendSeparator();

		menu->AppendCheckItem(ID_FILTER_FUNC  , wxString::Format("Filter functions to %s", procname      ));
		menu->AppendCheckItem(ID_FILTER_MODULE, wxString::Format("Filter Module to %s"   , modulename    ));
		menu->AppendCheckItem(ID_FILTER_SOURCE, wxString::Format("Filter Source to %s"   , sourcefilename));
		menu->AppendSeparator();
	}

	wxString highlightTarget = selection.size()==1 ? sym->procname : L"selected";
	if (set_get(theMainWin->getViewState()->highlighted, addr))
		menu->AppendCheckItem(ID_UNHIGHLIGHT, wxString::Format("Unhighlight %s", highlightTarget));
	else
		menu->AppendCheckItem(ID_HIGHLIGHT  , wxString::Format("Highlight %s"  , highlightTarget));

	funcWindow.PopupMenu(menu);
	switch(funcWindow.option)
	{
	case ID_COLLAPSE_FUNC:
		if (IsOsFunction(procname))
			RemoveOsFunction(procname);
		else
			AddOsFunction(procname);
		theMainWin->refresh();
		break;

	case ID_COLLAPSE_MOD:
		if (IsOsModule(modulename))
			RemoveOsModule(modulename);
		else
			AddOsModule(modulename);
		theMainWin->refresh();
		break;

	case ID_SET_ROOT:
		database->setRoot(sym);
		theMainWin->refresh();
		break;

	case ID_FILTER_FUNC:
		theMainWin->setFilter("procname", procname);
		break;

	case ID_FILTER_MODULE:
		theMainWin->setFilter("module", modulename);
		break;

	case ID_FILTER_SOURCE:
		theMainWin->setFilter("sourcefile", sourcefilename);
		break;

	case ID_HIGHLIGHT:
		theMainWin->setHighlight(selection, true);
		break;
	case ID_UNHIGHLIGHT:
		theMainWin->setHighlight(selection, false);
		break;
	}
}

