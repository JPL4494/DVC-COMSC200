
// GeometryHomework7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "GeometryHomework7.h"
#include "GeometryHomework7Dlg.h"
#include "afxdialogex.h"
#include "GeometryHomework.h"

#include <sstream> 
using std::ostringstream;

#include <string> 
using std::string; 

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
	ON_BN_CLICKED(IDOK, &CGeometryHomework7Dlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CGeometryHomework7Dlg::OnCbnSelchangeCombo1)
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
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombo->InsertString(0, "Square");
	pCombo->InsertString(1, "Rectange");
	pCombo->InsertString(2, "Circle");
	pCombo->InsertString(3, "Cube");
	pCombo->InsertString(4, "Cylinder");
	pCombo->InsertString(5, "Prism");
	pCombo->SetCurSel(-1);

	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);

	CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
    MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION); 
	pPicture->SetBitmap(hb);

	CStatic* pStatic9 = (CStatic*)GetDlgItem(IDC_STATIC9);
	pStatic9->SetWindowText("Shapes Calculator:\nSelect a shape and enter the dimensions\nto get the area and perimeter(2D)\nor surface are and volume(3D)");

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



void CGeometryHomework7Dlg::OnBnClickedOk()
{
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int pick = pCombo->GetCurSel();

	switch(pick)
	{
	case 0:
		{
			CEdit* pEdits = (CEdit*)GetDlgItem(IDC_EDIT1);
			CString edits;
			pEdits->GetWindowText(edits);
			const char* const temp = (LPCTSTR)edits;
			const char* const token [] = {temp,temp,temp,temp};
			Square s(token);

			ostringstream soutS;
			soutS << &s;

			string outputS; 
			outputS = soutS.str();

			CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
			CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
			pStatic4->SetWindowText("Results:");
			pStatic5->SetWindowText(outputS.c_str());

		}break;
	case 1:
		{
			CEdit* Edits1 = (CEdit*)GetDlgItem(IDC_EDIT1);
			CEdit* Edits2 = (CEdit*)GetDlgItem(IDC_EDIT2);
			CString edit1, edit2;
			Edits1->GetWindowText(edit1);
			Edits2->GetWindowText(edit2);
			const char* const temp1 = (LPCTSTR)edit1;
			const char* const temp2 = (LPCTSTR)edit2;
			const char* const token [] = {temp1,temp1,temp2,temp2};
			JPL::Rectangle r(token);

			ostringstream soutR;
			soutR << &r;

			string outputR; 
			outputR = soutR.str();

			CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
			CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
			pStatic4->SetWindowText("Results:");
			pStatic5->SetWindowText(outputR.c_str());

		}break;
	case 2:
		{
			CEdit* pEdits = (CEdit*)GetDlgItem(IDC_EDIT1);
			CString edits;
			pEdits->GetWindowText(edits);
			const char* const temp = (LPCTSTR)edits;
			const char* const token [] = {temp,temp,temp,temp};
			Circle c(token);

			ostringstream soutC;
			soutC << &c;

			string outputC; 
			outputC = soutC.str();

			CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
			CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
			pStatic4->SetWindowText("Results:");
			pStatic5->SetWindowText(outputC.c_str());
		}break;
	case 3:
		{
			CEdit* pEdits = (CEdit*)GetDlgItem(IDC_EDIT1);
			CString edits;
			pEdits->GetWindowText(edits);
			const char* const temp = (LPCTSTR)edits;
			const char* const token [] = {temp,temp,temp,temp};
			Cube c(token);

			ostringstream sout;
			sout << &c;

			string outputCB; 
			outputCB = sout.str();

			CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
			CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
			pStatic4->SetWindowText("Results:");
			pStatic5->SetWindowText(outputCB.c_str());
		}break;
	case 4:
		{
			CEdit* Edits1 = (CEdit*)GetDlgItem(IDC_EDIT1);
			CEdit* Edits2 = (CEdit*)GetDlgItem(IDC_EDIT2);
			CString edit1, edit2;
			Edits1->GetWindowText(edit1);
			Edits2->GetWindowText(edit2);
			const char* const temp1 = (LPCTSTR)edit1;
			const char* const temp2 = (LPCTSTR)edit2;
			const char* const token [] = {temp1,temp1,temp2,temp2};
			Cylinder c(token);

			ostringstream sout;
			sout << &c;

			string outputCY; 
			outputCY = sout.str();

			CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
			CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
			pStatic4->SetWindowText("Results:");
			pStatic5->SetWindowText(outputCY.c_str());
		}break;
	case 5:
		{
			CEdit* Edits1 = (CEdit*)GetDlgItem(IDC_EDIT1);
			CEdit* Edits2 = (CEdit*)GetDlgItem(IDC_EDIT2);
			CEdit* Edits3 = (CEdit*)GetDlgItem(IDC_EDIT3);
			CString edit1, edit2, edit3;
			Edits1->GetWindowText(edit1);
			Edits2->GetWindowText(edit2);
			Edits3->GetWindowText(edit3);
			const char* const temp1 = (LPCTSTR)edit1;
			const char* const temp2 = (LPCTSTR)edit2;
			const char* const temp3 = (LPCTSTR)edit3;
			const char* const token [] = {temp1,temp1,temp2,temp3};
			Prism p(token);

			ostringstream sout;
			sout << &p;

			string outputP; 
			outputP = sout.str();

			CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
			CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
			pStatic4->SetWindowText("Results:");
			pStatic5->SetWindowText(outputP.c_str());
		}break;
	}
}


