/*-------------------*/
/*  ħ�����ͷ�ļ�   */
/*-------------------*/
#include "StdAfx.h"
#include"All_Function.h"
#include<iostream>
#include <conio.h>

/*----------------*/
/*�洢��չ��ת����*/
/*----------------*/

struct nodec
{
	int v;
	nodec *parent;	//����ָ�򸸽��								
	nodec *next;	//����ָ����չ���								
	
	//�����ľ���ָ��
	nodec *l_1;	nodec *l_2;	nodec *r_1;	nodec *r_2;
	nodec *u_1;	nodec *u_2;	nodec *d_1;	nodec *d_2;
	nodec *f_1;	nodec *f_2;	nodec *b_1;	nodec *b_2;
};

/*----------------*/
/*��������Ҫ�ı���*/
/*----------------*/

nodec *tree;		//ָ���������
nodec *here;		//ָ����Ҫ��չ�Ľ��
nodec *nextnode;	//ָ��ǰ���	
nodec *newnode;		//ָ���½��
queue<int> re;		//�洢��ת���У���֦
stack<int> rb;		//�ָ���ǰ���״̬
int solve=0;		//�����ж�ħ������Ƿ�ɹ�										
/*------------------*/
/*�ж�ħ���Ƿ񱻽��*/
/*------------------*/							

bool compara()
{
	int i,j;
	char s;
	for(i=0;i<12;i++)
		for(j=0;j<9;j++)
		{
			//ħ�������׼״̬
			s=graphsta[7][4];
			if((i>=6&&i<9)&&(j>=3&&j<6))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//ħ�������׼״̬
			s=graphsta[1][4];
			if((i>=0&&i<3)&&(j>2&&j<6))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//ħ�������׼״̬
			s=graphsta[10][4];
			if((i>=9&&i<12)&&(j>=3&&j<9))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//ħ�������׼״̬
			s=graphsta[4][1];
			if(i>2&&(j>=0&&j<3))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//ħ��ǰ���׼״̬
			s=graphsta[4][4];
			if(i>2&&(j>2&&j<6))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//ħ�������׼״̬
			s=graphsta[4][7];
			if(i>2&&(j>5&&j<9))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
		}	
	//ħ�������	
	if(solve==54)return true;					
	//ħ��û�б����
	else
	{	
		solve=0;
		return false;							
	}
}

/*----------------------------------*/
/*��Ҫ����ħ��״̬������ת��������*/
/*----------------------------------*/

void change() 
{
	int i,j;
	for(i=0;i<12;i++)
		for(j=0;j<9;j++)
			graphsta[i][j]=graphmf[i][j];
}


/*------------------------------*/
/*�ҵ���ǰҪ��չ�Ľ�����ת����*/
/*------------------------------*/

void reback()
{
	nodec *p;
	p=here;
	while(p->v!=0)
	{
		rb.push(p->v);
		p=p->parent;
	}
}
/*----------------*/
/*ħ���ҵ���Ĺ���*/
/*----------------*/
void bfs_solve()
{
	int i;
	nodec *p;
	p=nextnode;
	while(p->v!=0)
	{
		rb.push(p->v);
		p=p->parent;
	}
	while(rb.size()!=0)
	{
		i=rb.top();
		rc.push(i);			//��������
		rb.pop();
	}
}

/*---------------------------------------------------------*/
/*����չ����ת����ת���ɾ������ת����,�õ�ħ����ǰ��״̬ͼ*/
/*---------------------------------------------------------*/

void node_operation()
{
	int i;
	while(rb.size()!=0)
	{
		i=rb.top();
		switch(i)
		{
			case 1:{front_1();break;}
			case 2:{front_2();break;}
			case 3:{back_1();break;}
			case 4:{back_2();break;}
			case 5:{left_1();break;}
			case 6:{left_2();break;}
			case 7:{right_1();break;}
			case 8:{right_2();break;}
			case 9:{up_1();break;}
			case 10:{up_2();break;}
			case 11:{down_1();break;}
			case 12:{down_2();break;}
		}
		rb.pop();
	}
}


/*----------------*/
/*��ӡħ��������*/
/*----------------*/
//void mission_compelet() moved to GLView.cpp

/*--------*/
/*ħ�����*/
/*--------*/

