// GLView.cpp : implementation of the CGLView class
//

#include "stdafx.h"
#include "GL.h"

#include "GLDoc.h"
#include "GLView.h"
#include "EyeDlg.h"
#include <math.h>
#include <stdlib.h>
#include "All_function.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGLView

IMPLEMENT_DYNCREATE(CGLView, CView)

BEGIN_MESSAGE_MAP(CGLView, CView)
	//{{AFX_MSG_MAP(CGLView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_COMMAND(ID_BUTTON_CLOSER, OnButtonCloser)
	ON_COMMAND(ID_BUTTON_FARTHER, OnButtonFarther)
	ON_COMMAND(ID_VIEW_EYE, OnViewEye)
	ON_COMMAND(ID_FRONT_CW, OnFrontCw)
	ON_COMMAND(ID_FRONT_CCW, OnFrontCcw)
	ON_COMMAND(ID_BACK_CW, OnBackCw)
	ON_COMMAND(ID_BACK_CCW, OnBackCcw)
	ON_COMMAND(ID_LEFT_CW, OnLeftCw)
	ON_COMMAND(ID_LEFT_CCW, OnLeftCcw)
	ON_COMMAND(ID_RIGHT_CW, OnRightCw)
	ON_COMMAND(ID_RIGHT_CCW, OnRightCcw)
	ON_COMMAND(ID_UPPER_CW, OnUpperCw)
	ON_COMMAND(ID_UPPER_CCW, OnUpperCcw)
	ON_COMMAND(ID_DOWN_CW, OnDownCw)
	ON_COMMAND(ID_DOWN_CCW, OnDownCcw)
	ON_COMMAND(ID_WHOLE_LF, OnWholeLf)
	ON_COMMAND(ID_WHOLE_FD, OnWholeFd)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_RANDOMCREATE, OnRandomcreate)
	ON_COMMAND(ID_SOLVE, OnSolve)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLView construction/destruction

CGLView::CGLView()
{
	// TODO: add construction code here
	m_refresh = 0;
	m_angle = 0;
	m_scale = 5.0;
	m_Eye[0] = -70.0;
	m_Eye[1] = -120.0;
	m_Eye[2] = 70.0;
}


CGLView::~CGLView()
{
}

BOOL CGLView::PreCreateWindow(CREATESTRUCT& cs) //
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	
	// An OpenGL window must be created with the following
    // flags and must not include CS_PARENTDC for the
    // class style.

    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

    return CView::PreCreateWindow(cs);

}

/////////////////////////////////////////////////////////////////////////////
// CGLView drawing

void CGLView::OnDraw(CDC* pDC)
{
	CGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	wglMakeCurrent(pDC->m_hDC, m_hRC);
	glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
//设置视区
	RECT rect;
	this->GetClientRect(&rect);
	glViewport(0, 0, rect.right, rect.bottom);
//设置观察体	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-rect.right/m_scale, rect.right/m_scale, -rect.bottom/m_scale, rect.bottom/m_scale, 0, 1000);
//观察变换
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(m_Eye[0], m_Eye[1], m_Eye[2], 0.0, 0.0, 0.0, -m_Eye[0]*m_Eye[2], -m_Eye[1]*m_Eye[2], m_Eye[0]*m_Eye[0]+m_Eye[1]*m_Eye[1]);
//设置光源 此问题没必要

	
//设置景物的一些基本属性
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	//glShadeModel(GL_GOURAUD);

//景物描述
	switch(m_refresh)
	{
	case 0: DrawCubes(); break;
	case FRONT_POS: FrontPos(); break;
	case FRONT_NEG: FrontNeg(); break;
	case BACK_POS: BackPos(); break;
	case BACK_NEG: BackNeg(); break;
	case LEFT_POS: LeftPos(); break;
	case LEFT_NEG: LeftNeg(); break;
	case RIGHT_POS: RightPos(); break;
	case RIGHT_NEG: RightNeg(); break;
	case UPPER_POS: UpperPos(); break;
	case UPPER_NEG: UpperNeg(); break;
	case DOWN_POS: DownPos(); break;
	case DOWN_NEG: DownNeg(); break;
	case WHOLE_LF: WholeLF(); break;
	case WHOLE_FD: WholeFD(); break;
	case HINT_BRD: DrawCubes(); HintBRD(); break;
	}
	glFlush();
	::SwapBuffers(m_pDC->GetSafeHdc());		//交互缓冲区
}

/////////////////////////////////////////////////////////////////////////////
// CGLView printing

BOOL CGLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGLView diagnostics

#ifdef _DEBUG
void CGLView::AssertValid() const
{
	CView::AssertValid();
}

void CGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGLDoc* CGLView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLDoc)));
	return (CGLDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGLView message handlers

int CGLView::OnCreate(LPCREATESTRUCT lpCreateStruct) // 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	InitializeOpenGL();
	return 0;
}

void CGLView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here

    // this call makes the current RC not current
    if ( FALSE ==  ::wglMakeCurrent( 0, 0 ) )
        {
	       ::AfxMessageBox("wglMakeCurrent failed.");
        }

    // delete the RC
    if ( m_hRC && (FALSE == ::wglDeleteContext( m_hRC )) )
        {
	        ::AfxMessageBox("wglDeleteContext failed.");
        }

    // delete the DC
	
}

BOOL CGLView::OnEraseBkgnd(CDC* pDC) // 
{
	// TODO: Add your message handler code here and/or call default
	
	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}

void CGLView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
}

BOOL CGLView::InitializeOpenGL()
{
	PIXELFORMATDESCRIPTOR pfd=
	{
		sizeof(PIXELFORMATDESCRIPTOR),1,
        PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,24,
		0,0,0,0,0,0,
		0,0,0,0,0,0,0,32,
		0,0,
		PFD_MAIN_PLANE,
		0,0,0,0
	}; 
	m_pDC = new CClientDC(this);
	int pixelFormat=ChoosePixelFormat(m_pDC->GetSafeHdc(),&pfd);
	BOOL sucess=SetPixelFormat(m_pDC->GetSafeHdc(),pixelFormat,&pfd);
	m_hRC=wglCreateContext(m_pDC->GetSafeHdc());
	
    return TRUE;
}

void CGLView::OnButtonCloser() 
{
	// TODO: Add your command handler code here
	m_scale *= 1.25f;
	InvalidateRect(NULL);
	UpdateWindow();
}

void CGLView::OnButtonFarther() 
{
	// TODO: Add your command handler code here
	m_scale *= 0.8f;
	InvalidateRect(NULL);
	UpdateWindow();
}

void CGLView::OnViewEye() 
{
	// TODO: Add your command handler code here
	//CEyeDlg eyeDlg;
	//eyeDlg.DoModal();	
}

void CGLView::SetGLColor(char c)
{
	switch(c)
	{
	case 'R': glColor3f(1.0, 0.0, 0.0); break;
	case 'G': glColor3f(0.0, 1.0, 0.0); break;
	case 'Y': glColor3f(1.0, 1.0, 0.0); break;
	case 'B': glColor3f(0.0, 0.0, 1.0); break;
	case 'O': glColor3f(1.0, 0.0, 1.0); break;
	case 'W': glColor3f(1.0, 1.0, 1.0); break;
	}
}

void CGLView::DrawCubes()
{
	FLU(); 	FMU();	FRU();	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
	MLU();	MMU();	MRU();	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	BLU();	BMU();	BRU();	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
}

void CGLView::FrontPos()
{
	MLU();	MMU();	MRU();	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	BLU();	BMU();	BRU();	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
	glRotatef(m_angle, 0.0, -1.0, 0.0);
	FLU(); 	FMU();	FRU();	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
}

void CGLView::FrontNeg()
{
	MLU();	MMU();	MRU();	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	BLU();	BMU();	BRU();	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
	glRotatef(m_angle, 0.0, 1.0, 0.0);
	FLU(); 	FMU();	FRU();	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
}

void CGLView::BackPos()
{
	FLU(); 	FMU();	FRU();	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
	MLU();	MMU();	MRU();	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	glRotatef(m_angle, 0.0, -1.0, 0.0);	
	BLU();	BMU();	BRU();	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
}

void CGLView::BackNeg()
{
	FLU(); 	FMU();	FRU();	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
	MLU();	MMU();	MRU();	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	glRotatef(m_angle, 0.0, 1.0, 0.0);
	BLU();	BMU();	BRU();	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
}

void CGLView::LeftPos()
{
	FMU();	FRU();	FMM();	FRM();	FMD();	FRD();
	MMU();	MRU();	        MRM();	MMD();	MRD();
	BMU();	BRU();	BMM();	BRM();	BMD();	BRD();
	glRotatef(m_angle, -1.0, 0.0, 0.0);	
	FLU(); 	MLU();	BLU();	FLM();	MLM();  BLM();	FLD();	MLD();	BLD();	
}

void CGLView::LeftNeg()
{
	FMU();	FRU();	FMM();	FRM();	FMD();	FRD();
	MMU();	MRU();	        MRM();	MMD();	MRD();
	BMU();	BRU();	BMM();	BRM();	BMD();	BRD();
	glRotatef(m_angle, 1.0, 0.0, 0.0);	
	FLU(); 	MLU();	BLU();	FLM();	MLM();  BLM();	FLD();	MLD();	BLD();	
}

