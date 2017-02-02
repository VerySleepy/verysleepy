/*=====================================================================
launchdlg.h
--------------

Copyright (C) Richard Mitton

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
#ifndef __LAUNCHDLG_H__
#define __LAUNCHDLG_H__

#include "profilergui.h"

#define ID_CMD_CHOOSE 1
#define ID_CWD_CHOOSE 2

class LaunchDlg : public wxDialog
{
public:
	LaunchDlg(wxWindow *parent);

	void SetCmdValue(const wxString& val);
	void SetCwdValue(const wxString& val);
	wxString GetCmdValue() const { return m_cmdvalue; }
	wxString GetCwdValue() const { return m_cwdvalue; }

protected:
	wxTextCtrl *m_cmdctl;
	wxString    m_cmdvalue;
	wxTextCtrl *m_cwdctl;
	wxString    m_cwdvalue;
	long        m_dialogStyle;

	void OnOK(wxCommandEvent& event);
	void OnChooseCmd(wxCommandEvent& event);
	void OnChooseCwd(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
};

#endif // __LAUNCHDLG_H__
