// GLView.cpp : implementation of the CGLView class
//

#include "stdafx.h"
#include "GL.h"

#include "GLDoc.h"
#include "GLView.h"
#include "EyeDlg.h"
#include <math.h>
#include "All_function.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void CGLView::MMM()
{
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, -10.0, -10.0);
	glVertex3f( 10.0, -10.0, -10.0);
	glVertex3f( 10.0, -10.0,  10.0);
	glVertex3f(-10.0, -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, 10.0,  10.0);
	glVertex3f( 10.0, 10.0,  10.0);
	glVertex3f( 10.0, 10.0, -10.0);
	glVertex3f(-10.0, 10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, -10.0, -10.0);
	glVertex3f(-10.0, -10.0,  10.0);
	glVertex3f(-10.0,  10.0,  10.0);
	glVertex3f(-10.0,  10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0,  10.0, -10.0);
	glVertex3f(10.0,  10.0,  10.0);
	glVertex3f(10.0, -10.0,  10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  -10.0,  10.0);
	glVertex3f( 10.0,  -10.0,  10.0);
	glVertex3f( 10.0,   10.0,  10.0);
	glVertex3f(-10.0,   10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,   10.0,  -10.0);
	glVertex3f( 10.0,   10.0,  -10.0);
	glVertex3f( 10.0,  -10.0,  -10.0);
	glVertex3f(-10.0,  -10.0,  -10.0);
	glEnd();
}

void CGLView::FLU()//-20,-20,+20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, -30.0,  10.0);
	glVertex3f(-10.0, -30.0,  10.0);
	glVertex3f(-10.0, -30.0,  30.0);
	glVertex3f(-30.0, -30.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, -10.0,  30.0);
	glVertex3f(-10.0, -10.0,  30.0);
	glVertex3f(-10.0, -10.0,  10.0);
	glVertex3f(-30.0, -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, -30.0,  10.0);
	glVertex3f(-30.0, -30.0,  30.0);
	glVertex3f(-30.0, -10.0,  30.0);
	glVertex3f(-30.0, -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0, -10.0,  10.0);
	glVertex3f(-10.0, -10.0,  30.0);
	glVertex3f(-10.0, -30.0,  30.0);
	glVertex3f(-10.0, -30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  -30.0,  30.0);
	glVertex3f(-10.0,  -30.0,  30.0);
	glVertex3f(-10.0,  -10.0,  30.0);
	glVertex3f(-30.0,  -10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,  -10.0,  10.0);
	glVertex3f(-10.0,  -10.0,  10.0);
	glVertex3f(-10.0,  -30.0,  10.0);
	glVertex3f(-30.0,  -30.0,  10.0);
	glEnd();

	SetGLColor(graphsta[3][3]);
	glBegin(GL_QUADS);//Front
	glVertex3f(-29.5, -31.0,  10.5);
	glVertex3f(-10.5, -31.0,  10.5);
	glVertex3f(-10.5, -31.0,  29.5);
	glVertex3f(-29.5, -31.0,  29.5);
	glEnd();
	SetGLColor(graphsta[3][2]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, -29.5,  10.5);
	glVertex3f(-30.5, -29.5,  29.5);
	glVertex3f(-30.5, -10.5,  29.5);
	glVertex3f(-30.5, -10.5,  10.5);
	glEnd();
	SetGLColor(graphsta[2][3]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(-29.5,  -29.5,  30.5);
	glVertex3f(-10.5,  -29.5,  30.5);
	glVertex3f(-10.5,  -10.5,  30.5);
	glVertex3f(-29.5,  -10.5,  30.5);
}

void CGLView::FMU()//0, -20, +20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, -30.0,  10.0);
	glVertex3f( 10.0, -30.0,  10.0);
	glVertex3f( 10.0, -30.0,  30.0);
	glVertex3f(-10.0, -30.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, -10.0, 30.0);
	glVertex3f( 10.0, -10.0, 30.0);
	glVertex3f( 10.0, -10.0, 10.0);
	glVertex3f(-10.0, -10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, -30.0, 10.0);
	glVertex3f(-10.0, -30.0, 30.0);
	glVertex3f(-10.0, -10.0, 30.0);
	glVertex3f(-10.0, -10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, 30.0);
	glVertex3f(10.0, -30.0, 30.0);
	glVertex3f(10.0, -30.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  -30.0,  30.0);
	glVertex3f( 10.0,  -30.0,  30.0);
	glVertex3f( 10.0,  -10.0,  30.0);
	glVertex3f(-10.0,  -10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,  -10.0,  10.0);
	glVertex3f( 10.0,  -10.0,  10.0);
	glVertex3f( 10.0,  -30.0,  10.0);
	glVertex3f(-10.0,  -30.0,  10.0);
	glEnd();

	SetGLColor(graphsta[3][4]);
	glBegin(GL_QUADS);//Front
	glVertex3f(-9.5, -30.5,  10.5);
	glVertex3f( 9.5, -30.5,  10.5);
	glVertex3f( 9.5, -30.5,  29.5);
	glVertex3f(-9.5, -30.5,  29.5);
	glEnd();
	SetGLColor(graphsta[2][4]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(-9.5,  -29.5,  30.5);
	glVertex3f( 9.5,  -29.5,  30.5);
	glVertex3f( 9.5,  -10.5,  30.5);
	glVertex3f(-9.5,  -10.5,  30.5);
	glEnd();
}

void CGLView::FRU()
{
	glColor3f(0.3f, 0.3f, 0.0f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, -30.0, 10.0);
	glVertex3f(30.0, -30.0, 10.0);
	glVertex3f(30.0, -30.0,  30.0);
	glVertex3f(10.0, -30.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, -10.0,  30.0);
	glVertex3f(30.0, -10.0,  30.0);
	glVertex3f(30.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, -30.0, 10.0);
	glVertex3f(10.0, -30.0,  30.0);
	glVertex3f(10.0,  -10.0,  30.0);
	glVertex3f(10.0,  -10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  -10.0, 10.0);
	glVertex3f(30.0,  -10.0,  30.0);
	glVertex3f(30.0, -30.0,  30.0);
	glVertex3f(30.0, -30.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  -30.0,  30.0);
	glVertex3f(30.0,  -30.0,  30.0);
	glVertex3f(30.0,   -10.0,  30.0);
	glVertex3f(10.0,   -10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   -10.0,  10.0);
	glVertex3f(30.0,   -10.0,  10.0);
	glVertex3f(30.0,  -30.0,  10.0);
	glVertex3f(10.0,  -30.0,  10.0);
	glEnd();

	SetGLColor(graphsta[3][5]);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.5, -30.5, 10.5);
	glVertex3f(29.5, -30.5, 10.5);
	glVertex3f(29.5, -30.5,  29.5);
	glVertex3f(10.5, -30.5,  29.5);
	glEnd();
	SetGLColor(graphsta[3][6]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, -10.5, 10.5);
	glVertex3f(30.5, -10.5,  29.5);
	glVertex3f(30.5, -29.5,  29.5);
	glVertex3f(30.5, -29.5, 10.5);
	glEnd();
	SetGLColor(graphsta[2][5]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.5,  -29.5,  30.5);
	glVertex3f(29.5,  -29.5,  30.5);
	glVertex3f(29.5,   -10.5,  30.5);
	glVertex3f(10.5,   -10.5,  30.5);
	glEnd();

}

