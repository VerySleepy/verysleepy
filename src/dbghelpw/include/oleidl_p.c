

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Nov 07 19:57:53 2011
 */
/* Compiler settings for oleidl.idl:
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


#include "oleidl.h"

#define TYPE_FORMAT_STRING_SIZE   1155                              
#define PROC_FORMAT_STRING_SIZE   3463                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   6            

typedef struct _oleidl_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } oleidl_MIDL_TYPE_FORMAT_STRING;

typedef struct _oleidl_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } oleidl_MIDL_PROC_FORMAT_STRING;

typedef struct _oleidl_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } oleidl_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const oleidl_MIDL_TYPE_FORMAT_STRING oleidl__MIDL_TypeFormatString;
extern const oleidl_MIDL_PROC_FORMAT_STRING oleidl__MIDL_ProcFormatString;
extern const oleidl_MIDL_EXPR_FORMAT_STRING oleidl__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleWindow_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleWindow_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleInPlaceObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleInPlaceObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleInPlaceUIWindow_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleInPlaceUIWindow_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleInPlaceFrame_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleInPlaceFrame_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleInPlaceActiveObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleInPlaceActiveObject_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_RemoteTranslateAccelerator_Proxy( 
    IOleInPlaceActiveObject * This)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[72],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IOleInPlaceActiveObject_RemoteTranslateAccelerator_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IOleInPlaceActiveObject *This;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IOleInPlaceActiveObject_TranslateAccelerator_Stub((IOleInPlaceActiveObject *) pParamStruct->This);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IOleInPlaceActiveObject_RemoteResizeBorder_Proxy( 
    IOleInPlaceActiveObject * This,
    /* [in] */ LPCRECT prcBorder,
    /* [in] */ REFIID riid,
    /* [iid_is][unique][in] */ IOleInPlaceUIWindow *pUIWindow,
    /* [in] */ BOOL fFrameWindow)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[666],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IOleInPlaceActiveObject_RemoteResizeBorder_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IOleInPlaceActiveObject *This;
        LPCRECT prcBorder;
        REFIID riid;
        IOleInPlaceUIWindow *pUIWindow;
        BOOL fFrameWindow;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IOleInPlaceActiveObject_ResizeBorder_Stub(
                                                    (IOleInPlaceActiveObject *) pParamStruct->This,
                                                    pParamStruct->prcBorder,
                                                    pParamStruct->riid,
                                                    pParamStruct->pUIWindow,
                                                    pParamStruct->fFrameWindow);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleInPlaceSite_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleInPlaceSite_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IParseDisplayName_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IParseDisplayName_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleContainer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleContainer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleItemContainer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleItemContainer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleLink_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleLink_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleClientSite_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleClientSite_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleCache_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleCache_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleCache2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleCache2_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IOleCache2_RemoteUpdateCache_Proxy( 
    IOleCache2 * This,
    /* [in] */ LPDATAOBJECT pDataObject,
    /* [in] */ DWORD grfUpdf,
    /* [in] */ LONG_PTR pReserved)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[1974],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IOleCache2_RemoteUpdateCache_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IOleCache2 *This;
        LPDATAOBJECT pDataObject;
        DWORD grfUpdf;
        LONG_PTR pReserved;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IOleCache2_UpdateCache_Stub(
                                      (IOleCache2 *) pParamStruct->This,
                                      pParamStruct->pDataObject,
                                      pParamStruct->grfUpdf,
                                      pParamStruct->pReserved);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleCacheControl_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleCacheControl_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IEnumOLEVERB_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IEnumOLEVERB_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IEnumOLEVERB_RemoteNext_Proxy( 
    IEnumOLEVERB * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ LPOLEVERB rgelt,
    /* [out] */ ULONG *pceltFetched)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[2088],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IEnumOLEVERB_RemoteNext_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IEnumOLEVERB *This;
        ULONG celt;
        LPOLEVERB rgelt;
        ULONG *pceltFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IEnumOLEVERB_Next_Stub(
                                 (IEnumOLEVERB *) pParamStruct->This,
                                 pParamStruct->celt,
                                 pParamStruct->rgelt,
                                 pParamStruct->pceltFetched);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOleObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOleObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IContinue_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IContinue_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IViewObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IViewObject_ProxyInfo;

/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteDraw_Proxy( 
    IViewObject * This,
    /* [in] */ DWORD dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ ULONG_PTR pvAspect,
    /* [unique][in] */ DVTARGETDEVICE *ptd,
    /* [in] */ ULONG_PTR hdcTargetDev,
    /* [in] */ ULONG_PTR hdcDraw,
    /* [in] */ LPCRECTL lprcBounds,
    /* [unique][in] */ LPCRECTL lprcWBounds,
    /* [in] */ IContinue *pContinue)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[2952],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IViewObject_RemoteDraw_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IViewObject *This;
        DWORD dwDrawAspect;
        LONG lindex;
        ULONG_PTR pvAspect;
        DVTARGETDEVICE *ptd;
        ULONG_PTR hdcTargetDev;
        ULONG_PTR hdcDraw;
        LPCRECTL lprcBounds;
        LPCRECTL lprcWBounds;
        IContinue *pContinue;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IViewObject_Draw_Stub(
                                (IViewObject *) pParamStruct->This,
                                pParamStruct->dwDrawAspect,
                                pParamStruct->lindex,
                                pParamStruct->pvAspect,
                                pParamStruct->ptd,
                                pParamStruct->hdcTargetDev,
                                pParamStruct->hdcDraw,
                                pParamStruct->lprcBounds,
                                pParamStruct->lprcWBounds,
                                pParamStruct->pContinue);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteGetColorSet_Proxy( 
    IViewObject * This,
    /* [in] */ DWORD dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ ULONG_PTR pvAspect,
    /* [unique][in] */ DVTARGETDEVICE *ptd,
    /* [in] */ ULONG_PTR hicTargetDev,
    /* [out] */ LOGPALETTE **ppColorSet)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[3036],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IViewObject_RemoteGetColorSet_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IViewObject *This;
        DWORD dwDrawAspect;
        LONG lindex;
        ULONG_PTR pvAspect;
        DVTARGETDEVICE *ptd;
        ULONG_PTR hicTargetDev;
        LOGPALETTE **ppColorSet;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IViewObject_GetColorSet_Stub(
                                       (IViewObject *) pParamStruct->This,
                                       pParamStruct->dwDrawAspect,
                                       pParamStruct->lindex,
                                       pParamStruct->pvAspect,
                                       pParamStruct->ptd,
                                       pParamStruct->hicTargetDev,
                                       pParamStruct->ppColorSet);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteFreeze_Proxy( 
    IViewObject * This,
    /* [in] */ DWORD dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ ULONG_PTR pvAspect,
    /* [out] */ DWORD *pdwFreeze)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[3102],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IViewObject_RemoteFreeze_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IViewObject *This;
        DWORD dwDrawAspect;
        LONG lindex;
        ULONG_PTR pvAspect;
        DWORD *pdwFreeze;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IViewObject_Freeze_Stub(
                                  (IViewObject *) pParamStruct->This,
                                  pParamStruct->dwDrawAspect,
                                  pParamStruct->lindex,
                                  pParamStruct->pvAspect,
                                  pParamStruct->pdwFreeze);
    
}

/* [call_as] */ HRESULT STDMETHODCALLTYPE IViewObject_RemoteGetAdvise_Proxy( 
    IViewObject * This,
    /* [out] */ DWORD *pAspects,
    /* [out] */ DWORD *pAdvf,
    /* [out] */ IAdviseSink **ppAdvSink)
{
CLIENT_CALL_RETURN _RetVal;

_RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&Object_StubDesc,
                  (PFORMAT_STRING) &oleidl__MIDL_ProcFormatString.Format[3204],
                  ( unsigned char * )&This);
return ( HRESULT  )_RetVal.Simple;

}

void __RPC_API
IViewObject_RemoteGetAdvise_Thunk(
    PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IViewObject *This;
        DWORD *pAspects;
        DWORD *pAdvf;
        IAdviseSink **ppAdvSink;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT * pParamStruct;

    pParamStruct = (struct _PARAM_STRUCT *) pStubMsg->StackTop;
    
    /* Call the server */
    
    pParamStruct->_RetVal = IViewObject_GetAdvise_Stub(
                                     (IViewObject *) pParamStruct->This,
                                     pParamStruct->pAspects,
                                     pParamStruct->pAdvf,
                                     pParamStruct->ppAdvSink);
    
}


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IViewObject2_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IViewObject2_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDropTarget_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDropTarget_ProxyInfo;


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


static const oleidl_MIDL_PROC_FORMAT_STRING oleidl__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetWindow */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 18 */	NdrFcShort( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phwnd */

/* 24 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Skip */


	/* Procedure Uncache */


	/* Procedure ContextSensitiveHelp */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x8 ),	/* 8 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */


	/* Parameter dwConnection */


	/* Parameter fEnterMode */

/* 60 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DragLeave */


	/* Procedure Reset */


	/* Procedure CanInPlaceActivate */


	/* Procedure RemoteTranslateAccelerator */


	/* Procedure InPlaceDeactivate */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x5 ),	/* 5 */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 88 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowObject */


	/* Procedure OnInPlaceActivate */


	/* Procedure UIDeactivate */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x6 ),	/* 6 */
/* 110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetObjectRects */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x7 ),	/* 7 */
/* 140 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 142 */	NdrFcShort( 0x68 ),	/* 104 */
/* 144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 146 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 148 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lprcPosRect */

/* 156 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 160 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter lprcClipRect */

/* 162 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 166 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RequestNewObjectLayout */


	/* Procedure ReactivateAndUndo */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 190 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBorder */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x5 ),	/* 5 */
