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
#include <algorithm>
#include <wx/aui/auibar.h>
#include <wx/filedlg.h>
#include "contextmenu.h"
#include "mainwin.h"
#include "../utils/stringutils.h"

class wxStaticTextTransparent: public wxControl
{
	wxString label;
public:
	wxStaticTextTransparent(wxWindow *parent,wxWindowID id)
	{
		wxString spaces(' ',1024);
		wxSize	size;
		GetTextExtent(spaces,&size.x,&size.y);
		Create(parent, id, wxDefaultPosition, size, wxTRANSPARENT_WINDOW|wxNO_BORDER);
		SetMinSize(size);
		SetBackgroundColour(*wxGREEN);
	}

	void OnPaint(wxPaintEvent& WXUNUSED(event))
	{
		wxPaintDC dc(this);
		dc.SetBackgroundMode(wxTRANSPARENT);
		dc.SetFont(GetFont());
		dc.DrawText(label, 0,0);
	}

	void SetLabel(const wxString& label)
	{
		this->label = label;
	}

	void OnEraseBackground(wxEraseEvent& WXUNUSED(event))
	{
	}

	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(wxStaticTextTransparent, wxControl)
EVT_PAINT(wxStaticTextTransparent::OnPaint)
EVT_ERASE_BACKGROUND(wxStaticTextTransparent::OnEraseBackground)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(CallstackView, wxWindow)
EVT_SIZE(CallstackView::OnSize)
EVT_TOOL_RANGE(0,10,CallstackView::OnTool)
EVT_LIST_ITEM_SELECTED(LIST_CTRL, CallstackView::OnSelected)
EVT_CONTEXT_MENU(CallstackView::OnContextMenu)
END_EVENT_TABLE()

CallstackView::CallstackView(wxWindow *parent,Database *_database)
:	wxWindow(parent,-1), database(_database), callstackActive(0), currSymbol(NULL), itemSelected(~0u)
{
	listCtrl = new wxListCtrl(this,LIST_CTRL,wxDefaultPosition,wxDefaultSize,wxLC_REPORT);
	setupColumn(COL_NAME,			150,	_T("Name"));
	setupColumn(COL_MODULE,			-1,		_T("Module"));
	setupColumn(COL_SOURCEFILE,		245,	_T("Source File"));
	setupColumn(COL_SOURCELINE,		-1,		_T("Source Line"));
	setupColumn(COL_ADDRESS,		-1,		_T("Address"));

	toolBar = new wxAuiToolBar(this,-1);
	toolBar->AddTool(TOOL_PREV,"-",LoadPngResource(L"button_prev"),_T("Previous"));
	toolBar->AddTool(TOOL_NEXT,"+",LoadPngResource(L"button_next"),_T("Next"));
	toolBar->AddTool(TOOL_EXPORT_CSV,"CSV",LoadPngResource(L"button_exportcsv"),_T("Export as CSV"));
	toolRange = new wxStaticTextTransparent(toolBar,-1);
	toolBar->AddControl(toolRange);

	toolBar->Realize();

	wxBoxSizer *sizer = new wxBoxSizer( wxVERTICAL );
	sizer->Add(toolBar,wxSizerFlags(0).Expand());
	sizer->Add(listCtrl,wxSizerFlags(1).Expand());
	SetSizer(sizer);
	sizer->SetSizeHints(this);
}

void CallstackView::OnSelected(wxListEvent& event)
{
	itemSelected = event.m_itemIndex;
	if (callstackActive < callstacks.size() && (size_t)itemSelected < callstacks[callstackActive]->symbols.size())
	{
		const Database::AddrInfo *addrinfo = database->getAddrInfo(callstacks[callstackActive]->addresses[itemSelected]);
		theMainWin->focusSymbol(addrinfo);
	}
	itemSelected = ~0u;
}

void CallstackView::OnSize(wxSizeEvent& WXUNUSED(event))
{
	Layout();
}

void CallstackView::setupColumn(ColumnType index, int width, const wxString &name)
{
	wxListItem itemCol;
	itemCol.SetText(name);
	if (width >= 0)
		itemCol.SetWidth(width);
	listCtrl->InsertColumn(index, itemCol);
}

CallstackView::~CallstackView(void)
{
}

bool SortCalls(const Database::CallStack*a,const Database::CallStack*b)
{
	return a->samplecount > b->samplecount;
}

void CallstackView::showCallStack(const Database::Symbol *symbol)
{
	updateTools();

	if(currSymbol == symbol || symbol == NULL)
		return;

	currSymbol = symbol;

	const Database::CallStack *pCallStackSelected;
	if(callstackActive < callstacks.size()) {
		pCallStackSelected = callstacks[callstackActive];
	} else {
		pCallStackSelected = NULL;
	}

	callstacks = database->getCallstacksContaining(symbol);
	std::sort(callstacks.begin(),callstacks.end(),SortCalls);

	callstackActive = 0;

	for(size_t i=0;i<callstacks.size();i++)  {
		if(callstacks[i] == pCallStackSelected) {
			callstackActive = i;
			break;
		}
	}
	updateList();
}

void CallstackView::updateTools()
{
	toolBar->EnableTool(TOOL_PREV,callstackActive != 0);
	toolBar->EnableTool(TOOL_NEXT,int(callstackActive) < int(callstacks.size()-1));
	toolBar->EnableTool(TOOL_EXPORT_CSV,!callstacks.empty());
	toolRange->SetLabel(callstackStats);
	toolBar->Realize();
	toolBar->Refresh();
}

void CallstackView::updateList()
{
	const Database::CallStack *now = NULL;
	if(callstackActive < callstacks.size())
		now = callstacks[callstackActive];
	if(now) {
		double totalcount = database->getMainList().totalcount;
		callstackStats = wxString::Format("Call stack %d of %d | Accounted for %0.2fs (%0.2f%%)",
			(int)(callstackActive+1),(int)callstacks.size(),now->samplecount,now->samplecount*100/totalcount);
	} else {
		callstackStats = wxString("");
	}

	updateTools();

	if(!now)
		return;

	const ViewState *viewstate = theMainWin->getViewState();

	for (size_t i = 0; i < now->symbols.size(); i++)
	{
		const Database::Symbol *snow = now->symbols[i];
		Database::Address addr = now->addresses[i];
		const Database::AddrInfo *addrinfo = database->getAddrInfo(addr);

		if (i == (size_t)listCtrl->GetItemCount())
			listCtrl->InsertItem(i,snow->procname.c_str());
		else
			listCtrl->SetItem(i,COL_NAME,snow->procname.c_str());

		if (snow->isCollapseFunction || snow->isCollapseModule)
			listCtrl->SetItemTextColour(i,wxColor(0,128,0));
		else
			listCtrl->SetItemTextColour(i,wxColor(0,0,0));

		if (set_get(viewstate->highlighted, snow->address))
			listCtrl->SetItemBackgroundColour(i, wxColor(255,255,0));
		else
			listCtrl->SetItemBackgroundColour(i, wxColor(255,255,255));

		listCtrl->SetItem(i, COL_MODULE    , database->getModuleName(snow->module));
		listCtrl->SetItem(i, COL_SOURCEFILE, database->getFileName  (snow->sourcefile));
		listCtrl->SetItem(i, COL_SOURCELINE, wxString::Format("%d", addrinfo->sourceline));
		listCtrl->SetItem(i, COL_ADDRESS   , ::toHexString(addr));

		wxFont font = listCtrl->GetFont();
		if(snow == currSymbol)
			font.SetWeight(wxFONTWEIGHT_BOLD);
		else
			font.SetWeight(wxFONTWEIGHT_NORMAL);

		listCtrl->SetItemFont(i, font);
		if(i == itemSelected) {
			listCtrl->SetItemState(i,wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
		} else {
			listCtrl->SetItemState(i, 0, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
		}
		listCtrl->SetItemPtrData(i, (wxUIntPtr)addrinfo);
	}

	while (listCtrl->GetItemCount() > int(now->symbols.size()))
		listCtrl->DeleteItem(listCtrl->GetItemCount()-1);
}

void CallstackView::exportCSV(wxFileOutputStream &file)
{
	wxTextOutputStream txt(file);

	int columnCount = listCtrl->GetColumnCount();
	int rowCount = listCtrl->GetItemCount();

	for (int columnIndex = 0; columnIndex < columnCount; columnIndex++)
	{
		wxListItem column;
		column.SetMask(wxLIST_MASK_TEXT);
		listCtrl->GetColumn(columnIndex, column);
		writeQuote(txt, std::wstring(column.GetText()), '"');
		txt << ((columnIndex == (columnCount - 1)) ? "\n" : ",");
	}

	for(int rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < columnCount; columnIndex++ )
		{
			writeQuote(txt, std::wstring(listCtrl->GetItemText(rowIndex, columnIndex)), '"');
			txt << ((columnIndex == (columnCount - 1)) ? "\n" : ",");
		}
	}
}

void CallstackView::OnTool(wxCommandEvent &event)
{
	if(event.GetId() == TOOL_PREV) {
		callstackActive--;
		updateList();
	}
	if(event.GetId() == TOOL_NEXT) {
		callstackActive++;
		updateList();
	}
	if(event.GetId() == TOOL_EXPORT_CSV) {
		wxFileDialog dlg(this, "Export Callstack As", "", "callstack.csv", "CSV Files (*.csv)|*.csv", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
		if (dlg.ShowModal() != wxID_CANCEL)
		{
			wxFileOutputStream file(dlg.GetPath());
			if(!file.IsOk())
				wxLogSysError("Could not export profile data.\n");
			exportCSV(file);
		}
	}
}

void CallstackView::OnContextMenu(wxContextMenuEvent& WXUNUSED(event))
{
	FunctionMenu(listCtrl, database);
}
