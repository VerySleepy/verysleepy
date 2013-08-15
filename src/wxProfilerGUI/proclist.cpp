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

BEGIN_EVENT_TABLE(ProcList, wxListCtrl)
EVT_LIST_ITEM_SELECTED(LIST_CTRL, ProcList::OnSelected)
EVT_LIST_ITEM_ACTIVATED(LIST_CTRL, ProcList::OnActivated)
EVT_LIST_COL_CLICK(-1, ProcList::OnSort)
EVT_LIST_ITEM_RIGHT_CLICK(-1,ProcList::OnRClickItem)
END_EVENT_TABLE()

ProcList::ProcList(wxWindow *parent, const wxWindowID id, const wxPoint& pos,
				   const wxSize& size, long style, SourceView* sourceview_,
				   Database* database_, bool isroot, std::set<std::wstring>& highlights_)

				   :	wxSortedListCtrl(parent, id, pos, size, wxLC_REPORT /*style*/),
				   m_attr(*wxBLUE, *wxLIGHT_GREY, wxNullFont),
				   sourceview(sourceview_),
				   database(database_),
				   parentview(NULL), callersview(NULL), calleesview(NULL), callStackView(NULL), filters(NULL),
				   highlights(highlights_)
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
	showList();
}

void ProcList::OnRClickItem(wxListEvent& event)
{
	const Database::Symbol *symbol = list.items[GetItemData(event.m_itemIndex)].symbol;

	FunctionMenu(this, symbol, database, filters, highlights);
	setFilters(filters);
}

struct NamePred { bool operator () (const Database::Item &a, const Database::Item &b)			{ return a.symbol->procname < b.symbol->procname; } };
struct ExclusivePred { bool operator () (const Database::Item &a, const Database::Item &b)		{ return a.exclusive < b.exclusive; } };
struct InclusivePred { bool operator () (const Database::Item &a, const Database::Item &b)		{ return a.inclusive < b.inclusive; } };
struct ModulePred { bool operator () (const Database::Item &a, const Database::Item &b)			{ return a.symbol->module < b.symbol->module; } };
struct SourceFilePred { bool operator () (const Database::Item &a, const Database::Item &b)		{ return a.symbol->sourcefile < b.symbol->sourcefile; } };
struct SourceLinePred { bool operator () (const Database::Item &a, const Database::Item &b)		{ return a.symbol->sourceline < b.symbol->sourceline; } };

void ProcList::sortList()
{
	switch(sort_column) {
	case COL_NAME:			std::sort(list.items.begin(), list.items.end(), NamePred()); break;
	case COL_EXCLUSIVE:		std::sort(list.items.begin(), list.items.end(), ExclusivePred()); break;
	case COL_INCLUSIVE:		std::sort(list.items.begin(), list.items.end(), InclusivePred()); break;
	case COL_EXCLUSIVEPCT:	std::sort(list.items.begin(), list.items.end(), ExclusivePred()); break;
	case COL_INCLUSIVEPCT:	std::sort(list.items.begin(), list.items.end(), InclusivePred()); break;
	case COL_SAMPLES:		std::sort(list.items.begin(), list.items.end(), ExclusivePred()); break;
	case COL_CALLSPCT:		std::sort(list.items.begin(), list.items.end(), ExclusivePred()); break;
	case COL_MODULE:		std::sort(list.items.begin(), list.items.end(), ModulePred()); break;
	case COL_SOURCEFILE:	std::sort(list.items.begin(), list.items.end(), SourceFilePred()); break;
	case COL_SOURCELINE:	std::sort(list.items.begin(), list.items.end(), SourceLinePred()); break;
	}

	if (sort_dir == SORT_DOWN)
		std::reverse(list.items.begin(), list.items.end());
}

void ProcList::showMainList(const Database::Symbol *symbol)
{
	list = database->getMainList();
	sortList();
	showList();

	// RM: 20130815 de-duplicate find logic, since we're working with filters now
	selectSymbol(symbol);

	if (!list.items.empty())
	{
		if (callersview)
			callersview->showCallers(symbol);
		if (calleesview)
			calleesview->showCallees(symbol);
		if(callStackView)
			callStackView->showCallStack(symbol);
	}
}

void ProcList::showCallees(const Database::Symbol *symbol)
{
	list = database->getCallees(symbol);

	sortList();
	showList();
}

void ProcList::showCallers(const Database::Symbol *symbol)
{
	list = database->getCallers(symbol);

	sortList();
	showList();
}


