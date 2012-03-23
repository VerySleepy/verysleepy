

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Nov 07 19:54:02 2011
 */
/* Compiler settings for objidl.idl:
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


#include "objidl.h"

#define TYPE_FORMAT_STRING_SIZE   1587                              
#define PROC_FORMAT_STRING_SIZE   5179                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   6            

typedef struct _objidl_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } objidl_MIDL_TYPE_FORMAT_STRING;

typedef struct _objidl_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } objidl_MIDL_PROC_FORMAT_STRING;

typedef struct _objidl_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } objidl_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const objidl_MIDL_TYPE_FORMAT_STRING objidl__MIDL_TypeFormatString;
extern const objidl_MIDL_PROC_FORMAT_STRING objidl__MIDL_ProcFormatString;
extern const objidl_MIDL_EXPR_FORMAT_STRING objidl__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumUnknown_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumUnknown_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumUnknown_RemoteNext_Proxy( 
    IEnumUnknown * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IUnknown **rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumUnknown_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumUnknown *This;
        ULONG celt;
        IUnknown **rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumUnknown_Next_Stub(
                                 (IEnumUnknown *) pParamStruct->This,
                                 pParamStruct->celt,
                                 pParamStruct->rgelt,
                                 pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISurrogate_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISurrogate_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBindCtx_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBindCtx_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IBindCtx_RemoteSetBindOptions_Proxy( 
    IBindCtx * This,
    /* [in] */ BIND_OPTS2 *pbindopts)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[288],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IBindCtx_RemoteSetBindOptions_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IBindCtx *This;
        BIND_OPTS2 *pbindopts;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IBindCtx_SetBindOptions_Stub((IBindCtx *) pParamStruct->This,pParamStruct->pbindopts);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IBindCtx_RemoteGetBindOptions_Proxy( 
    IBindCtx * This,
    /* [out][in] */ BIND_OPTS2 *pbindopts)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[324],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IBindCtx_RemoteGetBindOptions_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IBindCtx *This;
        BIND_OPTS2 *pbindopts;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IBindCtx_GetBindOptions_Stub((IBindCtx *) pParamStruct->This,pParamStruct->pbindopts);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumMoniker_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumMoniker_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumMoniker_RemoteNext_Proxy( 
    IEnumMoniker * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IMoniker **rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[552],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumMoniker_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumMoniker *This;
        ULONG celt;
        IMoniker **rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumMoniker_Next_Stub(
                                 (IEnumMoniker *) pParamStruct->This,
                                 pParamStruct->celt,
                                 pParamStruct->rgelt,
                                 pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRunnableObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRunnableObject_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IRunnableObject_RemoteIsRunning_Proxy( 
    IRunnableObject * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[84],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IRunnableObject_RemoteIsRunning_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IRunnableObject *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IRunnableObject_IsRunning_Stub((IRunnableObject *) pParamStruct->This);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRunningObjectTable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRunningObjectTable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPersist_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPersist_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPersistStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPersistStream_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IMoniker_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IMoniker_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IMoniker_RemoteBindToObject_Proxy( 
    IMoniker * This,
    /* [unique][in] */ IBindCtx *pbc,
    /* [unique][in] */ IMoniker *pmkToLeft,
    /* [in] */ REFIID riidResult,
    /* [iid_is][out] */ IUnknown **ppvResult)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[1152],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IMoniker_RemoteBindToObject_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IMoniker *This;
        IBindCtx *pbc;
        IMoniker *pmkToLeft;
        REFIID riidResult;
        IUnknown **ppvResult;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IMoniker_BindToObject_Stub(
                                     (IMoniker *) pParamStruct->This,
                                     pParamStruct->pbc,
                                     pParamStruct->pmkToLeft,
                                     pParamStruct->riidResult,
                                     pParamStruct->ppvResult);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IMoniker_RemoteBindToStorage_Proxy( 
    IMoniker * This,
    /* [unique][in] */ IBindCtx *pbc,
    /* [unique][in] */ IMoniker *pmkToLeft,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown **ppvObj)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[1206],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IMoniker_RemoteBindToStorage_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IMoniker *This;
        IBindCtx *pbc;
        IMoniker *pmkToLeft;
        REFIID riid;
        IUnknown **ppvObj;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IMoniker_BindToStorage_Stub(
                                      (IMoniker *) pParamStruct->This,
                                      pParamStruct->pbc,
                                      pParamStruct->pmkToLeft,
                                      pParamStruct->riid,
                                      pParamStruct->ppvObj);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IROTData_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IROTData_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumString_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumString_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumString_RemoteNext_Proxy( 
    IEnumString * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ LPOLESTR *rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[1884],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumString_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumString *This;
        ULONG celt;
        LPOLESTR *rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumString_Next_Stub(
                                (IEnumString *) pParamStruct->This,
                                pParamStruct->celt,
                                pParamStruct->rgelt,
                                pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IClassActivator_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IClassActivator_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISequentialStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISequentialStream_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE ISequentialStream_RemoteRead_Proxy( 
    ISequentialStream * This,
    /* [length_is][size_is][out] */ byte *pv,
    /* [in] */ ULONG cb,
    /* [out] */ ULONG *pcbRead)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[2028],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ISequentialStream_RemoteRead_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ISequentialStream *This;
        byte *pv;
        ULONG cb;
        ULONG *pcbRead;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ISequentialStream_Read_Stub(
                                      (ISequentialStream *) pParamStruct->This,
                                      pParamStruct->pv,
                                      pParamStruct->cb,
                                      pParamStruct->pcbRead);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ISequentialStream_RemoteWrite_Proxy( 
    ISequentialStream * This,
    /* [size_is][in] */ const byte *pv,
    /* [in] */ ULONG cb,
    /* [out] */ ULONG *pcbWritten)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[2076],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ISequentialStream_RemoteWrite_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ISequentialStream *This;
        const byte *pv;
        ULONG cb;
        ULONG *pcbWritten;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ISequentialStream_Write_Stub(
                                       (ISequentialStream *) pParamStruct->This,
                                       pParamStruct->pv,
                                       pParamStruct->cb,
                                       pParamStruct->pcbWritten);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStream_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IStream_RemoteSeek_Proxy( 
    IStream * This,
    /* [in] */ LARGE_INTEGER dlibMove,
    /* [in] */ DWORD dwOrigin,
    /* [out] */ ULARGE_INTEGER *plibNewPosition)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[2124],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IStream_RemoteSeek_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IStream *This;
        LARGE_INTEGER dlibMove;
        DWORD dwOrigin;
        ULARGE_INTEGER *plibNewPosition;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IStream_Seek_Stub(
                            (IStream *) pParamStruct->This,
                            pParamStruct->dlibMove,
                            pParamStruct->dwOrigin,
                            pParamStruct->plibNewPosition);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IStream_RemoteCopyTo_Proxy( 
    IStream * This,
    /* [unique][in] */ IStream *pstm,
    /* [in] */ ULARGE_INTEGER cb,
    /* [out] */ ULARGE_INTEGER *pcbRead,
    /* [out] */ ULARGE_INTEGER *pcbWritten)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[2208],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IStream_RemoteCopyTo_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IStream *This;
        IStream *pstm;
        ULARGE_INTEGER cb;
        ULARGE_INTEGER *pcbRead;
        ULARGE_INTEGER *pcbWritten;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IStream_CopyTo_Stub(
                              (IStream *) pParamStruct->This,
                              pParamStruct->pstm,
                              pParamStruct->cb,
                              pParamStruct->pcbRead,
                              pParamStruct->pcbWritten);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumSTATSTG_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumSTATSTG_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumSTATSTG_RemoteNext_Proxy( 
    IEnumSTATSTG * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ STATSTG *rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[2502],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumSTATSTG_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumSTATSTG *This;
        ULONG celt;
        STATSTG *rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumSTATSTG_Next_Stub(
                                 (IEnumSTATSTG *) pParamStruct->This,
                                 pParamStruct->celt,
                                 pParamStruct->rgelt,
                                 pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IStorage_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IStorage_RemoteOpenStream_Proxy( 
    IStorage * This,
    /* [in] */ LPCOLESTR pwcsName,
    /* [in] */ unsigned long cbReserved1,
    /* [size_is][unique][in] */ byte *reserved1,
    /* [in] */ DWORD grfMode,
    /* [in] */ DWORD reserved2,
    /* [out] */ IStream **ppstm)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[2646],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IStorage_RemoteOpenStream_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IStorage *This;
        LPCOLESTR pwcsName;
        unsigned long cbReserved1;
        byte *reserved1;
        DWORD grfMode;
        DWORD reserved2;
        IStream **ppstm;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IStorage_OpenStream_Stub(
                                   (IStorage *) pParamStruct->This,
                                   pParamStruct->pwcsName,
                                   pParamStruct->cbReserved1,
                                   pParamStruct->reserved1,
                                   pParamStruct->grfMode,
                                   pParamStruct->reserved2,
                                   pParamStruct->ppstm);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IStorage_RemoteEnumElements_Proxy( 
    IStorage * This,
    /* [in] */ DWORD reserved1,
    /* [in] */ unsigned long cbReserved2,
    /* [size_is][unique][in] */ byte *reserved2,
    /* [in] */ DWORD reserved3,
    /* [out] */ IEnumSTATSTG **ppenum)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[3012],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IStorage_RemoteEnumElements_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IStorage *This;
        DWORD reserved1;
        unsigned long cbReserved2;
        byte *reserved2;
        DWORD reserved3;
        IEnumSTATSTG **ppenum;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IStorage_EnumElements_Stub(
                                     (IStorage *) pParamStruct->This,
                                     pParamStruct->reserved1,
                                     pParamStruct->cbReserved2,
                                     pParamStruct->reserved2,
                                     pParamStruct->reserved3,
                                     pParamStruct->ppenum);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPersistFile_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPersistFile_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPersistStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPersistStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IRootStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IRootStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILockBytes_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ILockBytes_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE ILockBytes_RemoteReadAt_Proxy( 
    ILockBytes * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [length_is][size_is][out] */ byte *pv,
    /* [in] */ ULONG cb,
    /* [out] */ ULONG *pcbRead)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[3630],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ILockBytes_RemoteReadAt_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ILockBytes *This;
        ULARGE_INTEGER ulOffset;
        byte *pv;
        ULONG cb;
        ULONG *pcbRead;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ILockBytes_ReadAt_Stub(
                                 (ILockBytes *) pParamStruct->This,
                                 pParamStruct->ulOffset,
                                 pParamStruct->pv,
                                 pParamStruct->cb,
                                 pParamStruct->pcbRead);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ILockBytes_RemoteWriteAt_Proxy( 
    ILockBytes * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const byte *pv,
    /* [in] */ ULONG cb,
    /* [out] */ ULONG *pcbWritten)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[3684],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ILockBytes_RemoteWriteAt_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ILockBytes *This;
        ULARGE_INTEGER ulOffset;
        const byte *pv;
        ULONG cb;
        ULONG *pcbWritten;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ILockBytes_WriteAt_Stub(
                                  (ILockBytes *) pParamStruct->This,
                                  pParamStruct->ulOffset,
                                  pParamStruct->pv,
                                  pParamStruct->cb,
                                  pParamStruct->pcbWritten);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFillLockBytes_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFillLockBytes_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IFillLockBytes_RemoteFillAppend_Proxy( 
    IFillLockBytes * This,
    /* [size_is][in] */ const byte *pv,
    /* [in] */ ULONG cb,
    /* [out] */ ULONG *pcbWritten)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[3876],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IFillLockBytes_RemoteFillAppend_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IFillLockBytes *This;
        const byte *pv;
        ULONG cb;
        ULONG *pcbWritten;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IFillLockBytes_FillAppend_Stub(
                                         (IFillLockBytes *) pParamStruct->This,
                                         pParamStruct->pv,
                                         pParamStruct->cb,
                                         pParamStruct->pcbWritten);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IFillLockBytes_RemoteFillAt_Proxy( 
    IFillLockBytes * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const byte *pv,
    /* [in] */ ULONG cb,
    /* [out] */ ULONG *pcbWritten)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[3684],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IFillLockBytes_RemoteFillAt_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IFillLockBytes *This;
        ULARGE_INTEGER ulOffset;
        const byte *pv;
        ULONG cb;
        ULONG *pcbWritten;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IFillLockBytes_FillAt_Stub(
                                     (IFillLockBytes *) pParamStruct->This,
                                     pParamStruct->ulOffset,
                                     pParamStruct->pv,
                                     pParamStruct->cb,
                                     pParamStruct->pcbWritten);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IProgressNotify_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IProgressNotify_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBlockingLock_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBlockingLock_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITimeAndNoticeControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITimeAndNoticeControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOplockStorage_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOplockStorage_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumFORMATETC_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumFORMATETC_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumFORMATETC_RemoteNext_Proxy( 
    IEnumFORMATETC * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ FORMATETC *rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4260],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumFORMATETC_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumFORMATETC *This;
        ULONG celt;
        FORMATETC *rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumFORMATETC_Next_Stub(
                                   (IEnumFORMATETC *) pParamStruct->This,
                                   pParamStruct->celt,
                                   pParamStruct->rgelt,
                                   pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumSTATDATA_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumSTATDATA_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumSTATDATA_RemoteNext_Proxy( 
    IEnumSTATDATA * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ STATDATA *rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4344],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumSTATDATA_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumSTATDATA *This;
        ULONG celt;
        STATDATA *rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumSTATDATA_Next_Stub(
                                  (IEnumSTATDATA *) pParamStruct->This,
                                  pParamStruct->celt,
                                  pParamStruct->rgelt,
                                  pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAdviseSink_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAdviseSink_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSink_RemoteOnDataChange_Proxy( 
    IAdviseSink * This,
    /* [unique][in] */ FORMATETC *pFormatetc,
    /* [unique][in] */ ASYNC_STGMEDIUM *pStgmed)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4428],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IAdviseSink_RemoteOnDataChange_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IAdviseSink *This;
        FORMATETC *pFormatetc;
        ASYNC_STGMEDIUM *pStgmed;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IAdviseSink_OnDataChange_Stub(
                                        (IAdviseSink *) pParamStruct->This,
                                        pParamStruct->pFormatetc,
                                        pParamStruct->pStgmed);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSink_RemoteOnViewChange_Proxy( 
    IAdviseSink * This,
    /* [in] */ DWORD dwAspect,
    /* [in] */ LONG lindex)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4470],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IAdviseSink_RemoteOnViewChange_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IAdviseSink *This;
        DWORD dwAspect;
        LONG lindex;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IAdviseSink_OnViewChange_Stub(
                                        (IAdviseSink *) pParamStruct->This,
                                        pParamStruct->dwAspect,
                                        pParamStruct->lindex);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSink_RemoteOnRename_Proxy( 
    IAdviseSink * This,
    /* [in] */ IMoniker *pmk)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[840],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IAdviseSink_RemoteOnRename_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IAdviseSink *This;
        IMoniker *pmk;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IAdviseSink_OnRename_Stub((IAdviseSink *) pParamStruct->This,pParamStruct->pmk);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSink_RemoteOnSave_Proxy( 
    IAdviseSink * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4512],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IAdviseSink_RemoteOnSave_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IAdviseSink *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IAdviseSink_OnSave_Stub((IAdviseSink *) pParamStruct->This);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSink_RemoteOnClose_Proxy( 
    IAdviseSink * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4542],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IAdviseSink_RemoteOnClose_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IAdviseSink *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IAdviseSink_OnClose_Stub((IAdviseSink *) pParamStruct->This);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAdviseSink2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAdviseSink2_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IAdviseSink2_RemoteOnLinkSrcChange_Proxy( 
    IAdviseSink2 * This,
    /* [unique][in] */ IMoniker *pmk)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4572],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IAdviseSink2_RemoteOnLinkSrcChange_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IAdviseSink2 *This;
        IMoniker *pmk;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IAdviseSink2_OnLinkSrcChange_Stub((IAdviseSink2 *) pParamStruct->This,pParamStruct->pmk);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDataObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDataObject_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IDataObject_RemoteGetData_Proxy( 
    IDataObject * This,
    /* [unique][in] */ FORMATETC *pformatetcIn,
    /* [out] */ STGMEDIUM *pRemoteMedium)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4608],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IDataObject_RemoteGetData_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IDataObject *This;
        FORMATETC *pformatetcIn;
        STGMEDIUM *pRemoteMedium;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IDataObject_GetData_Stub(
                                   (IDataObject *) pParamStruct->This,
                                   pParamStruct->pformatetcIn,
                                   pParamStruct->pRemoteMedium);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IDataObject_RemoteGetDataHere_Proxy( 
    IDataObject * This,
    /* [unique][in] */ FORMATETC *pformatetc,
    /* [out][in] */ STGMEDIUM *pRemoteMedium)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4650],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IDataObject_RemoteGetDataHere_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IDataObject *This;
        FORMATETC *pformatetc;
        STGMEDIUM *pRemoteMedium;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IDataObject_GetDataHere_Stub(
                                       (IDataObject *) pParamStruct->This,
                                       pParamStruct->pformatetc,
                                       pParamStruct->pRemoteMedium);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IDataObject_RemoteSetData_Proxy( 
    IDataObject * This,
    /* [unique][in] */ FORMATETC *pformatetc,
    /* [unique][in] */ FLAG_STGMEDIUM *pmedium,
    /* [in] */ BOOL fRelease)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &objidl__MIDL_ProcFormatString.Format[4770],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IDataObject_RemoteSetData_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IDataObject *This;
        FORMATETC *pformatetc;
        FLAG_STGMEDIUM *pmedium;
        BOOL fRelease;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IDataObject_SetData_Stub(
                                   (IDataObject *) pParamStruct->This,
                                   pParamStruct->pformatetc,
                                   pParamStruct->pmedium,
                                   pParamStruct->fRelease);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDirectWriterLock_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDirectWriterLock_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISynchronize_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISynchronize_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IUrlMon_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IUrlMon_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IProcessInitControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IProcessInitControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IThumbnailExtractor_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IThumbnailExtractor_ProxyInfo;


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


static const objidl_MIDL_PROC_FORMAT_STRING objidl__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RemoteNext */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x24 ),	/* 36 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 16 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 18 */	NdrFcShort( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 24 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 30 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x18 ),	/* Type Offset=24 */

	/* Parameter pceltFetched */

/* 36 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 42 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 44 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 46 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */


	/* Procedure Skip */


	/* Procedure Skip */


	/* Procedure Skip */


	/* Procedure Revoke */


	/* Procedure Skip */


	/* Procedure Skip */

/* 48 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 50 */	NdrFcLong( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x4 ),	/* 4 */
/* 56 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 58 */	NdrFcShort( 0x8 ),	/* 8 */
/* 60 */	NdrFcShort( 0x8 ),	/* 8 */
/* 62 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 64 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */


	/* Parameter celt */


	/* Parameter celt */


	/* Parameter celt */


	/* Parameter dwRegister */


	/* Parameter celt */


	/* Parameter celt */

/* 72 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 74 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */


	/* Procedure HaveWriteAccess */


	/* Procedure Reset */


	/* Procedure Reset */


	/* Procedure Flush */


	/* Procedure Reset */


	/* Procedure Reset */


	/* Procedure RemoteIsRunning */


	/* Procedure Reset */


	/* Procedure ReleaseBoundObjects */


	/* Procedure Reset */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x5 ),	/* 5 */
/* 92 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 100 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x6 ),	/* 6 */
/* 122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 130 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 138 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadDllServer */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x3 ),	/* 3 */
/* 158 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 160 */	NdrFcShort( 0x44 ),	/* 68 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 166 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Clsid */

/* 174 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 180 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Signal */


	/* Procedure ReleaseWriteAccess */


	/* Procedure Unlock */


	/* Procedure IsDirty */


	/* Procedure IsDirty */


	/* Procedure IsDirty */


	/* Procedure FreeSurrogate */

/* 186 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 188 */	NdrFcLong( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x4 ),	/* 4 */
/* 194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 200 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 202 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterObjectBound */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x3 ),	/* 3 */
/* 224 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 230 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 232 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter punk */

