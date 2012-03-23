

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Nov 07 19:54:12 2011
 */
/* Compiler settings for oaidl.idl:
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


#include "oaidl.h"

#define TYPE_FORMAT_STRING_SIZE   2015                              
#define PROC_FORMAT_STRING_SIZE   3151                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   3            

typedef struct _oaidl_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } oaidl_MIDL_TYPE_FORMAT_STRING;

typedef struct _oaidl_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } oaidl_MIDL_PROC_FORMAT_STRING;

typedef struct _oaidl_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } oaidl_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const oaidl_MIDL_TYPE_FORMAT_STRING oaidl__MIDL_TypeFormatString;
extern const oaidl_MIDL_PROC_FORMAT_STRING oaidl__MIDL_ProcFormatString;
extern const oaidl_MIDL_EXPR_FORMAT_STRING oaidl__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDispatch_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDispatch_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IDispatch_RemoteInvoke_Proxy( 
    IDispatch * This,
    /* [in] */ DISPID dispIdMember,
    /* [in] */ REFIID riid,
    /* [in] */ LCID lcid,
    /* [in] */ DWORD dwFlags,
    /* [in] */ DISPPARAMS *pDispParams,
    /* [out] */ VARIANT *pVarResult,
    /* [out] */ EXCEPINFO *pExcepInfo,
    /* [out] */ UINT *pArgErr,
    /* [in] */ UINT cVarRef,
    /* [size_is][in] */ UINT *rgVarRefIdx,
    /* [size_is][out][in] */ VARIANTARG *rgVarRef)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[144],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IDispatch_RemoteInvoke_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IDispatch *This;
        DISPID dispIdMember;
        REFIID riid;
        LCID lcid;
        DWORD dwFlags;
        DISPPARAMS *pDispParams;
        VARIANT *pVarResult;
        EXCEPINFO *pExcepInfo;
        UINT *pArgErr;
        UINT cVarRef;
        UINT *rgVarRefIdx;
        VARIANTARG *rgVarRef;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IDispatch_Invoke_Stub(
                                (IDispatch *) pParamStruct->This,
                                pParamStruct->dispIdMember,
                                pParamStruct->riid,
                                pParamStruct->lcid,
                                pParamStruct->dwFlags,
                                pParamStruct->pDispParams,
                                pParamStruct->pVarResult,
                                pParamStruct->pExcepInfo,
                                pParamStruct->pArgErr,
                                pParamStruct->cVarRef,
                                pParamStruct->rgVarRefIdx,
                                pParamStruct->rgVarRef);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumVARIANT_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumVARIANT_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumVARIANT_RemoteNext_Proxy( 
    IEnumVARIANT * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ VARIANT *rgVar,
    /* [out] */ ULONG *pCeltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[240],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumVARIANT_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumVARIANT *This;
        ULONG celt;
        VARIANT *rgVar;
        ULONG *pCeltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumVARIANT_Next_Stub(
                                 (IEnumVARIANT *) pParamStruct->This,
                                 pParamStruct->celt,
                                 pParamStruct->rgVar,
                                 pParamStruct->pCeltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITypeComp_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITypeComp_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeComp_RemoteBind_Proxy( 
    ITypeComp * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ ULONG lHashVal,
    /* [in] */ WORD wFlags,
    /* [out] */ ITypeInfo **ppTInfo,
    /* [out] */ DESCKIND *pDescKind,
    /* [out] */ LPFUNCDESC *ppFuncDesc,
    /* [out] */ LPVARDESC *ppVarDesc,
    /* [out] */ ITypeComp **ppTypeComp,
    /* [out] */ CLEANLOCALSTORAGE *pDummy)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[390],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeComp_RemoteBind_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeComp *This;
        LPOLESTR szName;
        ULONG lHashVal;
        WORD wFlags;
        char Pad0[2];
        ITypeInfo **ppTInfo;
        DESCKIND *pDescKind;
        LPFUNCDESC *ppFuncDesc;
        LPVARDESC *ppVarDesc;
        ITypeComp **ppTypeComp;
        CLEANLOCALSTORAGE *pDummy;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeComp_Bind_Stub(
                              (ITypeComp *) pParamStruct->This,
                              pParamStruct->szName,
                              pParamStruct->lHashVal,
                              pParamStruct->wFlags,
                              pParamStruct->ppTInfo,
                              pParamStruct->pDescKind,
                              pParamStruct->ppFuncDesc,
                              pParamStruct->ppVarDesc,
                              pParamStruct->ppTypeComp,
                              pParamStruct->pDummy);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeComp_RemoteBindType_Proxy( 
    ITypeComp * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ ULONG lHashVal,
    /* [out] */ ITypeInfo **ppTInfo)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[474],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeComp_RemoteBindType_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeComp *This;
        LPOLESTR szName;
        ULONG lHashVal;
        ITypeInfo **ppTInfo;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeComp_BindType_Stub(
                                  (ITypeComp *) pParamStruct->This,
                                  pParamStruct->szName,
                                  pParamStruct->lHashVal,
                                  pParamStruct->ppTInfo);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITypeInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITypeInfo_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetTypeAttr_Proxy( 
    ITypeInfo * This,
    /* [out] */ LPTYPEATTR *ppTypeAttr,
    /* [out] */ CLEANLOCALSTORAGE *pDummy)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[522],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteGetTypeAttr_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        LPTYPEATTR *ppTypeAttr;
        CLEANLOCALSTORAGE *pDummy;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetTypeAttr_Stub(
                                     (ITypeInfo *) pParamStruct->This,
                                     pParamStruct->ppTypeAttr,
                                     pParamStruct->pDummy);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetFuncDesc_Proxy( 
    ITypeInfo * This,
    /* [in] */ UINT index,
    /* [out] */ LPFUNCDESC *ppFuncDesc,
    /* [out] */ CLEANLOCALSTORAGE *pDummy)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[600],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteGetFuncDesc_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        UINT index;
        LPFUNCDESC *ppFuncDesc;
        CLEANLOCALSTORAGE *pDummy;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetFuncDesc_Stub(
                                     (ITypeInfo *) pParamStruct->This,
                                     pParamStruct->index,
                                     pParamStruct->ppFuncDesc,
                                     pParamStruct->pDummy);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetVarDesc_Proxy( 
    ITypeInfo * This,
    /* [in] */ UINT index,
    /* [out] */ LPVARDESC *ppVarDesc,
    /* [out] */ CLEANLOCALSTORAGE *pDummy)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[648],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteGetVarDesc_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        UINT index;
        LPVARDESC *ppVarDesc;
        CLEANLOCALSTORAGE *pDummy;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetVarDesc_Stub(
                                    (ITypeInfo *) pParamStruct->This,
                                    pParamStruct->index,
                                    pParamStruct->ppVarDesc,
                                    pParamStruct->pDummy);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetNames_Proxy( 
    ITypeInfo * This,
    /* [in] */ MEMBERID memid,
    /* [length_is][size_is][out] */ BSTR *rgBstrNames,
    /* [in] */ UINT cMaxNames,
    /* [out] */ UINT *pcNames)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[696],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteGetNames_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        MEMBERID memid;
        BSTR *rgBstrNames;
        UINT cMaxNames;
        UINT *pcNames;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetNames_Stub(
                                  (ITypeInfo *) pParamStruct->This,
                                  pParamStruct->memid,
                                  pParamStruct->rgBstrNames,
                                  pParamStruct->cMaxNames,
                                  pParamStruct->pcNames);
    
}

void __RPC_API
ITypeInfo_LocalGetIDsOfNames_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetIDsOfNames_Stub((ITypeInfo *) pParamStruct->This);
    
}

void __RPC_API
ITypeInfo_LocalInvoke_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_Invoke_Stub((ITypeInfo *) pParamStruct->This);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetDocumentation_Proxy( 
    ITypeInfo * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ DWORD refPtrFlags,
    /* [out] */ BSTR *pBstrName,
    /* [out] */ BSTR *pBstrDocString,
    /* [out] */ DWORD *pdwHelpContext,
    /* [out] */ BSTR *pBstrHelpFile)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[894],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteGetDocumentation_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        MEMBERID memid;
        DWORD refPtrFlags;
        BSTR *pBstrName;
        BSTR *pBstrDocString;
        DWORD *pdwHelpContext;
        BSTR *pBstrHelpFile;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetDocumentation_Stub(
                                          (ITypeInfo *) pParamStruct->This,
                                          pParamStruct->memid,
                                          pParamStruct->refPtrFlags,
                                          pParamStruct->pBstrName,
                                          pParamStruct->pBstrDocString,
                                          pParamStruct->pdwHelpContext,
                                          pParamStruct->pBstrHelpFile);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetDllEntry_Proxy( 
    ITypeInfo * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ INVOKEKIND invKind,
    /* [in] */ DWORD refPtrFlags,
    /* [out] */ BSTR *pBstrDllName,
    /* [out] */ BSTR *pBstrName,
    /* [out] */ WORD *pwOrdinal)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[960],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteGetDllEntry_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        MEMBERID memid;
        INVOKEKIND invKind;
        DWORD refPtrFlags;
        BSTR *pBstrDllName;
        BSTR *pBstrName;
        WORD *pwOrdinal;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetDllEntry_Stub(
                                     (ITypeInfo *) pParamStruct->This,
                                     pParamStruct->memid,
                                     pParamStruct->invKind,
                                     pParamStruct->refPtrFlags,
                                     pParamStruct->pBstrDllName,
                                     pParamStruct->pBstrName,
                                     pParamStruct->pwOrdinal);
    
}

void __RPC_API
ITypeInfo_LocalAddressOfMember_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_AddressOfMember_Stub((ITypeInfo *) pParamStruct->This);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteCreateInstance_Proxy( 
    ITypeInfo * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown **ppvObj)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[1098],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteCreateInstance_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        REFIID riid;
        IUnknown **ppvObj;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_CreateInstance_Stub(
                                        (ITypeInfo *) pParamStruct->This,
                                        pParamStruct->riid,
                                        pParamStruct->ppvObj);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo_RemoteGetContainingTypeLib_Proxy( 
    ITypeInfo * This,
    /* [out] */ ITypeLib **ppTLib,
    /* [out] */ UINT *pIndex)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[1182],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo_RemoteGetContainingTypeLib_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        ITypeLib **ppTLib;
        UINT *pIndex;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_GetContainingTypeLib_Stub(
                                              (ITypeInfo *) pParamStruct->This,
                                              pParamStruct->ppTLib,
                                              pParamStruct->pIndex);
    
}

void __RPC_API
ITypeInfo_LocalReleaseTypeAttr_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_ReleaseTypeAttr_Stub((ITypeInfo *) pParamStruct->This);
    
}

void __RPC_API
ITypeInfo_LocalReleaseFuncDesc_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_ReleaseFuncDesc_Stub((ITypeInfo *) pParamStruct->This);
    
}

