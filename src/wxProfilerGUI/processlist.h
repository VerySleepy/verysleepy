/*=====================================================================
processlist.h
-------------
File created by ClassTemplate on Sun Mar 20 17:33:43 2005

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
#ifndef __PROCESSLIST_H_666_
#define __PROCESSLIST_H_666_

#include "profilergui.h"
#include "../profiler/processinfo.h"
#include "../utils/sortlist.h"

// DE: 20090325 ProcessList knows about threadlist and updates it based on process selection
class ThreadList;
class SymbolInfo;

/*=====================================================================
ProcessList
-----------

=====================================================================*/
class ProcessList : public wxSortedListCtrl
{
public:
	/*=====================================================================
	ProcessList
	-----------

	=====================================================================*/
	// DE: 20090325 ProcessList knows about threadlist and updates it based on process selection
	ProcessList(wxWindow *parent, const wxPoint& pos,
			const wxSize& size,
			ThreadList* threadList);

	virtual ~ProcessList();

	void OnSelected(wxListEvent& event);
	void OnTimer(wxTimerEvent& event);
	void OnSort(wxListEvent& event);

	void updateProcesses();
	void updateTimes();
	void updateThreadList();
	void updateSorting();
	void sortByName();
	void sortByCpuUsage();
	void sortByTotalCpuTime();
	void sortByPID();
#ifdef _WIN64
	void sortByType();
#endif
	void reloadSymbols(bool download);

	const ProcessInfo* getSelectedProcess();
	SymbolInfo* takeSymbolInfo();
private:
	DECLARE_EVENT_TABLE()

	enum {
		COL_NAME,
#ifdef _WIN64
		COL_TYPE,
#endif
		COL_CPUUSAGE,
		COL_TOTALCPU,
		COL_PID,
		NUM_COLUMNS
	};

	std::vector<ProcessInfo> processes;
	// DE: 20090325 ProcessList knows about threadlist and updates it based on process selection
	ThreadList* threadList;
	SymbolInfo *syminfo;

	int selected_process;
	wxTimer timer;
	wxLongLong lastTime;
	int sort_column;
	SortType sort_dir;
	// DE: 20090325 Update thread list on process selection change, but do it on idle
	bool selectionChanged;
	bool firstUpdate;

	void fillList();
};


enum
{
	PROCESS_LIST = 4000,
	PROCESS_LIST_TIMER = 4001
};


#endif //__PROCESSLIST_H_666_