void CGLView::RightPos()
{
	FMU();	FLU();	FMM();	FLM();	FMD();	FLD();
	MMU();	MLU();	        MLM();	MMD();	MLD();
	BMU();	BLU();	BMM();	BLM();	BMD();	BLD();
	glRotatef(m_angle, -1.0, 0.0, 0.0);	
	FRU(); 	MRU();	BRU();	FRM();	MRM();  BRM();	FRD();	MRD();	BRD();	
}

void CGLView::RightNeg()
{
	FMU();	FLU();	FMM();	FLM();	FMD();	FLD();
	MMU();	MLU();	        MLM();	MMD();	MLD();
	BMU();	BLU();	BMM();	BLM();	BMD();	BLD();
	glRotatef(m_angle, 1.0, 0.0, 0.0);	
	FRU(); 	MRU();	BRU();	FRM();	MRM();  BRM();	FRD();	MRD();	BRD();	
}

void CGLView::UpperPos()
{
	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
	glRotatef(m_angle, 0.0, 0.0, 1.0);
	FLU(); 	FMU();	FRU();	MLU();	MMU();	MRU();	BLU();	BMU();	BRU();	
}

void CGLView::UpperNeg()
{
	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
	glRotatef(m_angle, 0.0, 0.0, -1.0);
	FLU(); 	FMU();	FRU();	MLU();	MMU();	MRU();	BLU();	BMU();	BRU();	
}

void CGLView::DownPos()
{
	FLM();	FMM();	FRM();	FLU();	FMU();	FRU();
	MLM();/*MMM();*/MRM();	MLU();	MMU();	MRU();
	BLM();	BMM();	BRM();	BLU();	BMU();	BRU();
	glRotatef(m_angle, 0.0, 0.0, 1.0);
	FLD(); 	FMD();	FRD();	MLD();	MMD();	MRD();	BLD();	BMD();	BRD();	
}

void CGLView::DownNeg()
{
	FLM();	FMM();	FRM();	FLU();	FMU();	FRU();
	MLM();/*MMM();*/MRM();	MLU();	MMU();	MRU();
	BLM();	BMM();	BRM();	BLU();	BMU();	BRU();
	glRotatef(m_angle, 0.0, 0.0, -1.0);
	FLD(); 	FMD();	FRD();	MLD();	MMD();	MRD();	BLD();	BMD();	BRD();	
}

void CGLView::WholeLF()
{
	glRotatef(m_angle, 0.0, 0.0, 1.0);
	FLU(); 	FMU();	FRU();	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
	MLU();	MMU();	MRU();	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	BLU();	BMU();	BRU();	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
}

void CGLView::WholeFD()
{
	glRotatef(m_angle, 1.0, 0.0, 0.0);
	FLU(); 	FMU();	FRU();	FLM();	FMM();	FRM();	FLD();	FMD();	FRD();
	MLU();	MMU();	MRU();	MLM();/*MMM();*/MRM();	MLD();	MMD();	MRD();
	BLU();	BMU();	BRU();	BLM();	BMM();	BRM();	BLD();	BMD();	BRD();
}

void CGLView::AnimateRotate()
{
	m_angle = 0.0;
	for(int i=0; i<9; i++)
	{
		m_angle += 10.0;
		Invalidate(FALSE);
		UpdateWindow();
		for(int j=0; j<20000000; j++);
	}
}

void CGLView::OnFrontCw() 
{
	// TODO: Add your command handler code here
	m_refresh = FRONT_POS;
	AnimateRotate();
	m_refresh = 0;
	front_2();
}

void CGLView::OnFrontCcw() 
{
	// TODO: Add your command handler code here
	m_refresh = FRONT_NEG;
	AnimateRotate();
	m_refresh = 0;
	front_1();
}

void CGLView::OnBackCw() 
{
	// TODO: Add your command handler code here
	m_refresh = BACK_POS;
	AnimateRotate();
	m_refresh = 0;
	back_1();
}

void CGLView::OnBackCcw() 
{
	// TODO: Add your command handler code here
	m_refresh = BACK_NEG;
	AnimateRotate();
	m_refresh = 0;
	back_2();
}

void CGLView::OnLeftCw() 
{
	// TODO: Add your command handler code here
	m_refresh = LEFT_POS;
	AnimateRotate();
	m_refresh = 0;
	left_2();
}

void CGLView::OnLeftCcw() 
{
	// TODO: Add your command handler code here
	m_refresh = LEFT_NEG;
	AnimateRotate();
	m_refresh = 0;
	left_1();
}

void CGLView::OnRightCw() 
{
	// TODO: Add your command handler code here
	m_refresh = RIGHT_POS;
	AnimateRotate();
	m_refresh = 0;
	right_1();
}