void CGLView::FLM()//-20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.0f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, -30.0, -10.0);
	glVertex3f( -10.0, -30.0, -10.0);
	glVertex3f( -10.0, -30.0,  10.0);
	glVertex3f(-30.0, -30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, -10.0,  10.0);
	glVertex3f( -10.0, -10.0,  10.0);
	glVertex3f( -10.0, -10.0, -10.0);
	glVertex3f(-30.0, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, -30.0, -10.0);
	glVertex3f(-30.0, -30.0,  10.0);
	glVertex3f(-30.0,  -10.0,  10.0);
	glVertex3f(-30.0,  -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0,  -10.0, -10.0);
	glVertex3f(-10.0,  -10.0,  10.0);
	glVertex3f(-10.0, -30.0,  10.0);
	glVertex3f(-10.0, -30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  -30.0,  10.0);
	glVertex3f( -10.0,  -30.0,  10.0);
	glVertex3f( -10.0,   -10.0,  10.0);
	glVertex3f(-30.0,   -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,   -10.0,  -10.0);
	glVertex3f( -10.0,   -10.0,  -10.0);
	glVertex3f( -10.0,  -30.0,  -10.0);
	glVertex3f(-30.0,  -30.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[4][3]);
	glBegin(GL_QUADS);//Front
	glVertex3f(-29.5, -30.5, -9.5);
	glVertex3f(-10.5, -30.5, -9.5);
	glVertex3f(-10.5, -30.5,  9.5);
	glVertex3f(-29.5, -30.5,  9.5);
	glEnd();
	SetGLColor(graphsta[4][2]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, -29.5, -9.5);
	glVertex3f(-30.5, -29.5,  9.5);
	glVertex3f(-30.5, -10.5,  9.5);
	glVertex3f(-30.5, -10.5, -9.5);
	glEnd();
}

void CGLView::FMM()//0,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, -30.0, -10.0);
	glVertex3f( 10.0, -30.0, -10.0);
	glVertex3f( 10.0, -30.0,  10.0);
	glVertex3f(-10.0, -30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, -10.0,  10.0);
	glVertex3f( 10.0, -10.0,  10.0);
	glVertex3f( 10.0, -10.0, -10.0);
	glVertex3f(-10.0, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, -30.0, -10.0);
	glVertex3f(-10.0, -30.0,  10.0);
	glVertex3f(-10.0,  -10.0,  10.0);
	glVertex3f(-10.0,  -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0,  -10.0, -10.0);
	glVertex3f(10.0,  -10.0,  10.0);
	glVertex3f(10.0, -30.0,  10.0);
	glVertex3f(10.0, -30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  -30.0,  10.0);
	glVertex3f( 10.0,  -30.0,  10.0);
	glVertex3f( 10.0,   -10.0,  10.0);
	glVertex3f(-10.0,   -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,   -10.0,  -10.0);
	glVertex3f( 10.0,   -10.0,  -10.0);
	glVertex3f( 10.0,  -30.0,  -10.0);
	glVertex3f(-10.0,  -30.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[4][4]);
	glBegin(GL_QUADS);//Front
	glVertex3f(-9.5, -30.5, -9.5);
	glVertex3f( 9.5, -30.5, -9.5);
	glVertex3f( 9.5, -30.5,  9.5);
	glVertex3f(-9.5, -30.5,  9.5);
	glEnd();
}

void CGLView::FRM()//20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, -30.0, -10.0);
	glVertex3f( 30.0, -30.0, -10.0);
	glVertex3f( 30.0, -30.0,  10.0);
	glVertex3f(10.0, -30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, -10.0,  10.0);
	glVertex3f( 30.0, -10.0,  10.0);
	glVertex3f( 30.0, -10.0, -10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, -30.0, -10.0);
	glVertex3f(10.0, -30.0,  10.0);
	glVertex3f(10.0,  -10.0,  10.0);
	glVertex3f(10.0,  -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  -10.0, -10.0);
	glVertex3f(30.0,  -10.0,  10.0);
	glVertex3f(30.0, -30.0,  10.0);
	glVertex3f(30.0, -30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  -30.0,  10.0);
	glVertex3f( 30.0,  -30.0,  10.0);
	glVertex3f( 30.0,   -10.0,  10.0);
	glVertex3f(10.0,   -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   -10.0,  -10.0);
	glVertex3f( 30.0,   -10.0,  -10.0);
	glVertex3f( 30.0,  -30.0,  -10.0);
	glVertex3f(10.0,  -30.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[4][5]);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.5, -30.5, -9.5);
	glVertex3f(29.5, -30.5, -9.5);
	glVertex3f(29.5, -30.5,  9.5);
	glVertex3f(10.5, -30.5,  9.5);
	glEnd();
	SetGLColor(graphsta[4][6]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, -10.5, -9.5);
	glVertex3f(30.5, -10.5,  9.5);
	glVertex3f(30.5, -29.5,  9.5);
	glVertex3f(30.5, -29.5, -9.5);
	glEnd();

}

void CGLView::FLD()//-20,-20,-20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, -30.0, -30.0);
	glVertex3f( -10.0, -30.0, -30.0);
	glVertex3f( -10.0, -30.0,  -10.0);
	glVertex3f(-30.0, -30.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, -10.0,  -10.0);
	glVertex3f( -10.0, -10.0,  -10.0);
	glVertex3f( -10.0, -10.0, -30.0);
	glVertex3f(-30.0, -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, -30.0, -30.0);
	glVertex3f(-30.0, -30.0,  -10.0);
	glVertex3f(-30.0,  -10.0,  -10.0);
	glVertex3f(-30.0,  -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0,  -10.0, -30.0);
	glVertex3f(-10.0,  -10.0,  -10.0);
	glVertex3f(-10.0, -30.0,  -10.0);
	glVertex3f(-10.0, -30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  -30.0,  -10.0);
	glVertex3f( -10.0,  -30.0,  -10.0);
	glVertex3f( -10.0,   -10.0,  -10.0);
	glVertex3f(-30.0,   -10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,   -10.0,  -30.0);
	glVertex3f( -10.0,   -10.0,  -30.0);
	glVertex3f( -10.0,  -30.0,  -30.0);
	glVertex3f(-30.0,  -30.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[5][3]);
	glBegin(GL_QUADS);//Front
	glVertex3f(-29.5, -30.5, -29.5);
	glVertex3f(-10.5, -30.5, -29.5);
	glVertex3f(-10.5, -30.5, -10.5);
	glVertex3f(-29.5, -30.5, -10.5);
	glEnd();
	SetGLColor(graphsta[5][2]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, -29.5, -29.5);
	glVertex3f(-30.5, -29.5, -10.5);
	glVertex3f(-30.5, -10.5, -10.5);
	glVertex3f(-30.5, -10.5, -29.5);
	glEnd();
	SetGLColor(graphsta[6][3]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-29.5,  -10.5,  -30.5);
	glVertex3f(-10.5,  -10.5,  -30.5);
	glVertex3f(-10.5,  -29.5,  -30.5);
	glVertex3f(-29.5,  -29.5,  -30.5);
	glEnd();

}

