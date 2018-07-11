/*=====================================================================
proclist.cpp
------------
File created by ClassTemplate on Tue Mar 15 21:13:18 2005

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
#include "proclist.h"

#include "../utils/stringutils.h"
#include "sourceview.h"
#include "database.h"
#include <fstream>
#include <algorithm>
#include "contextmenu.h"
#include "mainwin.h"

enum
{
	ProcList_List = 1
};

BEGIN_EVENT_TABLE(ProcList, wxListCtrl)
EVT_LIST_ITEM_SELECTED(ProcList_List, ProcList::OnSelected)
EVT_LIST_ITEM_ACTIVATED(ProcList_List, ProcList::OnActivated)
EVT_LIST_COL_CLICK(-1, ProcList::OnSort)
EVT_CONTEXT_MENU(ProcList::OnContextMenu)
END_EVENT_TABLE()

ProcList::ProcList(wxWindow *parent, bool isroot, Database *database)
:	wxSortedListCtrl(parent, ProcList_List, wxDefaultPosition, wxDefaultSize, wxLC_REPORT /*style*/),
	isroot(isroot), database(database),
	updating(false)
{
	InitSort();

	this->isroot = isroot;

	for (int n=0;n<MAX_COLUMNS;n++)
		columns[n].listctrl_column = -1;

	if (isroot)
	{
		setupColumn(COL_NAME,			300,	SORT_UP,	_T("Name"));
		setupColumn(COL_EXCLUSIVE,		-1,		SORT_DOWN,	_T("Exclusive"));
		setupColumn(COL_INCLUSIVE,		-1,		SORT_DOWN,	_T("Inclusive"));
		setupColumn(COL_EXCLUSIVEPCT,	-1,		SORT_DOWN,	_T("% Exclusive"));
		setupColumn(COL_INCLUSIVEPCT,	-1,		SORT_DOWN,	_T("% Inclusive"));
	} else {
		setupColumn(COL_NAME,			150,	SORT_UP,	_T("Name"));
		setupColumn(COL_SAMPLES,		-1,		SORT_DOWN,	_T("Samples"));
		setupColumn(COL_CALLSPCT,		-1,		SORT_DOWN,	_T("% Calls"));
	}
	setupColumn(COL_MODULE,			-1,		SORT_UP,	_T("Module"));
	setupColumn(COL_SOURCEFILE,		245,	SORT_UP,	_T("Source File"));
	setupColumn(COL_SOURCELINE,		-1,		SORT_UP,	_T("Source Line"));
	setupColumn(COL_ADDRESS,		-1,		SORT_UP,	_T("Address"));

	if (isroot)
		sort_column = COL_EXCLUSIVE;
	else
		sort_column = COL_SAMPLES;
	sort_dir = SORT_DOWN;
	SetSortImage(columns[sort_column].listctrl_column, sort_dir);
}


ProcList::~ProcList()
{

}

void ProcList::setupColumn(ColumnType id, int width, SortType defsort, const wxString &name)
{
	int index = GetColumnCount();

	columns[id].name = name;
	columns[id].width = width;
	columns[id].listctrl_column = index;
	columns[id].default_sort = defsort;

	wxListItem itemCol;
	itemCol.SetText(name);
	if (width >= 0)
		itemCol.SetWidth(width);
	InsertColumn(index, itemCol);
}

void ProcList::OnSort(wxListEvent& event)
{
	SetSortImage(columns[sort_column].listctrl_column, SORT_NONE);

	int new_column = 0;
	for (int n=0;n<MAX_COLUMNS;n++)
		if (columns[n].listctrl_column == event.m_col)
			new_column = n;

	if (sort_column == new_column)
	{
		// toggle if we clicked on the same column as last time
		sort_dir = (SortType)((SORT_UP+SORT_DOWN) - sort_dir);
	} else {
		// if switching columns, start with the default sort for that column type
		sort_column = new_column;
		sort_dir = columns[sort_column].default_sort;
	}

	SetSortImage(columns[sort_column].listctrl_column, sort_dir);

	sortList();
	displayList();
}

void ProcList::OnContextMenu(wxContextMenuEvent& WXUNUSED(event))
{
	FunctionMenu(this, database);
}

struct NamePred       { bool operator () (const Database::Item &a, const Database::Item &b) { return a.symbol->procname   < b.symbol->procname  ; } };
struct ExclusivePred  { bool operator () (const Database::Item &a, const Database::Item &b) { return a.exclusive          < b.exclusive         ; } };
struct InclusivePred  { bool operator () (const Database::Item &a, const Database::Item &b) { return a.inclusive          < b.inclusive         ; } };
struct ModulePred     { bool operator () (const Database::Item &a, const Database::Item &b) { return a.symbol->module     < b.symbol->module    ; } };
struct SourceFilePred { bool operator () (const Database::Item &a, const Database::Item &b) { return a.symbol->sourcefile < b.symbol->sourcefile; } };
struct AddressPred    { bool operator () (const Database::Item &a, const Database::Item &b) { return a.address            < b.address           ; } };

