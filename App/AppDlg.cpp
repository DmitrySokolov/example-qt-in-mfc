
// AppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "App.h"
#include "AppDlg.h"
#include "afxdialogex.h"

#include <mydialog_api.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAppDlg dialog


CAppDlg::CAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_APP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAppDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAppDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAppDlg message handlers

BOOL CAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAppDlg::OnPaint()
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
HCURSOR CAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CStringW utf8_to_CStringW(char* data)
{
	if (!data || data[0] == '\0') return L"";

	CStringW res;
	int len = 0;

	if ((len = MultiByteToWideChar(CP_UTF8, 0, data, -1, NULL, 0) - 1) > 0)
	{
		wchar_t* buf = res.GetBuffer(len);
		if (buf) MultiByteToWideChar(CP_UTF8, 0, data, -1, buf, len);
		res.ReleaseBuffer();
	}
	return res;
}

CAppDlg* self = nullptr;


void updateData(char** data, size_t data_size)
{
	if (!self || !data || data_size == 0) {return;}
	self->SetDlgItemText(IDC_STATIC2, utf8_to_CStringW(data[0]));
}


void CAppDlg::OnBnClickedButton1()
{
	self = this;
	showMyDialog(updateData);
}