/* 240 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 244 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 248 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RevokeObjectBound */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x4 ),	/* 4 */
/* 260 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 268 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter punk */

/* 276 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 280 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteSetBindOptions */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x6 ),	/* 6 */
/* 296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 302 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 304 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x3 ),	/* 3 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbindopts */

/* 312 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 316 */	NdrFcShort( 0xf8 ),	/* Type Offset=248 */

	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetBindOptions */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x7 ),	/* 7 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 340 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 342 */	NdrFcShort( 0x3 ),	/* 3 */
/* 344 */	NdrFcShort( 0x3 ),	/* 3 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbindopts */

/* 348 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	NdrFcShort( 0xf8 ),	/* Type Offset=248 */

	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRunningObjectTable */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 374 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 376 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pprot */

/* 384 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 388 */	NdrFcShort( 0x112 ),	/* Type Offset=274 */

	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RegisterObjectParam */

/* 396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x9 ),	/* 9 */
/* 404 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 412 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszKey */

/* 420 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 424 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter punk */

/* 426 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 430 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 434 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetObjectParam */

/* 438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0xa ),	/* 10 */
/* 446 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 452 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 454 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszKey */

/* 462 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 464 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 466 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter ppunk */

/* 468 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 470 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 472 */	NdrFcShort( 0x12c ),	/* Type Offset=300 */

	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 476 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumObjectParam */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0xb ),	/* 11 */
/* 488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 494 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 504 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	NdrFcShort( 0x130 ),	/* Type Offset=304 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DestroyElement */


	/* Procedure RevokeObjectParam */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0xc ),	/* 12 */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 532 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */


	/* Parameter pszKey */

/* 540 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 544 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Return value */


	/* Return value */

/* 546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x3 ),	/* 3 */
/* 560 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 564 */	NdrFcShort( 0x24 ),	/* 36 */
/* 566 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 568 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 570 */	NdrFcShort( 0x1 ),	/* 1 */
/* 572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 582 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 586 */	NdrFcShort( 0x15c ),	/* Type Offset=348 */

	/* Parameter pceltFetched */

/* 588 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 596 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x6 ),	/* 6 */
/* 608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 614 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 616 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 624 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 626 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 628 */	NdrFcShort( 0x172 ),	/* Type Offset=370 */

	/* Return value */

/* 630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 632 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClassID */


	/* Procedure GetRunningClass */

/* 636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x3 ),	/* 3 */
/* 644 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x4c ),	/* 76 */
/* 650 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 652 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClassID */


	/* Parameter lpClsid */

/* 660 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 662 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 664 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */


	/* Return value */

/* 666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 668 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Run */

/* 672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x4 ),	/* 4 */
/* 680 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 686 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 688 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 696 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 698 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 700 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Return value */

/* 702 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 704 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockRunning */

/* 708 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 710 */	NdrFcLong( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x6 ),	/* 6 */
/* 716 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 718 */	NdrFcShort( 0x10 ),	/* 16 */
/* 720 */	NdrFcShort( 0x8 ),	/* 8 */
/* 722 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 724 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fLock */

/* 732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 734 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter fLastUnlockCloses */

/* 738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 740 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 746 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetContainedObject */

/* 750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x7 ),	/* 7 */
/* 758 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 764 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 766 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fContained */

/* 774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 782 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Register */

/* 786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x3 ),	/* 3 */
/* 794 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 798 */	NdrFcShort( 0x24 ),	/* 36 */
/* 800 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 802 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfFlags */

/* 810 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter punkObject */

/* 816 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 820 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pmkObjectName */

/* 822 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 826 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter pdwRegister */

/* 828 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 836 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteOnRename */


	/* Procedure IsRunning */

/* 840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x5 ),	/* 5 */
/* 848 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 856 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmk */


	/* Parameter pmkObjectName */

/* 864 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 866 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 868 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Return value */


	/* Return value */

/* 870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetObject */

/* 876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x6 ),	/* 6 */
/* 884 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 892 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmkObjectName */

/* 900 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 904 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter ppunkObject */

/* 906 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 910 */	NdrFcShort( 0x12c ),	/* Type Offset=300 */

	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NoteChangeTime */

/* 918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x7 ),	/* 7 */
/* 926 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 928 */	NdrFcShort( 0x34 ),	/* 52 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwRegister */

/* 942 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pfiletime */

/* 948 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 952 */	NdrFcShort( 0x1a2 ),	/* Type Offset=418 */

	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTimeOfLastChange */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 968 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x34 ),	/* 52 */
/* 974 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 976 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmkObjectName */

/* 984 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 988 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter pfiletime */

/* 990 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 994 */	NdrFcShort( 0x1a2 ),	/* Type Offset=418 */

	/* Return value */

/* 996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumRunning */

/* 1002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1010 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1016 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1018 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenumMoniker */

/* 1026 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1030 */	NdrFcShort( 0x172 ),	/* Type Offset=370 */

	/* Return value */

/* 1032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Load */

/* 1038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1046 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1052 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1054 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStm */

/* 1062 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1064 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1066 */	NdrFcShort( 0x1ae ),	/* Type Offset=430 */

	/* Return value */

/* 1068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1070 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 1074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1082 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1088 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1090 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStm */

/* 1098 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1102 */	NdrFcShort( 0x1ae ),	/* Type Offset=430 */

	/* Parameter fClearDirty */

/* 1104 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1112 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSizeMax */

/* 1116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1124 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1132 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcbSize */

/* 1140 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1144 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Return value */

/* 1146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteBindToObject */

/* 1152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1160 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1162 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1166 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1168 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1170 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1176 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1178 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1180 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter pmkToLeft */

/* 1182 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1184 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1186 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter riidResult */

/* 1188 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1192 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter ppvResult */

/* 1194 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1196 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1198 */	NdrFcShort( 0x1ca ),	/* Type Offset=458 */

	/* Return value */

/* 1200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1202 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteBindToStorage */

/* 1206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1214 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1216 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1220 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1222 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1224 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1230 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1232 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1234 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter pmkToLeft */

/* 1236 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1240 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter riid */

/* 1242 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1244 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1246 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter ppvObj */

/* 1248 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1250 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1252 */	NdrFcShort( 0x1d6 ),	/* Type Offset=470 */

	/* Return value */

/* 1254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1256 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reduce */

/* 1260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0xa ),	/* 10 */
/* 1268 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1274 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1276 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1282 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1284 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1286 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1288 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter dwReduceHowFar */

/* 1290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1292 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1294 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppmkToLeft */

/* 1296 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1298 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1300 */	NdrFcShort( 0x1e2 ),	/* Type Offset=482 */

	/* Parameter ppmkReduced */

/* 1302 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1304 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1306 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ComposeWith */

/* 1314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0xb ),	/* 11 */
/* 1322 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1328 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1330 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmkRight */

/* 1338 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1342 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter fOnlyIfNotGeneric */

/* 1344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppmkComposite */

/* 1350 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1352 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1354 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 1356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1358 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Enum */

/* 1362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0xc ),	/* 12 */
/* 1370 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1372 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1376 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1378 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fForward */

/* 1386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppenumMoniker */

/* 1392 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1394 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1396 */	NdrFcShort( 0x172 ),	/* Type Offset=370 */

	/* Return value */

/* 1398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1400 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsEqual */

/* 1404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0xd ),	/* 13 */
/* 1412 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1418 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1420 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmkOtherMoniker */

/* 1428 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1430 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1432 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Return value */

/* 1434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1436 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Hash */

/* 1440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0xe ),	/* 14 */
/* 1448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1454 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1456 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdwHash */

/* 1464 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1466 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsRunning */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0xf ),	/* 15 */
/* 1484 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1492 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1500 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter pmkToLeft */

/* 1506 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1510 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter pmkNewlyRunning */

/* 1512 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1514 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1516 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Return value */

/* 1518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1520 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTimeOfLastChange */

/* 1524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1532 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1538 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1540 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1548 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1552 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter pmkToLeft */

/* 1554 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1558 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter pFileTime */

/* 1560 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 1562 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1564 */	NdrFcShort( 0x1a2 ),	/* Type Offset=418 */

	/* Return value */

/* 1566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1568 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Inverse */

/* 1572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1580 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1586 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1588 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppmk */

/* 1596 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1598 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1600 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 1602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1604 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CommonPrefixWith */

/* 1608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1616 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1622 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1624 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmkOther */

/* 1632 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1634 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1636 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter ppmkPrefix */

/* 1638 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1640 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1642 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 1644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RelativePathTo */

/* 1650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1656 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1658 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1664 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1666 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmkOther */

/* 1674 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1678 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter ppmkRelPath */

/* 1680 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1684 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 1686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1688 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDisplayName */

/* 1692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1700 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1706 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1708 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1716 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1718 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1720 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter pmkToLeft */

/* 1722 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1724 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1726 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter ppszDisplayName */

/* 1728 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1730 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1732 */	NdrFcShort( 0x1ea ),	/* Type Offset=490 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ParseDisplayName */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1748 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1754 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1756 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1764 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter pmkToLeft */

/* 1770 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1772 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1774 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Parameter pszDisplayName */

/* 1776 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1778 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1780 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter pchEaten */

/* 1782 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1784 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppmkOut */

/* 1788 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1790 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1792 */	NdrFcShort( 0x1e6 ),	/* Type Offset=486 */

	/* Return value */

/* 1794 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1796 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsSystemMoniker */

/* 1800 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1802 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1806 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1808 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1814 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1816 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdwMksys */

/* 1824 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1826 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1832 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetComparisonData */

/* 1836 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1842 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1844 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1848 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1850 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1852 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1858 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbData */

/* 1860 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1862 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1864 */	NdrFcShort( 0x1f6 ),	/* Type Offset=502 */

	/* Parameter cbMax */

/* 1866 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1868 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbData */

/* 1872 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1874 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1880 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 1884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1892 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1896 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1898 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1900 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1902 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 1908 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1910 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 1914 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1916 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1918 */	NdrFcShort( 0x206 ),	/* Type Offset=518 */

	/* Parameter pceltFetched */

/* 1920 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1928 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 1932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1940 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1946 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1948 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 1956 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1958 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1960 */	NdrFcShort( 0x130 ),	/* Type Offset=304 */

	/* Return value */

/* 1962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1964 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClassObject */

/* 1968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1976 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1978 */	NdrFcShort( 0x98 ),	/* 152 */
/* 1980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1982 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 1984 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1986 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rclsid */