void __RPC_API
ITypeInfo_LocalReleaseVarDesc_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo_ReleaseVarDesc_Stub((ITypeInfo *) pParamStruct->This);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITypeInfo2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITypeInfo2_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeInfo2_RemoteGetDocumentation2_Proxy( 
    ITypeInfo2 * This,
    /* [in] */ MEMBERID memid,
    /* [in] */ LCID lcid,
    /* [in] */ DWORD refPtrFlags,
    /* [out] */ BSTR *pbstrHelpString,
    /* [out] */ DWORD *pdwHelpStringContext,
    /* [out] */ BSTR *pbstrHelpStringDll)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[1716],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeInfo2_RemoteGetDocumentation2_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeInfo2 *This;
        MEMBERID memid;
        LCID lcid;
        DWORD refPtrFlags;
        BSTR *pbstrHelpString;
        DWORD *pdwHelpStringContext;
        BSTR *pbstrHelpStringDll;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeInfo2_GetDocumentation2_Stub(
                                            (ITypeInfo2 *) pParamStruct->This,
                                            pParamStruct->memid,
                                            pParamStruct->lcid,
                                            pParamStruct->refPtrFlags,
                                            pParamStruct->pbstrHelpString,
                                            pParamStruct->pdwHelpStringContext,
                                            pParamStruct->pbstrHelpStringDll);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITypeLib_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITypeLib_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeLib_RemoteGetTypeInfoCount_Proxy( 
    ITypeLib * This,
    /* [out] */ UINT *pcTInfo)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeLib_RemoteGetTypeInfoCount_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib *This;
        UINT *pcTInfo;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib_GetTypeInfoCount_Stub((ITypeLib *) pParamStruct->This,pParamStruct->pcTInfo);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeLib_RemoteGetLibAttr_Proxy( 
    ITypeLib * This,
    /* [out] */ LPTLIBATTR *ppTLibAttr,
    /* [out] */ CLEANLOCALSTORAGE *pDummy)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[2118],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeLib_RemoteGetLibAttr_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib *This;
        LPTLIBATTR *ppTLibAttr;
        CLEANLOCALSTORAGE *pDummy;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib_GetLibAttr_Stub(
                                   (ITypeLib *) pParamStruct->This,
                                   pParamStruct->ppTLibAttr,
                                   pParamStruct->pDummy);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeLib_RemoteGetDocumentation_Proxy( 
    ITypeLib * This,
    /* [in] */ INT index,
    /* [in] */ DWORD refPtrFlags,
    /* [out] */ BSTR *pBstrName,
    /* [out] */ BSTR *pBstrDocString,
    /* [out] */ DWORD *pdwHelpContext,
    /* [out] */ BSTR *pBstrHelpFile)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[2196],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeLib_RemoteGetDocumentation_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib *This;
        INT index;
        DWORD refPtrFlags;
        BSTR *pBstrName;
        BSTR *pBstrDocString;
        DWORD *pdwHelpContext;
        BSTR *pBstrHelpFile;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib_GetDocumentation_Stub(
                                         (ITypeLib *) pParamStruct->This,
                                         pParamStruct->index,
                                         pParamStruct->refPtrFlags,
                                         pParamStruct->pBstrName,
                                         pParamStruct->pBstrDocString,
                                         pParamStruct->pdwHelpContext,
                                         pParamStruct->pBstrHelpFile);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeLib_RemoteIsName_Proxy( 
    ITypeLib * This,
    /* [in] */ LPOLESTR szNameBuf,
    /* [in] */ ULONG lHashVal,
    /* [out] */ BOOL *pfName,
    /* [out] */ BSTR *pBstrLibName)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[2262],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeLib_RemoteIsName_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib *This;
        LPOLESTR szNameBuf;
        ULONG lHashVal;
        BOOL *pfName;
        BSTR *pBstrLibName;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib_IsName_Stub(
                               (ITypeLib *) pParamStruct->This,
                               pParamStruct->szNameBuf,
                               pParamStruct->lHashVal,
                               pParamStruct->pfName,
                               pParamStruct->pBstrLibName);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeLib_RemoteFindName_Proxy( 
    ITypeLib * This,
    /* [in] */ LPOLESTR szNameBuf,
    /* [in] */ ULONG lHashVal,
    /* [length_is][size_is][out] */ ITypeInfo **ppTInfo,
    /* [length_is][size_is][out] */ MEMBERID *rgMemId,
    /* [out][in] */ USHORT *pcFound,
    /* [out] */ BSTR *pBstrLibName)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[2316],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeLib_RemoteFindName_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib *This;
        LPOLESTR szNameBuf;
        ULONG lHashVal;
        ITypeInfo **ppTInfo;
        MEMBERID *rgMemId;
        USHORT *pcFound;
        BSTR *pBstrLibName;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib_FindName_Stub(
                                 (ITypeLib *) pParamStruct->This,
                                 pParamStruct->szNameBuf,
                                 pParamStruct->lHashVal,
                                 pParamStruct->ppTInfo,
                                 pParamStruct->rgMemId,
                                 pParamStruct->pcFound,
                                 pParamStruct->pBstrLibName);
    
}

void __RPC_API
ITypeLib_LocalReleaseTLibAttr_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib_ReleaseTLibAttr_Stub((ITypeLib *) pParamStruct->This);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITypeLib2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITypeLib2_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeLib2_RemoteGetLibStatistics_Proxy( 
    ITypeLib2 * This,
    /* [out] */ ULONG *pcUniqueNames,
    /* [out] */ ULONG *pcchUniqueNames)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[2454],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeLib2_RemoteGetLibStatistics_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib2 *This;
        ULONG *pcUniqueNames;
        ULONG *pcchUniqueNames;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib2_GetLibStatistics_Stub(
                                          (ITypeLib2 *) pParamStruct->This,
                                          pParamStruct->pcUniqueNames,
                                          pParamStruct->pcchUniqueNames);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE ITypeLib2_RemoteGetDocumentation2_Proxy( 
    ITypeLib2 * This,
    /* [in] */ INT index,
    /* [in] */ LCID lcid,
    /* [in] */ DWORD refPtrFlags,
    /* [out] */ BSTR *pbstrHelpString,
    /* [out] */ DWORD *pdwHelpStringContext,
    /* [out] */ BSTR *pbstrHelpStringDll)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[2496],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
ITypeLib2_RemoteGetDocumentation2_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        ITypeLib2 *This;
        INT index;
        LCID lcid;
        DWORD refPtrFlags;
        BSTR *pbstrHelpString;
        DWORD *pdwHelpStringContext;
        BSTR *pbstrHelpStringDll;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = ITypeLib2_GetDocumentation2_Stub(
                                           (ITypeLib2 *) pParamStruct->This,
                                           pParamStruct->index,
                                           pParamStruct->lcid,
                                           pParamStruct->refPtrFlags,
                                           pParamStruct->pbstrHelpString,
                                           pParamStruct->pdwHelpStringContext,
                                           pParamStruct->pbstrHelpStringDll);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IErrorInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IErrorInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICreateErrorInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ICreateErrorInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISupportErrorInfo_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISupportErrorInfo_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITypeFactory_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITypeFactory_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IErrorLog_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IErrorLog_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IPropertyBag_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IPropertyBag_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IPropertyBag_RemoteRead_Proxy( 
    IPropertyBag * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [out] */ VARIANT *pVar,
    /* [in] */ IErrorLog *pErrorLog,
    /* [in] */ DWORD varType,
    /* [in] */ IUnknown *pUnkObj)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oaidl__MIDL_ProcFormatString.Format[3048],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IPropertyBag_RemoteRead_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IPropertyBag *This;
        LPCOLESTR pszPropName;
        VARIANT *pVar;
        IErrorLog *pErrorLog;
        DWORD varType;
        IUnknown *pUnkObj;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IPropertyBag_Read_Stub(
                                 (IPropertyBag *) pParamStruct->This,
                                 pParamStruct->pszPropName,
                                 pParamStruct->pVar,
                                 pParamStruct->pErrorLog,
                                 pParamStruct->varType,
                                 pParamStruct->pUnkObj);
    
}


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


static const oaidl_MIDL_PROC_FORMAT_STRING oaidl__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RemoteGetTypeInfoCount */


	/* Procedure GetTypeInfoCount */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x24 ),	/* 36 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcTInfo */


	/* Parameter pctinfo */

/* 24 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeInfo */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 46 */	NdrFcShort( 0x10 ),	/* 16 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter iTInfo */

/* 60 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lcid */

/* 66 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppTInfo */

/* 72 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIDsOfNames */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x5 ),	/* 5 */
/* 92 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 94 */	NdrFcShort( 0x54 ),	/* 84 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 100 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 102 */	NdrFcShort( 0x1 ),	/* 1 */
/* 104 */	NdrFcShort( 0x1 ),	/* 1 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 108 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 112 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter rgszNames */

/* 114 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 116 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 118 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter cNames */

/* 120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lcid */

/* 126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 128 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgDispId */

/* 132 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 134 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 136 */	NdrFcShort( 0x5a ),	/* Type Offset=90 */

	/* Return value */

/* 138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 140 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteInvoke */

/* 144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x6 ),	/* 6 */
/* 152 */	NdrFcShort( 0x34 ),	/* x86 Stack size/offset = 52 */
/* 154 */	NdrFcShort( 0x64 ),	/* 100 */
/* 156 */	NdrFcShort( 0x24 ),	/* 36 */
/* 158 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xc,		/* 12 */
/* 160 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 162 */	NdrFcShort( 0x18e ),	/* 398 */
/* 164 */	NdrFcShort( 0x16d ),	/* 365 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dispIdMember */

/* 168 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 170 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 174 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 176 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 178 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter lcid */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwFlags */

/* 186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 188 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pDispParams */

/* 192 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 194 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 196 */	NdrFcShort( 0x45e ),	/* Type Offset=1118 */

	/* Parameter pVarResult */

/* 198 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 200 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 202 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Parameter pExcepInfo */

/* 204 */	NdrFcShort( 0x8113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=32 */
/* 206 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 208 */	NdrFcShort( 0x498 ),	/* Type Offset=1176 */

	/* Parameter pArgErr */

/* 210 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 212 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter cVarRef */

/* 216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 218 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgVarRefIdx */

/* 222 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 224 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 226 */	NdrFcShort( 0x4b8 ),	/* Type Offset=1208 */

	/* Parameter rgVarRef */

/* 228 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 230 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 232 */	NdrFcShort( 0x4c8 ),	/* Type Offset=1224 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x3 ),	/* 3 */
/* 248 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 252 */	NdrFcShort( 0x24 ),	/* 36 */
/* 254 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 256 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 258 */	NdrFcShort( 0xe2 ),	/* 226 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 264 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgVar */

/* 270 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 274 */	NdrFcShort( 0x4e2 ),	/* Type Offset=1250 */

	/* Parameter pCeltFetched */

/* 276 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x4 ),	/* 4 */
/* 296 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 302 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 312 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x5 ),	/* 5 */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 340 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x6 ),	/* 6 */
/* 362 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 370 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 378 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 380 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 382 */	NdrFcShort( 0x4f8 ),	/* Type Offset=1272 */

	/* Return value */

/* 384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 386 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteBind */

/* 390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x3 ),	/* 3 */
/* 398 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 400 */	NdrFcShort( 0xe ),	/* 14 */
/* 402 */	NdrFcShort( 0x40 ),	/* 64 */
/* 404 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 406 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 408 */	NdrFcShort( 0xa47 ),	/* 2631 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 414 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 416 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 418 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Parameter lHashVal */

/* 420 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter wFlags */

/* 426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 428 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 430 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter ppTInfo */

/* 432 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 434 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 436 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Parameter pDescKind */

/* 438 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 440 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 442 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter ppFuncDesc */

/* 444 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 446 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 448 */	NdrFcShort( 0x516 ),	/* Type Offset=1302 */

	/* Parameter ppVarDesc */

/* 450 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 452 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 454 */	NdrFcShort( 0x5f4 ),	/* Type Offset=1524 */

	/* Parameter ppTypeComp */

/* 456 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 458 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 460 */	NdrFcShort( 0x642 ),	/* Type Offset=1602 */

	/* Parameter pDummy */

