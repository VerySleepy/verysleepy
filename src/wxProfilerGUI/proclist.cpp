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

void ProcList::OnContextMenu(wxContextMenuEvent& event)
{
	FunctionMenu(this, database);
}

struct NamePred       { bool operator () (const Database::Item &a, const Database::Item &b) { return a.symbol->procname   < b.symbol->procname  ; } };
struct ExclusivePred  { bool operator () (const Database::Item &a, const Database::Item &b) { return a.exclusive          < b.exclusive         ; } };
struct InclusivePred  { bool operator () (const Database::Item &a, const Database::Item &b) { return a.inclusive          < b.inclusive         ; } };
struct ModulePred     { bool operator () (const Database::Item &a, const Database::Item &b) { return a.symbol->module     < b.symbol->module    ; } };
struct SourceFilePred { bool operator () (const Database::Item &a, const Database::Item &b) { return a.symbol->sourcefile < b.symbol->sourcefile; } };
struct SourceLinePred { bool operator () (const Database::Item &a, const Database::Item &b) { return a.symbol->sourceline < b.symbol->sourceline; } };

void ProcList::sortList()
{
	switch(sort_column) {
	case COL_NAME:         std::sort(list.items.begin(), list.items.end(), NamePred      ()); break;
	case COL_EXCLUSIVE:
	case COL_EXCLUSIVEPCT:
	case COL_SAMPLES:
	case COL_CALLSPCT:     std::sort(list.items.begin(), list.items.end(), ExclusivePred ()); break;
	case COL_INCLUSIVE:
	case COL_INCLUSIVEPCT: std::sort(list.items.begin(), list.items.end(), InclusivePred ()); break;
	case COL_MODULE:       std::sort(list.items.begin(), list.items.end(), ModulePred    ()); break;
	case COL_SOURCEFILE:   std::sort(list.items.begin(), list.items.end(), SourceFilePred()); break;
	case COL_SOURCELINE:   std::sort(list.items.begin(), list.items.end(), SourceLinePred()); break;
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
	int *item_state = new int[database->getSymbolIDCount()]();
	// TODO: use GetNextItem?
	for (long i=0; i<GetItemCount(); i++)
		item_state[GetItemData(i)] = GetItemState(i, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);

	Freeze();
	DeleteAllItems();

	const ViewState *viewstate = theMainWin->getViewState();

	for (std::vector<Database::Item>::const_iterator i = list.items.begin(); i != list.items.end(); i++)
	{
		const Database::Symbol *sym = i->symbol;

		if (isroot && viewstate->flags[sym->id] & ViewState::Flag_Filtered)
			continue;

		double inclusive = i->inclusive;
		double exclusive = i->exclusive;
		float inclusivepercent = i->inclusive * 100.0f / list.totalcount;
		float exclusivepercent = i->exclusive * 100.0f / list.totalcount;

		long c = GetItemCount();

		wxListItem item;
		item.SetId(c);
		item.SetText(sym->procname);

		if(sym->isCollapseFunction || sym->isCollapseModule) {
			item.SetTextColour(wxColor(0,128,0));
		}
		if(viewstate->flags[sym->id] & ViewState::Flag_Highlighted) {
			item.SetBackgroundColour(wxColor(255,255,0));
		}

		item.SetData(sym->id);
		item.SetState(item_state[sym->id]);
		item.SetStateMask(wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);

		InsertItem(item);

		setColumnValue(c, COL_EXCLUSIVE,	wxString::Format("%0.2fs" ,exclusive));
		setColumnValue(c, COL_INCLUSIVE,	wxString::Format("%0.2fs" ,inclusive));
		setColumnValue(c, COL_EXCLUSIVEPCT,	wxString::Format("%0.2f%%",exclusivepercent));
		setColumnValue(c, COL_INCLUSIVEPCT,	wxString::Format("%0.2f%%",inclusivepercent));
		setColumnValue(c, COL_SAMPLES,		wxString::Format("%0.2fs" ,exclusive));
		setColumnValue(c, COL_CALLSPCT,		wxString::Format("%0.2f%%",exclusivepercent));
		setColumnValue(c, COL_MODULE,		sym->module.c_str());
		setColumnValue(c, COL_SOURCEFILE,	sym->sourcefile.c_str());
		setColumnValue(c, COL_SOURCELINE,	::toString(sym->sourceline).c_str());

		if (item_state[sym->id] & wxLIST_STATE_FOCUSED)
			EnsureVisible(c);
	}

	delete[] item_state;
	Thaw();
}

void ProcList::setColumnValue(int row, ColumnType id, const wchar_t *value)
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
	return i >= 0 ? database->getSymbol(GetItemData(i)) : NULL;
}

void ProcList::OnSelected(wxListEvent& event)
{
	if (IsFrozen() || updating)
		return; // the list is being populated or updated
	updating = true;

	assert(GetWindowStyle() & wxLC_REPORT);

	const Database::Symbol *symbol = database->getSymbol(GetItemData(event.m_itemIndex));
	if (isroot)
		theMainWin->inspectSymbol(symbol);
	else
		theMainWin->focusSymbol(symbol);

	updating = false;
}

void ProcList::OnActivated(wxListEvent& event)
{
	assert(GetWindowStyle() & wxLC_REPORT);

	const Database::Symbol *symbol = database->getSymbol(GetItemData(event.m_itemIndex));
	if (!isroot)
		theMainWin->inspectSymbol(symbol);
}