/* 1992 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1996 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter dwClassContext */

/* 1998 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter locale */

/* 2004 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2006 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2010 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2012 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2014 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter ppv */

/* 2016 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2018 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2020 */	NdrFcShort( 0x22c ),	/* Type Offset=556 */

	/* Return value */

/* 2022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2024 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteRead */

/* 2028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2036 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2040 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2042 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2044 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2046 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pv */

/* 2052 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2054 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2056 */	NdrFcShort( 0x23c ),	/* Type Offset=572 */

	/* Parameter cb */

/* 2058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2060 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbRead */

/* 2064 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2066 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2072 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteWrite */

/* 2076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2084 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2088 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2090 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2092 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2096 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pv */

/* 2100 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2104 */	NdrFcShort( 0x1f6 ),	/* Type Offset=502 */

	/* Parameter cb */

/* 2106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */

/* 2112 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2120 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteSeek */

/* 2124 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2132 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2134 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2136 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2138 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2140 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dlibMove */

/* 2148 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2150 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2152 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter dwOrigin */

/* 2154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2156 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter plibNewPosition */

/* 2160 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2162 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2164 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Return value */

/* 2166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2168 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSize */


	/* Procedure SetSize */

/* 2172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2180 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2182 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2186 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2188 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter cb */


	/* Parameter libNewSize */

/* 2196 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2200 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Return value */


	/* Return value */

/* 2202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteCopyTo */

/* 2208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2216 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2218 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2220 */	NdrFcShort( 0x60 ),	/* 96 */
/* 2222 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2224 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstm */

/* 2232 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2236 */	NdrFcShort( 0x1ae ),	/* Type Offset=430 */

	/* Parameter cb */

/* 2238 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2242 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter pcbRead */

/* 2244 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2248 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter pcbWritten */

/* 2250 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2252 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2254 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Return value */

/* 2256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2258 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 2262 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2276 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2278 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfCommitFlags */

/* 2286 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2288 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HandsOffStorage */


	/* Procedure Revert */

/* 2298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2306 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2314 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 2322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2324 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockRegion */

/* 2328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0xa ),	/* 10 */
/* 2336 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2338 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2342 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2344 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 2352 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2356 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter cb */

/* 2358 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2360 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2362 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter dwLockType */

/* 2364 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2366 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2372 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockRegion */

/* 2376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0xb ),	/* 11 */
/* 2384 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2386 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2390 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 2392 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 2400 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2402 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2404 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter cb */

/* 2406 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2408 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2410 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter dwLockType */

/* 2412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2414 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2420 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stat */

/* 2424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2430 */	NdrFcShort( 0xc ),	/* 12 */
/* 2432 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2438 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2440 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstatstg */

/* 2448 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2450 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2452 */	NdrFcShort( 0x252 ),	/* Type Offset=594 */

	/* Parameter grfStatFlag */

/* 2454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2456 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2462 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0xd ),	/* 13 */
/* 2474 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2480 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2482 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppstm */

/* 2490 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2492 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2494 */	NdrFcShort( 0x27e ),	/* Type Offset=638 */

	/* Return value */

/* 2496 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2498 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2500 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 2502 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2504 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2508 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2510 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2514 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2516 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2518 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2520 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 2526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2528 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 2532 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2536 */	NdrFcShort( 0x286 ),	/* Type Offset=646 */

	/* Parameter pceltFetched */

/* 2538 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2540 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2546 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2556 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2558 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2564 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2566 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 2574 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2576 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2578 */	NdrFcShort( 0x2ae ),	/* Type Offset=686 */

	/* Return value */

/* 2580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2582 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateStream */

/* 2586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2592 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2594 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2596 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2600 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2602 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2608 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 2610 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2612 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2614 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter grfMode */

/* 2616 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2618 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2620 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reserved1 */

/* 2622 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2624 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reserved2 */

/* 2628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2630 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppstm */

/* 2634 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2636 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2638 */	NdrFcShort( 0x27e ),	/* Type Offset=638 */

	/* Return value */

/* 2640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2642 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteOpenStream */

/* 2646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2652 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2654 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2656 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2660 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2662 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2666 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 2670 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2672 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2674 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter cbReserved1 */

/* 2676 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2678 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reserved1 */

/* 2682 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2686 */	NdrFcShort( 0x2c4 ),	/* Type Offset=708 */

	/* Parameter grfMode */

/* 2688 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2690 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reserved2 */

/* 2694 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2696 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppstm */

/* 2700 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2702 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2704 */	NdrFcShort( 0x27e ),	/* Type Offset=638 */

	/* Return value */

/* 2706 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2708 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2710 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateStorage */

/* 2712 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2714 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2718 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2720 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2722 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2726 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2728 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2734 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 2736 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2738 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2740 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter grfMode */

/* 2742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2744 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwStgFmt */

/* 2748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2750 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reserved2 */

/* 2754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2756 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppstg */

/* 2760 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2762 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2764 */	NdrFcShort( 0x2d4 ),	/* Type Offset=724 */

	/* Return value */

/* 2766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2768 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenStorage */

/* 2772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2778 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2780 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2782 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2786 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2788 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2792 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2794 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 2796 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2798 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2800 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Parameter pstgPriority */

/* 2802 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2804 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2806 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Parameter grfMode */

/* 2808 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2810 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter snbExclude */

/* 2814 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2816 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2818 */	NdrFcShort( 0x308 ),	/* Type Offset=776 */

	/* Parameter reserved */

/* 2820 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2822 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppstg */

/* 2826 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2828 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2830 */	NdrFcShort( 0x2d4 ),	/* Type Offset=724 */

	/* Return value */

/* 2832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2834 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyTo */

/* 2838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2844 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2846 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2852 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2854 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2858 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ciidExclude */

/* 2862 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2864 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgiidExclude */

/* 2868 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2870 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2872 */	NdrFcShort( 0x312 ),	/* Type Offset=786 */

	/* Parameter snbExclude */

/* 2874 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2876 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2878 */	NdrFcShort( 0x308 ),	/* Type Offset=776 */

	/* Parameter pstgDest */

/* 2880 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2882 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2884 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Return value */

/* 2886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2888 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MoveElementTo */

/* 2892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2900 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2906 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2908 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 2916 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2918 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2920 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter pstgDest */

/* 2922 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2924 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2926 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Parameter pwcsNewName */

/* 2928 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2930 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2932 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter grfFlags */

/* 2934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2936 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2942 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Commit */

/* 2946 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2954 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2960 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2962 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfCommitFlags */

/* 2970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2972 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2978 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Revert */

/* 2982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2988 */	NdrFcShort( 0xa ),	/* 10 */
/* 2990 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2996 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2998 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3004 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3008 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteEnumElements */

/* 3012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3018 */	NdrFcShort( 0xb ),	/* 11 */
/* 3020 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3022 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3026 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3028 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3032 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3034 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter reserved1 */

/* 3036 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3038 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cbReserved2 */

/* 3042 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3044 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter reserved2 */

/* 3048 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3050 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3052 */	NdrFcShort( 0x2c4 ),	/* Type Offset=708 */

	/* Parameter reserved3 */

/* 3054 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3056 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppenum */

/* 3060 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3062 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3064 */	NdrFcShort( 0x2ae ),	/* Type Offset=686 */

	/* Return value */

/* 3066 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3068 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RenameElement */

/* 3072 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3074 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3078 */	NdrFcShort( 0xd ),	/* 13 */
/* 3080 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3086 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3088 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3094 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsOldName */

/* 3096 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3098 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3100 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter pwcsNewName */

/* 3102 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3106 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Return value */

/* 3108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetElementTimes */

/* 3114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3120 */	NdrFcShort( 0xe ),	/* 14 */
/* 3122 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3124 */	NdrFcShort( 0x84 ),	/* 132 */
/* 3126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3128 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3130 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 3138 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3142 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Parameter pctime */

/* 3144 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3148 */	NdrFcShort( 0x326 ),	/* Type Offset=806 */

	/* Parameter patime */

/* 3150 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3152 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3154 */	NdrFcShort( 0x326 ),	/* Type Offset=806 */

	/* Parameter pmtime */

/* 3156 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3160 */	NdrFcShort( 0x326 ),	/* Type Offset=806 */

	/* Return value */

/* 3162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3164 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetClass */

/* 3168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0xf ),	/* 15 */
/* 3176 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3178 */	NdrFcShort( 0x44 ),	/* 68 */
/* 3180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3182 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3184 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter clsid */

/* 3192 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 3194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3196 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 3198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStateBits */

/* 3204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3210 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3212 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3214 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 3220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfStateBits */

/* 3228 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter grfMask */

/* 3234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3242 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stat */

/* 3246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3252 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3254 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3260 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3262 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstatstg */

/* 3270 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3274 */	NdrFcShort( 0x252 ),	/* Type Offset=594 */

	/* Parameter grfStatFlag */

/* 3276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3278 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3284 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Load */

/* 3288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3294 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3296 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3302 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszFileName */

/* 3312 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3316 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter dwMode */

/* 3318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3326 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 3330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3336 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3338 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3344 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszFileName */

/* 3354 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3358 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Parameter fRemember */

/* 3360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveCompleted */

/* 3372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3386 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3388 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszFileName */

/* 3396 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3398 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3400 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Return value */

/* 3402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3404 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCurFile */

/* 3408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3422 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppszFileName */

/* 3432 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3436 */	NdrFcShort( 0x1ea ),	/* Type Offset=490 */

	/* Return value */

/* 3438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitNew */

/* 3444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3450 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3458 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStg */

/* 3468 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3472 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Return value */

/* 3474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Load */

/* 3480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3494 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStg */

/* 3504 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3508 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Return value */

/* 3510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 3516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3524 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3530 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3532 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStgSave */

/* 3540 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3544 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Parameter fSameAsLoad */

/* 3546 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3554 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveCompleted */

/* 3558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3570 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3572 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3574 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStgNew */

/* 3582 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3584 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3586 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Return value */

/* 3588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3590 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SwitchToFile */

/* 3594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3600 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3608 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3610 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszFile */

/* 3618 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3620 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3622 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Return value */

/* 3624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3626 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteReadAt */

/* 3630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3636 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3638 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3640 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3642 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3644 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 3646 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3648 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3652 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ulOffset */

/* 3654 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3656 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3658 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter pv */

/* 3660 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3664 */	NdrFcShort( 0x32e ),	/* Type Offset=814 */

	/* Parameter cb */

/* 3666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3668 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbRead */

/* 3672 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3674 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3680 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteFillAt */


	/* Procedure RemoteWriteAt */

/* 3684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3690 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3692 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3694 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3696 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3698 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3700 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3704 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3706 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ulOffset */


	/* Parameter ulOffset */

/* 3708 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3710 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3712 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter pv */


	/* Parameter pv */

/* 3714 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3716 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3718 */	NdrFcShort( 0x344 ),	/* Type Offset=836 */

	/* Parameter cb */


	/* Parameter cb */

/* 3720 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3722 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */


	/* Parameter pcbWritten */

/* 3726 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3728 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3734 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockRegion */

/* 3738 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3744 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3746 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3748 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3752 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 3754 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 3762 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3764 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3766 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter cb */

/* 3768 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3772 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter dwLockType */

/* 3774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3776 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3782 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlockRegion */

/* 3786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3794 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3796 */	NdrFcShort( 0x38 ),	/* 56 */
/* 3798 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3800 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 3802 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter libOffset */

/* 3810 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3814 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter cb */

/* 3816 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3818 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3820 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Parameter dwLockType */

/* 3822 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3824 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3830 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Stat */

/* 3834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3840 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3842 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3848 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3850 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pstatstg */

/* 3858 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 3860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3862 */	NdrFcShort( 0x252 ),	/* Type Offset=594 */

	/* Parameter grfStatFlag */

/* 3864 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3868 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteFillAppend */

/* 3876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3882 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3884 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3888 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3890 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3892 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3896 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pv */

/* 3900 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3904 */	NdrFcShort( 0x1f6 ),	/* Type Offset=502 */

	/* Parameter cb */

/* 3906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcbWritten */

/* 3912 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3914 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3920 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetFillSize */

/* 3924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3932 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3934 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3938 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3940 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ulSize */

/* 3948 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3950 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3952 */	NdrFcShort( 0x1c4 ),	/* Type Offset=452 */

	/* Return value */

/* 3954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Terminate */

/* 3960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3966 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3976 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bCanceled */

/* 3984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnProgress */

/* 3996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4002 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4004 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4006 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4010 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 4012 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwProgressCurrent */

/* 4020 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwProgressMaximum */

/* 4026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter fAccurate */

/* 4032 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter fOwner */

/* 4038 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4046 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ResetInitializerTimeout */


	/* Procedure WaitForWriteAccess */


	/* Procedure Lock */

/* 4050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4056 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4058 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4060 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4064 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4066 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4072 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwSecondsRemaining */


	/* Parameter dwTimeout */


	/* Parameter dwTimeout */

/* 4074 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4076 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 4080 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4082 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Wait */


	/* Procedure SuppressChanges */

/* 4086 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4088 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4092 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4094 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4096 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4100 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4102 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4108 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwFlags */


	/* Parameter res1 */

/* 4110 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4112 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwMilliseconds */


	/* Parameter res2 */

/* 4116 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4118 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4120 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 4122 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4124 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateStorageEx */

/* 4128 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4134 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4136 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4138 */	NdrFcShort( 0x5c ),	/* 92 */
/* 4140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4142 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 4144 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4146 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 4152 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4156 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter grfMode */

/* 4158 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4160 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stgfmt */

/* 4164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4166 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter grfAttrs */

/* 4170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4172 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 4176 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4178 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4180 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter ppstgOpen */

/* 4182 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4184 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4186 */	NdrFcShort( 0x350 ),	/* Type Offset=848 */

	/* Return value */

/* 4188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4190 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenStorageEx */

/* 4194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4200 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4202 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 4204 */	NdrFcShort( 0x5c ),	/* 92 */
/* 4206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4208 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 4210 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4212 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4216 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pwcsName */

/* 4218 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4222 */	NdrFcShort( 0x12a ),	/* Type Offset=298 */

	/* Parameter grfMode */

/* 4224 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stgfmt */

/* 4230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4232 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter grfAttrs */

/* 4236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4238 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 4242 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4244 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4246 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter ppstgOpen */

/* 4248 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4250 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4252 */	NdrFcShort( 0x35c ),	/* Type Offset=860 */

	/* Return value */

/* 4254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4256 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 4260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4266 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4268 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4272 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4274 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 4276 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4278 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4282 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 4284 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4286 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 4290 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 4292 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4294 */	NdrFcShort( 0x3bc ),	/* Type Offset=956 */

	/* Parameter pceltFetched */

/* 4296 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4298 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4304 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 4308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4314 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4322 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4324 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 4332 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4334 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4336 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Return value */

/* 4338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 4344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4350 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4352 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4356 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4358 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 4360 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4362 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 4368 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 4374 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 4376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4378 */	NdrFcShort( 0x412 ),	/* Type Offset=1042 */

	/* Parameter pceltFetched */

