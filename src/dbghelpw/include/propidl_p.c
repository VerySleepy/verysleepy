

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Nov 07 19:54:07 2011
 */
/* Compiler settings for propidl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "propidl.h"

#define TYPE_FORMAT_STRING_SIZE   2529                              
#define PROC_FORMAT_STRING_SIZE   883                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _propidl_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } propidl_MIDL_TYPE_FORMAT_STRING;

typedef struct _propidl_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } propidl_MIDL_PROC_FORMAT_STRING;

typedef struct _propidl_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } propidl_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const propidl_MIDL_TYPE_FORMAT_STRING propidl__MIDL_TypeFormatString;
extern const propidl_MIDL_PROC_FORMAT_STRING propidl__MIDL_ProcFormatString;
extern const propidl_MIDL_EXPR_FORMAT_STRING propidl__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPropertyStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPropertyStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPropertySetStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPropertySetStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumSTATPROPSTG_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumSTATPROPSTG_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumSTATPROPSTG_RemoteNext_Proxy( 
    IEnumSTATPROPSTG * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ STATPROPSTG *rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &propidl__MIDL_ProcFormatString.Format[684],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumSTATPROPSTG_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumSTATPROPSTG *This;
        ULONG celt;
        STATPROPSTG *rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumSTATPROPSTG_Next_Stub(
                                     (IEnumSTATPROPSTG *) pParamStruct->This,
                                     pParamStruct->celt,
                                     pParamStruct->rgelt,
                                     pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumSTATPROPSETSTG_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumSTATPROPSETSTG_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumSTATPROPSETSTG_RemoteNext_Proxy( 
    IEnumSTATPROPSETSTG * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ STATPROPSETSTG *rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &propidl__MIDL_ProcFormatString.Format[834],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumSTATPROPSETSTG_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumSTATPROPSETSTG *This;
        ULONG celt;
        STATPROPSETSTG *rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumSTATPROPSETSTG_Next_Stub(
                                        (IEnumSTATPROPSETSTG *) pParamStruct->This,
                                        pParamStruct->celt,
                                        pParamStruct->rgelt,
                                        pParamStruct->pceltFetched);
    
}


extern const EXPR_EVAL ExprEvalRoutines[];
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const propidl_MIDL_PROC_FORMAT_STRING propidl__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure ReadMultiple */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 16 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 18 */	NdrFcShort( 0xd8 ),	/* 216 */
/* 20 */	NdrFcShort( 0x2 ),	/* 2 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cpspec */

/* 24 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgpspec */

/* 30 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter rgpropvar */

/* 36 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x8c6 ),	/* Type Offset=2246 */

	/* Return value */

/* 42 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 44 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 46 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteMultiple */

/* 48 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 50 */	NdrFcLong( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x4 ),	/* 4 */
/* 56 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 58 */	NdrFcShort( 0x10 ),	/* 16 */
/* 60 */	NdrFcShort( 0x8 ),	/* 8 */
/* 62 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 64 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x106 ),	/* 262 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cpspec */

/* 72 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 74 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgpspec */

/* 78 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Parameter rgpropvar */

/* 84 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 86 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 88 */	NdrFcShort( 0x8c6 ),	/* Type Offset=2246 */

	/* Parameter propidNameFirst */

/* 90 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 92 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 94 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteMultiple */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x5 ),	/* 5 */
/* 110 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 112 */	NdrFcShort( 0x8 ),	/* 8 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 118 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x3 ),	/* 3 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cpspec */

/* 126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgpspec */

/* 132 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 136 */	NdrFcShort( 0x30 ),	/* Type Offset=48 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ReadPropertyNames */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x6 ),	/* 6 */
/* 152 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 160 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 162 */	NdrFcShort( 0x1 ),	/* 1 */
/* 164 */	NdrFcShort( 0x1 ),	/* 1 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cpropid */

/* 168 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgpropid */

/* 174 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	NdrFcShort( 0x8dc ),	/* Type Offset=2268 */

	/* Parameter rglpwstrName */

/* 180 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 184 */	NdrFcShort( 0x8e8 ),	/* Type Offset=2280 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WritePropertyNames */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x7 ),	/* 7 */
/* 200 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 208 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x2 ),	/* 2 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cpropid */

/* 216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgpropid */

/* 222 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	NdrFcShort( 0x8dc ),	/* Type Offset=2268 */

	/* Parameter rglpwstrName */

/* 228 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 232 */	NdrFcShort( 0x908 ),	/* Type Offset=2312 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeletePropertyNames */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 256 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x1 ),	/* 1 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cpropid */

/* 264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgpropid */

/* 270 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 274 */	NdrFcShort( 0x8dc ),	/* Type Offset=2268 */

	/* Return value */

/* 276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x9 ),	/* 9 */
/* 290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 296 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 298 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfCommitFlags */

/* 306 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Revert */

/* 318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0xa ),	/* 10 */
/* 326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 332 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 334 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 344 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Enum */

/* 348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0xb ),	/* 11 */
/* 356 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 362 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 364 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 372 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 374 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 376 */	NdrFcShort( 0x928 ),	/* Type Offset=2344 */

	/* Return value */

/* 378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 380 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTimes */

/* 384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0xc ),	/* 12 */
/* 392 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 394 */	NdrFcShort( 0x84 ),	/* 132 */
/* 396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 398 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 400 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pctime */

/* 408 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 412 */	NdrFcShort( 0x272 ),	/* Type Offset=626 */

	/* Parameter patime */

/* 414 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 418 */	NdrFcShort( 0x272 ),	/* Type Offset=626 */

	/* Parameter pmtime */

/* 420 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 424 */	NdrFcShort( 0x272 ),	/* Type Offset=626 */

	/* Return value */

/* 426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 428 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetClass */

/* 432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0xd ),	/* 13 */
/* 440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 442 */	NdrFcShort( 0x44 ),	/* 68 */
/* 444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 446 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 448 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter clsid */

/* 456 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 458 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 460 */	NdrFcShort( 0x284 ),	/* Type Offset=644 */

	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stat */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0xe ),	/* 14 */
/* 476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0xdc ),	/* 220 */
/* 482 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 484 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter statpsstg */

/* 492 */	NdrFcShort( 0x112 ),	/* Flags:  must free, out, simple ref, */
/* 494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 496 */	NdrFcShort( 0x94a ),	/* Type Offset=2378 */

	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x3 ),	/* 3 */
/* 512 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 514 */	NdrFcShort( 0x98 ),	/* 152 */
/* 516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 518 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 520 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rfmtid */

/* 528 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 530 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 532 */	NdrFcShort( 0x284 ),	/* Type Offset=644 */

	/* Parameter pclsid */