/* 462 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 464 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 466 */	NdrFcShort( 0x65e ),	/* Type Offset=1630 */

	/* Return value */

/* 468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 470 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteBindType */

/* 474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x4 ),	/* 4 */
/* 482 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 484 */	NdrFcShort( 0x8 ),	/* 8 */
/* 486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 488 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 490 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szName */

/* 498 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 502 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Parameter lHashVal */

/* 504 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 506 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppTInfo */

/* 510 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 512 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 514 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 518 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetTypeAttr */

/* 522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x3 ),	/* 3 */
/* 530 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x24 ),	/* 36 */
/* 536 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 538 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 540 */	NdrFcShort( 0x2 ),	/* 2 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTypeAttr */

/* 546 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 550 */	NdrFcShort( 0x668 ),	/* Type Offset=1640 */

	/* Parameter pDummy */

/* 552 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 554 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 556 */	NdrFcShort( 0x6aa ),	/* Type Offset=1706 */

	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 560 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeComp */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x4 ),	/* 4 */
/* 572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 578 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 580 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTComp */

/* 588 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 592 */	NdrFcShort( 0x642 ),	/* Type Offset=1602 */

	/* Return value */

/* 594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 596 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetFuncDesc */

/* 600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x5 ),	/* 5 */
/* 608 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 612 */	NdrFcShort( 0x24 ),	/* 36 */
/* 614 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 616 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 618 */	NdrFcShort( 0xc60 ),	/* 3168 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 626 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppFuncDesc */

/* 630 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 632 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 634 */	NdrFcShort( 0x516 ),	/* Type Offset=1302 */

	/* Parameter pDummy */

/* 636 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 638 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 640 */	NdrFcShort( 0x6ba ),	/* Type Offset=1722 */

	/* Return value */

/* 642 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 644 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 646 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetVarDesc */

/* 648 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 650 */	NdrFcLong( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x6 ),	/* 6 */
/* 656 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 660 */	NdrFcShort( 0x24 ),	/* 36 */
/* 662 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 664 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 666 */	NdrFcShort( 0xaab ),	/* 2731 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 672 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 674 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppVarDesc */

/* 678 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 680 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 682 */	NdrFcShort( 0x5f4 ),	/* Type Offset=1524 */

	/* Parameter pDummy */

/* 684 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 688 */	NdrFcShort( 0x6ca ),	/* Type Offset=1738 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 692 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetNames */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x7 ),	/* 7 */
/* 704 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 706 */	NdrFcShort( 0x10 ),	/* 16 */
/* 708 */	NdrFcShort( 0x24 ),	/* 36 */
/* 710 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 712 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 714 */	NdrFcShort( 0x2 ),	/* 2 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter memid */

/* 720 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 722 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgBstrNames */

/* 726 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 728 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 730 */	NdrFcShort( 0x6d8 ),	/* Type Offset=1752 */

	/* Parameter cMaxNames */

/* 732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcNames */

/* 738 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 740 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 746 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRefTypeOfImplType */

/* 750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 760 */	NdrFcShort( 0x8 ),	/* 8 */
/* 762 */	NdrFcShort( 0x24 ),	/* 36 */
/* 764 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 766 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 774 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRefType */

/* 780 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 782 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetImplTypeFlags */

/* 792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x9 ),	/* 9 */
/* 800 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 802 */	NdrFcShort( 0x8 ),	/* 8 */
/* 804 */	NdrFcShort( 0x24 ),	/* 36 */
/* 806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 816 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pImplTypeFlags */

/* 822 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 830 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LocalGetIDsOfNames */

/* 834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0xa ),	/* 10 */
/* 842 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 850 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LocalInvoke */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0xb ),	/* 11 */
/* 872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 880 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetDocumentation */

/* 894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0xc ),	/* 12 */
/* 902 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 904 */	NdrFcShort( 0x10 ),	/* 16 */
/* 906 */	NdrFcShort( 0x24 ),	/* 36 */
/* 908 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 910 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 912 */	NdrFcShort( 0x18 ),	/* 24 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter memid */

/* 918 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 920 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter refPtrFlags */

/* 924 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 926 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBstrName */

/* 930 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 932 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 934 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pBstrDocString */

/* 936 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 938 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 940 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pdwHelpContext */

/* 942 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 944 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBstrHelpFile */

/* 948 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 950 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 952 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetDllEntry */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0xd ),	/* 13 */
/* 968 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 970 */	NdrFcShort( 0x18 ),	/* 24 */
/* 972 */	NdrFcShort( 0x22 ),	/* 34 */
/* 974 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 976 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 978 */	NdrFcShort( 0x10 ),	/* 16 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter memid */

/* 984 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invKind */

/* 990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 994 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter refPtrFlags */

/* 996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBstrDllName */

/* 1002 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1004 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1006 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pBstrName */

/* 1008 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1010 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1012 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pwOrdinal */

/* 1014 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1016 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1018 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRefTypeInfo */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0xe ),	/* 14 */
/* 1034 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hRefType */

/* 1050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppTInfo */

/* 1056 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1060 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LocalAddressOfMember */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0xf ),	/* 15 */
/* 1076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1082 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1084 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteCreateInstance */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1106 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1108 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1112 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1114 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1116 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 1122 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppvObj */

/* 1128 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	NdrFcShort( 0x6f6 ),	/* Type Offset=1782 */

	/* Return value */

/* 1134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1136 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMops */

/* 1140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1148 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1156 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter memid */

/* 1164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1166 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBstrMops */

/* 1170 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1172 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1174 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 1176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1178 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetContainingTypeLib */

/* 1182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1190 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1196 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1198 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTLib */

/* 1206 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1208 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1210 */	NdrFcShort( 0x702 ),	/* Type Offset=1794 */

	/* Parameter pIndex */

/* 1212 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1214 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1220 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LocalReleaseTypeAttr */

/* 1224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1232 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1238 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1240 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1250 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LocalReleaseFuncDesc */

/* 1254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1262 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1268 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1270 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LocalReleaseVarDesc */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1292 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1300 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeKind */

/* 1314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1330 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTypeKind */

/* 1338 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1342 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeFlags */

/* 1350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1364 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1366 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTypeFlags */

/* 1374 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFuncIndexOfMemId */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1394 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1396 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1398 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1400 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter memid */

/* 1410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter invKind */

/* 1416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1420 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pFuncIndex */

/* 1422 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1430 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVarIndexOfMemId */

/* 1434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1442 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1444 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1446 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1448 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1450 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1456 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter memid */

/* 1458 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1460 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVarIndex */

/* 1464 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1466 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCustData */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1484 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1486 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1492 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1494 */	NdrFcShort( 0x18a ),	/* 394 */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter guid */

/* 1500 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pVarVal */

/* 1506 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1510 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 1512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1514 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFuncCustData */

/* 1518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1526 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1528 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1532 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1534 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1536 */	NdrFcShort( 0x6de ),	/* 1758 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 1542 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter guid */

/* 1548 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1552 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pVarVal */

/* 1554 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1556 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1558 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 1560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1562 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetParamCustData */

/* 1566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1574 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1576 */	NdrFcShort( 0x54 ),	/* 84 */
/* 1578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1580 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1582 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1584 */	NdrFcShort( 0x6de ),	/* 1758 */
/* 1586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter indexFunc */

/* 1590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter indexParam */

/* 1596 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter guid */

/* 1602 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1604 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1606 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pVarVal */

/* 1608 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1610 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1612 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 1614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1616 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVarCustData */

/* 1620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1628 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1630 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1634 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1636 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1638 */	NdrFcShort( 0x6de ),	/* 1758 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 1644 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter guid */

/* 1650 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1654 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pVarVal */

/* 1656 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1658 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1660 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 1662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1664 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetImplTypeCustData */

/* 1668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1676 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1678 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1682 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1684 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1686 */	NdrFcShort( 0x6de ),	/* 1758 */
/* 1688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 1692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1694 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter guid */

/* 1698 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1700 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1702 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pVarVal */

/* 1704 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1706 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1708 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 1710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1712 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetDocumentation2 */

/* 1716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1724 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1726 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1728 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1730 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 1732 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1734 */	NdrFcShort( 0xb ),	/* 11 */
/* 1736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter memid */

/* 1740 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lcid */

/* 1746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1748 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter refPtrFlags */

/* 1752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbstrHelpString */

/* 1758 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1760 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1762 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pdwHelpStringContext */

/* 1764 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1766 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbstrHelpStringDll */

/* 1770 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1772 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1774 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 1776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1778 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAllCustData */

/* 1782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1790 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1796 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1798 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1800 */	NdrFcShort( 0x18d ),	/* 397 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCustData */

/* 1806 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1810 */	NdrFcShort( 0x744 ),	/* Type Offset=1860 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAllFuncCustData */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1826 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1834 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1836 */	NdrFcShort( 0x18f ),	/* 399 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 1842 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCustData */

/* 1848 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1852 */	NdrFcShort( 0x744 ),	/* Type Offset=1860 */

	/* Return value */

/* 1854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1856 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAllParamCustData */

/* 1860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1868 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1870 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1874 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1876 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1878 */	NdrFcShort( 0x18f ),	/* 399 */
/* 1880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter indexFunc */

/* 1884 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1886 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter indexParam */

/* 1890 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1892 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCustData */

/* 1896 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1898 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1900 */	NdrFcShort( 0x744 ),	/* Type Offset=1860 */

	/* Return value */

/* 1902 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1904 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1906 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAllVarCustData */

/* 1908 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1910 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1914 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1916 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1922 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1924 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1926 */	NdrFcShort( 0x18f ),	/* 399 */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 1932 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1934 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCustData */

/* 1938 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1940 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1942 */	NdrFcShort( 0x744 ),	/* Type Offset=1860 */

	/* Return value */

/* 1944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1946 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAllImplTypeCustData */

/* 1950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1958 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1964 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1966 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1968 */	NdrFcShort( 0x18f ),	/* 399 */
/* 1970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 1974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1976 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCustData */

/* 1980 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1982 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1984 */	NdrFcShort( 0x744 ),	/* Type Offset=1860 */

	/* Return value */

/* 1986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1988 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeInfo */

/* 1992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2000 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2006 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2008 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2016 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2018 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppTInfo */

/* 2022 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2024 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2026 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 2028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2030 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeInfoType */

/* 2034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2040 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2042 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2046 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2048 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2050 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2060 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTKind */

/* 2064 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2068 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 2070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2072 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeInfoOfGuid */

/* 2076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2084 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2086 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2090 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2092 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter guid */

/* 2100 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2104 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppTinfo */

/* 2106 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2110 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetLibAttr */

/* 2118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2126 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2132 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2134 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTLibAttr */

/* 2142 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2146 */	NdrFcShort( 0x754 ),	/* Type Offset=1876 */

	/* Parameter pDummy */

/* 2148 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2152 */	NdrFcShort( 0x776 ),	/* Type Offset=1910 */

	/* Return value */

/* 2154 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2156 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTypeComp */

/* 2160 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2172 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2174 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2176 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTComp */

/* 2184 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2186 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2188 */	NdrFcShort( 0x642 ),	/* Type Offset=1602 */

	/* Return value */

/* 2190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2192 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetDocumentation */

/* 2196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2204 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2206 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2208 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2210 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 2212 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2214 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter refPtrFlags */

/* 2226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBstrName */

/* 2232 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2236 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pBstrDocString */

/* 2238 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2240 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2242 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pdwHelpContext */

/* 2244 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2246 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBstrHelpFile */

/* 2250 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2252 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2254 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 2256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2258 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteIsName */

