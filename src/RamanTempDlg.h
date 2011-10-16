// RamanTempDlg.h : header file
//

#if !defined(AFX_RAMANTEMPDLG_H__B25B9B5F_B4E3_49E6_AA21_DDEB7C8A305C__INCLUDED_)
#define AFX_RAMANTEMPDLG_H__B25B9B5F_B4E3_49E6_AA21_DDEB7C8A305C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRamanTempDlg dialog

class CRamanTempDlg : public CDialog
{
// Construction
public:
	CRamanTempDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRamanTempDlg)
	enum { IDD = IDD_RAMANTEMP_DIALOG };
	CString	m_disptemp;
	CString	m_disptempc;
	CString	m_ratio;
	double	m_stokes;
	double	m_astokes;
	double	m_wavenumber;
	double	m_incident;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRamanTempDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRamanTempDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAboutbtn();
	afx_msg void OnWaveNumber();
	afx_msg void OnStokes();
	afx_msg void OnChangeAstokes();
	afx_msg void FindTemperature();
	afx_msg void OnChangeIncident();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAMANTEMPDLG_H__B25B9B5F_B4E3_49E6_AA21_DDEB7C8A305C__INCLUDED_)
