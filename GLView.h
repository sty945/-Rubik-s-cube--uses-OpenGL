// GLView.h : interface of the CGLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLVIEW_H__81B758ED_6D10_11D7_9391_D6C3514BFA3D__INCLUDED_)
#define AFX_GLVIEW_H__81B758ED_6D10_11D7_9391_D6C3514BFA3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "gl\gl.h"
#include "gl\glu.h"
#include "gl\glaux.h"
#include "glut.h"

class CGLView : public CView
{
protected: // create from serialization only
	CGLView();
	DECLARE_DYNCREATE(CGLView)

// Attributes
public:
	CGLDoc* GetDocument();

// Operations
public:
	float m_scale, m_Eye[3];
	int   m_refresh;
	float m_angle;
	BOOL InitializeOpenGL();
	void SetGLColor(char c);
	void DrawCubes();
	void FLU(); //第一个字母为前后，第2个字母为左右，第3个为上下
	void FMU();
	void FRU();
	void FLM();
	void FMM();
	void FRM();
	void FLD();
	void FMD();
	void FRD();
	
	void MLU();
	void MMU();
	void MRU();
	void MLM();
	void MMM();
	void MRM();
	void MLD();
	void MMD();
	void MRD();

	void BLU();
	void BMU();
	void BRU();
	void BLM();
	void BMM();
	void BRM();
	void BLD();
	void BMD();
	void BRD();
	// To animate the operations
	void AnimateRotate();
	void FrontPos();
	void FrontNeg();
	void BackPos();
	void BackNeg();
	void LeftPos();
	void LeftNeg();
	void RightPos();
	void RightNeg();
	void UpperPos();
	void UpperNeg();
	void DownPos();
	void DownNeg();
	void WholeLF();
	void WholeFD();
	void HintBRD();
	void DemoSolution();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  //added for OpenGL
	HGLRC    m_hRC;
	CDC*     m_pDC;
    int m_WindowWidth;
    int m_WindowHeight;
	float m_AspectRatio;

// Generated message map functions
protected:
	//{{AFX_MSG(CGLView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnButtonCloser();
	afx_msg void OnButtonFarther();
	afx_msg void OnViewEye();
	afx_msg void OnFrontCw();
	afx_msg void OnFrontCcw();
	afx_msg void OnBackCw();
	afx_msg void OnBackCcw();
	afx_msg void OnLeftCw();
	afx_msg void OnLeftCcw();
	afx_msg void OnRightCw();
	afx_msg void OnRightCcw();
	afx_msg void OnUpperCw();
	afx_msg void OnUpperCcw();
	afx_msg void OnDownCw();
	afx_msg void OnDownCcw();
	afx_msg void OnWholeLf();
	afx_msg void OnWholeFd();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnRandomcreate();
	afx_msg void OnSolve();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GLView.cpp
inline CGLDoc* CGLView::GetDocument()
   { return (CGLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLVIEW_H__81B758ED_6D10_11D7_9391_D6C3514BFA3D__INCLUDED_)
