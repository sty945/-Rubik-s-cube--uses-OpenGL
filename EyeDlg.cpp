// EyeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GL.h"
#include "EyeDlg.h"
#include "GLDoc.h"
#include "GLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEyeDlg dialog


CEyeDlg::CEyeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEyeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEyeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEyeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEyeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEyeDlg, CDialog)
	//{{AFX_MSG_MAP(CEyeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEyeDlg message handlers

BOOL CEyeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	char str[50];
	CFrameWnd *pFrame = (CFrameWnd *)AfxGetApp()->m_pMainWnd;
	CGLView *pView = (CGLView *)pFrame->GetActiveView();
	sprintf(str, "%f", pView->m_Eye[0]);
	SetDlgItemText(IDC_EDIT1, str);
	sprintf(str, "%f", pView->m_Eye[1]);
	SetDlgItemText(IDC_EDIT2, str);
	sprintf(str, "%f", pView->m_Eye[2]);
	SetDlgItemText(IDC_EDIT3, str);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEyeDlg::OnOK() 
{
	// TODO: Add extra validation here
	char str[50];
	CFrameWnd *pFrame = (CFrameWnd *)AfxGetApp()->m_pMainWnd;
	CGLView *pView = (CGLView *)pFrame->GetActiveView();
	GetDlgItemText(IDC_EDIT1, str, 50);
	pView->m_Eye[0] = (float)atof(str);
	GetDlgItemText(IDC_EDIT2, str, 50);
	pView->m_Eye[1] = (float)atof(str);
	GetDlgItemText(IDC_EDIT3, str, 50);
	pView->m_Eye[2] = (float)atof(str);
	pView->Invalidate();
	pView->UpdateWindow();
	CDialog::OnOK();
}
