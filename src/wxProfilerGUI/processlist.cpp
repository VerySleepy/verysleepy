/*=====================================================================
processlist.cpp
---------------
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
#include "processlist.h"
#include "threadlist.h"
#include "../profiler/symbolinfo.h"
#include "../utils/osutils.h"
#include <algorithm>
#include "../utils/except.h"

BEGIN_EVENT_TABLE(ProcessList, wxListCtrl)
EVT_LIST_ITEM_SELECTED(PROCESS_LIST, ProcessList::OnSelected)
EVT_LIST_COL_CLICK(-1, ProcessList::OnSort)
EVT_TIMER(PROCESS_LIST_TIMER, ProcessList::OnTimer)
END_EVENT_TABLE()

ProcessList::ProcessList(wxWindow *parent, const wxPoint& pos,
						 const wxSize& size,
						ThreadList* threadList_)
						 :	wxSortedListCtrl(parent, PROCESS_LIST, pos, size, wxLC_REPORT | wxLC_SINGLE_SEL),
						 timer(this, PROCESS_LIST_TIMER)
{
	threadList = threadList_;
	selectionChanged = false;
	firstUpdate = true;
	InitSort();

	selected_process = -1;
	syminfo = new SymbolInfo();

	wxListItem itemCol;
	itemCol.m_mask = wxLIST_MASK_TEXT/* | wxLIST_MASK_IMAGE*/;
	itemCol.m_text = _T("Process");
	itemCol.m_image = -1;
	InsertColumn(COL_NAME, itemCol);
	itemCol.m_text = _T("CPU");
	InsertColumn(COL_CPUUSAGE, itemCol);
	itemCol.m_text = _T("Total CPU");
	InsertColumn(COL_TOTALCPU, itemCol);
	itemCol.m_text = _T("PID");
	InsertColumn(COL_PID, itemCol);

	SetColumnWidth(COL_NAME, 220);
	SetColumnWidth(COL_CPUUSAGE, 80);
	SetColumnWidth(COL_TOTALCPU, 100);
	SetColumnWidth(COL_PID, 60);

#ifdef _WIN64
	itemCol.m_text = _T("Type");
	InsertColumn(COL_TYPE, itemCol);
	SetColumnWidth(COL_TYPE, 45);
#endif

	sort_column = COL_CPUUSAGE;
	sort_dir = SORT_DOWN;
	SetSortImage(sort_column, sort_dir);

	timer.Start(1000); // 1 second interval
}


ProcessList::~ProcessList()
{
	if (syminfo)
		delete syminfo;
}

void ProcessList::reloadSymbols(bool download)
{
	delete syminfo;
	syminfo = new SymbolInfo;

	//------------------------------------------------------------------------
	//load up the debug info for it
	//------------------------------------------------------------------------
	try
	{
		const ProcessInfo* process_info = getSelectedProcess();
		if (!process_info)
			throw SleepyException(L"No process selected");

		HANDLE process_handle = process_info->getProcessHandle();
		if (process_handle)
		{
			syminfo->loadSymbols(process_handle, download);
		}
	}
	catch (SleepyException &e)
	{
		::MessageBox(NULL, std::wstring(L"Error: " + e.wwhat()).c_str(), L"Profiler Error", MB_OK);
		delete syminfo;
		syminfo = NULL;
	}

	updateThreadList();
}

void ProcessList::OnSelected(wxListEvent& event)
{
	if(this->selected_process != event.m_itemIndex)
	{
		this->selected_process = event.m_itemIndex;
		selectionChanged = true;

		reloadSymbols(false);
	}
}

const ProcessInfo* ProcessList::getSelectedProcess()
{
	if(selected_process >= 0 && selected_process < (int)processes.size())
	{
		return &processes[selected_process];
	}
	else
		return NULL;
}

SymbolInfo *ProcessList::takeSymbolInfo()
{
	SymbolInfo *sym = syminfo;
	syminfo = NULL;
	return sym;
}

static __int64 getDiff(FILETIME before, FILETIME after)
{
	__int64 i0 = (__int64(before.dwHighDateTime) << 32) + before.dwLowDateTime;
	__int64 i1 = (__int64( after.dwHighDateTime) << 32) +  after.dwLowDateTime;
	return i1 - i0;
}

