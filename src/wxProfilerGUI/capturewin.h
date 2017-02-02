/*=====================================================================
capturewin.h
--------------

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
#ifndef __CAPTUREWIN_H__
#define __CAPTUREWIN_H__

#include "profilergui.h"

class CaptureWin : public wxDialog
{
public:
	CaptureWin();
	virtual ~CaptureWin();

	bool UpdateProgress(const wchar_t *status, int numSamples, int numThreads, int timeout);

	bool Paused() { return paused; }
	bool Cancelled() { return cancelled; }

	virtual WXLRESULT MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam);

private:
	void OnOk( wxCommandEvent & event );
	void OnPause( wxCommandEvent & event );
	void OnCancel( wxCommandEvent & event );

	bool cancelled, stopped, paused;
	wxGauge *progressBar;
	wxStaticText *progressText;
	wxStopWatch stopwatch;
	class wxBitmapToggleButton *pauseButton;
	struct ITaskbarList3 *win7taskBar;

	DECLARE_EVENT_TABLE()
};


#endif //__CAPTUREWIN_H__
