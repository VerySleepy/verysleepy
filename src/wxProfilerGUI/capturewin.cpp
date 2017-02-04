/*=====================================================================
capturewin.cpp
----------------

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
#include "capturewin.h"
#include <shobjidl.h>
#include <wx/tglbtn.h>
#include <wx/stattext.h>
#include <wx/gauge.h>
#include <wx/button.h>
#include "../appinfo.h"

// If like me your SDK doesn't have the newest Windows 7 stuff, define it here ourselves.
// I swear they make this stuff complicated on purpose.
#ifndef __ITaskbarList3_INTERFACE_DEFINED__
#define __ITaskbarList3_INTERFACE_DEFINED__
typedef enum THUMBBUTTONFLAGS {THBF_ENABLED = 0, THBF_DISABLED = 0x1, THBF_DISMISSONCLICK = 0x2, THBF_NOBACKGROUND = 0x4, THBF_HIDDEN = 0x8, THBF_NONINTERACTIVE = 0x10} THUMBBUTTONFLAGS;
typedef enum THUMBBUTTONMASK {THB_BITMAP = 0x1, THB_ICON = 0x2, THB_TOOLTIP = 0x4, THB_FLAGS = 0x8} THUMBBUTTONMASK;
typedef struct THUMBBUTTON {THUMBBUTTONMASK dwMask; UINT iId; UINT iBitmap; HICON hIcon; WCHAR szTip[260]; THUMBBUTTONFLAGS dwFlags; } THUMBBUTTON;
typedef enum TBPFLAG  {TBPF_NOPROGRESS = 0, TBPF_INDETERMINATE = 0x1, TBPF_NORMAL = 0x2, TBPF_ERROR = 0x4, TBPF_PAUSED = 0x8 } TBPFLAG;
#define THBN_CLICKED  0x1800
extern "C" {const GUID IID_ITaskbarList3 = { 0xEA1AFB91, 0x9E28, 0x4B86, {0x90, 0xE9, 0x9E, 0x9F, 0x8A, 0x5E, 0xEF, 0xAF} };}

class ITaskbarList3 : public ITaskbarList2
{
public:
	virtual HRESULT STDMETHODCALLTYPE SetProgressValue      (HWND hwnd, ULONGLONG ullCompleted, ULONGLONG ullTotal) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetProgressState      (HWND hwnd, TBPFLAG tbpFlags) = 0;
	virtual HRESULT STDMETHODCALLTYPE RegisterTab           (HWND hwndTab, HWND hwndMDI) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnregisterTab         (HWND hwndTab) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetTabOrder           (HWND hwndTab,  HWND hwndInsertBefore) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetTabActive          (HWND hwndTab,  HWND hwndMDI, DWORD dwReserved) = 0;
	virtual HRESULT STDMETHODCALLTYPE ThumbBarAddButtons    (HWND hwnd, UINT cButtons, THUMBBUTTON * pButton) = 0;
	virtual HRESULT STDMETHODCALLTYPE ThumbBarUpdateButtons (HWND hwnd, UINT cButtons, THUMBBUTTON * pButton) = 0;
	virtual HRESULT STDMETHODCALLTYPE ThumbBarSetImageList  (HWND hwnd, HIMAGELIST himl) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOverlayIcon        (HWND hwnd, HICON hIcon, LPCWSTR pszDescription) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetThumbnailTooltip   (HWND hwnd, LPCWSTR pszTip) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetThumbnailClip      (HWND hwnd, RECT *prcClip) = 0;
};
#endif  /* ITaskbarList3 */

enum CaptureWinId
{
	CaptureWin_Pause = 1000,
};

// Doesn't really matter what number is here, it's just a guide
// so that we get good feedback around the 10000-50000 sample range.
#define MAX_RANGE		1600

BEGIN_EVENT_TABLE(CaptureWin, wxDialog)
EVT_TOGGLEBUTTON(CaptureWin_Pause, CaptureWin::OnPause)
EVT_BUTTON(wxID_OK, CaptureWin::OnOk)
EVT_BUTTON(wxID_CANCEL, CaptureWin::OnCancel)
END_EVENT_TABLE()

unsigned WM_TASKBARBUTTONCREATED = RegisterWindowMessage(L"TaskbarButtonCreated");