/* 534 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 536 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 538 */	NdrFcShort( 0x966 ),	/* Type Offset=2406 */

	/* Parameter grfFlags */

/* 540 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 542 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter grfMode */

/* 546 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 548 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppprstg */

/* 552 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 554 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 556 */	NdrFcShort( 0x96a ),	/* Type Offset=2410 */

	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 560 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Open */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x4 ),	/* 4 */
/* 572 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 574 */	NdrFcShort( 0x4c ),	/* 76 */
/* 576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 578 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 580 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rfmtid */

/* 588 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 592 */	NdrFcShort( 0x284 ),	/* Type Offset=644 */

	/* Parameter grfMode */

/* 594 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 596 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppprstg */

/* 600 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 604 */	NdrFcShort( 0x96a ),	/* Type Offset=2410 */

	/* Return value */

/* 606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 608 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x5 ),	/* 5 */
/* 620 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 622 */	NdrFcShort( 0x44 ),	/* 68 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 628 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rfmtid */

/* 636 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 638 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 640 */	NdrFcShort( 0x284 ),	/* Type Offset=644 */

	/* Return value */

/* 642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 644 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */


	/* Procedure Enum */

/* 648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x6 ),	/* 6 */
/* 656 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 662 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 664 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */


	/* Parameter ppenum */

/* 672 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 674 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 676 */	NdrFcShort( 0x980 ),	/* Type Offset=2432 */

	/* Return value */


	/* Return value */

/* 678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 680 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x3 ),	/* 3 */
/* 692 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 696 */	NdrFcShort( 0x24 ),	/* 36 */
/* 698 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 700 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 702 */	NdrFcShort( 0x1 ),	/* 1 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 710 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 714 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 716 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 718 */	NdrFcShort( 0x9ac ),	/* Type Offset=2476 */

	/* Parameter pceltFetched */

/* 720 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 722 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 728 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */


	/* Procedure Skip */

/* 732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x4 ),	/* 4 */
/* 740 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 742 */	NdrFcShort( 0x8 ),	/* 8 */
/* 744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 746 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 748 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */


	/* Parameter celt */

/* 756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 758 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */


	/* Procedure Reset */

/* 768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x5 ),	/* 5 */
/* 776 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 782 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 784 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x6 ),	/* 6 */
/* 806 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 814 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 822 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 824 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 826 */	NdrFcShort( 0x928 ),	/* Type Offset=2344 */

	/* Return value */

/* 828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x3 ),	/* 3 */
/* 842 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 846 */	NdrFcShort( 0x24 ),	/* 36 */
/* 848 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 850 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 852 */	NdrFcShort( 0x1 ),	/* 1 */
/* 854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 858 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 864 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 868 */	NdrFcShort( 0x9ca ),	/* Type Offset=2506 */

	/* Parameter pceltFetched */

