/*=====================================================================
threadsview.cpp
------------

Copyright (C) Very Sleepy authors and contributors

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
#include "threadsview.h"
#include "mainwin.h"

BEGIN_EVENT_TABLE(ThreadsView, wxListCtrl)
EVT_LIST_ITEM_SELECTED(THREADS_VIEW, ThreadsView::OnSelected)
EVT_LIST_ITEM_DESELECTED(THREADS_VIEW, ThreadsView::OnDeSelected)
EVT_LIST_COL_CLICK(-1, ThreadsView::OnSort)
EVT_TIMER(THREADS_VIEW_TIMER, ThreadsView::OnTimer)
END_EVENT_TABLE()


ThreadsView::ThreadsView(wxWindow *parent, Database *database_)
	: wxSortedListCtrl(parent, THREADS_VIEW, wxDefaultPosition, wxDefaultSize, wxLC_REPORT /*style*/)
	, selectionTimer(this, THREADS_VIEW_TIMER)
{
	InitSort();

	wxListItem itemCol;
	itemCol.m_mask = wxLIST_MASK_TEXT;
	itemCol.m_image = -1;
	itemCol.m_text = _T("TID");
	InsertColumn(COL_TID, itemCol);
	itemCol.m_text = _T("Thread Name");
	InsertColumn(COL_NAME, itemCol);

	SetColumnWidth(COL_TID, FromDIP(80));
	SetColumnWidth(COL_NAME, FromDIP(200));

	database = database_;
	sort_column = COL_TID;
	sort_dir = SORT_UP;
	SetSortImage(sort_column, sort_dir);
}

ThreadsView::~ThreadsView()
{
}

void ThreadsView::OnSelected(wxListEvent &WXUNUSED(event))
{
	startSelectionTimer();
}

void ThreadsView::OnDeSelected(wxListEvent &WXUNUSED(event))
{
	startSelectionTimer();
}

void ThreadsView::startSelectionTimer()
{
	// user interactions typically generate a series of selection change events
	// so we only update the main window 100ms after selection events have stopped coming
	selectionTimer.Stop();
	selectionTimer.StartOnce(100);
}

void ThreadsView::OnTimer(wxTimerEvent &WXUNUSED(event))
{
	theMainWin->refreshSelectedThreads();
}

void ThreadsView::OnSort(wxListEvent &event)
{
	SetSortImage(sort_column, SORT_NONE);

	if (sort_column == event.m_col)
	{
		// toggle if we clicked on the same column as last time
		sort_dir = (SortType)((SORT_UP + SORT_DOWN) - sort_dir);
	} else {
		// if switching columns, start with the default sort for that column type
		sort_column = event.m_col;
		sort_dir = SORT_UP;
	}

	SetSortImage(sort_column, sort_dir);

	sortThreads();
	fillList();
}

void ThreadsView::updateList()
{
	getThreadsFromDatabase();
	sortThreads();
	fillList();
}

std::vector<Database::ThreadID> ThreadsView::getSelectedThreads()
{
	std::vector<Database::ThreadID> selected;
	for (long i = GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); i >= 0; i = GetNextItem(i, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED))
	{
		int ind = GetItemData(i);
		selected.push_back(threads[ind].tid);
	}
	return selected;
}

void ThreadsView::clearSelectedThreads()
{
	std::vector<Database::ThreadID> selected;
	for (long i = GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED); i >= 0; i = GetNextItem(i, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED))
	{
		SetItemState(i, 0, wxLIST_STATE_SELECTED);
	}
}

void ThreadsView::focusThread(Database::ThreadID tid)
{
	auto it = std::find_if(threads.begin(), threads.end(), [=](ThreadRow &r) { return r.tid == tid; });
	if (it == threads.end())
		return;
	long i = FindItem(-1, std::distance(threads.begin(), it));
	if (i >= 0)
	{
		SetItemState(i, wxLIST_STATE_FOCUSED, wxLIST_STATE_FOCUSED);
		EnsureVisible(i);

		for (int j = 0; j < GetItemCount(); ++j)
		{
			SetItemTextColour(j, wxColor(0, i == j ? 128 : 0, 0));
		}
	}
}

