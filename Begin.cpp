/*--------------*/
/*ħ���������*/
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
	cout<<"*               1-�˹����                *"<<endl;
	cout<<"*               2-���Խ��                *"<<endl;
	cout<<"*               3-�˳�                    *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<"����������ѡ��:";
	string c;
	cin>>c;
	if(c=="3")
	{
		help=true;
		solve=true;
	}
	while(c!="1"&&c!="2"&&c!="3")
	{	
		cout<<"�������!  ����������ѡ��:";
		cin>>c;
	}
	if(c=="1")
	{
		help=false;
		change();
		cout<<"*******************************************"<<endl;
		cout<<"*  f+:����˳ʱ����� | f-:������ʱ�����  *"<<endl;
		cout<<"*  b+:����˳ʱ����� | b-:������ʱ�����  *"<<endl;
		cout<<"*  l+:����˳ʱ����� | l-:������ʱ�����  *"<<endl;
		cout<<"*  r+:����˳ʱ����� | r-:������ʱ�����  *"<<endl;
		cout<<"*  u+:����˳ʱ����� | u-:������ʱ�����  *"<<endl;
		cout<<"*  d+:����˳ʱ����� | d-:������ʱ�����  *"<<endl;
		cout<<"*  f-d:ǰ��ת��������| l-f:����ת����ǰ�� *"<<endl;
		cout<<"*******************************************"<<endl;
		cout<<endl;
		cout<<"��Ҫ�����밴h! ����Ҫ��������ת����:";
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
			if(i==0)cout<<"��������!����������!"<<endl;
			switch(i)
			{
			case 1:{ cout<<endl<<"ǰ��˳ʱ����ת:"<<endl; front_1(); display_mf(); break; }
			case 2:{ cout<<endl<<"ǰ����ʱ����ת:"<<endl; front_2(); display_mf(); break; }
			case 3:{ cout<<endl<<"����˳ʱ����ת:"<<endl; back_1(); display_mf(); break; }
			case 4:{ cout<<endl<<"������ʱ����ת:"<<endl; back_2(); display_mf(); break; }
			case 5:{ cout<<endl<<"����˳ʱ����ת:"<<endl; left_1(); display_mf(); break; }
			case 6:{ cout<<endl<<"������ʱ����ת:"<<endl; left_2(); display_mf(); break; }
			case 7:{ cout<<endl<<"����˳ʱ����ת:"<<endl; right_1(); display_mf(); break; }
			case 8:{ cout<<endl<<"������ʱ����ת:"<<endl; right_2(); display_mf(); break; }
			case 9:{ cout<<endl<<"����˳ʱ����ת:"<<endl; up_1(); display_mf(); break; }
			case 10:{ cout<<endl<<"������ʱ����ת:"<<endl; up_2(); display_mf(); break; }
			case 11:{ cout<<endl<<"����˳ʱ����ת:"<<endl; down_1(); display_mf(); break; }
			case 12:{ cout<<endl<<"������ʱ����ת:"<<endl; down_2(); display_mf(); break; }
			case 13:{cout<<endl<<"ǰ��->����->����->����->ǰ���ת������:"<<endl;front_down();display_mf();break;}
			case 14:{cout<<endl<<"����->ǰ��->����->����->�����ת������:"<<endl;left_front();display_mf();break;}
			}

			solve=compara();
			if(solve==true)
			{	
				cout<<endl;
				cout<<"�����ħ���ɹ�!"<<endl;
				help=true;
			}
			cout<<endl;
			if(solve==false)
			{
				cout<<"��Ҫ�����밴h! ����Ҫ��������ת����:";
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
//�ø������ķ������ɫ��һ��
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
	//���浱ǰ״̬
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