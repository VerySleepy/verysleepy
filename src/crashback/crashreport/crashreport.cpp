#define _CRT_SECURE_NO_DEPRECATE
#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <shlwapi.h>
#include <time.h>
#include "crashreport.h"
#include "resource.h"
#include "..\..\..\thirdparty\ms\dbghelp.h"
#include "..\..\appinfo.h"
#include "..\..\version.h"

#define HOSTNAME	"thecybershadow.net"
#define PORT		80
#define PAGE		"/sleepy/crashback.php"

#define MAX_FILES	64

HINSTANCE hInst;
HWND hDlg;
HWND hProgress = NULL;

DWORD targetProcessId;
CbReport *cbReportData;
int numFiles = 0;
char files[MAX_FILES][MAX_PATH];
char uploadDir[MAX_PATH];

#pragma comment( linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"" )

bool ReadReport()
{
	wchar_t shareName[256];
	swprintf_s( shareName, 256, L"CrashBack_%x", targetProcessId );

	HANDLE hShared = CreateFileMappingW(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // max. object size
		sizeof(CbReport),        // buffer size
		shareName );             // name of mapping object
	if ( !hShared )
		return false;

	cbReportData = (CbReport *)MapViewOfFile( hShared, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(CbReport) );
	if ( !cbReportData )
	{
		CloseHandle( hShared );
		return false;
	}

	return true;
}

bool SendReport()
{
	size_t sizes[MAX_FILES];
	void *srcBuffers[MAX_FILES];

	for (int n=0;n<numFiles;n++)
	{
		// Open the file.
		FILE *file = fopen( files[n], "rb" );
		if ( !file )
			return false;
		fseek( file, 0, SEEK_END );
		sizes[n] = ftell( file );
		fseek( file, 0, SEEK_SET );

		srcBuffers[n] = malloc( sizes[n] );
		if ( !srcBuffers[n] )
			return false;

		// Read all the data in.
		if ( fread( srcBuffers[n], 1, sizes[n], file ) != sizes[n] )
			return false;
		fclose( file );
	}

	// Open a socket.
	SOCKET sock = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	if ( sock == INVALID_SOCKET )
		return false;

	hostent *he = gethostbyname( HOSTNAME );
	if ( !he )
		return false;

	sockaddr_in addr = { 0 };
	memcpy( &addr.sin_addr, he->h_addr_list[0], he->h_length );
	addr.sin_family = AF_INET;
	addr.sin_port = htons( PORT );

	if ( connect(sock, (struct sockaddr *)&addr, sizeof(addr) ) == SOCKET_ERROR )
		return false;

	char header[4096], contentStart[4096], contentEnd[4096];
	char *fileHeaders[MAX_FILES];
	size_t contentSize = 0;
	for (int n=0;n<numFiles;n++)
	{
		char tmp[4096];
		sprintf( tmp,
			"--THAT_WOULD_BE_AN_ECUMENICAL_MATTER\r\n"
			"Content-Disposition: form-data; name=\"file%i\"; filename=\"%s\"\r\n"
			"Content-Type: application/octet-stream\r\n"
			"Content-Transfer-Encoding: binary\r\n"
			"\r\n", n, PathFindFileName( files[n] ) );

		fileHeaders[n] = _strdup( tmp );
		contentSize += strlen( tmp );
		contentSize += sizes[n];
		contentSize += 2; // \r\n
	}

	contentSize += sprintf( contentStart,
		"--THAT_WOULD_BE_AN_ECUMENICAL_MATTER\r\n"
		"Content-Disposition: form-data; name=\"program\"\r\n"
		"\r\n"
		"%s\r\n"
		"--THAT_WOULD_BE_AN_ECUMENICAL_MATTER\r\n"
		"Content-Disposition: form-data; name=\"count\"\r\n"
		"\r\n"
		"%i\r\n",
		cbReportData->programName,
		numFiles );

	contentSize += sprintf( contentEnd,
		"--THAT_WOULD_BE_AN_ECUMENICAL_MATTER--\r\n" );

	sprintf( header,
		"POST %s HTTP/1.0\r\n"
		"Host: %s\r\n"
		"Content-Type: multipart/form-data; boundary=THAT_WOULD_BE_AN_ECUMENICAL_MATTER\r\n"
		"Content-Length: %i\r\n"
		"\r\n",
		PAGE, HOSTNAME, contentSize );

	if ( send( sock, header, (int)strlen( header ), 0 ) == SOCKET_ERROR )
		return false;
	if ( send( sock, contentStart, (int)strlen( contentStart ), 0 ) == SOCKET_ERROR )
		return false;
	for (int n=0;n<numFiles;n++)
	{
		if ( send( sock, fileHeaders[n], (int)strlen( fileHeaders[n] ), 0 ) == SOCKET_ERROR )
			return false;
		if ( send( sock, (char *)srcBuffers[n], (int)sizes[n], 0 ) == SOCKET_ERROR )
			return false;
		if ( send( sock, (char *)"\r\n", 2, 0 ) == SOCKET_ERROR )
			return false;
	}
	if ( send( sock, contentEnd, (int)strlen( contentEnd ), 0 ) == SOCKET_ERROR )
		return false;

	while( true )
	{
		char tmp[1024];
		int n = recv( sock, tmp, 1024, 0 );
		if ( n <= 0 )
			break;
	}

	closesocket( sock );
	return true;
}