void bfs_mf()
{
	//cout<<"1";
	int i=0;
	//��֦���
	int re_check=0,re_check1=1;					
	//���������
	tree=new nodec;								
	tree->v=0;
	tree->parent=NULL;
	here=tree;
	nextnode=tree;
	//ת����Ҫ����ħ��״̬									
	(*p)();		//��ʼʱ��ΪҪ��״̬
	while(solve_1==false)
	{
		/*ǰ��˳ʱ����ת��չ-1*/
		
		//����չ�ϴ���ת�������
		if(re_check!=2)							
		{
			front_1();
			(*p)();
			if(solve_1==true)
			{	
				
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;	
				newnode->v=1;			//��ת��ʽ							
				newnode->parent=here;	//ָ�򸸽��							
				here->f_1=newnode;		//�����ǰ��˳ʱ��ָ��ָ���½��					
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;				
				break;
			}
			else
			{	
				
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;				
				newnode->v=1;			//��ת��ʽ						
				newnode->parent=here;	//ָ�򸸽��							
				here->f_1=newnode;		//�����ǰ��˳ʱ��ָ��ָ���½��							
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;					
				front_2();				//�ָ�����չǰ��״̬	
				re.push(1);				//��֦����
			}
		}
		
		/*ǰ����ʱ����ת��չ-2*/
		
		//����չ�ϴ���ת�������
		if(re_check!=1)							
		{
			front_2();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;			
				newnode->v=2;			//��ת��ʽ					
				newnode->parent=here;	//ָ�򸸽��						
				here->f_2=newnode;		//�����ǰ����ʱ��ָ��ָ���½��						
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;			
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��			
				newnode->next=NULL;			
				newnode->v=2;			//��ת��ʽ					
				newnode->parent=here;	//ָ�򸸽��				
				here->f_2=newnode;		//�����ǰ����ʱ��ָ��ָ���½��					
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;			
				front_1();				//�ָ�����չǰ��״̬
				re.push(2);				//��֦����
			}
		}
		
		/*����˳ʱ����ת��չ-3*/
		
		//����չ�ϴ���ת�������
		if(re_check!=4)							
		{
			back_1();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//�����½��			
				newnode->next=NULL;		
				newnode->v=3;			//��ת��ʽ				
				newnode->parent=here;	//ָ�򸸽��				
				here->b_1=newnode;		//��������˳ʱ��ָ��ָ���½��					
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;			
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��	
				newnode->next=NULL;						
				newnode->v=3;			//��ת��ʽ					
				newnode->parent=here;	//ָ�򸸽��				
				here->b_1=newnode;		//��������˳ʱ��ָ��ָ���½��			
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;				
				back_2();				//�ָ�����չǰ��״̬	
				re.push(3);				//��֦����
			}
		}

		/*������ʱ����ת��չ-4*/
		
		//����չ�ϴ���ת�������
		if(re_check!=3)							
		{
			back_2();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;				
				newnode->v=4;			//��ת��ʽ					
				newnode->parent=here;	//ָ�򸸽��					
				here->b_2=newnode;		//����������ʱ��ָ��ָ���½��					
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;				
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;			
				newnode->v=4;			//��ת��ʽ						
				newnode->parent=here;	//ָ�򸸽��						
				here->b_2=newnode;		//����������ʱ��ָ��ָ���½��					
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;					
				back_1();				//�ָ�����չǰ��״̬		
				re.push(4);				//��֦����
			}
		}
		
		/*����˳ʱ����ת��չ-5*/
		
		//����չ�ϴ���ת�������
		if(re_check!=6)							
		{
			left_1();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//�����½��			
				newnode->next=NULL;			
				newnode->v=5;			//��ת��ʽ				
				newnode->parent=here;	//ָ�򸸽��				
				here->l_1=newnode;		//���������˳ʱ��ָ��ָ���½��				
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;		
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;		
				newnode->v=5;			//��ת��ʽ				
				newnode->parent=here;	//ָ�򸸽��						
				here->l_1=newnode;		//���������˳ʱ��ָ��ָ���½��						
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;				
				left_2();				//�ָ�����չǰ��״̬	
				re.push(5);				//��֦����
			}
		}

		/*������ʱ����ת��չ-6*/
		
		//����չ�ϴ���ת�������
		if(re_check!=5)							
		{
			left_2();
			(*p)();
			if(solve_1==true)
			{			
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;				
				newnode->v=6;			//��ת��ʽ						
				newnode->parent=here;	//ָ�򸸽��						
				here->l_2=newnode;		//�����������ʱ��ָ��ָ���½��					
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;			
				break;
			}
			else
			{	
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;		
				newnode->v=6;			//��ת��ʽ				
				newnode->parent=here;	//ָ�򸸽��				
				here->l_2=newnode;		//�����������ʱ��ָ��ָ���½��				
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;			
				left_1();				//�ָ�����չǰ��״̬	
				re.push(6);				//��֦����
			}
		}

		/*����˳ʱ����ת��չ-7*/
		
		//����չ�ϴ���ת�������
		if(re_check!=8)							
		{
			right_1();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;		
				newnode->v=7;			//��ת��ʽ			
				newnode->parent=here;	//ָ�򸸽��					
				here->r_1=newnode;		//���������˳ʱ��ָ��ָ���½��						
				nextnode->next=newnode;	//�½������β��������չ����	
				nextnode=newnode;		
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;	
				newnode->v=7;			//��ת��ʽ				
				newnode->parent=here;	//ָ�򸸽��	
				here->r_1=newnode;		//���������˳ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;
				right_2();				//�ָ�����չǰ��״̬
				re.push(7);				//��֦����
			}
		}

		/*������ʱ����ת��չ-8*/
		
		//����չ�ϴ���ת�������
		if(re_check!=7)							
		{
			right_2();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=8;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->r_2=newnode;		//�����������ʱ��ָ��ָ���½��	
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=8;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->r_2=newnode;		//�����������ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;
				right_1();				//�ָ�����չǰ��״̬
				re.push(8);				//��֦����
			}
		}

		/*����˳ʱ����ת��չ-9*/
		
		//����չ�ϴ���ת�������
		if(re_check!=10)						
		{
			up_1();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;		
				newnode->v=9;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->u_1=newnode;		//���������˳ʱ��ָ��ָ���½��					
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;	
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=9;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->u_1=newnode;		//���������˳ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;		//�ָ�����չǰ��״̬
				up_2();
				re.push(9);				//��֦����
			}
		}

		/*������ʱ����ת��չ-10*/
		
		//����չ�ϴ���ת�������
		if(re_check!=9)							
		{
			up_2();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=10;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->u_2=newnode;		//�����������ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=10;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��			
				here->u_2=newnode;		//�����������ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;
				up_1();					//�ָ�����չǰ��״̬
				re.push(10);			//��֦����
			}
		}

		/*����˳ʱ����ת��չ-11*/
		
		//����չ�ϴ���ת�������
		if(re_check!=12)						
		{
			down_1();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=11;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->d_1=newnode;		//���������˳ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;			
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=11;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->d_1=newnode;		//���������˳ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;
				down_2();				//�ָ�����չǰ��״̬
				re.push(11);			//��֦����
			}
		}

		/*������ʱ����ת��չ-12*/
		
		//����չ�ϴ���ת�������
		if(re_check!=11)					
		{
			down_2();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//�����½��			
				newnode->next=NULL;
				newnode->v=12;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->d_2=newnode;		//�����������ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�½������β��������չ����
				nextnode=newnode;
				break;
			}
			else
			{
				newnode=new nodec;		//�����½��		
				newnode->next=NULL;
				newnode->v=12;			//��ת��ʽ		
				newnode->parent=here;	//ָ�򸸽��		
				here->d_2=newnode;		//�����������ʱ��ָ��ָ���½��		
				nextnode->next=newnode;	//�����������ʱ��ָ��ָ���½��
				nextnode=newnode;
				down_1();				//�ָ�����չǰ��״̬
				re.push(12);			//��֦����
			}
		}
		here=here->next;				//��һ����Ҫ��չ�Ľ��				
		re_check=re.front();			//Ҫ��չ�Ľ�����ת��ʽ	
		re.pop();
		
		/*�ڶ��μ�֦,ֻ�������Ĳ����ﵽ4�����ϲ�������*/
		/*if(re_check1==1)
		{
			nodec *p;
			p=here;
			while(re_check1!=4&&p->parent!=NULL&&re_check1!=5)				
			{
				
				if(p->parent->v!=0)			
				{
					if(p->parent->v==here->v)
					{	
						p=p->parent;
						re_check1++;
					}	
					else
						
						//��ǰ�Ĵε���ת������һ���뱾�εĲ�ͬ���˳�
						re_check1=5;			
				}
				else
					
					//����ת���������Ĵε�ʱ���˳�
					re_check1=5;				
				
				//�����Ĵν���ͬһ����ת����
				if(re_check1==4)				
				{
					//������ǰҪ��չ�Ľ��,ָ����һ��Ҫ��չ�Ľ��
					here=here->next;			
					re_check=re.front();	
					
					//�����˴���ת��ʽ
					re.pop();					

					p=here;
					re_check1=1;
				}
			}
		}*/
		re_check1=1;
		reback();
		node_operation();
	}
	bfs_solve();
}