/* 2262 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0xa ),	/* 10 */
/* 2270 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2274 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2276 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2278 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2280 */	NdrFcShort( 0xc ),	/* 12 */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szNameBuf */

/* 2286 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2288 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2290 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Parameter lHashVal */

/* 2292 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pfName */

/* 2298 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2300 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pBstrLibName */

/* 2304 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2306 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2308 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 2310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2312 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteFindName */

/* 2316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0xb ),	/* 11 */
/* 2324 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2326 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2328 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2330 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2332 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2334 */	NdrFcShort( 0xe ),	/* 14 */
/* 2336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szNameBuf */

/* 2340 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2342 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2344 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Parameter lHashVal */

/* 2346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2348 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppTInfo */

/* 2352 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2354 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2356 */	NdrFcShort( 0x784 ),	/* Type Offset=1924 */

	/* Parameter rgMemId */

/* 2358 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2360 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2362 */	NdrFcShort( 0x79e ),	/* Type Offset=1950 */

	/* Parameter pcFound */

/* 2364 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2366 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2368 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pBstrLibName */

/* 2370 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2372 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2374 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 2376 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2378 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2380 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LocalReleaseTLibAttr */

/* 2382 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2384 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2388 */	NdrFcShort( 0xc ),	/* 12 */
/* 2390 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2394 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2396 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2398 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2406 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2408 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCustData */

/* 2412 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2414 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0xd ),	/* 13 */
/* 2420 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2422 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2426 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2428 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2430 */	NdrFcShort( 0x18e ),	/* 398 */
/* 2432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2434 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter guid */

/* 2436 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2438 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2440 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pVarVal */

/* 2442 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2444 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2446 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 2448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2450 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetLibStatistics */

/* 2454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0xe ),	/* 14 */
/* 2462 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2466 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2468 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2470 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pcUniqueNames */

/* 2478 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pcchUniqueNames */

/* 2484 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2492 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetDocumentation2 */

/* 2496 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0xf ),	/* 15 */
/* 2504 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2506 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2508 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2510 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x7,		/* 7 */
/* 2512 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2514 */	NdrFcShort( 0xf ),	/* 15 */
/* 2516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2522 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lcid */

/* 2526 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2528 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter refPtrFlags */

/* 2532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2534 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbstrHelpString */

/* 2538 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2540 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2542 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Parameter pdwHelpStringContext */

/* 2544 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2546 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbstrHelpStringDll */

/* 2550 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2552 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2554 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 2556 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2558 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAllCustData */

/* 2562 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2564 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2568 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2570 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2576 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2578 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2580 */	NdrFcShort( 0x18f ),	/* 399 */
/* 2582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2584 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCustData */

/* 2586 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2588 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2590 */	NdrFcShort( 0x744 ),	/* Type Offset=1860 */

	/* Return value */

/* 2592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2594 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGUID */

/* 2598 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2604 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2606 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2612 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2614 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2620 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pGUID */

/* 2622 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2624 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2626 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 2628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2630 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSource */

/* 2634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2642 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2648 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2650 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2652 */	NdrFcShort( 0xe ),	/* 14 */
/* 2654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBstrSource */

/* 2658 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2660 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2662 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 2664 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2666 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2668 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDescription */

/* 2670 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2672 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2676 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2678 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2682 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2684 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2686 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2688 */	NdrFcShort( 0xe ),	/* 14 */
/* 2690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2692 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBstrDescription */

/* 2694 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2696 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2698 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 2700 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2702 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHelpFile */

/* 2706 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2708 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2712 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2714 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2718 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2720 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2722 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2724 */	NdrFcShort( 0xe ),	/* 14 */
/* 2726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2728 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBstrHelpFile */

/* 2730 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2732 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2734 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 2736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2738 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHelpContext */

/* 2742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2748 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2750 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2754 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2756 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2758 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2764 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdwHelpContext */

/* 2766 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2768 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2772 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2774 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2776 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InterfaceSupportsErrorInfo */


	/* Procedure SetGUID */

/* 2778 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2780 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2784 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2786 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2788 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2790 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2792 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2794 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2800 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */


	/* Parameter rguid */

/* 2802 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2804 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2806 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */


	/* Return value */

/* 2808 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2810 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSource */

/* 2814 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2816 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2822 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2828 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2830 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2836 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szSource */

/* 2838 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2840 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2842 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Return value */

/* 2844 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2846 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2848 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDescription */

/* 2850 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2852 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2858 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2864 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2866 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szDescription */

/* 2874 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2876 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2878 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Return value */

/* 2880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2882 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHelpFile */

/* 2886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2892 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2894 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2900 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2902 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szHelpFile */

/* 2910 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2912 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2914 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Return value */

/* 2916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2918 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHelpContext */

/* 2922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2930 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2932 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2936 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2938 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2944 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwHelpContext */

/* 2946 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2948 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2952 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2954 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFromTypeInfo */

/* 2958 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2966 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2968 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2972 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2974 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2976 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2980 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTypeInfo */

/* 2982 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2984 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2986 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter riid */

/* 2988 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2990 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2992 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppv */

/* 2994 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2996 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2998 */	NdrFcShort( 0x7b8 ),	/* Type Offset=1976 */

	/* Return value */

/* 3000 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3002 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddError */

/* 3006 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3008 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3012 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3014 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3018 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3020 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3022 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3026 */	NdrFcShort( 0x1f ),	/* 31 */
/* 3028 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszPropName */

/* 3030 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3032 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3034 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Parameter pExcepInfo */

/* 3036 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3038 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3040 */	NdrFcShort( 0x498 ),	/* Type Offset=1176 */

	/* Return value */

/* 3042 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3044 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteRead */

/* 3048 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3054 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3056 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3058 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3060 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3062 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 3064 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3066 */	NdrFcShort( 0x9f8 ),	/* 2552 */
/* 3068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3070 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszPropName */

/* 3072 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3074 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3076 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Parameter pVar */

/* 3078 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3080 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3082 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Parameter pErrorLog */

/* 3084 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3086 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3088 */	NdrFcShort( 0x7c8 ),	/* Type Offset=1992 */

	/* Parameter varType */

/* 3090 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3092 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pUnkObj */

/* 3096 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3098 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3100 */	NdrFcShort( 0x1aa ),	/* Type Offset=426 */

	/* Return value */

/* 3102 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3104 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 3108 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3110 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3114 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3120 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3122 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3124 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3128 */	NdrFcShort( 0x11c ),	/* 284 */
/* 3130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszPropName */

/* 3132 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3134 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3136 */	NdrFcShort( 0x510 ),	/* Type Offset=1296 */

	/* Parameter pVar */

/* 3138 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3140 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3142 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 3144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const oaidl_MIDL_TYPE_FORMAT_STRING oaidl__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 12 */	NdrFcLong( 0x20401 ),	/* 132097 */
/* 16 */	NdrFcShort( 0x0 ),	/* 0 */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 22 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 24 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 26 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 28 */	
			0x11, 0x0,	/* FC_RP */
/* 30 */	NdrFcShort( 0x8 ),	/* Offset= 8 (38) */
/* 32 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 38 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 40 */	NdrFcShort( 0x10 ),	/* 16 */
/* 42 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 44 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 46 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (32) */
			0x5b,		/* FC_END */
/* 50 */	
			0x11, 0x0,	/* FC_RP */
