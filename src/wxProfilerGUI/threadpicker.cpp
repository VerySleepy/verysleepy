/*=====================================================================
threadpicker.cpp
----------------
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
#include "threadpicker.h"
#include "launchdlg.h"
#include "optionsdlg.h"
#include "../profiler/symbolinfo.h"

// IDs for the controls and the menu commands
enum
{
	// menu items
	ProcWin_Exit = 1,
	ProcWin_Refresh,
	ProcWin_Download,
	ProcWin_Launch,
	ProcWin_Options,
	ProcWin_Log,

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	ProcWin_About = wxID_ABOUT
};

BEGIN_EVENT_TABLE(ThreadPicker, wxModalFrame)
EVT_BUTTON(wxID_OK, ThreadPicker::OnAttachProfiler)
EVT_BUTTON(wxID_SELECTALL, ThreadPicker::OnAttachProfilerAll)
EVT_MENU(wxID_OPEN, ThreadPicker::OnOpen)
EVT_LIST_ITEM_ACTIVATED(PROCESS_LIST, ThreadPicker::OnDoubleClicked)
EVT_MENU(ProcWin_Exit, ThreadPicker::OnQuit)
EVT_MENU(ProcWin_Refresh, ThreadPicker::OnRefresh)
EVT_MENU(ProcWin_Options, ThreadPicker::OnOptions)
EVT_MENU(ProcWin_Download, ThreadPicker::OnDownload)
EVT_MENU(ProcWin_Launch, ThreadPicker::OnLaunchExe)
EVT_MENU(ProcWin_About, ThreadPicker::OnAbout)	
EVT_BUTTON(ProcWin_Refresh, ThreadPicker::OnRefresh)
EVT_BUTTON(ProcWin_Download, ThreadPicker::OnDownload)
EVT_CLOSE(ThreadPicker::OnClose)
EVT_BUTTON(ProcWin_Exit, ThreadPicker::OnQuit)
EVT_COMMAND_CONTEXT_MENU(ProcWin_Log,ThreadPicker::OnContextMenu)
EVT_MENU(wxID_COPY, ThreadPicker::OnCopy)
EVT_MENU(wxID_CLEAR, ThreadPicker::OnClearLog)
EVT_MENU(wxID_SELECTALL, ThreadPicker::OnSelectAll)
EVT_IDLE(ThreadPicker::OnIdle)
END_EVENT_TABLE()

ThreadPicker *cur_picker = NULL;
wxProgressDialog *g_symProgress = NULL;
int g_symProgressAmount = 0;

void symLogCallback(const wchar_t *text)
{
	wxString str = text;

	// dbghelp likes to add ASCII backspaces in. (sigh)
	// convert them out into newlines.
	int backspaceat = -1;
	size_t len = str.length();
	for (size_t n=0;n<len;n++)
	{
		if (str[n] == 8)
		{
			if (backspaceat == -1)
				backspaceat = (int)n;
			str[n] = '.';
		}
	}

	bool forceupdate = false;
	if (backspaceat != -1)
	{
		str[backspaceat] = '\n';
		forceupdate = true;
	}
		
	// We don't want to constantly update the log, or it turns into
	// one of those hilarious situations where outputing the progress takes more
	// time than the operation itself. So we freeze it, and update either
	// when we hit the idle, or every now and again here.
	if (!cur_picker->log->IsFrozen())
		cur_picker->log->Freeze();
	cur_picker->log->AppendText(str);
	cur_picker->log->ShowPosition(-1);

	// Simple logarithmic progress. We have no idea how long dbghelp will take,
	// but it's nice to at least show something.
	if (g_symProgress)
	{
		size_t n = (int)(5 * log(g_symProgressAmount+1.0f));
		if (n>99)
			n=99;
		g_symProgress->Update((int)n);
		g_symProgressAmount += (int)len;
	}

	// Update if it's been more than N seconds since our last one.
	static DWORD prev = 0;
	DWORD now = GetTickCount();
	DWORD diff = now - prev;
	if (diff > 500)
		forceupdate = true;

	if (forceupdate)
	{
		prev = now;
		if (cur_picker->log->IsFrozen())
			cur_picker->log->Thaw();
		cur_picker->log->Update();
	}
}

ThreadPicker::ThreadPicker()
:	wxModalFrame(NULL, -1, wxString(_T("Sleepy")), 
			 wxDefaultPosition, wxDefaultSize,
			 wxDEFAULT_FRAME_STYLE)
{
    SetIcon(sleepy_icon);

	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_OPEN, _T("&Open..."), _T("Opens an existing profile"));
	menuFile->Append(ProcWin_Launch, _T("&Launch..."), _T("Launches a new executable to profile"));
	menuFile->AppendSeparator();
	menuFile->Append(ProcWin_Exit, _T("E&xit\tAlt-X"), _T("Quit this program"));

	wxMenu *menuTools = new wxMenu;
	menuTools->Append(ProcWin_Refresh, _T("&Refresh\tF5"), _T("Refreshes the process list"));
	menuTools->Append(ProcWin_Download, _T("&Download Symbols"), _T("Downloads symbols from a symbol server"));
	menuTools->AppendSeparator();
	menuTools->Append(ProcWin_Options, _T("&Options..."), _T("Opens the options dialog"));

	// the "About" item should be in the help menu
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(ProcWin_About, _T("&About...\tF1"), _T("Show about dialog"));

	// now append the freshly created menu to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(menuFile, _T("&File"));
	menuBar->Append(menuTools, _T("&Tools"));
	menuBar->Append(menuHelp, _T("&Help"));

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);

	wxBoxSizer *rootsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *dlgsizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *topsizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *bottomsizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *leftsizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *rightsizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *panel = new wxPanel(this);
	rootsizer->Add(panel, 1, wxEXPAND | wxALL);

	wxButton *ok_button = new wxButton(panel, wxID_OK, "Profile &Selected", wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT);
	ok_button->SetBitmap(LoadPngResource(L"button_profilesel"));
	ok_button->SetBitmapPosition(wxRIGHT);
	ok_button->SetBitmapMargins(-1,-1);
	wxButton *all_button = new wxButton(panel, wxID_SELECTALL,"Profile &All", wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT);
	all_button->SetBitmap(LoadPngResource(L"button_profileall"));
	all_button->SetBitmapPosition(wxRIGHT);
	all_button->SetBitmapMargins(-1,-1);
	all_button->Disable();
	all_button->SetDefault();

	// DE: 20090325 one list for processes and one list for selected process threads
	threadlist = new ThreadList(panel, wxDefaultPosition, wxDefaultSize, ok_button, all_button);
	processlist = new ProcessList(panel, wxDefaultPosition, wxDefaultSize, threadlist);

	leftsizer->Add(new wxStaticText(panel, -1, "Select a process to profile:"), 0, wxTOP, 5);
	leftsizer->Add(processlist, 1, wxEXPAND | wxTOP, 3);

	// DE: 20090325 title for thread list
	rightsizer->Add(new wxStaticText(panel, -1, "Select thread(s) to profile: (CTRL-click for multiple)"), 0, wxTOP, 5);
	rightsizer->Add(threadlist, 1, wxEXPAND | wxTOP, 3);

	wxButton *refreshButton = new wxButton(panel, ProcWin_Refresh, "Refresh", wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT);
	refreshButton->SetBitmap(LoadPngResource(L"button_refresh"));
	refreshButton->SetBitmapPosition(wxRIGHT);
	refreshButton->SetBitmapMargins(-1,-1);
	refreshButton->SetToolTip("Refreshes the list of processes and threads.");

	wxButton *downloadButton = new wxButton(panel, ProcWin_Download, "Download", wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT);
	downloadButton->SetBitmap(LoadPngResource(L"button_download"));
	downloadButton->SetBitmapPosition(wxRIGHT);
	downloadButton->SetBitmapMargins(-1,-1);
	downloadButton->SetToolTip("Downloads symbols from a remote symbol server.");

	wxSizer *buttons = new wxBoxSizer(wxHORIZONTAL);
	buttons->Add(refreshButton,										0, wxALIGN_LEFT  | wxRIGHT,			5);
	buttons->Add(downloadButton,									0, wxALIGN_LEFT,					0);
	buttons->AddStretchSpacer();
	buttons->Add(all_button,										0, wxALIGN_RIGHT,					0);
	buttons->Add(ok_button,											0, wxALIGN_RIGHT | wxLEFT,			5);

	bottomsizer->Add(buttons, 0, wxLEFT|wxRIGHT|wxEXPAND, 10);
	bottomsizer->AddSpacer(8);

	log = new wxTextCtrl(panel, ProcWin_Log, "", wxDefaultPosition, wxSize(100,100), wxTE_MULTILINE|wxTE_READONLY);
	bottomsizer->Add(log, 0, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);

	topsizer->Add(leftsizer, 1, wxEXPAND | wxLEFT, 10);
	topsizer->AddSpacer(10);
	topsizer->Add(rightsizer, 1, wxEXPAND | wxRIGHT, 10);
	dlgsizer->Add(topsizer, 1, wxEXPAND);
	dlgsizer->AddSpacer(8);
	dlgsizer->Add(bottomsizer, 0, wxEXPAND);

	panel->SetSizer(dlgsizer);
	panel->SetAutoLayout(TRUE);

	SetSizer(rootsizer);
	rootsizer->SetSizeHints(this);
	SetAutoLayout(TRUE);

	SetSize(wxSize(800, 500));
	Centre();

	g_symLog = symLogCallback;
	cur_picker = this;
}

void ThreadPicker::OnIdle(wxIdleEvent& event)
{
	if (log->IsFrozen())
		log->Thaw();
}

void ThreadPicker::OnContextMenu(wxContextMenuEvent& event)
{
	wxMenu *menu = new wxMenu;
	menu->Append(wxID_COPY, _("&Copy"));
	menu->Append(wxID_SELECTALL, _("Select &All"));
	menu->Append(wxID_CLEAR, _("Clear &Log"));

	PopupMenu(menu);
	delete menu;
}

void ThreadPicker::OnCopy(wxCommandEvent& event)
{
	log->Copy();
}

void ThreadPicker::OnClearLog(wxCommandEvent& event)
{
	log->Clear();
}

void ThreadPicker::OnSelectAll(wxCommandEvent& event)
{
	log->SetSelection(-1, -1);
}

void ThreadPicker::OnOpen(wxCommandEvent& event)
{
	open_filename = ProfilerGUI::PromptOpen(this);
	if (!open_filename.empty())
	{
		EndModal(OPEN);
	}
}

void ThreadPicker::OnAttachProfiler()
{
	if ( AttachToProcess(false) )
	{
		EndModal(ATTACH);
	}
}

void ThreadPicker::OnAttachProfiler(wxCommandEvent& event)
{
	OnAttachProfiler();
}

void ThreadPicker::OnAttachProfilerAll(wxCommandEvent& event)
{
	if ( AttachToProcess(true) )
	{
		EndModal(ATTACH);
	}
}

void ThreadPicker::OnDoubleClicked(wxListEvent& event)
{
	OnAttachProfiler();
}

void ThreadPicker::OnClose(wxCloseEvent& event)
{
	EndModal(QUIT);
}

void ThreadPicker::OnQuit(wxCommandEvent& event)
{
	EndModal(QUIT);
}

void ThreadPicker::OnRefresh(wxCommandEvent& event)
{
	processlist->updateProcesses();
}

void ThreadPicker::OnOptions(wxCommandEvent& event)
{
	OptionsDlg dlg;
	if (dlg.ShowModal() != wxID_OK)
		return;
}

void ThreadPicker::OnDownload(wxCommandEvent& event)
{
	g_symProgress = new wxProgressDialog("Sleepy", "Downloading symbols...", 100, this);
	g_symProgressAmount = 0;
	processlist->reloadSymbols(true);
	delete g_symProgress;
	g_symProgress = NULL;
}

void ThreadPicker::OnLaunchExe(wxCommandEvent& event)
{
	wxString prevCmdPath;
	config.Read("PrevLaunchPath", &prevCmdPath, "");
	wxString prevCwd;
	config.Read("PrevLaunchCwd", &prevCwd, "");

	LaunchDlg dlg(this);
	dlg.SetCmdValue(prevCmdPath);
	dlg.SetCwdValue(prevCwd);
	if (dlg.ShowModal() != wxID_OK)
		return;

	run_filename = dlg.GetCmdValue();
	config.Write("PrevLaunchPath", run_filename.c_str());
	run_cwd = dlg.GetCwdValue();
	config.Write("PrevLaunchCwd", run_cwd.c_str());
	EndModal(RUN);
}

void ThreadPicker::OnAbout(wxCommandEvent& event)
{
	ProfilerGUI::ShowAboutBox();
}


ThreadPicker::~ThreadPicker()
{
	g_symLog = NULL;
	cur_picker = NULL;
}

/*
unsigned int ThreadPicker::getSelectedThread()
{
	const ProcessInfo* info = processlist->getSelectedProcess();

	if(info)
	{
		return info->threads[0].getID();
	}

	return 0;
}
*/

