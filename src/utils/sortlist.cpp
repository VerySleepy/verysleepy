/*=====================================================================
sortlist.cpp
------------

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
#include "sortlist.h"
#include <wx/dataview.h>

/* XPM */
static char *sort_none_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 16 2 1",
". c #ACA899",
"  c #FF0000",
/* pixels */
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"                "
};

/* XPM */
static char *sort_up_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 16 2 1",
". c #ACA899",
"  c #FF0000",
/* pixels */
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"        .       ",
"       ...      ",
"      .....     ",
"     .......    ",
"    .........   ",
"                ",
"                ",
"                ",
"                ",
"                "
};

/* XPM */
static char *sort_down_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 16 2 1",
". c #ACA899",
"  c #FF0000",
/* pixels */
"                ",
"                ",
"                ",
"                ",
"                ",
"                ",
"    .........   ",
"     .......    ",
"      .....     ",
"       ...      ",
"        .       ",
"                ",
"                ",
"                ",
"                ",
"                "
};

void wxSortedListCtrl::InitSort()
{
	wxImageList *images = new wxImageList;
	images->Create(16, 16);
	images->Add(wxBitmap(sort_none_xpm), wxColor(255,0,0));
	images->Add(wxBitmap(sort_up_xpm), wxColor(255,0,0));
	images->Add(wxBitmap(sort_down_xpm), wxColor(255,0,0));

	SetImageList(images, wxIMAGE_LIST_SMALL);
}

void wxSortedListCtrl::SetSortImage(int col, SortType type)
{
	wxListItem item;
	item.SetMask(wxLIST_MASK_IMAGE);
	item.SetImage(type);
	SetColumn(col, item);
}
