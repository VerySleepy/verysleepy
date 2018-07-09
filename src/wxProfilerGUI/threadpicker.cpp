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
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include "../utils/except.h"
#include "../appinfo.h"

// IDs for the controls and the menu commands
enum
{
	// menu items
	ProcWin_Exit = 1,
	ProcWin_Refresh,
	ProcWin_Download,
	ProcWin_Launch,
	ProcWin_Options,
	ProcWin_TimeCtrl,
	ProcWin_TimeCheck,
	ProcWin_Help_Documentation,
	ProcWin_Help_Support,

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	ProcWin_Help_About = wxID_ABOUT
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
EVT_MENU(ProcWin_Help_Documentation, ThreadPicker::OnDocumentation)
EVT_MENU(ProcWin_Help_Support, ThreadPicker::OnSupport)
EVT_MENU(ProcWin_Help_About, ThreadPicker::OnAbout)
EVT_BUTTON(ProcWin_Refresh, ThreadPicker::OnRefresh)
EVT_BUTTON(ProcWin_Download, ThreadPicker::OnDownload)
EVT_CLOSE(ThreadPicker::OnClose)
EVT_BUTTON(ProcWin_Exit, ThreadPicker::OnQuit)
EVT_CHECKBOX(ProcWin_TimeCheck, ThreadPicker::OnTimeCheck)
END_EVENT_TABLE()

wxProgressDialog *g_symProgress = NULL;

void symLogCallback(const wchar_t *text)
{
	wxLogMessage(L"%s", text);

	// Pulse the progress bar, if there is one.
	if (g_symProgress)
		g_symProgress->Pulse();
}

ThreadPicker::ThreadPicker()
:	wxModalFrame(NULL, -1, wxString(APPNAME),
			 wxDefaultPosition, wxDefaultSize,
			 wxDEFAULT_FRAME_STYLE), attach_info(NULL)
{
	SetIcon(sleepy_icon);

	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_OPEN, _T("&Open...\tCtrl-O"), _T("Opens an existing profile"));
	menuFile->Append(ProcWin_Launch, _T("&Launch...\tCtrl-N"), _T("Launches a new executable to profile"));
	menuFile->AppendSeparator();
	menuFile->Append(ProcWin_Exit, _T("E&xit\tAlt-X"), _T("Quit this program"));

	wxMenu *menuTools = new wxMenu;
	menuTools->Append(ProcWin_Refresh, _T("&Refresh\tF5"), _T("Refreshes the process list"));
	menuTools->Append(ProcWin_Download, _T("&Download Symbols"), _T("Downloads symbols from a symbol server"));
	menuTools->AppendSeparator();
	menuTools->Append(ProcWin_Options, _T("&Options..."), _T("Opens the options dialog"));

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(ProcWin_Help_Documentation, _T("&Documentation\tF1"), _T("Visit the on-line documentation wiki on GitHub"));
	menuHelp->Append(ProcWin_Help_Support, _T("&Support"), _T("Visit the on-line issue list on GitHub"));
	menuHelp->AppendSeparator();
	menuHelp->Append(ProcWin_Help_About, _T("&About..."), _T("Show about dialog"));

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
	ok_button->SetToolTip("Begins profiling selected threads.");
	wxButton *all_button = new wxButton(panel, wxID_SELECTALL,"Profile &All", wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT);
	all_button->SetBitmap(LoadPngResource(L"button_profileall"));
	all_button->SetBitmapPosition(wxRIGHT);
	all_button->SetBitmapMargins(-1,-1);
	all_button->Disable();
	all_button->SetDefault();
	all_button->SetToolTip("Begins profiling all threads in the selected process.");

	// RM: 20110614 Set time for profiler to run for
	time_value = 100;
	time_validator = new wxIntegerValidator<int>(&time_value);
	time_validator->SetMin(0);
	time_check = new wxCheckBox(panel, ProcWin_TimeCheck, "Profile for set time (s)");
	time_ctrl = new wxTextCtrl(panel, ProcWin_TimeCtrl, "100", wxDefaultPosition, wxSize(60,20), 0, *time_validator );
	time_ctrl->Disable();
	time_ctrl->SetToolTip("When enabled, this will limit the profile to run for a set time in seconds.");
	time_validator->SetWindow(time_ctrl);

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
	buttons->Add(refreshButton,										0, wxALIGN_LEFT  | wxRIGHT,					5);
	buttons->Add(downloadButton,									0, wxALIGN_LEFT,							0);
	buttons->AddStretchSpacer();
	buttons->Add(time_check,										0, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL,	0);
	buttons->Add(time_ctrl,											0, wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL,	0);
	buttons->AddStretchSpacer();
	buttons->Add(all_button,										0, wxALIGN_RIGHT,							0);
	buttons->Add(ok_button,											0, wxALIGN_RIGHT | wxLEFT,					5);

	bottomsizer->Add(buttons, 0, wxLEFT|wxRIGHT|wxEXPAND, 10);
	bottomsizer->AddSpacer(8);

