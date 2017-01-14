// GLDoc.cpp : implementation of the CGLDoc class
//

#include "StdAfx.h"
#include "GL.h"
#include "GLDoc.h"
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "All_function.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGLDoc

IMPLEMENT_DYNCREATE(CGLDoc, CDocument)

BEGIN_MESSAGE_MAP(CGLDoc, CDocument)
	//{{AFX_MSG_MAP(CGLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLDoc construction/destruction

CGLDoc::CGLDoc()
{
	// TODO: add one-time construction code here
	initgraph();	
}

CGLDoc::~CGLDoc()
{
	
}

BOOL CGLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGLDoc serialization

void CGLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		char s[6][20];
		extractgraph(s);
/*
		CFile *file = ar.GetFile();
		CString path = file->GetFilePath();
		ofstream ostuf(path, ios::out);
		if(!ostuf)
		{
			return;
		}*/
		for(int i=0; i<6; i++)
		{
			for(int j=0; j<9; j++)
				ar<<s[i][j];
			char q = 13, r = 10;
			ar<<q<<r;
		}
	}
	else
	{
		// TODO: add loading code here
		char s[6][20];
		CFile *file = ar.GetFile();
		CString path = file->GetFilePath();
		ifstream instuf(path, ios::in);
		if(!instuf)
		{
			return;
		}
		instuf.getline(s[0],20);	//魔方上面数据			
		instuf.getline(s[1],20);	//魔方左面数据				
		instuf.getline(s[2],20);	//魔方前面数据			
		instuf.getline(s[3],20);	//魔方右面数据			
		instuf.getline(s[4],20);	//魔方下面数据			
		instuf.getline(s[5],20);	//魔方后面数据
		makegraph(s);
		AfxGetMainWnd()->Invalidate();
		AfxGetMainWnd()->UpdateWindow();
	}
}


/////////////////////////////////////////////////////////////////////////////
// CGLDoc diagnostics

#ifdef _DEBUG
void CGLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGLDoc commands