void ProcList::showList()
{
	int c = 0;
	int realIndex = 0;
	Freeze();
	DeleteAllItems();
	for (std::vector<Database::Item>::const_iterator i = list.items.begin(); i != list.items.end(); i++)
	{
		if( matchesFilters( *i ) )
		{
			const Database::Symbol *sym = i->symbol;
			double inclusive = i->inclusive;
			double exclusive = i->exclusive;
			float inclusivepercent = i->inclusive * 100.0f / list.totalcount;
			float exclusivepercent = i->exclusive * 100.0f / list.totalcount;

			InsertItem(c, sym->procname.c_str(), -1);
			if(sym->isCollapseFunction || sym->isCollapseModule) {
				SetItemTextColour(c,wxColor(0,128,0));
			}
			if(highlights.find(sym->id) != highlights.end()) {
				SetItemBackgroundColour(c, wxColor(255,255,0));
			}
			setColumnValue(c, COL_EXCLUSIVE,	wxString::Format("%0.2fs",exclusive));
			setColumnValue(c, COL_INCLUSIVE,	wxString::Format("%0.2fs",inclusive));
			setColumnValue(c, COL_EXCLUSIVEPCT,	wxString::Format("%0.2f%%",exclusivepercent));
			setColumnValue(c, COL_INCLUSIVEPCT,	wxString::Format("%0.2f%%",inclusivepercent));
			setColumnValue(c, COL_SAMPLES,		wxString::Format("%0.2fs",exclusive));
			setColumnValue(c, COL_CALLSPCT,		wxString::Format("%0.2f%%",exclusivepercent));
			setColumnValue(c, COL_MODULE,		sym->module.c_str());
			setColumnValue(c, COL_SOURCEFILE,	sym->sourcefile.c_str());
			setColumnValue(c, COL_SOURCELINE,	::toString(sym->sourceline).c_str());
		
			SetItemData(c, realIndex);
			c++;
		}
		realIndex++;
	}

	Thaw();
}

void ProcList::setColumnValue(int row, ColumnType id, const wchar_t *value)
{
	int listcol = columns[id].listctrl_column;
	if (listcol != -1)
		SetItem(row, listcol, value);
}

void ProcList::selectSymbol(const Database::Symbol *symbol)
{
	for(int i=0;i<GetItemCount();i++) {
		if(list.items[GetItemData(i)].symbol == symbol) {
			SetItemState(i,wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
			EnsureVisible(i);
		} else {
			SetItemState(i,0,wxLIST_STATE_SELECTED);
		}

	}
}

void ProcList::OnSelected(wxListEvent& event)
{
	assert(GetWindowStyle() & wxLC_REPORT);

	const Database::Symbol *symbol = list.items[GetItemData(event.m_itemIndex)].symbol;

	if (sourceview)
	{
		const LINEINFOMAP *lineInfo = database->getLineInfo(symbol->sourcefile);

		if (symbol->procname == L"KiFastSystemCallRet") {
			sourceview->showFile(L"[hint KiFastSystemCallRet]", 0, NULL);			
		} else if(lineInfo) {
			sourceview->showFile(symbol->sourcefile, symbol->sourceline, lineInfo);
		} else {
			LINEINFOMAP dummymap;
			sourceview->showFile(symbol->sourcefile, symbol->sourceline, &dummymap);
		}
	}

	if (callersview)
		callersview->showCallers(symbol);
	if (calleesview)
		calleesview->showCallees(symbol);
	if (callStackView)
		callStackView->showCallStack(symbol);
}

void ProcList::OnActivated(wxListEvent& event)
{
	assert(GetWindowStyle() & wxLC_REPORT);

	const Database::Symbol *symbol = list.items[GetItemData(event.m_itemIndex)].symbol;
	if (parentview)
		parentview->showMainList(symbol);
}

void ProcList::setParentView(ProcList *parentview)
{
	this->parentview = parentview;
}

void ProcList::setCallersView(ProcList *callersview)
{
	this->callersview = callersview;
}

void ProcList::setCalleesView(ProcList *calleesview)
{
	this->calleesview = calleesview;
}

void ProcList::setCallStackView(CallstackView *callStackView)
{

	this->callStackView = callStackView;
}

void ProcList::setFilters(wxPropertyGrid *filters)
{
	this->filters = filters;
	showMainList(NULL);
}

// Check if this item matches the filters
bool ProcList::matchesFilters(const Database::Item& item)
{
	if( !isroot || !filters )
		return true;

	std::wstring procname = filters->GetProperty("procname")->GetValueAsString();
	std::wstring module = filters->GetProperty("module")->GetValueAsString();
	std::wstring sourcefile = filters->GetProperty("sourcefile")->GetValueAsString();

	if( procname.size() > 0 )
	{
		if( item.symbol->procname.find( procname ) == std::wstring::npos )
			return false;
	}

	if( module.size() > 0 )
	{
		if( item.symbol->module.find( module ) == std::wstring::npos )
			return false;
	}

	if( sourcefile.size() > 0 )
	{
		if( item.symbol->sourcefile.find( sourcefile ) == std::wstring::npos )
			return false;
	}

	return true;
}