/* 52 */	NdrFcShort( 0x2 ),	/* Offset= 2 (54) */
/* 54 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 56 */	NdrFcShort( 0x4 ),	/* 4 */
/* 58 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 60 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 62 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 64 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 66 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 68 */	NdrFcShort( 0x4 ),	/* 4 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x1 ),	/* 1 */
/* 74 */	NdrFcShort( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 80 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 82 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 84 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 86 */	
			0x11, 0x0,	/* FC_RP */
/* 88 */	NdrFcShort( 0x2 ),	/* Offset= 2 (90) */
/* 90 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 92 */	NdrFcShort( 0x4 ),	/* 4 */
/* 94 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 96 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 98 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 100 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 102 */	
			0x11, 0x0,	/* FC_RP */
/* 104 */	NdrFcShort( 0x3f6 ),	/* Offset= 1014 (1118) */
/* 106 */	
			0x12, 0x0,	/* FC_UP */
/* 108 */	NdrFcShort( 0x3b2 ),	/* Offset= 946 (1054) */
/* 110 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x7,		/* FC_USHORT */
/* 112 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 114 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 116 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 118 */	NdrFcShort( 0x2 ),	/* Offset= 2 (120) */
/* 120 */	NdrFcShort( 0x10 ),	/* 16 */
/* 122 */	NdrFcShort( 0x2b ),	/* 43 */
/* 124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x0 ),	/* Offset= 0 (128) */
/* 130 */	NdrFcLong( 0x1 ),	/* 1 */
/* 134 */	NdrFcShort( 0x0 ),	/* Offset= 0 (134) */
/* 136 */	NdrFcLong( 0x10 ),	/* 16 */
/* 140 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 142 */	NdrFcLong( 0x12 ),	/* 18 */
/* 146 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 148 */	NdrFcLong( 0x13 ),	/* 19 */
/* 152 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 154 */	NdrFcLong( 0x16 ),	/* 22 */
/* 158 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 160 */	NdrFcLong( 0x17 ),	/* 23 */
/* 164 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 166 */	NdrFcLong( 0x11 ),	/* 17 */
/* 170 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 172 */	NdrFcLong( 0x2 ),	/* 2 */
/* 176 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 178 */	NdrFcLong( 0x3 ),	/* 3 */
/* 182 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 184 */	NdrFcLong( 0x4 ),	/* 4 */
/* 188 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 190 */	NdrFcLong( 0x5 ),	/* 5 */
/* 194 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 196 */	NdrFcLong( 0xb ),	/* 11 */
/* 200 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 202 */	NdrFcLong( 0xa ),	/* 10 */
/* 206 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 208 */	NdrFcLong( 0x7 ),	/* 7 */
/* 212 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 214 */	NdrFcLong( 0x8 ),	/* 8 */
/* 218 */	NdrFcShort( 0xa6 ),	/* Offset= 166 (384) */
/* 220 */	NdrFcLong( 0x6 ),	/* 6 */
/* 224 */	NdrFcShort( 0xba ),	/* Offset= 186 (410) */
/* 226 */	NdrFcLong( 0xe ),	/* 14 */
/* 230 */	NdrFcShort( 0xba ),	/* Offset= 186 (416) */
/* 232 */	NdrFcLong( 0xd ),	/* 13 */
/* 236 */	NdrFcShort( 0xbe ),	/* Offset= 190 (426) */
/* 238 */	NdrFcLong( 0x9 ),	/* 9 */
/* 242 */	NdrFcShort( 0xca ),	/* Offset= 202 (444) */
/* 244 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 248 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (462) */
/* 250 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 254 */	NdrFcShort( 0x2e8 ),	/* Offset= 744 (998) */
/* 256 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 260 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (1002) */
/* 262 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 266 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (1006) */
/* 268 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 272 */	NdrFcShort( 0x2de ),	/* Offset= 734 (1006) */
/* 274 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 278 */	NdrFcShort( 0x2d8 ),	/* Offset= 728 (1006) */
/* 280 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 284 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (998) */
/* 286 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 290 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (1002) */
/* 292 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 296 */	NdrFcShort( 0x2c6 ),	/* Offset= 710 (1006) */
/* 298 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 302 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (1010) */
/* 304 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 308 */	NdrFcShort( 0x2c2 ),	/* Offset= 706 (1014) */
/* 310 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 314 */	NdrFcShort( 0x2b0 ),	/* Offset= 688 (1002) */
/* 316 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 320 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (1006) */
/* 322 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 326 */	NdrFcShort( 0x2b0 ),	/* Offset= 688 (1014) */
/* 328 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 332 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (1018) */
/* 334 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 338 */	NdrFcShort( 0x2ac ),	/* Offset= 684 (1022) */
/* 340 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 344 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (1030) */
/* 346 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 350 */	NdrFcShort( 0x2ac ),	/* Offset= 684 (1034) */
/* 352 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 356 */	NdrFcShort( 0x2aa ),	/* Offset= 682 (1038) */
/* 358 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 362 */	NdrFcShort( 0x2a8 ),	/* Offset= 680 (1042) */
/* 364 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 368 */	NdrFcShort( 0x2a6 ),	/* Offset= 678 (1046) */
/* 370 */	NdrFcLong( 0x24 ),	/* 36 */
/* 374 */	NdrFcShort( 0x2a4 ),	/* Offset= 676 (1050) */
/* 376 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 380 */	NdrFcShort( 0x29e ),	/* Offset= 670 (1050) */
/* 382 */	NdrFcShort( 0xffff ),	/* Offset= -1 (381) */
/* 384 */	
			0x12, 0x0,	/* FC_UP */
/* 386 */	NdrFcShort( 0xe ),	/* Offset= 14 (400) */
/* 388 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 390 */	NdrFcShort( 0x2 ),	/* 2 */
/* 392 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 394 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 396 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 398 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 400 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 404 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (388) */
/* 406 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 408 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 410 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 414 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 416 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 418 */	NdrFcShort( 0x10 ),	/* 16 */
/* 420 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 422 */	0x2,		/* FC_CHAR */
			0x8,		/* FC_LONG */
/* 424 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 426 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 438 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 440 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 442 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 444 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 446 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 454 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 456 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 458 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 460 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 462 */	
			0x12, 0x0,	/* FC_UP */
/* 464 */	NdrFcShort( 0x204 ),	/* Offset= 516 (980) */
/* 466 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 468 */	NdrFcShort( 0x18 ),	/* 24 */
/* 470 */	NdrFcShort( 0xa ),	/* 10 */
/* 472 */	NdrFcLong( 0x8 ),	/* 8 */
/* 476 */	NdrFcShort( 0x5a ),	/* Offset= 90 (566) */
/* 478 */	NdrFcLong( 0xd ),	/* 13 */
/* 482 */	NdrFcShort( 0x7e ),	/* Offset= 126 (608) */
/* 484 */	NdrFcLong( 0x9 ),	/* 9 */
/* 488 */	NdrFcShort( 0x9e ),	/* Offset= 158 (646) */
/* 490 */	NdrFcLong( 0xc ),	/* 12 */
/* 494 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (694) */
/* 496 */	NdrFcLong( 0x24 ),	/* 36 */
/* 500 */	NdrFcShort( 0x124 ),	/* Offset= 292 (792) */
/* 502 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 506 */	NdrFcShort( 0x12e ),	/* Offset= 302 (808) */
/* 508 */	NdrFcLong( 0x10 ),	/* 16 */
/* 512 */	NdrFcShort( 0x148 ),	/* Offset= 328 (840) */
/* 514 */	NdrFcLong( 0x2 ),	/* 2 */
/* 518 */	NdrFcShort( 0x162 ),	/* Offset= 354 (872) */
/* 520 */	NdrFcLong( 0x3 ),	/* 3 */
/* 524 */	NdrFcShort( 0x17c ),	/* Offset= 380 (904) */
/* 526 */	NdrFcLong( 0x14 ),	/* 20 */
/* 530 */	NdrFcShort( 0x196 ),	/* Offset= 406 (936) */
/* 532 */	NdrFcShort( 0xffff ),	/* Offset= -1 (531) */
/* 534 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 536 */	NdrFcShort( 0x4 ),	/* 4 */
/* 538 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 544 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 546 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 548 */	NdrFcShort( 0x4 ),	/* 4 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x1 ),	/* 1 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	0x12, 0x0,	/* FC_UP */
/* 560 */	NdrFcShort( 0xff60 ),	/* Offset= -160 (400) */
/* 562 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 564 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 566 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 568 */	NdrFcShort( 0x8 ),	/* 8 */
/* 570 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 572 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 574 */	NdrFcShort( 0x4 ),	/* 4 */
/* 576 */	NdrFcShort( 0x4 ),	/* 4 */
/* 578 */	0x11, 0x0,	/* FC_RP */
/* 580 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (534) */
/* 582 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 584 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 586 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 596 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 600 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 602 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 604 */	NdrFcShort( 0xff4e ),	/* Offset= -178 (426) */
/* 606 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 608 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x6 ),	/* Offset= 6 (620) */
/* 616 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 618 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 620 */	
			0x11, 0x0,	/* FC_RP */
/* 622 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (586) */
/* 624 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 634 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 638 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 640 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 642 */	NdrFcShort( 0xff3a ),	/* Offset= -198 (444) */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x6 ),	/* Offset= 6 (658) */
/* 654 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 656 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 658 */	
			0x11, 0x0,	/* FC_RP */
/* 660 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (624) */
/* 662 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 664 */	NdrFcShort( 0x4 ),	/* 4 */
/* 666 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 672 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 674 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 676 */	NdrFcShort( 0x4 ),	/* 4 */
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x1 ),	/* 1 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	0x12, 0x0,	/* FC_UP */
/* 688 */	NdrFcShort( 0x16e ),	/* Offset= 366 (1054) */
/* 690 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 692 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 694 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 696 */	NdrFcShort( 0x8 ),	/* 8 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x6 ),	/* Offset= 6 (706) */
/* 702 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 704 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 706 */	
			0x11, 0x0,	/* FC_RP */
/* 708 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (662) */
/* 710 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 712 */	NdrFcLong( 0x2f ),	/* 47 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 720 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 722 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 724 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 726 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 728 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 730 */	NdrFcShort( 0x1 ),	/* 1 */
/* 732 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 734 */	NdrFcShort( 0x4 ),	/* 4 */
/* 736 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 738 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 740 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 742 */	NdrFcShort( 0x10 ),	/* 16 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0xa ),	/* Offset= 10 (756) */
/* 748 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 750 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 752 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (710) */
/* 754 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 756 */	
			0x12, 0x0,	/* FC_UP */
/* 758 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (728) */
/* 760 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 762 */	NdrFcShort( 0x4 ),	/* 4 */
/* 764 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 770 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 772 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 774 */	NdrFcShort( 0x4 ),	/* 4 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x1 ),	/* 1 */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	0x12, 0x0,	/* FC_UP */
/* 786 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (740) */
/* 788 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 790 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 792 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x6 ),	/* Offset= 6 (804) */
/* 800 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 802 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 804 */	
			0x11, 0x0,	/* FC_RP */
/* 806 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (760) */
/* 808 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 810 */	NdrFcShort( 0x18 ),	/* 24 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0xa ),	/* Offset= 10 (824) */
/* 816 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 818 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 820 */	NdrFcShort( 0xfcf2 ),	/* Offset= -782 (38) */
/* 822 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 824 */	
			0x11, 0x0,	/* FC_RP */
/* 826 */	NdrFcShort( 0xff10 ),	/* Offset= -240 (586) */
/* 828 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 830 */	NdrFcShort( 0x1 ),	/* 1 */
/* 832 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 836 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 838 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 840 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 844 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 846 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 848 */	NdrFcShort( 0x4 ),	/* 4 */
/* 850 */	NdrFcShort( 0x4 ),	/* 4 */
/* 852 */	0x12, 0x0,	/* FC_UP */
/* 854 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (828) */
/* 856 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 858 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 860 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 862 */	NdrFcShort( 0x2 ),	/* 2 */
/* 864 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 870 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 872 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 876 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 878 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 880 */	NdrFcShort( 0x4 ),	/* 4 */
/* 882 */	NdrFcShort( 0x4 ),	/* 4 */
/* 884 */	0x12, 0x0,	/* FC_UP */
/* 886 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (860) */
/* 888 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 890 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 892 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 902 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 904 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 908 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 910 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 912 */	NdrFcShort( 0x4 ),	/* 4 */
/* 914 */	NdrFcShort( 0x4 ),	/* 4 */
/* 916 */	0x12, 0x0,	/* FC_UP */
/* 918 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (892) */
/* 920 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 922 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 924 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 928 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 934 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 936 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 942 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 944 */	NdrFcShort( 0x4 ),	/* 4 */
/* 946 */	NdrFcShort( 0x4 ),	/* 4 */
/* 948 */	0x12, 0x0,	/* FC_UP */
/* 950 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (924) */
/* 952 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 954 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 956 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 960 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 962 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 964 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 968 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 970 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 972 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 974 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 976 */	NdrFcShort( 0xffec ),	/* Offset= -20 (956) */
/* 978 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 980 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 982 */	NdrFcShort( 0x28 ),	/* 40 */
/* 984 */	NdrFcShort( 0xffec ),	/* Offset= -20 (964) */
/* 986 */	NdrFcShort( 0x0 ),	/* Offset= 0 (986) */
/* 988 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 990 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 992 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 994 */	NdrFcShort( 0xfdf0 ),	/* Offset= -528 (466) */
/* 996 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 998 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1000 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1002 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1004 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1006 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1008 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1010 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1012 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 1014 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1016 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1018 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1020 */	NdrFcShort( 0xfd84 ),	/* Offset= -636 (384) */
/* 1022 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1024 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1026) */
/* 1026 */	
			0x12, 0x0,	/* FC_UP */
/* 1028 */	NdrFcShort( 0x1a ),	/* Offset= 26 (1054) */
/* 1030 */	
			0x12, 0x0,	/* FC_UP */
/* 1032 */	NdrFcShort( 0xfd92 ),	/* Offset= -622 (410) */
/* 1034 */	
			0x12, 0x0,	/* FC_UP */
/* 1036 */	NdrFcShort( 0xfd94 ),	/* Offset= -620 (416) */
/* 1038 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1040 */	NdrFcShort( 0xfd9a ),	/* Offset= -614 (426) */
/* 1042 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1044 */	NdrFcShort( 0xfda8 ),	/* Offset= -600 (444) */
/* 1046 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1048 */	NdrFcShort( 0xfdb6 ),	/* Offset= -586 (462) */
/* 1050 */	
			0x12, 0x0,	/* FC_UP */
/* 1052 */	NdrFcShort( 0xfec8 ),	/* Offset= -312 (740) */
/* 1054 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1056 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1060) */
/* 1062 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1064 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1066 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1068 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1070 */	NdrFcShort( 0xfc40 ),	/* Offset= -960 (110) */
/* 1072 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1074 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0xfc30 ),	/* Offset= -976 (106) */
/* 1084 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1090 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1092 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1094 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1098 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1100 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1102 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (1074) */
/* 1104 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1106 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1108 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1110 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1112 */	NdrFcShort( 0xc ),	/* 12 */
/* 1114 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1116 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1118 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1120 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x8 ),	/* Offset= 8 (1132) */
/* 1126 */	0x36,		/* FC_POINTER */
			0x36,		/* FC_POINTER */
/* 1128 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1130 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1132 */	
			0x12, 0x0,	/* FC_UP */
/* 1134 */	NdrFcShort( 0xffce ),	/* Offset= -50 (1084) */
/* 1136 */	
			0x12, 0x0,	/* FC_UP */
/* 1138 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (1106) */
/* 1140 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1142 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1148) */
/* 1144 */	
			0x13, 0x0,	/* FC_OP */
