/*=====================================================================
osutils.h
----------

Copyright (C) Dan Engelbrecht
Copyright (C) 2015 Ashod Nakashian

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

#ifndef __OSUTILS_H__
#define __OSUTILS_H__

#include <windows.h>

void InitSysInfo();
int GetCPUCores();
int GetCoresForProcess(HANDLE process);
void EnableDebugPrivilege();
bool Is64BitProcess(HANDLE hProcess);

bool CanProfileProcess(HANDLE hProcess);

#endif // __OSUTILS_H__
