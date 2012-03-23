

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Nov 07 19:52:50 2011
 */
/* Compiler settings for unknwn.idl:
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


#include "unknwn.h"

#define TYPE_FORMAT_STRING_SIZE   37                                
#define PROC_FORMAT_STRING_SIZE   79                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _unknwn_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } unknwn_MIDL_TYPE_FORMAT_STRING;

typedef struct _unknwn_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } unknwn_MIDL_PROC_FORMAT_STRING;

typedef struct _unknwn_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } unknwn_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const unknwn_MIDL_TYPE_FORMAT_STRING unknwn__MIDL_TypeFormatString;
extern const unknwn_MIDL_PROC_FORMAT_STRING unknwn__MIDL_ProcFormatString;
extern const unknwn_MIDL_EXPR_FORMAT_STRING unknwn__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IClassFactory_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IClassFactory_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IClassFactory_RemoteCreateInstance_Proxy( 
    IClassFactory * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown **ppvObject)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &unknwn__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IClassFactory_RemoteCreateInstance_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IClassFactory *This;
        REFIID riid;
        IUnknown **ppvObject;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IClassFactory_CreateInstance_Stub(
                                            (IClassFactory *) pParamStruct->This,
                                            pParamStruct->riid,
                                            pParamStruct->ppvObject);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IClassFactory_RemoteLockServer_Proxy( 
    IClassFactory * This,
    /* [in] */ BOOL fLock)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &unknwn__MIDL_ProcFormatString.Format[42],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IClassFactory_RemoteLockServer_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IClassFactory *This;
        BOOL fLock;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IClassFactory_LockServer_Stub((IClassFactory *) pParamStruct->This,pParamStruct->fLock);
    
}



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const unknwn_MIDL_PROC_FORMAT_STRING unknwn__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RemoteCreateInstance */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x44 ),	/* 68 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 18 */	NdrFcShort( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 24 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0xc ),	/* Type Offset=12 */

	/* Parameter ppvObject */

/* 30 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteLockServer */

/* 42 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 52 */	NdrFcShort( 0x8 ),	/* 8 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 58 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fLock */

/* 66 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 68 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 72 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const unknwn_MIDL_TYPE_FORMAT_STRING unknwn__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x8 ),	/* Offset= 8 (12) */
/*  6 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 12 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x10 ),	/* 16 */
/* 16 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 18 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (6) */
			0x5b,		/* FC_END */
/* 24 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 26 */	NdrFcShort( 0x2 ),	/* Offset= 2 (28) */
/* 28 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 30 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 32 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 34 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IClassFactory, ver. 0.0,
   GUID={0x00000001,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IClassFactory_FormatStringOffsetTable[] =
    {
    0,
    42
    };

static const MIDL_STUBLESS_PROXY_INFO IClassFactory_ProxyInfo =
    {
    &Object_StubDesc,
    unknwn__MIDL_ProcFormatString.Format,
    &IClassFactory_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IClassFactory_StubThunkTable[] = 
    {
    IClassFactory_RemoteCreateInstance_Thunk,
    IClassFactory_RemoteLockServer_Thunk
    };

static const MIDL_SERVER_INFO IClassFactory_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    unknwn__MIDL_ProcFormatString.Format,
    &IClassFactory_FormatStringOffsetTable[-3],
    &IClassFactory_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IClassFactoryProxyVtbl = 
{
    &IClassFactory_ProxyInfo,
    &IID_IClassFactory,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IClassFactory_CreateInstance_Proxy ,
    IClassFactory_LockServer_Proxy
};

const CInterfaceStubVtbl _IClassFactoryStubVtbl =
{
    &IID_IClassFactory,
    &IClassFactory_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    unknwn__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _unknwn_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IClassFactoryProxyVtbl,
    0
};

const CInterfaceStubVtbl * _unknwn_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IClassFactoryStubVtbl,
    0
};

PCInterfaceName const _unknwn_InterfaceNamesList[] = 
{
    "IClassFactory",
    0
};


#define _unknwn_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _unknwn, pIID, n)

int __stdcall _unknwn_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_unknwn_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo unknwn_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _unknwn_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _unknwn_StubVtblList,
    (const PCInterfaceName * ) & _unknwn_InterfaceNamesList,
    0, // no delegation
    & _unknwn_IID_Lookup, 
    1,
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

