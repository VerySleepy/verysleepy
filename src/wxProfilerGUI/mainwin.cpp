/*=====================================================================
mainwin.cpp
-----------
File created by ClassTemplate on Sun Mar 13 21:12:40 2005

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
#include "mainwin.h"
#include "database.h"

#include "../utils/stringutils.h"
#include "CallstackView.h"
#include <wx/aui/auibook.h>

MainWin *theMainWin;

// IDs for the controls and the menu commands
enum
{
	// menu items
	MainWin_Quit = 1,
	MainWin_Open,
	MainWin_SaveAs,
	MainWin_ExportAsCsv,
	MainWin_View_Collapse_OS,
	MainWin_View_Stats,
	MainWin_ResetToRoot,

	// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	MainWin_About = wxID_ABOUT
};

MainWin::MainWin(const wxString& title, 
				 const std::wstring& profilepath,
				 Database *database)
				 :	wxFrame()
{
	assert(!theMainWin);
	theMainWin = this;
	wxString str;
	long style = wxDEFAULT_FRAME_STYLE;

	wxPoint pos(50, 50);
	wxSize size = wxGetDisplaySize();
	size.Scale(0.75f, 0.75f);

	if (config.Read("MainWinMaximized", 0L))
		style |= wxMAXIMIZE;
	pos.x = config.Read("MainWinX", (long)pos.x);
	pos.y = config.Read("MainWinY", (long)pos.x);
	size.x = config.Read("MainWinW", (long)size.x);
	size.y = config.Read("MainWinH", (long)size.y);

	Create(NULL, -1, title, pos, size, style);
				
	panel = NULL;
	proclist = NULL;
	sourceview = NULL;
	this->profilepath = profilepath;
	this->database = database;

	// set the frame icon
    SetIcon(sleepy_icon);

#if wxUSE_MENUS
	// create a menu bar
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(MainWin_Open, _T("&Open..."), _T("Opens an existing profile"));
	menuFile->Append(MainWin_SaveAs, _T("Save &As..."), _T("Saves the profile data to a file"));
	menuFile->Append(MainWin_ExportAsCsv, _T("&Export as CSV..."), _T("Export the profile data to a CSV file"));
	menuFile->AppendSeparator();
	menuFile->Append(MainWin_Quit, _T("E&xit\tAlt-X"), _T("Quit this program"));

	// View options and layout.
	wxMenu *menuView = new wxMenu;
	menuView->Append(MainWin_View_Stats,_T("Show Profiling Sstatistics"), _T("Shows any extra information logged while profiling")); 
	collapseOSCalls = menuView->AppendCheckItem(MainWin_View_Collapse_OS,_T("&Hide Collapsed Functions"), _T("Hide functions nested inside system calls")); 
	collapseOSCalls->Check(config.Read("MainWinCollapseOS",1)!=0);
	menuView->Append(MainWin_ResetToRoot , _T("Reset Profile &Root"), _T("Resets the root so that the entire profile is shown"));

	// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(MainWin_About, _T("&About...\tF1"), _T("Show about dialog"));

	// now append the freshly created menu to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(menuFile, _T("&File"));
	menuBar->Append(menuView, _T("&View"));
	menuBar->Append(helpMenu, _T("&Help"));

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);
#endif // wxUSE_MENUS

	CreateStatusBar(2);
	// Construct the docking panes
	wxSize clientSize = GetClientSize();

	aui = new wxAuiManager(this,wxAUI_MGR_RECTANGLE_HINT);

	wxWindow *splitWindow = new wxWindow(this,-1);

	sourceview = new SourceView(this ,this);

	// Create the windows
	proclist = new ProcList(this, LIST_CTRL,
		wxDefaultPosition, wxDefaultSize,
		wxLC_EDIT_LABELS, 
		sourceview, database, true);

	callers = new ProcList(splitWindow, LIST_CTRL,
		wxDefaultPosition, wxDefaultSize,
		wxLC_EDIT_LABELS, 
		NULL, database, false);

	callees = new ProcList(splitWindow, LIST_CTRL,
		wxDefaultPosition, wxDefaultSize,
		wxLC_EDIT_LABELS, 
		NULL, database, false);

	callStack = new CallstackView(this,database);


	aui->AddPane(proclist, wxAuiPaneInfo()
		.Name(wxT("Functions"))
		.CentrePane()
		.Caption(wxT("Functions"))
		.CaptionVisible(true)
		);

	aui->AddPane(sourceview, wxAuiPaneInfo()
		.Name(wxT("Source"))
		.Caption(wxT("Source"))
		.CloseButton(false)
		.Bottom()
		.Layer(0)
		.BestSize(clientSize.GetWidth() * 2/3, clientSize.GetHeight() * 1/3)
		);

	
	callViews = new wxAuiNotebook(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxAUI_TB_DEFAULT_STYLE|wxNO_BORDER);

	callViews->AddPage(splitWindow,wxT("Averages"));
	callViews->AddPage(callStack,wxT("Call Stacks"));
	aui->AddPane(callViews,wxAuiPaneInfo()
		.Name(wxT("CallInfo"))
		.CaptionVisible(false)
		.CloseButton(false)
		.Right()
		.Layer(1)
		.PaneBorder(false)
		.BestSize(clientSize.GetWidth() * 1/3, clientSize.GetHeight() * 1/3)
		);


	auiTab1 = new wxAuiManager(splitWindow,wxAUI_MGR_RECTANGLE_HINT);
	auiTab1->AddPane(callers, wxAuiPaneInfo()
		.Name(wxT("CalledFrom"))
		.Caption(wxT("Called From"))
		.CloseButton(false)
		.Center()
		.PaneBorder(false)
		);

	auiTab1->AddPane(callees, wxAuiPaneInfo()
		.Name("ChildCalls")
		.Caption(wxT("Child Calls"))
		.CloseButton(false)
		.Center()
		.PaneBorder(false)
		);

	aui->Update();
	auiTab1->Update();

	// Calculate a string with the content of the AUI.
	// If we add or remove elements, the config will reset.
	contentString = aui->SavePerspective()+"|"+auiTab1->SavePerspective();

	if(config.Read("MainWinContent") == contentString) {
		if (config.Read("MainWinLayout", &str) ) {
			aui->LoadPerspective(str);
		}
		if (config.Read("MainWinBookTab1Layout", &str) ) {
			auiTab1->LoadPerspective(str);
		}
		callViews->SetSelection(config.Read("MainWinBookTab",callViews->GetSelection()));
	}

	aui->Update();

	// Tie it all together
	proclist->setCallersView(callers);
	proclist->setCalleesView(callees);
	proclist->setCallStackView(callStack);
	callers->setParentView(proclist);
	callees->setParentView(proclist);
	callStack->setProcList(proclist);
}

void MainWin::Reset()
{
	proclist->showMainList(NULL);
}


MainWin::~MainWin()
{
	auiTab1->UnInit();
	aui->UnInit();
	delete database;	
	delete auiTab1;
	delete aui;
}


// the event tables connect the wxWindows events with the functions (event
// handlers) which process them. It can be also done at run-time, but for the
// simple menu events like this the static method is much simpler.
BEGIN_EVENT_TABLE(MainWin, wxFrame)
EVT_CLOSE(MainWin::OnClose)
EVT_MENU(MainWin_Quit,  MainWin::OnQuit)
EVT_MENU(MainWin_Open,  MainWin::OnOpen)
EVT_MENU(MainWin_SaveAs,  MainWin::OnSaveAs)
EVT_MENU(MainWin_ExportAsCsv,  MainWin::OnExportAsCsv)
EVT_MENU(MainWin_ResetToRoot, MainWin::ResetToRoot)
EVT_UPDATE_UI(MainWin_ResetToRoot, MainWin::ResetToRootUpdate)
EVT_MENU(MainWin_View_Collapse_OS,  MainWin::OnCollapseOS)
EVT_MENU(MainWin_View_Stats,  MainWin::OnStats)
EVT_MENU(MainWin_About, MainWin::OnAbout)	
END_EVENT_TABLE()

void MainWin::OnClose(wxCloseEvent& WXUNUSED(event))
{
	config.Write("MainWinMaximized", IsMaximized());

	assert(GetScreenRect().width > 200);

	wxString str = aui->SavePerspective();
	config.Write("MainWinLayout", str);
	config.Write("MainWinX", GetScreenRect().x);
	config.Write("MainWinY", GetScreenRect().y);
	config.Write("MainWinW", GetScreenRect().width);
	config.Write("MainWinH", GetScreenRect().height);
	config.Write("MainWinBookTab",callViews->GetSelection());
	config.Write("MainWinBookTab1Layout",auiTab1->SavePerspective());
	config.Write("MainWinContent",contentString);
	config.Write("MainWinCollapseOS",collapseOSCalls->IsChecked());

	wxExit();
}

void MainWin::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	wxExit();
}

void MainWin::OnOpen(wxCommandEvent& WXUNUSED(event))
{
	wxString filename = ProfilerGUI::PromptOpen(this);
	if (filename.empty())
		return;

	database->loadFromPath(filename.c_str().AsWChar(),collapseOSCalls->IsChecked());
	Reset();
}

void MainWin::ResetToRoot(wxCommandEvent& WXUNUSED(event))
{
	database->setRoot(NULL);
	proclist->showMainList(NULL);
}

void MainWin::ResetToRootUpdate(wxUpdateUIEvent& event)
{
	event.Enable(database->getRoot() != NULL);
}

void MainWin::OnSaveAs(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog dlg(this, "Save File As", "", "capture.sleepy", "Sleepy Profiles (*.sleepy)|*.sleepy", 
		wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (dlg.ShowModal() != wxID_CANCEL)
	{
		if (!CopyFile(profilepath.c_str(), dlg.GetPath(), FALSE))
		{
			wxLogSysError("Could not save profile data.");
		}
	}
}

void MainWin::OnExportAsCsv(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog dlg(this, "Export File As", "", "capture.csv", "CSV Files (*.csv)|*.csv", 
		wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (dlg.ShowModal() != wxID_CANCEL)
	{
		wxFileOutputStream file(dlg.GetPath());
		if(!file.IsOk())
			wxLogSysError("Could not export profile data.");
		wxTextOutputStream txt(file);
		for each(const Database::Item &item in proclist->list.items) {
			txt << item.symbol->procname << ",";
			txt << item.exclusive << ",";
			txt << item.inclusive << ",";
			txt << (item.exclusive*100.0f/proclist->list.totalcount) << ",";
			txt << (item.inclusive*100.0f/proclist->list.totalcount) << ",";
			txt << item.symbol->module << ",";
			txt << item.symbol->sourcefile << ",";
			txt << item.symbol->sourceline << "\n";
		}
	}
}

void MainWin::OnCollapseOS(wxCommandEvent& event)
{
	database->reload(collapseOSCalls->IsChecked());
	Reset();
}

void MainWin::OnStats(wxCommandEvent& event)
{
	wxDialog dlg(this, -1, wxString("Statistics"), wxDefaultPosition, wxDefaultSize, wxRESIZE_BORDER|wxDEFAULT_DIALOG_STYLE);
	wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	wxString string;
	string += database->getProfilePath();
	string += "\n";
	string += "\n";

	for (size_t n=0;n<database->stats.size();n++)
	{
		string += database->stats[n];
		string += "\n";
	}

	wxTextCtrl *text = new wxTextCtrl(&dlg, wxID_ANY, string, wxDefaultPosition, wxDefaultSize, 
		wxBORDER_NONE|wxTE_READONLY|wxTE_MULTILINE|wxTE_NO_VSCROLL);
	text->SetBackgroundColour(dlg.GetBackgroundColour());
	sizer->Add(text, wxSizerFlags().Expand().Proportion(1).Border(wxALL, 10));

    wxSizer *sizerBtns = dlg.CreateButtonSizer(wxOK);
    if ( sizerBtns )
    {
        sizer->Add(sizerBtns, wxSizerFlags().Expand().Border());
    }

    dlg.SetSizerAndFit(sizer);
	dlg.SetSize(300, 200);
    dlg.CentreOnScreen();
	dlg.ShowModal();
}

void MainWin::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	ProfilerGUI::ShowAboutBox();
}

void MainWin::setCurrent(const std::wstring& currentfile_, int currentline_)
{
	if(currentfile != currentfile_ || currentline != currentline_)
	{
		currentfile = currentfile_;
		currentline = currentline_;

		SetStatusText(std::wstring("Source file: " + currentfile).c_str(), 0);
		SetStatusText(std::wstring("Line " + ::toString(currentline)).c_str(), 1);
	}
}