/* 4380 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4388 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 4392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4398 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4400 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4406 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4408 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 4416 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4420 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 4422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4424 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteOnDataChange */

/* 4428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4434 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4436 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4442 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4444 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4448 */	NdrFcShort( 0x1d ),	/* 29 */
/* 4450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFormatetc */

/* 4452 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4454 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4456 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Parameter pStgmed */

/* 4458 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4460 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4462 */	NdrFcShort( 0x442 ),	/* Type Offset=1090 */

	/* Return value */

/* 4464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteOnViewChange */

/* 4470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4476 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4478 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4480 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4484 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4486 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAspect */

/* 4494 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4496 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lindex */

/* 4500 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4502 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4508 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteOnSave */

/* 4512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4518 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4520 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4526 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4528 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4538 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteOnClose */

/* 4542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4548 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4554 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4556 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4558 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4564 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4568 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteOnLinkSrcChange */

/* 4572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4580 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4586 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4588 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4594 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmk */

/* 4596 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4598 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4600 */	NdrFcShort( 0x14a ),	/* Type Offset=330 */

	/* Return value */

/* 4602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4604 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetData */

/* 4608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4614 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4616 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4622 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4624 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4626 */	NdrFcShort( 0x1e ),	/* 30 */
/* 4628 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatetcIn */

/* 4632 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4634 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4636 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Parameter pRemoteMedium */

/* 4638 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 4640 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4642 */	NdrFcShort( 0x5e8 ),	/* Type Offset=1512 */

	/* Return value */

/* 4644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetDataHere */

/* 4650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4656 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4658 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4664 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4666 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4668 */	NdrFcShort( 0x21 ),	/* 33 */
/* 4670 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4672 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatetc */

/* 4674 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4676 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4678 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Parameter pRemoteMedium */

/* 4680 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 4682 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4684 */	NdrFcShort( 0x5e8 ),	/* Type Offset=1512 */

	/* Return value */

/* 4686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4688 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QueryGetData */

/* 4692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4698 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4706 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4708 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4712 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4714 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatetc */

/* 4716 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4718 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4720 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Return value */

/* 4722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4724 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCanonicalFormatEtc */

/* 4728 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4734 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4736 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4742 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4744 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 4746 */	NdrFcShort( 0x2 ),	/* 2 */
/* 4748 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4750 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatectIn */

/* 4752 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4754 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4756 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Parameter pformatetcOut */

/* 4758 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 4760 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4762 */	NdrFcShort( 0x3a6 ),	/* Type Offset=934 */

	/* Return value */

/* 4764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4766 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteSetData */

/* 4770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4776 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4778 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4782 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4784 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4786 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4790 */	NdrFcShort( 0x26 ),	/* 38 */
/* 4792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatetc */

/* 4794 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4796 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4798 */	NdrFcShort( 0x43e ),	/* Type Offset=1086 */

	/* Parameter pmedium */

/* 4800 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4804 */	NdrFcShort( 0x5fa ),	/* Type Offset=1530 */

	/* Parameter fRelease */

/* 4806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4808 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4814 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumFormatEtc */

/* 4818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4826 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4832 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 4834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDirection */

/* 4842 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppenumFormatEtc */

/* 4848 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4852 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Return value */

/* 4854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4856 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DAdvise */

/* 4860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4866 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4868 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4872 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4874 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4876 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 4878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4880 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatetc */

/* 4884 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4886 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4888 */	NdrFcShort( 0x3a6 ),	/* Type Offset=934 */

	/* Parameter advf */

/* 4890 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4892 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAdvSink */

/* 4896 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4898 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4900 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Parameter pdwConnection */

/* 4902 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4904 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4908 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4910 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DUnadvise */

/* 4914 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4916 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4920 */	NdrFcShort( 0xa ),	/* 10 */
/* 4922 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4928 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4930 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwConnection */

/* 4938 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4940 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4946 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumDAdvise */

/* 4950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4956 */	NdrFcShort( 0xb ),	/* 11 */
/* 4958 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4964 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4966 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenumAdvise */

/* 4974 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4978 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 4980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4982 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AsyncGetClassBits */

/* 4986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4992 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4994 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 4996 */	NdrFcShort( 0xa8 ),	/* 168 */
/* 4998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5000 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 5002 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rclsid */

/* 5010 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5012 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5014 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter pszTYPE */

/* 5016 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5020 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Parameter pszExt */

/* 5022 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5024 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5026 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Parameter dwFileVersionMS */

/* 5028 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5030 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwFileVersionLS */

/* 5034 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5036 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pszCodeBase */

/* 5040 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5042 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5044 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Parameter pbc */

/* 5046 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5048 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5050 */	NdrFcShort( 0x18c ),	/* Type Offset=396 */

	/* Parameter dwClassContext */

/* 5052 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5054 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 5058 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 5060 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5062 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Parameter flags */

/* 5064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5066 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5072 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 5074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExtractThumbnail */

/* 5076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5082 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5084 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5086 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5088 */	NdrFcShort( 0x40 ),	/* 64 */
/* 5090 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 5092 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 5094 */	NdrFcShort( 0x2 ),	/* 2 */
/* 5096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStg */

/* 5100 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5104 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Parameter ulLength */

/* 5106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ulHeight */

/* 5112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulOutputLength */

/* 5118 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5120 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pulOutputHeight */

/* 5124 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5126 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter phOutputBitmap */

/* 5130 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 5132 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5134 */	NdrFcShort( 0x628 ),	/* Type Offset=1576 */

	/* Return value */

/* 5136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5138 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnFileUpdated */

/* 5142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5148 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5150 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5156 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5158 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStg */

/* 5166 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5168 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5170 */	NdrFcShort( 0x2d8 ),	/* Type Offset=728 */

	/* Return value */

/* 5172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5174 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const objidl_MIDL_TYPE_FORMAT_STRING objidl__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x14 ),	/* Offset= 20 (24) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 20 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 22 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 24 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 30 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 32 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 34 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 36 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 38 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 40 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 42 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (6) */
/* 44 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 46 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 48 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 50 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 52 */	NdrFcShort( 0x2 ),	/* Offset= 2 (54) */
/* 54 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 56 */	NdrFcLong( 0x100 ),	/* 256 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 66 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 68 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 70 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 72 */	
			0x11, 0x0,	/* FC_RP */
/* 74 */	NdrFcShort( 0x8 ),	/* Offset= 8 (82) */
/* 76 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 82 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 84 */	NdrFcShort( 0x10 ),	/* 16 */
/* 86 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 88 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 90 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (76) */
			0x5b,		/* FC_END */
/* 94 */	
			0x11, 0x0,	/* FC_RP */
/* 96 */	NdrFcShort( 0x98 ),	/* Offset= 152 (248) */
/* 98 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 100 */	NdrFcShort( 0x2 ),	/* 2 */
/* 102 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 104 */	NdrFcShort( 0x4 ),	/* 4 */
/* 106 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 108 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 110 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 112 */	NdrFcShort( 0x2 ),	/* 2 */
/* 114 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 116 */	NdrFcShort( 0xc ),	/* 12 */
/* 118 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 120 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 122 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 124 */	NdrFcShort( 0x2 ),	/* 2 */
/* 126 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x57,		/* FC_ADD_1 */
/* 128 */	NdrFcShort( 0x14 ),	/* 20 */
/* 130 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 132 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 134 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 136 */	NdrFcShort( 0x1c ),	/* 28 */
/* 138 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 140 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	0x12, 0x0,	/* FC_UP */
/* 148 */	NdrFcShort( 0xffce ),	/* Offset= -50 (98) */
/* 150 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 154 */	NdrFcShort( 0x8 ),	/* 8 */
/* 156 */	0x12, 0x0,	/* FC_UP */
/* 158 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (110) */
/* 160 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 162 */	NdrFcShort( 0x10 ),	/* 16 */
/* 164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 166 */	0x12, 0x0,	/* FC_UP */
/* 168 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (122) */
/* 170 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 172 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 174 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 176 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 178 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 180 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 182 */	NdrFcShort( 0x1c ),	/* 28 */
/* 184 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 186 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 192 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 194 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 196 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 198 */	NdrFcShort( 0x14 ),	/* 20 */
/* 200 */	NdrFcShort( 0x14 ),	/* 20 */
/* 202 */	0x12, 0x0,	/* FC_UP */
/* 204 */	NdrFcShort( 0xffba ),	/* Offset= -70 (134) */
/* 206 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 208 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 210 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 212 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 214 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 216 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 218 */	NdrFcShort( 0x10 ),	/* 16 */
/* 220 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 222 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 224 */	NdrFcShort( 0x4 ),	/* 4 */
/* 226 */	NdrFcShort( 0x4 ),	/* 4 */
/* 228 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 230 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 232 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 238 */	0x12, 0x0,	/* FC_UP */
/* 240 */	NdrFcShort( 0xffc4 ),	/* Offset= -60 (180) */
/* 242 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 244 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 246 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 248 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 250 */	NdrFcShort( 0x20 ),	/* 32 */
/* 252 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 254 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 256 */	NdrFcShort( 0x1c ),	/* 28 */
/* 258 */	NdrFcShort( 0x1c ),	/* 28 */
/* 260 */	0x12, 0x0,	/* FC_UP */
/* 262 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (216) */
/* 264 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 266 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 268 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 270 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 272 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 274 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 276 */	NdrFcShort( 0x2 ),	/* Offset= 2 (278) */
/* 278 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 280 */	NdrFcLong( 0x10 ),	/* 16 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 290 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 292 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 294 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 296 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 298 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 300 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 302 */	NdrFcShort( 0xfed8 ),	/* Offset= -296 (6) */
/* 304 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 306 */	NdrFcShort( 0x2 ),	/* Offset= 2 (308) */
/* 308 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 310 */	NdrFcLong( 0x101 ),	/* 257 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 320 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 322 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 324 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 326 */	
			0x11, 0x0,	/* FC_RP */
/* 328 */	NdrFcShort( 0x14 ),	/* Offset= 20 (348) */
/* 330 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 332 */	NdrFcLong( 0xf ),	/* 15 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 342 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 344 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 346 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 348 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 356 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 358 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 360 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 362 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 364 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 366 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (330) */
/* 368 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 370 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 372 */	NdrFcShort( 0x2 ),	/* Offset= 2 (374) */
/* 374 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 376 */	NdrFcLong( 0x102 ),	/* 258 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 386 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 388 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 390 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 392 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 394 */	NdrFcShort( 0xfec8 ),	/* Offset= -312 (82) */
/* 396 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 398 */	NdrFcLong( 0xe ),	/* 14 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 408 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 410 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 412 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 414 */	
			0x11, 0x0,	/* FC_RP */
/* 416 */	NdrFcShort( 0x2 ),	/* Offset= 2 (418) */
/* 418 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 420 */	NdrFcShort( 0x8 ),	/* 8 */
/* 422 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 424 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 426 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 428 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (418) */
/* 430 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 432 */	NdrFcLong( 0xc ),	/* 12 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 440 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 442 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 444 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 446 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 448 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 450 */	NdrFcShort( 0x2 ),	/* Offset= 2 (452) */
/* 452 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 456 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 458 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 460 */	NdrFcShort( 0x2 ),	/* Offset= 2 (462) */
/* 462 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 464 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 468 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 470 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 472 */	NdrFcShort( 0x2 ),	/* Offset= 2 (474) */
/* 474 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 476 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 480 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 482 */	
			0x12, 0x14,	/* FC_UP [alloced_on_stack] [pointer_deref] */
/* 484 */	NdrFcShort( 0xff66 ),	/* Offset= -154 (330) */
/* 486 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 488 */	NdrFcShort( 0xff62 ),	/* Offset= -158 (330) */
/* 490 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 492 */	NdrFcShort( 0x2 ),	/* Offset= 2 (494) */
/* 494 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 496 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 498 */	
			0x11, 0x0,	/* FC_RP */
/* 500 */	NdrFcShort( 0x2 ),	/* Offset= 2 (502) */
/* 502 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 504 */	NdrFcShort( 0x1 ),	/* 1 */
/* 506 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 510 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 512 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 514 */	
			0x11, 0x0,	/* FC_RP */
/* 516 */	NdrFcShort( 0x2 ),	/* Offset= 2 (518) */
/* 518 */	
			0x1c,		/* FC_CVARRAY */
			0x3,		/* 3 */
/* 520 */	NdrFcShort( 0x4 ),	/* 4 */
/* 522 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 524 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 526 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 528 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 530 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 532 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 534 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 536 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x4a,		/* FC_VARIABLE_OFFSET */
/* 538 */	NdrFcShort( 0x4 ),	/* 4 */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x1 ),	/* 1 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 550 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 552 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 554 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 556 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 558 */	NdrFcShort( 0x2 ),	/* Offset= 2 (560) */
/* 560 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 562 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 564 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 566 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 568 */	
			0x11, 0x0,	/* FC_RP */
/* 570 */	NdrFcShort( 0x2 ),	/* Offset= 2 (572) */
/* 572 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 574 */	NdrFcShort( 0x1 ),	/* 1 */
/* 576 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 580 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 582 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 584 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 586 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 588 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 590 */	
			0x11, 0x0,	/* FC_RP */
/* 592 */	NdrFcShort( 0x2 ),	/* Offset= 2 (594) */
/* 594 */	
			0x16,		/* FC_PSTRUCT */
			0x7,		/* 7 */
/* 596 */	NdrFcShort( 0x48 ),	/* 72 */
/* 598 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 600 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 608 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 610 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 612 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 614 */	0x0,		/* 0 */
			NdrFcShort( 0xff5d ),	/* Offset= -163 (452) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 618 */	0x0,		/* 0 */
			NdrFcShort( 0xff37 ),	/* Offset= -201 (418) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 622 */	0x0,		/* 0 */
			NdrFcShort( 0xff33 ),	/* Offset= -205 (418) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 626 */	0x0,		/* 0 */
			NdrFcShort( 0xff2f ),	/* Offset= -209 (418) */
			0x8,		/* FC_LONG */
/* 630 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 632 */	0x0,		/* 0 */
			NdrFcShort( 0xfdd9 ),	/* Offset= -551 (82) */
			0x8,		/* FC_LONG */
/* 636 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 638 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 640 */	NdrFcShort( 0xff2e ),	/* Offset= -210 (430) */
/* 642 */	
			0x11, 0x0,	/* FC_RP */
/* 644 */	NdrFcShort( 0x2 ),	/* Offset= 2 (646) */
/* 646 */	
			0x1c,		/* FC_CVARRAY */
			0x7,		/* 7 */
/* 648 */	NdrFcShort( 0x48 ),	/* 72 */
/* 650 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 652 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 654 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 656 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 658 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 660 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 662 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 664 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x4a,		/* FC_VARIABLE_OFFSET */
/* 666 */	NdrFcShort( 0x48 ),	/* 72 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x1 ),	/* 1 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 678 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 680 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 682 */	0x0,		/* 0 */
			NdrFcShort( 0xffa7 ),	/* Offset= -89 (594) */
			0x5b,		/* FC_END */
/* 686 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 688 */	NdrFcShort( 0x2 ),	/* Offset= 2 (690) */
/* 690 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 692 */	NdrFcLong( 0xd ),	/* 13 */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 702 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 704 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 706 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 708 */	
			0x12, 0x0,	/* FC_UP */
