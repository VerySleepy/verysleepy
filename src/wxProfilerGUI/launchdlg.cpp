/*=====================================================================
launchdlg.cpp
----------------

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
#include "launchdlg.h"
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>

BEGIN_EVENT_TABLE(LaunchDlg, wxDialog)
EVT_BUTTON(wxID_OK, LaunchDlg::OnOK)
EVT_BUTTON(ID_CMD_CHOOSE, LaunchDlg::OnChooseCmd)
EVT_BUTTON(ID_CWD_CHOOSE, LaunchDlg::OnChooseCwd)
END_EVENT_TABLE()

LaunchDlg::LaunchDlg(wxWindow *parent)
	: wxDialog(parent, wxID_ANY, "Launch an EXE", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE)
{
	wxBeginBusyCursor();

	wxBoxSizer *rootsizer = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );

	topsizer->Add(new wxStaticText(this, -1, "Enter a command to execute, with any additional arguments."), 0, wxBOTTOM, 5);

	m_cmdctl = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(500, 22));
	wxButton *cmdpick = new wxButton(this, ID_CMD_CHOOSE, "...", wxDefaultPosition, wxSize(22, 22));
	wxBoxSizer *rowsizer = new wxBoxSizer( wxHORIZONTAL );
	rowsizer->Add(m_cmdctl, 0, wxRIGHT, 4);
	rowsizer->Add(cmdpick);

	topsizer->Add(rowsizer, 0, wxEXPAND);
	topsizer->AddSpacer(10);


	topsizer->Add(new wxStaticText(this, -1, "Working directory."), 0, wxBOTTOM, 5);
	rowsizer = new wxBoxSizer( wxHORIZONTAL );
	m_cwdctl = new wxTextCtrl(this, -1, "", wxDefaultPosition, wxSize(500, 22));
	rowsizer->Add(m_cwdctl, 0, wxRIGHT, 4);
	rowsizer->Add(new wxButton(this, ID_CWD_CHOOSE, "...", wxDefaultPosition, wxSize(22, 22)));

	topsizer->Add(rowsizer, 0, wxEXPAND);


	int border = ConvertDialogToPixels(wxSize(2, 0)).x;
	wxSizer *buttons = new wxBoxSizer(wxHORIZONTAL);
	buttons->AddStretchSpacer();
	wxButton *ok = new wxButton(this, wxID_OK, "&Launch");
	wxButton *cancel = new wxButton(this, wxID_CANCEL);
	buttons->Add(ok,		0, wxALIGN_RIGHT | wxLEFT|wxRIGHT,	border);
	buttons->Add(cancel,	0, wxALIGN_RIGHT | wxLEFT,			border);
	topsizer->Add(buttons, 0, wxEXPAND|wxTOP, 10);

	rootsizer->Add(topsizer, 0, wxEXPAND|wxALL, 10);

	SetAutoLayout( true );
	SetSizer( rootsizer );

	rootsizer->SetSizeHints( this );
	rootsizer->Fit( this );

	Centre( wxBOTH );

	m_cmdctl->SetSelection(-1, -1);
	m_cmdctl->SetFocus();
	ok->SetDefault();

	wxEndBusyCursor();
}

void LaunchDlg::OnOK(wxCommandEvent& WXUNUSED(event) )
{
	m_cmdvalue = m_cmdctl->GetValue();
	m_cwdvalue = m_cwdctl->GetValue();

	EndModal(wxID_OK);
}

void LaunchDlg::OnChooseCmd(wxCommandEvent& WXUNUSED(event) )
{
	wxFileDialog dlg(this, "Choose an exectuable to launch", wxEmptyString, wxEmptyString,
		"Executable files (*.exe)|*.exe|All files (*.*)|*.*");
	if (dlg.ShowModal() == wxID_OK)
		SetCmdValue(dlg.GetPath());
}

void LaunchDlg::OnChooseCwd(wxCommandEvent& WXUNUSED(event) )
{
	wxDirDialog dlg(this, "Choose working directory");
	if (dlg.ShowModal() == wxID_OK)
		SetCwdValue(dlg.GetPath());
}

void LaunchDlg::SetCmdValue(const wxString& val)
{
	m_cmdvalue = val;

	m_cmdctl->SetValue(val);
}

void LaunchDlg::SetCwdValue(const wxString& val)
{
	m_cwdvalue = val;

	m_cwdctl->SetValue(val);
}