	log = new LogView(panel);
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
}

void ThreadPicker::OnOpen(wxCommandEvent& WXUNUSED(event))
{
	open_filename = ProfilerGUI::PromptOpen(this);
	if (!open_filename.empty())
		EndModal(OPEN);
}

void ThreadPicker::OnAttachProfiler(wxCommandEvent& WXUNUSED(event))
{
	if (TryAttachToProcess(false))
		EndModal(ATTACH);
}

void ThreadPicker::OnAttachProfilerAll(wxCommandEvent& WXUNUSED(event))
{
	if (TryAttachToProcess(true))
		EndModal(ATTACH);
}

void ThreadPicker::OnDoubleClicked(wxListEvent& WXUNUSED(event))
{
	if (TryAttachToProcess(false))
		EndModal(ATTACH);
}

void ThreadPicker::OnClose(wxCloseEvent& WXUNUSED(event))
{
	EndModal(QUIT);
}

void ThreadPicker::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	EndModal(QUIT);
}

void ThreadPicker::OnRefresh(wxCommandEvent& WXUNUSED(event))
{
	processlist->updateProcesses();
}

void ThreadPicker::OnOptions(wxCommandEvent& WXUNUSED(event))
{
	OptionsDlg dlg;
	if (dlg.ShowModal() != wxID_OK)
		return;
}

void ThreadPicker::OnDownload(wxCommandEvent& WXUNUSED(event))
{
	g_symProgress = new wxProgressDialog(APPNAME, "Downloading symbols...", 100, this);
	processlist->reloadSymbols(true);
	delete g_symProgress;
	g_symProgress = NULL;
}

void ThreadPicker::OnLaunchExe(wxCommandEvent& WXUNUSED(event))
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

void ThreadPicker::OnDocumentation(wxCommandEvent& WXUNUSED(event))
{
	wxLaunchDefaultBrowser(GITURL "/wiki");
}

void ThreadPicker::OnSupport(wxCommandEvent& WXUNUSED(event))
{
	wxLaunchDefaultBrowser(GITURL "/issues");
}

void ThreadPicker::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	ProfilerGUI::ShowAboutBox();
}

void ThreadPicker::OnTimeCheck(wxCommandEvent& WXUNUSED(event))
{
	if( time_check->IsChecked() )
	{
		time_ctrl->Enable();
	}
	else
	{
		time_ctrl->Disable();
	}
}

ThreadPicker::~ThreadPicker()
{
	g_symLog = NULL;
	delete log;
	if (attach_info)
		delete attach_info;
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

bool ThreadPicker::TryAttachToProcess(bool allThreads)
{
	try
	{
		AttachToProcess(allThreads);
	}
	catch (SleepyException &e)
	{
		wxLogError("%ls\n", e.wwhat());
		return false;
	}

	return true;
}

void ThreadPicker::AttachToProcess(bool allThreads)
{
	assert(IsModal());

	attach_info = new AttachInfo;

	const ProcessInfo* processInfo = processlist->getSelectedProcess();
	enforce(processInfo, "No process selected");

	// RM: 20130614 Check if the user wants the profile to run for a set time period
	if (time_check->IsChecked() && time_validator->TransferFromWindow() )
	{
		attach_info->limit_profile_time = time_value;
	}
	else
	{
		attach_info->limit_profile_time = -1; // run until cancelled
	}

	//------------------------------------------------------------------------
	//Get handle to target process
	//------------------------------------------------------------------------
	attach_info->process_handle = processInfo->getProcessHandle();
	attach_info->sym_info = processlist->takeSymbolInfo();
	enforce(attach_info->sym_info, "No symbol info");

	// Check it didn't exit.
	if (WaitForSingleObject(attach_info->process_handle, 0) == WAIT_OBJECT_0)
		attach_info->process_handle = NULL;

	enforce(attach_info->process_handle, "Cannot attach to running process");

	// DE: 20090325 attaches to specific a list of threads
	std::vector<const ThreadInfo*> selectedThreads = threadlist->getSelectedThreads(allThreads);
	if (selectedThreads.size() == 0)
	{
		selectedThreads = threadlist->getSelectedThreads(true);
	}
	enforce(selectedThreads.size(), "No thread(s) selected");

	// DE: 20090325 attaches to specific a list of threads
	for (auto it = selectedThreads.begin(); it != selectedThreads.end(); ++it)
	{
		try
		{
			const ThreadInfo* threadInfo(*it);

			HANDLE threadHandle = threadInfo->getThreadHandle();
			wenforce(threadHandle, "Attaching to selected thread");
			attach_info->thread_handles.push_back(threadHandle);
		}
		catch (SleepyException &e)
		{
			wxLogError("%ls\n", e.wwhat());
		}
	}

	// DE: 20090325 attaches to specific a list of threads
	enforce(attach_info->thread_handles.size(), "Cannot attach to any threads");
}