/* 710 */	NdrFcShort( 0x2 ),	/* Offset= 2 (712) */
/* 712 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 714 */	NdrFcShort( 0x1 ),	/* 1 */
/* 716 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 718 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 720 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 722 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 724 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 726 */	NdrFcShort( 0x2 ),	/* Offset= 2 (728) */
/* 728 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 730 */	NdrFcLong( 0xb ),	/* 11 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 740 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 742 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 744 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 746 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 748 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 750 */	
			0x12, 0x0,	/* FC_UP */
/* 752 */	NdrFcShort( 0xe ),	/* Offset= 14 (766) */
/* 754 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 756 */	NdrFcShort( 0x2 ),	/* 2 */
/* 758 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 760 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 762 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 764 */	0x5,		/* FC_WCHAR */
			0x5b,		/* FC_END */
/* 766 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (754) */
/* 772 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 774 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 776 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x4 ),	/* 4 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0xffde ),	/* Offset= -34 (750) */
/* 786 */	
			0x12, 0x0,	/* FC_UP */
/* 788 */	NdrFcShort( 0x2 ),	/* Offset= 2 (790) */
/* 790 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 792 */	NdrFcShort( 0x10 ),	/* 16 */
/* 794 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 796 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 798 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 800 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 802 */	NdrFcShort( 0xfd30 ),	/* Offset= -720 (82) */
/* 804 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 806 */	
			0x12, 0x0,	/* FC_UP */
/* 808 */	NdrFcShort( 0xfe7a ),	/* Offset= -390 (418) */
/* 810 */	
			0x11, 0x0,	/* FC_RP */
/* 812 */	NdrFcShort( 0x2 ),	/* Offset= 2 (814) */
/* 814 */	
			0x1c,		/* FC_CVARRAY */
			0x0,		/* 0 */
/* 816 */	NdrFcShort( 0x1 ),	/* 1 */
/* 818 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 820 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 822 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 824 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 826 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 828 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 830 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 832 */	
			0x11, 0x0,	/* FC_RP */
/* 834 */	NdrFcShort( 0x2 ),	/* Offset= 2 (836) */
/* 836 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 838 */	NdrFcShort( 0x1 ),	/* 1 */
/* 840 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 842 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 844 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 846 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 848 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 850 */	NdrFcShort( 0x2 ),	/* Offset= 2 (852) */
/* 852 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 854 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 856 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 858 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 860 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 862 */	NdrFcShort( 0x2 ),	/* Offset= 2 (864) */
/* 864 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 866 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 868 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 870 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 872 */	
			0x11, 0x0,	/* FC_RP */
/* 874 */	NdrFcShort( 0x52 ),	/* Offset= 82 (956) */
/* 876 */	
			0x13, 0x0,	/* FC_OP */
/* 878 */	NdrFcShort( 0x2 ),	/* Offset= 2 (880) */
/* 880 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 882 */	NdrFcShort( 0x4 ),	/* 4 */
/* 884 */	NdrFcShort( 0x2 ),	/* 2 */
/* 886 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 890 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 892 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 896 */	NdrFcShort( 0xfe6e ),	/* Offset= -402 (494) */
/* 898 */	NdrFcShort( 0xffff ),	/* Offset= -1 (897) */
/* 900 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 902 */	NdrFcShort( 0x1 ),	/* 1 */
/* 904 */	NdrFcShort( 0x2 ),	/* 2 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (876) */
/* 910 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 912 */	NdrFcShort( 0x1 ),	/* 1 */
/* 914 */	0x0,		/* Corr desc:  field,  */
			0x59,		/* FC_CALLBACK */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 920 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 922 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 924 */	NdrFcShort( 0xc ),	/* 12 */
/* 926 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (910) */
/* 928 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 930 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 932 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 934 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 936 */	NdrFcShort( 0x14 ),	/* 20 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0xc ),	/* Offset= 12 (952) */
/* 942 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 944 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (900) */
/* 946 */	0x3e,		/* FC_STRUCTPAD2 */
			0x36,		/* FC_POINTER */
/* 948 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 950 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 952 */	
			0x13, 0x0,	/* FC_OP */
/* 954 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (922) */
/* 956 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 962 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 964 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 966 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 970 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 972 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 974 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (934) */
/* 976 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 978 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 980 */	NdrFcShort( 0x2 ),	/* Offset= 2 (982) */
/* 982 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 984 */	NdrFcLong( 0x103 ),	/* 259 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 992 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 994 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 996 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 998 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1000 */	
			0x11, 0x0,	/* FC_RP */
/* 1002 */	NdrFcShort( 0x28 ),	/* Offset= 40 (1042) */
/* 1004 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1006 */	NdrFcLong( 0x10f ),	/* 271 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1016 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1018 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1020 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1022 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1024 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0xe ),	/* Offset= 14 (1042) */
/* 1030 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1032 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (934) */
/* 1034 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1036 */	0x0,		/* 0 */
			NdrFcShort( 0xffdf ),	/* Offset= -33 (1004) */
			0x8,		/* FC_LONG */
/* 1040 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1042 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1048 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1050 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1052 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1054 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1056 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1058 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1060 */	NdrFcShort( 0xffda ),	/* Offset= -38 (1022) */
/* 1062 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1064 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1066 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1068) */
/* 1068 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1070 */	NdrFcLong( 0x105 ),	/* 261 */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1080 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1082 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1084 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1086 */	
			0x12, 0x0,	/* FC_UP */
/* 1088 */	NdrFcShort( 0xff66 ),	/* Offset= -154 (934) */
/* 1090 */	
			0x12, 0x0,	/* FC_UP */
/* 1092 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1494) */
/* 1094 */	
			0x12, 0x0,	/* FC_UP */
/* 1096 */	NdrFcShort( 0x17c ),	/* Offset= 380 (1476) */
/* 1098 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 1100 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1108 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1108) */
/* 1110 */	NdrFcLong( 0x20 ),	/* 32 */
/* 1114 */	NdrFcShort( 0x28 ),	/* Offset= 40 (1154) */
/* 1116 */	NdrFcLong( 0x40 ),	/* 64 */
/* 1120 */	NdrFcShort( 0x8c ),	/* Offset= 140 (1260) */
/* 1122 */	NdrFcLong( 0x10 ),	/* 16 */
/* 1126 */	NdrFcShort( 0xa4 ),	/* Offset= 164 (1290) */
/* 1128 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1132 */	NdrFcShort( 0x12c ),	/* Offset= 300 (1432) */
/* 1134 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1138 */	NdrFcShort( 0xfe78 ),	/* Offset= -392 (746) */
/* 1140 */	NdrFcLong( 0x4 ),	/* 4 */
/* 1144 */	NdrFcShort( 0x46 ),	/* Offset= 70 (1214) */
/* 1146 */	NdrFcLong( 0x8 ),	/* 8 */
/* 1150 */	NdrFcShort( 0x40 ),	/* Offset= 64 (1214) */
/* 1152 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1151) */
/* 1154 */	
			0x12, 0x0,	/* FC_UP */
/* 1156 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1158) */
/* 1158 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 1160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1162 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1164 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 1168 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1170 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 1174 */	NdrFcShort( 0xa ),	/* Offset= 10 (1184) */
/* 1176 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 1180 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1182 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1181) */
/* 1184 */	
			0x12, 0x0,	/* FC_UP */
/* 1186 */	NdrFcShort( 0x34 ),	/* Offset= 52 (1238) */
/* 1188 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 1190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1192 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1194 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 1198 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1200 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 1204 */	NdrFcShort( 0xa ),	/* Offset= 10 (1214) */
/* 1206 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 1210 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1212 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1211) */
/* 1214 */	
			0x12, 0x0,	/* FC_UP */
/* 1216 */	NdrFcShort( 0xe ),	/* Offset= 14 (1230) */
/* 1218 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1220 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1222 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 1224 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 1226 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1228 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1230 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 1232 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1234 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1218) */
/* 1236 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1238 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1240 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1242 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1244 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1246 */	NdrFcShort( 0xc ),	/* 12 */
/* 1248 */	NdrFcShort( 0xc ),	/* 12 */
/* 1250 */	0x12, 0x0,	/* FC_UP */
/* 1252 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (1188) */
/* 1254 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1256 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1258 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1260 */	
			0x12, 0x0,	/* FC_UP */
/* 1262 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1264) */
/* 1264 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 1266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1268 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1270 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 1274 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1276 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 1280 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (1214) */
/* 1282 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 1286 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1288 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1287) */
/* 1290 */	
			0x12, 0x0,	/* FC_UP */
/* 1292 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1294) */
/* 1294 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 1296 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1298 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1300 */	NdrFcLong( 0x7 ),	/* 7 */
/* 1304 */	NdrFcShort( 0xa ),	/* Offset= 10 (1314) */
/* 1306 */	NdrFcLong( 0x5 ),	/* 5 */
/* 1310 */	NdrFcShort( 0x34 ),	/* Offset= 52 (1362) */
/* 1312 */	NdrFcShort( 0x78 ),	/* Offset= 120 (1432) */
/* 1314 */	
			0x12, 0x0,	/* FC_UP */
/* 1316 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1318) */
/* 1318 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 1320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1322 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1324 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 1328 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1330 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 1334 */	NdrFcShort( 0xa ),	/* Offset= 10 (1344) */
/* 1336 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 1340 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1342 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1341) */
/* 1344 */	
			0x12, 0x0,	/* FC_UP */
/* 1346 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1348) */
/* 1348 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 1350 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1352 */	NdrFcShort( 0xff7a ),	/* Offset= -134 (1218) */
/* 1354 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1356 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1358 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1360 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1362 */	
			0x12, 0x0,	/* FC_UP */
/* 1364 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1366) */
/* 1366 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 1368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1370 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1372 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 1376 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1378 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 1382 */	NdrFcShort( 0xa ),	/* Offset= 10 (1392) */
/* 1384 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 1388 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1390 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1389) */
/* 1392 */	
			0x12, 0x0,	/* FC_UP */
/* 1394 */	NdrFcShort( 0x1c ),	/* Offset= 28 (1422) */
/* 1396 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 1398 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1400 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 1402 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 1404 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1406 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 1408 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1410 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1412 */	NdrFcShort( 0xfffe ),	/* -2 */
/* 1414 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1416 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1418 */	NdrFcShort( 0xffea ),	/* Offset= -22 (1396) */
/* 1420 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1422 */	
			0x17,		/* FC_CSTRUCT */
			0x1,		/* 1 */
/* 1424 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1426 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1406) */
/* 1428 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1430 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1432 */	
			0x12, 0x0,	/* FC_UP */
/* 1434 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1436) */
/* 1436 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 1438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1440 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1442 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 1446 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1448 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 1452 */	NdrFcShort( 0xa ),	/* Offset= 10 (1462) */
/* 1454 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 1458 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 1460 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1459) */
/* 1462 */	
			0x12, 0x0,	/* FC_UP */
/* 1464 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1466) */
/* 1466 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 1468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1470 */	NdrFcShort( 0xff04 ),	/* Offset= -252 (1218) */
/* 1472 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1474 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1476 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1478 */	NdrFcShort( 0xc ),	/* 12 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0xc ),	/* Offset= 12 (1494) */
/* 1484 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1486 */	NdrFcShort( 0xfe7c ),	/* Offset= -388 (1098) */
/* 1488 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1490 */	NdrFcShort( 0xfa34 ),	/* Offset= -1484 (6) */
/* 1492 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1494 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1496 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1498 */	NdrFcShort( 0xc ),	/* 12 */
/* 1500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1502 */	NdrFcShort( 0xfe68 ),	/* Offset= -408 (1094) */
/* 1504 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1506 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1512) */
/* 1508 */	
			0x13, 0x0,	/* FC_OP */
/* 1510 */	NdrFcShort( 0xffde ),	/* Offset= -34 (1476) */
/* 1512 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1514 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1516 */	NdrFcShort( 0xc ),	/* 12 */
/* 1518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1520 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1508) */
/* 1522 */	
			0x11, 0x0,	/* FC_RP */
/* 1524 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1512) */
/* 1526 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1528 */	NdrFcShort( 0xfdae ),	/* Offset= -594 (934) */
/* 1530 */	
			0x12, 0x0,	/* FC_UP */
/* 1532 */	NdrFcShort( 0x16 ),	/* Offset= 22 (1554) */
/* 1534 */	
			0x12, 0x0,	/* FC_UP */
/* 1536 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1538) */
/* 1538 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1540 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1544) */
/* 1546 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1548 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1550 */	NdrFcShort( 0xffb6 ),	/* Offset= -74 (1476) */
/* 1552 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1554 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1556 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1558 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (1534) */
/* 1564 */	
			0x11, 0x0,	/* FC_RP */
/* 1566 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (934) */
/* 1568 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1570 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1576) */
/* 1572 */	
			0x13, 0x0,	/* FC_OP */
/* 1574 */	NdrFcShort( 0xff00 ),	/* Offset= -256 (1318) */
/* 1576 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1578 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1580 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1572) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            SNB_UserSize
            ,SNB_UserMarshal
            ,SNB_UserUnmarshal
            ,SNB_UserFree
            },
            {
            CLIPFORMAT_UserSize
            ,CLIPFORMAT_UserMarshal
            ,CLIPFORMAT_UserUnmarshal
            ,CLIPFORMAT_UserFree
            },
            {
            ASYNC_STGMEDIUM_UserSize
            ,ASYNC_STGMEDIUM_UserMarshal
            ,ASYNC_STGMEDIUM_UserUnmarshal
            ,ASYNC_STGMEDIUM_UserFree
            },
            {
            STGMEDIUM_UserSize
            ,STGMEDIUM_UserMarshal
            ,STGMEDIUM_UserUnmarshal
            ,STGMEDIUM_UserFree
            },
            {
            FLAG_STGMEDIUM_UserSize
            ,FLAG_STGMEDIUM_UserMarshal
            ,FLAG_STGMEDIUM_UserUnmarshal
            ,FLAG_STGMEDIUM_UserFree
            },
            {
            HBITMAP_UserSize
            ,HBITMAP_UserMarshal
            ,HBITMAP_UserUnmarshal
            ,HBITMAP_UserFree
            }

        };


static void __RPC_USER IEnumFORMATETC_DVTARGETDEVICEExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{
    DVTARGETDEVICE *pS	=	( DVTARGETDEVICE * )(( pStubMsg->StackTop - 12 ) );
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = ( unsigned long ) ( ( ( pS->tdSize - sizeof( DWORD  ) )  - ( 4 * sizeof( WORD  ) )  )  );
}

static const EXPR_EVAL ExprEvalRoutines[] = 
    {
    IEnumFORMATETC_DVTARGETDEVICEExprEval_0000
    };



/* Standard interface: __MIDL_itf_objidl_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMarshal, ver. 0.0,
   GUID={0x00000003,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMarshal2, ver. 0.0,
   GUID={0x000001cf,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IStdMarshalInfo, ver. 0.0,
   GUID={0x00000018,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IExternalConnection, ver. 0.0,
   GUID={0x00000019,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMultiQI, ver. 0.0,
   GUID={0x00000020,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMalloc, ver. 0.0,
   GUID={0x00000002,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMallocSpy, ver. 0.0,
   GUID={0x0000001d,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IInternalUnknown, ver. 0.0,
   GUID={0x00000021,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IEnumUnknown, ver. 0.0,
   GUID={0x00000100,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumUnknown_FormatStringOffsetTable[] =
    {
    0,
    48,
    84,
    114
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumUnknown_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumUnknown_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumUnknown_StubThunkTable[] = 
    {
    IEnumUnknown_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumUnknown_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumUnknown_FormatStringOffsetTable[-3],
    &IEnumUnknown_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumUnknownProxyVtbl = 
{
    &IEnumUnknown_ProxyInfo,
    &IID_IEnumUnknown,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumUnknown_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumUnknown::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumUnknown::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumUnknown::Clone */
};

