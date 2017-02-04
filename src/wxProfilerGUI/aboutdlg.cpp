/*=====================================================================
aboutdlg.cpp
-------------
File created by ClassTemplate on Sun Mar 13 18:16:34 2005

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

#include "aboutdlg.h"
#include <wx/aboutdlg.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include "../appinfo.h"
#include "../version.h"

AboutDlg::AboutDlg()
{
	Init();

	if ( !wxDialog::Create(NULL, wxID_ANY, _T("About ") _T(APPNAME),
		wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE) )
		return;

	m_sizerText = new wxBoxSizer(wxVERTICAL);

	wxString nameAndVersion = _T(APPNAME) _T(" ") _T(VERSION);
	wxSizer *sizerIconAndTitle = new wxBoxSizer(wxHORIZONTAL);
	wxIcon icon = wxAboutDialogInfo().GetIcon();
	if ( icon.Ok() )
		sizerIconAndTitle->Add(new wxStaticBitmap(this, wxID_ANY, icon), 0, wxRIGHT, 20);

	wxSizer *sizerTitle = new wxBoxSizer(wxVERTICAL);
	{
		wxStaticText *label = new wxStaticText(this, wxID_ANY, nameAndVersion);
		wxFont font(*wxNORMAL_FONT);
		font.SetPointSize(font.GetPointSize() + 3);
		font.SetWeight(wxFONTWEIGHT_BOLD);
		label->SetFont(font);

		sizerTitle->Add(label, 0, wxBOTTOM, 4);
	}
	{
		wxStaticText *label = new wxStaticText(this, wxID_ANY, _T("Open-source CPU profiler"));
		label->SetFont(*wxITALIC_FONT);

		sizerTitle->Add(label, 0, wxBOTTOM, 4);
	}
	sizerTitle->Add(new wxStaticLine(this), wxSizerFlags().Expand());

	sizerIconAndTitle->Add(sizerTitle, 1, wxEXPAND);

	m_sizerText->Add(sizerIconAndTitle, 1, wxEXPAND);
	m_sizerText->AddSpacer(10);

//	AddText(_T(APPNAME) L":");
//	AddDev("Your Name Here", "http://example.com/", "maintainer");

	AddText("Very Sleepy:");
	AddDev("Richard Mitton", "http://www.codersnotes.com/", "maintainer");
	AddDev("Vladimir Panteleev", "http://thecybershadow.net/", "maintainer");
	AddDev("Richard Munn", "https://github.com/benjymous", "time limit, filters, highlights");
	AddDev("Michael Vance", "", "callstack CSV export");
	AddDev(L"Bernat Mu\x00F1oz Garcia", "https://github.com/shashClp", "Scintilla syntax highlighting");
	AddDev("Dan Engelbrecht", "", "threading");
	AddDev(L"Johan K" L"\x00F6" L"hler", "", "64-bit");
	AddDev("... and many other kind people contributing patches.", "", "");

	AddText("Sleepy:");
	AddDev("Nicholas Chapman", "http://sleepy.sourceforge.net/", "creator");

	AddControl(new wxStaticLine(this), wxSizerFlags().Expand());
	AddText(L"Copyright \x00A9 authors and contributors.\n"
		L"\n"
		L"This program is released under the GNU Public License.\n"
		L"See LICENSE.TXT for more information.");

	AddControl(new wxStaticLine(this), wxSizerFlags().Expand());
	wxHyperlinkCtrl *link = new wxHyperlinkCtrl(this, wxID_ANY,
		_T(APPNAME) _T(" web site"),
		_T(APPURL));
	link->SetToolTip(_T(APPURL));
	AddControl(link, wxSizerFlags().Center());

	wxSizer *sizerBtns = CreateButtonSizer(wxOK);
	if ( sizerBtns )
	{
		m_sizerText->Add(sizerBtns, wxSizerFlags().Expand().Border());
	}

	wxSizer *sizerTop = new wxBoxSizer(wxVERTICAL);
	sizerTop->Add(m_sizerText, 1, wxEXPAND|wxALL, 10);
	SetSizerAndFit(sizerTop);

	CentreOnScreen();
}

void AboutDlg::AddControl(wxWindow *win, const wxSizerFlags& flags)
{
	wxSizerFlags newflags = flags;
	m_sizerText->Add(win, newflags.Border(wxTOP|wxBOTTOM));
}

void AboutDlg::AddControl(wxWindow *win)
{
	AddControl(win, wxSizerFlags());
}

void AboutDlg::AddText(const wxString& text)
{
	if (!text.empty())
		AddControl(new wxStaticText(this, wxID_ANY, text));
}

void AboutDlg::AddDev(const wxString& name, const wxString& url, const wxString &role)
{
	wxSizer *s = new wxBoxSizer(wxHORIZONTAL);
	s->Add(new wxStaticText(this, wxID_ANY, L"     \x00BB   "));
	if (url.empty())
		s->Add(new wxStaticText(this, wxID_ANY, name));
	else
	{
		wxHyperlinkCtrl* link = new wxHyperlinkCtrl(this, wxID_ANY, name, url);
		link->SetToolTip(url);
		s->Add(link);
	}
	if (!role.empty())
		s->Add(new wxStaticText(this, wxID_ANY, L" (" + role + ")"));
	m_sizerText->Add(s);
}
