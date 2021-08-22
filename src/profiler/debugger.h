/*=====================================================================
symbolinfo.h
------------

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

http://www.gnu.org/copyleft/gpl.html..
=====================================================================*/
#ifndef __DEBUGGER_H_666_
#define __DEBUGGER_H_666_

#include <windows.h>
#include <functional>
#include <map>

class Debugger
{
public:
	enum NotifyEvent
	{
		NOTIFY_NEW_THREAD,
	};

	struct NotifyData
	{
		NotifyEvent eventType;
		HANDLE threadHandle;
		DWORD threadId;
	};

	Debugger(DWORD processId);
	~Debugger();

	bool attach(std::function<void(NotifyData const &notification)> notifyFunc);
	void detach();

	void update();
protected:
	DWORD processId;
	HANDLE processHandle;
	std::function<void(NotifyData const &notification)> notifyFunc;
	std::map<DWORD, bool> knownThreads;
	bool debuggingActive;
	bool attached;

	void notifyNewThread(DWORD threadId, HANDLE threadHandle);

	void finishAttaching();

	void updateFromSnapshot();
	void updateDebugging();

	void deactivateDebugging();

};

#endif // __DEBUGGER_H_666_
