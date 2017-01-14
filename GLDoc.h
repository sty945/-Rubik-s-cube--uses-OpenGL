// GLDoc.h : interface of the CGLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLDOC_H__81B758EB_6D10_11D7_9391_D6C3514BFA3D__INCLUDED_)
#define AFX_GLDOC_H__81B758EB_6D10_11D7_9391_D6C3514BFA3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGLDoc : public CDocument
{
protected: // create from serialization only
	CGLDoc();
	DECLARE_DYNCREATE(CGLDoc)

// Attributes
public:

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CGLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLDOC_H__81B758EB_6D10_11D7_9391_D6C3514BFA3D__INCLUDED_)