void Cleanup()
{
	for (int n=0;n<numFiles;n++)
		DeleteFile( files[n] );
	RemoveDirectory( uploadDir );
}

bool MakeDirectory()
{
	const char *tmpDir = getenv( "TMP" );
	if ( !tmpDir )
		tmpDir = getenv( "TEMP" );
	if ( !tmpDir )
		tmpDir = "C:";

	int suffix = 1;
	while( true )
	{
		sprintf_s( uploadDir, MAX_PATH, "%s\\crashback_%i", tmpDir, suffix++ );
		if ( CreateDirectory( uploadDir, NULL ) )
			break;

		if ( suffix == 1000 )
			return false;
	}

	atexit( Cleanup );
	return true;
}

bool GenerateDump()
{
	HANDLE hTarget = OpenProcess( PROCESS_QUERY_INFORMATION|PROCESS_VM_READ, FALSE, targetProcessId );
	if ( !hTarget )
		return false;

	char dumpFile[MAX_PATH];
	sprintf_s( dumpFile, MAX_PATH, "%s\\crash.dmp", uploadDir );

	HANDLE hFile = CreateFile( dumpFile, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );

	MINIDUMP_EXCEPTION_INFORMATION miniExcep;
	PMINIDUMP_EXCEPTION_INFORMATION pminiExcep;
	if (cbReportData->type) // cbReportData is valid
	{
		miniExcep.ThreadId = cbReportData->threadId;
		miniExcep.ExceptionPointers = cbReportData->exceptionPtrs;
		miniExcep.ClientPointers = TRUE;
		pminiExcep = &miniExcep;
	}
	else
		pminiExcep = NULL;

	bool ok = MiniDumpWriteDump( hTarget, targetProcessId, hFile, MiniDumpNormal,
		pminiExcep, NULL, NULL ) != 0;

	CloseHandle( hFile );
	CloseHandle( hTarget );

	if ( ok )
		strcpy_s( files[numFiles++], MAX_PATH, dumpFile );
	else
		DeleteFile( dumpFile );
	return ok;
}

char *GetOSDesc()
{
	static char buffer[1024];
	char prod[1024]="?", build[1024]="?", csd[1024]="?";

	HKEY key;
	DWORD size, type;
	if ( RegOpenKeyEx( HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_READ, &key ) == ERROR_SUCCESS )
	{
		size = 1024;
		RegQueryValueEx( key, "ProductName", 0, &type, (BYTE *)prod, &size );
		size = 1024;
		RegQueryValueEx( key, "CurrentBuildNumber", 0, &type, (BYTE *)build, &size );
		size = 1024;
		RegQueryValueEx( key, "CSDVersion", 0, &type, (BYTE *)csd, &size );
		RegCloseKey( key );
	}
	sprintf_s( buffer, 1024, "%s / %s / %s", prod, build, csd );
	return buffer;
}

