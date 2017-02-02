/*=====================================================================
threadpicker.h
--------------
File created by ClassTemplate on Sun Mar 20 17:12:56 2005

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
#ifndef __THREADPICKER_H_666_
#define __THREADPICKER_H_666_

#include "profilergui.h"
#include "processlist.h"
#include "logview.h"
#include <vector>

#include <wx/checkbox.h>
#include <wx/valnum.h>

// DE: 20090325 Include for list to pick thread(s)
#include "threadlist.h"

class wxModalFrame : public wxFrame
{
public:
	wxModalFrame() { m_evtLoop = NULL; m_retCode = -1; }
	wxModalFrame::wxModalFrame(wxWindow *parent,
			wxWindowID id,
			const wxString& title,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize,
			long style = wxDEFAULT_FRAME_STYLE,
			const wxString& name = wxFrameNameStr)
		: wxFrame(parent, id, title, pos, size, style, name)
	{
		m_evtLoop = NULL; m_retCode = -1;
		modal = false;
	}

	int ShowModal()
	{
		modal = true;
		Show();

		m_evtLoop = new wxModalEventLoop(this);
		m_evtLoop->Run();
		delete m_evtLoop;
		m_evtLoop = NULL;

		Hide();
		return m_retCode;
	}

	void EndModal(int retCode)
	{
		modal = false;
		m_retCode = retCode;
		m_evtLoop->Exit();
	}

	bool IsModal() const { return modal; }

protected:
	wxModalEventLoop *m_evtLoop;
	int m_retCode;
	bool modal;
};

class ThreadPicker : public wxModalFrame
{
public:
	enum Mode { QUIT, OPEN, ATTACH, RUN };

	ThreadPicker();
	virtual ~ThreadPicker();

	bool TryAttachToProcess(bool allThreads);
	void AttachToProcess(bool allThreads);
	void UpdateSorting();

	void OnOpen(wxCommandEvent& event);
	void OnClose(wxCloseEvent& event);
	void OnQuit(wxCommandEvent& event);
	void OnRefresh(wxCommandEvent& event);
	void OnOptions(wxCommandEvent& event);
	void OnDownload(wxCommandEvent& event);
	void OnLaunchExe(wxCommandEvent& event);
	void OnDocumentation(wxCommandEvent& event);
	void OnSupport(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnAttachProfiler(wxCommandEvent& event);
	void OnAttachProfilerAll(wxCommandEvent& event);
	void OnDoubleClicked(wxListEvent& event);
	void OnTimeCheck(wxCommandEvent& event);

	AttachInfo *attach_info;
	std::wstring run_filename, run_cwd, open_filename;
	LogView *log;
	wxCheckBox *time_check;
	wxTextCtrl *time_ctrl;
	int time_value;
	wxIntegerValidator<int>* time_validator;

private:
	ProcessList* processlist;

	// DE: 20090325 Include for list to pick thread(s)
	ThreadList* threadlist;
	wxBitmap* bitmap;

	DECLARE_EVENT_TABLE()
};





#endif //__THREADPICKER_H_666_
