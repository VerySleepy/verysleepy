/*=====================================================================
optionsdlg.cpp
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
#include "optionsdlg.h"
#include "wx/filepicker.h"
#include "wx/msw/wrapcctl.h" // include <commctrl.h> "properly"

class wxPercentSlider : public wxSlider
{
public:
    wxPercentSlider(wxWindow *parent,
             wxWindowID id,
             int value,
             int minValue,
             int maxValue,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = wxSL_HORIZONTAL,
             const wxValidator& validator = wxDefaultValidator,
             const wxString& name = wxSliderNameStr)
    {
        Init();

        Create(parent, id, value, minValue, maxValue, pos, size, style, validator, name);
    }

protected:

	// RJM- had to modify the wxWidgets source slightly to get this to work :-/
	// Just go into include/wx/msw/slider.h, and change the definition of this
	// from 'static' to 'virtual', and add a const modifier. Then you have to do
	// a full 'make clean' and rebuild for it to take.
    virtual wxString Format(int n) const { return wxString::Format(wxT("%d%%"), n); }
};

enum OptionsId
{
	Options_UseSymServer = 1,
	Options_Throttle,
};

BEGIN_EVENT_TABLE(OptionsDlg, wxDialog)
EVT_BUTTON(wxID_OK, OptionsDlg::OnOk)
EVT_CHECKBOX(Options_UseSymServer, OptionsDlg::OnUseSymServer)
END_EVENT_TABLE()

OptionsDlg::OptionsDlg()
:	wxDialog(NULL, -1, wxString(_T("Options")), 
			 wxDefaultPosition, wxDefaultSize,
			 wxDEFAULT_DIALOG_STYLE)
{
	wxBoxSizer *rootsizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);

	wxStaticBoxSizer *symsizer = new wxStaticBoxSizer(wxVERTICAL, this, "Symbol server");

	useSymServer = new wxCheckBox(this, Options_UseSymServer, "Use symbol server");
	symCacheDir = new wxDirPickerCtrl(this, -1, prefs.symCacheDir, "Select a directory to store local symbols in:",
		wxDefaultPosition, wxDefaultSize, wxDIRP_USE_TEXTCTRL);
	symServer = new wxTextCtrl(this, -1, prefs.symServer);

	useSymServer->SetValue(prefs.useSymServer);
	symCacheDir->Enable(prefs.useSymServer);
	symServer->Enable(prefs.useSymServer);

	symsizer->Add(useSymServer, 0, wxALL, 5);
	symsizer->Add(new wxStaticText(this, -1, "Local cache directory:"), 0, wxLEFT|wxTOP, 5);
	symsizer->Add(symCacheDir, 0, wxALL|wxEXPAND, 5);
	symsizer->Add(new wxStaticText(this, -1, "Symbol server location:"), 0, wxLEFT|wxTOP, 5);
	symsizer->Add(symServer, 0, wxALL|wxEXPAND, 5);

	wxStaticBoxSizer *throttlesizer = new wxStaticBoxSizer(wxVERTICAL, this, "Sample rate control");
	throttle = new wxPercentSlider(this, Options_Throttle, prefs.throttle, 1, 100, wxDefaultPosition, wxDefaultSize,
		wxSL_HORIZONTAL|wxSL_TICKS|wxSL_TOP|wxSL_LABELS);
	throttle->SetTickFreq(10);
	throttlesizer->Add(new wxStaticText(this, -1, 
		"Adjusts the sample rate speed. Useful for doing longer captures\n"
		"where you wish to reduce the profiler overhead."), 0, wxALL, 5);
	throttlesizer->Add(throttle, 0, wxEXPAND|wxLEFT|wxTOP, 5);
	
	topsizer->Add(symsizer, 0, wxEXPAND|wxALL, 0);
	topsizer->AddSpacer(5);
	topsizer->Add(throttlesizer, 0, wxEXPAND|wxALL, 0);
	rootsizer->Add(topsizer, 1, wxEXPAND|wxLEFT|wxTOP|wxRIGHT, 10);
	rootsizer->Add(CreateButtonSizer(wxOK|wxCANCEL), 0, wxEXPAND|wxALL, 10);
	SetSizer(rootsizer);
	rootsizer->SetSizeHints(this);
	SetAutoLayout(TRUE);

	SetSize(wxSize(400, -1));
	Centre();
}

OptionsDlg::~OptionsDlg()
{
}

void OptionsDlg::OnOk(wxCommandEvent& event)
{
	prefs.useSymServer = useSymServer->GetValue();
	prefs.symCacheDir = symCacheDir->GetPath();
	prefs.symServer = symServer->GetValue();
	prefs.throttle = throttle->GetValue();
	EndModal(wxID_OK);
}

void OptionsDlg::OnUseSymServer(wxCommandEvent& event)
{
	bool enabled = useSymServer->GetValue();
	symCacheDir->Enable(enabled);
	symServer->Enable(enabled);
}
