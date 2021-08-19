#ifndef __CRASHREPORT_H__
#define __CRASHREPORT_H__

/// Reason of the abnormal termination.
/// Update the types array in crashreport.cpp / SaveInfo()
/// when adding new members.
typedef enum
{
	CB_CRASH_NONE, // CbReport is invalid
	CB_CRASH_WIN32_SEH,
	CB_CRASH_CRT_TERMINATE,
	CB_CRASH_CRT_UNEXPECTED,
	CB_CRASH_CRT_PURE_VIRTUAL,
	CB_CRASH_CRT_INVALID_PARAMETER,
	CB_CRASH_CRT_NEW,
} CbCrashType;

/// The structure shared between sleepy.exe and crashback.exe
/// using a shared memory object.
typedef struct
{
	CbCrashType type;
	char programName[32];
	char cmdLine[1024];
	DWORD threadId;
	EXCEPTION_POINTERS *exceptionPtrs;
} CbReport;

#endif // __CRASHREPORT_H__