/* 1146 */	NdrFcShort( 0xffa4 ),	/* Offset= -92 (1054) */
/* 1148 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1144) */
/* 1158 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1160 */	NdrFcShort( 0x10 ),	/* Offset= 16 (1176) */
/* 1162 */	
			0x13, 0x0,	/* FC_OP */
/* 1164 */	NdrFcShort( 0xfd04 ),	/* Offset= -764 (400) */
/* 1166 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1170 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1174 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1162) */
/* 1176 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1178 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1182) */
/* 1184 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1186 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1188 */	NdrFcShort( 0xffea ),	/* Offset= -22 (1166) */
/* 1190 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1192 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1166) */
/* 1194 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1196 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1166) */
/* 1198 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1200 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1202 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1204 */	
			0x11, 0x0,	/* FC_RP */
/* 1206 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1208) */
/* 1208 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1210 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1212 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1214 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1216 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1218 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1220 */	
			0x11, 0x0,	/* FC_RP */
/* 1222 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1224) */
/* 1224 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1230 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1232 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1234 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1238 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1240 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1242 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (1148) */
/* 1244 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1246 */	
			0x11, 0x0,	/* FC_RP */
/* 1248 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1250) */
/* 1250 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1256 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1258 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1260 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1264 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1266 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1268 */	NdrFcShort( 0xff88 ),	/* Offset= -120 (1148) */
/* 1270 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1272 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1274 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1276) */
/* 1276 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1278 */	NdrFcLong( 0x20404 ),	/* 132100 */
/* 1282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1288 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1290 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1292 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1294 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1296 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1298 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1300 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 1302 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1304 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1306) */
/* 1306 */	
			0x13, 0x0,	/* FC_OP */
/* 1308 */	NdrFcShort( 0xb6 ),	/* Offset= 182 (1490) */
/* 1310 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x7,		/* FC_USHORT */
/* 1312 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1314 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1316 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1318 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1320) */
/* 1320 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1322 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1324 */	NdrFcLong( 0x1a ),	/* 26 */
/* 1328 */	NdrFcShort( 0x16 ),	/* Offset= 22 (1350) */
/* 1330 */	NdrFcLong( 0x1b ),	/* 27 */
/* 1334 */	NdrFcShort( 0x10 ),	/* Offset= 16 (1350) */
/* 1336 */	NdrFcLong( 0x1c ),	/* 28 */
/* 1340 */	NdrFcShort( 0xe ),	/* Offset= 14 (1354) */
/* 1342 */	NdrFcLong( 0x1d ),	/* 29 */
/* 1346 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1348 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1348) */
/* 1350 */	
			0x13, 0x0,	/* FC_OP */
/* 1352 */	NdrFcShort( 0x26 ),	/* Offset= 38 (1390) */
/* 1354 */	
			0x13, 0x0,	/* FC_OP */
/* 1356 */	NdrFcShort( 0x12 ),	/* Offset= 18 (1374) */
/* 1358 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1362 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1364 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 1366 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1368 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1370 */	NdrFcShort( 0xfe62 ),	/* Offset= -414 (956) */
/* 1372 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1374 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1376 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1378 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1358) */
/* 1380 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1380) */
/* 1382 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1384 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1390) */
/* 1386 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1388 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1390 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1392 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1396 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1396) */
/* 1398 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1400 */	NdrFcShort( 0xffa6 ),	/* Offset= -90 (1310) */
/* 1402 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1404 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1406 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1408 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1412) */
/* 1414 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 1416 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1418 */	NdrFcShort( 0xfef2 ),	/* Offset= -270 (1148) */
/* 1420 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1422 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1434) */
/* 1430 */	0x36,		/* FC_POINTER */
			0x6,		/* FC_SHORT */
/* 1432 */	0x3e,		/* FC_STRUCTPAD2 */
			0x5b,		/* FC_END */
/* 1434 */	
			0x13, 0x0,	/* FC_OP */
/* 1436 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1406) */
/* 1438 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1440 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1444 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1444) */
/* 1446 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1448 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (1390) */
/* 1450 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1452 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (1422) */
/* 1454 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1456 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1458 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1460 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x0,		/*  */
/* 1462 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1464 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1466 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1468 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1472 */	0x16,		/* Corr desc:  field pointer, FC_SHORT */
			0x0,		/*  */
/* 1474 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1476 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1478 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1482 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1484 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1486 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (1438) */
/* 1488 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1490 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1492 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1496 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1516) */
/* 1498 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1500 */	0x36,		/* FC_POINTER */
			0xe,		/* FC_ENUM32 */
/* 1502 */	0xe,		/* FC_ENUM32 */
			0xe,		/* FC_ENUM32 */
/* 1504 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1506 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1508 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1510 */	NdrFcShort( 0xffb8 ),	/* Offset= -72 (1438) */
/* 1512 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1514 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1516 */	
			0x13, 0x0,	/* FC_OP */
/* 1518 */	NdrFcShort( 0xffc2 ),	/* Offset= -62 (1456) */
/* 1520 */	
			0x13, 0x0,	/* FC_OP */
/* 1522 */	NdrFcShort( 0xffca ),	/* Offset= -54 (1468) */
/* 1524 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1526 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1528) */
/* 1528 */	
			0x13, 0x0,	/* FC_OP */
/* 1530 */	NdrFcShort( 0x2e ),	/* Offset= 46 (1576) */
/* 1532 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x8,		/* FC_LONG */
/* 1534 */	0x8,		/* Corr desc: FC_LONG */
			0x0,		/*  */
/* 1536 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1538 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1540 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1542) */
/* 1542 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1544 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1550 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1552 */	NdrFcLong( 0x3 ),	/* 3 */
/* 1556 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1558 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1562 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 1564 */	NdrFcLong( 0x2 ),	/* 2 */
/* 1568 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1572) */
/* 1570 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1569) */
/* 1572 */	
			0x13, 0x0,	/* FC_OP */
/* 1574 */	NdrFcShort( 0xfe56 ),	/* Offset= -426 (1148) */
/* 1576 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1578 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x10 ),	/* Offset= 16 (1598) */
/* 1584 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1586 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1588 */	NdrFcShort( 0xffc8 ),	/* Offset= -56 (1532) */
/* 1590 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1592 */	NdrFcShort( 0xff66 ),	/* Offset= -154 (1438) */
/* 1594 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1596 */	0xe,		/* FC_ENUM32 */
			0x5b,		/* FC_END */
/* 1598 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1600 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1602 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1604 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1606) */
/* 1606 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1608 */	NdrFcLong( 0x20403 ),	/* 132099 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1618 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1620 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1622 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1624 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1626 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1630) */
/* 1628 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1630 */	0xb4,		/* FC_USER_MARSHAL */
			0x3,		/* 3 */
/* 1632 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1634 */	NdrFcShort( 0xc ),	/* 12 */
/* 1636 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1638 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (1628) */
/* 1640 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1642 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1644) */
/* 1644 */	
			0x13, 0x0,	/* FC_OP */
/* 1646 */	NdrFcShort( 0xe ),	/* Offset= 14 (1660) */
/* 1648 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1654 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1654) */
/* 1656 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 1658 */	0x3e,		/* FC_STRUCTPAD2 */
			0x5b,		/* FC_END */
/* 1660 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1662 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0x1e ),	/* Offset= 30 (1696) */
/* 1668 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1670 */	NdrFcShort( 0xf9a0 ),	/* Offset= -1632 (38) */
/* 1672 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1674 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1676 */	0x36,		/* FC_POINTER */
			0x8,		/* FC_LONG */
/* 1678 */	0xe,		/* FC_ENUM32 */
			0x6,		/* FC_SHORT */
/* 1680 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1682 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1684 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1686 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1688 */	0x0,		/* 0 */
			NdrFcShort( 0xfed5 ),	/* Offset= -299 (1390) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1692 */	0x0,		/* 0 */
			NdrFcShort( 0xffd3 ),	/* Offset= -45 (1648) */
			0x5b,		/* FC_END */
/* 1696 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1698 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1700 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1702 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1706) */
/* 1704 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1706 */	0xb4,		/* FC_USER_MARSHAL */
			0x3,		/* 3 */
/* 1708 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1710 */	NdrFcShort( 0xc ),	/* 12 */
/* 1712 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1714 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (1704) */
/* 1716 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1718 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1722) */
/* 1720 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1722 */	0xb4,		/* FC_USER_MARSHAL */
			0x3,		/* 3 */
/* 1724 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1726 */	NdrFcShort( 0xc ),	/* 12 */
/* 1728 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1730 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (1720) */
/* 1732 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1734 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1738) */
/* 1736 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1738 */	0xb4,		/* FC_USER_MARSHAL */
			0x3,		/* 3 */
/* 1740 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1742 */	NdrFcShort( 0xc ),	/* 12 */
/* 1744 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1746 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (1736) */
/* 1748 */	
			0x11, 0x0,	/* FC_RP */
/* 1750 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1752) */
/* 1752 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 1758 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1760 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1762 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1764 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1766 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1768 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1770 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (1166) */
/* 1772 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1774 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1776 */	NdrFcShort( 0xfd9e ),	/* Offset= -610 (1166) */
/* 1778 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1780 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1782 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1784 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1786) */
/* 1786 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 1788 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 1790 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1792 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 1794 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1796 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1798) */
/* 1798 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1800 */	NdrFcLong( 0x20402 ),	/* 132098 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1808 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1810 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1812 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1814 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1816 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1818 */	NdrFcShort( 0x2a ),	/* Offset= 42 (1860) */
/* 1820 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1822 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1826 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1826) */
/* 1828 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1830 */	NdrFcShort( 0xf900 ),	/* Offset= -1792 (38) */
/* 1832 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1834 */	NdrFcShort( 0xfd52 ),	/* Offset= -686 (1148) */
/* 1836 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1838 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1842 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1848 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 1852 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1854 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1856 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1820) */
/* 1858 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1860 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1872) */
/* 1868 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 1870 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1872 */	
			0x13, 0x0,	/* FC_OP */
/* 1874 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1838) */
/* 1876 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1878 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1880) */
/* 1880 */	
			0x13, 0x0,	/* FC_OP */
/* 1882 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1884) */
/* 1884 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1886 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1890) */
/* 1892 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1894 */	NdrFcShort( 0xf8c0 ),	/* Offset= -1856 (38) */
/* 1896 */	0x8,		/* FC_LONG */
			0xe,		/* FC_ENUM32 */
/* 1898 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1900 */	0x6,		/* FC_SHORT */
			0x3e,		/* FC_STRUCTPAD2 */
/* 1902 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1904 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1906 */	NdrFcShort( 0x4 ),	/* Offset= 4 (1910) */
/* 1908 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1910 */	0xb4,		/* FC_USER_MARSHAL */
			0x3,		/* 3 */
/* 1912 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1914 */	NdrFcShort( 0xc ),	/* 12 */
/* 1916 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1918 */	NdrFcShort( 0xfff6 ),	/* Offset= -10 (1908) */
/* 1920 */	
			0x11, 0x0,	/* FC_RP */
/* 1922 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1924) */
/* 1924 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x54,		/* FC_DEREFERENCE */
/* 1930 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1932 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1934 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x54,		/* FC_DEREFERENCE */
/* 1936 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1938 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1940 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1942 */	NdrFcShort( 0xf874 ),	/* Offset= -1932 (10) */
/* 1944 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1946 */	
			0x11, 0x0,	/* FC_RP */
/* 1948 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1950) */
/* 1950 */	
			0x1c,		/* FC_CVARRAY */
			0x3,		/* 3 */
