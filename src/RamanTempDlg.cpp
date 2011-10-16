// RamanTempDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RamanTemp.h"
#include "RamanTempDlg.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRamanTempDlg dialog

CRamanTempDlg::CRamanTempDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRamanTempDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRamanTempDlg)
	m_disptemp = _T("");
	m_disptempc = _T("");
	m_ratio = _T("");
	m_stokes = 4300;
	m_astokes = 346;
	m_wavenumber = 521.5;
	m_incident = 632.817;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRamanTempDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRamanTempDlg)
	DDX_Text(pDX, IDC_TEMP, m_disptemp);
	DDX_Text(pDX, IDC_TEMPC, m_disptempc);
	DDX_Text(pDX, IDC_RATIO, m_ratio);
	DDX_Text(pDX, IDC_STOKES, m_stokes);
	DDV_MinMaxDouble(pDX, m_stokes, 1., 1.e+020);
	DDX_Text(pDX, IDC_ASTOKES, m_astokes);
	DDV_MinMaxDouble(pDX, m_astokes, 1., 1.e+020);
	DDX_Text(pDX, IDC_WAVENUMBER, m_wavenumber);
	DDV_MinMaxDouble(pDX, m_wavenumber, 1., 20000.);
	DDX_Text(pDX, IDC_INCIDENT, m_incident);
	DDV_MinMaxDouble(pDX, m_incident, 1., 20000.);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRamanTempDlg, CDialog)
	//{{AFX_MSG_MAP(CRamanTempDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ABOUTBTN, OnAboutbtn)
	ON_EN_CHANGE(IDC_WAVENUMBER, OnWaveNumber)
	ON_EN_CHANGE(IDC_STOKES, OnStokes)
	ON_EN_CHANGE(IDC_ASTOKES, OnChangeAstokes)
	ON_EN_CHANGE(IDC_INCIDENT, OnChangeIncident)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRamanTempDlg message handlers

BOOL CRamanTempDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	FindTemperature();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRamanTempDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRamanTempDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRamanTempDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRamanTempDlg::OnAboutbtn() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg Dlg3;
	Dlg3.DoModal();
}

void CRamanTempDlg::OnWaveNumber() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
FindTemperature();


}

void CRamanTempDlg::OnStokes() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
FindTemperature();

}

void CRamanTempDlg::OnChangeAstokes() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	

	FindTemperature();
}


void CRamanTempDlg::OnChangeIncident() 
{
	FindTemperature();
	
}

void CRamanTempDlg::FindTemperature()

{	double factor, temp, coeff;
	factor=1.45;
	UpdateData(true);
	
	coeff=(pow(((1.0e+7/m_incident) + m_wavenumber),3)/pow(((1.0e+7/m_incident) - m_wavenumber),3));
	temp=m_wavenumber*factor/log(m_stokes*coeff/m_astokes);
	
	if(m_stokes/m_astokes==1)
	{	m_disptemp.Format("not allowed");
		m_disptempc.Format("not allowed");
	}

	else
	{	
		

		if(temp<=0)
			{m_disptemp.Format("T<0 !!!");
			m_disptempc.Format("T<-273 !!!");}
		else
		{
			m_disptemp.Format("%.1f", temp);
			m_disptempc.Format("%.1f", temp-273.3);
			m_ratio.Format("%.3f",m_stokes/m_astokes);
		}

	}

	UpdateData(false);
}