void ThreadsView::getThreadsFromDatabase()
{
	threads.clear();
	for (auto &tn : database->getThreadNames())
	{
		ThreadRow row;
		row.tid = tn.first;
		row.name = tn.second;
		threads.push_back(row);
	}
}

static std::wstring toLower(std::wstring s)
{
	std::transform(s.begin(), s.end(), s.begin(), tolower);
	return s;
}

void ThreadsView::sortThreads()
{
	switch (sort_column)
	{
		case COL_TID:
			std::stable_sort(threads.begin(), threads.end(), [](ThreadRow const &t0, ThreadRow const &t1) {
				return t0.tid < t1.tid;
			});
			break;
		case COL_NAME:
			std::stable_sort(threads.begin(), threads.end(), [](ThreadRow const &t0, ThreadRow const &t1) {
				return toLower(t0.name) < toLower(t1.name);
			});
			break;
	}
	if (sort_dir == SORT_DOWN)
		std::reverse(threads.begin(), threads.end());
}

void ThreadsView::fillList()
{
	Freeze();
	DeleteAllItems();

	for (int i = 0; i < (int)threads.size(); ++i)
	{
		long tmp = InsertItem(i, "", -1);
		SetItemData(tmp, i);

		wxString tid = wxString::Format("%d", threads[i].tid);
		SetItem(i, COL_TID, tid);

		SetItem(i, COL_NAME, threads[i].name);
	}

	Thaw();
}


BEGIN_EVENT_TABLE(ThreadSamplesView, wxListCtrl)
EVT_LIST_COL_CLICK(-1, ThreadSamplesView::OnSort)
EVT_LIST_ITEM_ACTIVATED(THREAD_SAMPLES_VIEW, ThreadSamplesView::OnActivated)
END_EVENT_TABLE()


ThreadSamplesView::ThreadSamplesView(wxWindow *parent, Database *database_)
	: wxSortedListCtrl(parent, THREAD_SAMPLES_VIEW, wxDefaultPosition, wxDefaultSize, wxLC_REPORT /*style*/)
{
	InitSort();

	wxListItem itemCol;
	itemCol.m_mask = wxLIST_MASK_TEXT;
	itemCol.m_image = -1;
	itemCol.m_text = _T("TID");
	InsertColumn(COL_TID, itemCol);
	itemCol.m_text = _T("Thread Name");
	InsertColumn(COL_NAME, itemCol);
	itemCol.m_text = _T("Exclusive");
	InsertColumn(COL_EXCLUSIVE, itemCol);
	itemCol.m_text = _T("Inclusive");
	InsertColumn(COL_INCLUSIVE, itemCol);
	itemCol.m_text = _T("% Exclusive");
	InsertColumn(COL_EXCLUSIVEPCT, itemCol);
	itemCol.m_text = _T("% Inclusive");
	InsertColumn(COL_INCLUSIVEPCT, itemCol);

	SetColumnWidth(COL_TID, FromDIP(80));
	SetColumnWidth(COL_NAME, FromDIP(200));
	SetColumnWidth(COL_EXCLUSIVE, FromDIP(70));
	SetColumnWidth(COL_INCLUSIVE, FromDIP(70));
	SetColumnWidth(COL_EXCLUSIVEPCT, FromDIP(70));
	SetColumnWidth(COL_INCLUSIVEPCT, FromDIP(70));

	database = database_;
	sort_column = COL_EXCLUSIVE;
	sort_dir = SORT_DOWN;
	SetSortImage(sort_column, sort_dir);

}

ThreadSamplesView::~ThreadSamplesView()
{
}

void ThreadSamplesView::OnSort(wxListEvent &event)
{
	SetSortImage(sort_column, SORT_NONE);

	if (sort_column == event.m_col)
	{
		// toggle if we clicked on the same column as last time
		sort_dir = (SortType)((SORT_UP + SORT_DOWN) - sort_dir);
	} else {
		// if switching columns, start with the default sort for that column type
		sort_column = event.m_col;
		sort_dir = SORT_UP;
	}

	SetSortImage(sort_column, sort_dir);

	sortThreads();
	fillList();
}

void ThreadSamplesView::OnActivated(wxListEvent &event)
{
	Database::ThreadID tid = threads[event.GetData()].tid;
	theMainWin->focusThread(tid);
}