void CGLView::OnRightCcw() 
{
	// TODO: Add your command handler code here
	m_refresh = RIGHT_NEG;
	AnimateRotate();
	m_refresh = 0;
	right_2();
}

void CGLView::OnUpperCw() 
{
	// TODO: Add your command handler code here
	m_refresh = UPPER_POS;
	AnimateRotate();
	m_refresh = 0;
	up_2();
}

void CGLView::OnUpperCcw() 
{
	// TODO: Add your command handler code here
	m_refresh = UPPER_NEG;
	AnimateRotate();
	m_refresh = 0;
	up_1();
}

void CGLView::OnDownCw() 
{
	// TODO: Add your command handler code here
	m_refresh = DOWN_POS;
	AnimateRotate();
	m_refresh = 0;
	down_1();
}

void CGLView::OnDownCcw() 
{
	// TODO: Add your command handler code here
	m_refresh = DOWN_NEG;
	AnimateRotate();
	m_refresh = 0;
	down_2();
}

void CGLView::OnWholeLf() 
{
	// TODO: Add your command handler code here
	m_refresh = WHOLE_LF;
	AnimateRotate();
	m_refresh = 0;
	left_front();
}

void CGLView::OnWholeFd() 
{
	// TODO: Add your command handler code here
	m_refresh = WHOLE_FD;
	AnimateRotate();
	m_refresh = 0;
	front_down();
}

void CGLView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_refresh = HINT_BRD;
	Invalidate(FALSE);
	UpdateWindow();
	m_refresh = 0;
	//CView::OnLButtonDown(nFlags, point);
}

void CGLView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(FALSE);
	UpdateWindow();
	//CView::OnLButtonUp(nFlags, point);
}

BOOL CGLView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	HCURSOR hCur = AfxGetApp()->LoadCursor(IDC_HELP1);
	SetCursor(hCur);
	return TRUE; //CView::OnSetCursor(pWnd, nHitTest, message);
}

void CGLView::OnRandomcreate() 
{
	// TODO: Add your command handler code here
	srand(time(NULL));
	for(int i=0; i<20; i++)
	{
		int num = rand()%14+1;
		switch(num)
		{
		case FRONT_POS: OnFrontCw(); break;
		case FRONT_NEG: OnFrontCcw(); break;
		case BACK_POS: OnBackCw(); break;
		case BACK_NEG: OnBackCcw(); break;
		case LEFT_POS: OnLeftCw(); break;
		case LEFT_NEG: OnLeftCcw(); break;
		case RIGHT_POS: OnRightCw(); break;
		case RIGHT_NEG: OnRightCcw(); break;
		case UPPER_POS: OnUpperCw(); break;
		case UPPER_NEG: OnUpperCcw(); break;
		case DOWN_POS: OnDownCw(); break;
		case DOWN_NEG: OnDownCcw(); break;
		case WHOLE_LF: OnWholeLf(); break;
		case WHOLE_FD: OnWholeFd(); break;
		}
	}
}

void CGLView::OnSolve() 
{
	// TODO: Add your command handler code here
	if(solve_rubik()==true)
	{
		char text[100];
		sprintf(text, "由当前状态到目标状态共需%d步，按OK开始演示。", rc.size());
		if(IDOK==MessageBox(text, "魔方自动求解", MB_OK))
			DemoSolution();
		else
			change();
	}
	else
	{
		MessageBox("当前状态求解失败，换一个状态再试！", "魔方自动求解", MB_OK);
		change();
	}
}

//改自原来的mission_complet()
void CGLView::DemoSolution() 
{
	
	int count=0;			//计算执行到第几步

	//转换到要求解的魔方状态
	for(int i=0;i<12;i++)
		for(int j=0;j<9;j++)
			graphsta[i][j]=graphmf1[i][j];

	while(rc.size()!=0)		
	{
		count++;
		int i=rc.front();	//取出旋转操作							
		switch(i)
		{
			case 1: OnFrontCcw(); break;
			case 2: OnFrontCw(); break;
			case 3: OnBackCw(); break;
			case 4: OnBackCcw(); break;
			case 5: OnLeftCcw(); break;
			case 6: OnLeftCw(); break;
			case 7: OnRightCw(); break;
			case 8: OnRightCcw(); break;
			case 9: OnUpperCcw(); break;
			case 10: OnUpperCw(); break;
			case 11: OnDownCw(); break;
			case 12: OnDownCcw(); break;
			case 13: OnWholeFd(); break;
			case 14: OnWholeLf(); break;
		}
		i=0;
		rc.pop();
	}
}

void CGLView::OnFileNew() 
{
	// TODO: Add your command handler code here
	initgraph();
	Invalidate();
	UpdateWindow();
}