/* 212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x3c ),	/* 60 */
/* 218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lprectBorder */

/* 228 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 232 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RequestBorderSpace */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x6 ),	/* 6 */
/* 248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 250 */	NdrFcShort( 0x34 ),	/* 52 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 256 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pborderwidths */

/* 264 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBorderSpace */

/* 276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0x7 ),	/* 7 */
/* 284 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 286 */	NdrFcShort( 0x34 ),	/* 52 */
/* 288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pborderwidths */

/* 300 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 304 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 306 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 310 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetActiveObject */

/* 312 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 314 */	NdrFcLong( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 320 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x8 ),	/* 8 */
/* 326 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 328 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pActiveObject */

/* 336 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 338 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 340 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Parameter pszObjName */

/* 342 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 344 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 346 */	NdrFcShort( 0x50 ),	/* Type Offset=80 */

	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InsertMenus */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x9 ),	/* 9 */
/* 362 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 364 */	NdrFcShort( 0x4c ),	/* 76 */
/* 366 */	NdrFcShort( 0x54 ),	/* 84 */
/* 368 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 370 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x1 ),	/* 1 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hmenuShared */

/* 378 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 380 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 382 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter lpMenuWidths */

/* 384 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 386 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 388 */	NdrFcShort( 0x6c ),	/* Type Offset=108 */

	/* Return value */

/* 390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 392 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMenu */

/* 396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0xa ),	/* 10 */
/* 404 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 412 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 416 */	NdrFcShort( 0x2 ),	/* 2 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hmenuShared */

/* 420 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 422 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 424 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Parameter holemenu */

/* 426 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 428 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 430 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Parameter hwndActiveObject */

/* 432 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 434 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 436 */	NdrFcShort( 0xb8 ),	/* Type Offset=184 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveMenus */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0xb ),	/* 11 */
/* 452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 458 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hmenuShared */

/* 468 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	NdrFcShort( 0x58 ),	/* Type Offset=88 */

	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStatusText */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0xc ),	/* 12 */
/* 488 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 494 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 496 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszStatusText */

/* 504 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 506 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 508 */	NdrFcShort( 0x50 ),	/* Type Offset=80 */

	/* Return value */

/* 510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 512 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnableModeless */

/* 516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0xd ),	/* 13 */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 530 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 532 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fEnable */

/* 540 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 542 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 548 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TranslateAccelerator */

/* 552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0xe ),	/* 14 */
/* 560 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 562 */	NdrFcShort( 0x6 ),	/* 6 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 568 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x1 ),	/* 1 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lpmsg */

/* 576 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 578 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 580 */	NdrFcShort( 0xce ),	/* Type Offset=206 */

	/* Parameter wID */

/* 582 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 584 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 586 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Unfreeze */


	/* Procedure Close */


	/* Procedure OnFrameWindowActivate */

/* 594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x6 ),	/* 6 */
/* 602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 608 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 610 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwFreeze */


	/* Parameter dwSaveOption */


	/* Parameter fActivate */

/* 618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 620 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 626 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnShowWindow */


	/* Procedure OnDocWindowActivate */

/* 630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x7 ),	/* 7 */
/* 638 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 644 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 646 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fShow */


	/* Parameter fActivate */

/* 654 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 656 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 658 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 662 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteResizeBorder */

/* 666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 676 */	NdrFcShort( 0x80 ),	/* 128 */
/* 678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 680 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 682 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x1 ),	/* 1 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter prcBorder */

/* 690 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 692 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 694 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter riid */

/* 696 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 698 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 700 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Parameter pUIWindow */

/* 702 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 706 */	NdrFcShort( 0xfa ),	/* Type Offset=250 */

	/* Parameter fFrameWindow */

/* 708 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 710 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 716 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DiscardCache */


	/* Procedure EnableModeless */

/* 720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x9 ),	/* 9 */
/* 728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 734 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 736 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDiscardOptions */


	/* Parameter fEnable */

/* 744 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnUIActivate */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x7 ),	/* 7 */
/* 764 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 772 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetWindowContext */

/* 786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 794 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x70 ),	/* 112 */
/* 800 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 802 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 804 */	NdrFcShort( 0x1 ),	/* 1 */
/* 806 */	NdrFcShort( 0x1 ),	/* 1 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppFrame */

/* 810 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 812 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 814 */	NdrFcShort( 0x102 ),	/* Type Offset=258 */

	/* Parameter ppDoc */

/* 816 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 818 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 820 */	NdrFcShort( 0x118 ),	/* Type Offset=280 */

	/* Parameter lprcPosRect */

/* 822 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 826 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter lprcClipRect */

/* 828 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 830 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 832 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter lpFrameInfo */

/* 834 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 836 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 838 */	NdrFcShort( 0x13c ),	/* Type Offset=316 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 842 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Scroll */

/* 846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x9 ),	/* 9 */
/* 854 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 856 */	NdrFcShort( 0x18 ),	/* 24 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 862 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter scrollExtent */

/* 870 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 872 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 874 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 878 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnUIDeactivate */

/* 882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0xa ),	/* 10 */
/* 890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 896 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 898 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fUndoable */

/* 906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnInPlaceDeactivate */

/* 918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0xb ),	/* 11 */
/* 926 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnbindSource */


	/* Procedure DiscardUndoState */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0xc ),	/* 12 */
/* 956 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x8 ),	/* 8 */
/* 962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Update */


	/* Procedure DeactivateAndUndo */

/* 978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0xd ),	/* 13 */
/* 986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 992 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 994 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1002 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1004 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnPosRectChange */

/* 1008 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0xe ),	/* 14 */
/* 1016 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1018 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1020 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1022 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1024 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter lprcPosRect */

/* 1032 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1034 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1036 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 1038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1040 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ParseDisplayName */

/* 1044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1052 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1058 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1060 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1068 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1070 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1072 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter pszDisplayName */

/* 1074 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1078 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Parameter pchEaten */

/* 1080 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1082 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppmkOut */

/* 1086 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1088 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1090 */	NdrFcShort( 0x16a ),	/* Type Offset=362 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumObjects */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1106 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1112 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1114 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfFlags */

/* 1122 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppenum */

/* 1128 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	NdrFcShort( 0x180 ),	/* Type Offset=384 */

	/* Return value */

/* 1134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1136 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LockContainer */

/* 1140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1156 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fLock */

/* 1164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1166 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1172 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetObject */

/* 1176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1184 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1186 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1190 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1192 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1194 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszItem */

/* 1200 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1202 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1204 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Parameter dwSpeedNeeded */

/* 1206 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1208 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbc */

/* 1212 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1214 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1216 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter riid */

/* 1218 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1220 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1222 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Parameter ppvObject */

/* 1224 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1226 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1228 */	NdrFcShort( 0x196 ),	/* Type Offset=406 */

	/* Return value */

/* 1230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1232 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetObjectStorage */

/* 1236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1242 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1244 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1246 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1250 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1252 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszItem */

/* 1260 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1264 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Parameter pbc */

/* 1266 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1270 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Parameter riid */

/* 1272 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1276 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Parameter ppvStorage */

/* 1278 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1280 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1282 */	NdrFcShort( 0x1a2 ),	/* Type Offset=418 */

	/* Return value */

/* 1284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1286 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsRunning */

/* 1290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1304 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1306 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszItem */

/* 1314 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1316 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1318 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 1320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1322 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUpdateOptions */

/* 1326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1334 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1338 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1340 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1342 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1348 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwUpdateOpt */

/* 1350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1352 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1358 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUpdateOptions */

/* 1362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1370 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1378 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pdwUpdateOpt */

/* 1386 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1394 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSourceMoniker */

/* 1398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1406 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1408 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1412 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1414 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pmk */

/* 1422 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1424 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1426 */	NdrFcShort( 0x16e ),	/* Type Offset=366 */

	/* Parameter rclsid */

/* 1428 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1430 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1432 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Return value */

/* 1434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1436 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSourceMoniker */

/* 1440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1454 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1456 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppmk */

/* 1464 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1466 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1468 */	NdrFcShort( 0x16a ),	/* Type Offset=362 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSourceDisplayName */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1484 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1492 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszStatusText */

/* 1500 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Return value */

/* 1506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSourceDisplayName */

/* 1512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1526 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1528 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppszDisplayName */

/* 1536 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 1538 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1540 */	NdrFcShort( 0x1ae ),	/* Type Offset=430 */

	/* Return value */

/* 1542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1544 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BindToSource */

/* 1548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1554 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1556 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1562 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1564 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1570 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bindflags */

/* 1572 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1574 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pbc */

/* 1578 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1580 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1582 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1586 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BindIfRunning */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0xa ),	/* 10 */
/* 1598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1606 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1616 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBoundSource */

/* 1620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0xb ),	/* 11 */
/* 1628 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1634 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1636 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppunk */

/* 1644 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1648 */	NdrFcShort( 0x1b6 ),	/* Type Offset=438 */

	/* Return value */

/* 1650 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1654 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Update */

/* 1656 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1658 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1662 */	NdrFcShort( 0xd ),	/* 13 */
/* 1664 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1670 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1672 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1678 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbc */

/* 1680 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1682 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1684 */	NdrFcShort( 0x150 ),	/* Type Offset=336 */

	/* Return value */

/* 1686 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1688 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FContinue */


	/* Procedure SaveObject */

/* 1692 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1694 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1700 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1706 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1708 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1718 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMoniker */

/* 1722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1728 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1730 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1732 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1736 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1738 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1744 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAssign */

/* 1746 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1748 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwWhichMoniker */

/* 1752 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1754 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1756 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppmk */

