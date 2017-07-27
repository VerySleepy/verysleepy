/*=====================================================================
threadList.cpp
---------------
File created by ClassTemplate on Sun Mar 20 17:33:43 2005

Copyright (C) Dan Engelbrecht

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
#include "threadList.h"
#include "database.h"
#include "../profiler/profiler.h"
#include "../profiler/symbolinfo.h"
#include "../utils/osutils.h"
#include <algorithm>
#include <wx/button.h>

#define UPDATE_DELAY 1000	 // 1 second interval
#define MAX_NUM_THREAD_LOCATIONS 100 // getting location of thread is very expensive, so only show it for the first X threads in the list
#define MAX_NUM_DISPLAYED_THREADS 1000 // creating very large tables is expensive, limit number of threads to first X in selected sort order

BEGIN_EVENT_TABLE(ThreadList, wxListCtrl)
EVT_LIST_ITEM_SELECTED(THREADS_LIST, ThreadList::OnSelected)
EVT_LIST_ITEM_DESELECTED(THREADS_LIST, ThreadList::OnDeSelected)
EVT_LIST_COL_CLICK(-1, ThreadList::OnSort)
EVT_TIMER(THREADS_LIST_TIMER, ThreadList::OnTimer)
END_EVENT_TABLE()

ThreadList::ThreadList(wxWindow *parent, const wxPoint& pos,
						 const wxSize& size, wxButton *_ok_button, wxButton *_all_button)
						 :	wxSortedListCtrl(parent, THREADS_LIST, pos, size, wxLC_REPORT),
						 timer(this, THREADS_LIST_TIMER),
						 ok_button(_ok_button), all_button(_all_button)
{
	InitSort();

	wxListItem itemCol;
	itemCol.m_mask = wxLIST_MASK_TEXT/* | wxLIST_MASK_IMAGE*/;
	itemCol.m_image = -1;
	itemCol.m_text = _T("Location");
	InsertColumn(COL_LOCATION, itemCol);
	itemCol.m_text = _T("CPU");
	InsertColumn(COL_CPUUSAGE, itemCol);
	itemCol.m_text = _T("Total CPU");
	InsertColumn(COL_TOTALCPU, itemCol);
	itemCol.m_text = _T("TID");
	InsertColumn(COL_ID, itemCol);

	SetColumnWidth(COL_LOCATION, 220);
	SetColumnWidth(COL_CPUUSAGE, 80);
	SetColumnWidth(COL_TOTALCPU, 100);
	SetColumnWidth(COL_ID, 60);

	sort_column = COL_CPUUSAGE;
	sort_dir = SORT_DOWN;
	SetSortImage(sort_column, sort_dir);

	process_handle = NULL;
	syminfo = NULL;

	lastTime = wxGetLocalTimeMillis();
	updateThreads(NULL, NULL);
	timer.Start(UPDATE_DELAY);
}


ThreadList::~ThreadList()
{

}

void ThreadList::OnSelected(wxListEvent& event)
{
	this->selected_threads.insert(event.m_itemIndex);
	ok_button->Enable(true);
}

void ThreadList::OnDeSelected(wxListEvent& event)
{
	this->selected_threads.erase(event.m_itemIndex);
	if (this->selected_threads.empty())
		ok_button->Enable(false);
}

std::vector<const ThreadInfo*> ThreadList::getSelectedThreads(bool all)
{
	std::vector<const ThreadInfo*> selectedThreads;
	if(all) {
		selectedThreads.reserve(this->threads.size());
		for(size_t i=0;i<threads.size();i++) {
			selectedThreads.push_back(&threads[i]);
		}
	} else {
		selectedThreads.reserve(this->selected_threads.size());
		for (auto it = this->selected_threads.begin(); it != this->selected_threads.end(); ++it)
		{
			int selected_thread = *it;
			if(selected_thread >= 0 && selected_thread < (int)threads.size())
			{
				selectedThreads.push_back(&threads[selected_thread]);
			}
		}
	}
	return selectedThreads;
}

void ThreadList::OnTimer(wxTimerEvent& WXUNUSED(event))
{
	updateTimes();
}

struct LocationAscPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.getLocation() < b.getLocation();
} };

struct LocationDescPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.getLocation() > b.getLocation();
} };

struct CpuUsageAscPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.cpuUsage < b.cpuUsage;
} };

struct CpuUsageDescPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.cpuUsage > b.cpuUsage;
} };

struct TotalCpuTimeAscPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.totalCpuTimeMs < b.totalCpuTimeMs;
} };

struct TotalCpuTimeDescPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.totalCpuTimeMs > b.totalCpuTimeMs;
} };

struct IdAscPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.getID() < b.getID();
} };

struct IdDescPred { bool operator () (const ThreadInfo &a, const ThreadInfo &b) {
	return a.getID() > b.getID();
} };

void ThreadList::sortByLocation()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(threads.begin(), threads.end(), LocationAscPred());
	else
		std::stable_sort(threads.begin(), threads.end(), LocationDescPred());
}

void ThreadList::sortByCpuUsage()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(threads.begin(), threads.end(), CpuUsageAscPred());
	else
		std::stable_sort(threads.begin(), threads.end(), CpuUsageDescPred());
}

void ThreadList::sortByTotalCpuTime()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(threads.begin(), threads.end(), TotalCpuTimeAscPred());
	else
		std::stable_sort(threads.begin(), threads.end(), TotalCpuTimeDescPred());
}

