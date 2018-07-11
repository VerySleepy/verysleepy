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
#include <wx/clipbrd.h>
#include <sstream>

enum {
	ID_COLLAPSE_FUNC=2001,
	ID_COLLAPSE_MOD,
	ID_SET_ROOT,
	ID_FILTER_FUNC,
	ID_FILTER_MODULE,
	ID_FILTER_SOURCE,
	ID_HIGHLIGHT,
	ID_UNHIGHLIGHT,
	ID_COPY,
};

class FunctionMenuWindow : public wxWindow
{
public:
	int option;

	FunctionMenuWindow(wxWindow *parent) : wxWindow(parent, -1), option(0), mPushed(false)
	{
		this      ->Bind(wxEVT_MENU          , &FunctionMenuWindow::OnMenu     , this, wxID_ANY);
		theMainWin->Bind(wxEVT_MENU_OPEN     , &FunctionMenuWindow::OnOpen     , this, wxID_ANY);
		theMainWin->Bind(wxEVT_MENU_CLOSE    , &FunctionMenuWindow::OnClose    , this, wxID_ANY);
		theMainWin->Bind(wxEVT_MENU_HIGHLIGHT, &FunctionMenuWindow::OnHighlight, this, wxID_ANY);
	}

	~FunctionMenuWindow()
	{
		theMainWin->Unbind(wxEVT_MENU_OPEN     , &FunctionMenuWindow::OnOpen     , this, wxID_ANY);
		theMainWin->Unbind(wxEVT_MENU_CLOSE    , &FunctionMenuWindow::OnClose    , this, wxID_ANY);
		theMainWin->Unbind(wxEVT_MENU_HIGHLIGHT, &FunctionMenuWindow::OnHighlight, this, wxID_ANY);
	}

private:
	void OnMenu(wxCommandEvent& event)
	{
		option = event.GetId();
	}

	void OnOpen(wxMenuEvent &event)
	{
		this->mMenu = event.GetMenu();
		if (!mPushed)
		{
			theMainWin->GetStatusBar()->PushStatusText(wxString());
			mPushed = true;
		}
	}

	void OnClose(wxMenuEvent &WXUNUSED(event))
	{
		if (mPushed)
		{
			theMainWin->GetStatusBar()->PopStatusText();
			mPushed = false;
		}
	}

	const wxString GetHelpString(wxMenuEvent &event)
	{
		if (event.GetMenuId() < 0)
			return wxString();
		else
			return mMenu->GetHelpString(event.GetMenuId());
	}

	void OnHighlight(wxMenuEvent &event)
	{
		if (mPushed)
			theMainWin->GetStatusBar()->SetStatusText(GetHelpString(event));
		else
		{
			theMainWin->GetStatusBar()->PushStatusText(GetHelpString(event));
			mPushed = true;
		}
	}

	bool mPushed;
	wxMenu* mMenu;
};

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
		const Database::AddrInfo *addrinfo = (const Database::AddrInfo *)list->GetItemData(i);
		sym = addrinfo->symbol;
		addr = sym->address;
	}

	for (long item = -1;;)
	{
		item = list->GetNextItem(item,
			wxLIST_NEXT_ALL,
			wxLIST_STATE_SELECTED);
		if (item == -1)
			break;

		const Database::AddrInfo *itemaddrinfo = (const Database::AddrInfo *)list->GetItemData(item);
		selection.push_back(itemaddrinfo->symbol->address);
	}

	if (selection.size() == 0)
		return;

	// Focused symbol properties
	wxString procname       = sym->procname;
	wxString sourcefilename = database->getFileName  (sym->sourcefile);
	wxString modulename     = database->getModuleName(sym->module    );

	menu->Append(ID_COPY, "&Copy");
	menu->AppendSeparator();

	if (selection.size() == 1)
	{
		wxString modUpper = modulename;
		modUpper.UpperCase();

		menu->AppendCheckItem(ID_COLLAPSE_FUNC,
			"Collapse child calls",
			"Present all CPU time in functions called by this function as if inside this function")
			->Check(IsOsFunction(procname));
		menu->AppendCheckItem(ID_COLLAPSE_MOD,
			wxString::Format("Collapse all %s calls", modUpper),
			"Present all CPU time in functions called by functions in this module as if inside functions in this module")
			->Check(IsOsModule(modUpper));
		menu->AppendCheckItem(ID_SET_ROOT,
			wxString::Format("Set root to %s", procname),
			"Ignore all CPU samples except for functions called by this function");

		menu->AppendSeparator();

		menu->AppendCheckItem(ID_FILTER_FUNC,
			wxString::Format("Filter functions to %s", procname),
			"Ignore all CPU samples except inside this function");
		menu->AppendCheckItem(ID_FILTER_MODULE,
			wxString::Format("Filter modules to %s", modulename),
			"Ignore all CPU samples except inside this module");
		menu->AppendCheckItem(ID_FILTER_SOURCE,
			wxString::Format("Filter source files to %s", sourcefilename),
			"Ignore all CPU samples except inside this source file");
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
	case ID_COPY:
	{
		std::wstringstream buf;
		for (long item = -1;;)
		{
			item = list->GetNextItem(item,
				wxLIST_NEXT_ALL,
				wxLIST_STATE_SELECTED);
			if (item == -1)
				break;

			for (int col = 0; col < list->GetColumnCount(); col++)
			{
				if (col)
					buf << '\t';
				buf << list->GetItemText(item, col);
			}
			buf << '\n';
		}
		wxTheClipboard->SetData(new wxTextDataObject(buf.str()));

		break;
	}

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
