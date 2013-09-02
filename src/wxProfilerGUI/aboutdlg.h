/*=====================================================================
aboutdlg.h
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

#include <wx/hyperlink.h>
#include <wx/dialog.h>
#include <wx/sizer.h>

// ----------------------------------------------------------------------------
// AboutDlg
// Less-rubbish about dialog
// ----------------------------------------------------------------------------
class AboutDlg : public wxDialog
{
public:
	AboutDlg();

private:
	void AddControl(wxWindow *win, const wxSizerFlags& flags);
	void AddControl(wxWindow *win);
	void AddText(const wxString& text);
	void AddDev(const wxString& name, const wxString& url, const wxString &role);

	wxSizer *m_sizerText;
};