/* 1758 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1762 */	NdrFcShort( 0x16a ),	/* Type Offset=362 */

	/* Return value */

/* 1764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1766 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetContainer */

/* 1770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1778 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1784 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1786 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppContainer */

/* 1794 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1796 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1798 */	NdrFcShort( 0x1cc ),	/* Type Offset=460 */

	/* Return value */

/* 1800 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cache */

/* 1806 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1808 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1812 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1814 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1818 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1820 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1822 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1826 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatetc */

/* 1830 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1832 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1834 */	NdrFcShort( 0x1e2 ),	/* Type Offset=482 */

	/* Parameter advf */

/* 1836 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1838 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwConnection */

/* 1842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1844 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumCache */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1868 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenumSTATDATA */

/* 1878 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	NdrFcShort( 0x236 ),	/* Type Offset=566 */

	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitCache */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1898 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1904 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataObject */

/* 1914 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Return value */

/* 1920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetData */

/* 1926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1934 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1940 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1942 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x48 ),	/* 72 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pformatetc */

/* 1950 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1954 */	NdrFcShort( 0x1e2 ),	/* Type Offset=482 */

	/* Parameter pmedium */

/* 1956 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1960 */	NdrFcShort( 0x25e ),	/* Type Offset=606 */

	/* Parameter fRelease */

/* 1962 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1964 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1968 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1970 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteUpdateCache */

/* 1974 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1976 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1982 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1984 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1986 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1988 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1990 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1996 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataObject */

/* 1998 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2000 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2002 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Parameter grfUpdf */

/* 2004 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2006 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pReserved */

/* 2010 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2012 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2018 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnRun */

/* 2022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2028 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2030 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2036 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2038 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataObject */

/* 2046 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2048 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2050 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Return value */

/* 2052 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2054 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnStop */

/* 2058 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2060 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2064 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2070 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2072 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2074 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2084 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteNext */

/* 2088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2094 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2096 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2100 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2102 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2104 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2106 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter celt */

/* 2112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2114 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter rgelt */

/* 2118 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2122 */	NdrFcShort( 0x3de ),	/* Type Offset=990 */

	/* Parameter pceltFetched */

/* 2124 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2130 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2132 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2134 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2136 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2138 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2144 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2150 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2152 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenum */

/* 2160 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2164 */	NdrFcShort( 0x406 ),	/* Type Offset=1030 */

	/* Return value */

/* 2166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2168 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetClientSite */

/* 2172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2180 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2184 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2186 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2188 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pClientSite */

/* 2196 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2200 */	NdrFcShort( 0x41c ),	/* Type Offset=1052 */

	/* Return value */

/* 2202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2204 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClientSite */

/* 2208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2214 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2216 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2222 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2224 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppClientSite */

/* 2232 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2234 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2236 */	NdrFcShort( 0x42e ),	/* Type Offset=1070 */

	/* Return value */

/* 2238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHostNames */

/* 2244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2252 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2258 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2260 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter szContainerApp */

/* 2268 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2270 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2272 */	NdrFcShort( 0x164 ),	/* Type Offset=356 */

	/* Parameter szContainerObj */

/* 2274 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2276 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2278 */	NdrFcShort( 0x50 ),	/* Type Offset=80 */

	/* Return value */

/* 2280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2282 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetMoniker */

/* 2286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2294 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2300 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2302 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwWhichMoniker */

/* 2310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pmk */

/* 2316 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2320 */	NdrFcShort( 0x16e ),	/* Type Offset=366 */

	/* Return value */

/* 2322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMoniker */

/* 2328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2336 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2338 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2342 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2344 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAssign */

/* 2352 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwWhichMoniker */

/* 2358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2360 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppmk */

/* 2364 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2366 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2368 */	NdrFcShort( 0x16a ),	/* Type Offset=362 */

	/* Return value */

/* 2370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2372 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitFromData */

/* 2376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2384 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2386 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2390 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2392 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataObject */

/* 2400 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2402 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2404 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Parameter fCreation */

/* 2406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2408 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter dwReserved */

/* 2412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2414 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2420 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetClipboardData */

/* 2424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2430 */	NdrFcShort( 0xa ),	/* 10 */
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

	/* Parameter dwReserved */

/* 2448 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2450 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppDataObject */

/* 2454 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2456 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2458 */	NdrFcShort( 0x432 ),	/* Type Offset=1074 */

	/* Return value */

/* 2460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2462 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoVerb */

/* 2466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0xb ),	/* 11 */
/* 2474 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2476 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2480 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 2482 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2486 */	NdrFcShort( 0x2 ),	/* 2 */
/* 2488 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter iVerb */

/* 2490 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2492 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lpmsg */

/* 2496 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2498 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2500 */	NdrFcShort( 0x436 ),	/* Type Offset=1078 */

	/* Parameter pActiveSite */

/* 2502 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2504 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2506 */	NdrFcShort( 0x41c ),	/* Type Offset=1052 */

	/* Parameter lindex */

/* 2508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2510 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hwndParent */

/* 2514 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2516 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2518 */	NdrFcShort( 0xb8 ),	/* Type Offset=184 */

	/* Parameter lprcPosRect */

/* 2520 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 2522 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2524 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Return value */

/* 2526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2528 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumVerbs */

/* 2532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0xc ),	/* 12 */
/* 2540 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2546 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2548 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnumOleVerb */

/* 2556 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2560 */	NdrFcShort( 0x406 ),	/* Type Offset=1030 */

	/* Return value */

/* 2562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsUpToDate */

/* 2568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0xe ),	/* 14 */
/* 2576 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2582 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2584 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2594 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserClassID */

/* 2598 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2604 */	NdrFcShort( 0xf ),	/* 15 */
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

	/* Parameter pClsid */

/* 2622 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 2624 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2626 */	NdrFcShort( 0xee ),	/* Type Offset=238 */

	/* Return value */

/* 2628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2630 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUserType */

/* 2634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2640 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2642 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2644 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2648 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2650 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2656 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwFormOfType */

/* 2658 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2660 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pszUserType */

/* 2664 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 2666 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2668 */	NdrFcShort( 0x1ae ),	/* Type Offset=430 */

	/* Return value */

/* 2670 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2672 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExtent */

/* 2676 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2678 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2682 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2684 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2686 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2690 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2692 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDrawAspect */

/* 2700 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2702 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter psizel */

/* 2706 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2708 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2710 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 2712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2714 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetExtent */

/* 2718 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2724 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2726 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2730 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2732 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2734 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDrawAspect */

/* 2742 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2744 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2746 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter psizel */

/* 2748 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2750 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2752 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 2754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2756 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Advise */

/* 2760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2766 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2768 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2774 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2776 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAdvSink */

/* 2784 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2786 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2788 */	NdrFcShort( 0x446 ),	/* Type Offset=1094 */

	/* Parameter pdwConnection */

/* 2790 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2792 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2796 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2798 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Unadvise */

/* 2802 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2808 */	NdrFcShort( 0x14 ),	/* 20 */
/* 2810 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2814 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2816 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2818 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2824 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwConnection */

/* 2826 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2828 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2832 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2834 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2836 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumAdvise */

/* 2838 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2840 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2844 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2846 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2852 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2854 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppenumAdvise */

/* 2862 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2864 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2866 */	NdrFcShort( 0x236 ),	/* Type Offset=566 */

	/* Return value */

/* 2868 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2870 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMiscStatus */

/* 2874 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2880 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2882 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2886 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2888 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2890 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2896 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwAspect */

/* 2898 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2900 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwStatus */

/* 2904 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2906 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2908 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2910 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2912 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetColorScheme */

/* 2916 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2922 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2924 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2930 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2932 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2936 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2938 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pLogpal */

/* 2940 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2942 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2944 */	NdrFcShort( 0x39e ),	/* Type Offset=926 */

	/* Return value */

/* 2946 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2948 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2950 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteDraw */

/* 2952 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2954 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2958 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2960 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 2962 */	NdrFcShort( 0x90 ),	/* 144 */
/* 2964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2966 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 2968 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2972 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDrawAspect */

/* 2976 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2978 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lindex */

/* 2982 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2984 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvAspect */

/* 2988 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2990 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ptd */

/* 2994 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2996 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2998 */	NdrFcShort( 0x45c ),	/* Type Offset=1116 */

	/* Parameter hdcTargetDev */

/* 3000 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3002 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hdcDraw */

/* 3006 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3008 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lprcBounds */

/* 3012 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 3014 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3016 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter lprcWBounds */

/* 3018 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 3020 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3022 */	NdrFcShort( 0x3a ),	/* Type Offset=58 */

	/* Parameter pContinue */

/* 3024 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3026 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 3028 */	NdrFcShort( 0x460 ),	/* Type Offset=1120 */

	/* Return value */

/* 3030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3032 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetColorSet */

/* 3036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3044 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3046 */	NdrFcShort( 0x20 ),	/* 32 */
/* 3048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3050 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 3052 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 3054 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3056 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDrawAspect */

/* 3060 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3064 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lindex */

/* 3066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3068 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvAspect */

/* 3072 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ptd */

/* 3078 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3080 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3082 */	NdrFcShort( 0x45c ),	/* Type Offset=1116 */

	/* Parameter hicTargetDev */

/* 3084 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3086 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3088 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppColorSet */

/* 3090 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3092 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3094 */	NdrFcShort( 0x472 ),	/* Type Offset=1138 */

	/* Return value */

/* 3096 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3098 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteFreeze */

/* 3102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3108 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3110 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3112 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3114 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3116 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDrawAspect */

/* 3126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lindex */

/* 3132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pvAspect */

/* 3138 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pdwFreeze */

