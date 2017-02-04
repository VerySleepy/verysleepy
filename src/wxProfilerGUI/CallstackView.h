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

class CallstackView;

#include "profilergui.h"
#include "database.h"

#ifndef __CALLSTTACKVIEW_H_
#define __CALLSTTACKVIEW_H_

class wxStaticTextTransparent;

class CallstackView : public wxWindow
{
	wxAuiToolBar			*toolBar;
	wxListCtrl				*listCtrl;
	wxStaticTextTransparent	*toolRange;
	Database				*database;

	enum ColumnType
	{
		COL_NAME,
		COL_MODULE,
		COL_SOURCEFILE,
		COL_SOURCELINE,
		COL_ADDRESS,
		MAX_COLUMNS
	};

	enum ToolId
	{
		TOOL_PREV,
		TOOL_NEXT,
		TOOL_EXPORT_CSV,
	};

	enum ListCtrl {
		LIST_CTRL = 1000
	};

	std::vector<const Database::CallStack*> callstacks;
	size_t									callstackActive;
	wxString								callstackStats;
	const Database::Symbol					*currSymbol;
	size_t									itemSelected;

	void setupColumn(ColumnType id, int width, const wxString &name);
	void updateList();
	void updateTools();
	void exportCSV(wxFileOutputStream &file);

public:
	CallstackView(wxWindow *parent, Database *database);
	virtual ~CallstackView(void);
	void OnSize(wxSizeEvent& event);
	void OnTool(wxCommandEvent &event);
	void OnSelected(wxListEvent& event);
	void OnContextMenu(wxContextMenuEvent& event);
public:
	void showCallStack(const Database::Symbol *symbol);
	DECLARE_EVENT_TABLE()

};

#endif