static __int64 getTotal(FILETIME time)
{
	return (__int64(time.dwHighDateTime) << 32) + time.dwLowDateTime;
}

void ProcessList::updateThreadList()
{
	if (syminfo && selected_process >= 0 && selected_process < (int)processes.size())
	{
		threadList->updateThreads(&processes[this->selected_process], syminfo);
	} else {
		threadList->updateThreads(NULL, NULL);
	}
}

void ProcessList::OnTimer(wxTimerEvent& WXUNUSED(event))
{
	if (firstUpdate)
	{
		firstUpdate = false;

		updateProcesses();
	}

	updateTimes();
	if(selectionChanged){
		selectionChanged = false;
		updateThreadList();
	}
}

struct NameAscPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return wcsicmp(a.getName().c_str(), b.getName().c_str()) < 0;
} };

struct NameDescPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return wcsicmp(a.getName().c_str(), b.getName().c_str()) > 0;
} };

struct CpuUsageAscPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return a.cpuUsage < b.cpuUsage;
} };

struct CpuUsageDescPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return a.cpuUsage > b.cpuUsage;
} };

struct TotalCpuTimeAscPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return a.totalCpuTimeMs < b.totalCpuTimeMs;
} };

struct TotalCpuTimeDescPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return a.totalCpuTimeMs > b.totalCpuTimeMs;
} };

struct PIDAscPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return a.getID() < b.getID();
} };

struct PIDDescPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	return a.getID() > b.getID();
} };

#ifdef _WIN64
struct TypeAscPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	if(a.getIs64Bits() == b.getIs64Bits()) {
		CpuUsageAscPred cmp;
		return cmp(a,b);
	}
	return a.getIs64Bits() < b.getIs64Bits();
} };

struct TypeDescPred { bool operator () (const ProcessInfo &a, const ProcessInfo &b) {
	if(a.getIs64Bits() == b.getIs64Bits()) {
		CpuUsageDescPred cmp;
		return cmp(a,b);
	}
	return a.getIs64Bits() > b.getIs64Bits();
} };
#endif

void ProcessList::sortByName()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(processes.begin(), processes.end(), NameAscPred());
	else
		std::stable_sort(processes.begin(), processes.end(), NameDescPred());
}

void ProcessList::sortByCpuUsage()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(processes.begin(), processes.end(), CpuUsageAscPred());
	else
		std::stable_sort(processes.begin(), processes.end(), CpuUsageDescPred());
}

void ProcessList::sortByTotalCpuTime()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(processes.begin(), processes.end(), TotalCpuTimeAscPred());
	else
		std::stable_sort(processes.begin(), processes.end(), TotalCpuTimeDescPred());
}

void ProcessList::sortByPID()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(processes.begin(), processes.end(), PIDAscPred());
	else
		std::stable_sort(processes.begin(), processes.end(), PIDDescPred());
}

#ifdef _WIN64
void ProcessList::sortByType()
{
	if (sort_dir == SORT_UP)
		std::stable_sort(processes.begin(), processes.end(), TypeAscPred());
	else
		std::stable_sort(processes.begin(), processes.end(), TypeDescPred());
}
#endif
void ProcessList::OnSort(wxListEvent& event)
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

void ProcessList::updateSorting()
{
	switch(sort_column) {
		case COL_NAME: sortByName(); break;
		case COL_CPUUSAGE: sortByCpuUsage(); break;
		case COL_TOTALCPU: sortByTotalCpuTime(); break;
		case COL_PID: sortByPID(); break;
#ifdef _WIN64
		case COL_TYPE: sortByType(); break;
#endif
	}
	fillList();
}