/* 3144 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3146 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3152 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAdvise */

/* 3156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3162 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3164 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3166 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3170 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3172 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter aspects */

/* 3180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter advf */

/* 3186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3188 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAdvSink */

/* 3192 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3194 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3196 */	NdrFcShort( 0x446 ),	/* Type Offset=1094 */

	/* Return value */

/* 3198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3200 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoteGetAdvise */

/* 3204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3212 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x40 ),	/* 64 */
/* 3218 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 3220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAspects */

/* 3228 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pAdvf */

/* 3234 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ppAdvSink */

/* 3240 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3242 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3244 */	NdrFcShort( 0x47a ),	/* Type Offset=1146 */

	/* Return value */

/* 3246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3248 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetExtent */

/* 3252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3258 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3260 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3262 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3264 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3266 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3268 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3272 */	NdrFcShort( 0x16 ),	/* 22 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dwDrawAspect */

/* 3276 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3278 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lindex */

/* 3282 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ptd */

/* 3288 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3290 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3292 */	NdrFcShort( 0x45c ),	/* Type Offset=1116 */

	/* Parameter lpsizel */

/* 3294 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 3296 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3298 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DragEnter */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3314 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3316 */	NdrFcShort( 0x3c ),	/* 60 */
/* 3318 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3320 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3322 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataObj */

/* 3330 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3334 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Parameter grfKeyState */

/* 3336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pt */

/* 3342 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3346 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Parameter pdwEffect */

/* 3348 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3350 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3356 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DragOver */

/* 3360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3366 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3368 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3370 */	NdrFcShort( 0x3c ),	/* 60 */
/* 3372 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 3376 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter grfKeyState */

/* 3384 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pt */

/* 3390 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3394 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Parameter pdwEffect */

/* 3396 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3398 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3402 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3404 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Drop */

/* 3408 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3410 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3416 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3418 */	NdrFcShort( 0x3c ),	/* 60 */
/* 3420 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3422 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3424 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3430 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDataObj */

/* 3432 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3434 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3436 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Parameter grfKeyState */

/* 3438 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3440 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pt */

/* 3444 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3446 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3448 */	NdrFcShort( 0xc6 ),	/* Type Offset=198 */

	/* Parameter pdwEffect */

/* 3450 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 3452 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3458 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const oleidl_MIDL_TYPE_FORMAT_STRING oleidl__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x1a ),	/* Offset= 26 (30) */
/*  6 */	
			0x13, 0x0,	/* FC_OP */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 12 */	NdrFcShort( 0x4 ),	/* 4 */
