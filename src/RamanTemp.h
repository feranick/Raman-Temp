// RamanTemp.h : main header file for the RAMANTEMP application
//

#if !defined(AFX_RAMANTEMP_H__649D37F6_01AC_4142_A530_983A1699F1D5__INCLUDED_)
#define AFX_RAMANTEMP_H__649D37F6_01AC_4142_A530_983A1699F1D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRamanTempApp:
// See RamanTemp.cpp for the implementation of this class
//

class CRamanTempApp : public CWinApp
{
public:
	CRamanTempApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRamanTempApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRamanTempApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAMANTEMP_H__649D37F6_01AC_4142_A530_983A1699F1D5__INCLUDED_)
