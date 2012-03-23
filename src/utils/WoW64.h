#if defined(_WIN64)

// Microsoft added a couple of functions that does not exist on Windows XP 64.
// The function also needs a newer sdk.
//
// To make things easy I add the missing functions using function pointers.
//
//Johan

#if WINVER < 0x0600 // Already defined on Vista SDKs

#define WOW64_MAXIMUM_SUPPORTED_EXTENSION     512
#define WOW64_SIZE_OF_80387_REGISTERS      80

typedef struct _WOW64_FLOATING_SAVE_AREA {
	DWORD   ControlWord;
	DWORD   StatusWord;
	DWORD   TagWord;
	DWORD   ErrorOffset;
	DWORD   ErrorSelector;
	DWORD   DataOffset;
	DWORD   DataSelector;
	BYTE    RegisterArea[WOW64_SIZE_OF_80387_REGISTERS];
	DWORD   Cr0NpxState;
} WOW64_FLOATING_SAVE_AREA;

typedef struct _WOW64_CONTEXT {

	//
	// The flags values within this flag control the contents of
	// a CONTEXT record.
	//
	// If the context record is used as an input parameter, then
	// for each portion of the context record controlled by a flag
	// whose value is set, it is assumed that that portion of the
	// context record contains valid context. If the context record
	// is being used to modify a threads context, then only that
	// portion of the threads context will be modified.
	//
	// If the context record is used as an IN OUT parameter to capture
	// the context of a thread, then only those portions of the thread's
	// context corresponding to set flags will be returned.
	//
	// The context record is never used as an OUT only parameter.
	//

	DWORD ContextFlags;

	//
	// This section is specified/returned if CONTEXT_DEBUG_REGISTERS is
	// set in ContextFlags.  Note that CONTEXT_DEBUG_REGISTERS is NOT
	// included in CONTEXT_FULL.
	//

	DWORD   Dr0;
	DWORD   Dr1;
	DWORD   Dr2;
	DWORD   Dr3;
	DWORD   Dr6;
	DWORD   Dr7;

	//
	// This section is specified/returned if the
	// ContextFlags word contians the flag CONTEXT_FLOATING_POINT.
	//

	WOW64_FLOATING_SAVE_AREA FloatSave;

	//
	// This section is specified/returned if the
	// ContextFlags word contians the flag CONTEXT_SEGMENTS.
	//

	DWORD   SegGs;
	DWORD   SegFs;
	DWORD   SegEs;
	DWORD   SegDs;

	//
	// This section is specified/returned if the
	// ContextFlags word contians the flag CONTEXT_INTEGER.
	//

	DWORD   Edi;
	DWORD   Esi;
	DWORD   Ebx;
	DWORD   Edx;
	DWORD   Ecx;
	DWORD   Eax;

	//
	// This section is specified/returned if the
	// ContextFlags word contians the flag CONTEXT_CONTROL.
	//

	DWORD   Ebp;
	DWORD   Eip;
	DWORD   SegCs;              // MUST BE SANITIZED
	DWORD   EFlags;             // MUST BE SANITIZED
	DWORD   Esp;
	DWORD   SegSs;

	//
	// This section is specified/returned if the ContextFlags word
	// contains the flag CONTEXT_EXTENDED_REGISTERS.
	// The format and contexts are processor specific
	//

	BYTE    ExtendedRegisters[WOW64_MAXIMUM_SUPPORTED_EXTENSION];

} WOW64_CONTEXT;

typedef WOW64_CONTEXT *PWOW64_CONTEXT;

#define WOW64_CONTEXT_i386      0x00010000    // this assumes that i386 and
#define WOW64_CONTEXT_i486      0x00010000    // i486 have identical context records

#define WOW64_CONTEXT_CONTROL               (WOW64_CONTEXT_i386 | 0x00000001L) // SS:SP, CS:IP, FLAGS, BP
#define WOW64_CONTEXT_INTEGER               (WOW64_CONTEXT_i386 | 0x00000002L) // AX, BX, CX, DX, SI, DI
#define WOW64_CONTEXT_SEGMENTS              (WOW64_CONTEXT_i386 | 0x00000004L) // DS, ES, FS, GS
#define WOW64_CONTEXT_FLOATING_POINT        (WOW64_CONTEXT_i386 | 0x00000008L) // 387 state
#define WOW64_CONTEXT_DEBUG_REGISTERS       (WOW64_CONTEXT_i386 | 0x00000010L) // DB 0-3,6,7
#define WOW64_CONTEXT_EXTENDED_REGISTERS    (WOW64_CONTEXT_i386 | 0x00000020L) // cpu specific extensions

#define WOW64_CONTEXT_FULL      (WOW64_CONTEXT_CONTROL | WOW64_CONTEXT_INTEGER | WOW64_CONTEXT_SEGMENTS)

#define WOW64_CONTEXT_ALL       (WOW64_CONTEXT_CONTROL | WOW64_CONTEXT_INTEGER | WOW64_CONTEXT_SEGMENTS | \
	WOW64_CONTEXT_FLOATING_POINT | WOW64_CONTEXT_DEBUG_REGISTERS | \
	WOW64_CONTEXT_EXTENDED_REGISTERS)

#define WOW64_CONTEXT_XSTATE                (WOW64_CONTEXT_i386 | 0x00000040L)

#endif // WINVER

typedef BOOL WINAPI Wow64GetThreadContext_t(__in     HANDLE hThread,__inout  PWOW64_CONTEXT lpContext);
typedef DWORD WINAPI Wow64SuspendThread_t(__in  HANDLE hThread);

extern Wow64GetThreadContext_t *fn_Wow64GetThreadContext;
extern Wow64SuspendThread_t *fn_Wow64SuspendThread;

#endif
