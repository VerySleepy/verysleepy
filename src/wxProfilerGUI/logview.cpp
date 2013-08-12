/*=====================================================================
logview.cpp
----------------

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

#include "logview.h"
#include <windows.h>
#include <wx/menu.h>

enum
{
	// menu items
	LogView_Clear = 1,
};

BEGIN_EVENT_TABLE(LogView, wxTextCtrl)
EVT_CONTEXT_MENU(LogView::OnContextMenu)
EVT_MENU(wxID_COPY, LogView::OnCopy)
EVT_MENU(LogView_Clear, LogView::OnClearLog)
EVT_MENU(wxID_SELECTALL, LogView::OnSelectAll)
EVT_IDLE(LogView::OnIdle)
END_EVENT_TABLE()

LogView::LogView(wxWindow *parent)
:	wxTextCtrl(parent, 0, "", wxDefaultPosition, wxSize(100,100), wxTE_MULTILINE|wxTE_READONLY)
{
	previous_log = wxLog::SetActiveTarget(this);
}

LogView::~LogView()
{
	wxLog::SetActiveTarget(previous_log);
}

void LogView::DoLogText(const wxString& msg)
{
	wxString str = msg;

	// dbghelp likes to add ASCII backspaces in. (sigh)
	// convert them out into newlines.
	int backspaceat = -1;
	size_t len = str.length();
	for (size_t n=0;n<len;n++)
	{
		if (str[n] == 8)
		{
			if (backspaceat == -1)
				backspaceat = (int)n;
			str[n] = '.';
		}
	}

	bool forceupdate = false;
	if (backspaceat != -1)
	{
		str[backspaceat] = '\n';
		forceupdate = true;
	}

	// We don't want to constantly update the log, or it turns into
	// one of those hilarious situations where outputting the progress takes more
	// time than the operation itself. So we freeze it, and update either
	// when we hit the idle, or every now and again here.
	if (!IsFrozen())
		Freeze();
	AppendText(str);
	ShowPosition(-1);

	// Update if it's been more than N seconds since our last one.
	static DWORD prev = 0;
	DWORD now = GetTickCount();
	DWORD diff = now - prev;
	if (diff > 500)
		forceupdate = true;

	if (forceupdate)
	{
		prev = now;
		if (IsFrozen())
			Thaw();
		Update();
	}
}

void LogView::OnContextMenu(wxContextMenuEvent& event)
{
	wxMenu *menu = new wxMenu;
	menu->Append(wxID_COPY, _("&Copy"));
	menu->Append(wxID_SELECTALL, _("Select &All"));
	menu->Append(LogView_Clear, _("Clear &Log"));
	menu->Enable(LogView_Clear, !this->GetValue().empty());

	PopupMenu(menu);
	delete menu;
}

void LogView::OnCopy(wxCommandEvent& event)
{
	Copy();
}

void LogView::OnClearLog(wxCommandEvent& event)
{
	Clear();
}

void LogView::OnSelectAll(wxCommandEvent& event)
{
	SetSelection(-1, -1);
}

void LogView::OnIdle(wxIdleEvent& event)
{
	if (IsFrozen())
		Thaw();
}
