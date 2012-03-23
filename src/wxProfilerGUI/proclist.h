/*=====================================================================
proclist.h
----------
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
#ifndef __PROCLIST_H_666_
#define __PROCLIST_H_666_

#include "profilergui.h"
#include "database.h"
#include "../utils/sortlist.h"
#include "CallstackView.h"

class SourceView;

/*=====================================================================
ProcList
--------

=====================================================================*/
class ProcList : public wxSortedListCtrl
{
public:
	/*=====================================================================
	ProcList
	--------
	
	=====================================================================*/
	ProcList(wxWindow *parent, const wxWindowID id, const wxPoint& pos,
               const wxSize& size, long style, SourceView* sourceview, Database *database,
			   bool isroot);
  
	virtual ~ProcList();

	void OnSelected(wxListEvent& event);
	void OnActivated(wxListEvent& event);
	void OnSort(wxListEvent& event);
	void OnRClickItem(wxListEvent& event);

	void setParentView(ProcList *parentview);
	void setCallersView(ProcList *callersview);
	void setCalleesView(ProcList *calleesview);
	void setCallStackView(CallstackView *callStackView);

	void showMainList(const Database::Symbol *symbol);
	void showCallers(const Database::Symbol *symbol);
	void showCallees(const Database::Symbol *symbol);
	void selectSymbol(const Database::Symbol *symbol);

	Database::List list;
private:
	enum ColumnType
	{
		COL_NAME,
		COL_EXCLUSIVE,
		COL_INCLUSIVE,
		COL_EXCLUSIVEPCT,
		COL_INCLUSIVEPCT,
		COL_SAMPLES,
		COL_CALLSPCT,
		COL_MODULE,
		COL_SOURCEFILE,
		COL_SOURCELINE,
		MAX_COLUMNS
	};

	struct Column
	{
		wxString name;
		int width;
		int listctrl_column;
		SortType default_sort;
	};

	wxListItemAttr m_attr;

    DECLARE_EVENT_TABLE()

	SourceView* sourceview;
	ProcList *parentview, *callersview, *calleesview;
	CallstackView *callStackView;
	Database* database;
	int sort_column;
	SortType sort_dir;
	wxString curToolTip;

	Column columns[MAX_COLUMNS];

	void setupColumn(ColumnType id, int width, SortType defsort, const wxString &name);
	void setColumnValue(int row, ColumnType id, const wchar_t *value);
	void sortList();
	void showList(int highlight);
};


// IDs for the menu commands
enum
{
    LIST_ABOUT,
    LIST_QUIT,

    /*LIST_LIST_VIEW,
    LIST_ICON_VIEW,
    LIST_ICON_TEXT_VIEW,
    LIST_SMALL_ICON_VIEW,
    LIST_SMALL_ICON_TEXT_VIEW,
    LIST_REPORT_VIEW,
    LIST_VIRTUAL_VIEW,

    LIST_DESELECT_ALL,
    LIST_SELECT_ALL,
    LIST_DELETE_ALL,
    LIST_DELETE,
    LIST_ADD,
    LIST_EDIT,
    LIST_SORT,
    LIST_SET_FG_COL,
    LIST_SET_BG_COL,
    LIST_TOGGLE_MULTI_SEL,
    LIST_TOGGLE_FIRST,
    LIST_SHOW_COL_INFO,
    LIST_SHOW_SEL_INFO,
    LIST_FOCUS_LAST,
    LIST_FREEZE,
    LIST_THAW,*/

    LIST_CTRL                   = 1000
};


#endif //__PROCLIST_H_666_




