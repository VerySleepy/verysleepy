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
#include "proclist.h"
#include "contextmenu.h"

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
	
	void OnPaint(wxPaintEvent &event)
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

	void OnEraseBackground(wxEraseEvent& event)
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
EVT_LIST_ITEM_RIGHT_CLICK(-1,CallstackView::OnRClickItem)
END_EVENT_TABLE()

CallstackView::CallstackView(wxWindow *parent,Database *_database) : wxWindow(parent,-1), database(_database), callstackActive(0),itemSelected(~0)
{
	

	listCtrl = new wxListCtrl(this,LIST_CTRL,wxDefaultPosition,wxDefaultSize,wxLC_REPORT);
	setupColumn(COL_NAME,			150,	_T("Name"));
	setupColumn(COL_MODULE,			-1,		_T("Module"));
	setupColumn(COL_SOURCEFILE,		245,	_T("Source File"));
	setupColumn(COL_SOURCELINE,		-1,		_T("Source Line"));

	toolBar = new wxAuiToolBar(this,-1);
	toolBar->AddTool(0,"-",LoadPngResource(L"button_prev"));
	toolBar->AddTool(1,"+",LoadPngResource(L"button_next"));
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
	if(callstackActive < callstacks.size() && (size_t)itemSelected < callstacks[callstackActive]->stack.size()) {
		const Database::Symbol *symbol =  callstacks[callstackActive]->stack[itemSelected];
		procList->selectSymbol(symbol);
	}
	itemSelected = ~0;
}

void CallstackView::OnSize(wxSizeEvent& event)
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

void CallstackView::setProcList(ProcList *procList_ )
{
	procList = procList_;
}

bool SortCalls(const Database::CallStack*a,const Database::CallStack*b)
{
	return a->samplecount > b->samplecount;
}

void CallstackView::showCallStack(const Database::Symbol *symbol)
{
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

void CallstackView::updateList()
{
	toolBar->EnableTool(TOOL_PREV,callstackActive != 0);
	toolBar->EnableTool(TOOL_NEXT,int(callstackActive) < int(callstacks.size()-1));

	const Database::CallStack *now = NULL;
	if(callstackActive < callstacks.size())
		now = callstacks[callstackActive];
	if(now) {
		double totalcount = database->getMainList().totalcount;
		toolRange->SetLabel(wxString::Format("Call stack %d of %d | Accounted for %0.2fs (%0.2f%%)",
			(int)(callstackActive+1),(int)callstacks.size(),now->samplecount,now->samplecount*100/totalcount));
	} else {
		toolRange->SetLabel("");
	}
	toolBar->Realize();
	toolBar->Refresh();

	if(!now)
		return;

	for(unsigned i=0;i<now->stack.size();i++) {
		const Database::Symbol *snow = now->stack[i];
		if(i == listCtrl->GetItemCount()) {
			listCtrl->InsertItem(i,snow->procname.c_str());
		} else {
			listCtrl->SetItem(i,COL_NAME,snow->procname.c_str());
		}
		if(snow->isCollapseFunction || snow->isCollapseModule) {
			listCtrl->SetItemTextColour(i,wxColor(0,128,0));
		} else {
			listCtrl->SetItemTextColour(i,wxColor(0,0,0));
		}
		listCtrl->SetItem(i,COL_MODULE,snow->module.c_str());
		listCtrl->SetItem(i,COL_SOURCEFILE,snow->sourcefile.c_str());
		listCtrl->SetItem(i,COL_SOURCELINE,wxString::Format("%d",snow->sourceline));
		wxFont font = listCtrl->GetFont();
		if(snow == currSymbol) {
			font.SetWeight(wxFONTWEIGHT_BOLD);
		} else {
			font.SetWeight(wxFONTWEIGHT_NORMAL);
		}
		listCtrl->SetItemFont(i, font);
		if(i == itemSelected) {
			listCtrl->SetItemState(i,wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
		} else {
			listCtrl->SetItemState(i, 0, wxLIST_STATE_FOCUSED|wxLIST_STATE_SELECTED);
		}
		listCtrl->SetItemPtrData(i, (wxUIntPtr)snow);
	}
	while(listCtrl->GetItemCount() > int(now->stack.size())) {
		listCtrl->DeleteItem(listCtrl->GetItemCount()-1);
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
}

void CallstackView::OnRClickItem(wxListEvent& event)
{
	const Database::Symbol *sym = (const Database::Symbol *)listCtrl->GetItemData(event.GetIndex());
	
	FunctionMenu(this, sym, database);
}