void CGLView::FMD()//0,-20,-20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, -30.0, -30.0);
	glVertex3f( 10.0, -30.0, -30.0);
	glVertex3f( 10.0, -30.0,  -10.0);
	glVertex3f(-10.0, -30.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, -10.0,  -10.0);
	glVertex3f( 10.0, -10.0,  -10.0);
	glVertex3f( 10.0, -10.0, -30.0);
	glVertex3f(-10.0, -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, -30.0, -30.0);
	glVertex3f(-10.0, -30.0,  -10.0);
	glVertex3f(-10.0,  -10.0,  -10.0);
	glVertex3f(-10.0,  -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0,  -10.0, -30.0);
	glVertex3f(10.0,  -10.0,  -10.0);
	glVertex3f(10.0, -30.0,  -10.0);
	glVertex3f(10.0, -30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  -30.0,  -10.0);
	glVertex3f( 10.0,  -30.0,  -10.0);
	glVertex3f( 10.0,   -10.0,  -10.0);
	glVertex3f(-10.0,   -10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,   -10.0,  -30.0);
	glVertex3f( 10.0,   -10.0,  -30.0);
	glVertex3f( 10.0,  -30.0,  -30.0);
	glVertex3f(-10.0,  -30.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[5][4]);
	glBegin(GL_QUADS);//Front
	glVertex3f(-9.5, -30.5, -29.5);
	glVertex3f( 9.5, -30.5, -29.5);
	glVertex3f( 9.5, -30.5, -10.5);
	glVertex3f(-9.5, -30.5, -10.5);
	glEnd();
	SetGLColor(graphsta[6][4]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-9.5,  -10.5,  -30.5);
	glVertex3f( 9.5,  -10.5,  -30.5);
	glVertex3f( 9.5,  -29.5,  -30.5);
	glVertex3f(-9.5,  -29.5,  -30.5);
	glEnd();
}

void CGLView::FRD()//20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, -30.0, -30.0);
	glVertex3f( 30.0, -30.0, -30.0);
	glVertex3f( 30.0, -30.0,  -10.0);
	glVertex3f(10.0, -30.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, -10.0,  -10.0);
	glVertex3f( 30.0, -10.0,  -10.0);
	glVertex3f( 30.0, -10.0, -30.0);
	glVertex3f(10.0, -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, -30.0, -30.0);
	glVertex3f(10.0, -30.0,  -10.0);
	glVertex3f(10.0,  -10.0,  -10.0);
	glVertex3f(10.0,  -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  -10.0, -30.0);
	glVertex3f(30.0,  -10.0,  -10.0);
	glVertex3f(30.0, -30.0,  -10.0);
	glVertex3f(30.0, -30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  -30.0,  -10.0);
	glVertex3f( 30.0,  -30.0,  -10.0);
	glVertex3f( 30.0,   -10.0,  -10.0);
	glVertex3f(10.0,   -10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   -10.0,  -30.0);
	glVertex3f( 30.0,   -10.0,  -30.0);
	glVertex3f( 30.0,  -30.0,  -30.0);
	glVertex3f(10.0,  -30.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[5][5]);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.5, -30.5, -29.5);
	glVertex3f(29.5, -30.5, -29.5);
	glVertex3f(29.5, -30.5, -10.5);
	glVertex3f(10.5, -30.5, -10.5);
	glEnd();
	SetGLColor(graphsta[5][6]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, -10.5, -29.5);
	glVertex3f(30.5, -10.5, -10.5);
	glVertex3f(30.5, -29.5, -10.5);
	glVertex3f(30.5, -29.5, -29.5);
	glEnd();
	SetGLColor(graphsta[6][5]);
	glBegin(GL_QUADS);//Down
	glVertex3f(10.5,  -10.5,  -30.5);
	glVertex3f(29.5,  -10.5,  -30.5);
	glVertex3f(29.5,  -29.5,  -30.5);
	glVertex3f(10.5,  -29.5,  -30.5);
	glEnd();
}

//Middle layer
void CGLView::MLU()//-20,-20,+20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, -10.0,  10.0);
	glVertex3f(-10.0, -10.0,  10.0);
	glVertex3f(-10.0, -10.0,  30.0);
	glVertex3f(-30.0, -10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, 10.0,  30.0);
	glVertex3f(-10.0, 10.0,  30.0);
	glVertex3f(-10.0, 10.0,  10.0);
	glVertex3f(-30.0, 10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, -10.0,  10.0);
	glVertex3f(-30.0, -10.0,  30.0);
	glVertex3f(-30.0, 10.0,  30.0);
	glVertex3f(-30.0, 10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0, 10.0,  10.0);
	glVertex3f(-10.0, 10.0,  30.0);
	glVertex3f(-10.0, -10.0,  30.0);
	glVertex3f(-10.0, -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  -10.0,  30.0);
	glVertex3f(-10.0,  -10.0,  30.0);
	glVertex3f(-10.0,  10.0,  30.0);
	glVertex3f(-30.0,  10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,  10.0,  10.0);
	glVertex3f(-10.0,  10.0,  10.0);
	glVertex3f(-10.0,  -10.0,  10.0);
	glVertex3f(-30.0,  -10.0,  10.0);
	glEnd();

	SetGLColor(graphsta[3][1]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, -9.5,  10.5);
	glVertex3f(-30.5, -9.5,  29.5);
	glVertex3f(-30.5,  9.5,  29.5);
	glVertex3f(-30.5,  9.5,  10.5);
	glEnd();
	SetGLColor(graphsta[1][3]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(-29.5,  -9.5,  30.5);
	glVertex3f(-10.5,  -9.5,  30.5);
	glVertex3f(-10.5,   9.5,  30.5);
	glVertex3f(-29.5,   9.5,  30.5);
	glEnd();
}

