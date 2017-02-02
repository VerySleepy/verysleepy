#include <windows.h>
#include <new.h>
#include <intrin.h>
#include <stdio.h>
#include "crashreport.h"

HANDLE cbLock = NULL;
CbReport *cbReportData = NULL;
wchar_t cbShareName[256];
wchar_t cbReportExePath[MAX_PATH] = L"";
wchar_t cbReportExeDir[MAX_PATH] = L"";
wchar_t cbReportCmdLine[1024] = L"";
char cbProgName[256] = "";
char cbCmdLine[1024] = "";
EXCEPTION_POINTERS cbTmpExceptionPtrs;
EXCEPTION_RECORD cbTmpExceptionRecord;
CONTEXT cbTmpContext;

void cbGetExceptionPointers()
{
	CONTEXT context;
	memset( &context, 0, sizeof(CONTEXT) );

#ifdef _X86_
	__asm {
		mov dword ptr [context.Eax], eax
			mov dword ptr [context.Ecx], ecx
			mov dword ptr [context.Edx], edx
			mov dword ptr [context.Ebx], ebx
			mov dword ptr [context.Esi], esi
			mov dword ptr [context.Edi], edi
			mov word ptr [context.SegSs], ss
			mov word ptr [context.SegCs], cs
			mov word ptr [context.SegDs], ds
			mov word ptr [context.SegEs], es
			mov word ptr [context.SegFs], fs
			mov word ptr [context.SegGs], gs
			pushfd
			pop [context.EFlags]
	}

	context.ContextFlags = CONTEXT_CONTROL;
	context.Eip = (ULONG)_ReturnAddress();
	context.Esp = (ULONG)_AddressOfReturnAddress();
	context.Ebp = *((ULONG *)_AddressOfReturnAddress()-1);

#elif defined (_IA64_) || defined (_AMD64_)
	RtlCaptureContext( &context );
#else
#error
#endif

	memcpy( &cbTmpContext, &context, sizeof(CONTEXT) );

	ZeroMemory( &cbTmpExceptionRecord, sizeof(EXCEPTION_RECORD) );
	cbTmpExceptionRecord.ExceptionCode = 0;
	cbTmpExceptionRecord.ExceptionAddress = _ReturnAddress();

	cbReportData->exceptionPtrs = &cbTmpExceptionPtrs;
	cbTmpExceptionPtrs.ExceptionRecord = &cbTmpExceptionRecord;
	cbTmpExceptionPtrs.ContextRecord = &cbTmpContext;
}

void cbReport( CbCrashType type, EXCEPTION_POINTERS *excep )
{
	// Crash handler.
	// We try to minimize the amount of code in here,
	// as the application may/will be in an unstable state.

	// If we have exception data, use it, otherwise make our own.
	if ( excep )
	{
		cbReportData->exceptionPtrs = excep;
	} else {
		cbGetExceptionPointers();
		cbReportData->exceptionPtrs = &cbTmpExceptionPtrs;
	}

	// Get some info.
	cbReportData->type = type;
	cbReportData->threadId = GetCurrentThreadId();
	strcpy_s( cbReportData->programName, 32, cbProgName );
	strcpy_s( cbReportData->cmdLine, 1024, cbCmdLine );

	// Launch the crash reporter. If it fails, never mind.
	STARTUPINFO si = { 0 };
	PROCESS_INFORMATION pi = { 0 };
	si.cb = sizeof(si);
	if ( CreateProcess( cbReportExePath, cbReportCmdLine, NULL, NULL, FALSE, 0, NULL, cbReportExeDir, &si, &pi ) )
	{
		WaitForSingleObject( pi.hProcess, INFINITE );
		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
	}
}

LONG CALLBACK cbExceptionHandler( EXCEPTION_POINTERS *excep )
{
	WaitForSingleObject( cbLock, INFINITE );
	cbReport( CB_CRASH_WIN32_SEH, excep );
	TerminateProcess( GetCurrentProcess(), 1 );
	return EXCEPTION_EXECUTE_HANDLER;
}

void cbTerminateHandler()
{
	WaitForSingleObject( cbLock, INFINITE );
	cbReport( CB_CRASH_CRT_TERMINATE, NULL );
	TerminateProcess( GetCurrentProcess(), 1 );
}