/* 1952 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1954 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x54,		/* FC_DEREFERENCE */
/* 1956 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1958 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1960 */	0x27,		/* Corr desc:  parameter, FC_USHORT */
			0x54,		/* FC_DEREFERENCE */
/* 1962 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1964 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1966 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1968 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1970 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1972 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1974 */	NdrFcShort( 0xf870 ),	/* Offset= -1936 (38) */
/* 1976 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1978 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1980) */
/* 1980 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 1982 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 1984 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1986 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 1988 */	
			0x11, 0x0,	/* FC_RP */
/* 1990 */	NdrFcShort( 0xfcd2 ),	/* Offset= -814 (1176) */
/* 1992 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1994 */	NdrFcLong( 0x3127ca40 ),	/* 824691264 */
/* 1998 */	NdrFcShort( 0x446e ),	/* 17518 */
/* 2000 */	NdrFcShort( 0x11ce ),	/* 4558 */
/* 2002 */	0x81,		/* 129 */
			0x35,		/* 53 */
/* 2004 */	0x0,		/* 0 */
			0xaa,		/* 170 */
/* 2006 */	0x0,		/* 0 */
			0x4b,		/* 75 */
/* 2008 */	0xb8,		/* 184 */
			0x51,		/* 81 */
/* 2010 */	0x11, 0x0,	/* FC_RP */
/* 2012 */	NdrFcShort( 0xfc56 ),	/* Offset= -938 (1074) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            CLEANLOCALSTORAGE_UserSize
            ,CLEANLOCALSTORAGE_UserMarshal
            ,CLEANLOCALSTORAGE_UserUnmarshal
            ,CLEANLOCALSTORAGE_UserFree
            }

        };



/* Standard interface: __MIDL_itf_oaidl_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Standard interface: IOleAutomationTypes, ver. 1.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IDispatch_FormatStringOffsetTable[] =
    {
    0,
    36,
    84,
    144
    };

static const MIDL_STUBLESS_PROXY_INFO IDispatch_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &IDispatch_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IDispatch_StubThunkTable[] = 
    {
    0,
    0,
    0,
    IDispatch_RemoteInvoke_Thunk
    };

static const MIDL_SERVER_INFO IDispatch_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &IDispatch_FormatStringOffsetTable[-3],
    &IDispatch_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IDispatchProxyVtbl = 
{
    &IDispatch_ProxyInfo,
    &IID_IDispatch,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    IDispatch_Invoke_Proxy
};

const CInterfaceStubVtbl _IDispatchStubVtbl =
{
    &IID_IDispatch,
    &IDispatch_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumVARIANT, ver. 0.0,
   GUID={0x00020404,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumVARIANT_FormatStringOffsetTable[] =
    {
    240,
    288,
    324,
    354
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumVARIANT_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &IEnumVARIANT_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumVARIANT_StubThunkTable[] = 
    {
    IEnumVARIANT_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumVARIANT_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &IEnumVARIANT_FormatStringOffsetTable[-3],
    &IEnumVARIANT_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumVARIANTProxyVtbl = 
{
    &IEnumVARIANT_ProxyInfo,
    &IID_IEnumVARIANT,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumVARIANT_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumVARIANT::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumVARIANT::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumVARIANT::Clone */
};