bool SaveInfo()
{
	char fileName[MAX_PATH];
	sprintf_s( fileName, MAX_PATH, "%s\\info.txt", uploadDir );

	FILE *file = fopen( fileName, "w" );
	if ( !file )
		return false;

	// Get system time in UTC format
	char timeStamp[64];
	time_t t;
	struct tm timeinfo;
	time( &t );
	gmtime_s( &timeinfo, &t );
	strftime( timeStamp, 64, "%Y-%m-%d %H:%M:%S", &timeinfo );

	const char *types[] = {
		"CB_CRASH_NONE",
		"CB_CRASH_WIN32_SEH",
		"CB_CRASH_CRT_TERMINATE",
		"CB_CRASH_CRT_UNEXPECTED",
		"CB_CRASH_CRT_PURE_VIRTUAL",
		"CB_CRASH_CRT_INVALID_PARAMETER",
		"CB_CRASH_CRT_NEW",
	};

	OSVERSIONINFO osInfo = { 0 };
	SYSTEM_INFO sysInfo;
	osInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetSystemInfo( &sysInfo );
	GetVersionEx( &osInfo );

	// On XP and higher, use the actually correct version instead.
	typedef VOID WINAPI Fn( LPSYSTEM_INFO lpSystemInfo );
	Fn *fn = (Fn *)GetProcAddress( LoadLibrary( "kernel32.dll" ), "GetNativeSystemInfo" );
	if ( fn )
		fn( &sysInfo );

	fprintf( file, "Crash type: %s\n", types[cbReportData->type] );
	fprintf( file, "Version: %s\n", VERSION );
	fprintf( file, "Command line: %s\n", cbReportData->cmdLine );
	fprintf( file, "Date/time: %s\n", timeStamp );
	fprintf( file, "Operating system: %i.%i / %s\n", osInfo.dwMajorVersion, osInfo.dwMinorVersion, GetOSDesc() );
	switch ( sysInfo.wProcessorArchitecture )
	{
	case PROCESSOR_ARCHITECTURE_AMD64:  fprintf( file, "Processor type: AMD64\n" ); break;
	case PROCESSOR_ARCHITECTURE_IA64:   fprintf( file, "Processor type: IA64\n" ); break;
	case PROCESSOR_ARCHITECTURE_INTEL:  fprintf( file, "Processor type: x86\n" ); break;
	default: fprintf( file, "Processor type: ? (%i)\n", sysInfo.wProcessorArchitecture ); break;
	}
#ifdef _WIN64
	fprintf( file, "Program built for: 64-bit\n" );
#else
	fprintf( file, "Program built for: 32-bit\n" );
#endif

	fclose( file );
	strcpy_s( files[numFiles++], MAX_PATH, fileName );
	return true;
}

bool CreateFiles()
{
	if ( !MakeDirectory() )
		return false;
	if ( !ReadReport() )
		return false;

	// If any of these fail, we still try and send the rest of the report.
	GenerateDump();
	SaveInfo();

	return true;
}

DWORD CALLBACK ReportThread( LPVOID param )
{
	DWORD startTime = GetTickCount();

	SendMessage( hProgress, PBM_SETMARQUEE, (WPARAM)TRUE, (LPARAM)0 );
	SendMessage( hProgress, PBM_STEPIT, 0, 0 );

	// Send it. We don't really care whether it worked or not here.
	SendReport();

	// Make sure the user sees some feedback.
	DWORD endTime = GetTickCount();
	int diff = endTime - startTime;
	int minTime = 2000;
	if ( diff < minTime )
		Sleep( minTime - diff );

	// Exit the dialog (and the program).
	SendMessage( hDlg, WM_COMMAND, IDCANCEL, NULL );
	return 0;
}

