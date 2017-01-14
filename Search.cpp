/*-------------------*/
/*  魔方求解头文件   */
/*-------------------*/
#include "StdAfx.h"
#include"All_Function.h"
#include<iostream>
#include <conio.h>

/*----------------*/
/*存储扩展旋转序列*/
/*----------------*/

struct nodec
{
	int v;
	nodec *parent;	//用来指向父结点								
	nodec *next;	//用来指向扩展结点								
	
	//父结点的具体指向
	nodec *l_1;	nodec *l_2;	nodec *r_1;	nodec *r_2;
	nodec *u_1;	nodec *u_2;	nodec *d_1;	nodec *d_2;
	nodec *f_1;	nodec *f_2;	nodec *b_1;	nodec *b_2;
};

/*----------------*/
/*定义所需要的变量*/
/*----------------*/

nodec *tree;		//指向树根结点
nodec *here;		//指向需要扩展的结点
nodec *nextnode;	//指向当前结点	
nodec *newnode;		//指向新结点
queue<int> re;		//存储旋转序列，剪枝
stack<int> rb;		//恢复当前结点状态
int solve=0;		//用来判断魔方求解是否成功										
/*------------------*/
/*判断魔方是否被解出*/
/*------------------*/							

bool compara()
{
	int i,j;
	char s;
	for(i=0;i<12;i++)
		for(j=0;j<9;j++)
		{
			//魔方下面标准状态
			s=graphsta[7][4];
			if((i>=6&&i<9)&&(j>=3&&j<6))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//魔方上面标准状态
			s=graphsta[1][4];
			if((i>=0&&i<3)&&(j>2&&j<6))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//魔方后面标准状态
			s=graphsta[10][4];
			if((i>=9&&i<12)&&(j>=3&&j<9))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//魔方左面标准状态
			s=graphsta[4][1];
			if(i>2&&(j>=0&&j<3))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//魔方前面标准状态
			s=graphsta[4][4];
			if(i>2&&(j>2&&j<6))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
			//魔方右面标准状态
			s=graphsta[4][7];
			if(i>2&&(j>5&&j<9))
			{	
				if(graphsta[i][j]==s)	
					solve++;
			}
		}	
	//魔方被解出	
	if(solve==54)return true;					
	//魔方没有被解出
	else
	{	
		solve=0;
		return false;							
	}
}

/*----------------------------------*/
/*将要求解的魔方状态送入旋转操作数组*/
/*----------------------------------*/

void change() 
{
	int i,j;
	for(i=0;i<12;i++)
		for(j=0;j<9;j++)
			graphsta[i][j]=graphmf[i][j];
}


/*------------------------------*/
/*找到当前要扩展的结点的旋转过程*/
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
/*魔方找到解的过程*/
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
		rc.push(i);			//进总序列
		rb.pop();
	}
}

/*---------------------------------------------------------*/
/*将扩展的旋转序列转换成具体的旋转操作,得到魔方当前的状态图*/
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
/*打印魔方求解过程*/
/*----------------*/
//void mission_compelet() moved to GLView.cpp

/*--------*/
/*魔方求解*/
/*--------*/