void CGLView::MMU()//0, -20, +20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, -10.0,  10.0);
	glVertex3f( 10.0, -10.0,  10.0);
	glVertex3f( 10.0, -10.0,  30.0);
	glVertex3f(-10.0, -10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, 10.0, 30.0);
	glVertex3f( 10.0, 10.0, 30.0);
	glVertex3f( 10.0, 10.0, 10.0);
	glVertex3f(-10.0, 10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(-10.0, -10.0, 30.0);
	glVertex3f(-10.0, 10.0, 30.0);
	glVertex3f(-10.0, 10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0, 10.0, 10.0);
	glVertex3f(10.0, 10.0, 30.0);
	glVertex3f(10.0, -10.0, 30.0);
	glVertex3f(10.0, -10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  -10.0,  30.0);
	glVertex3f( 10.0,  -10.0,  30.0);
	glVertex3f( 10.0,  10.0,  30.0);
	glVertex3f(-10.0,  10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,  10.0,  10.0);
	glVertex3f( 10.0,  10.0,  10.0);
	glVertex3f( 10.0,  -10.0,  10.0);
	glVertex3f(-10.0,  -10.0,  10.0);
	glEnd();

	SetGLColor(graphsta[1][4]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(-9.5,  -9.5,  30.5);
	glVertex3f( 9.5,  -9.5,  30.5);
	glVertex3f( 9.5,   9.5,  30.5);
	glVertex3f(-9.5,   9.5,  30.5);
	glEnd();
}

void CGLView::MRU()
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(30.0, -10.0, 10.0);
	glVertex3f(30.0, -10.0,  30.0);
	glVertex3f(10.0, -10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, 10.0,  30.0);
	glVertex3f(30.0, 10.0,  30.0);
	glVertex3f(30.0, 10.0, 10.0);
	glVertex3f(10.0, 10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0,  30.0);
	glVertex3f(10.0,  10.0,  30.0);
	glVertex3f(10.0,  10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  10.0, 10.0);
	glVertex3f(30.0,  10.0,  30.0);
	glVertex3f(30.0, -10.0,  30.0);
	glVertex3f(30.0, -10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  -10.0,  30.0);
	glVertex3f(30.0,  -10.0,  30.0);
	glVertex3f(30.0,   10.0,  30.0);
	glVertex3f(10.0,   10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   10.0,  10.0);
	glVertex3f(30.0,   10.0,  10.0);
	glVertex3f(30.0,  -10.0,  10.0);
	glVertex3f(10.0,  -10.0,  10.0);
	glEnd();

	SetGLColor(graphsta[3][7]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5,  9.5, 10.5);
	glVertex3f(30.5,  9.5, 29.5);
	glVertex3f(30.5, -9.5, 29.5);
	glVertex3f(30.5, -9.5, 10.5);
	glEnd();
	SetGLColor(graphsta[1][5]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.5,  -9.5,  30.5);
	glVertex3f(29.5,  -9.5,  30.5);
	glVertex3f(29.5,   9.5,  30.5);
	glVertex3f(10.5,   9.5,  30.5);
	glEnd();
}

void CGLView::MLM()//-20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, -10.0, -10.0);
	glVertex3f( -10.0, -10.0, -10.0);
	glVertex3f( -10.0, -10.0,  10.0);
	glVertex3f(-30.0, -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, 10.0,  10.0);
	glVertex3f( -10.0, 10.0,  10.0);
	glVertex3f( -10.0, 10.0, -10.0);
	glVertex3f(-30.0, 10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, -10.0, -10.0);
	glVertex3f(-30.0, -10.0,  10.0);
	glVertex3f(-30.0,  10.0,  10.0);
	glVertex3f(-30.0,  10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0,  10.0, -10.0);
	glVertex3f(-10.0,  10.0,  10.0);
	glVertex3f(-10.0, -10.0,  10.0);
	glVertex3f(-10.0, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  -10.0,  10.0);
	glVertex3f( -10.0,  -10.0,  10.0);
	glVertex3f( -10.0,   10.0,  10.0);
	glVertex3f(-30.0,   10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,   10.0,  -10.0);
	glVertex3f( -10.0,  10.0,  -10.0);
	glVertex3f( -10.0,  -10.0,  -10.0);
	glVertex3f(-30.0,  -10.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[4][1]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, -9.5, -9.5);
	glVertex3f(-30.5, -9.5,  9.5);
	glVertex3f(-30.5,  9.5,  9.5);
	glVertex3f(-30.5,  9.5, -9.5);
	glEnd();

}

//void CGLView::MMM() //omitted

void CGLView::MRM()//20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, -10.0, -10.0);
	glVertex3f( 30.0, -10.0, -10.0);
	glVertex3f( 30.0, -10.0,  10.0);
	glVertex3f(10.0, -10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, 10.0,  10.0);
	glVertex3f( 30.0, 10.0,  10.0);
	glVertex3f( 30.0, 10.0, -10.0);
	glVertex3f(10.0, 10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, -10.0, -10.0);
	glVertex3f(10.0, -10.0,  10.0);
	glVertex3f(10.0,  10.0,  10.0);
	glVertex3f(10.0,  10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  10.0, -10.0);
	glVertex3f(30.0,  10.0,  10.0);
	glVertex3f(30.0, -10.0,  10.0);
	glVertex3f(30.0, -10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  -10.0,  10.0);
	glVertex3f( 30.0,  -10.0,  10.0);
	glVertex3f( 30.0,   10.0,  10.0);
	glVertex3f(10.0,   10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   10.0,  -10.0);
	glVertex3f( 30.0,  10.0,  -10.0);
	glVertex3f( 30.0,  -10.0,  -10.0);
	glVertex3f(10.0,  -10.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[4][7]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5,  9.5, -9.5);
	glVertex3f(30.5,  9.5,  9.5);
	glVertex3f(30.5, -9.5,  9.5);
	glVertex3f(30.5, -9.5, -9.5);
	glEnd();
}

void CGLView::MLD()//-20,-20,-20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, -10.0, -30.0);
	glVertex3f( -10.0, -10.0, -30.0);
	glVertex3f( -10.0, -10.0,  -10.0);
	glVertex3f(-30.0, -10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, 10.0,  -10.0);
	glVertex3f( -10.0, 10.0,  -10.0);
	glVertex3f( -10.0, 10.0, -30.0);
	glVertex3f(-30.0, 10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, -10.0, -30.0);
	glVertex3f(-30.0, -10.0,  -10.0);
	glVertex3f(-30.0,  10.0,  -10.0);
	glVertex3f(-30.0,  10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0,  10.0, -30.0);
	glVertex3f(-10.0,  10.0,  -10.0);
	glVertex3f(-10.0, -10.0,  -10.0);
	glVertex3f(-10.0, -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  -10.0,  -10.0);
	glVertex3f( -10.0,  -10.0,  -10.0);
	glVertex3f( -10.0,   10.0,  -10.0);
	glVertex3f(-30.0,   10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,   10.0,  -30.0);
	glVertex3f( -10.0,   10.0,  -30.0);
	glVertex3f( -10.0,  -10.0,  -30.0);
	glVertex3f(-30.0,  -10.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[5][1]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, -9.5, -29.5);
	glVertex3f(-30.5, -9.5, -10.5);
	glVertex3f(-30.5,  9.5, -10.5);
	glVertex3f(-30.5,  9.5, -29.5);
	glEnd();
	SetGLColor(graphsta[7][3]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-29.5,   9.5,  -30.5);
	glVertex3f(-10.5,   9.5,  -30.5);
	glVertex3f(-10.5,  -9.5,  -30.5);
	glVertex3f(-29.5,  -9.5,  -30.5);
	glEnd();
}

