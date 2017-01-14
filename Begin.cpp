/*--------------*/
/*魔方求解的入口*/
/*--------------*/
#include "StdAfx.h"
#define _FIRST_ 1
#include "All_Function.h"

bool help=false;
bool solve=false;
/*
bool choice()
{
	cout<<endl;
	cout<<"*******************************************"<<endl;
	cout<<"*               1-人工解决                *"<<endl;
	cout<<"*               2-电脑解决                *"<<endl;
	cout<<"*               3-退出                    *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<"请输入您的选择:";
	string c;
	cin>>c;
	if(c=="3")
	{
		help=true;
		solve=true;
	}
	while(c!="1"&&c!="2"&&c!="3")
	{	
		cout<<"输入错误!  请输入您的选择:";
		cin>>c;
	}
	if(c=="1")
	{
		help=false;
		change();
		cout<<"*******************************************"<<endl;
		cout<<"*  f+:正面顺时针操作 | f-:正面逆时针操作  *"<<endl;
		cout<<"*  b+:后面顺时针操作 | b-:后面逆时针操作  *"<<endl;
		cout<<"*  l+:左面顺时针操作 | l-:左面逆时针操作  *"<<endl;
		cout<<"*  r+:右面顺时针操作 | r-:右面逆时针操作  *"<<endl;
		cout<<"*  u+:上面顺时针操作 | u-:上面逆时针操作  *"<<endl;
		cout<<"*  d+:下面顺时针操作 | d-:下面逆时针操作  *"<<endl;
		cout<<"*  f-d:前面转换到底面| l-f:左面转换到前面 *"<<endl;
		cout<<"*******************************************"<<endl;
		cout<<endl;
		cout<<"需要帮助请按h! 不需要请输入旋转操作:";
		string s;
		cin>>s;
		while(help==false)
		{
			if(s=="h")
			{
				help=true;
				break;	
			}
			int i=0;
			if(s=="f+")i=1; if(s=="f-")i=2;
			if(s=="b+")i=3; if(s=="b-")i=4;
			if(s=="l+")i=5; if(s=="l-")i=6;
			if(s=="r+")i=7; if(s=="r-")i=8;
			if(s=="u+")i=9; if(s=="u-")i=10;
			if(s=="d+")i=11; if(s=="d-")i=12;
			if(s=="f-d")i=13;if(s=="l-f")i=14;
			cout<<endl;
			if(i==0)cout<<"输入有误!请重新输入!"<<endl;
			switch(i)
			{
			case 1:{ cout<<endl<<"前面顺时针旋转:"<<endl; front_1(); display_mf(); break; }
			case 2:{ cout<<endl<<"前面逆时针旋转:"<<endl; front_2(); display_mf(); break; }
			case 3:{ cout<<endl<<"后面顺时针旋转:"<<endl; back_1(); display_mf(); break; }
			case 4:{ cout<<endl<<"后面逆时针旋转:"<<endl; back_2(); display_mf(); break; }
			case 5:{ cout<<endl<<"左面顺时针旋转:"<<endl; left_1(); display_mf(); break; }
			case 6:{ cout<<endl<<"左面逆时针旋转:"<<endl; left_2(); display_mf(); break; }
			case 7:{ cout<<endl<<"右面顺时针旋转:"<<endl; right_1(); display_mf(); break; }
			case 8:{ cout<<endl<<"右面逆时针旋转:"<<endl; right_2(); display_mf(); break; }
			case 9:{ cout<<endl<<"上面顺时针旋转:"<<endl; up_1(); display_mf(); break; }
			case 10:{ cout<<endl<<"上面逆时针旋转:"<<endl; up_2(); display_mf(); break; }
			case 11:{ cout<<endl<<"下面顺时针旋转:"<<endl; down_1(); display_mf(); break; }
			case 12:{ cout<<endl<<"下面逆时针旋转:"<<endl; down_2(); display_mf(); break; }
			case 13:{cout<<endl<<"前面->下面->背面->上面->前面的转换操作:"<<endl;front_down();display_mf();break;}
			case 14:{cout<<endl<<"左面->前面->右面->后面->左面的转换操作:"<<endl;left_front();display_mf();break;}
			}

			solve=compara();
			if(solve==true)
			{	
				cout<<endl;
				cout<<"您求解魔方成功!"<<endl;
				help=true;
			}
			cout<<endl;
			if(solve==false)
			{
				cout<<"需要帮助请按h! 不需要请输入旋转操作:";
				cin>>s;
				if(s=="h")
				{
					help=true;
				}
			}
		}
	}
	else
		return true;
	if(help==true)return true;//?
	return false;
}
*/
void init_stage()
//让各面中心方块的颜色归一化
{
	if(graphsta[4][1]=='R') //red is on the left
	{
		left_front(); rc.push(14);
		left_front(); rc.push(14);
		left_front(); rc.push(14);
		front_down(); rc.push(13);
	}
	else if(graphsta[4][4]=='R') //red is on the front
	{
		front_down(); rc.push(13);
		front_down(); rc.push(13);
		front_down(); rc.push(13);
	}
	else if(graphsta[4][7]=='R') //red is on the right
	{
		left_front(); rc.push(14);
		front_down(); rc.push(13);
	}
	else if(graphsta[7][4]=='R') //red is on the down
	{
		front_down(); rc.push(13);
		front_down(); rc.push(13);
	}
	else if(graphsta[10][4]=='R') //red is on the back
	{
		front_down(); rc.push(13);
	}

	if(graphsta[4][1]=='Y') //yellow is on the left
	{
		left_front(); rc.push(14);
	}
	else if(graphsta[10][4]=='Y') //yellow is on the back
	{
		left_front(); rc.push(14);
		left_front(); rc.push(14);
	}
	else if(graphsta[4][7]=='Y') //yellow is on the right
	{
		left_front(); rc.push(14);
		left_front(); rc.push(14);
		left_front(); rc.push(14);
	}
}

bool solve_rubik()
{
	//保存当前状态
	for(int i=0;i<12;i++)
		for(int j=0;j<9;j++)
		{
			graphmf1[i][j] = graphsta[i][j];
			graphmf[i][j] = graphsta[i][j];
		}

	init_stage();	
	first_stage();
	second_stage();
	third_stage();
	forth_stage();
	fifth_stage();
	sixth_stage();
	seventh_stage();
	eighth_stage();
	//mission_compelet();
	return compara();
}