const CInterfaceStubVtbl _IEnumVARIANTStubVtbl =
{
    &IID_IEnumVARIANT,
    &IEnumVARIANT_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeComp, ver. 0.0,
   GUID={0x00020403,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ITypeComp_FormatStringOffsetTable[] =
    {
    390,
    474
    };

static const MIDL_STUBLESS_PROXY_INFO ITypeComp_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeComp_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK ITypeComp_StubThunkTable[] = 
    {
    ITypeComp_RemoteBind_Thunk,
    ITypeComp_RemoteBindType_Thunk
    };

static const MIDL_SERVER_INFO ITypeComp_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeComp_FormatStringOffsetTable[-3],
    &ITypeComp_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _ITypeCompProxyVtbl = 
{
    &ITypeComp_ProxyInfo,
    &IID_ITypeComp,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ITypeComp_Bind_Proxy ,
    ITypeComp_BindType_Proxy
};

const CInterfaceStubVtbl _ITypeCompStubVtbl =
{
    &IID_ITypeComp,
    &ITypeComp_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeInfo, ver. 0.0,
   GUID={0x00020401,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ITypeInfo_FormatStringOffsetTable[] =
    {
    522,
    564,
    600,
    648,
    696,
    750,
    792,
    834,
    864,
    894,
    960,
    1026,
    1068,
    1098,
    1140,
    1182,
    1224,
    1254,
    1284
    };

static const MIDL_STUBLESS_PROXY_INFO ITypeInfo_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK ITypeInfo_StubThunkTable[] = 
    {
    ITypeInfo_RemoteGetTypeAttr_Thunk,
    0,
    ITypeInfo_RemoteGetFuncDesc_Thunk,
    ITypeInfo_RemoteGetVarDesc_Thunk,
    ITypeInfo_RemoteGetNames_Thunk,
    0,
    0,
    ITypeInfo_LocalGetIDsOfNames_Thunk,
    ITypeInfo_LocalInvoke_Thunk,
    ITypeInfo_RemoteGetDocumentation_Thunk,
    ITypeInfo_RemoteGetDllEntry_Thunk,
    0,
    ITypeInfo_LocalAddressOfMember_Thunk,
    ITypeInfo_RemoteCreateInstance_Thunk,
    0,
    ITypeInfo_RemoteGetContainingTypeLib_Thunk,
    ITypeInfo_LocalReleaseTypeAttr_Thunk,
    ITypeInfo_LocalReleaseFuncDesc_Thunk,
    ITypeInfo_LocalReleaseVarDesc_Thunk
    };

static const MIDL_SERVER_INFO ITypeInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeInfo_FormatStringOffsetTable[-3],
    &ITypeInfo_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(22) _ITypeInfoProxyVtbl = 
{
    &ITypeInfo_ProxyInfo,
    &IID_ITypeInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ITypeInfo_GetTypeAttr_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetTypeComp */ ,
    ITypeInfo_GetFuncDesc_Proxy ,
    ITypeInfo_GetVarDesc_Proxy ,
    ITypeInfo_GetNames_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetRefTypeOfImplType */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetImplTypeFlags */ ,
    ITypeInfo_GetIDsOfNames_Proxy ,
    ITypeInfo_Invoke_Proxy ,
    ITypeInfo_GetDocumentation_Proxy ,
    ITypeInfo_GetDllEntry_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetRefTypeInfo */ ,
    ITypeInfo_AddressOfMember_Proxy ,
    ITypeInfo_CreateInstance_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetMops */ ,
    ITypeInfo_GetContainingTypeLib_Proxy ,
    ITypeInfo_ReleaseTypeAttr_Proxy ,
    ITypeInfo_ReleaseFuncDesc_Proxy ,
    ITypeInfo_ReleaseVarDesc_Proxy
};

const CInterfaceStubVtbl _ITypeInfoStubVtbl =
{
    &IID_ITypeInfo,
    &ITypeInfo_ServerInfo,
    22,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeInfo2, ver. 0.0,
   GUID={0x00020412,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ITypeInfo2_FormatStringOffsetTable[] =
    {
    522,
    564,
    600,
    648,
    696,
    750,
    792,
    834,
    864,
    894,
    960,
    1026,
    1068,
    1098,
    1140,
    1182,
    1224,
    1254,
    1284,
    1314,
    1350,
    1386,
    1434,
    1476,
    1518,
    1566,
    1620,
    1668,
    1716,
    1782,
    1818,
    1860,
    1908,
    1950
    };

static const MIDL_STUBLESS_PROXY_INFO ITypeInfo2_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeInfo2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK ITypeInfo2_StubThunkTable[] = 
    {
    ITypeInfo_RemoteGetTypeAttr_Thunk,
    0,
    ITypeInfo_RemoteGetFuncDesc_Thunk,
    ITypeInfo_RemoteGetVarDesc_Thunk,
    ITypeInfo_RemoteGetNames_Thunk,
    0,
    0,
    ITypeInfo_LocalGetIDsOfNames_Thunk,
    ITypeInfo_LocalInvoke_Thunk,
    ITypeInfo_RemoteGetDocumentation_Thunk,
    ITypeInfo_RemoteGetDllEntry_Thunk,
    0,
    ITypeInfo_LocalAddressOfMember_Thunk,
    ITypeInfo_RemoteCreateInstance_Thunk,
    0,
    ITypeInfo_RemoteGetContainingTypeLib_Thunk,
    ITypeInfo_LocalReleaseTypeAttr_Thunk,
    ITypeInfo_LocalReleaseFuncDesc_Thunk,
    ITypeInfo_LocalReleaseVarDesc_Thunk,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    ITypeInfo2_RemoteGetDocumentation2_Thunk,
    0,
    0,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO ITypeInfo2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeInfo2_FormatStringOffsetTable[-3],
    &ITypeInfo2_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(37) _ITypeInfo2ProxyVtbl = 
{
    &ITypeInfo2_ProxyInfo,
    &IID_ITypeInfo2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ITypeInfo_GetTypeAttr_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetTypeComp */ ,
    ITypeInfo_GetFuncDesc_Proxy ,
    ITypeInfo_GetVarDesc_Proxy ,
    ITypeInfo_GetNames_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetRefTypeOfImplType */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetImplTypeFlags */ ,
    ITypeInfo_GetIDsOfNames_Proxy ,
    ITypeInfo_Invoke_Proxy ,
    ITypeInfo_GetDocumentation_Proxy ,
    ITypeInfo_GetDllEntry_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetRefTypeInfo */ ,
    ITypeInfo_AddressOfMember_Proxy ,
    ITypeInfo_CreateInstance_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo::GetMops */ ,
    ITypeInfo_GetContainingTypeLib_Proxy ,
    ITypeInfo_ReleaseTypeAttr_Proxy ,
    ITypeInfo_ReleaseFuncDesc_Proxy ,
    ITypeInfo_ReleaseVarDesc_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetTypeKind */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetTypeFlags */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetFuncIndexOfMemId */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetVarIndexOfMemId */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetFuncCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetParamCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetVarCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetImplTypeCustData */ ,
    ITypeInfo2_GetDocumentation2_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetAllCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetAllFuncCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetAllParamCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetAllVarCustData */ ,
    (void *) (INT_PTR) -1 /* ITypeInfo2::GetAllImplTypeCustData */
};

const CInterfaceStubVtbl _ITypeInfo2StubVtbl =
{
    &IID_ITypeInfo2,
    &ITypeInfo2_ServerInfo,
    37,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeLib, ver. 0.0,
   GUID={0x00020402,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ITypeLib_FormatStringOffsetTable[] =
    {
    0,
    1992,
    2034,
    2076,
    2118,
    2160,
    2196,
    2262,
    2316,
    2382
    };

static const MIDL_STUBLESS_PROXY_INFO ITypeLib_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeLib_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK ITypeLib_StubThunkTable[] = 
    {
    ITypeLib_RemoteGetTypeInfoCount_Thunk,
    0,
    0,
    0,
    ITypeLib_RemoteGetLibAttr_Thunk,
    0,
    ITypeLib_RemoteGetDocumentation_Thunk,
    ITypeLib_RemoteIsName_Thunk,
    ITypeLib_RemoteFindName_Thunk,
    ITypeLib_LocalReleaseTLibAttr_Thunk
    };

static const MIDL_SERVER_INFO ITypeLib_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeLib_FormatStringOffsetTable[-3],
    &ITypeLib_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _ITypeLibProxyVtbl = 
{
    &ITypeLib_ProxyInfo,
    &IID_ITypeLib,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ITypeLib_GetTypeInfoCount_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeInfo */ ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeInfoType */ ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeInfoOfGuid */ ,
    ITypeLib_GetLibAttr_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeComp */ ,
    ITypeLib_GetDocumentation_Proxy ,
    ITypeLib_IsName_Proxy ,
    ITypeLib_FindName_Proxy ,
    ITypeLib_ReleaseTLibAttr_Proxy
};

const CInterfaceStubVtbl _ITypeLibStubVtbl =
{
    &IID_ITypeLib,
    &ITypeLib_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeLib2, ver. 0.0,
   GUID={0x00020411,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ITypeLib2_FormatStringOffsetTable[] =
    {
    0,
    1992,
    2034,
    2076,
    2118,
    2160,
    2196,
    2262,
    2316,
    2382,
    2412,
    2454,
    2496,
    2562
    };

static const MIDL_STUBLESS_PROXY_INFO ITypeLib2_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeLib2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK ITypeLib2_StubThunkTable[] = 
    {
    ITypeLib_RemoteGetTypeInfoCount_Thunk,
    0,
    0,
    0,
    ITypeLib_RemoteGetLibAttr_Thunk,
    0,
    ITypeLib_RemoteGetDocumentation_Thunk,
    ITypeLib_RemoteIsName_Thunk,
    ITypeLib_RemoteFindName_Thunk,
    ITypeLib_LocalReleaseTLibAttr_Thunk,
    0,
    ITypeLib2_RemoteGetLibStatistics_Thunk,
    ITypeLib2_RemoteGetDocumentation2_Thunk,
    0
    };

static const MIDL_SERVER_INFO ITypeLib2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeLib2_FormatStringOffsetTable[-3],
    &ITypeLib2_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _ITypeLib2ProxyVtbl = 
{
    &ITypeLib2_ProxyInfo,
    &IID_ITypeLib2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    ITypeLib_GetTypeInfoCount_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeInfo */ ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeInfoType */ ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeInfoOfGuid */ ,
    ITypeLib_GetLibAttr_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeLib::GetTypeComp */ ,
    ITypeLib_GetDocumentation_Proxy ,
    ITypeLib_IsName_Proxy ,
    ITypeLib_FindName_Proxy ,
    ITypeLib_ReleaseTLibAttr_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeLib2::GetCustData */ ,
    ITypeLib2_GetLibStatistics_Proxy ,
    ITypeLib2_GetDocumentation2_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeLib2::GetAllCustData */
};

const CInterfaceStubVtbl _ITypeLib2StubVtbl =
{
    &IID_ITypeLib2,
    &ITypeLib2_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeChangeEvents, ver. 0.0,
   GUID={0x00020410,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IErrorInfo, ver. 0.0,
   GUID={0x1CF2B120,0x547D,0x101B,{0x8E,0x65,0x08,0x00,0x2B,0x2B,0xD1,0x19}} */

#pragma code_seg(".orpc")
static const unsigned short IErrorInfo_FormatStringOffsetTable[] =
    {
    2598,
    2634,
    2670,
    2706,
    2742
    };

static const MIDL_STUBLESS_PROXY_INFO IErrorInfo_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &IErrorInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IErrorInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &IErrorInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IErrorInfoProxyVtbl = 
{
    &IErrorInfo_ProxyInfo,
    &IID_IErrorInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IErrorInfo::GetGUID */ ,
    (void *) (INT_PTR) -1 /* IErrorInfo::GetSource */ ,
    (void *) (INT_PTR) -1 /* IErrorInfo::GetDescription */ ,
    (void *) (INT_PTR) -1 /* IErrorInfo::GetHelpFile */ ,
    (void *) (INT_PTR) -1 /* IErrorInfo::GetHelpContext */
};

const CInterfaceStubVtbl _IErrorInfoStubVtbl =
{
    &IID_IErrorInfo,
    &IErrorInfo_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ICreateErrorInfo, ver. 0.0,
   GUID={0x22F03340,0x547D,0x101B,{0x8E,0x65,0x08,0x00,0x2B,0x2B,0xD1,0x19}} */

#pragma code_seg(".orpc")
static const unsigned short ICreateErrorInfo_FormatStringOffsetTable[] =
    {
    2778,
    2814,
    2850,
    2886,
    2922
    };

static const MIDL_STUBLESS_PROXY_INFO ICreateErrorInfo_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ICreateErrorInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ICreateErrorInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ICreateErrorInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _ICreateErrorInfoProxyVtbl = 
{
    &ICreateErrorInfo_ProxyInfo,
    &IID_ICreateErrorInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ICreateErrorInfo::SetGUID */ ,
    (void *) (INT_PTR) -1 /* ICreateErrorInfo::SetSource */ ,
    (void *) (INT_PTR) -1 /* ICreateErrorInfo::SetDescription */ ,
    (void *) (INT_PTR) -1 /* ICreateErrorInfo::SetHelpFile */ ,
    (void *) (INT_PTR) -1 /* ICreateErrorInfo::SetHelpContext */
};

const CInterfaceStubVtbl _ICreateErrorInfoStubVtbl =
{
    &IID_ICreateErrorInfo,
    &ICreateErrorInfo_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISupportErrorInfo, ver. 0.0,
   GUID={0xDF0B3D60,0x548F,0x101B,{0x8E,0x65,0x08,0x00,0x2B,0x2B,0xD1,0x19}} */

#pragma code_seg(".orpc")
static const unsigned short ISupportErrorInfo_FormatStringOffsetTable[] =
    {
    2778
    };

static const MIDL_STUBLESS_PROXY_INFO ISupportErrorInfo_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ISupportErrorInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISupportErrorInfo_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ISupportErrorInfo_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _ISupportErrorInfoProxyVtbl = 
{
    &ISupportErrorInfo_ProxyInfo,
    &IID_ISupportErrorInfo,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ISupportErrorInfo::InterfaceSupportsErrorInfo */
};

const CInterfaceStubVtbl _ISupportErrorInfoStubVtbl =
{
    &IID_ISupportErrorInfo,
    &ISupportErrorInfo_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeFactory, ver. 0.0,
   GUID={0x0000002E,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short ITypeFactory_FormatStringOffsetTable[] =
    {
    2958
    };

static const MIDL_STUBLESS_PROXY_INFO ITypeFactory_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeFactory_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITypeFactory_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &ITypeFactory_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _ITypeFactoryProxyVtbl = 
{
    &ITypeFactory_ProxyInfo,
    &IID_ITypeFactory,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* ITypeFactory::CreateFromTypeInfo */
};

const CInterfaceStubVtbl _ITypeFactoryStubVtbl =
{
    &IID_ITypeFactory,
    &ITypeFactory_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ITypeMarshal, ver. 0.0,
   GUID={0x0000002D,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IRecordInfo, ver. 0.0,
   GUID={0x0000002F,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICreateTypeInfo, ver. 0.0,
   GUID={0x00020405,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICreateTypeInfo2, ver. 0.0,
   GUID={0x0002040E,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICreateTypeLib, ver. 0.0,
   GUID={0x00020406,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ICreateTypeLib2, ver. 0.0,
   GUID={0x0002040F,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IErrorLog, ver. 0.0,
   GUID={0x3127ca40,0x446e,0x11ce,{0x81,0x35,0x00,0xaa,0x00,0x4b,0xb8,0x51}} */

#pragma code_seg(".orpc")
static const unsigned short IErrorLog_FormatStringOffsetTable[] =
    {
    3006
    };

static const MIDL_STUBLESS_PROXY_INFO IErrorLog_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &IErrorLog_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IErrorLog_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &IErrorLog_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IErrorLogProxyVtbl = 
{
    &IErrorLog_ProxyInfo,
    &IID_IErrorLog,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IErrorLog::AddError */
};

const CInterfaceStubVtbl _IErrorLogStubVtbl =
{
    &IID_IErrorLog,
    &IErrorLog_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IPropertyBag, ver. 0.0,
   GUID={0x55272a00,0x42cb,0x11ce,{0x81,0x35,0x00,0xaa,0x00,0x4b,0xb8,0x51}} */

#pragma code_seg(".orpc")
static const unsigned short IPropertyBag_FormatStringOffsetTable[] =
    {
    3048,
    3108
    };

static const MIDL_STUBLESS_PROXY_INFO IPropertyBag_ProxyInfo =
    {
    &Object_StubDesc,
    oaidl__MIDL_ProcFormatString.Format,
    &IPropertyBag_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IPropertyBag_StubThunkTable[] = 
    {
    IPropertyBag_RemoteRead_Thunk,
    0
    };

static const MIDL_SERVER_INFO IPropertyBag_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oaidl__MIDL_ProcFormatString.Format,
    &IPropertyBag_FormatStringOffsetTable[-3],
    &IPropertyBag_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IPropertyBagProxyVtbl = 
{
    &IPropertyBag_ProxyInfo,
    &IID_IPropertyBag,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IPropertyBag_Read_Proxy ,
    (void *) (INT_PTR) -1 /* IPropertyBag::Write */
};

const CInterfaceStubVtbl _IPropertyBagStubVtbl =
{
    &IID_IPropertyBag,
    &IPropertyBag_ServerInfo,
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
    oaidl__MIDL_TypeFormatString.Format,
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

const CInterfaceProxyVtbl * _oaidl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IDispatchProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IPropertyBagProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITypeInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITypeLibProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITypeCompProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IEnumVARIANTProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITypeLib2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITypeInfo2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IErrorInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITypeFactoryProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICreateErrorInfoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IErrorLogProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISupportErrorInfoProxyVtbl,
    0
};

const CInterfaceStubVtbl * _oaidl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IDispatchStubVtbl,
    ( CInterfaceStubVtbl *) &_IPropertyBagStubVtbl,
    ( CInterfaceStubVtbl *) &_ITypeInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_ITypeLibStubVtbl,
    ( CInterfaceStubVtbl *) &_ITypeCompStubVtbl,
    ( CInterfaceStubVtbl *) &_IEnumVARIANTStubVtbl,
    ( CInterfaceStubVtbl *) &_ITypeLib2StubVtbl,
    ( CInterfaceStubVtbl *) &_ITypeInfo2StubVtbl,
    ( CInterfaceStubVtbl *) &_IErrorInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_ITypeFactoryStubVtbl,
    ( CInterfaceStubVtbl *) &_ICreateErrorInfoStubVtbl,
    ( CInterfaceStubVtbl *) &_IErrorLogStubVtbl,
    ( CInterfaceStubVtbl *) &_ISupportErrorInfoStubVtbl,
    0
};

PCInterfaceName const _oaidl_InterfaceNamesList[] = 
{
    "IDispatch",
    "IPropertyBag",
    "ITypeInfo",
    "ITypeLib",
    "ITypeComp",
    "IEnumVARIANT",
    "ITypeLib2",
    "ITypeInfo2",
    "IErrorInfo",
    "ITypeFactory",
    "ICreateErrorInfo",
    "IErrorLog",
    "ISupportErrorInfo",
    0
};


#define _oaidl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _oaidl, pIID, n)

int __stdcall _oaidl_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _oaidl, 13, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _oaidl, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _oaidl, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _oaidl, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _oaidl, 13, *pIndex )
    
}

const ExtendedProxyFileInfo oaidl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _oaidl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _oaidl_StubVtblList,
    (const PCInterfaceName * ) & _oaidl_InterfaceNamesList,
    0, // no delegation
    & _oaidl_IID_Lookup, 
    13,
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