void CGLView::MMD()//0,-20,-20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, -10.0, -30.0);
	glVertex3f( 10.0, -10.0, -30.0);
	glVertex3f( 10.0, -10.0,  -10.0);
	glVertex3f(-10.0, -10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, 10.0,  -10.0);
	glVertex3f( 10.0, 10.0,  -10.0);
	glVertex3f( 10.0, 10.0, -30.0);
	glVertex3f(-10.0, 10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, -10.0, -30.0);
	glVertex3f(-10.0, -10.0,  -10.0);
	glVertex3f(-10.0,  10.0,  -10.0);
	glVertex3f(-10.0,  10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0,  10.0, -30.0);
	glVertex3f(10.0,  10.0,  -10.0);
	glVertex3f(10.0, -10.0,  -10.0);
	glVertex3f(10.0, -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  -10.0,  -10.0);
	glVertex3f( 10.0,  -10.0,  -10.0);
	glVertex3f( 10.0,   10.0,  -10.0);
	glVertex3f(-10.0,   10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,   10.0,  -30.0);
	glVertex3f( 10.0,   10.0,  -30.0);
	glVertex3f( 10.0,  -10.0,  -30.0);
	glVertex3f(-10.0,  -10.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[7][4]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-9.5,   9.5,  -30.5);
	glVertex3f( 9.5,   9.5,  -30.5);
	glVertex3f( 9.5,  -9.5,  -30.5);
	glVertex3f(-9.5,  -9.5,  -30.5);
	glEnd();

}

void CGLView::MRD()//20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, -10.0, -30.0);
	glVertex3f( 30.0, -10.0, -30.0);
	glVertex3f( 30.0, -10.0,  -10.0);
	glVertex3f(10.0, -10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, 10.0,  -10.0);
	glVertex3f( 30.0, 10.0,  -10.0);
	glVertex3f( 30.0, 10.0, -30.0);
	glVertex3f(10.0, 10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, -10.0, -30.0);
	glVertex3f(10.0, -10.0,  -10.0);
	glVertex3f(10.0,  10.0,  -10.0);
	glVertex3f(10.0,  10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  10.0, -30.0);
	glVertex3f(30.0,  10.0,  -10.0);
	glVertex3f(30.0, -10.0,  -10.0);
	glVertex3f(30.0, -10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  -10.0,  -10.0);
	glVertex3f( 30.0,  -10.0,  -10.0);
	glVertex3f( 30.0,   10.0,  -10.0);
	glVertex3f(10.0,   10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   10.0,  -30.0);
	glVertex3f( 30.0,   10.0,  -30.0);
	glVertex3f( 30.0,  -10.0,  -30.0);
	glVertex3f(10.0,  -10.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[5][7]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5,  9.5, -29.5);
	glVertex3f(30.5,  9.5, -10.5);
	glVertex3f(30.5, -9.5, -10.5);
	glVertex3f(30.5, -9.5, -29.5);
	glEnd();
	SetGLColor(graphsta[7][5]);
	glBegin(GL_QUADS);//Down
	glVertex3f(10.5,   9.5,  -30.5);
	glVertex3f(29.5,   9.5,  -30.5);
	glVertex3f(29.5,  -9.5,  -30.5);
	glVertex3f(10.5,  -9.5,  -30.5);
	glEnd();

}

//Back layer
void CGLView::BLU()//-20,-20,+20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, 10.0,  10.0);
	glVertex3f(-10.0, 10.0,  10.0);
	glVertex3f(-10.0, 10.0,  30.0);
	glVertex3f(-30.0, 10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, 30.0,  30.0);
	glVertex3f(-10.0, 30.0,  30.0);
	glVertex3f(-10.0, 30.0,  10.0);
	glVertex3f(-30.0, 30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, 10.0,  10.0);
	glVertex3f(-30.0, 10.0,  30.0);
	glVertex3f(-30.0, 30.0,  30.0);
	glVertex3f(-30.0, 30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0, 30.0,  10.0);
	glVertex3f(-10.0, 30.0,  30.0);
	glVertex3f(-10.0, 10.0,  30.0);
	glVertex3f(-10.0, 10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  10.0,  30.0);
	glVertex3f(-10.0,  10.0,  30.0);
	glVertex3f(-10.0,  30.0,  30.0);
	glVertex3f(-30.0,  30.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,  30.0,  10.0);
	glVertex3f(-10.0,  30.0,  10.0);
	glVertex3f(-10.0,  10.0,  10.0);
	glVertex3f(-30.0,  10.0,  10.0);
	glEnd();

	SetGLColor(graphsta[9][3]);	
	glBegin(GL_QUADS);//Back
	glVertex3f(-29.5, 30.5,  29.5);
	glVertex3f(-10.5, 30.5,  29.5);
	glVertex3f(-10.5, 30.5,  10.5);
	glVertex3f(-29.5, 30.5,  10.5);
	glEnd();
	SetGLColor(graphsta[3][0]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, 10.5,  10.5);
	glVertex3f(-30.5, 10.5,  29.5);
	glVertex3f(-30.5, 29.5,  29.5);
	glVertex3f(-30.5, 29.5,  10.5);
	glEnd();
	SetGLColor(graphsta[0][3]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(-29.5,  10.5,  30.5);
	glVertex3f(-10.5,  10.5,  30.5);
	glVertex3f(-10.5,  29.5,  30.5);
	glVertex3f(-29.5,  29.5,  30.5);
	glEnd();
}

void CGLView::BMU()//0, -20, +20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, 10.0,  10.0);
	glVertex3f( 10.0, 10.0,  10.0);
	glVertex3f( 10.0, 10.0,  30.0);
	glVertex3f(-10.0, 10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, 30.0, 30.0);
	glVertex3f( 10.0, 30.0, 30.0);
	glVertex3f( 10.0, 30.0, 10.0);
	glVertex3f(-10.0, 30.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, 10.0, 10.0);
	glVertex3f(-10.0, 10.0, 30.0);
	glVertex3f(-10.0, 30.0, 30.0);
	glVertex3f(-10.0, 30.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0, 30.0, 10.0);
	glVertex3f(10.0, 30.0, 30.0);
	glVertex3f(10.0, 10.0, 30.0);
	glVertex3f(10.0, 10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  10.0,  30.0);
	glVertex3f( 10.0,  10.0,  30.0);
	glVertex3f( 10.0,  30.0,  30.0);
	glVertex3f(-10.0,  30.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,  30.0,  10.0);
	glVertex3f( 10.0,  30.0,  10.0);
	glVertex3f( 10.0,  10.0,  10.0);
	glVertex3f(-10.0,  10.0,  10.0);
	glEnd();

	SetGLColor(graphsta[9][4]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-9.5, 30.5, 29.5);
	glVertex3f( 9.5, 30.5, 29.5);
	glVertex3f( 9.5, 30.5, 10.5);
	glVertex3f(-9.5, 30.5, 10.5);
	glEnd();
	SetGLColor(graphsta[0][4]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(-9.5,  10.5,  30.5);
	glVertex3f( 9.5,  10.5,  30.5);
	glVertex3f( 9.5,  29.5,  30.5);
	glVertex3f(-9.5,  29.5,  30.5);
	glEnd();
}