void ThreadList::sortByID()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(threads.begin(), threads.end(), IdAscPred());
	else
		std::stable_sort(threads.begin(), threads.end(), IdDescPred());
}

void ThreadList::OnSort(wxListEvent& event)
{
	SetSortImage(sort_column, SORT_NONE);

	if (sort_column == event.m_col)
	{
		// toggle if we clicked on the same column as last time
		sort_dir = (SortType)((SORT_UP+SORT_DOWN) - sort_dir);
	} else {
		// if switching columns, start with the default sort for that column type
		sort_column = event.m_col;
		sort_dir = (sort_column >= 1 && sort_column <= 4) ? SORT_DOWN : SORT_UP;
	}

	SetSortImage(sort_column, sort_dir);
	updateSorting();
}

void ThreadList::updateSorting()
{
	switch(sort_column) {
		case COL_LOCATION:	sortByLocation(); break;
		case COL_CPUUSAGE:	sortByCpuUsage(); break;
		case COL_TOTALCPU:	sortByTotalCpuTime(); break;
		case COL_ID:		sortByID(); break;
	}
	fillList();
}

int ThreadList::getNumDisplayedThreads() {
	int numThreads = (int) threads.size();
	return numThreads < MAX_NUM_DISPLAYED_THREADS ? numThreads : MAX_NUM_DISPLAYED_THREADS;
}

void ThreadList::fillList()
{
	Freeze();

	int numDisplayedThreads = getNumDisplayedThreads();
	for(int i=0; i<numDisplayedThreads; ++i)
	{
		this->SetItem(i, COL_LOCATION, threads[i].getLocation());

		char str[32];
		if (threads[i].cpuUsage >= 0)
			sprintf(str, "%i%%", threads[i].cpuUsage);
		else
			strcpy(str, "-");
		this->SetItem(i, COL_CPUUSAGE, str);

		if (threads[i].totalCpuTimeMs >= 0)
			sprintf(str, "%0.1f s", (double) (threads[i].totalCpuTimeMs) / 1000);
		else
			strcpy(str, "-");
		this->SetItem(i, COL_TOTALCPU, str);

		sprintf(str, "%d", threads[i].getID());
		this->SetItem(i, COL_ID, str);
	}
	Thaw();
}

void ThreadList::updateThreads(const ProcessInfo* processInfo, SymbolInfo *symInfo)
{
	this->selected_threads.clear();
	DeleteAllItems();
	this->threads.clear();
	ok_button->Enable(false);
	all_button->Enable(false);

	if(processInfo != NULL)
	{
		this->process_handle = processInfo->getProcessHandle();
		this->syminfo = symInfo;

		this->threads = processInfo->threads;

		int numDisplayedThreads = getNumDisplayedThreads();
		for(int i=0; i<numDisplayedThreads; ++i)
		{
			long tmp = this->InsertItem(i, "", -1);
			SetItemData(tmp, i);
		}

		all_button->Enable(this->threads.size() != 0);

		lastTime = wxGetLocalTimeMillis();
		updateTimes();
		updateSorting();
		fillList();
	}
}

void ThreadList::updateTimes()
{
	wxLongLong now = wxGetLocalTimeMillis();
	int sampleTimeDiff = (now - lastTime).ToLong();
	lastTime = now;

	for(int i=0; i<(int)this->threads.size(); ++i)
	{
		if (!this->threads[i].recalcUsage(sampleTimeDiff))
			continue;

		HANDLE thread_handle = this->threads[i].getThreadHandle();
		if (thread_handle == NULL)
			continue;

		this->threads[i].setLocation(L"-");
		if (i < MAX_NUM_THREAD_LOCATIONS) {
			std::wstring loc = getLocation(thread_handle);
			this->threads[i].setLocation(loc);
		}
	}

	fillList();
}

std::wstring ThreadList::getLocation(HANDLE thread_handle) {
	PROFILER_ADDR profaddr = 0;
	try {
		std::map<CallStack, SAMPLE_TYPE> callstacks;
		std::map<PROFILER_ADDR, SAMPLE_TYPE> flatcounts;
		Profiler profiler(process_handle, thread_handle, callstacks, flatcounts);
		bool ok = profiler.sampleTarget(0, syminfo);
		if (ok && !profiler.targetExited() && callstacks.size() > 0)
		{
			const CallStack &stack = callstacks.begin()->first;
			profaddr = stack.addr[0];

			// Collapse functions down
			if (syminfo && stack.depth > 0)
			{
				for (size_t n=0;n<stack.depth;n++)
				{
					PROFILER_ADDR addr = stack.addr[n];
					std::wstring mod = syminfo->getModuleNameForAddr(addr);
					if (IsOsModule(mod))
					{
						profaddr = addr;
					} else {
						break;
					}
				}

				for (int n=(int)stack.depth-1;n>=0;n--)
				{
					std::wstring file;
					int line;

					PROFILER_ADDR addr = stack.addr[n];
					std::wstring loc = syminfo->getProcForAddr(addr, file, line);
					if (IsOsFunction(loc))
					{
						profaddr = addr;
						break;
					}
				}
			}
		}
	} catch( ProfilerExcep &)
	{
	}

	if (profaddr && syminfo)
	{
		std::wstring file;
		int line;

		// Grab the name of the current IP location.
		return syminfo->getProcForAddr(profaddr, file, line);
	}

	return L"-";
}