void CGeometryHomework7Dlg::OnCbnSelchangeCombo1()
{
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int pick = pCombo->GetCurSel();

	CStatic* pStatic4 = (CStatic*)GetDlgItem(IDC_STATIC4);
	CStatic* pStatic5 = (CStatic*)GetDlgItem(IDC_STATIC5);
	pStatic4->SetWindowText(" ");
	pStatic5->SetWindowText(" ");

	CEdit* Edits1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* Edits2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* Edits3 = (CEdit*)GetDlgItem(IDC_EDIT3);

	Edits1->SetWindowTextA("");
	Edits2->SetWindowTextA("");
	Edits3->SetWindowTextA("");

	switch(pick)
	{
	case 0:
		{
			CStatic* pStatic0 = (CStatic*)GetDlgItem(IDC_STATIC0);
			CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
			CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
			CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
			pStatic0->SetWindowText("Enter Dimension:");
			pStatic1->SetWindowText("Side:");
			pStatic2->SetWindowText("");
			pStatic3->SetWindowText("");
			GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);

			CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
			pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
			HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION); 
			pPicture->SetBitmap(hb);
		}break;
	case 1:
		{
			CStatic* pStatic0 = (CStatic*)GetDlgItem(IDC_STATIC0);
			CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
			CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
			CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
			pStatic0->SetWindowText("Enter Dimensions:");
			pStatic1->SetWindowText("Length:");
			pStatic2->SetWindowText("Width");
			pStatic3->SetWindowText("");
			GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);

			CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
			pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
			HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION); 
			pPicture->SetBitmap(hb);
		}break;
	case 2:
		{
			CStatic* pStatic0 = (CStatic*)GetDlgItem(IDC_STATIC0);
			CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
			CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
			CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
			pStatic0->SetWindowText("Enter Dimension:");
			pStatic1->SetWindowText("Radius:");
			pStatic2->SetWindowText("");
			pStatic3->SetWindowText("");
			GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);

			CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
			pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
			HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION); 
			pPicture->SetBitmap(hb);
		}break;
	case 3:
		{
			CStatic* pStatic0 = (CStatic*)GetDlgItem(IDC_STATIC0);
			CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
			CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
			CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
			pStatic0->SetWindowText("Enter Dimension:");
			pStatic1->SetWindowText("Side:");
			pStatic2->SetWindowText("");
			pStatic3->SetWindowText("");
			GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);

			CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
			pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
			HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			MAKEINTRESOURCE(IDB_BITMAP5), IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION); 
			pPicture->SetBitmap(hb);
		}break;
	case 4:
		{
			CStatic* pStatic0 = (CStatic*)GetDlgItem(IDC_STATIC0);
			CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
			CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
			CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
			pStatic0->SetWindowText("Enter Dimensions:");
			pStatic1->SetWindowText("Radius:");
			pStatic2->SetWindowText("Height");
			pStatic3->SetWindowText("");
			GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);

			CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
			pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
			HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			MAKEINTRESOURCE(IDB_BITMAP6), IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION); 
			pPicture->SetBitmap(hb);
		}break;
	case 5:
		{
			CStatic* pStatic0 = (CStatic*)GetDlgItem(IDC_STATIC0);
			CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
			CStatic* pStatic2 = (CStatic*)GetDlgItem(IDC_STATIC2);
			CStatic* pStatic3 = (CStatic*)GetDlgItem(IDC_STATIC3);
			pStatic0->SetWindowText("Enter Dimensions:");
			pStatic1->SetWindowText("Length:");
			pStatic2->SetWindowText("Width:");
			pStatic3->SetWindowText("Height:");
			GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);

			CStatic* pPicture = (CStatic*)GetDlgItem(IDC_STATIC8);
			pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
			HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), 
			MAKEINTRESOURCE(IDB_BITMAP7), IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION); 
			pPicture->SetBitmap(hb);
		}break;
	}
}
