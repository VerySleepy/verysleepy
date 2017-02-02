/*=====================================================================
sourceview.h
------------
File created by ClassTemplate on Tue Mar 15 21:38:06 2005

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
#ifndef __SOURCEVIEW_H_666_
#define __SOURCEVIEW_H_666_

#include "profilergui.h"

#include <wx/stc/stc.h>

class MainWin;

/*=====================================================================
SourceView
----------

=====================================================================*/
class SourceView : public wxStyledTextCtrl
{
public:
	/*=====================================================================
	SourceView
	----------

	=====================================================================*/
	SourceView(wxWindow *parent, MainWin* mainwin);

	virtual ~SourceView();

	void OnPaint(wxPaintEvent& event);
	void OnUpdateUI(wxUpdateUIEvent& event);

	void showFile(std::wstring path, int linenum, const std::vector<double> &linecounts);

	const std::wstring& getCurrentFile() const { return currentfile; }
private:
	void setPlainMode();
	void setCppMode();
	void updateText(const wxString& text);

	std::wstring currentfile;
	MainWin* mainwin;

	DECLARE_EVENT_TABLE()

};

enum
{
	SOURCE_VIEW					  = 1005
};


#endif //__SOURCEVIEW_H_666_
