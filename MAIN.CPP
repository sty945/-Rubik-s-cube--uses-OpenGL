/*-------------------*/
/*    ħ�����ļ�     */
/*-------------------*/

#include"All_Function.h"
#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

//����ħ������,ȫ�ֱ���
char graphmf[12][9];	//�����ļ�������		
char graphsta[12][9];	//ʵ�ʲ���������
char graphmf1[12][9];	//������¼ħ����ʼ״̬������
queue<int> rc;			//�洢ħ�������Ĳ���
bool solve_1=false;
void (*p)();			//����ָ��,����ħ����ԭ��һ�׶ε�bfs��
/*ħ���ļ���������������,��Ӧ������,���밴��R,G,Y,B,O,W���˳������.*/
void main()
{
	string c;
	while(1)
	{
		search_begin();		//��⿪ʼ	
		cout<<"N/n �˳�,�����ִ����һ��ħ���ļ�"<<endl;
		cin>>c;
		if(c=="N"||c=="n")
			break;
	}

	/*�������û��ħ��,Ҳ����ͨ�������³��������������ת����,
	���õ����ҵ�ħ��,��Ȼ���������Ȳ�Ҫִ��.*/
	
	//getgraph();
	//makegraph();
	//change();
	
	/*front_1(),front_2(),down_1(),down_()
	  left_1(),left_2(),right_1(),right_2()
	  up_1(),up_2(),back_1(),back_2()*/
	
	//�������������
	//front_1();
	//up_1();
	//down_1();
	//left_2();
	
	//display_mf();
}