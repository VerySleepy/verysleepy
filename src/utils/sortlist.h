/*=====================================================================
sortlist.h
----------

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
#ifndef __SORTLIST_H_666_
#define __SORTLIST_H_666_

#include <wx/listctrl.h>

class wxSortedListCtrl : public wxListCtrl
{
public:
	wxSortedListCtrl() { Init(); }

	wxSortedListCtrl(wxWindow *parent,
			wxWindowID id = wxID_ANY,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize,
			long style = wxLC_ICON,
			const wxValidator& validator = wxDefaultValidator,
			const wxString& name = wxListCtrlNameStr)
	{
		Init();

		Create(parent, id, pos, size, style, validator, name);
	}

	enum SortType { SORT_NONE, SORT_UP, SORT_DOWN };

	void InitSort();
	void SetSortImage(int col, SortType type);
};

#endif // __SORTLIST_H_666_