void CGLView::BRU()
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, 10.0, 10.0);
	glVertex3f(30.0, 10.0, 10.0);
	glVertex3f(30.0, 10.0,  30.0);
	glVertex3f(10.0, 10.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, 30.0,  30.0);
	glVertex3f(30.0, 30.0,  30.0);
	glVertex3f(30.0, 30.0, 10.0);
	glVertex3f(10.0, 30.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, 10.0, 10.0);
	glVertex3f(10.0, 10.0,  30.0);
	glVertex3f(10.0,  30.0,  30.0);
	glVertex3f(10.0,  30.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  30.0, 10.0);
	glVertex3f(30.0,  30.0,  30.0);
	glVertex3f(30.0, 10.0,  30.0);
	glVertex3f(30.0, 10.0, 10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  10.0,  30.0);
	glVertex3f(30.0,  10.0,  30.0);
	glVertex3f(30.0,   30.0,  30.0);
	glVertex3f(10.0,   30.0,  30.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   30.0,  10.0);
	glVertex3f(30.0,   30.0,  10.0);
	glVertex3f(30.0,  10.0,  10.0);
	glVertex3f(10.0,  10.0,  10.0);
	glEnd();

	SetGLColor(graphsta[9][5]);
	glBegin(GL_QUADS);//Back
	glVertex3f(10.5, 30.5, 29.5);
	glVertex3f(29.5, 30.5, 29.5);
	glVertex3f(29.5, 30.5, 10.5);
	glVertex3f(10.5, 30.5, 10.5);
	glEnd();
	SetGLColor(graphsta[3][8]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, 29.5, 10.5);
	glVertex3f(30.5, 29.5, 29.5);
	glVertex3f(30.5, 10.5, 29.5);
	glVertex3f(30.5, 10.5, 10.5);
	glEnd();
	SetGLColor(graphsta[0][5]);
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.5,  10.5,  30.5);
	glVertex3f(29.5,  10.5,  30.5);
	glVertex3f(29.5,  29.5,  30.5);
	glVertex3f(10.5,  29.5,  30.5);
	glEnd();
}

void CGLView::BLM()//-20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, 10.0, -10.0);
	glVertex3f( -10.0, 10.0, -10.0);
	glVertex3f( -10.0, 10.0,  10.0);
	glVertex3f(-30.0, 10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, 30.0,  10.0);
	glVertex3f( -10.0, 30.0,  10.0);
	glVertex3f( -10.0, 30.0, -10.0);
	glVertex3f(-30.0, 30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, 10.0, -10.0);
	glVertex3f(-30.0, 10.0,  10.0);
	glVertex3f(-30.0,  30.0,  10.0);
	glVertex3f(-30.0,  30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0,  30.0, -10.0);
	glVertex3f(-10.0,  30.0,  10.0);
	glVertex3f(-10.0, 10.0,  10.0);
	glVertex3f(-10.0, 10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  10.0,  10.0);
	glVertex3f( -10.0,  10.0,  10.0);
	glVertex3f( -10.0,   30.0,  10.0);
	glVertex3f(-30.0,   30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,   30.0,  -10.0);
	glVertex3f( -10.0,  30.0,  -10.0);
	glVertex3f( -10.0,  10.0,  -10.0);
	glVertex3f(-30.0,  10.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[10][3]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-29.5, 30.5,  9.5);
	glVertex3f(-10.5, 30.5,  9.5);
	glVertex3f(-10.5, 30.5, -9.5);
	glVertex3f(-29.5, 30.5, -9.5);
	glEnd();
	SetGLColor(graphsta[4][0]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, 10.5, -9.5);
	glVertex3f(-30.5, 10.5,  9.5);
	glVertex3f(-30.5, 29.5,  9.5);
	glVertex3f(-30.5, 29.5, -9.5);
	glEnd();
}

void CGLView::BMM() 
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, 10.0, -10.0);
	glVertex3f( 10.0, 10.0, -10.0);
	glVertex3f( 10.0, 10.0,  10.0);
	glVertex3f(-10.0, 10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, 30.0,  10.0);
	glVertex3f( 10.0, 30.0,  10.0);
	glVertex3f( 10.0, 30.0, -10.0);
	glVertex3f(-10.0, 30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, 10.0, -10.0);
	glVertex3f(-10.0, 10.0,  10.0);
	glVertex3f(-10.0,  30.0,  10.0);
	glVertex3f(-10.0,  30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0,  30.0, -10.0);
	glVertex3f(10.0,  30.0,  10.0);
	glVertex3f(10.0, 10.0,  10.0);
	glVertex3f(10.0, 10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  10.0,  10.0);
	glVertex3f( 10.0,  10.0,  10.0);
	glVertex3f( 10.0,   30.0,  10.0);
	glVertex3f(-10.0,   30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,   30.0,  -10.0);
	glVertex3f( 10.0,   30.0,  -10.0);
	glVertex3f( 10.0,  10.0,  -10.0);
	glVertex3f(-10.0,  10.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[10][4]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-9.5, 30.5,  9.5);
	glVertex3f( 9.5, 30.5,  9.5);
	glVertex3f( 9.5, 30.5, -9.5);
	glVertex3f(-9.5, 30.5, -9.5);
	glEnd();
}

void CGLView::BRM()//20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, 10.0, -10.0);
	glVertex3f( 30.0, 10.0, -10.0);
	glVertex3f( 30.0, 10.0,  10.0);
	glVertex3f(10.0, 10.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, 30.0,  10.0);
	glVertex3f( 30.0, 30.0,  10.0);
	glVertex3f( 30.0, 30.0, -10.0);
	glVertex3f(10.0, 30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, 10.0, -10.0);
	glVertex3f(10.0, 10.0,  10.0);
	glVertex3f(10.0,  30.0,  10.0);
	glVertex3f(10.0,  30.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  30.0, -10.0);
	glVertex3f(30.0,  30.0,  10.0);
	glVertex3f(30.0, 10.0,  10.0);
	glVertex3f(30.0, 10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  10.0,  10.0);
	glVertex3f( 30.0,  10.0,  10.0);
	glVertex3f( 30.0,   30.0,  10.0);
	glVertex3f(10.0,   30.0,  10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   30.0,  -10.0);
	glVertex3f( 30.0,  30.0,  -10.0);
	glVertex3f( 30.0,  10.0,  -10.0);
	glVertex3f(10.0,  10.0,  -10.0);
	glEnd();

	SetGLColor(graphsta[10][5]);
	glBegin(GL_QUADS);//Back
	glVertex3f(10.5, 30.5,  9.5);
	glVertex3f(29.5, 30.5,  9.5);
	glVertex3f(29.5, 30.5, -9.5);
	glVertex3f(10.5, 30.5, -9.5);
	glEnd();
	SetGLColor(graphsta[4][8]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, 29.5, -9.5);
	glVertex3f(30.5, 29.5,  9.5);
	glVertex3f(30.5, 10.5,  9.5);
	glVertex3f(30.5, 10.5, -9.5);
	glEnd();
}

