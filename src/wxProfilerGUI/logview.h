/*=====================================================================
logview.h
--------------

Copyright (C) Vladimir Panteleev

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
#pragma once

#include <wx/config.h>
#include <wx/textctrl.h>

class LogView :	public wxTextCtrl
{
	friend class LogViewLog;

public:
	LogView(wxWindow *parent);
	virtual ~LogView();

	void OnContextMenu(wxContextMenuEvent& event);
	void OnCopy(wxCommandEvent& event);
	void OnClearLog(wxCommandEvent& event);
	void OnSelectAll(wxCommandEvent& event);
	void OnIdle(wxIdleEvent& event);

private:
	class wxLog *previous_log;
	LogViewLog *log;

	DECLARE_EVENT_TABLE()
};
