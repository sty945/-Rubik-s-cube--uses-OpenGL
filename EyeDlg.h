#if !defined(AFX_EYEDLG_H__E061046A_7510_11D7_9391_88CE1F68853D__INCLUDED_)
#define AFX_EYEDLG_H__E061046A_7510_11D7_9391_88CE1F68853D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EyeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEyeDlg dialog

class CEyeDlg : public CDialog
{
// Construction
public:
	CEyeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEyeDlg)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEyeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEyeDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EYEDLG_H__E061046A_7510_11D7_9391_88CE1F68853D__INCLUDED_)