LRESULT CALLBACK DlgProc( HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam )
{
	switch(Msg)
	{
	case WM_INITDIALOG:
		{
			hDlg = hWndDlg;
			HWND hCtl = GetDlgItem( hWndDlg, ID_ICON );
			HICON hIcon = LoadIcon( NULL, IDI_ERROR );
			SendMessage( hCtl, STM_SETICON, (WPARAM)hIcon, 0 );
			return TRUE;
		}

	case WM_COMMAND:
		switch( wParam )
		{
		case IDOK:
			if ( !hProgress )
			{
				hProgress = GetDlgItem( hWndDlg, ID_PROGRESS );

				SetDlgItemText( hWndDlg, IDOK, "Sending..." );
				SetDlgItemText( hWndDlg, IDCANCEL, "Cancel" );
				EnableWindow( GetDlgItem( hWndDlg, IDOK ), FALSE );

				CreateThread( NULL, 0, &ReportThread, NULL, 0, NULL );
				return TRUE;
			}
		case IDCANCEL:
			EndDialog( hWndDlg, 0 );
			return TRUE;
		}
		break;
	}

	return FALSE;
}

// A simple hyperlink-esque class.
LRESULT CALLBACK LinkProc( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps;
	char text[256];
	static HFONT hFont = NULL;
	switch(Msg)
	{
	case WM_SETFONT:
		{
			HDC hDC = GetDC( NULL );
			SelectObject( hDC, (HFONT)wParam );
			TEXTMETRIC tm;
			LOGFONT lf;

			GetTextMetrics( hDC, &tm );
			lf.lfHeight = tm.tmHeight;
			lf.lfWidth = 0;
			lf.lfEscapement = 0;
			lf.lfOrientation = 0;
			lf.lfWeight = tm.tmWeight;
			lf.lfItalic = tm.tmItalic;
			lf.lfUnderline = TRUE;
			lf.lfStrikeOut = tm.tmStruckOut;
			lf.lfCharSet = tm.tmCharSet;
			lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
			lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
			lf.lfQuality = DEFAULT_QUALITY;
			lf.lfPitchAndFamily = tm.tmPitchAndFamily;
			GetTextFace( hDC, LF_FACESIZE, lf.lfFaceName );
			ReleaseDC( hWnd, hDC );
			hFont = CreateFontIndirect( &lf );
		}
		return 0;
	case WM_PAINT:
		BeginPaint( hWnd, &ps );
		SetTextColor( ps.hdc, RGB(0,0,255) );
		SetBkColor( ps.hdc, GetSysColor( COLOR_BTNFACE ) );
		GetWindowText( hWnd, text, 256 );
		SelectObject( ps.hdc, hFont );
		TextOut( ps.hdc, 0, 0, text, (int)strlen( text ) );
		EndPaint( hWnd, &ps );
		return 0;
	case WM_LBUTTONDOWN:
		ShellExecute( hWnd, NULL, uploadDir, NULL, NULL, SW_SHOWNORMAL );
		return 0;
	}

	return DefWindowProc( hWnd, Msg, wParam, lParam );
}

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	targetProcessId = strtoul( lpCmdLine, NULL, 16 );
	if ( !targetProcessId )
		return 1;

	hInst = hInstance;
	InitCommonControls();

	// Register the link class we use.
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = &LinkProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor( NULL, MAKEINTRESOURCE(IDC_HAND) );
	wc.hbrBackground = (HBRUSH)( COLOR_BTNFACE+1 );
	wc.lpszClassName = "LINK";
	RegisterClass( &wc );


	WSADATA wsaData;
	int err = WSAStartup( MAKEWORD(2, 2), &wsaData );
	if ( err != 0 )
		return 1;

	if ( !CreateFiles() )
		return 1;

	DialogBox( hInstance, MAKEINTRESOURCE(IDD_CRASH), NULL, reinterpret_cast<DLGPROC>(DlgProc) );

	return 0;
}