void cbUnexpectedHandler()
{
	WaitForSingleObject( cbLock, INFINITE );
	cbReport( CB_CRASH_CRT_UNEXPECTED, NULL );
	TerminateProcess( GetCurrentProcess(), 1 );
}

void cbPureCallHandler()
{
	WaitForSingleObject( cbLock, INFINITE );
	cbReport( CB_CRASH_CRT_PURE_VIRTUAL, NULL );
	TerminateProcess( GetCurrentProcess(), 1 );
}

void cbInvalidParameterHandler(
							   const wchar_t *expression,
							   const wchar_t *function,
							   const wchar_t *file,
							   unsigned int line,
							   uintptr_t pReserved )
{
	WaitForSingleObject( cbLock, INFINITE );
	cbReport( CB_CRASH_CRT_INVALID_PARAMETER, NULL );
	TerminateProcess( GetCurrentProcess(), 1 );
}

int cbNewHandler( size_t size )
{
	WaitForSingleObject( cbLock, INFINITE );
	cbReport( CB_CRASH_CRT_NEW, NULL );
	TerminateProcess( GetCurrentProcess(), 1 );
	return 0;
}

void cbGetProgramName()
{
	char tmp[256];
	if ( !GetModuleFileNameA( NULL, tmp, 256 ) )
		strcpy_s( tmp, 256, "unknown" );
	tmp[255] = 0; // ensure it's terminated, just in case

	char *modName = strrchr( tmp, '\\' );
	if ( modName )
		strcpy_s( cbProgName, 256, modName + 1 );
	else
		strcpy_s( cbProgName, 256, tmp );

	// Strip out funny characters, just in case.
	for (int n=0;n<256;n++)
	{
		char &c = cbProgName[n];
		if ( c == 0 )
			break;

		if ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) || ( c >= '0' && c <= '9' ) )
		{
			// ok
		} else {
			c = '_'; // bad
		}
	}
}

void cbGetCmdLine()
{
	strcpy_s( cbCmdLine, 1024, GetCommandLineA() );
}

extern "C" void cbStartup()
{
	cbLock = CreateMutex( NULL, FALSE, NULL );
	cbReportData = NULL;

	swprintf_s( cbShareName, 256, L"CrashBack_%x", GetCurrentProcessId() );

	GetModuleFileName( NULL, cbReportExePath, MAX_PATH );
	wcscpy_s( cbReportExeDir, MAX_PATH, cbReportExePath );
	wchar_t *p = wcsrchr( cbReportExeDir, '\\' );
	if ( p )
		*p = 0;

	wcscpy_s( cbReportExePath, MAX_PATH, cbReportExeDir );
	wcscat_s( cbReportExePath, MAX_PATH, L"\\" );
	wcscat_s( cbReportExePath, MAX_PATH, L"crashreport.exe" );

	// Check that crashreport.exe exists in the app's directory.
	if ( GetFileAttributes( cbReportExePath ) == INVALID_FILE_ATTRIBUTES )
		return;

	swprintf_s( cbReportCmdLine, 1024, L"\"%s\" 0x%x", cbReportExePath, GetCurrentProcessId() );

	cbGetProgramName();
	cbGetCmdLine();

	// Set up shared memory to communicate with the report handler EXE.
	HANDLE hShared = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // max. object size
		sizeof(CbReport),        // buffer size
		cbShareName );           // name of mapping object
	if ( !hShared )
		return;

	cbReportData = (CbReport *)MapViewOfFile( hShared, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(CbReport) );
	if ( !cbReportData )
	{
		CloseHandle( hShared );
		return;
	}

	// Register the handlers.
	SetUnhandledExceptionFilter( &cbExceptionHandler );
	_set_error_mode( _OUT_TO_STDERR );
	_set_purecall_handler( cbPureCallHandler );
	_set_new_mode( 1 ); // malloc calls the new handler on failure
	_set_new_handler( cbNewHandler );
	_set_invalid_parameter_handler( cbInvalidParameterHandler );
	_set_abort_behavior( _CALL_REPORTFAULT, _CALL_REPORTFAULT );
}
