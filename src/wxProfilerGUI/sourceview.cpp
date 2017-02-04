/*=====================================================================
sourceview.cpp
--------------
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
#include "sourceview.h"

#define countof(_x) (sizeof(_x)/sizeof(_x[0]))

#include "../utils/stringutils.h"
#include "mainwin.h"

BEGIN_EVENT_TABLE(SourceView, wxStyledTextCtrl)
	EVT_PAINT(SourceView::OnPaint)
	EVT_UPDATE_UI(SOURCE_VIEW, SourceView::OnUpdateUI)
END_EVENT_TABLE()


StringList keywords(L"keywords.txt");


class MSDevPaths: public std::vector<std::wstring>
{
public:
	MSDevPaths()
	{
		int idx=0;
		_wgetenv(L""); // initialises _wenviron

		while(wchar_t *env = _wenviron[idx++]) {
			if(wcsstr(env,L"COMNTOOLS=") == NULL)
				continue;
			env = wcschr(env,'=');
			if(!env)
				continue;
			env++;
			push_back(std::wstring(env) + L"..\\..\\vc\\crt\\src\\");
		}
	}
};

MSDevPaths msDevPaths;

static const int MARGIN_TEXT_STYLE = wxSTC_STYLE_LASTPREDEFINED+1;

SourceView::SourceView(wxWindow *parent, MainWin* mainwin_)
:	wxStyledTextCtrl(parent, SOURCE_VIEW,
					 wxDefaultPosition, wxDefaultSize,
					 wxSUNKEN_BORDER, wxEmptyString ),
	mainwin(mainwin_)
{
	SetUseTabs (false);
	SetTabWidth(8);

	setPlainMode();
	updateText ("Select a procedure from the list above.");
}

SourceView::~SourceView()
{
}

void SourceView::updateText(const wxString& text)
{
	SetEditable(true);
	SetText(text);
	SetEditable(false);
}

void SourceView::setPlainMode()
{
	SetLexer (wxSTC_LEX_NULL);

	SetMarginWidth (0, 0);
	SetMarginWidth (1, 0);
}

void SourceView::setCppMode()
{
	SetLexer	(wxSTC_LEX_CPP);
	SetKeyWords	(0, keywords.Get());

	StyleClearAll	();

	SetMarginType	(0, wxSTC_MARGIN_NUMBER);
	SetMarginWidth	(0, 40);
	StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour( 32, 32, 32));
	StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour(192,192,192));

	SetMarginType	(1, wxSTC_MARGIN_RTEXT);
	SetMarginWidth	(1, 50);
	StyleSetForeground (MARGIN_TEXT_STYLE, wxColour(255,  0,  0));
	StyleSetBackground (MARGIN_TEXT_STYLE, wxColour(192,192,192));

	StyleSetForeground (wxSTC_C_DEFAULT,			wxColour(0,0,0)	);
	StyleSetForeground (wxSTC_C_STRING,				wxColour(163,21,21));
	StyleSetForeground (wxSTC_C_PREPROCESSOR,		wxColour(0,0,255));

	StyleSetForeground (wxSTC_C_IDENTIFIER,			wxColour(0,0,0));

	StyleSetForeground (wxSTC_C_WORD,				wxColour(0,0,255));
	StyleSetForeground (wxSTC_C_WORD2,				wxColour(0,0,255));
	StyleSetForeground (wxSTC_C_NUMBER,				wxColour(0,0,0));
	StyleSetForeground (wxSTC_C_CHARACTER,			wxColour(0,0,0));

	StyleSetForeground (wxSTC_C_COMMENT,				wxColour(0,128,0));
	StyleSetForeground (wxSTC_C_COMMENTLINE,			wxColour(0,128,0));
	StyleSetForeground (wxSTC_C_COMMENTDOC,				wxColour(0,128,0));
	StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD,		wxColour(0,128,0));
	StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0,128,0));
	StyleSetBold(wxSTC_C_WORD, true);
	StyleSetBold(wxSTC_C_WORD2, true);
	StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);

	for (int i = wxSTC_C_DEFAULT; i <= wxSTC_C_PREPROCESSORCOMMENT; ++i)
	{
		wxFont font(wxFontInfo(10).FaceName("Consolas"));
		StyleSetFont(i, font);
	}
}

void SourceView::showFile(std::wstring path, int proclinenum, const std::vector<double> &linecounts)
{
	currentfile = path;

	// Don't show error messages with CPP highlighting
	setPlainMode();
	if (path == "[hint KiFastSystemCallRet]")
	{
		updateText(
			" Hint: KiFastSystemCallRet often means the thread was waiting for something else to finish.\n"
			" \n"
			" Possible causes might be disk I/O, waiting for an event, or maybe just calling Sleep().\n"
			);
		return;
	}

	if (path == "" || path == "[unknown]")
	{
		updateText("[ No source file available for this location. ]");
		return;
	}


	FILE *file = _wfopen(path.c_str(),L"r, ccs=UNICODE");
	if(!file)
	{
		wchar_t *crtSub = L"\\crt\\src\\";
		wchar_t *crt = wcsstr((wchar_t *)path.c_str(), crtSub);
		if(crt) {
			for(size_t i=0;i<msDevPaths.size();i++) {
				std::wstring newPath(msDevPaths[i]);
				newPath += crt+wcslen(crtSub);
				path = newPath;
				file = _wfopen(path.c_str(),L"r");
				if(file)
					break;
			}
		}
	}

	if(!file)
	{
		updateText(std::wstring("[ Could not open file '" + path + "'. ]").c_str());
		return;
	}

	std::wstring displaytext;
	wchar_t line[1024];
	while(fgetws(line,countof(line),file))
	{
		displaytext += line;
	}

	fclose(file);

	setCppMode();

	updateText(displaytext);

	// Show line counts in margin
	for (int line=1,lineCount=linecounts.size(); line<lineCount; ++line)
	{
		if (linecounts[line])
		{
			wchar_t currCount[32];
			swprintf(currCount, countof(currCount), L"%0.2fs ", linecounts[line]);
			MarginSetText (line-1, currCount);
			MarginSetStyle(line-1, MARGIN_TEXT_STYLE);
		}
	}

	SetYCaretPolicy(wxSTC_CARET_STRICT|wxSTC_CARET_EVEN, 0);
	GotoLine(proclinenum);
	SetYCaretPolicy(wxSTC_CARET_EVEN, 0);

	MarkerDefine(1, wxSTC_MARK_BACKGROUND, wxNullColour, *wxYELLOW);
	MarkerAdd(proclinenum-1, 1);
}

void SourceView::OnPaint(wxPaintEvent& event)
{

	{
	//wxPaintDC dc(this);
	//dc.BeginDrawing();
	//dc.SetBrush( *wxRED_BRUSH );
	//dc.DrawLine(100, 0, 100, 300);
	//dc.EndDrawing();
	}

	event.Skip();
}

void SourceView::OnUpdateUI(wxUpdateUIEvent& event)
{
	long col, line;
	const bool result = PositionToXY(GetInsertionPoint(), &col, &line);
	if(!result)
		line = -1;
	else
		line += 1;//convert to 1-based line numbering

	mainwin->setSourcePos(currentfile, line);

	event.Skip();
}