void CGLView::BLD()//-20,-20,-20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-30.0, 10.0, -30.0);
	glVertex3f( -10.0, 10.0, -30.0);
	glVertex3f( -10.0, 10.0,  -10.0);
	glVertex3f(-30.0, 10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-30.0, 30.0,  -10.0);
	glVertex3f( -10.0, 30.0,  -10.0);
	glVertex3f( -10.0, 30.0, -30.0);
	glVertex3f(-30.0, 30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.0, 10.0, -30.0);
	glVertex3f(-30.0, 10.0,  -10.0);
	glVertex3f(-30.0,  30.0,  -10.0);
	glVertex3f(-30.0,  30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(-10.0,  30.0, -30.0);
	glVertex3f(-10.0,  30.0,  -10.0);
	glVertex3f(-10.0, 10.0,  -10.0);
	glVertex3f(-10.0, 10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-30.0,  10.0,  -10.0);
	glVertex3f( -10.0,  10.0,  -10.0);
	glVertex3f( -10.0,   30.0,  -10.0);
	glVertex3f(-30.0,   30.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-30.0,   30.0,  -30.0);
	glVertex3f( -10.0,   30.0,  -30.0);
	glVertex3f( -10.0,  10.0,  -30.0);
	glVertex3f(-30.0,  10.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[11][3]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-29.5, 30.5, -10.5);
	glVertex3f(-10.5, 30.5, -10.5);
	glVertex3f(-10.5, 30.5, -29.5);
	glVertex3f(-29.5, 30.5, -29.5);
	glEnd();
	SetGLColor(graphsta[5][0]);
	glBegin(GL_QUADS);//Left
	glVertex3f(-30.5, 10.5, -29.5);
	glVertex3f(-30.5, 10.5, -10.5);
	glVertex3f(-30.5, 29.5, -10.5);
	glVertex3f(-30.5, 29.5, -29.5);
	glEnd();
	SetGLColor(graphsta[8][3]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-29.5,  29.5,  -30.5);
	glVertex3f(-10.5,  29.5,  -30.5);
	glVertex3f(-10.5,  10.5,  -30.5);
	glVertex3f(-29.5,  10.5,  -30.5);
	glEnd();
}