const CInterfaceStubVtbl _IEnumUnknownStubVtbl =
{
    &IID_IEnumUnknown,
    &IEnumUnknown_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISurrogate, ver. 1.0,
   GUID={0x00000022,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ISurrogate_FormatStringOffsetTable[] =
    {
    150,
    186
    };

static const MIDL_STUBLESS_PROXY_INFO ISurrogate_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &ISurrogate_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISurrogate_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &ISurrogate_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _ISurrogateProxyVtbl = 
{
    &ISurrogate_ProxyInfo,
    &IID_ISurrogate,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ISurrogate::LoadDllServer */ ,
    (void *) (INT_PTR) -1 /* ISurrogate::FreeSurrogate */
};

const CInterfaceStubVtbl _ISurrogateStubVtbl =
{
    &IID_ISurrogate,
    &ISurrogate_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IGlobalInterfaceTable, ver. 0.0,
   GUID={0x00000146,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IBindCtx, ver. 0.0,
   GUID={0x0000000e,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IBindCtx_FormatStringOffsetTable[] =
    {
    216,
    252,
    84,
    288,
    324,
    360,
    396,
    438,
    480,
    516
    };

static const MIDL_STUBLESS_PROXY_INFO IBindCtx_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IBindCtx_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IBindCtx_StubThunkTable[] = 
    {
    0,
    0,
    0,
    IBindCtx_RemoteSetBindOptions_Thunk,
    IBindCtx_RemoteGetBindOptions_Thunk,
    0,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IBindCtx_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IBindCtx_FormatStringOffsetTable[-3],
    &IBindCtx_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IBindCtxProxyVtbl = 
{
    &IBindCtx_ProxyInfo,
    &IID_IBindCtx,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IBindCtx::RegisterObjectBound */ ,
    (void *) (INT_PTR) -1 /* IBindCtx::RevokeObjectBound */ ,
    (void *) (INT_PTR) -1 /* IBindCtx::ReleaseBoundObjects */ ,
    IBindCtx_SetBindOptions_Proxy ,
    IBindCtx_GetBindOptions_Proxy ,
    (void *) (INT_PTR) -1 /* IBindCtx::GetRunningObjectTable */ ,
    (void *) (INT_PTR) -1 /* IBindCtx::RegisterObjectParam */ ,
    (void *) (INT_PTR) -1 /* IBindCtx::GetObjectParam */ ,
    (void *) (INT_PTR) -1 /* IBindCtx::EnumObjectParam */ ,
    (void *) (INT_PTR) -1 /* IBindCtx::RevokeObjectParam */
};

const CInterfaceStubVtbl _IBindCtxStubVtbl =
{
    &IID_IBindCtx,
    &IBindCtx_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumMoniker, ver. 0.0,
   GUID={0x00000102,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumMoniker_FormatStringOffsetTable[] =
    {
    552,
    48,
    84,
    600
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumMoniker_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumMoniker_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumMoniker_StubThunkTable[] = 
    {
    IEnumMoniker_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumMoniker_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumMoniker_FormatStringOffsetTable[-3],
    &IEnumMoniker_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumMonikerProxyVtbl = 
{
    &IEnumMoniker_ProxyInfo,
    &IID_IEnumMoniker,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumMoniker_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumMoniker::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumMoniker::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumMoniker::Clone */
};

const CInterfaceStubVtbl _IEnumMonikerStubVtbl =
{
    &IID_IEnumMoniker,
    &IEnumMoniker_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRunnableObject, ver. 0.0,
   GUID={0x00000126,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IRunnableObject_FormatStringOffsetTable[] =
    {
    636,
    672,
    84,
    708,
    750
    };

static const MIDL_STUBLESS_PROXY_INFO IRunnableObject_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IRunnableObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IRunnableObject_StubThunkTable[] = 
    {
    0,
    0,
    IRunnableObject_RemoteIsRunning_Thunk,
    0,
    0
    };

static const MIDL_SERVER_INFO IRunnableObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IRunnableObject_FormatStringOffsetTable[-3],
    &IRunnableObject_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IRunnableObjectProxyVtbl = 
{
    &IRunnableObject_ProxyInfo,
    &IID_IRunnableObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRunnableObject::GetRunningClass */ ,
    (void *) (INT_PTR) -1 /* IRunnableObject::Run */ ,
    IRunnableObject_IsRunning_Proxy ,
    (void *) (INT_PTR) -1 /* IRunnableObject::LockRunning */ ,
    (void *) (INT_PTR) -1 /* IRunnableObject::SetContainedObject */
};

const CInterfaceStubVtbl _IRunnableObjectStubVtbl =
{
    &IID_IRunnableObject,
    &IRunnableObject_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_objidl_0000_0014, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IRunningObjectTable, ver. 0.0,
   GUID={0x00000010,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IRunningObjectTable_FormatStringOffsetTable[] =
    {
    786,
    48,
    840,
    876,
    918,
    960,
    1002
    };

static const MIDL_STUBLESS_PROXY_INFO IRunningObjectTable_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IRunningObjectTable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRunningObjectTable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IRunningObjectTable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IRunningObjectTableProxyVtbl = 
{
    &IRunningObjectTable_ProxyInfo,
    &IID_IRunningObjectTable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRunningObjectTable::Register */ ,
    (void *) (INT_PTR) -1 /* IRunningObjectTable::Revoke */ ,
    (void *) (INT_PTR) -1 /* IRunningObjectTable::IsRunning */ ,
    (void *) (INT_PTR) -1 /* IRunningObjectTable::GetObject */ ,
    (void *) (INT_PTR) -1 /* IRunningObjectTable::NoteChangeTime */ ,
    (void *) (INT_PTR) -1 /* IRunningObjectTable::GetTimeOfLastChange */ ,
    (void *) (INT_PTR) -1 /* IRunningObjectTable::EnumRunning */
};

const CInterfaceStubVtbl _IRunningObjectTableStubVtbl =
{
    &IID_IRunningObjectTable,
    &IRunningObjectTable_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPersist, ver. 0.0,
   GUID={0x0000010c,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IPersist_FormatStringOffsetTable[] =
    {
    636
    };

static const MIDL_STUBLESS_PROXY_INFO IPersist_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IPersist_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPersist_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IPersist_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IPersistProxyVtbl = 
{
    &IPersist_ProxyInfo,
    &IID_IPersist,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPersist::GetClassID */
};

const CInterfaceStubVtbl _IPersistStubVtbl =
{
    &IID_IPersist,
    &IPersist_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPersistStream, ver. 0.0,
   GUID={0x00000109,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IPersistStream_FormatStringOffsetTable[] =
    {
    636,
    186,
    1038,
    1074,
    1116
    };

static const MIDL_STUBLESS_PROXY_INFO IPersistStream_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IPersistStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPersistStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IPersistStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IPersistStreamProxyVtbl = 
{
    &IPersistStream_ProxyInfo,
    &IID_IPersistStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPersist::GetClassID */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::IsDirty */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::Load */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::Save */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::GetSizeMax */
};

const CInterfaceStubVtbl _IPersistStreamStubVtbl =
{
    &IID_IPersistStream,
    &IPersistStream_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IMoniker, ver. 0.0,
   GUID={0x0000000f,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IMoniker_FormatStringOffsetTable[] =
    {
    636,
    186,
    1038,
    1074,
    1116,
    1152,
    1206,
    1260,
    1314,
    1362,
    1404,
    1440,
    1476,
    1524,
    1572,
    1608,
    1650,
    1692,
    1740,
    1800
    };

static const MIDL_STUBLESS_PROXY_INFO IMoniker_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IMoniker_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IMoniker_StubThunkTable[] = 
    {
    0,
    0,
    0,
    0,
    0,
    IMoniker_RemoteBindToObject_Thunk,
    IMoniker_RemoteBindToStorage_Thunk,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IMoniker_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IMoniker_FormatStringOffsetTable[-3],
    &IMoniker_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(23) _IMonikerProxyVtbl = 
{
    &IMoniker_ProxyInfo,
    &IID_IMoniker,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPersist::GetClassID */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::IsDirty */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::Load */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::Save */ ,
    (void *) (INT_PTR) -1 /* IPersistStream::GetSizeMax */ ,
    IMoniker_BindToObject_Proxy ,
    IMoniker_BindToStorage_Proxy ,
    (void *) (INT_PTR) -1 /* IMoniker::Reduce */ ,
    (void *) (INT_PTR) -1 /* IMoniker::ComposeWith */ ,
    (void *) (INT_PTR) -1 /* IMoniker::Enum */ ,
    (void *) (INT_PTR) -1 /* IMoniker::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IMoniker::Hash */ ,
    (void *) (INT_PTR) -1 /* IMoniker::IsRunning */ ,
    (void *) (INT_PTR) -1 /* IMoniker::GetTimeOfLastChange */ ,
    (void *) (INT_PTR) -1 /* IMoniker::Inverse */ ,
    (void *) (INT_PTR) -1 /* IMoniker::CommonPrefixWith */ ,
    (void *) (INT_PTR) -1 /* IMoniker::RelativePathTo */ ,
    (void *) (INT_PTR) -1 /* IMoniker::GetDisplayName */ ,
    (void *) (INT_PTR) -1 /* IMoniker::ParseDisplayName */ ,
    (void *) (INT_PTR) -1 /* IMoniker::IsSystemMoniker */
};

const CInterfaceStubVtbl _IMonikerStubVtbl =
{
    &IID_IMoniker,
    &IMoniker_ServerInfo,
    23,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IROTData, ver. 0.0,
   GUID={0xf29f6bc0,0x5021,0x11ce,{0xaa,0x15,0x00,0x00,0x69,0x01,0x29,0x3f}} */

#pragma code_seg(".orpc")
static const unsigned short IROTData_FormatStringOffsetTable[] =
    {
    1836
    };

static const MIDL_STUBLESS_PROXY_INFO IROTData_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IROTData_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IROTData_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IROTData_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IROTDataProxyVtbl = 
{
    &IROTData_ProxyInfo,
    &IID_IROTData,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IROTData::GetComparisonData */
};

const CInterfaceStubVtbl _IROTDataStubVtbl =
{
    &IID_IROTData,
    &IROTData_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumString, ver. 0.0,
   GUID={0x00000101,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumString_FormatStringOffsetTable[] =
    {
    1884,
    48,
    84,
    1932
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumString_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumString_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumString_StubThunkTable[] = 
    {
    IEnumString_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumString_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumString_FormatStringOffsetTable[-3],
    &IEnumString_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumStringProxyVtbl = 
{
    &IEnumString_ProxyInfo,
    &IID_IEnumString,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumString_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumString::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumString::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumString::Clone */
};

const CInterfaceStubVtbl _IEnumStringStubVtbl =
{
    &IID_IEnumString,
    &IEnumString_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IClassActivator, ver. 0.0,
   GUID={0x00000140,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IClassActivator_FormatStringOffsetTable[] =
    {
    1968
    };

static const MIDL_STUBLESS_PROXY_INFO IClassActivator_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IClassActivator_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IClassActivator_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IClassActivator_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IClassActivatorProxyVtbl = 
{
    &IClassActivator_ProxyInfo,
    &IID_IClassActivator,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IClassActivator::GetClassObject */
};

const CInterfaceStubVtbl _IClassActivatorStubVtbl =
{
    &IID_IClassActivator,
    &IClassActivator_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISequentialStream, ver. 0.0,
   GUID={0x0c733a30,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}} */

#pragma code_seg(".orpc")
static const unsigned short ISequentialStream_FormatStringOffsetTable[] =
    {
    2028,
    2076
    };

static const MIDL_STUBLESS_PROXY_INFO ISequentialStream_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &ISequentialStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK ISequentialStream_StubThunkTable[] = 
    {
    ISequentialStream_RemoteRead_Thunk,
    ISequentialStream_RemoteWrite_Thunk
    };

static const MIDL_SERVER_INFO ISequentialStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &ISequentialStream_FormatStringOffsetTable[-3],
    &ISequentialStream_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _ISequentialStreamProxyVtbl = 
{
    &ISequentialStream_ProxyInfo,
    &IID_ISequentialStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ISequentialStream_Read_Proxy ,
    ISequentialStream_Write_Proxy
};

const CInterfaceStubVtbl _ISequentialStreamStubVtbl =
{
    &IID_ISequentialStream,
    &ISequentialStream_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IStream, ver. 0.0,
   GUID={0x0000000c,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IStream_FormatStringOffsetTable[] =
    {
    2028,
    2076,
    2124,
    2172,
    2208,
    2262,
    2298,
    2328,
    2376,
    2424,
    2466
    };

static const MIDL_STUBLESS_PROXY_INFO IStream_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IStream_StubThunkTable[] = 
    {
    ISequentialStream_RemoteRead_Thunk,
    ISequentialStream_RemoteWrite_Thunk,
    IStream_RemoteSeek_Thunk,
    0,
    IStream_RemoteCopyTo_Thunk,
    0,
    0,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IStream_FormatStringOffsetTable[-3],
    &IStream_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IStreamProxyVtbl = 
{
    &IStream_ProxyInfo,
    &IID_IStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ISequentialStream_Read_Proxy ,
    ISequentialStream_Write_Proxy ,
    IStream_Seek_Proxy ,
    (void *) (INT_PTR) -1 /* IStream::SetSize */ ,
    IStream_CopyTo_Proxy ,
    (void *) (INT_PTR) -1 /* IStream::Commit */ ,
    (void *) (INT_PTR) -1 /* IStream::Revert */ ,
    (void *) (INT_PTR) -1 /* IStream::LockRegion */ ,
    (void *) (INT_PTR) -1 /* IStream::UnlockRegion */ ,
    (void *) (INT_PTR) -1 /* IStream::Stat */ ,
    (void *) (INT_PTR) -1 /* IStream::Clone */
};

const CInterfaceStubVtbl _IStreamStubVtbl =
{
    &IID_IStream,
    &IStream_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumSTATSTG, ver. 0.0,
   GUID={0x0000000d,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumSTATSTG_FormatStringOffsetTable[] =
    {
    2502,
    48,
    84,
    2550
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumSTATSTG_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumSTATSTG_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumSTATSTG_StubThunkTable[] = 
    {
    IEnumSTATSTG_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumSTATSTG_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumSTATSTG_FormatStringOffsetTable[-3],
    &IEnumSTATSTG_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumSTATSTGProxyVtbl = 
{
    &IEnumSTATSTG_ProxyInfo,
    &IID_IEnumSTATSTG,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumSTATSTG_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumSTATSTG::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATSTG::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATSTG::Clone */
};

const CInterfaceStubVtbl _IEnumSTATSTGStubVtbl =
{
    &IID_IEnumSTATSTG,
    &IEnumSTATSTG_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IStorage, ver. 0.0,
   GUID={0x0000000b,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IStorage_FormatStringOffsetTable[] =
    {
    2586,
    2646,
    2712,
    2772,
    2838,
    2892,
    2946,
    2982,
    3012,
    516,
    3072,
    3114,
    3168,
    3204,
    3246
    };

static const MIDL_STUBLESS_PROXY_INFO IStorage_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IStorage_StubThunkTable[] = 
    {
    0,
    IStorage_RemoteOpenStream_Thunk,
    0,
    0,
    0,
    0,
    0,
    0,
    IStorage_RemoteEnumElements_Thunk,
    0,
    0,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IStorage_FormatStringOffsetTable[-3],
    &IStorage_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IStorageProxyVtbl = 
{
    &IStorage_ProxyInfo,
    &IID_IStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IStorage::CreateStream */ ,
    IStorage_OpenStream_Proxy ,
    (void *) (INT_PTR) -1 /* IStorage::CreateStorage */ ,
    (void *) (INT_PTR) -1 /* IStorage::OpenStorage */ ,
    (void *) (INT_PTR) -1 /* IStorage::CopyTo */ ,
    (void *) (INT_PTR) -1 /* IStorage::MoveElementTo */ ,
    (void *) (INT_PTR) -1 /* IStorage::Commit */ ,
    (void *) (INT_PTR) -1 /* IStorage::Revert */ ,
    IStorage_EnumElements_Proxy ,
    (void *) (INT_PTR) -1 /* IStorage::DestroyElement */ ,
    (void *) (INT_PTR) -1 /* IStorage::RenameElement */ ,
    (void *) (INT_PTR) -1 /* IStorage::SetElementTimes */ ,
    (void *) (INT_PTR) -1 /* IStorage::SetClass */ ,
    (void *) (INT_PTR) -1 /* IStorage::SetStateBits */ ,
    (void *) (INT_PTR) -1 /* IStorage::Stat */
};

const CInterfaceStubVtbl _IStorageStubVtbl =
{
    &IID_IStorage,
    &IStorage_ServerInfo,
    18,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPersistFile, ver. 0.0,
   GUID={0x0000010b,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IPersistFile_FormatStringOffsetTable[] =
    {
    636,
    186,
    3288,
    3330,
    3372,
    3408
    };

static const MIDL_STUBLESS_PROXY_INFO IPersistFile_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IPersistFile_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPersistFile_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IPersistFile_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IPersistFileProxyVtbl = 
{
    &IPersistFile_ProxyInfo,
    &IID_IPersistFile,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPersist::GetClassID */ ,
    (void *) (INT_PTR) -1 /* IPersistFile::IsDirty */ ,
    (void *) (INT_PTR) -1 /* IPersistFile::Load */ ,
    (void *) (INT_PTR) -1 /* IPersistFile::Save */ ,
    (void *) (INT_PTR) -1 /* IPersistFile::SaveCompleted */ ,
    (void *) (INT_PTR) -1 /* IPersistFile::GetCurFile */
};

const CInterfaceStubVtbl _IPersistFileStubVtbl =
{
    &IID_IPersistFile,
    &IPersistFile_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPersistStorage, ver. 0.0,
   GUID={0x0000010a,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IPersistStorage_FormatStringOffsetTable[] =
    {
    636,
    186,
    3444,
    3480,
    3516,
    3558,
    2298
    };

static const MIDL_STUBLESS_PROXY_INFO IPersistStorage_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IPersistStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IPersistStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IPersistStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IPersistStorageProxyVtbl = 
{
    &IPersistStorage_ProxyInfo,
    &IID_IPersistStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IPersist::GetClassID */ ,
    (void *) (INT_PTR) -1 /* IPersistStorage::IsDirty */ ,
    (void *) (INT_PTR) -1 /* IPersistStorage::InitNew */ ,
    (void *) (INT_PTR) -1 /* IPersistStorage::Load */ ,
    (void *) (INT_PTR) -1 /* IPersistStorage::Save */ ,
    (void *) (INT_PTR) -1 /* IPersistStorage::SaveCompleted */ ,
    (void *) (INT_PTR) -1 /* IPersistStorage::HandsOffStorage */
};

const CInterfaceStubVtbl _IPersistStorageStubVtbl =
{
    &IID_IPersistStorage,
    &IPersistStorage_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IRootStorage, ver. 0.0,
   GUID={0x00000012,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IRootStorage_FormatStringOffsetTable[] =
    {
    3594
    };

static const MIDL_STUBLESS_PROXY_INFO IRootStorage_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IRootStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IRootStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IRootStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IRootStorageProxyVtbl = 
{
    &IRootStorage_ProxyInfo,
    &IID_IRootStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IRootStorage::SwitchToFile */
};

const CInterfaceStubVtbl _IRootStorageStubVtbl =
{
    &IID_IRootStorage,
    &IRootStorage_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ILockBytes, ver. 0.0,
   GUID={0x0000000a,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ILockBytes_FormatStringOffsetTable[] =
    {
    3630,
    3684,
    84,
    2172,
    3738,
    3786,
    3834
    };

static const MIDL_STUBLESS_PROXY_INFO ILockBytes_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &ILockBytes_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK ILockBytes_StubThunkTable[] = 
    {
    ILockBytes_RemoteReadAt_Thunk,
    ILockBytes_RemoteWriteAt_Thunk,
    0,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO ILockBytes_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &ILockBytes_FormatStringOffsetTable[-3],
    &ILockBytes_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _ILockBytesProxyVtbl = 
{
    &ILockBytes_ProxyInfo,
    &IID_ILockBytes,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ILockBytes_ReadAt_Proxy ,
    ILockBytes_WriteAt_Proxy ,
    (void *) (INT_PTR) -1 /* ILockBytes::Flush */ ,
    (void *) (INT_PTR) -1 /* ILockBytes::SetSize */ ,
    (void *) (INT_PTR) -1 /* ILockBytes::LockRegion */ ,
    (void *) (INT_PTR) -1 /* ILockBytes::UnlockRegion */ ,
    (void *) (INT_PTR) -1 /* ILockBytes::Stat */
};

const CInterfaceStubVtbl _ILockBytesStubVtbl =
{
    &IID_ILockBytes,
    &ILockBytes_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IFillLockBytes, ver. 0.0,
   GUID={0x99caf010,0x415e,0x11cf,{0x88,0x14,0x00,0xaa,0x00,0xb5,0x69,0xf5}} */

#pragma code_seg(".orpc")
static const unsigned short IFillLockBytes_FormatStringOffsetTable[] =
    {
    3876,
    3684,
    3924,
    3960
    };

static const MIDL_STUBLESS_PROXY_INFO IFillLockBytes_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IFillLockBytes_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IFillLockBytes_StubThunkTable[] = 
    {
    IFillLockBytes_RemoteFillAppend_Thunk,
    IFillLockBytes_RemoteFillAt_Thunk,
    0,
    0
    };

static const MIDL_SERVER_INFO IFillLockBytes_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IFillLockBytes_FormatStringOffsetTable[-3],
    &IFillLockBytes_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IFillLockBytesProxyVtbl = 
{
    &IFillLockBytes_ProxyInfo,
    &IID_IFillLockBytes,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IFillLockBytes_FillAppend_Proxy ,
    IFillLockBytes_FillAt_Proxy ,
    (void *) (INT_PTR) -1 /* IFillLockBytes::SetFillSize */ ,
    (void *) (INT_PTR) -1 /* IFillLockBytes::Terminate */
};

const CInterfaceStubVtbl _IFillLockBytesStubVtbl =
{
    &IID_IFillLockBytes,
    &IFillLockBytes_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IProgressNotify, ver. 0.0,
   GUID={0xa9d758a0,0x4617,0x11cf,{0x95,0xfc,0x00,0xaa,0x00,0x68,0x0d,0xb4}} */

#pragma code_seg(".orpc")
static const unsigned short IProgressNotify_FormatStringOffsetTable[] =
    {
    3996
    };

static const MIDL_STUBLESS_PROXY_INFO IProgressNotify_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IProgressNotify_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IProgressNotify_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IProgressNotify_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IProgressNotifyProxyVtbl = 
{
    &IProgressNotify_ProxyInfo,
    &IID_IProgressNotify,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IProgressNotify::OnProgress */
};

const CInterfaceStubVtbl _IProgressNotifyStubVtbl =
{
    &IID_IProgressNotify,
    &IProgressNotify_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ILayoutStorage, ver. 0.0,
   GUID={0x0e6d4d90,0x6738,0x11cf,{0x96,0x08,0x00,0xaa,0x00,0x68,0x0d,0xb4}} */


/* Object interface: IBlockingLock, ver. 0.0,
   GUID={0x30f3d47a,0x6447,0x11d1,{0x8e,0x3c,0x00,0xc0,0x4f,0xb9,0x38,0x6d}} */

#pragma code_seg(".orpc")
static const unsigned short IBlockingLock_FormatStringOffsetTable[] =
    {
    4050,
    186
    };

static const MIDL_STUBLESS_PROXY_INFO IBlockingLock_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IBlockingLock_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBlockingLock_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IBlockingLock_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IBlockingLockProxyVtbl = 
{
    &IBlockingLock_ProxyInfo,
    &IID_IBlockingLock,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IBlockingLock::Lock */ ,
    (void *) (INT_PTR) -1 /* IBlockingLock::Unlock */
};

const CInterfaceStubVtbl _IBlockingLockStubVtbl =
{
    &IID_IBlockingLock,
    &IBlockingLock_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITimeAndNoticeControl, ver. 0.0,
   GUID={0xbc0bf6ae,0x8878,0x11d1,{0x83,0xe9,0x00,0xc0,0x4f,0xc2,0xc6,0xd4}} */

#pragma code_seg(".orpc")
static const unsigned short ITimeAndNoticeControl_FormatStringOffsetTable[] =
    {
    4086
    };

static const MIDL_STUBLESS_PROXY_INFO ITimeAndNoticeControl_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &ITimeAndNoticeControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITimeAndNoticeControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &ITimeAndNoticeControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _ITimeAndNoticeControlProxyVtbl = 
{
    &ITimeAndNoticeControl_ProxyInfo,
    &IID_ITimeAndNoticeControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ITimeAndNoticeControl::SuppressChanges */
};

const CInterfaceStubVtbl _ITimeAndNoticeControlStubVtbl =
{
    &IID_ITimeAndNoticeControl,
    &ITimeAndNoticeControl_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOplockStorage, ver. 0.0,
   GUID={0x8d19c834,0x8879,0x11d1,{0x83,0xe9,0x00,0xc0,0x4f,0xc2,0xc6,0xd4}} */

#pragma code_seg(".orpc")
static const unsigned short IOplockStorage_FormatStringOffsetTable[] =
    {
    4128,
    4194
    };

static const MIDL_STUBLESS_PROXY_INFO IOplockStorage_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IOplockStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOplockStorage_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IOplockStorage_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOplockStorageProxyVtbl = 
{
    &IOplockStorage_ProxyInfo,
    &IID_IOplockStorage,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOplockStorage::CreateStorageEx */ ,
    (void *) (INT_PTR) -1 /* IOplockStorage::OpenStorageEx */
};

const CInterfaceStubVtbl _IOplockStorageStubVtbl =
{
    &IID_IOplockStorage,
    &IOplockStorage_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumFORMATETC, ver. 0.0,
   GUID={0x00000103,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumFORMATETC_FormatStringOffsetTable[] =
    {
    4260,
    48,
    84,
    4308
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumFORMATETC_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumFORMATETC_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumFORMATETC_StubThunkTable[] = 
    {
    IEnumFORMATETC_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumFORMATETC_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumFORMATETC_FormatStringOffsetTable[-3],
    &IEnumFORMATETC_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumFORMATETCProxyVtbl = 
{
    &IEnumFORMATETC_ProxyInfo,
    &IID_IEnumFORMATETC,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumFORMATETC_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumFORMATETC::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumFORMATETC::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumFORMATETC::Clone */
};

const CInterfaceStubVtbl _IEnumFORMATETCStubVtbl =
{
    &IID_IEnumFORMATETC,
    &IEnumFORMATETC_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumSTATDATA, ver. 0.0,
   GUID={0x00000105,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumSTATDATA_FormatStringOffsetTable[] =
    {
    4344,
    48,
    84,
    4392
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumSTATDATA_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumSTATDATA_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumSTATDATA_StubThunkTable[] = 
    {
    IEnumSTATDATA_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumSTATDATA_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IEnumSTATDATA_FormatStringOffsetTable[-3],
    &IEnumSTATDATA_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumSTATDATAProxyVtbl = 
{
    &IEnumSTATDATA_ProxyInfo,
    &IID_IEnumSTATDATA,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumSTATDATA_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumSTATDATA::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATDATA::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumSTATDATA::Clone */
};

const CInterfaceStubVtbl _IEnumSTATDATAStubVtbl =
{
    &IID_IEnumSTATDATA,
    &IEnumSTATDATA_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IAdviseSink, ver. 0.0,
   GUID={0x0000010f,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IAdviseSink_FormatStringOffsetTable[] =
    {
    4428,
    4470,
    840,
    4512,
    4542
    };

static const MIDL_STUBLESS_PROXY_INFO IAdviseSink_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IAdviseSink_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IAdviseSink_StubThunkTable[] = 
    {
    IAdviseSink_RemoteOnDataChange_Thunk,
    IAdviseSink_RemoteOnViewChange_Thunk,
    IAdviseSink_RemoteOnRename_Thunk,
    IAdviseSink_RemoteOnSave_Thunk,
    IAdviseSink_RemoteOnClose_Thunk
    };

static const MIDL_SERVER_INFO IAdviseSink_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IAdviseSink_FormatStringOffsetTable[-3],
    &IAdviseSink_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IAdviseSinkProxyVtbl = 
{
    &IAdviseSink_ProxyInfo,
    &IID_IAdviseSink,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IAdviseSink_OnDataChange_Proxy ,
    IAdviseSink_OnViewChange_Proxy ,
    IAdviseSink_OnRename_Proxy ,
    IAdviseSink_OnSave_Proxy ,
    IAdviseSink_OnClose_Proxy
};

const CInterfaceStubVtbl _IAdviseSinkStubVtbl =
{
    &IID_IAdviseSink,
    &IAdviseSink_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IAdviseSink2, ver. 0.0,
   GUID={0x00000125,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IAdviseSink2_FormatStringOffsetTable[] =
    {
    4428,
    4470,
    840,
    4512,
    4542,
    4572
    };

static const MIDL_STUBLESS_PROXY_INFO IAdviseSink2_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IAdviseSink2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IAdviseSink2_StubThunkTable[] = 
    {
    IAdviseSink_RemoteOnDataChange_Thunk,
    IAdviseSink_RemoteOnViewChange_Thunk,
    IAdviseSink_RemoteOnRename_Thunk,
    IAdviseSink_RemoteOnSave_Thunk,
    IAdviseSink_RemoteOnClose_Thunk,
    IAdviseSink2_RemoteOnLinkSrcChange_Thunk
    };

static const MIDL_SERVER_INFO IAdviseSink2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IAdviseSink2_FormatStringOffsetTable[-3],
    &IAdviseSink2_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IAdviseSink2ProxyVtbl = 
{
    &IAdviseSink2_ProxyInfo,
    &IID_IAdviseSink2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IAdviseSink_OnDataChange_Proxy ,
    IAdviseSink_OnViewChange_Proxy ,
    IAdviseSink_OnRename_Proxy ,
    IAdviseSink_OnSave_Proxy ,
    IAdviseSink_OnClose_Proxy ,
    IAdviseSink2_OnLinkSrcChange_Proxy
};

const CInterfaceStubVtbl _IAdviseSink2StubVtbl =
{
    &IID_IAdviseSink2,
    &IAdviseSink2_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IDataObject, ver. 0.0,
   GUID={0x0000010e,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IDataObject_FormatStringOffsetTable[] =
    {
    4608,
    4650,
    4692,
    4728,
    4770,
    4818,
    4860,
    4914,
    4950
    };

static const MIDL_STUBLESS_PROXY_INFO IDataObject_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IDataObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IDataObject_StubThunkTable[] = 
    {
    IDataObject_RemoteGetData_Thunk,
    IDataObject_RemoteGetDataHere_Thunk,
    0,
    0,
    IDataObject_RemoteSetData_Thunk,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IDataObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IDataObject_FormatStringOffsetTable[-3],
    &IDataObject_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IDataObjectProxyVtbl = 
{
    &IDataObject_ProxyInfo,
    &IID_IDataObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IDataObject_GetData_Proxy ,
    IDataObject_GetDataHere_Proxy ,
    (void *) (INT_PTR) -1 /* IDataObject::QueryGetData */ ,
    (void *) (INT_PTR) -1 /* IDataObject::GetCanonicalFormatEtc */ ,
    IDataObject_SetData_Proxy ,
    (void *) (INT_PTR) -1 /* IDataObject::EnumFormatEtc */ ,
    (void *) (INT_PTR) -1 /* IDataObject::DAdvise */ ,
    (void *) (INT_PTR) -1 /* IDataObject::DUnadvise */ ,
    (void *) (INT_PTR) -1 /* IDataObject::EnumDAdvise */
};

const CInterfaceStubVtbl _IDataObjectStubVtbl =
{
    &IID_IDataObject,
    &IDataObject_ServerInfo,
    12,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IDataAdviseHolder, ver. 0.0,
   GUID={0x00000110,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IMessageFilter, ver. 0.0,
   GUID={0x00000016,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IRpcChannelBuffer, ver. 0.0,
   GUID={0xD5F56B60,0x593B,0x101A,{0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A}} */


/* Object interface: IRpcChannelBuffer2, ver. 0.0,
   GUID={0x594f31d0,0x7f19,0x11d0,{0xb1,0x94,0x00,0xa0,0xc9,0x0d,0xc8,0xbf}} */


/* Object interface: IRpcChannelBuffer3, ver. 0.0,
   GUID={0x25B15600,0x0115,0x11d0,{0xBF,0x0D,0x00,0xAA,0x00,0xB8,0xDF,0xD2}} */


/* Object interface: IAsyncRpcChannelBuffer, ver. 0.0,
   GUID={0xa5029fb6,0x3c34,0x11d1,{0x9c,0x99,0x00,0xc0,0x4f,0xb9,0x98,0xaa}} */


/* Object interface: IRpcSyntaxNegotiate, ver. 0.0,
   GUID={0x58a08519,0x24c8,0x4935,{0xb4,0x82,0x3f,0xd8,0x23,0x33,0x3a,0x4f}} */


/* Object interface: IRpcProxyBuffer, ver. 0.0,
   GUID={0xD5F56A34,0x593B,0x101A,{0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A}} */


/* Object interface: IRpcStubBuffer, ver. 0.0,
   GUID={0xD5F56AFC,0x593B,0x101A,{0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A}} */


/* Object interface: IPSFactoryBuffer, ver. 0.0,
   GUID={0xD5F569D0,0x593B,0x101A,{0xB5,0x69,0x08,0x00,0x2B,0x2D,0xBF,0x7A}} */


/* Object interface: IChannelHook, ver. 0.0,
   GUID={0x1008c4a0,0x7613,0x11cf,{0x9a,0xf1,0x00,0x20,0xaf,0x6e,0x72,0xf4}} */


/* Standard interface: __MIDL_itf_objidl_0000_0051, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IClientSecurity, ver. 0.0,
   GUID={0x0000013D,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IServerSecurity, ver. 0.0,
   GUID={0x0000013E,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAsyncSetup, ver. 0.0,
   GUID={0x00000024,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDirectWriterLock, ver. 0.0,
   GUID={0x0e6d4d92,0x6738,0x11cf,{0x96,0x08,0x00,0xaa,0x00,0x68,0x0d,0xb4}} */

#pragma code_seg(".orpc")
static const unsigned short IDirectWriterLock_FormatStringOffsetTable[] =
    {
    4050,
    186,
    84
    };

static const MIDL_STUBLESS_PROXY_INFO IDirectWriterLock_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IDirectWriterLock_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDirectWriterLock_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IDirectWriterLock_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IDirectWriterLockProxyVtbl = 
{
    &IDirectWriterLock_ProxyInfo,
    &IID_IDirectWriterLock,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IDirectWriterLock::WaitForWriteAccess */ ,
    (void *) (INT_PTR) -1 /* IDirectWriterLock::ReleaseWriteAccess */ ,
    (void *) (INT_PTR) -1 /* IDirectWriterLock::HaveWriteAccess */
};

const CInterfaceStubVtbl _IDirectWriterLockStubVtbl =
{
    &IID_IDirectWriterLock,
    &IDirectWriterLock_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISynchronize, ver. 0.0,
   GUID={0x00000030,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ISynchronize_FormatStringOffsetTable[] =
    {
    4086,
    186,
    84
    };

static const MIDL_STUBLESS_PROXY_INFO ISynchronize_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &ISynchronize_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISynchronize_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &ISynchronize_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _ISynchronizeProxyVtbl = 
{
    &ISynchronize_ProxyInfo,
    &IID_ISynchronize,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ISynchronize::Wait */ ,
    (void *) (INT_PTR) -1 /* ISynchronize::Signal */ ,
    (void *) (INT_PTR) -1 /* ISynchronize::Reset */
};

const CInterfaceStubVtbl _ISynchronizeStubVtbl =
{
    &IID_ISynchronize,
    &ISynchronize_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISynchronizeHandle, ver. 0.0,
   GUID={0x00000031,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ISynchronizeEvent, ver. 0.0,
   GUID={0x00000032,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ISynchronizeContainer, ver. 0.0,
   GUID={0x00000033,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ISynchronizeMutex, ver. 0.0,
   GUID={0x00000025,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICancelMethodCalls, ver. 0.0,
   GUID={0x00000029,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAsyncManager, ver. 0.0,
   GUID={0x0000002A,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICallFactory, ver. 0.0,
   GUID={0x1c733a30,0x2a1c,0x11ce,{0xad,0xe5,0x00,0xaa,0x00,0x44,0x77,0x3d}} */


/* Object interface: IRpcOptions, ver. 0.0,
   GUID={0x00000144,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Standard interface: __MIDL_itf_objidl_0000_0064, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IRpcHelper, ver. 0.0,
   GUID={0x00000149,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IReleaseMarshalBuffers, ver. 0.0,
   GUID={0xeb0cb9e8,0x7996,0x11d2,{0x87,0x2e,0x00,0x00,0xf8,0x08,0x08,0x59}} */


/* Object interface: IWaitMultiple, ver. 0.0,
   GUID={0x0000002B,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IUrlMon, ver. 0.0,
   GUID={0x00000026,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IUrlMon_FormatStringOffsetTable[] =
    {
    4986
    };

static const MIDL_STUBLESS_PROXY_INFO IUrlMon_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IUrlMon_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IUrlMon_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IUrlMon_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IUrlMonProxyVtbl = 
{
    &IUrlMon_ProxyInfo,
    &IID_IUrlMon,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IUrlMon::AsyncGetClassBits */
};

const CInterfaceStubVtbl _IUrlMonStubVtbl =
{
    &IID_IUrlMon,
    &IUrlMon_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IForegroundTransfer, ver. 0.0,
   GUID={0x00000145,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAddrTrackingControl, ver. 0.0,
   GUID={0x00000147,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IAddrExclusionControl, ver. 0.0,
   GUID={0x00000148,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Standard interface: __MIDL_itf_objidl_0000_0071, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IComThreadingInfo, ver. 0.0,
   GUID={0x000001ce,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IProcessInitControl, ver. 0.0,
   GUID={0x72380d55,0x8d2b,0x43a3,{0x85,0x13,0x2b,0x6e,0xf3,0x14,0x34,0xe9}} */

#pragma code_seg(".orpc")
static const unsigned short IProcessInitControl_FormatStringOffsetTable[] =
    {
    4050
    };

static const MIDL_STUBLESS_PROXY_INFO IProcessInitControl_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IProcessInitControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IProcessInitControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IProcessInitControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IProcessInitControlProxyVtbl = 
{
    &IProcessInitControl_ProxyInfo,
    &IID_IProcessInitControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IProcessInitControl::ResetInitializerTimeout */
};

const CInterfaceStubVtbl _IProcessInitControlStubVtbl =
{
    &IID_IProcessInitControl,
    &IProcessInitControl_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IInitializeSpy, ver. 0.0,
   GUID={0x00000034,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IThumbnailExtractor, ver. 0.0,
   GUID={0x969dc708,0x5c76,0x11d1,{0x8d,0x86,0x00,0x00,0xf8,0x04,0xb0,0x57}} */

#pragma code_seg(".orpc")
static const unsigned short IThumbnailExtractor_FormatStringOffsetTable[] =
    {
    5076,
    5142
    };

static const MIDL_STUBLESS_PROXY_INFO IThumbnailExtractor_ProxyInfo =
    {
    &Object_StubDesc,
    objidl__MIDL_ProcFormatString.Format,
    &IThumbnailExtractor_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IThumbnailExtractor_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    objidl__MIDL_ProcFormatString.Format,
    &IThumbnailExtractor_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IThumbnailExtractorProxyVtbl = 
{
    &IThumbnailExtractor_ProxyInfo,
    &IID_IThumbnailExtractor,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IThumbnailExtractor::ExtractThumbnail */ ,
    (void *) (INT_PTR) -1 /* IThumbnailExtractor::OnFileUpdated */
};

const CInterfaceStubVtbl _IThumbnailExtractorStubVtbl =
{
    &IID_IThumbnailExtractor,
    &IThumbnailExtractor_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_objidl_0000_0075, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IEnumContextProps, ver. 0.0,
   GUID={0x000001c1,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IContext, ver. 0.0,
   GUID={0x000001c0,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IObjContext, ver. 0.0,
   GUID={0x000001c6,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Standard interface: __MIDL_itf_objidl_0000_0078, ver. 0.0,
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
    objidl__MIDL_TypeFormatString.Format,
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

const CInterfaceProxyVtbl * _objidl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IEnumUnknownProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumStringProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumMonikerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumFORMATETCProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumSTATDATAProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IThumbnailExtractorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPersistStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILockBytesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPersistStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPersistFileProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPersistProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumSTATSTGProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBindCtxProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDataObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IMonikerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAdviseSinkProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRunningObjectTableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFillLockBytesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRootStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISurrogateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAdviseSink2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IUrlMonProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IRunnableObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISynchronizeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISequentialStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOplockStorageProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IClassActivatorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IProcessInitControlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBlockingLockProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDirectWriterLockProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IProgressNotifyProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITimeAndNoticeControlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IROTDataProxyVtbl,
    0
};

const CInterfaceStubVtbl * _objidl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IEnumUnknownStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumStringStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumMonikerStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumFORMATETCStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumSTATDATAStubVtbl,
    ( CInterfaceStubVtbl *) &_IThumbnailExtractorStubVtbl,
    ( CInterfaceStubVtbl *) &_IPersistStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_ILockBytesStubVtbl,
    ( CInterfaceStubVtbl *) &_IPersistStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_IStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_IPersistFileStubVtbl,
    ( CInterfaceStubVtbl *) &_IStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_IPersistStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumSTATSTGStubVtbl,
    ( CInterfaceStubVtbl *) &_IBindCtxStubVtbl,
    ( CInterfaceStubVtbl *) &_IDataObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IMonikerStubVtbl,
    ( CInterfaceStubVtbl *) &_IAdviseSinkStubVtbl,
    ( CInterfaceStubVtbl *) &_IRunningObjectTableStubVtbl,
    ( CInterfaceStubVtbl *) &_IFillLockBytesStubVtbl,
    ( CInterfaceStubVtbl *) &_IRootStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_ISurrogateStubVtbl,
    ( CInterfaceStubVtbl *) &_IAdviseSink2StubVtbl,
    ( CInterfaceStubVtbl *) &_IUrlMonStubVtbl,
    ( CInterfaceStubVtbl *) &_IRunnableObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_ISynchronizeStubVtbl,
    ( CInterfaceStubVtbl *) &_ISequentialStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_IOplockStorageStubVtbl,
    ( CInterfaceStubVtbl *) &_IClassActivatorStubVtbl,
    ( CInterfaceStubVtbl *) &_IProcessInitControlStubVtbl,
    ( CInterfaceStubVtbl *) &_IBlockingLockStubVtbl,
    ( CInterfaceStubVtbl *) &_IDirectWriterLockStubVtbl,
    ( CInterfaceStubVtbl *) &_IProgressNotifyStubVtbl,
    ( CInterfaceStubVtbl *) &_ITimeAndNoticeControlStubVtbl,
    ( CInterfaceStubVtbl *) &_IROTDataStubVtbl,
    0
};

PCInterfaceName const _objidl_InterfaceNamesList[] = 
{
    "IEnumUnknown",
    "IEnumString",
    "IEnumMoniker",
    "IEnumFORMATETC",
    "IEnumSTATDATA",
    "IThumbnailExtractor",
    "IPersistStream",
    "ILockBytes",
    "IPersistStorage",
    "IStorage",
    "IPersistFile",
    "IStream",
    "IPersist",
    "IEnumSTATSTG",
    "IBindCtx",
    "IDataObject",
    "IMoniker",
    "IAdviseSink",
    "IRunningObjectTable",
    "IFillLockBytes",
    "IRootStorage",
    "ISurrogate",
    "IAdviseSink2",
    "IUrlMon",
    "IRunnableObject",
    "ISynchronize",
    "ISequentialStream",
    "IOplockStorage",
    "IClassActivator",
    "IProcessInitControl",
    "IBlockingLock",
    "IDirectWriterLock",
    "IProgressNotify",
    "ITimeAndNoticeControl",
    "IROTData",
    0
};


#define _objidl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _objidl, pIID, n)

int __stdcall _objidl_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _objidl, 35, 32 )
    IID_BS_LOOKUP_NEXT_TEST( _objidl, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _objidl, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _objidl, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _objidl, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _objidl, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _objidl, 35, *pIndex )
    
}

const ExtendedProxyFileInfo objidl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _objidl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _objidl_StubVtblList,
    (const PCInterfaceName * ) & _objidl_InterfaceNamesList,
    0, // no delegation
    & _objidl_IID_Lookup, 
    35,
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