/* 14 */	NdrFcShort( 0x2 ),	/* 2 */
/* 16 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 20 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 22 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 26 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 28 */	NdrFcShort( 0xffff ),	/* Offset= -1 (27) */
/* 30 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x4 ),	/* 4 */
/* 36 */	NdrFcShort( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (6) */
/* 40 */	
			0x11, 0x0,	/* FC_RP */
/* 42 */	NdrFcShort( 0x2 ),	/* Offset= 2 (44) */
/* 44 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 46 */	NdrFcShort( 0x10 ),	/* 16 */
/* 48 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 50 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 52 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 54 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 56 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (44) */
/* 58 */	
			0x12, 0x0,	/* FC_UP */
/* 60 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (44) */
/* 62 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 64 */	NdrFcLong( 0x117 ),	/* 279 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 74 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 76 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 78 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 80 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 82 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 84 */	
			0x12, 0x0,	/* FC_UP */
/* 86 */	NdrFcShort( 0xffb4 ),	/* Offset= -76 (10) */
/* 88 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 90 */	NdrFcShort( 0x1 ),	/* 1 */
/* 92 */	NdrFcShort( 0x4 ),	/* 4 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (84) */
/* 98 */	
			0x11, 0x0,	/* FC_RP */
/* 100 */	NdrFcShort( 0x8 ),	/* Offset= 8 (108) */
/* 102 */	
			0x1d,		/* FC_SMFARRAY */
			0x3,		/* 3 */
/* 104 */	NdrFcShort( 0x18 ),	/* 24 */
/* 106 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 108 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 110 */	NdrFcShort( 0x18 ),	/* 24 */
/* 112 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 114 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (102) */
/* 116 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 118 */	
			0x12, 0x0,	/* FC_UP */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	NdrFcShort( 0x3 ),	/* 3 */
/* 128 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 132 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 134 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 138 */	NdrFcShort( 0xa ),	/* Offset= 10 (148) */
/* 140 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 144 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 146 */	NdrFcShort( 0xffff ),	/* Offset= -1 (145) */
/* 148 */	
			0x12, 0x0,	/* FC_UP */
/* 150 */	NdrFcShort( 0xe ),	/* Offset= 14 (164) */
/* 152 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 154 */	NdrFcShort( 0x1 ),	/* 1 */
/* 156 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 158 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 160 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 162 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 164 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 168 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (152) */
/* 170 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 172 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 174 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 176 */	NdrFcShort( 0x2 ),	/* 2 */
/* 178 */	NdrFcShort( 0x4 ),	/* 4 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (118) */
/* 184 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x4 ),	/* 4 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0xff94 ),	/* Offset= -108 (84) */
/* 194 */	
			0x11, 0x0,	/* FC_RP */
/* 196 */	NdrFcShort( 0xa ),	/* Offset= 10 (206) */
/* 198 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 202 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 204 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 206 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 208 */	NdrFcShort( 0x1c ),	/* 28 */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* Offset= 0 (212) */
/* 214 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 216 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (184) */
/* 218 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 220 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 222 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 224 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (198) */
/* 226 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 228 */	
			0x11, 0x0,	/* FC_RP */
/* 230 */	NdrFcShort( 0x8 ),	/* Offset= 8 (238) */
/* 232 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 236 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 238 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 240 */	NdrFcShort( 0x10 ),	/* 16 */
/* 242 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 244 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 246 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (232) */
			0x5b,		/* FC_END */
/* 250 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 252 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 254 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 256 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 258 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 260 */	NdrFcShort( 0x2 ),	/* Offset= 2 (262) */
/* 262 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 264 */	NdrFcLong( 0x116 ),	/* 278 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 272 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 274 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 276 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 278 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 280 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 282 */	NdrFcShort( 0x2 ),	/* Offset= 2 (284) */
/* 284 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 286 */	NdrFcLong( 0x115 ),	/* 277 */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 296 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 298 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 300 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 302 */	
			0x11, 0x0,	/* FC_RP */
/* 304 */	NdrFcShort( 0xc ),	/* Offset= 12 (316) */
/* 306 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 308 */	NdrFcShort( 0x3 ),	/* 3 */
/* 310 */	NdrFcShort( 0x4 ),	/* 4 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0xfecc ),	/* Offset= -308 (6) */
/* 316 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 318 */	NdrFcShort( 0x14 ),	/* 20 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* Offset= 0 (322) */
/* 324 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 326 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 328 */	NdrFcShort( 0xfed6 ),	/* Offset= -298 (30) */
/* 330 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 332 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (306) */
/* 334 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 336 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 338 */	NdrFcLong( 0xe ),	/* 14 */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 348 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 350 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 352 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 354 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 356 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 358 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 360 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 362 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 364 */	NdrFcShort( 0x2 ),	/* Offset= 2 (366) */
/* 366 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 368 */	NdrFcLong( 0xf ),	/* 15 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 378 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 380 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 382 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 384 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 386 */	NdrFcShort( 0x2 ),	/* Offset= 2 (388) */
/* 388 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 390 */	NdrFcLong( 0x100 ),	/* 256 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 400 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 402 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 404 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 406 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 408 */	NdrFcShort( 0x2 ),	/* Offset= 2 (410) */
/* 410 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 412 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 414 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 416 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 418 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 420 */	NdrFcShort( 0x2 ),	/* Offset= 2 (422) */
/* 422 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 424 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 426 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 428 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 430 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 432 */	NdrFcShort( 0x2 ),	/* Offset= 2 (434) */
/* 434 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 436 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 438 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 440 */	NdrFcShort( 0x2 ),	/* Offset= 2 (442) */
/* 442 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 454 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 456 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 458 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 460 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 462 */	NdrFcShort( 0x2 ),	/* Offset= 2 (464) */
/* 464 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 466 */	NdrFcLong( 0x11b ),	/* 283 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 474 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 476 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 478 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 480 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 482 */	
			0x12, 0x0,	/* FC_UP */
/* 484 */	NdrFcShort( 0x3c ),	/* Offset= 60 (544) */
/* 486 */	
			0x12, 0x0,	/* FC_UP */
/* 488 */	NdrFcShort( 0x2 ),	/* Offset= 2 (490) */
/* 490 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x48,		/* 72 */
/* 492 */	NdrFcShort( 0x4 ),	/* 4 */
/* 494 */	NdrFcShort( 0x2 ),	/* 2 */
/* 496 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 500 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 502 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 506 */	NdrFcShort( 0xfe56 ),	/* Offset= -426 (80) */
/* 508 */	NdrFcShort( 0xffff ),	/* Offset= -1 (507) */
/* 510 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 512 */	NdrFcShort( 0x4 ),	/* 4 */
/* 514 */	NdrFcShort( 0x2 ),	/* 2 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (486) */
/* 520 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 522 */	NdrFcShort( 0x1 ),	/* 1 */
/* 524 */	0x0,		/* Corr desc:  field,  */
			0x59,		/* FC_CALLBACK */
/* 526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 530 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 532 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 534 */	NdrFcShort( 0xc ),	/* 12 */
/* 536 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (520) */
/* 538 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 540 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 542 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 544 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 546 */	NdrFcShort( 0x14 ),	/* 20 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0xc ),	/* Offset= 12 (562) */
/* 552 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 554 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (510) */
/* 556 */	0x3e,		/* FC_STRUCTPAD2 */
			0x36,		/* FC_POINTER */
/* 558 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 560 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 562 */	
			0x12, 0x0,	/* FC_UP */
/* 564 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (532) */
/* 566 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 568 */	NdrFcShort( 0x2 ),	/* Offset= 2 (570) */
/* 570 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 572 */	NdrFcLong( 0x105 ),	/* 261 */
/* 576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 582 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 584 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 586 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 588 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 590 */	NdrFcLong( 0x10e ),	/* 270 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 600 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 602 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 604 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 606 */	
			0x12, 0x0,	/* FC_UP */
/* 608 */	NdrFcShort( 0x15a ),	/* Offset= 346 (954) */
/* 610 */	
			0x12, 0x0,	/* FC_UP */
/* 612 */	NdrFcShort( 0x144 ),	/* Offset= 324 (936) */
/* 614 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 616 */	NdrFcShort( 0x4 ),	/* 4 */
/* 618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x0 ),	/* Offset= 0 (624) */
/* 626 */	NdrFcLong( 0x20 ),	/* 32 */
/* 630 */	NdrFcShort( 0x28 ),	/* Offset= 40 (670) */
/* 632 */	NdrFcLong( 0x40 ),	/* 64 */
/* 636 */	NdrFcShort( 0x80 ),	/* Offset= 128 (764) */
/* 638 */	NdrFcLong( 0x10 ),	/* 16 */
/* 642 */	NdrFcShort( 0x98 ),	/* Offset= 152 (794) */
/* 644 */	NdrFcLong( 0x1 ),	/* 1 */
/* 648 */	NdrFcShort( 0xfdee ),	/* Offset= -530 (118) */
/* 650 */	NdrFcLong( 0x2 ),	/* 2 */
/* 654 */	NdrFcShort( 0xfdc2 ),	/* Offset= -574 (80) */
/* 656 */	NdrFcLong( 0x4 ),	/* 4 */
/* 660 */	NdrFcShort( 0x46 ),	/* Offset= 70 (730) */
/* 662 */	NdrFcLong( 0x8 ),	/* 8 */
/* 666 */	NdrFcShort( 0x40 ),	/* Offset= 64 (730) */
/* 668 */	NdrFcShort( 0xffff ),	/* Offset= -1 (667) */
/* 670 */	
			0x12, 0x0,	/* FC_UP */
/* 672 */	NdrFcShort( 0x2 ),	/* Offset= 2 (674) */
/* 674 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 678 */	NdrFcShort( 0x3 ),	/* 3 */
/* 680 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 684 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 686 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 690 */	NdrFcShort( 0xa ),	/* Offset= 10 (700) */
/* 692 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 696 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 698 */	NdrFcShort( 0xffff ),	/* Offset= -1 (697) */
/* 700 */	
			0x12, 0x0,	/* FC_UP */
/* 702 */	NdrFcShort( 0x28 ),	/* Offset= 40 (742) */
/* 704 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 708 */	NdrFcShort( 0x3 ),	/* 3 */
/* 710 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 714 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 716 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 720 */	NdrFcShort( 0xa ),	/* Offset= 10 (730) */
/* 722 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 726 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 728 */	NdrFcShort( 0xffff ),	/* Offset= -1 (727) */
/* 730 */	
			0x12, 0x0,	/* FC_UP */
/* 732 */	NdrFcShort( 0x2 ),	/* Offset= 2 (734) */
/* 734 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 736 */	NdrFcShort( 0x4 ),	/* 4 */
/* 738 */	NdrFcShort( 0xfdb6 ),	/* Offset= -586 (152) */
/* 740 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 742 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 744 */	NdrFcShort( 0x10 ),	/* 16 */
/* 746 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 748 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 750 */	NdrFcShort( 0xc ),	/* 12 */
/* 752 */	NdrFcShort( 0xc ),	/* 12 */
/* 754 */	0x12, 0x0,	/* FC_UP */
/* 756 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (704) */
/* 758 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 760 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 762 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 764 */	
			0x12, 0x0,	/* FC_UP */
/* 766 */	NdrFcShort( 0x2 ),	/* Offset= 2 (768) */
/* 768 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 770 */	NdrFcShort( 0x8 ),	/* 8 */
/* 772 */	NdrFcShort( 0x3 ),	/* 3 */
/* 774 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 778 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 780 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 784 */	NdrFcShort( 0xffca ),	/* Offset= -54 (730) */
/* 786 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 790 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 792 */	NdrFcShort( 0xffff ),	/* Offset= -1 (791) */
/* 794 */	
			0x12, 0x0,	/* FC_UP */
/* 796 */	NdrFcShort( 0x2 ),	/* Offset= 2 (798) */
/* 798 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 800 */	NdrFcShort( 0x4 ),	/* 4 */
/* 802 */	NdrFcShort( 0x2 ),	/* 2 */
/* 804 */	NdrFcLong( 0x7 ),	/* 7 */
/* 808 */	NdrFcShort( 0xa ),	/* Offset= 10 (818) */
/* 810 */	NdrFcLong( 0x5 ),	/* 5 */
/* 814 */	NdrFcShort( 0x34 ),	/* Offset= 52 (866) */
/* 816 */	NdrFcShort( 0xfd46 ),	/* Offset= -698 (118) */
/* 818 */	
			0x12, 0x0,	/* FC_UP */
/* 820 */	NdrFcShort( 0x2 ),	/* Offset= 2 (822) */
/* 822 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 826 */	NdrFcShort( 0x3 ),	/* 3 */
/* 828 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 832 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 834 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 838 */	NdrFcShort( 0xa ),	/* Offset= 10 (848) */
/* 840 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 844 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 846 */	NdrFcShort( 0xffff ),	/* Offset= -1 (845) */
/* 848 */	
			0x12, 0x0,	/* FC_UP */
/* 850 */	NdrFcShort( 0x2 ),	/* Offset= 2 (852) */
/* 852 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x18 ),	/* 24 */
/* 856 */	NdrFcShort( 0xfd40 ),	/* Offset= -704 (152) */
/* 858 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 860 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 862 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 864 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 866 */	
			0x12, 0x0,	/* FC_UP */
/* 868 */	NdrFcShort( 0x2 ),	/* Offset= 2 (870) */
/* 870 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x88,		/* 136 */
/* 872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 874 */	NdrFcShort( 0x3 ),	/* 3 */
/* 876 */	NdrFcLong( 0x48746457 ),	/* 1215587415 */
/* 880 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 882 */	NdrFcLong( 0x52746457 ),	/* 1383359575 */
/* 886 */	NdrFcShort( 0xa ),	/* Offset= 10 (896) */
/* 888 */	NdrFcLong( 0x50746457 ),	/* 1349805143 */
/* 892 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 894 */	NdrFcShort( 0xffff ),	/* Offset= -1 (893) */
/* 896 */	
			0x12, 0x0,	/* FC_UP */
/* 898 */	NdrFcShort( 0x1c ),	/* Offset= 28 (926) */
/* 900 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 902 */	NdrFcShort( 0x4 ),	/* 4 */
/* 904 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 906 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 908 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 910 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 912 */	NdrFcShort( 0x4 ),	/* 4 */
/* 914 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 916 */	NdrFcShort( 0xfffe ),	/* -2 */
/* 918 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 920 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 922 */	NdrFcShort( 0xffea ),	/* Offset= -22 (900) */
/* 924 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 926 */	
			0x17,		/* FC_CSTRUCT */
			0x1,		/* 1 */
/* 928 */	NdrFcShort( 0x4 ),	/* 4 */
/* 930 */	NdrFcShort( 0xffec ),	/* Offset= -20 (910) */
/* 932 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 934 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 936 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0xc ),	/* 12 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0xc ),	/* Offset= 12 (954) */
/* 944 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 946 */	NdrFcShort( 0xfeb4 ),	/* Offset= -332 (614) */
/* 948 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 950 */	NdrFcShort( 0xfe04 ),	/* Offset= -508 (442) */
/* 952 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 954 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 956 */	NdrFcShort( 0x5 ),	/* 5 */
/* 958 */	NdrFcShort( 0xc ),	/* 12 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0xfea0 ),	/* Offset= -352 (610) */
/* 964 */	
			0x11, 0x0,	/* FC_RP */
/* 966 */	NdrFcShort( 0x18 ),	/* Offset= 24 (990) */
/* 968 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 970 */	NdrFcShort( 0x10 ),	/* 16 */
/* 972 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 974 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 976 */	NdrFcShort( 0x4 ),	/* 4 */
/* 978 */	NdrFcShort( 0x4 ),	/* 4 */
/* 980 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 982 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 984 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 986 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 988 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 990 */	
			0x1c,		/* FC_CVARRAY */
			0x3,		/* 3 */
/* 992 */	NdrFcShort( 0x10 ),	/* 16 */
/* 994 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 996 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 998 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1000 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 1002 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1004 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 1006 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1008 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x4a,		/* FC_VARIABLE_OFFSET */
/* 1010 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1016 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1018 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1020 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1022 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 1024 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1026 */	0x0,		/* 0 */
			NdrFcShort( 0xffc5 ),	/* Offset= -59 (968) */
			0x5b,		/* FC_END */
/* 1030 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1032 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1034) */
/* 1034 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1036 */	NdrFcLong( 0x104 ),	/* 260 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1046 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1048 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1050 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1052 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1054 */	NdrFcLong( 0x118 ),	/* 280 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1064 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1066 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1068 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1070 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1072 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1052) */
/* 1074 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1076 */	NdrFcShort( 0xfe18 ),	/* Offset= -488 (588) */
/* 1078 */	
			0x12, 0x0,	/* FC_UP */
/* 1080 */	NdrFcShort( 0xfc96 ),	/* Offset= -874 (206) */
/* 1082 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1084 */	NdrFcShort( 0xfcb2 ),	/* Offset= -846 (238) */
/* 1086 */	
			0x11, 0x0,	/* FC_RP */
/* 1088 */	NdrFcShort( 0xfc86 ),	/* Offset= -890 (198) */
/* 1090 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1092 */	NdrFcShort( 0xfc82 ),	/* Offset= -894 (198) */
/* 1094 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1096 */	NdrFcLong( 0x10f ),	/* 271 */
/* 1100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1104 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1106 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1108 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1110 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1112 */	
			0x11, 0x0,	/* FC_RP */
/* 1114 */	NdrFcShort( 0xff44 ),	/* Offset= -188 (926) */
/* 1116 */	
			0x12, 0x0,	/* FC_UP */
/* 1118 */	NdrFcShort( 0xfdb6 ),	/* Offset= -586 (532) */
/* 1120 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1122 */	NdrFcLong( 0x12a ),	/* 298 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1132 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1134 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1136 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1138 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 1140 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1142) */
/* 1142 */	
			0x13, 0x0,	/* FC_OP */
/* 1144 */	NdrFcShort( 0xff26 ),	/* Offset= -218 (926) */
/* 1146 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1148 */	NdrFcShort( 0xffca ),	/* Offset= -54 (1094) */
/* 1150 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1152 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            HWND_UserSize
            ,HWND_UserMarshal
            ,HWND_UserUnmarshal
            ,HWND_UserFree
            },
            {
            HMENU_UserSize
            ,HMENU_UserMarshal
            ,HMENU_UserUnmarshal
            ,HMENU_UserFree
            },
            {
            HGLOBAL_UserSize
            ,HGLOBAL_UserMarshal
            ,HGLOBAL_UserUnmarshal
            ,HGLOBAL_UserFree
            },
            {
            HACCEL_UserSize
            ,HACCEL_UserMarshal
            ,HACCEL_UserUnmarshal
            ,HACCEL_UserFree
            },
            {
            CLIPFORMAT_UserSize
            ,CLIPFORMAT_UserMarshal
            ,CLIPFORMAT_UserUnmarshal
            ,CLIPFORMAT_UserFree
            },
            {
            STGMEDIUM_UserSize
            ,STGMEDIUM_UserMarshal
            ,STGMEDIUM_UserUnmarshal
            ,STGMEDIUM_UserFree
            }

        };


static void __RPC_USER IOleCache_DVTARGETDEVICEExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{
    DVTARGETDEVICE *pS	=	( DVTARGETDEVICE * )(( pStubMsg->StackTop - 12 ) );
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = ( unsigned long ) ( ( ( pS->tdSize - sizeof( DWORD  ) )  - ( 4 * sizeof( WORD  ) )  )  );
}

static const EXPR_EVAL ExprEvalRoutines[] = 
    {
    IOleCache_DVTARGETDEVICEExprEval_0000
    };



/* Standard interface: __MIDL_itf_oleidl_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Standard interface: IOLETypes, ver. 0.0,
   GUID={0xb0916c84,0x7416,0x101a,{0xbc,0xea,0x08,0x00,0x2b,0x2b,0x79,0xef}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IOleWindow, ver. 0.0,
   GUID={0x00000114,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleWindow_FormatStringOffsetTable[] =
    {
    0,
    36
    };

static const MIDL_STUBLESS_PROXY_INFO IOleWindow_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleWindow_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleWindow_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleWindow_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOleWindowProxyVtbl = 
{
    &IOleWindow_ProxyInfo,
    &IID_IOleWindow,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleWindow::GetWindow */ ,
    (void *) (INT_PTR) -1 /* IOleWindow::ContextSensitiveHelp */
};