void bfs_mf()
{
	//cout<<"1";
	int i=0;
	//剪枝标记
	int re_check=0,re_check1=1;					
	//建立根结点
	tree=new nodec;								
	tree->v=0;
	tree->parent=NULL;
	here=tree;
	nextnode=tree;
	//转换成要求解的魔方状态									
	(*p)();		//开始时就为要求状态
	while(solve_1==false)
	{
		/*前面顺时针旋转扩展-1*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=2)							
		{
			front_1();
			(*p)();
			if(solve_1==true)
			{	
				
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;	
				newnode->v=1;			//旋转方式							
				newnode->parent=here;	//指向父结点							
				here->f_1=newnode;		//父结点前面顺时针指针指向新结点					
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;				
				break;
			}
			else
			{	
				
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;				
				newnode->v=1;			//旋转方式						
				newnode->parent=here;	//指向父结点							
				here->f_1=newnode;		//父结点前面顺时针指针指向新结点							
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;					
				front_2();				//恢复到扩展前的状态	
				re.push(1);				//剪枝序列
			}
		}
		
		/*前面逆时针旋转扩展-2*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=1)							
		{
			front_2();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;			
				newnode->v=2;			//旋转方式					
				newnode->parent=here;	//指向父结点						
				here->f_2=newnode;		//父结点前面逆时针指针指向新结点						
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;			
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点			
				newnode->next=NULL;			
				newnode->v=2;			//旋转方式					
				newnode->parent=here;	//指向父结点				
				here->f_2=newnode;		//父结点前面逆时针指针指向新结点					
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;			
				front_1();				//恢复到扩展前的状态
				re.push(2);				//剪枝序列
			}
		}
		
		/*后面顺时针旋转扩展-3*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=4)							
		{
			back_1();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//申请新结点			
				newnode->next=NULL;		
				newnode->v=3;			//旋转方式				
				newnode->parent=here;	//指向父结点				
				here->b_1=newnode;		//父结点后面顺时针指针指向新结点					
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;			
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点	
				newnode->next=NULL;						
				newnode->v=3;			//旋转方式					
				newnode->parent=here;	//指向父结点				
				here->b_1=newnode;		//父结点后面顺时针指针指向新结点			
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;				
				back_2();				//恢复到扩展前的状态	
				re.push(3);				//剪枝序列
			}
		}

		/*后面逆时针旋转扩展-4*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=3)							
		{
			back_2();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;				
				newnode->v=4;			//旋转方式					
				newnode->parent=here;	//指向父结点					
				here->b_2=newnode;		//父结点后面逆时针指针指向新结点					
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;				
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;			
				newnode->v=4;			//旋转方式						
				newnode->parent=here;	//指向父结点						
				here->b_2=newnode;		//父结点后面逆时针指针指向新结点					
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;					
				back_1();				//恢复到扩展前的状态		
				re.push(4);				//剪枝序列
			}
		}
		
		/*左面顺时针旋转扩展-5*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=6)							
		{
			left_1();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//申请新结点			
				newnode->next=NULL;			
				newnode->v=5;			//旋转方式				
				newnode->parent=here;	//指向父结点				
				here->l_1=newnode;		//父结点左面顺时针指针指向新结点				
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;		
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;		
				newnode->v=5;			//旋转方式				
				newnode->parent=here;	//指向父结点						
				here->l_1=newnode;		//父结点左面顺时针指针指向新结点						
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;				
				left_2();				//恢复到扩展前的状态	
				re.push(5);				//剪枝序列
			}
		}

		/*左面逆时针旋转扩展-6*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=5)							
		{
			left_2();
			(*p)();
			if(solve_1==true)
			{			
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;				
				newnode->v=6;			//旋转方式						
				newnode->parent=here;	//指向父结点						
				here->l_2=newnode;		//父结点左面逆时针指针指向新结点					
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;			
				break;
			}
			else
			{	
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;		
				newnode->v=6;			//旋转方式				
				newnode->parent=here;	//指向父结点				
				here->l_2=newnode;		//父结点左面逆时针指针指向新结点				
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;			
				left_1();				//恢复到扩展前的状态	
				re.push(6);				//剪枝序列
			}
		}

		/*右面顺时针旋转扩展-7*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=8)							
		{
			right_1();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;		
				newnode->v=7;			//旋转方式			
				newnode->parent=here;	//指向父结点					
				here->r_1=newnode;		//父结点右面顺时针指针指向新结点						
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表	
				nextnode=newnode;		
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;	
				newnode->v=7;			//旋转方式				
				newnode->parent=here;	//指向父结点	
				here->r_1=newnode;		//父结点右面顺时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;
				right_2();				//恢复到扩展前的状态
				re.push(7);				//剪枝序列
			}
		}

		/*右面逆时针旋转扩展-8*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=7)							
		{
			right_2();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=8;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->r_2=newnode;		//父结点右面逆时针指针指向新结点	
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=8;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->r_2=newnode;		//父结点右面逆时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;
				right_1();				//恢复到扩展前的状态
				re.push(8);				//剪枝序列
			}
		}

		/*上面顺时针旋转扩展-9*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=10)						
		{
			up_1();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;		
				newnode->v=9;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->u_1=newnode;		//父结点上面顺时针指针指向新结点					
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;	
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=9;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->u_1=newnode;		//父结点上面顺时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;		//恢复到扩展前的状态
				up_2();
				re.push(9);				//剪枝序列
			}
		}

		/*上面逆时针旋转扩展-10*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=9)							
		{
			up_2();
			(*p)();
			if(solve_1==true)
			{	
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=10;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->u_2=newnode;		//父结点上面逆时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=10;			//旋转方式		
				newnode->parent=here;	//指向父结点			
				here->u_2=newnode;		//父结点上面逆时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;
				up_1();					//恢复到扩展前的状态
				re.push(10);			//剪枝序列
			}
		}

		/*下面顺时针旋转扩展-11*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=12)						
		{
			down_1();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=11;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->d_1=newnode;		//父结点下面顺时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;			
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=11;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->d_1=newnode;		//父结点下面顺时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;
				down_2();				//恢复到扩展前的状态
				re.push(11);			//剪枝序列
			}
		}

		/*下面逆时针旋转扩展-12*/
		
		//不扩展上次旋转的逆操作
		if(re_check!=11)					
		{
			down_2();
			(*p)();
			if(solve_1==true)
			{
				newnode=new nodec;		//申请新结点			
				newnode->next=NULL;
				newnode->v=12;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->d_2=newnode;		//父结点下面逆时针指针指向新结点		
				nextnode->next=newnode;	//新结点插入队尾，构造扩展链表
				nextnode=newnode;
				break;
			}
			else
			{
				newnode=new nodec;		//申请新结点		
				newnode->next=NULL;
				newnode->v=12;			//旋转方式		
				newnode->parent=here;	//指向父结点		
				here->d_2=newnode;		//父结点下面逆时针指针指向新结点		
				nextnode->next=newnode;	//父结点下面逆时针指针指向新结点
				nextnode=newnode;
				down_1();				//恢复到扩展前的状态
				re.push(12);			//剪枝序列
			}
		}
		here=here->next;				//下一个需要扩展的结点				
		re_check=re.front();			//要扩展的结点的旋转方式	
		re.pop();
		
		/*第二次剪枝,只对搜索的层数达到4层以上才起作用*/
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
						
						//当前四次的旋转操作有一次与本次的不同则退出
						re_check1=5;			
				}
				else
					
					//当旋转操作不足四次的时候退出
					re_check1=5;				
				
				//连续四次进行同一种旋转操作
				if(re_check1==4)				
				{
					//抛弃当前要扩展的结点,指向下一个要扩展的结点
					here=here->next;			
					re_check=re.front();	
					
					//抛弃此次旋转方式
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