void ThreadSamplesView::showList(Database::SymbolSamples const &symbolSamples)
{
	totalCount = symbolSamples.totalcount;

	auto incSamples = symbolSamples.inclusive.begin();
	auto exSamples = symbolSamples.exclusive.begin();

	auto compareSampleTid = [](std::pair<Database::ThreadID, double> const &si, Database::ThreadID t) { return si.first < t; };

	threads.clear();

	std::vector<Database::ThreadID> allThreads;
	std::vector<Database::ThreadID> const *filterThreads = &database->getFilterThreads();
	if (filterThreads->empty())
	{
		for (auto tn : database->getThreadNames())
		{
			allThreads.push_back(tn.first);
		}
		std::sort(allThreads.begin(), allThreads.end());
		filterThreads = &allThreads;
	}

	for (Database::ThreadID tid : *filterThreads)
	{
		ThreadRow row;

		incSamples = std::lower_bound(incSamples, symbolSamples.inclusive.end(), tid, compareSampleTid);
		if (incSamples != symbolSamples.inclusive.end() && incSamples->first == tid)
		{
			row.inclusive = incSamples->second;
		}
		else
		{
			row.inclusive = 0;
		}

		exSamples = std::lower_bound(exSamples, symbolSamples.exclusive.end(), tid, compareSampleTid);
		if (exSamples != symbolSamples.exclusive.end() && exSamples->first == tid)
		{
			row.exclusive = exSamples->second;
		}
		else
		{
			row.exclusive = 0;
		}

		if (row.inclusive == 0 && row.exclusive == 0)
			continue;

		row.tid = tid;
		row.name = database->getThreadNames().at(tid);

		threads.push_back(row);
	}

	sortThreads();
	fillList();
}

void ThreadSamplesView::reset()
{
	DeleteAllItems();
	totalCount = 0;
	threads.clear();
}

void ThreadSamplesView::sortThreads()
{
	switch (sort_column)
	{
		case COL_TID:
			std::stable_sort(threads.begin(), threads.end(), [](ThreadRow const &t0, ThreadRow const &t1) {
				return t0.tid < t1.tid;
			});
			break;
		case COL_NAME:
			std::stable_sort(threads.begin(), threads.end(), [](ThreadRow const &t0, ThreadRow const &t1) {
				return toLower(t0.name) < toLower(t1.name);
			});
			break;
		case COL_EXCLUSIVE:
		case COL_EXCLUSIVEPCT:
			std::stable_sort(threads.begin(), threads.end(), [](ThreadRow const &t0, ThreadRow const &t1) {
				if (t0.exclusive != t1.exclusive)
					return t0.exclusive < t1.exclusive;
				return t0.inclusive < t1.inclusive;
			});
			break;
		case COL_INCLUSIVE:
		case COL_INCLUSIVEPCT:
			std::stable_sort(threads.begin(), threads.end(), [](ThreadRow const &t0, ThreadRow const &t1) {
				if (t0.inclusive != t1.inclusive)
					return t0.inclusive < t1.inclusive;
				return t0.exclusive < t1.exclusive;
			});
			break;
	}
	if (sort_dir == SORT_DOWN)
		std::reverse(threads.begin(), threads.end());
}

void ThreadSamplesView::fillList()
{
	Freeze();
	DeleteAllItems();

	for (int i = 0; i < (int)threads.size(); ++i)
	{
		long tmp = InsertItem(i, "", -1);
		SetItemData(tmp, i);

		wxString tid = wxString::Format("%d", threads[i].tid);
		SetItem(i, COL_TID, tid);

		SetItem(i, COL_NAME, threads[i].name);

		wxString inclusive = wxString::Format("%0.2fs", threads[i].inclusive);
		wxString exclusive = wxString::Format("%0.2fs", threads[i].exclusive);
		wxString inclusivepercent = wxString::Format("%0.2f%%", threads[i].inclusive * 100.0f / totalCount);
		wxString exclusivepercent = wxString::Format("%0.2f%%", threads[i].exclusive * 100.0f / totalCount);

		SetItem(i, COL_EXCLUSIVE, exclusive);
		SetItem(i, COL_INCLUSIVE, inclusive);
		SetItem(i, COL_EXCLUSIVEPCT, exclusivepercent);
		SetItem(i, COL_INCLUSIVEPCT, inclusivepercent);
	}

	Thaw();
}