void ProcessList::fillList()
{
	Freeze();
	for(int i=0; i<(int)processes.size(); ++i)
	{
		this->SetItem(i, COL_NAME, processes[i].getName().c_str());

		char str[32];
		if (processes[i].cpuUsage >= 0)
			sprintf(str, "%i%%", processes[i].cpuUsage);
		else
			strcpy(str, "-");
		this->SetItem(i, COL_CPUUSAGE, str);

		if (processes[i].totalCpuTimeMs >= 0)
			sprintf(str, "%0.1f s", (double) (processes[i].totalCpuTimeMs) / 1000);
		else
			strcpy(str, "-");
		this->SetItem(i, COL_TOTALCPU, str);

		sprintf(str, "%i", processes[i].getID());
		this->SetItem(i, COL_PID, str);
#ifdef _WIN64
		if(Is64BitProcess(processes[i].getProcessHandle())) {
			SetItem(i,COL_TYPE,"64-bit");
		} else {
			SetItem(i,COL_TYPE,"32-bit");
		}
#endif
	}
	Thaw();
}

void ProcessList::updateProcesses()
{
	DWORD selectedProcessId = 0xffffffff;
	bool processWasSelected = false;
	const ProcessInfo* selectedProcess = this->getSelectedProcess();
	if(selectedProcess != NULL){
		processWasSelected = true;
		selectedProcessId = selectedProcess->getID();
	}
	this->selected_process = -1;
	DeleteAllItems();

	for(size_t i=0; i<processes.size(); ++i)
	{
		CloseHandle( processes[i].getProcessHandle() );

		for(size_t j=0; j<processes[i].threads.size(); ++j)
			CloseHandle( processes[i].threads[j].getThreadHandle() );
	}
	processes.clear();
	threadList->updateThreads(NULL, NULL);

	ProcessInfo::enumProcesses(this->processes);
	for(int i=0; i<(int)processes.size(); ++i)
	{
		long tmp = this->InsertItem(i, "", -1);
		SetItemData(tmp, i);
	}

	// Select the selected process last time the program was run..
	if(selectedProcessId == ~0) {
		wxString prevProcess;
		config.Read("PrevProcess", &prevProcess, "");
		if(!prevProcess.IsEmpty()) {
			for(int i=0; i<(int)processes.size(); ++i)
			{
				if(processes[i].getName() == prevProcess)
				{
					selectedProcessId = processes[i].getID();
					processWasSelected = true;
					break;
				}
			}
		}
	}

	lastTime = wxGetLocalTimeMillis();

	// We need to wait a bit before we can get any useful CPU usage data to sort on.
	updateTimes();
	Sleep(200);
	updateTimes();

	updateSorting();
	fillList();
	if(processWasSelected){
		int index = 0;
		for (auto it = this->processes.begin(); it != this->processes.end(); ++it)
		{
			const ProcessInfo& processInfo(*it);
			if(processInfo.getID() == selectedProcessId){
				this->SetFocus();
				this->EnsureVisible(index);
				int state = this->GetItemState(index, wxLIST_STATE_SELECTED);
				state |= wxLIST_STATE_SELECTED;
				this->SetItemState(index, state, wxLIST_STATE_SELECTED);
				break;
			}
			++index;
		}
	}
}

void ProcessList::updateTimes()
{
	wxLongLong now = wxGetLocalTimeMillis();
	int sampleTimeDiff = (now - lastTime).ToLong();
	lastTime = now;

	for(int i=0; i<(int)processes.size(); ++i)
	{
		processes[i].cpuUsage = -1;
		processes[i].totalCpuTimeMs = -1;

		__int64 coreCount = 0;

		HANDLE process_handle = processes[i].getProcessHandle();
		if (!process_handle)
			continue;

		FILETIME CreationTime, ExitTime, KernelTime, UserTime;
		BOOL result = GetProcessTimes(
			process_handle,
			&CreationTime,
			&ExitTime,
			&KernelTime,
			&UserTime
		);
		if (!result)
			continue;

		coreCount = GetCoresForProcess(process_handle);

		__int64 kernel_diff = getDiff(processes[i].prevKernelTime, KernelTime);
		__int64 user_diff = getDiff(processes[i].prevUserTime, UserTime);
		processes[i].prevKernelTime = KernelTime;
		processes[i].prevUserTime = UserTime;

		if (sampleTimeDiff > 0)
			processes[i].cpuUsage = (((kernel_diff + user_diff) / 10000) * 100 / sampleTimeDiff) / coreCount;

		processes[i].totalCpuTimeMs = (getTotal(KernelTime) + getTotal(UserTime)) / 10000;
	}

	fillList();
}
