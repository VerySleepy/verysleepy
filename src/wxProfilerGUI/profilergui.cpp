/*=====================================================================
profilergui.cpp
---------------
File created by ClassTemplate on Sun Mar 13 18:16:34 2005

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
#include "profilergui.h"
#include <wx/mstream.h>
#include <wx/apptrait.h>
#include <wx/msw/apptrait.h>
#include <memory>

#include "threadpicker.h"
#include "capturewin.h"
#include "mainwin.h"
#include "../utils/dbginterface.h"
#include "../profiler/profilerthread.h"
#include "../utils/stringutils.h"
#include "../utils/osutils.h"
#include <wx/stdpaths.h>
#include <wx/filedlg.h>
#include "crashback.h"
#include "aboutdlg.h"
#include "../utils/except.h"

// DE: 20090325 Linking fails in debug target under visual studio 2005
// RJM: works for me :-/
//#include <wx/apptrait.h>
//#if wxUSE_STACKWALKER && defined( __WXDEBUG__ )
//// silly workaround for the link error with debug configuration:
//// \src\common\appbase.cpp
//wxString wxAppTraitsBase::GetAssertStackTrace()
//{
//   return wxT("");
//}
//#endif

static const wxCmdLineEntryDesc g_cmdLineDesc[] =
{
	{ wxCMD_LINE_SWITCH, "h", "", "Displays help on the command line parameters.",			wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
	{ wxCMD_LINE_OPTION, "r", "", "Runs an executable and profiles it.",					wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL|wxCMD_LINE_NEEDS_SEPARATOR },
	{ wxCMD_LINE_OPTION, "i", "", "Loads an existing profile from a file.",					wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL|wxCMD_LINE_NEEDS_SEPARATOR },
	{ wxCMD_LINE_OPTION, "o", "", "Saves the captured profile to the given file.",			wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL|wxCMD_LINE_NEEDS_SEPARATOR },
	{ wxCMD_LINE_OPTION, "t", "", "Stops capturing automatically after N seconds time.",	wxCMD_LINE_VAL_NUMBER, wxCMD_LINE_PARAM_OPTIONAL },
	{ wxCMD_LINE_SWITCH, "q", "", "Quiet mode (no error messages will be shown).",			wxCMD_LINE_VAL_NONE },
	{ wxCMD_LINE_PARAM, NULL, NULL, "Loads an existing profile from a file.",				wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},

	{ wxCMD_LINE_NONE }
};

wxIcon sleepy_icon;
std::wstring cmdline_load, cmdline_save, cmdline_run;
long cmdline_timeout = -1;  // -1 means profile until cancelled
std::vector<std::wstring> tmp_files;
Prefs prefs;
wxConfig config(_T(APPNAME) L" " _T(VERSION), _T(VENDOR));

ProfilerGUI::ProfilerGUI()
{
	initialized = false;
	captureWin = NULL;
}


ProfilerGUI::~ProfilerGUI()
{

}


IMPLEMENT_APP(ProfilerGUI)

class ProfilerAppTraits : public wxGUIAppTraits
{
	virtual void SetLocale()
	{
		// wxWidgets, Y U futz with locale? Why?!
		// leave it alone dammit!
	}
};

wxAppTraits *ProfilerGUI::CreateTraits()
{
	return new ProfilerAppTraits;
}

wxBitmap LoadPngResource(const wchar_t *szName)
{
	HRSRC hResource = FindResource(NULL,szName,L"PNG");
	void *resource = LockResource(LoadResource(NULL,hResource));
	wxMemoryInputStream is(resource,SizeofResource(NULL,hResource));
	return wxBitmap(wxImage(is,wxBITMAP_TYPE_ANY,-1),-1);
}

void CleanupTempFiles()
{
	for each(std::wstring s in tmp_files)
	{
		DeleteFile(s.c_str());
	}
	tmp_files.clear();
}

void ProfilerGUI::ShowAboutBox()
{
	AboutDlg dlg;
	dlg.ShowModal();
}

wxString ProfilerGUI::PromptOpen(wxWindow *parent)
{
	wxFileDialog dlg(parent, "Open File", "", "", _T(APPNAME) L" Profiles (*.sleepy)|*.sleepy", 
		wxFD_OPEN);
	if (dlg.ShowModal() != wxID_CANCEL)
		return dlg.GetPath();
	else
		return wxEmptyString;
}

void ProfilerGUI::CreateProgressWindow()
{
	captureWin = new CaptureWin();
	captureWin->Show();
	captureWin->Update();
}

void ProfilerGUI::DestroyProgressWindow()
{
	delete captureWin;
	captureWin = NULL;
}

/// Returns the path to the profile archive, or an empty string
/// if profiling was aborted by the user.
std::wstring ProfilerGUI::LaunchProfiler(const AttachInfo *info)
{
	//------------------------------------------------------------------------
	//create the profiler thread
	//------------------------------------------------------------------------
	// DE: 20090325 attaches to a specific list of threads
	ProfilerThread* profilerthread = new ProfilerThread( 
		info->process_handle,
		info->thread_handles,
		info->sym_info
		);


	//------------------------------------------------------------------------
	//start the profiler thread
	//------------------------------------------------------------------------
	bool aborted = false;
	{
		if (!captureWin)
			CreateProgressWindow();

		profilerthread->launch(false, THREAD_PRIORITY_TIME_CRITICAL);

		wxStopWatch stopwatch;
		stopwatch.Start();

		class : public wxTimer
		{
		public:
			bool fired;
			void Notify() { fired = true; }
		} timer;
		timer.fired = false;
		timer.Start(100);

		while (true)
		{
			wxYieldIfNeeded();

			if (timer.fired)
			{
				timer.fired = false;
				if (!captureWin->UpdateProgress(profilerthread->getStatus(), profilerthread->getSampleProgress(), profilerthread->getNumThreadsRunning(), info->limit_profile_time))
					break;
			}

			profilerthread->setPaused(captureWin->Paused());

			if (profilerthread->getNumThreadsRunning() <= 0)
				break;

			if (info->limit_profile_time >= 0 && stopwatch.Time() >= info->limit_profile_time*1000)
				break;

			WaitMessage(); // in lieu of a wxWaitForEvent
		}
		aborted = captureWin->Cancelled();
		DestroyProgressWindow();
	}

	profilerthread->commit_suicide = true;
	wxLog::FlushActive();

	if (aborted)
	{
		profilerthread->cancel();
		profilerthread->waitFor();
		return std::wstring();
	}

	{
		wxProgressDialog dlg(APPNAME, "Waiting for symbol query to start...", 1000, NULL,
			wxPD_APP_MODAL | wxPD_AUTO_HIDE | wxPD_CAN_ABORT);

		while (true)
		{
			int permille;
			std::wstring stage;
			profilerthread->getSymbolsProgress(&permille, &stage);
			if (profilerthread->getDone() || profilerthread->getFailed())
				break;
			if (!dlg.Update(permille, stage))
				profilerthread->cancel();
			profilerthread->waitFor(100);
		}
		profilerthread->waitFor();
	}

	bool failed = profilerthread->getFailed();
	std::wstring output_filename = profilerthread->getFilename();

	delete profilerthread;
	profilerthread = NULL;

	if (failed)
		return std::wstring();

	enforce(!output_filename.empty(), "There was a problem creating the profile data.");

	tmp_files.push_back(output_filename);
	atexit(CleanupTempFiles);

	return output_filename;
}

AttachInfo::AttachInfo()
{
	process_handle = NULL;
	sym_info = NULL;
	limit_profile_time = cmdline_timeout;
}

AttachInfo::~AttachInfo()
{
	if (process_handle)
		CloseHandle(process_handle);
	if (sym_info)
		delete sym_info;
}

AttachInfo *ProfilerGUI::RunProcess(const std::wstring &run_cmd, const std::wstring &run_cwd)
{
	STARTUPINFO si = {sizeof(si)};
	PROCESS_INFORMATION pi = {};

	std::vector<wchar_t> run_cmd_dup(run_cmd.size() + 1); // CreateProcess lpCommandLine must be mutable
	std::copy(run_cmd.begin(), run_cmd.end(), run_cmd_dup.begin());
	wenforce(CreateProcess( NULL, &run_cmd_dup[0], NULL, NULL, FALSE, 0, NULL, run_cwd.size() ? run_cwd.c_str() : NULL, &si, &pi ), "CreateProcess");

	std::unique_ptr<AttachInfo> output(new AttachInfo);
	output->process_handle = pi.hProcess;
	output->thread_handles.push_back(pi.hThread);
	output->sym_info = new SymbolInfo;

	// Load up the debug info for it.
	// This can fail initially, because it turns out that you can't query information
	// about a process until that process has registered itself fully with CSRSS. 
	// So we wait a little and try again. I'm not sure what the correct solution is,
	// I think possibly monitoring for debug events might be the way to go.
	int retry = 100;
	while (retry--)
	{
		Sleep(10);
		try
		{
			output->sym_info->loadSymbols(output->process_handle, false);
			break;
		}
		catch (...)
		{
			if (retry == 0)
				throw;
		}
	}

	return output.release();
}

void ProfilerGUI::LoadProfileData(const std::wstring &filename)
{
	Database *database = new Database();
	database->loadFromPath(filename, config.Read("MainWinCollapseOS", 1) != 0, false);

	MainWin *frame = new MainWin(wxString::Format("%s - %s", APPNAME, filename), filename, database);
	frame->Show(TRUE);
	frame->Update();
	frame->Raise();
	frame->reset();
}

/// Returns the path to the profile archive, or an empty string
/// if the user quit the application.
std::wstring ProfilerGUI::ObtainProfileData()
{
	while (true)
	{
		std::unique_ptr<ThreadPicker> threadpicker(new ThreadPicker);
		int mode = threadpicker->ShowModal();
		wxLog::FlushActive();

		switch (mode)
		{
		case ThreadPicker::QUIT:
			return std::wstring();

		case ThreadPicker::OPEN:
			return threadpicker->open_filename;

		case ThreadPicker::ATTACH:
			return LaunchProfiler(threadpicker->attach_info);

		case ThreadPicker::RUN:
			// Create the window before we create the process,
			// so we don't steal focus from it.
			CreateProgressWindow();

			std::unique_ptr<AttachInfo> info;
			try
			{
				info.reset(RunProcess(threadpicker->run_filename, threadpicker->run_cwd));
			}
			catch (SleepyException &e)
			{
				DestroyProgressWindow();
				wxLogError("%ls\n", e.wwhat());
				continue;
			}

			wxScopeGuard sgTerm = wxMakeGuard(TerminateProcess, info->process_handle, 0);
			return LaunchProfiler(info.get());
		}
	}
}

bool ProfilerGUI::OnInit()
{
#ifndef _DEBUG
	cbStartup();
#endif
	wxInitAllImageHandlers();
	EnableDebugPrivilege();
	if (!dbgHelpInit())
		return false;

	sleepy_icon = wxICON(sleepy);

	if (!wxApp::OnInit())
		return false;

	// Make a default cache in their user directory.
	wxString symCache = wxStandardPaths::Get().GetUserLocalDataDir();

	prefs.symSearchPath = config.Read("SymbolSearchPath", "");
	prefs.useSymServer = config.Read("UseSymbolServer", 1) != 0;
	prefs.symServer = config.Read("SymbolServer", "http://msdl.microsoft.com/download/symbols");
	prefs.symCacheDir = config.Read("SymbolCache", symCache);
	prefs.saveMinidump = config.Read("SaveMinidump", -1);
	prefs.throttle = config.Read("SpeedThrottle", 100);
	if (prefs.throttle < 1)
		prefs.throttle = 1;
	if (prefs.throttle > 100)
		prefs.throttle = 100;

	return true;
}

bool ProfilerGUI::ProcessIdle()
{
	bool result = wxApp::ProcessIdle();
	HandleInit();
	return result;
}

void ProfilerGUI::HandleInit()
{
	if (initialized)
		return;

	initialized = true;

	SetExitOnFrameDelete(false);

	try
	{
		if (Run())
		{
			SetExitOnFrameDelete(true);
			return;
		}
	}
	catch (SleepyException &e)
	{
		wxLogError("%ls\n", e.wwhat());
	}
	wxEventLoop::GetActive()->Exit(1);
}

/// Returns true if a frame is still active.
bool ProfilerGUI::Run()
{
	// Explicitly create and set the default logger, so other threads use it.
	// Otherwise, wxWidgets will create a default logger on request,
	// but only by the request of the main thread.
	// Log messages for other threads will be discarded.
	wxLog::SetActiveTarget(new wxLogGui);

	std::wstring filename;

	if (!cmdline_run.empty())
	{
		std::unique_ptr<AttachInfo> info(RunProcess(cmdline_run, L""));
		wxScopeGuard sgTerm = wxMakeGuard(TerminateProcess, info->process_handle, 0);
		filename = LaunchProfiler(info.get());
	}
	else
	if (!cmdline_load.empty())
		filename = cmdline_load;
	else
	{
		filename = ObtainProfileData();
		if (filename.empty())
			return false; // Profiling was aborted
	}

	if (!cmdline_save.empty())
	{
		wenforce(CopyFile(filename.c_str(), cmdline_save.c_str(), FALSE), "Saving profile data");
		return false;	// No GUI, just save and exit
	}

	LoadProfileData(filename);
	return true;
}

int ProfilerGUI::OnExit()
{
	config.Write("SymbolSearchPath", prefs.symSearchPath);
	config.Write("UseSymbolServer", prefs.useSymServer);
	config.Write("SymbolServer", prefs.symServer);
	config.Write("SymbolCache", prefs.symCacheDir);
	config.Write("SaveMinidump", prefs.saveMinidump);
	config.Write("SpeedThrottle", prefs.throttle);

	return wxApp::OnExit();
}

void ProfilerGUI::OnInitCmdLine(wxCmdLineParser& parser)
{
	parser.DisableLongOptions();
	parser.SetDesc(g_cmdLineDesc);
	parser.SetSwitchChars("/");
}

bool ProfilerGUI::OnCmdLineParsed(wxCmdLineParser& parser)
{
	wxString param;

	if (parser.Found("q"))
		wxLog::EnableLogging(false);

	if (parser.Found("r") && parser.Found("i"))
	{
		parser.Usage();
		return false;
	}

	if (parser.Found("i", &param))
		cmdline_load = param.c_str();
	if (parser.GetParamCount())
		cmdline_load = parser.GetParam(0);
	if (parser.Found("o", &param))
		cmdline_save = param.c_str();
	if (!parser.Found("t", &cmdline_timeout))
		cmdline_timeout = -1;
	if (parser.Found("r", &param))
		cmdline_run = param.c_str();

	return true;
}