CaptureWin::CaptureWin()
:	wxDialog(NULL, -1, wxString(_T(APPNAME) _T(" - profiling")),
			 wxDefaultPosition, wxDefaultSize,
			 wxDEFAULT_DIALOG_STYLE)
{
	cancelled = stopped = paused = false;
	win7taskBar = NULL;

	wxBoxSizer *rootsizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *panelsizer = new wxBoxSizer(wxVERTICAL);

	rootsizer->SetMinSize(400, 0);

	wxPanel *panel = new wxPanel(this);

	progressText = new wxStaticText( panel, -1, "Waiting..." );
	progressBar = new wxGauge( panel, -1, 0, wxDefaultPosition, wxSize(100,18) );
	progressBar->SetRange(MAX_RANGE);

	wxBitmap pause = LoadPngResource(L"button_pause");
	pauseButton = new wxBitmapToggleButton(
		panel, CaptureWin_Pause, pause, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBU_EXACTFIT );

	wxButton *okButton = new wxButton(panel, wxID_OK, "&Stop");
	okButton->SetToolTip("Stop profiling and display collected results.");
	wxButton *cancelButton = new wxButton(panel, wxID_CANCEL, "&Abort");
	cancelButton->SetToolTip("Stop profiling, discard collected results, and exit.");

	int border = ConvertDialogToPixels(wxSize(2, 0)).x;
	wxSizer *buttons = new wxBoxSizer(wxHORIZONTAL);
	buttons->Add(pauseButton,				0, wxALIGN_LEFT,					border);
	buttons->AddStretchSpacer();
	buttons->Add(okButton,					0, wxALIGN_RIGHT | wxLEFT|wxRIGHT,	border);
	buttons->Add(cancelButton,				0, wxALIGN_RIGHT | wxLEFT,			border);

	panelsizer->Add(progressText, 0, wxBOTTOM, 3);
	panelsizer->Add(progressBar, 0, wxBOTTOM|wxEXPAND, 10);
	panelsizer->Add(buttons, 0, wxEXPAND);

	okButton->SetDefault();

	panel->SetSizer(panelsizer);
	panel->SetAutoLayout(TRUE);

	rootsizer->Add(panel, 1, wxEXPAND | wxALL, 10);
	SetSizer(rootsizer);
	rootsizer->SetSizeHints(this);
	SetAutoLayout(TRUE);

	Centre();
}

CaptureWin::~CaptureWin()
{
	if (win7taskBar)
		win7taskBar->Release();
}

WXLRESULT CaptureWin::MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam)
{
	if (nMsg == WM_TASKBARBUTTONCREATED)
	{
		// If windows 7, use the fancy taskbar progress update.
		// On non-windows 7, the COM create should just fail and we'll simply not use it.
		CoCreateInstance(CLSID_TaskbarList, 0, CLSCTX_INPROC_SERVER,
			IID_ITaskbarList3, (LPVOID *)&win7taskBar);

		if (win7taskBar)
		{
			win7taskBar->SetProgressState(GetHandle(), TBPF_NORMAL);
		}

		return 0;
	} else {
		return wxDialog::MSWWindowProc(nMsg, wParam, lParam);
	}
}

bool CaptureWin::UpdateProgress(const wchar_t *status, int numSamples, int numThreads, int timeout)
{
	if (!paused)
	{
		double elapsed = stopwatch.Time() / 1000.0f;

		if (status)
		{
			progressText->SetLabel(status);
			progressBar->Pulse();
		}
		else
		{
			char tmp[256];
			int n=0;
			if( timeout == -1 )
			{
				// RM: 20130614 Run forever, until cancelled
				sprintf(tmp, "%i samples, %.1fs elapsed, %i threads running", numSamples, elapsed, numThreads);
				progressBar->Pulse();
			}
			else
			{
				// RM: 20130614 Run for set time
				sprintf(tmp, "%i samples, %.1fs/%ds elapsed, %i threads running", numSamples, elapsed, timeout, numThreads);
				n = elapsed / timeout * MAX_RANGE;
				progressBar->SetValue(n);

				if (win7taskBar)
					win7taskBar->SetProgressValue(GetHandle(), n, MAX_RANGE);
			}

			progressText->SetLabel(tmp);
		}
	}

	return !stopped;
}

void CaptureWin::OnPause(wxCommandEvent& event)
{
	paused = event.IsChecked();
	if (paused)
	{
		stopwatch.Pause();
		pauseButton->SetBitmapLabel(LoadPngResource(L"button_go"));
	} else {
		stopwatch.Resume();
		pauseButton->SetBitmapLabel(LoadPngResource(L"button_pause"));
	}

	SetTitle(paused ? _T(APPNAME) L" - paused" : _T(APPNAME) L" - profiling");

	if (win7taskBar)
	{
		win7taskBar->SetProgressState(GetHandle(), paused ? TBPF_PAUSED : TBPF_NORMAL);
	}
}

void CaptureWin::OnOk(wxCommandEvent& WXUNUSED(event))
{
	if (win7taskBar)
	{
		win7taskBar->SetProgressState(GetHandle(), TBPF_NOPROGRESS);
	}

	stopped = true;
}

void CaptureWin::OnCancel(wxCommandEvent& WXUNUSED(event))
{
	if (win7taskBar)
	{
		win7taskBar->SetProgressState(GetHandle(), TBPF_NOPROGRESS);
	}

	cancelled = true;
	stopped = true;
}
