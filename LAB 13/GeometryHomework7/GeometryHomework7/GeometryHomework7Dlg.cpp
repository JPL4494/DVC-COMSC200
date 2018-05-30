
// GeometryHomework7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GeometryHomework7.h"
#include "GeometryHomework7Dlg.h"
#include "afxdialogex.h"

#include <sstream> 
using std::ostringstream; 

#include <string>
using std::string;

#include "GeometryHomework.h"
#include "GeometryHomework.cpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGeometryHomework7Dlg dialog



CGeometryHomework7Dlg::CGeometryHomework7Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGeometryHomework7Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGeometryHomework7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGeometryHomework7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CGeometryHomework7Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CGeometryHomework7Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CGeometryHomework7Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CGeometryHomework7Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CGeometryHomework7Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CGeometryHomework7Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDOK, &CGeometryHomework7Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CGeometryHomework7Dlg message handlers

BOOL CGeometryHomework7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGeometryHomework7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGeometryHomework7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGeometryHomework7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGeometryHomework7Dlg::OnBnClickedRadio1()
{
	CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
	CStatic* pStatic6 = (CStatic*)GetDlgItem(IDC_STATIC6);
	pStatic4->SetWindowText("Side:");
	pStatic5->SetWindowText("");
	pStatic6->SetWindowText("");
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
}



void CGeometryHomework7Dlg::OnBnClickedRadio2()
{
	CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
	CStatic* pStatic6 = (CStatic*)GetDlgItem(IDC_STATIC6);
	pStatic4->SetWindowText("Length:");
	pStatic5->SetWindowText("Width:");
	pStatic6->SetWindowText("");
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
}


void CGeometryHomework7Dlg::OnBnClickedRadio3()
{
	CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
	CStatic* pStatic6 = (CStatic*)GetDlgItem(IDC_STATIC6);
	pStatic4->SetWindowText("Radius:");
	pStatic5->SetWindowText("");
	pStatic6->SetWindowText("");
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
}


void CGeometryHomework7Dlg::OnBnClickedRadio4()
{
	CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
	CStatic* pStatic6 = (CStatic*)GetDlgItem(IDC_STATIC6);
	pStatic4->SetWindowText("Side:");
	pStatic5->SetWindowText("");
	pStatic6->SetWindowText("");
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
}


void CGeometryHomework7Dlg::OnBnClickedRadio5()
{
	CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
	CStatic* pStatic6 = (CStatic*)GetDlgItem(IDC_STATIC6);
	pStatic4->SetWindowText("Length:");
	pStatic5->SetWindowText("Width:");
	pStatic6->SetWindowText("Height:");
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
}


void CGeometryHomework7Dlg::OnBnClickedRadio6()
{
	CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
	CStatic* pStatic6 = (CStatic*)GetDlgItem(IDC_STATIC6);
	pStatic4->SetWindowText("Radius:");
	pStatic5->SetWindowText("Height:");
	pStatic6->SetWindowText("");
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
}


void CGeometryHomework7Dlg::OnBnClickedOk()
{
	CButton* p1Radio = (CButton*)GetDlgItem(IDC_RADIO1);
    int r1 = p1Radio->GetCheck();
	CButton* p2Radio = (CButton*)GetDlgItem(IDC_RADIO2);
	int r2 = p2Radio->GetCheck();
	CButton* p3Radio = (CButton*)GetDlgItem(IDC_RADIO3);
	int r3 = p3Radio->GetCheck();
	CButton* p4Radio = (CButton*)GetDlgItem(IDC_RADIO4);
	int r4 = p4Radio->GetCheck();
	CButton* p5Radio = (CButton*)GetDlgItem(IDC_RADIO5);
	int r5 = p5Radio->GetCheck();
	CButton* p6Radio = (CButton*)GetDlgItem(IDC_RADIO6);
	int r6 = p6Radio->GetCheck();

	if (r1 == 1)
	{
		CEdit* pEdits = (CEdit*)GetDlgItem(IDC_EDIT1);

		CString edits;
		pEdits->GetWindowText(edits);

		string s = CStringA(edits);
		const char const * c = s.c_str();
		const char const * token[] = {c,c};
		JPL::Square squareOn(token);

		///ostringstream sout; // a buffer 
		///sout << Cconvert;
		///pEditC->SetWindowText(sout.str().c_str());
	}
	///CDialogEx::OnOK(); ///Exit Code
}