void CGLView::BMD()//0,-20,-20
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(-10.0, 10.0, -30.0);
	glVertex3f( 10.0, 10.0, -30.0);
	glVertex3f( 10.0, 10.0, -10.0);
	glVertex3f(-10.0, 10.0, -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(-10.0, 30.0,  -10.0);
	glVertex3f( 10.0, 30.0,  -10.0);
	glVertex3f( 10.0, 30.0, -30.0);
	glVertex3f(-10.0, 30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(-10.0, 10.0, -30.0);
	glVertex3f(-10.0, 10.0,  -10.0);
	glVertex3f(-10.0,  30.0,  -10.0);
	glVertex3f(-10.0,  30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(10.0,  30.0, -30.0);
	glVertex3f(10.0,  30.0,  -10.0);
	glVertex3f(10.0, 10.0,  -10.0);
	glVertex3f(10.0, 10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(-10.0,  10.0,  -10.0);
	glVertex3f( 10.0,  10.0,  -10.0);
	glVertex3f( 10.0,   30.0,  -10.0);
	glVertex3f(-10.0,   30.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(-10.0,   30.0,  -30.0);
	glVertex3f( 10.0,   30.0,  -30.0);
	glVertex3f( 10.0,  10.0,  -30.0);
	glVertex3f(-10.0,  10.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[11][4]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-9.5, 30.5, -10.5);
	glVertex3f( 9.5, 30.5, -10.5);
	glVertex3f( 9.5, 30.5, -29.5);
	glVertex3f(-9.5, 30.5, -29.5);
	glEnd();
	SetGLColor(graphsta[8][4]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-9.5,  29.5,  -30.5);
	glVertex3f( 9.5,  29.5,  -30.5);
	glVertex3f( 9.5,  10.5,  -30.5);
	glVertex3f(-9.5,  10.5,  -30.5);
	glEnd();
}

void CGLView::BRD()//20,-20,0
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);//Front
	glVertex3f(10.0, 10.0, -30.0);
	glVertex3f( 30.0, 10.0, -30.0);
	glVertex3f( 30.0, 10.0,  -10.0);
	glVertex3f(10.0, 10.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Back
	glVertex3f(10.0, 30.0,  -10.0);
	glVertex3f( 30.0, 30.0,  -10.0);
	glVertex3f( 30.0, 30.0, -30.0);
	glVertex3f(10.0, 30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Left
	glVertex3f(10.0, 10.0, -30.0);
	glVertex3f(10.0, 10.0,  -10.0);
	glVertex3f(10.0,  30.0,  -10.0);
	glVertex3f(10.0,  30.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Right
	glVertex3f(30.0,  30.0, -30.0);
	glVertex3f(30.0,  30.0,  -10.0);
	glVertex3f(30.0, 10.0,  -10.0);
	glVertex3f(30.0, 10.0, -30.0);
	glEnd();
	glBegin(GL_QUADS);//Upper
	glVertex3f(10.0,  10.0,  -10.0);
	glVertex3f( 30.0,  10.0,  -10.0);
	glVertex3f( 30.0,   30.0,  -10.0);
	glVertex3f(10.0,   30.0,  -10.0);
	glEnd();
	glBegin(GL_QUADS);//Down
	glVertex3f(10.0,   30.0,  -30.0);
	glVertex3f( 30.0,   30.0,  -30.0);
	glVertex3f( 30.0,  10.0,  -30.0);
	glVertex3f(10.0,  10.0,  -30.0);
	glEnd();

	SetGLColor(graphsta[11][5]);
	glBegin(GL_QUADS);//Back
	glVertex3f(10.5, 30.5, -10.5);
	glVertex3f(29.5, 30.5, -10.5);
	glVertex3f(29.5, 30.5, -29.5);
	glVertex3f(10.5, 30.5, -29.5);
	glEnd();
	SetGLColor(graphsta[5][8]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, 29.5, -29.5);
	glVertex3f(30.5, 29.5, -10.5);
	glVertex3f(30.5, 10.5, -10.5);
	glVertex3f(30.5, 10.5, -29.5);
	glEnd();
	SetGLColor(graphsta[8][5]);
	glBegin(GL_QUADS);//Down
	glVertex3f(10.5,  29.5,  -30.5);
	glVertex3f(29.5,  29.5,  -30.5);
	glVertex3f(29.5,  10.5,  -30.5);
	glVertex3f(10.5,  10.5,  -30.5);
	glEnd();
}

void CGLView::HintBRD()
{
	glPushMatrix();
	glTranslatef(60.0f, 0.0f, 0.0f);
	glRotatef(90.0, 0.0, -1.0, 0.0);
	SetGLColor(graphsta[3][6]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, -10.5, 10.5);
	glVertex3f(30.5, -10.5,  29.5);
	glVertex3f(30.5, -29.5,  29.5);
	glVertex3f(30.5, -29.5, 10.5);
	glEnd();
	SetGLColor(graphsta[4][6]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, -10.5, -9.5);
	glVertex3f(30.5, -10.5,  9.5);
	glVertex3f(30.5, -29.5,  9.5);
	glVertex3f(30.5, -29.5, -9.5);
	glEnd();
	SetGLColor(graphsta[5][6]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, -10.5, -29.5);
	glVertex3f(30.5, -10.5, -10.5);
	glVertex3f(30.5, -29.5, -10.5);
	glVertex3f(30.5, -29.5, -29.5);
	glEnd();
	SetGLColor(graphsta[3][7]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5,  9.5, 10.5);
	glVertex3f(30.5,  9.5, 29.5);
	glVertex3f(30.5, -9.5, 29.5);
	glVertex3f(30.5, -9.5, 10.5);
	glEnd();
	SetGLColor(graphsta[4][7]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5,  9.5, -9.5);
	glVertex3f(30.5,  9.5,  9.5);
	glVertex3f(30.5, -9.5,  9.5);
	glVertex3f(30.5, -9.5, -9.5);
	glEnd();
	SetGLColor(graphsta[5][7]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5,  9.5, -29.5);
	glVertex3f(30.5,  9.5, -10.5);
	glVertex3f(30.5, -9.5, -10.5);
	glVertex3f(30.5, -9.5, -29.5);
	glEnd();
	SetGLColor(graphsta[3][8]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, 29.5, 10.5);
	glVertex3f(30.5, 29.5, 29.5);
	glVertex3f(30.5, 10.5, 29.5);
	glVertex3f(30.5, 10.5, 10.5);
	glEnd();
	SetGLColor(graphsta[4][8]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, 29.5, -9.5);
	glVertex3f(30.5, 29.5,  9.5);
	glVertex3f(30.5, 10.5,  9.5);
	glVertex3f(30.5, 10.5, -9.5);
	glEnd();
	SetGLColor(graphsta[5][8]);
	glBegin(GL_QUADS);//Right
	glVertex3f(30.5, 29.5, -29.5);
	glVertex3f(30.5, 29.5, -10.5);
	glVertex3f(30.5, 10.5, -10.5);
	glVertex3f(30.5, 10.5, -29.5);
	glEnd();
	
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -60.0f);
	glRotatef(90.0, -1.0, 0.0, 0.0);
	SetGLColor(graphsta[6][3]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-29.5,  -10.5,  -30.5);
	glVertex3f(-10.5,  -10.5,  -30.5);
	glVertex3f(-10.5,  -29.5,  -30.5);
	glVertex3f(-29.5,  -29.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[6][4]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-9.5,  -10.5,  -30.5);
	glVertex3f( 9.5,  -10.5,  -30.5);
	glVertex3f( 9.5,  -29.5,  -30.5);
	glVertex3f(-9.5,  -29.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[6][5]);
	glBegin(GL_QUADS);//Down
	glVertex3f(10.5,  -10.5,  -30.5);
	glVertex3f(29.5,  -10.5,  -30.5);
	glVertex3f(29.5,  -29.5,  -30.5);
	glVertex3f(10.5,  -29.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[7][3]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-29.5,   9.5,  -30.5);
	glVertex3f(-10.5,   9.5,  -30.5);
	glVertex3f(-10.5,  -9.5,  -30.5);
	glVertex3f(-29.5,  -9.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[7][4]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-9.5,   9.5,  -30.5);
	glVertex3f( 9.5,   9.5,  -30.5);
	glVertex3f( 9.5,  -9.5,  -30.5);
	glVertex3f(-9.5,  -9.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[7][5]);
	glBegin(GL_QUADS);//Down
	glVertex3f(10.5,   9.5,  -30.5);
	glVertex3f(29.5,   9.5,  -30.5);
	glVertex3f(29.5,  -9.5,  -30.5);
	glVertex3f(10.5,  -9.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[8][3]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-29.5,  29.5,  -30.5);
	glVertex3f(-10.5,  29.5,  -30.5);
	glVertex3f(-10.5,  10.5,  -30.5);
	glVertex3f(-29.5,  10.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[8][4]);
	glBegin(GL_QUADS);//Down
	glVertex3f(-9.5,  29.5,  -30.5);
	glVertex3f( 9.5,  29.5,  -30.5);
	glVertex3f( 9.5,  10.5,  -30.5);
	glVertex3f(-9.5,  10.5,  -30.5);
	glEnd();
	SetGLColor(graphsta[8][5]);
	glBegin(GL_QUADS);//Down
	glVertex3f(10.5,  29.5,  -30.5);
	glVertex3f(29.5,  29.5,  -30.5);
	glVertex3f(29.5,  10.5,  -30.5);
	glVertex3f(10.5,  10.5,  -30.5);
	glEnd();

	glPopMatrix();
	glTranslatef(0.0f, 60.0f, 0.0f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	SetGLColor(graphsta[9][3]);	
	glBegin(GL_QUADS);//Back
	glVertex3f(-29.5, 30.5,  29.5);
	glVertex3f(-10.5, 30.5,  29.5);
	glVertex3f(-10.5, 30.5,  10.5);
	glVertex3f(-29.5, 30.5,  10.5);
	glEnd();
	SetGLColor(graphsta[9][4]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-9.5, 30.5, 29.5);
	glVertex3f( 9.5, 30.5, 29.5);
	glVertex3f( 9.5, 30.5, 10.5);
	glVertex3f(-9.5, 30.5, 10.5);
	glEnd();
	SetGLColor(graphsta[9][5]);
	glBegin(GL_QUADS);//Back
	glVertex3f(10.5, 30.5, 29.5);
	glVertex3f(29.5, 30.5, 29.5);
	glVertex3f(29.5, 30.5, 10.5);
	glVertex3f(10.5, 30.5, 10.5);
	glEnd();
	SetGLColor(graphsta[10][3]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-29.5, 30.5,  9.5);
	glVertex3f(-10.5, 30.5,  9.5);
	glVertex3f(-10.5, 30.5, -9.5);
	glVertex3f(-29.5, 30.5, -9.5);
	glEnd();
	SetGLColor(graphsta[10][4]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-9.5, 30.5,  9.5);
	glVertex3f( 9.5, 30.5,  9.5);
	glVertex3f( 9.5, 30.5, -9.5);
	glVertex3f(-9.5, 30.5, -9.5);
	glEnd();
	SetGLColor(graphsta[10][5]);
	glBegin(GL_QUADS);//Back
	glVertex3f(10.5, 30.5,  9.5);
	glVertex3f(29.5, 30.5,  9.5);
	glVertex3f(29.5, 30.5, -9.5);
	glVertex3f(10.5, 30.5, -9.5);
	glEnd();
	SetGLColor(graphsta[11][3]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-29.5, 30.5, -10.5);
	glVertex3f(-10.5, 30.5, -10.5);
	glVertex3f(-10.5, 30.5, -29.5);
	glVertex3f(-29.5, 30.5, -29.5);
	glEnd();
	SetGLColor(graphsta[11][4]);
	glBegin(GL_QUADS);//Back
	glVertex3f(-9.5, 30.5, -10.5);
	glVertex3f( 9.5, 30.5, -10.5);
	glVertex3f( 9.5, 30.5, -29.5);
	glVertex3f(-9.5, 30.5, -29.5);
	glEnd();
	SetGLColor(graphsta[11][5]);
	glBegin(GL_QUADS);//Back
	glVertex3f(10.5, 30.5, -10.5);
	glVertex3f(29.5, 30.5, -10.5);
	glVertex3f(29.5, 30.5, -29.5);
	glVertex3f(10.5, 30.5, -29.5);
	glEnd();

}

