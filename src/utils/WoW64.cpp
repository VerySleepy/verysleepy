#ifdef _WIN64
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "WoW64.h"

Wow64GetThreadContext_t *fn_Wow64GetThreadContext = (Wow64GetThreadContext_t *)GetProcAddress(GetModuleHandle(L"kernel32"),"Wow64GetThreadContext");
Wow64SuspendThread_t *fn_Wow64SuspendThread = (Wow64SuspendThread_t *)GetProcAddress(GetModuleHandle(L"kernel32"),"Wow64SuspendThread");

#endif
