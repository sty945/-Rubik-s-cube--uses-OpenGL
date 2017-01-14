; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGLView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GL.h"
LastPage=0

ClassCount=6
Class1=CGLApp
Class2=CGLDoc
Class3=CGLView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDR_OPERATIONS
Class6=CEyeDlg
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOG1

[CLS:CGLApp]
Type=0
HeaderFile=GL.h
ImplementationFile=GL.cpp
Filter=N

[CLS:CGLDoc]
Type=0
HeaderFile=GLDoc.h
ImplementationFile=GLDoc.cpp
Filter=N

[CLS:CGLView]
Type=0
HeaderFile=GLView.h
ImplementationFile=GLView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_FILE_NEW


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=GL.cpp
ImplementationFile=GL.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_RANDOMCREATE
Command11=ID_SOLVE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_VIEW_EYE
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_BUTTON_CLOSER
Command10=ID_BUTTON_FARTHER
CommandCount=10

[DLG:IDD_DIALOG1]
Type=1
Class=CEyeDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_EDIT3,edit,1350631552
Control6=IDC_STATIC,static,1342308352

[CLS:CEyeDlg]
Type=0
HeaderFile=EyeDlg.h
ImplementationFile=EyeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[TB:IDR_OPERATIONS]
Type=1
Class=?
Command1=ID_FRONT_CW
Command2=ID_FRONT_CCW
Command3=ID_BACK_CW
Command4=ID_BACK_CCW
Command5=ID_LEFT_CW
Command6=ID_LEFT_CCW
Command7=ID_RIGHT_CW
Command8=ID_RIGHT_CCW
Command9=ID_UPPER_CW
Command10=ID_UPPER_CCW
Command11=ID_DOWN_CW
Command12=ID_DOWN_CCW
Command13=ID_WHOLE_FD
Command14=ID_WHOLE_LF
CommandCount=14