/* 870 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 878 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const propidl_MIDL_TYPE_FORMAT_STRING propidl__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/*  4 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/*  6 */	NdrFcShort( 0xfffc ),	/* -4 */
/*  8 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 10 */	NdrFcShort( 0x2 ),	/* Offset= 2 (12) */
/* 12 */	NdrFcShort( 0x4 ),	/* 4 */
/* 14 */	NdrFcShort( 0x2 ),	/* 2 */
/* 16 */	NdrFcLong( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 22 */	NdrFcLong( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x4 ),	/* Offset= 4 (30) */
/* 28 */	NdrFcShort( 0x0 ),	/* Offset= 0 (28) */
/* 30 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 32 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 34 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 36 */	NdrFcShort( 0x8 ),	/* 8 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x0 ),	/* Offset= 0 (40) */
/* 42 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 44 */	0x0,		/* 0 */
			NdrFcShort( 0xffd5 ),	/* Offset= -43 (2) */
			0x5b,		/* FC_END */
/* 48 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 54 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 56 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 58 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 62 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 64 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 66 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (34) */
/* 68 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 70 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x7,		/* FC_USHORT */
/* 72 */	0x0,		/* Corr desc:  field,  */
			0x59,		/* FC_CALLBACK */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 78 */	NdrFcShort( 0x2 ),	/* Offset= 2 (80) */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	NdrFcShort( 0x59 ),	/* 89 */
/* 84 */	NdrFcLong( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* Offset= 0 (88) */
/* 90 */	NdrFcLong( 0x1 ),	/* 1 */
/* 94 */	NdrFcShort( 0x0 ),	/* Offset= 0 (94) */
/* 96 */	NdrFcLong( 0x10 ),	/* 16 */
/* 100 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 102 */	NdrFcLong( 0x11 ),	/* 17 */
/* 106 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 108 */	NdrFcLong( 0x2 ),	/* 2 */
/* 112 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 114 */	NdrFcLong( 0x12 ),	/* 18 */
/* 118 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 120 */	NdrFcLong( 0xb ),	/* 11 */
/* 124 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 126 */	NdrFcLong( 0x3 ),	/* 3 */
/* 130 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 132 */	NdrFcLong( 0x13 ),	/* 19 */
/* 136 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 138 */	NdrFcLong( 0x4 ),	/* 4 */
/* 142 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 144 */	NdrFcLong( 0xa ),	/* 10 */
/* 148 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 150 */	NdrFcLong( 0x14 ),	/* 20 */
/* 154 */	NdrFcShort( 0x1d2 ),	/* Offset= 466 (620) */
/* 156 */	NdrFcLong( 0x15 ),	/* 21 */
/* 160 */	NdrFcShort( 0x1cc ),	/* Offset= 460 (620) */
/* 162 */	NdrFcLong( 0x5 ),	/* 5 */
/* 166 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 168 */	NdrFcLong( 0x6 ),	/* 6 */
/* 172 */	NdrFcShort( 0x1c0 ),	/* Offset= 448 (620) */
/* 174 */	NdrFcLong( 0x7 ),	/* 7 */
/* 178 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 180 */	NdrFcLong( 0x40 ),	/* 64 */
/* 184 */	NdrFcShort( 0x1ba ),	/* Offset= 442 (626) */
/* 186 */	NdrFcLong( 0x48 ),	/* 72 */
/* 190 */	NdrFcShort( 0x1bc ),	/* Offset= 444 (634) */
/* 192 */	NdrFcLong( 0x41 ),	/* 65 */
/* 196 */	NdrFcShort( 0x1d8 ),	/* Offset= 472 (668) */
/* 198 */	NdrFcLong( 0x46 ),	/* 70 */
/* 202 */	NdrFcShort( 0x1d2 ),	/* Offset= 466 (668) */
/* 204 */	NdrFcLong( 0x47 ),	/* 71 */
/* 208 */	NdrFcShort( 0x1e0 ),	/* Offset= 480 (688) */
/* 210 */	NdrFcLong( 0x42 ),	/* 66 */
/* 214 */	NdrFcShort( 0x200 ),	/* Offset= 512 (726) */
/* 216 */	NdrFcLong( 0x44 ),	/* 68 */
/* 220 */	NdrFcShort( 0x1fa ),	/* Offset= 506 (726) */
/* 222 */	NdrFcLong( 0x43 ),	/* 67 */
/* 226 */	NdrFcShort( 0x206 ),	/* Offset= 518 (744) */
/* 228 */	NdrFcLong( 0x45 ),	/* 69 */
/* 232 */	NdrFcShort( 0x200 ),	/* Offset= 512 (744) */
/* 234 */	NdrFcLong( 0x8 ),	/* 8 */
/* 238 */	NdrFcShort( 0x226 ),	/* Offset= 550 (788) */
/* 240 */	NdrFcLong( 0xfff ),	/* 4095 */
/* 244 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (668) */
/* 246 */	NdrFcLong( 0x1e ),	/* 30 */
/* 250 */	NdrFcShort( 0x224 ),	/* Offset= 548 (798) */
/* 252 */	NdrFcLong( 0x1f ),	/* 31 */
/* 256 */	NdrFcShort( 0x222 ),	/* Offset= 546 (802) */
/* 258 */	NdrFcLong( 0x1011 ),	/* 4113 */
/* 262 */	NdrFcShort( 0x196 ),	/* Offset= 406 (668) */
/* 264 */	NdrFcLong( 0x1002 ),	/* 4098 */
/* 268 */	NdrFcShort( 0x226 ),	/* Offset= 550 (818) */
/* 270 */	NdrFcLong( 0x1012 ),	/* 4114 */
/* 274 */	NdrFcShort( 0x220 ),	/* Offset= 544 (818) */
/* 276 */	NdrFcLong( 0x100b ),	/* 4107 */
/* 280 */	NdrFcShort( 0x21a ),	/* Offset= 538 (818) */
/* 282 */	NdrFcLong( 0x1003 ),	/* 4099 */
/* 286 */	NdrFcShort( 0x234 ),	/* Offset= 564 (850) */
/* 288 */	NdrFcLong( 0x1013 ),	/* 4115 */
/* 292 */	NdrFcShort( 0x22e ),	/* Offset= 558 (850) */
/* 294 */	NdrFcLong( 0x1004 ),	/* 4100 */
/* 298 */	NdrFcShort( 0x248 ),	/* Offset= 584 (882) */
/* 300 */	NdrFcLong( 0x100a ),	/* 4106 */
/* 304 */	NdrFcShort( 0x222 ),	/* Offset= 546 (850) */
/* 306 */	NdrFcLong( 0x1014 ),	/* 4116 */
/* 310 */	NdrFcShort( 0x260 ),	/* Offset= 608 (918) */
/* 312 */	NdrFcLong( 0x1015 ),	/* 4117 */
/* 316 */	NdrFcShort( 0x25a ),	/* Offset= 602 (918) */
/* 318 */	NdrFcLong( 0x1005 ),	/* 4101 */
/* 322 */	NdrFcShort( 0x274 ),	/* Offset= 628 (950) */
/* 324 */	NdrFcLong( 0x1006 ),	/* 4102 */
/* 328 */	NdrFcShort( 0x24e ),	/* Offset= 590 (918) */
/* 330 */	NdrFcLong( 0x1007 ),	/* 4103 */
/* 334 */	NdrFcShort( 0x268 ),	/* Offset= 616 (950) */
/* 336 */	NdrFcLong( 0x1040 ),	/* 4160 */
/* 340 */	NdrFcShort( 0x286 ),	/* Offset= 646 (986) */
/* 342 */	NdrFcLong( 0x1048 ),	/* 4168 */
/* 346 */	NdrFcShort( 0x2a4 ),	/* Offset= 676 (1022) */
/* 348 */	NdrFcLong( 0x1047 ),	/* 4167 */
/* 352 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (1076) */
/* 354 */	NdrFcLong( 0x1008 ),	/* 4104 */
/* 358 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (1118) */
/* 360 */	NdrFcLong( 0x1fff ),	/* 8191 */
/* 364 */	NdrFcShort( 0x328 ),	/* Offset= 808 (1172) */
/* 366 */	NdrFcLong( 0x101e ),	/* 4126 */
/* 370 */	NdrFcShort( 0x356 ),	/* Offset= 854 (1224) */
/* 372 */	NdrFcLong( 0x101f ),	/* 4127 */
/* 376 */	NdrFcShort( 0x384 ),	/* Offset= 900 (1276) */
/* 378 */	NdrFcLong( 0x100c ),	/* 4108 */
/* 382 */	NdrFcShort( 0x3a8 ),	/* Offset= 936 (1318) */
/* 384 */	NdrFcLong( 0x2010 ),	/* 8208 */
/* 388 */	NdrFcShort( 0x71a ),	/* Offset= 1818 (2206) */
/* 390 */	NdrFcLong( 0x2011 ),	/* 8209 */
/* 394 */	NdrFcShort( 0x714 ),	/* Offset= 1812 (2206) */
/* 396 */	NdrFcLong( 0x2002 ),	/* 8194 */
/* 400 */	NdrFcShort( 0x70e ),	/* Offset= 1806 (2206) */
/* 402 */	NdrFcLong( 0x2012 ),	/* 8210 */
/* 406 */	NdrFcShort( 0x708 ),	/* Offset= 1800 (2206) */
/* 408 */	NdrFcLong( 0x2003 ),	/* 8195 */
/* 412 */	NdrFcShort( 0x702 ),	/* Offset= 1794 (2206) */
/* 414 */	NdrFcLong( 0x2013 ),	/* 8211 */
/* 418 */	NdrFcShort( 0x6fc ),	/* Offset= 1788 (2206) */
/* 420 */	NdrFcLong( 0x2016 ),	/* 8214 */
/* 424 */	NdrFcShort( 0x6f6 ),	/* Offset= 1782 (2206) */
/* 426 */	NdrFcLong( 0x2017 ),	/* 8215 */
/* 430 */	NdrFcShort( 0x6f0 ),	/* Offset= 1776 (2206) */
/* 432 */	NdrFcLong( 0x2004 ),	/* 8196 */
/* 436 */	NdrFcShort( 0x6ea ),	/* Offset= 1770 (2206) */
/* 438 */	NdrFcLong( 0x2005 ),	/* 8197 */
/* 442 */	NdrFcShort( 0x6e4 ),	/* Offset= 1764 (2206) */
/* 444 */	NdrFcLong( 0x2006 ),	/* 8198 */
/* 448 */	NdrFcShort( 0x6de ),	/* Offset= 1758 (2206) */
/* 450 */	NdrFcLong( 0x2007 ),	/* 8199 */
/* 454 */	NdrFcShort( 0x6d8 ),	/* Offset= 1752 (2206) */
/* 456 */	NdrFcLong( 0x2008 ),	/* 8200 */
/* 460 */	NdrFcShort( 0x6d2 ),	/* Offset= 1746 (2206) */
/* 462 */	NdrFcLong( 0x200b ),	/* 8203 */
/* 466 */	NdrFcShort( 0x6cc ),	/* Offset= 1740 (2206) */
/* 468 */	NdrFcLong( 0x200e ),	/* 8206 */
/* 472 */	NdrFcShort( 0x6c6 ),	/* Offset= 1734 (2206) */
/* 474 */	NdrFcLong( 0x2009 ),	/* 8201 */
/* 478 */	NdrFcShort( 0x6c0 ),	/* Offset= 1728 (2206) */
/* 480 */	NdrFcLong( 0x200d ),	/* 8205 */
/* 484 */	NdrFcShort( 0x6ba ),	/* Offset= 1722 (2206) */
/* 486 */	NdrFcLong( 0x200a ),	/* 8202 */
/* 490 */	NdrFcShort( 0x6b4 ),	/* Offset= 1716 (2206) */
/* 492 */	NdrFcLong( 0x200c ),	/* 8204 */
/* 496 */	NdrFcShort( 0x6ae ),	/* Offset= 1710 (2206) */
/* 498 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 502 */	NdrFcShort( 0x550 ),	/* Offset= 1360 (1862) */
/* 504 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 508 */	NdrFcShort( 0x54a ),	/* Offset= 1354 (1862) */
/* 510 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 514 */	NdrFcShort( 0x548 ),	/* Offset= 1352 (1866) */
/* 516 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 520 */	NdrFcShort( 0x542 ),	/* Offset= 1346 (1866) */
/* 522 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 526 */	NdrFcShort( 0x540 ),	/* Offset= 1344 (1870) */
/* 528 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 532 */	NdrFcShort( 0x53a ),	/* Offset= 1338 (1870) */
/* 534 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 538 */	NdrFcShort( 0x534 ),	/* Offset= 1332 (1870) */
/* 540 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 544 */	NdrFcShort( 0x52e ),	/* Offset= 1326 (1870) */
/* 546 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 550 */	NdrFcShort( 0x52c ),	/* Offset= 1324 (1874) */
/* 552 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 556 */	NdrFcShort( 0x52a ),	/* Offset= 1322 (1878) */
/* 558 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 562 */	NdrFcShort( 0x518 ),	/* Offset= 1304 (1866) */
/* 564 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 568 */	NdrFcShort( 0x532 ),	/* Offset= 1330 (1898) */
/* 570 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 574 */	NdrFcShort( 0x510 ),	/* Offset= 1296 (1870) */
/* 576 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 580 */	NdrFcShort( 0x522 ),	/* Offset= 1314 (1894) */
/* 582 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 586 */	NdrFcShort( 0x50c ),	/* Offset= 1292 (1878) */
/* 588 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 592 */	NdrFcShort( 0x658 ),	/* Offset= 1624 (2216) */
/* 594 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 598 */	NdrFcShort( 0x518 ),	/* Offset= 1304 (1902) */
/* 600 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 604 */	NdrFcShort( 0x516 ),	/* Offset= 1302 (1906) */
/* 606 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 610 */	NdrFcShort( 0x64a ),	/* Offset= 1610 (2220) */
/* 612 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 616 */	NdrFcShort( 0x648 ),	/* Offset= 1608 (2224) */
/* 618 */	NdrFcShort( 0xffff ),	/* Offset= -1 (617) */
/* 620 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 624 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 626 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 632 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 634 */	
			0x13, 0x0,	/* FC_OP */
/* 636 */	NdrFcShort( 0x8 ),	/* Offset= 8 (644) */
/* 638 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 642 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 644 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 646 */	NdrFcShort( 0x10 ),	/* 16 */
/* 648 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 650 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 652 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (638) */
			0x5b,		/* FC_END */
/* 656 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 658 */	NdrFcShort( 0x1 ),	/* 1 */
/* 660 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 666 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 668 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 672 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 674 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 676 */	NdrFcShort( 0x4 ),	/* 4 */
/* 678 */	NdrFcShort( 0x4 ),	/* 4 */
/* 680 */	0x13, 0x0,	/* FC_OP */
/* 682 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (656) */
/* 684 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 686 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 688 */	
			0x13, 0x0,	/* FC_OP */
/* 690 */	NdrFcShort( 0xe ),	/* Offset= 14 (704) */
/* 692 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 694 */	NdrFcShort( 0x1 ),	/* 1 */
/* 696 */	0x10,		/* Corr desc:  field pointer,  */
			0x59,		/* FC_CALLBACK */
/* 698 */	NdrFcShort( 0x1 ),	/* 1 */
/* 700 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 702 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 704 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 706 */	NdrFcShort( 0xc ),	/* 12 */
/* 708 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 710 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 716 */	0x13, 0x0,	/* FC_OP */
/* 718 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (692) */
/* 720 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 722 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 724 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 726 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 728 */	NdrFcLong( 0xc ),	/* 12 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 738 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 740 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 742 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 744 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 746 */	NdrFcLong( 0xb ),	/* 11 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 754 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 756 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 758 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 760 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 762 */	
			0x13, 0x0,	/* FC_OP */
/* 764 */	NdrFcShort( 0xe ),	/* Offset= 14 (778) */
/* 766 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 768 */	NdrFcShort( 0x2 ),	/* 2 */
/* 770 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 772 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 774 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 776 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 778 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 782 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (766) */
/* 784 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 786 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 788 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x4 ),	/* 4 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0xffde ),	/* Offset= -34 (762) */
/* 798 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 800 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 802 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 804 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 806 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 808 */	NdrFcShort( 0x2 ),	/* 2 */
/* 810 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 816 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 818 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 822 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 824 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 826 */	NdrFcShort( 0x4 ),	/* 4 */
/* 828 */	NdrFcShort( 0x4 ),	/* 4 */
/* 830 */	0x13, 0x0,	/* FC_OP */
/* 832 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (806) */
/* 834 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 836 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 838 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 840 */	NdrFcShort( 0x4 ),	/* 4 */
/* 842 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 848 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 850 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 856 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 858 */	NdrFcShort( 0x4 ),	/* 4 */
/* 860 */	NdrFcShort( 0x4 ),	/* 4 */
/* 862 */	0x13, 0x0,	/* FC_OP */
/* 864 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (838) */
/* 866 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 868 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 870 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 872 */	NdrFcShort( 0x4 ),	/* 4 */
/* 874 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 880 */	0xa,		/* FC_FLOAT */
			0x5b,		/* FC_END */
/* 882 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 886 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 888 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 890 */	NdrFcShort( 0x4 ),	/* 4 */
/* 892 */	NdrFcShort( 0x4 ),	/* 4 */
/* 894 */	0x13, 0x0,	/* FC_OP */
/* 896 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (870) */
/* 898 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 900 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 902 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 906 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 912 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 914 */	NdrFcShort( 0xfeda ),	/* Offset= -294 (620) */
/* 916 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 918 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 922 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 924 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 926 */	NdrFcShort( 0x4 ),	/* 4 */
/* 928 */	NdrFcShort( 0x4 ),	/* 4 */
/* 930 */	0x13, 0x0,	/* FC_OP */
/* 932 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (902) */
/* 934 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 936 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 938 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 942 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 948 */	0xc,		/* FC_DOUBLE */
			0x5b,		/* FC_END */
/* 950 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 954 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 956 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 958 */	NdrFcShort( 0x4 ),	/* 4 */
/* 960 */	NdrFcShort( 0x4 ),	/* 4 */
/* 962 */	0x13, 0x0,	/* FC_OP */
/* 964 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (938) */
/* 966 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 968 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 970 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 980 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 982 */	NdrFcShort( 0xfe9c ),	/* Offset= -356 (626) */
/* 984 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 986 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 990 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 992 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 994 */	NdrFcShort( 0x4 ),	/* 4 */
/* 996 */	NdrFcShort( 0x4 ),	/* 4 */
/* 998 */	0x13, 0x0,	/* FC_OP */
/* 1000 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (970) */
/* 1002 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1004 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1006 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1008 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1010 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1016 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1018 */	NdrFcShort( 0xfe8a ),	/* Offset= -374 (644) */
/* 1020 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1022 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1026 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1028 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1030 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1032 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1034 */	0x13, 0x0,	/* FC_OP */
/* 1036 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1006) */
/* 1038 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1040 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1042 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1044 */	NdrFcShort( 0xc ),	/* 12 */
/* 1046 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1052 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1054 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1056 */	NdrFcShort( 0xc ),	/* 12 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1066 */	0x13, 0x0,	/* FC_OP */
/* 1068 */	NdrFcShort( 0xfe88 ),	/* Offset= -376 (692) */
/* 1070 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1072 */	0x0,		/* 0 */
			NdrFcShort( 0xfe8f ),	/* Offset= -369 (704) */
			0x5b,		/* FC_END */
/* 1076 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1078 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1080 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1082 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1084 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1086 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1088 */	0x13, 0x0,	/* FC_OP */
/* 1090 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (1042) */
/* 1092 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1094 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1096 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1100 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1106 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1110 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1112 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1114 */	NdrFcShort( 0xfeba ),	/* Offset= -326 (788) */
/* 1116 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1118 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1122 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1124 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1126 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1128 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1130 */	0x13, 0x0,	/* FC_OP */
/* 1132 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1096) */
/* 1134 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1136 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1138 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1142 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1148 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1150 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1158 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1160 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1162 */	0x13, 0x0,	/* FC_OP */
/* 1164 */	NdrFcShort( 0xfe04 ),	/* Offset= -508 (656) */
/* 1166 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1168 */	0x0,		/* 0 */
			NdrFcShort( 0xfe0b ),	/* Offset= -501 (668) */
			0x5b,		/* FC_END */
/* 1172 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1176 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1178 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1180 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1182 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1184 */	0x13, 0x0,	/* FC_OP */
/* 1186 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (1138) */
/* 1188 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1190 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1192 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1194 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1196 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1202 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1204 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1206 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1210 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1218 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 1220 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1222 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1224 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1228 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1230 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1232 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1234 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1236 */	0x13, 0x0,	/* FC_OP */
/* 1238 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1192) */
/* 1240 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1242 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1244 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1246 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1248 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1254 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1256 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1258 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1270 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1272 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1274 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1276 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1280 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1282 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1284 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1286 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1288 */	0x13, 0x0,	/* FC_OP */
/* 1290 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1244) */
/* 1292 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1294 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1296 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1306 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1310 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1312 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1314 */	NdrFcShort( 0x392 ),	/* Offset= 914 (2228) */
/* 1316 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1318 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1330) */
/* 1326 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1328 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1330 */	
			0x13, 0x0,	/* FC_OP */
/* 1332 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1296) */
/* 1334 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1336 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1338) */
/* 1338 */	
			0x13, 0x0,	/* FC_OP */
/* 1340 */	NdrFcShort( 0x350 ),	/* Offset= 848 (2188) */
/* 1342 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 1344 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1346 */	NdrFcShort( 0xa ),	/* 10 */
/* 1348 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1352 */	NdrFcShort( 0x5a ),	/* Offset= 90 (1442) */
/* 1354 */	NdrFcLong( 0xd ),	/* 13 */
/* 1358 */	NdrFcShort( 0x90 ),	/* Offset= 144 (1502) */
/* 1360 */	NdrFcLong( 0x9 ),	/* 9 */
/* 1364 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (1558) */
/* 1366 */	NdrFcLong( 0xc ),	/* 12 */
/* 1370 */	NdrFcShort( 0x28e ),	/* Offset= 654 (2024) */
/* 1372 */	NdrFcLong( 0x24 ),	/* 36 */
/* 1376 */	NdrFcShort( 0x2b8 ),	/* Offset= 696 (2072) */
/* 1378 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 1382 */	NdrFcShort( 0x2c2 ),	/* Offset= 706 (2088) */
/* 1384 */	NdrFcLong( 0x10 ),	/* 16 */
/* 1388 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (2120) */
/* 1390 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1394 */	NdrFcShort( 0xfdc0 ),	/* Offset= -576 (818) */
/* 1396 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1400 */	NdrFcShort( 0xfdda ),	/* Offset= -550 (850) */
/* 1402 */	NdrFcLong( 0x14 ),	/* 20 */
/* 1406 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (2152) */
/* 1408 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1407) */
/* 1410 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1412 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1414 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1418 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1420 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1422 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 1424 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1434 */	0x13, 0x0,	/* FC_OP */
/* 1436 */	NdrFcShort( 0xfd6e ),	/* Offset= -658 (778) */
/* 1438 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1440 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1442 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1446 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1448 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1450 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1452 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1454 */	0x11, 0x0,	/* FC_RP */
/* 1456 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1410) */
/* 1458 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1460 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1462 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1472 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1474 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1476 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1478 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1480 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1484 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1490 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1494 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1496 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1498 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1462) */
/* 1500 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1502 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1508 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1514) */
/* 1510 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1512 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1514 */	
			0x11, 0x0,	/* FC_RP */
/* 1516 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1480) */
/* 1518 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1520 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1528 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1530 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1532 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1534 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1536 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1546 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1550 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1552 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1554 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1518) */
/* 1556 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1558 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1564 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1570) */
/* 1566 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1568 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1570 */	
			0x11, 0x0,	/* FC_RP */
/* 1572 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1536) */
/* 1574 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x7,		/* FC_USHORT */
/* 1576 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1578 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 1580 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1582 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1584) */
/* 1584 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1586 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1592 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1592) */
/* 1594 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1598 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1598) */
/* 1600 */	NdrFcLong( 0x10 ),	/* 16 */
/* 1604 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 1606 */	NdrFcLong( 0x12 ),	/* 18 */
/* 1610 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1612 */	NdrFcLong( 0x13 ),	/* 19 */
/* 1616 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1618 */	NdrFcLong( 0x16 ),	/* 22 */
/* 1622 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1624 */	NdrFcLong( 0x17 ),	/* 23 */
/* 1628 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1630 */	NdrFcLong( 0x11 ),	/* 17 */
/* 1634 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 1636 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1640 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1642 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1646 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1648 */	NdrFcLong( 0x4 ),	/* 4 */
/* 1652 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 1654 */	NdrFcLong( 0x5 ),	/* 5 */
/* 1658 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 1660 */	NdrFcLong( 0xb ),	/* 11 */
/* 1664 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1666 */	NdrFcLong( 0xa ),	/* 10 */
/* 1670 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1672 */	NdrFcLong( 0x7 ),	/* 7 */
/* 1676 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 1678 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1682 */	NdrFcShort( 0xfc68 ),	/* Offset= -920 (762) */
/* 1684 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1688 */	NdrFcShort( 0xfbd4 ),	/* Offset= -1068 (620) */
/* 1690 */	NdrFcLong( 0xe ),	/* 14 */
/* 1694 */	NdrFcShort( 0x9a ),	/* Offset= 154 (1848) */
/* 1696 */	NdrFcLong( 0xd ),	/* 13 */
/* 1700 */	NdrFcShort( 0xff12 ),	/* Offset= -238 (1462) */
/* 1702 */	NdrFcLong( 0x9 ),	/* 9 */
/* 1706 */	NdrFcShort( 0xff44 ),	/* Offset= -188 (1518) */
/* 1708 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 1712 */	NdrFcShort( 0x92 ),	/* Offset= 146 (1858) */
/* 1714 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 1718 */	NdrFcShort( 0x90 ),	/* Offset= 144 (1862) */
/* 1720 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 1724 */	NdrFcShort( 0x8e ),	/* Offset= 142 (1866) */
/* 1726 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 1730 */	NdrFcShort( 0x8c ),	/* Offset= 140 (1870) */
/* 1732 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 1736 */	NdrFcShort( 0x86 ),	/* Offset= 134 (1870) */
/* 1738 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 1742 */	NdrFcShort( 0x80 ),	/* Offset= 128 (1870) */
/* 1744 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 1748 */	NdrFcShort( 0x72 ),	/* Offset= 114 (1862) */
/* 1750 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 1754 */	NdrFcShort( 0x70 ),	/* Offset= 112 (1866) */
/* 1756 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 1760 */	NdrFcShort( 0x6e ),	/* Offset= 110 (1870) */
/* 1762 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 1766 */	NdrFcShort( 0x6c ),	/* Offset= 108 (1874) */
/* 1768 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 1772 */	NdrFcShort( 0x6a ),	/* Offset= 106 (1878) */
/* 1774 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 1778 */	NdrFcShort( 0x58 ),	/* Offset= 88 (1866) */
/* 1780 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 1784 */	NdrFcShort( 0x56 ),	/* Offset= 86 (1870) */
/* 1786 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 1790 */	NdrFcShort( 0x58 ),	/* Offset= 88 (1878) */
/* 1792 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 1796 */	NdrFcShort( 0x56 ),	/* Offset= 86 (1882) */
/* 1798 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 1802 */	NdrFcShort( 0x54 ),	/* Offset= 84 (1886) */
/* 1804 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 1808 */	NdrFcShort( 0x56 ),	/* Offset= 86 (1894) */
/* 1810 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 1814 */	NdrFcShort( 0x54 ),	/* Offset= 84 (1898) */
/* 1816 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 1820 */	NdrFcShort( 0x52 ),	/* Offset= 82 (1902) */
/* 1822 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 1826 */	NdrFcShort( 0x50 ),	/* Offset= 80 (1906) */
/* 1828 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 1832 */	NdrFcShort( 0x4e ),	/* Offset= 78 (1910) */
/* 1834 */	NdrFcLong( 0x24 ),	/* 36 */
/* 1838 */	NdrFcShort( 0x50 ),	/* Offset= 80 (1918) */
/* 1840 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 1844 */	NdrFcShort( 0x4a ),	/* Offset= 74 (1918) */
/* 1846 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1845) */
/* 1848 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1850 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1852 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 1854 */	0x2,		/* FC_CHAR */
			0x8,		/* FC_LONG */
/* 1856 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1858 */	
			0x13, 0x0,	/* FC_OP */
/* 1860 */	NdrFcShort( 0x148 ),	/* Offset= 328 (2188) */
/* 1862 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1864 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1866 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1868 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1870 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1872 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1874 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1876 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1878 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1880 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1882 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1884 */	NdrFcShort( 0xfb9e ),	/* Offset= -1122 (762) */
/* 1886 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1888 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1890) */
/* 1890 */	
			0x13, 0x0,	/* FC_OP */
/* 1892 */	NdrFcShort( 0x50 ),	/* Offset= 80 (1972) */
/* 1894 */	
			0x13, 0x0,	/* FC_OP */
/* 1896 */	NdrFcShort( 0xfb04 ),	/* Offset= -1276 (620) */
/* 1898 */	
			0x13, 0x0,	/* FC_OP */
/* 1900 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (1848) */
/* 1902 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1904 */	NdrFcShort( 0xfe46 ),	/* Offset= -442 (1462) */
/* 1906 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1908 */	NdrFcShort( 0xfe7a ),	/* Offset= -390 (1518) */
/* 1910 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1912 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1914) */
/* 1914 */	
			0x13, 0x0,	/* FC_OP */
/* 1916 */	NdrFcShort( 0x110 ),	/* Offset= 272 (2188) */
/* 1918 */	
			0x13, 0x0,	/* FC_OP */
/* 1920 */	NdrFcShort( 0x20 ),	/* Offset= 32 (1952) */
/* 1922 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1924 */	NdrFcLong( 0x2f ),	/* 47 */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1932 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1934 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1936 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1938 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1940 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1942 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1944 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1946 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1948 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1950 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1952 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1954 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1958 */	NdrFcShort( 0xa ),	/* Offset= 10 (1968) */
/* 1960 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1962 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1964 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (1922) */
/* 1966 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 1968 */	
			0x13, 0x0,	/* FC_OP */
/* 1970 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1940) */
/* 1972 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1974 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1978 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1978) */
/* 1980 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1982 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1984 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1986 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1988 */	NdrFcShort( 0xfe62 ),	/* Offset= -414 (1574) */
/* 1990 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1992 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1994 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1996 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2000 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2002 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2004 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 2006 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2010 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2016 */	0x13, 0x0,	/* FC_OP */
/* 2018 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1972) */
/* 2020 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2022 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2024 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2026 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2036) */
/* 2032 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 2034 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2036 */	
			0x11, 0x0,	/* FC_RP */
/* 2038 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (1992) */
/* 2040 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2042 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2044 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2050 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2052 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 2054 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2058 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2064 */	0x13, 0x0,	/* FC_OP */
/* 2066 */	NdrFcShort( 0xff8e ),	/* Offset= -114 (1952) */
/* 2068 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2070 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2072 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2078 */	NdrFcShort( 0x6 ),	/* Offset= 6 (2084) */
/* 2080 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 2082 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2084 */	
			0x11, 0x0,	/* FC_RP */
/* 2086 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (2040) */
/* 2088 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2090 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2094 */	NdrFcShort( 0xa ),	/* Offset= 10 (2104) */
/* 2096 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 2098 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2100 */	NdrFcShort( 0xfa50 ),	/* Offset= -1456 (644) */
/* 2102 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2104 */	
			0x11, 0x0,	/* FC_RP */
/* 2106 */	NdrFcShort( 0xfd8e ),	/* Offset= -626 (1480) */
/* 2108 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 2110 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2112 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2118 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 2120 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2122 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2124 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2126 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2128 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2130 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2132 */	0x13, 0x0,	/* FC_OP */
/* 2134 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (2108) */
/* 2136 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2138 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2140 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 2142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2144 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2150 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 2152 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 2154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2156 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2158 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 2160 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2162 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2164 */	0x13, 0x0,	/* FC_OP */
/* 2166 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (2140) */
/* 2168 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2170 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2172 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2176 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 2178 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 2180 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2182 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2184 */	NdrFcShort( 0xf9ea ),	/* Offset= -1558 (626) */
/* 2186 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2188 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2190 */	NdrFcShort( 0x28 ),	/* 40 */
/* 2192 */	NdrFcShort( 0xffec ),	/* Offset= -20 (2172) */
/* 2194 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2194) */
/* 2196 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 2198 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 2200 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2202 */	NdrFcShort( 0xfca4 ),	/* Offset= -860 (1342) */
/* 2204 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2206 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 2208 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2210 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0xfc90 ),	/* Offset= -880 (1334) */
/* 2216 */	
			0x13, 0x0,	/* FC_OP */
/* 2218 */	NdrFcShort( 0xfa6a ),	/* Offset= -1430 (788) */
/* 2220 */	
			0x13, 0x0,	/* FC_OP */
/* 2222 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (2206) */
/* 2224 */	
			0x13, 0x0,	/* FC_OP */
/* 2226 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2228) */
/* 2228 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 2230 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2234 */	NdrFcShort( 0x0 ),	/* Offset= 0 (2234) */
/* 2236 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 2238 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 2240 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2242 */	NdrFcShort( 0xf784 ),	/* Offset= -2172 (70) */
/* 2244 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2246 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x7,		/* 7 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2250 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2252 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2254 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2256 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 2260 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2262 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2264 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2228) */
/* 2266 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2268 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2270 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2272 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2276 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2278 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 2280 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2282 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2284 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2286 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2288 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2290 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2292 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 2294 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2304 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 2306 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 2308 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2310 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2312 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 2314 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2316 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2318 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2320 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2322 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 2324 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 2326 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2330 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2336 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 2338 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 2340 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 2342 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2344 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2346 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2348) */
/* 2348 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2350 */	NdrFcLong( 0x139 ),	/* 313 */
/* 2354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2358 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 2360 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2362 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2364 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 2366 */	
			0x11, 0x0,	/* FC_RP */
/* 2368 */	NdrFcShort( 0xf932 ),	/* Offset= -1742 (626) */
/* 2370 */	
			0x11, 0x0,	/* FC_RP */
/* 2372 */	NdrFcShort( 0xf940 ),	/* Offset= -1728 (644) */
/* 2374 */	
			0x11, 0x0,	/* FC_RP */
/* 2376 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2378) */
/* 2378 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 2380 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2382 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2384 */	NdrFcShort( 0xf934 ),	/* Offset= -1740 (644) */
/* 2386 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2388 */	NdrFcShort( 0xf930 ),	/* Offset= -1744 (644) */
/* 2390 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2392 */	0x0,		/* 0 */
			NdrFcShort( 0xf919 ),	/* Offset= -1767 (626) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2396 */	0x0,		/* 0 */
			NdrFcShort( 0xf915 ),	/* Offset= -1771 (626) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 2400 */	0x0,		/* 0 */
			NdrFcShort( 0xf911 ),	/* Offset= -1775 (626) */
			0x8,		/* FC_LONG */
/* 2404 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2406 */	
			0x12, 0x0,	/* FC_UP */
/* 2408 */	NdrFcShort( 0xf91c ),	/* Offset= -1764 (644) */
/* 2410 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2412 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2414) */
/* 2414 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2416 */	NdrFcLong( 0x138 ),	/* 312 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2424 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 2426 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2428 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2430 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 2432 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 2434 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2436) */
/* 2436 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 2438 */	NdrFcLong( 0x13b ),	/* 315 */
/* 2442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2446 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 2448 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2450 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 2452 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 2454 */	
			0x11, 0x0,	/* FC_RP */
/* 2456 */	NdrFcShort( 0x14 ),	/* Offset= 20 (2476) */
/* 2458 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 2460 */	NdrFcShort( 0xc ),	/* 12 */
/* 2462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2464 */	NdrFcShort( 0x8 ),	/* Offset= 8 (2472) */
/* 2466 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 2468 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 2470 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2472 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 2474 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 2476 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 2478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2480 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2482 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2484 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2486 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 2488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2490 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2492 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2494 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (2458) */
/* 2496 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 2498 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 2500 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 2502 */	
			0x11, 0x0,	/* FC_RP */
/* 2504 */	NdrFcShort( 0x2 ),	/* Offset= 2 (2506) */
/* 2506 */	
			0x1c,		/* FC_CVARRAY */
			0x3,		/* 3 */
/* 2508 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2510 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 2512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2514 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 2516 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 2518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2520 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 2522 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 2524 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (2378) */
/* 2526 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            }

        };


static void __RPC_USER IPropertyStorage_PROPVARIANTExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{
    PROPVARIANT *pS	=	( PROPVARIANT * )(( pStubMsg->StackTop - 8 ) );
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = ( unsigned long ) ( ( pS->vt & 0x1fff )  );
}

static void __RPC_USER IPropertyStorage_CLIPDATAExprEval_0001( PMIDL_STUB_MESSAGE pStubMsg )
{
    CLIPDATA *pS	=	( CLIPDATA * )pStubMsg->StackTop;
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = ( unsigned long ) ( ( pS->cbSize - sizeof( long  ) )  );
}

static const EXPR_EVAL ExprEvalRoutines[] = 
    {
    IPropertyStorage_PROPVARIANTExprEval_0000
    ,IPropertyStorage_CLIPDATAExprEval_0001
    };



/* Standard interface: __MIDL_itf_propidl_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IPropertyStorage, ver. 0.0,
   GUID={0x00000138,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IPropertyStorage_FormatStringOffsetTable[] =
    {
    0,
    48,
    102,
    144,
    192,
    240,
    282,
    318,
    348,
    384,
    432,
    468
    };

static const MIDL_STUBLESS_PROXY_INFO IPropertyStorage_ProxyInfo =
    {
    &Object_StubDesc,
    propidl__MIDL_ProcFormatString.Format,
    &IPropertyStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPropertyStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    propidl__MIDL_ProcFormatString.Format,
    &IPropertyStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IPropertyStorageProxyVtbl = 
{
    &IPropertyStorage_ProxyInfo,
    &IID_IPropertyStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::ReadMultiple */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::WriteMultiple */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::DeleteMultiple */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::ReadPropertyNames */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::WritePropertyNames */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::DeletePropertyNames */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::Commit */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::Revert */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::Enum */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::SetTimes */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::SetClass */ ,
    (void *) (INT_PTR) -1 /* IPropertyStorage::Stat */
};

const CInterfaceStubVtbl _IPropertyStorageStubVtbl =
{
    &IID_IPropertyStorage,
    &IPropertyStorage_ServerInfo,
    15,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPropertySetStorage, ver. 0.0,
   GUID={0x0000013A,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IPropertySetStorage_FormatStringOffsetTable[] =
    {
    504,
    564,
    612,
    648
    };

static const MIDL_STUBLESS_PROXY_INFO IPropertySetStorage_ProxyInfo =
    {
    &Object_StubDesc,
    propidl__MIDL_ProcFormatString.Format,
    &IPropertySetStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPropertySetStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    propidl__MIDL_ProcFormatString.Format,
    &IPropertySetStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IPropertySetStorageProxyVtbl = 
{
    &IPropertySetStorage_ProxyInfo,
    &IID_IPropertySetStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPropertySetStorage::Create */ ,
    (void *) (INT_PTR) -1 /* IPropertySetStorage::Open */ ,
    (void *) (INT_PTR) -1 /* IPropertySetStorage::Delete */ ,
    (void *) (INT_PTR) -1 /* IPropertySetStorage::Enum */
};

const CInterfaceStubVtbl _IPropertySetStorageStubVtbl =
{
    &IID_IPropertySetStorage,
    &IPropertySetStorage_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumSTATPROPSTG, ver. 0.0,
   GUID={0x00000139,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumSTATPROPSTG_FormatStringOffsetTable[] =
    {
    684,
    732,
    768,
    798
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumSTATPROPSTG_ProxyInfo =
    {
    &Object_StubDesc,
    propidl__MIDL_ProcFormatString.Format,
    &IEnumSTATPROPSTG_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumSTATPROPSTG_StubThunkTable[] = 
    {
    IEnumSTATPROPSTG_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumSTATPROPSTG_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    propidl__MIDL_ProcFormatString.Format,
    &IEnumSTATPROPSTG_FormatStringOffsetTable[-3],
    &IEnumSTATPROPSTG_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumSTATPROPSTGProxyVtbl = 
{
    &IEnumSTATPROPSTG_ProxyInfo,
    &IID_IEnumSTATPROPSTG,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumSTATPROPSTG_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumSTATPROPSTG::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATPROPSTG::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATPROPSTG::Clone */
};

const CInterfaceStubVtbl _IEnumSTATPROPSTGStubVtbl =
{
    &IID_IEnumSTATPROPSTG,
    &IEnumSTATPROPSTG_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumSTATPROPSETSTG, ver. 0.0,
   GUID={0x0000013B,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumSTATPROPSETSTG_FormatStringOffsetTable[] =
    {
    834,
    732,
    768,
    648
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumSTATPROPSETSTG_ProxyInfo =
    {
    &Object_StubDesc,
    propidl__MIDL_ProcFormatString.Format,
    &IEnumSTATPROPSETSTG_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumSTATPROPSETSTG_StubThunkTable[] = 
    {
    IEnumSTATPROPSETSTG_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumSTATPROPSETSTG_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    propidl__MIDL_ProcFormatString.Format,
    &IEnumSTATPROPSETSTG_FormatStringOffsetTable[-3],
    &IEnumSTATPROPSETSTG_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumSTATPROPSETSTGProxyVtbl = 
{
    &IEnumSTATPROPSETSTG_ProxyInfo,
    &IID_IEnumSTATPROPSETSTG,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumSTATPROPSETSTG_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumSTATPROPSETSTG::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATPROPSETSTG::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATPROPSETSTG::Clone */
};

const CInterfaceStubVtbl _IEnumSTATPROPSETSTGStubVtbl =
{
    &IID_IEnumSTATPROPSETSTG,
    &IEnumSTATPROPSETSTG_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_propidl_0000_0004, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    ExprEvalRoutines,
    0,
    propidl__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _propidl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IPropertyStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumSTATPROPSTGProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPropertySetStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumSTATPROPSETSTGProxyVtbl,
    0
};

const CInterfaceStubVtbl * _propidl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IPropertyStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumSTATPROPSTGStubVtbl,
    ( CInterfaceStubVtbl *) &_IPropertySetStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumSTATPROPSETSTGStubVtbl,
    0
};

PCInterfaceName const _propidl_InterfaceNamesList[] = 
{
    "IPropertyStorage",
    "IEnumSTATPROPSTG",
    "IPropertySetStorage",
    "IEnumSTATPROPSETSTG",
    0
};


#define _propidl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _propidl, pIID, n)

int __stdcall _propidl_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _propidl, 4, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _propidl, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _propidl, 4, *pIndex )
    
}

const ExtendedProxyFileInfo propidl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _propidl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _propidl_StubVtblList,
    (const PCInterfaceName * ) & _propidl_InterfaceNamesList,
    0, // no delegation
    & _propidl_IID_Lookup, 
    4,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

