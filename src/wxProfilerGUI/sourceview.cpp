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

#include <fstream>
#include "../utils/stringutils.h"
#include "mainwin.h"
//#undef min
//#undef max
#include <algorithm>
#include <wx/mstream.h>
#include <richedit.h>

BEGIN_EVENT_TABLE(SourceView, wxTextCtrl)
	EVT_PAINT(SourceView::OnPaint)
	EVT_UPDATE_UI(SOURCE_VIEW, SourceView::OnUpdateUI)
END_EVENT_TABLE()


StringSet keywords(L"keywords.txt", true);


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

SourceView::SourceView(wxWindow *parent, MainWin* mainwin_)
:	wxTextCtrl(parent, SOURCE_VIEW, wxEmptyString,
               wxDefaultPosition, wxDefaultSize,
               wxTE_MULTILINE | wxSUNKEN_BORDER | wxTE_READONLY | wxTE_DONTWRAP | wxTE_RICH2  ),
	mainwin(mainwin_)
{
	AppendText("Select a procedure from the list above.");
}


SourceView::~SourceView()
{
	
}

void SourceView::showFile(std::wstring path, int proclinenum, const LINEINFOMAP *lineinfomap)
{
	currentfile = path;

	SetValue("");//clear text
	SetDefaultStyle(wxTextAttr(*wxBLACK));

	if (path == "[hint KiFastSystemCallRet]")
	{
		AppendText(
			" Hint: KiFastSystemCallRet often means the thread was waiting for something else to finish.\n"
			" \n"
			" Possible causes might be disk I/O, waiting for an event, or maybe just calling Sleep().\n"
			);
		return;
	}

	if (path == "" || path == "[unknown]")
	{
		SetValue("[ No source file available for this location. ]");

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
		AppendText(std::wstring("[ Could not open file '" + path + "'. ]").c_str());
		return;
	}

	Show(false);
	std::wstring displaytext = L"{\\rtf1\\ansi\\fdeff0{\\colortbl;\\red0\\green0\\blue0;\\red255\\green0\\blue0;\\red0\\green128\\blue0;\\red0\\green0\\blue255;}\\cf1";
	int linenum = 1;//1-based counting
	//int showpos = 0;//index of character to make visible in order to scroll to line where proc is defined.
	const int MARGIN_WIDTH = 7;
	wchar_t line[1024*10];
	bool block=false;
	wchar_t blockType;
	while(fgetws(line,countof(line),file))
	{
		wchar_t outLine[1024*20];
		LINEINFOMAP::const_iterator result = lineinfomap->find(linenum);
		
		if(result != lineinfomap->end()) {
			swprintf(outLine, countof(outLine), L"{\\b\\cf2 %0.2fs\t}",result->second.count);
		} else {
			wcscpy(outLine, L"\t");
		}
		wchar_t *out = outLine+wcslen(outLine);
		wchar_t *in = line;
		while(*in) {
			if(!block)
			{
				if(in[0] == '/' && in[1] == '/') {
					block = true;
					blockType = '/';
					wcscpy(out, L"{\\cf3 ");
					out += wcslen(out);
				} else 	if(in[0] == '/' && in[1] == '*') {
					block = true;
					blockType = '*';
					wcscpy(out, L"{\\cf3 ");
					out += wcslen(out);
				} else if(in[0] == '"' && ( in[-1] != '\\' || in[-2] == '\\' )) {
					block = true;
					blockType = '"';
					wcscpy(out, L"{\\cf3 ");
					out += wcslen(out);
				} if(!isCToken(in[-1]) && isCToken(in[0])) {
					wchar_t token[1024*10];
					wchar_t *tokOut = token;
					while(isCToken(*in)) {
						*(tokOut++) = *(in++);
					}
					*tokOut=0;
					if(keywords.Contains(token)) {
						wcscpy(out,L"{\\cf4 ");
						out += wcslen(out);
						wcscpy(out,token);
						out += wcslen(out);
						wcscpy(out,L"}");
						out += wcslen(out);
					} else {
						wcscpy(out,token);
						out += wcslen(token);
					}
					continue;
				}
			} else {
				if(blockType == '*' && in[-2] == '*' && in[-1] == '/') {
					block = false;
					wcscpy(out, L"}");
					out += wcslen(out);
				} else if(blockType == '"' && in[0] == '"' && ( in[-1] != '\\' || in[-2] == '\\' )) {
					*(out++) = '"';
					block = false;
					wcscpy(out, L"}");
					out += wcslen(out);
					in++;
					continue;
				}
			}

			switch(in[0]) {
			case '\n':
			case '\r':
				if(block && blockType == '/') {
					block = false;
					wcscpy(out, L"}");
					out += wcslen(out);
				}
				break;
			case '{':
			case '}':
			case '\\':
				*(out++) = '\\';
				*(out++) = in[0];
				break;
			default:
				*(out++) = in[0];
				break;
			}
			in++;
		}
		*out = 0;
		
		wcscat(outLine, L"\\line\n");

		displaytext += outLine ;//form line to display
	
		linenum++;
	}
	displaytext += L"}";
	fclose(file);

	// Convert to UTF8, which the richedit control seems to want (despite the documentation).
	size_t utflen = displaytext.length() * 4;
	void *utf = malloc(utflen);
	utflen = WideCharToMultiByte(CP_UTF8, 0, displaytext.c_str(), -1, (LPSTR)utf, utflen, NULL, NULL);

	SETTEXTEX settextex = {
		ST_DEFAULT,
		CP_UTF8,
	};
	SendMessage((HWND)GetHWND(),EM_EXLIMITTEXT,0,utflen);
	SendMessage((HWND)GetHWND(),EM_SETTEXTEX,(WPARAM)&settextex,(LPARAM)utf);

	free(utf);

	wxFont font(8, wxMODERN , wxNORMAL, wxNORMAL);
	const bool res = SetStyle(0, (long)displaytext.size(), wxTextAttr(wxNullColour, wxNullColour, 
						font));
	const int showpos = std::max((int)XYToPosition(0, std::max(proclinenum -7 , 0)), 0);
	ShowPosition(showpos);
	Show(true);
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

	//SetDefaultStyle(wxTextAttr(*wxBLACK, *wxWHITE));
	
}

void SourceView::OnUpdateUI(wxUpdateUIEvent& event)
{
	long col, line;
	const bool result = PositionToXY(GetInsertionPoint(), &col, &line);
	if(!result)
		line = -1;
	else
		line += 1;//convert to 1-based line numbering

	mainwin->setCurrent(currentfile, line);

	event.Skip();
}