void ProcList::sortList()
{
	switch(sort_column) {
	case COL_NAME:         std::stable_sort(list.items.begin(), list.items.end(), NamePred      ()); break;
	case COL_EXCLUSIVE:
	case COL_EXCLUSIVEPCT:
	case COL_SAMPLES:
	case COL_CALLSPCT:     std::stable_sort(list.items.begin(), list.items.end(), ExclusivePred ()); break;
	case COL_INCLUSIVE:
	case COL_INCLUSIVEPCT: std::stable_sort(list.items.begin(), list.items.end(), InclusivePred ()); break;
	case COL_MODULE:       std::stable_sort(list.items.begin(), list.items.end(), ModulePred    ()); break;
	case COL_SOURCEFILE:   std::stable_sort(list.items.begin(), list.items.end(), SourceFilePred()); break;
	case COL_SOURCELINE:
	case COL_ADDRESS:      std::stable_sort(list.items.begin(), list.items.end(), AddressPred   ()); break;
	}

	if (sort_dir == SORT_DOWN)
		std::reverse(list.items.begin(), list.items.end());
}


void ProcList::showList(const Database::List &list)
{
	this->list = list;
	sortList();
	displayList();
}

void ProcList::displayList()
{
	theMainWin->setProgress(L"Saving list state...");
	std::unordered_map<const Database::AddrInfo *, int> item_state;
	// TODO: use GetNextItem?
	for (long i=0; i<GetItemCount(); i++)
		if (int state = GetItemState(i, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED))
			item_state[(const Database::AddrInfo *)GetItemData(i)] = state;

	theMainWin->setProgress(L"Clearing list...");
	Freeze();
	DeleteAllItems();

	theMainWin->setProgress(L"Populating list...", list.items.size());
	const ViewState *viewstate = theMainWin->getViewState();

	for (auto i = list.items.begin(); i != list.items.end(); ++i)
	{
		const Database::Symbol *sym = i->symbol;

		if (isroot && set_get(viewstate->filtered, sym->address))
			continue;

		long c = GetItemCount();

		wxListItem item;
		item.SetId(c);
		item.SetText(sym->procname);

		if (sym->isCollapseFunction || sym->isCollapseModule)
			item.SetTextColour(wxColor(0,128,0));
		else
		if (i->inclusive == 0 && i->exclusive == 0)
			item.SetTextColour(wxColor(128, 128, 128));

		if (set_get(viewstate->highlighted, sym->address))
			item.SetBackgroundColour(wxColor(255,255,0));

		const Database::AddrInfo *addrinfo = database->getAddrInfo(i->address);
		int state = map_get(item_state, addrinfo, 0);
		item.SetData((void*)addrinfo);
		item.SetState(state);
		item.SetStateMask(wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);

		InsertItem(item);

		wxString inclusive = wxString::Format("%0.2fs", i->inclusive);
		wxString exclusive = wxString::Format("%0.2fs", i->exclusive);
		wxString inclusivepercent = wxString::Format("%0.2f%%", i->inclusive * 100.0f / list.totalcount);
		wxString exclusivepercent = wxString::Format("%0.2f%%", i->exclusive * 100.0f / list.totalcount);

		setColumnValue(c, COL_EXCLUSIVE,	exclusive);
		setColumnValue(c, COL_INCLUSIVE,	inclusive);
		setColumnValue(c, COL_EXCLUSIVEPCT,	exclusivepercent);
		setColumnValue(c, COL_INCLUSIVEPCT,	inclusivepercent);
		setColumnValue(c, COL_SAMPLES,		exclusive);
		setColumnValue(c, COL_CALLSPCT,		exclusivepercent);
		setColumnValue(c, COL_MODULE,		database->getModuleName(sym->module));
		setColumnValue(c, COL_SOURCEFILE,	database->getFileName  (sym->sourcefile));
		setColumnValue(c, COL_SOURCELINE,	::toString((int)addrinfo->sourceline));
		setColumnValue(c, COL_ADDRESS,	    ::toHexString(i->address));

		if (state & wxLIST_STATE_FOCUSED)
			EnsureVisible(c);

		theMainWin->updateProgress(i-list.items.begin());
	}

	Thaw();
	theMainWin->setProgress(NULL);
}

void ProcList::setColumnValue(int row, ColumnType id, const wxString &value)
{
	int listcol = columns[id].listctrl_column;
	if (listcol != -1)
		SetItem(row, listcol, value);
}

void ProcList::focusSymbol(const Database::Symbol *symbol)
{
	// If we use Freeze/Thaw here, we'll get an unpleasant blinking
	// even though the list is not being repopulated.
	if (updating) return;
	updating = true;

	for(long i=0;i<(long)list.items.size();i++) {
		if(list.items[i].symbol == symbol) {
			SetItemState(i,wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
			EnsureVisible(i);
		} else {
			if (GetItemState(i, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED))
				SetItemState(i,0,wxLIST_STATE_SELECTED);
		}
	}

	updating = false;
}

const Database::Symbol * ProcList::getFocusedSymbol()
{
	long i = GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_FOCUSED);
	return i >= 0 ? ((const Database::AddrInfo *)GetItemData(i))->symbol : NULL;
}

void ProcList::OnSelected(wxListEvent& event)
{
	if (IsFrozen() || updating)
		return; // the list is being populated or updated
	updating = true;

	assert(GetWindowStyle() & wxLC_REPORT);

	const Database::AddrInfo *addrinfo = (const Database::AddrInfo *)GetItemData(event.m_itemIndex);
	if (isroot)
		theMainWin->inspectSymbol(addrinfo);
	else
		theMainWin->focusSymbol(addrinfo);

	updating = false;
}

void ProcList::OnActivated(wxListEvent& event)
{
	assert(GetWindowStyle() & wxLC_REPORT);

	const Database::AddrInfo *addrinfo = (const Database::AddrInfo *)GetItemData(event.m_itemIndex);
	if (!isroot)
		theMainWin->inspectSymbol(addrinfo);
}