bool ThreadPicker::AttachToProcess(bool allThreads)
{
	if (!IsModal())
		return false;

	attach_info = new AttachInfo;

	const ProcessInfo* processInfo = processlist->getSelectedProcess();
	if(processInfo == NULL)
	{
		wxLogError("No process selected.");
		return false;
	}
	else
	{
		config.Write("PrevProcess",processInfo->getName().c_str());
	}

	//------------------------------------------------------------------------
	//Get handle to target process
	//------------------------------------------------------------------------
	attach_info->process_handle = processInfo->getProcessHandle(); 
	attach_info->sym_info = processlist->takeSymbolInfo();
	if (!attach_info->sym_info)
		return false;
	
	// Check it didn't exit.
	if (WaitForSingleObject(attach_info->process_handle, 0) == WAIT_OBJECT_0)
		attach_info->process_handle = NULL;

	if ( attach_info->process_handle == NULL )
	{
		wxLogError("Cannot attach to running process.");
		return false;
	}

	// DE: 20090325 attaches to specific a list of threads
	std::vector<const ThreadInfo*> selectedThreads = threadlist->getSelectedThreads(allThreads);
	if (selectedThreads.size() == 0)
	{
		selectedThreads = threadlist->getSelectedThreads(true);
	}
	if (selectedThreads.size() == 0)
	{
		wxLogError("No thread(s) selected.");
		return false;
	}

	// DE: 20090325 attaches to specific a list of threads
	for(std::vector<const ThreadInfo*>::const_iterator it = selectedThreads.begin(); it != selectedThreads.end(); ++it)
	{
		const ThreadInfo* threadInfo(*it);

		HANDLE threadHandle = threadInfo->getThreadHandle();
		

		if (threadHandle == NULL)
		{
			DWORD err = GetLastError();
			wxLogError("Cannot attach to selected thread.");
		} else {
			attach_info->thread_handles.push_back(threadHandle);
		}
	}

	// DE: 20090325 attaches to specific a list of threads
	if (attach_info->thread_handles.size() == 0){
		wxLogError("Cannot attach to any threads.");
		return false;
	}

	return true;
}