const CInterfaceStubVtbl _IOleWindowStubVtbl =
{
    &IID_IOleWindow,
    &IOleWindow_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleInPlaceObject, ver. 0.0,
   GUID={0x00000113,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleInPlaceObject_FormatStringOffsetTable[] =
    {
    0,
    36,
    72,
    102,
    132,
    174
    };

static const MIDL_STUBLESS_PROXY_INFO IOleInPlaceObject_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleInPlaceObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOleInPlaceObjectProxyVtbl = 
{
    &IOleInPlaceObject_ProxyInfo,
    &IID_IOleInPlaceObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleWindow::GetWindow */ ,
    (void *) (INT_PTR) -1 /* IOleWindow::ContextSensitiveHelp */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceObject::InPlaceDeactivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceObject::UIDeactivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceObject::SetObjectRects */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceObject::ReactivateAndUndo */
};

const CInterfaceStubVtbl _IOleInPlaceObjectStubVtbl =
{
    &IID_IOleInPlaceObject,
    &IOleInPlaceObject_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleInPlaceUIWindow, ver. 0.0,
   GUID={0x00000115,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleInPlaceUIWindow_FormatStringOffsetTable[] =
    {
    0,
    36,
    204,
    240,
    276,
    312
    };

static const MIDL_STUBLESS_PROXY_INFO IOleInPlaceUIWindow_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceUIWindow_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleInPlaceUIWindow_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceUIWindow_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOleInPlaceUIWindowProxyVtbl = 
{
    &IOleInPlaceUIWindow_ProxyInfo,
    &IID_IOleInPlaceUIWindow,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleWindow::GetWindow */ ,
    (void *) (INT_PTR) -1 /* IOleWindow::ContextSensitiveHelp */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::GetBorder */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::RequestBorderSpace */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::SetBorderSpace */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::SetActiveObject */
};

const CInterfaceStubVtbl _IOleInPlaceUIWindowStubVtbl =
{
    &IID_IOleInPlaceUIWindow,
    &IOleInPlaceUIWindow_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Standard interface: __MIDL_itf_oleidl_0000_0004, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IOleInPlaceFrame, ver. 0.0,
   GUID={0x00000116,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleInPlaceFrame_FormatStringOffsetTable[] =
    {
    0,
    36,
    204,
    240,
    276,
    312,
    354,
    396,
    444,
    480,
    516,
    552
    };

static const MIDL_STUBLESS_PROXY_INFO IOleInPlaceFrame_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceFrame_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleInPlaceFrame_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceFrame_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IOleInPlaceFrameProxyVtbl = 
{
    &IOleInPlaceFrame_ProxyInfo,
    &IID_IOleInPlaceFrame,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleWindow::GetWindow */ ,
    (void *) (INT_PTR) -1 /* IOleWindow::ContextSensitiveHelp */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::GetBorder */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::RequestBorderSpace */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::SetBorderSpace */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceUIWindow::SetActiveObject */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceFrame::InsertMenus */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceFrame::SetMenu */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceFrame::RemoveMenus */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceFrame::SetStatusText */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceFrame::EnableModeless */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceFrame::TranslateAccelerator */
};

const CInterfaceStubVtbl _IOleInPlaceFrameStubVtbl =
{
    &IID_IOleInPlaceFrame,
    &IOleInPlaceFrame_ServerInfo,
    15,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleInPlaceActiveObject, ver. 0.0,
   GUID={0x00000117,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleInPlaceActiveObject_FormatStringOffsetTable[] =
    {
    0,
    36,
    72,
    594,
    630,
    666,
    720
    };

static const MIDL_STUBLESS_PROXY_INFO IOleInPlaceActiveObject_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceActiveObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IOleInPlaceActiveObject_StubThunkTable[] = 
    {
    0,
    0,
    IOleInPlaceActiveObject_RemoteTranslateAccelerator_Thunk,
    0,
    0,
    IOleInPlaceActiveObject_RemoteResizeBorder_Thunk,
    0
    };

static const MIDL_SERVER_INFO IOleInPlaceActiveObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceActiveObject_FormatStringOffsetTable[-3],
    &IOleInPlaceActiveObject_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IOleInPlaceActiveObjectProxyVtbl = 
{
    &IOleInPlaceActiveObject_ProxyInfo,
    &IID_IOleInPlaceActiveObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleWindow::GetWindow */ ,
    (void *) (INT_PTR) -1 /* IOleWindow::ContextSensitiveHelp */ ,
    IOleInPlaceActiveObject_TranslateAccelerator_Proxy ,
    (void *) (INT_PTR) -1 /* IOleInPlaceActiveObject::OnFrameWindowActivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceActiveObject::OnDocWindowActivate */ ,
    IOleInPlaceActiveObject_ResizeBorder_Proxy ,
    (void *) (INT_PTR) -1 /* IOleInPlaceActiveObject::EnableModeless */
};

const CInterfaceStubVtbl _IOleInPlaceActiveObjectStubVtbl =
{
    &IID_IOleInPlaceActiveObject,
    &IOleInPlaceActiveObject_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleInPlaceSite, ver. 0.0,
   GUID={0x00000119,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleInPlaceSite_FormatStringOffsetTable[] =
    {
    0,
    36,
    72,
    102,
    756,
    786,
    846,
    882,
    918,
    948,
    978,
    1008
    };

static const MIDL_STUBLESS_PROXY_INFO IOleInPlaceSite_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceSite_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleInPlaceSite_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleInPlaceSite_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IOleInPlaceSiteProxyVtbl = 
{
    &IOleInPlaceSite_ProxyInfo,
    &IID_IOleInPlaceSite,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleWindow::GetWindow */ ,
    (void *) (INT_PTR) -1 /* IOleWindow::ContextSensitiveHelp */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::CanInPlaceActivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::OnInPlaceActivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::OnUIActivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::GetWindowContext */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::Scroll */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::OnUIDeactivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::OnInPlaceDeactivate */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::DiscardUndoState */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::DeactivateAndUndo */ ,
    (void *) (INT_PTR) -1 /* IOleInPlaceSite::OnPosRectChange */
};

const CInterfaceStubVtbl _IOleInPlaceSiteStubVtbl =
{
    &IID_IOleInPlaceSite,
    &IOleInPlaceSite_ServerInfo,
    15,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IParseDisplayName, ver. 0.0,
   GUID={0x0000011a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IParseDisplayName_FormatStringOffsetTable[] =
    {
    1044
    };

static const MIDL_STUBLESS_PROXY_INFO IParseDisplayName_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IParseDisplayName_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IParseDisplayName_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IParseDisplayName_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IParseDisplayNameProxyVtbl = 
{
    &IParseDisplayName_ProxyInfo,
    &IID_IParseDisplayName,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IParseDisplayName::ParseDisplayName */
};

const CInterfaceStubVtbl _IParseDisplayNameStubVtbl =
{
    &IID_IParseDisplayName,
    &IParseDisplayName_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleContainer, ver. 0.0,
   GUID={0x0000011b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleContainer_FormatStringOffsetTable[] =
    {
    1044,
    1098,
    1140
    };

static const MIDL_STUBLESS_PROXY_INFO IOleContainer_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleContainer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleContainer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleContainer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IOleContainerProxyVtbl = 
{
    &IOleContainer_ProxyInfo,
    &IID_IOleContainer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IParseDisplayName::ParseDisplayName */ ,
    (void *) (INT_PTR) -1 /* IOleContainer::EnumObjects */ ,
    (void *) (INT_PTR) -1 /* IOleContainer::LockContainer */
};

const CInterfaceStubVtbl _IOleContainerStubVtbl =
{
    &IID_IOleContainer,
    &IOleContainer_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleItemContainer, ver. 0.0,
   GUID={0x0000011c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleItemContainer_FormatStringOffsetTable[] =
    {
    1044,
    1098,
    1140,
    1176,
    1236,
    1290
    };

static const MIDL_STUBLESS_PROXY_INFO IOleItemContainer_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleItemContainer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleItemContainer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleItemContainer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOleItemContainerProxyVtbl = 
{
    &IOleItemContainer_ProxyInfo,
    &IID_IOleItemContainer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IParseDisplayName::ParseDisplayName */ ,
    (void *) (INT_PTR) -1 /* IOleContainer::EnumObjects */ ,
    (void *) (INT_PTR) -1 /* IOleContainer::LockContainer */ ,
    (void *) (INT_PTR) -1 /* IOleItemContainer::GetObject */ ,
    (void *) (INT_PTR) -1 /* IOleItemContainer::GetObjectStorage */ ,
    (void *) (INT_PTR) -1 /* IOleItemContainer::IsRunning */
};

const CInterfaceStubVtbl _IOleItemContainerStubVtbl =
{
    &IID_IOleItemContainer,
    &IOleItemContainer_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleLink, ver. 0.0,
   GUID={0x0000011d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleLink_FormatStringOffsetTable[] =
    {
    1326,
    1362,
    1398,
    1440,
    1476,
    1512,
    1548,
    1590,
    1620,
    948,
    1656
    };

static const MIDL_STUBLESS_PROXY_INFO IOleLink_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleLink_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleLink_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleLink_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IOleLinkProxyVtbl = 
{
    &IOleLink_ProxyInfo,
    &IID_IOleLink,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleLink::SetUpdateOptions */ ,
    (void *) (INT_PTR) -1 /* IOleLink::GetUpdateOptions */ ,
    (void *) (INT_PTR) -1 /* IOleLink::SetSourceMoniker */ ,
    (void *) (INT_PTR) -1 /* IOleLink::GetSourceMoniker */ ,
    (void *) (INT_PTR) -1 /* IOleLink::SetSourceDisplayName */ ,
    (void *) (INT_PTR) -1 /* IOleLink::GetSourceDisplayName */ ,
    (void *) (INT_PTR) -1 /* IOleLink::BindToSource */ ,
    (void *) (INT_PTR) -1 /* IOleLink::BindIfRunning */ ,
    (void *) (INT_PTR) -1 /* IOleLink::GetBoundSource */ ,
    (void *) (INT_PTR) -1 /* IOleLink::UnbindSource */ ,
    (void *) (INT_PTR) -1 /* IOleLink::Update */
};

const CInterfaceStubVtbl _IOleLinkStubVtbl =
{
    &IID_IOleLink,
    &IOleLink_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleClientSite, ver. 0.0,
   GUID={0x00000118,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleClientSite_FormatStringOffsetTable[] =
    {
    1692,
    1722,
    1770,
    102,
    630,
    174
    };

static const MIDL_STUBLESS_PROXY_INFO IOleClientSite_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleClientSite_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleClientSite_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleClientSite_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IOleClientSiteProxyVtbl = 
{
    &IOleClientSite_ProxyInfo,
    &IID_IOleClientSite,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleClientSite::SaveObject */ ,
    (void *) (INT_PTR) -1 /* IOleClientSite::GetMoniker */ ,
    (void *) (INT_PTR) -1 /* IOleClientSite::GetContainer */ ,
    (void *) (INT_PTR) -1 /* IOleClientSite::ShowObject */ ,
    (void *) (INT_PTR) -1 /* IOleClientSite::OnShowWindow */ ,
    (void *) (INT_PTR) -1 /* IOleClientSite::RequestNewObjectLayout */
};

const CInterfaceStubVtbl _IOleClientSiteStubVtbl =
{
    &IID_IOleClientSite,
    &IOleClientSite_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleCache, ver. 0.0,
   GUID={0x0000011e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleCache_FormatStringOffsetTable[] =
    {
    1806,
    36,
    1854,
    1890,
    1926
    };

static const MIDL_STUBLESS_PROXY_INFO IOleCache_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleCache_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleCache_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleCache_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IOleCacheProxyVtbl = 
{
    &IOleCache_ProxyInfo,
    &IID_IOleCache,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleCache::Cache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::Uncache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::EnumCache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::InitCache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::SetData */
};

const CInterfaceStubVtbl _IOleCacheStubVtbl =
{
    &IID_IOleCache,
    &IOleCache_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleCache2, ver. 0.0,
   GUID={0x00000128,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleCache2_FormatStringOffsetTable[] =
    {
    1806,
    36,
    1854,
    1890,
    1926,
    1974,
    720
    };

static const MIDL_STUBLESS_PROXY_INFO IOleCache2_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleCache2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IOleCache2_StubThunkTable[] = 
    {
    0,
    0,
    0,
    0,
    0,
    IOleCache2_RemoteUpdateCache_Thunk,
    0
    };

static const MIDL_SERVER_INFO IOleCache2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleCache2_FormatStringOffsetTable[-3],
    &IOleCache2_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IOleCache2ProxyVtbl = 
{
    &IOleCache2_ProxyInfo,
    &IID_IOleCache2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleCache::Cache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::Uncache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::EnumCache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::InitCache */ ,
    (void *) (INT_PTR) -1 /* IOleCache::SetData */ ,
    IOleCache2_UpdateCache_Proxy ,
    (void *) (INT_PTR) -1 /* IOleCache2::DiscardCache */
};

const CInterfaceStubVtbl _IOleCache2StubVtbl =
{
    &IID_IOleCache2,
    &IOleCache2_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleCacheControl, ver. 0.0,
   GUID={0x00000129,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleCacheControl_FormatStringOffsetTable[] =
    {
    2022,
    2058
    };

static const MIDL_STUBLESS_PROXY_INFO IOleCacheControl_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleCacheControl_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleCacheControl_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleCacheControl_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IOleCacheControlProxyVtbl = 
{
    &IOleCacheControl_ProxyInfo,
    &IID_IOleCacheControl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleCacheControl::OnRun */ ,
    (void *) (INT_PTR) -1 /* IOleCacheControl::OnStop */
};

const CInterfaceStubVtbl _IOleCacheControlStubVtbl =
{
    &IID_IOleCacheControl,
    &IOleCacheControl_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IEnumOLEVERB, ver. 0.0,
   GUID={0x00000104,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IEnumOLEVERB_FormatStringOffsetTable[] =
    {
    2088,
    36,
    72,
    2136
    };

static const MIDL_STUBLESS_PROXY_INFO IEnumOLEVERB_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IEnumOLEVERB_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IEnumOLEVERB_StubThunkTable[] = 
    {
    IEnumOLEVERB_RemoteNext_Thunk,
    0,
    0,
    0
    };

static const MIDL_SERVER_INFO IEnumOLEVERB_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IEnumOLEVERB_FormatStringOffsetTable[-3],
    &IEnumOLEVERB_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IEnumOLEVERBProxyVtbl = 
{
    &IEnumOLEVERB_ProxyInfo,
    &IID_IEnumOLEVERB,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IEnumOLEVERB_Next_Proxy ,
    (void *) (INT_PTR) -1 /* IEnumOLEVERB::Skip */ ,
    (void *) (INT_PTR) -1 /* IEnumOLEVERB::Reset */ ,
    (void *) (INT_PTR) -1 /* IEnumOLEVERB::Clone */
};

const CInterfaceStubVtbl _IEnumOLEVERBStubVtbl =
{
    &IID_IEnumOLEVERB,
    &IEnumOLEVERB_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleObject, ver. 0.0,
   GUID={0x00000112,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IOleObject_FormatStringOffsetTable[] =
    {
    2172,
    2208,
    2244,
    594,
    2286,
    2328,
    2376,
    2424,
    2466,
    2532,
    978,
    2568,
    2598,
    2634,
    2676,
    2718,
    2760,
    2802,
    2838,
    2874,
    2916
    };

static const MIDL_STUBLESS_PROXY_INFO IOleObject_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOleObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IOleObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(24) _IOleObjectProxyVtbl = 
{
    &IOleObject_ProxyInfo,
    &IID_IOleObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IOleObject::SetClientSite */ ,
    (void *) (INT_PTR) -1 /* IOleObject::GetClientSite */ ,
    (void *) (INT_PTR) -1 /* IOleObject::SetHostNames */ ,
    (void *) (INT_PTR) -1 /* IOleObject::Close */ ,
    (void *) (INT_PTR) -1 /* IOleObject::SetMoniker */ ,
    (void *) (INT_PTR) -1 /* IOleObject::GetMoniker */ ,
    (void *) (INT_PTR) -1 /* IOleObject::InitFromData */ ,
    (void *) (INT_PTR) -1 /* IOleObject::GetClipboardData */ ,
    (void *) (INT_PTR) -1 /* IOleObject::DoVerb */ ,
    (void *) (INT_PTR) -1 /* IOleObject::EnumVerbs */ ,
    (void *) (INT_PTR) -1 /* IOleObject::Update */ ,
    (void *) (INT_PTR) -1 /* IOleObject::IsUpToDate */ ,
    (void *) (INT_PTR) -1 /* IOleObject::GetUserClassID */ ,
    (void *) (INT_PTR) -1 /* IOleObject::GetUserType */ ,
    (void *) (INT_PTR) -1 /* IOleObject::SetExtent */ ,
    (void *) (INT_PTR) -1 /* IOleObject::GetExtent */ ,
    (void *) (INT_PTR) -1 /* IOleObject::Advise */ ,
    (void *) (INT_PTR) -1 /* IOleObject::Unadvise */ ,
    (void *) (INT_PTR) -1 /* IOleObject::EnumAdvise */ ,
    (void *) (INT_PTR) -1 /* IOleObject::GetMiscStatus */ ,
    (void *) (INT_PTR) -1 /* IOleObject::SetColorScheme */
};

const CInterfaceStubVtbl _IOleObjectStubVtbl =
{
    &IID_IOleObject,
    &IOleObject_ServerInfo,
    24,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IOleAdviseHolder, ver. 0.0,
   GUID={0x00000111,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IContinue, ver. 0.0,
   GUID={0x0000012a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IContinue_FormatStringOffsetTable[] =
    {
    1692
    };

static const MIDL_STUBLESS_PROXY_INFO IContinue_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IContinue_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IContinue_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IContinue_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IContinueProxyVtbl = 
{
    &IContinue_ProxyInfo,
    &IID_IContinue,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IContinue::FContinue */
};

const CInterfaceStubVtbl _IContinueStubVtbl =
{
    &IID_IContinue,
    &IContinue_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IViewObject, ver. 0.0,
   GUID={0x0000010d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IViewObject_FormatStringOffsetTable[] =
    {
    2952,
    3036,
    3102,
    594,
    3156,
    3204
    };

static const MIDL_STUBLESS_PROXY_INFO IViewObject_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IViewObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IViewObject_StubThunkTable[] = 
    {
    IViewObject_RemoteDraw_Thunk,
    IViewObject_RemoteGetColorSet_Thunk,
    IViewObject_RemoteFreeze_Thunk,
    0,
    0,
    IViewObject_RemoteGetAdvise_Thunk
    };

static const MIDL_SERVER_INFO IViewObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IViewObject_FormatStringOffsetTable[-3],
    &IViewObject_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IViewObjectProxyVtbl = 
{
    &IViewObject_ProxyInfo,
    &IID_IViewObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IViewObject_Draw_Proxy ,
    IViewObject_GetColorSet_Proxy ,
    IViewObject_Freeze_Proxy ,
    (void *) (INT_PTR) -1 /* IViewObject::Unfreeze */ ,
    (void *) (INT_PTR) -1 /* IViewObject::SetAdvise */ ,
    IViewObject_GetAdvise_Proxy
};

const CInterfaceStubVtbl _IViewObjectStubVtbl =
{
    &IID_IViewObject,
    &IViewObject_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IViewObject2, ver. 0.0,
   GUID={0x00000127,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IViewObject2_FormatStringOffsetTable[] =
    {
    2952,
    3036,
    3102,
    594,
    3156,
    3204,
    3252
    };

static const MIDL_STUBLESS_PROXY_INFO IViewObject2_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IViewObject2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const STUB_THUNK IViewObject2_StubThunkTable[] = 
    {
    IViewObject_RemoteDraw_Thunk,
    IViewObject_RemoteGetColorSet_Thunk,
    IViewObject_RemoteFreeze_Thunk,
    0,
    0,
    IViewObject_RemoteGetAdvise_Thunk,
    0
    };

static const MIDL_SERVER_INFO IViewObject2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IViewObject2_FormatStringOffsetTable[-3],
    &IViewObject2_StubThunkTable[-3],
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IViewObject2ProxyVtbl = 
{
    &IViewObject2_ProxyInfo,
    &IID_IViewObject2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    IViewObject_Draw_Proxy ,
    IViewObject_GetColorSet_Proxy ,
    IViewObject_Freeze_Proxy ,
    (void *) (INT_PTR) -1 /* IViewObject::Unfreeze */ ,
    (void *) (INT_PTR) -1 /* IViewObject::SetAdvise */ ,
    IViewObject_GetAdvise_Proxy ,
    (void *) (INT_PTR) -1 /* IViewObject2::GetExtent */
};

const CInterfaceStubVtbl _IViewObject2StubVtbl =
{
    &IID_IViewObject2,
    &IViewObject2_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IDropSource, ver. 0.0,
   GUID={0x00000121,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDropTarget, ver. 0.0,
   GUID={0x00000122,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */

#pragma code_seg(".orpc")
static const unsigned short IDropTarget_FormatStringOffsetTable[] =
    {
    3306,
    3360,
    72,
    3408
    };

static const MIDL_STUBLESS_PROXY_INFO IDropTarget_ProxyInfo =
    {
    &Object_StubDesc,
    oleidl__MIDL_ProcFormatString.Format,
    &IDropTarget_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDropTarget_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    oleidl__MIDL_ProcFormatString.Format,
    &IDropTarget_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IDropTargetProxyVtbl = 
{
    &IDropTarget_ProxyInfo,
    &IID_IDropTarget,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IDropTarget::DragEnter */ ,
    (void *) (INT_PTR) -1 /* IDropTarget::DragOver */ ,
    (void *) (INT_PTR) -1 /* IDropTarget::DragLeave */ ,
    (void *) (INT_PTR) -1 /* IDropTarget::Drop */
};

const CInterfaceStubVtbl _IDropTargetStubVtbl =
{
    &IID_IDropTarget,
    &IDropTarget_ServerInfo,
    7,
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
    ExprEvalRoutines,
    0,
    oleidl__MIDL_TypeFormatString.Format,
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

const CInterfaceProxyVtbl * _oleidl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IEnumOLEVERBProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IViewObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleInPlaceObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleWindowProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleInPlaceUIWindowProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleInPlaceFrameProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleInPlaceActiveObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleClientSiteProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleInPlaceSiteProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IParseDisplayNameProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleContainerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleItemContainerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleLinkProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleCacheProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDropTargetProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IViewObject2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleCache2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOleCacheControlProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IContinueProxyVtbl,
    0
};

const CInterfaceStubVtbl * _oleidl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IEnumOLEVERBStubVtbl,
    ( CInterfaceStubVtbl *) &_IViewObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleInPlaceObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleWindowStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleInPlaceUIWindowStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleInPlaceFrameStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleInPlaceActiveObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleClientSiteStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleInPlaceSiteStubVtbl,
    ( CInterfaceStubVtbl *) &_IParseDisplayNameStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleContainerStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleItemContainerStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleLinkStubVtbl,
    ( CInterfaceStubVtbl *) &_IOleCacheStubVtbl,
    ( CInterfaceStubVtbl *) &_IDropTargetStubVtbl,
    ( CInterfaceStubVtbl *) &_IViewObject2StubVtbl,
    ( CInterfaceStubVtbl *) &_IOleCache2StubVtbl,
    ( CInterfaceStubVtbl *) &_IOleCacheControlStubVtbl,
    ( CInterfaceStubVtbl *) &_IContinueStubVtbl,
    0
};

PCInterfaceName const _oleidl_InterfaceNamesList[] = 
{
    "IEnumOLEVERB",
    "IViewObject",
    "IOleObject",
    "IOleInPlaceObject",
    "IOleWindow",
    "IOleInPlaceUIWindow",
    "IOleInPlaceFrame",
    "IOleInPlaceActiveObject",
    "IOleClientSite",
    "IOleInPlaceSite",
    "IParseDisplayName",
    "IOleContainer",
    "IOleItemContainer",
    "IOleLink",
    "IOleCache",
    "IDropTarget",
    "IViewObject2",
    "IOleCache2",
    "IOleCacheControl",
    "IContinue",
    0
};


#define _oleidl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _oleidl, pIID, n)

int __stdcall _oleidl_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _oleidl, 20, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _oleidl, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _oleidl, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _oleidl, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _oleidl, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _oleidl, 20, *pIndex )
    
}

const ExtendedProxyFileInfo oleidl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _oleidl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _oleidl_StubVtblList,
    (const PCInterfaceName * ) & _oleidl_InterfaceNamesList,
    0, // no delegation
    & _oleidl_IID_Lookup, 
    20,
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

