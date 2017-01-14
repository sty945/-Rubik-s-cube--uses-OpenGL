#include "StdAfx.h"
#include "All_Function.h"

int solve1;				//判断角块的位置,来采取具体的旋转序列

/*--------------------------*/
/*恢复前面四个角块的专家序列*/
/*--------------------------*/
void expert1_1()		//角块五第一种情况
{
	up_1();		rc.push(9);
	back_1();	rc.push(3);
	up_2();		rc.push(10);
}

void expert1_2()		//角块五第二种情况
{
	left_2();	rc.push(6);
	back_2();	rc.push(4);
	left_1();	rc.push(5);
}
	
void expert1_3(const char s[2])	//角块五第三种情况
{
	int i=0,j=0,z=0;
	up_1();		rc.push(9);
	back_2();	rc.push(4);
	up_2();		rc.push(10);
	while(1)				//通过被面转动,恢复到角块五的第一种或第二种情况,如果经过一次逆时针和一次逆时针都没有
	{						//到标准位置就说明符合要求的角块在对角线的位置,可以经两次顺时针变换到达标准位置
		if(j==0)//逆时针
		{
			back_2();
			i++;
		}
		//rc.push(4);
		if((graphsta[0][3]=='R'&&graphsta[3][0]==s[0]&&graphsta[9][3]==s[1])||  //角块五第一种情况
		(graphsta[0][3]=='R'&&graphsta[3][0]==s[1]&&graphsta[9][3]==s[0]))
		{
			z=1;
			//expert1_1();
			break;
		}
		if((graphsta[3][0]=='R'&&graphsta[0][3]==s[1]&&graphsta[9][3]==s[0])||  //角块五第二种情况
		(graphsta[3][0]=='R'&&graphsta[0][3]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=2;
			//expert1_2();
			break;
		}
		if(i==1&&j==0)back_1();//恢复到转动前的状态
		if(i>=1)//顺时针
		{
			back_1();
			j++;
		}
	}
	if(i==1&&j==0)rc.push(4);
	if(j==1)rc.push(3);
	if(j==2)
	{
		rc.push(3);
		rc.push(3);
	}
	if(z==1)expert1_1();
	if(z==2)expert1_2();
}

void expert1_4(const char s[2])	//角块一第一种情况
{
	int i=0,j=0,z=0;
	up_1();		rc.push(9);
	back_1();	rc.push(3);
	up_2();		rc.push(10);
	while(1)				//通过被面的转动，恢复到角块五的第一种或第二种情况
	{
		if(j==0)//逆时针
		{
			back_2();
			i++;
		}
		//rc.push(4);
		if((graphsta[0][3]=='R'&&graphsta[3][0]==s[1]&&graphsta[9][3]==s[0])||  //角块五第一种情况
		(graphsta[0][3]=='R'&&graphsta[3][0]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=1;
			//expert1_1();
			break;
		}
		if((graphsta[3][0]=='R'&&graphsta[0][3]==s[1]&&graphsta[9][3]==s[0])||  //角块五第二种情况
		(graphsta[3][0]=='R'&&graphsta[0][3]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=2;
			//expert1_2();
			break;
		}
		if(i==1&&j==0)back_1();//恢复到转动前的状态
		if(i>=1)//顺时针
		{
			back_1();
			j++;
			i--;
		}
	}
	if(i==1&&j==0)rc.push(4);
	if(j==1)rc.push(3);
	if(j==2)
	{
		rc.push(3);
		rc.push(3);
	}
	if(z==1)expert1_1();
	if(z==2)expert1_2();
}

void expert1_5(const char s[2])	//角块一第二种情况
{
	int i=0,j=0,z=0;
	left_2();	rc.push(6);
	back_2();	rc.push(4);
	left_1();	rc.push(5);
	while(1)				//通过被面的转动，恢复到角块五的第一种或第二种情况
	{
		if(j==0)//逆时针
		{
			back_2();
			i++;
		}
		//rc.push(4);
		if((graphsta[0][3]=='R'&&graphsta[3][0]==s[1]&&graphsta[9][3]==s[0])||  //角块五第一种情况
		(graphsta[0][3]=='R'&&graphsta[3][0]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=1;
			//expert1_1();
			break;
		}
		if((graphsta[3][0]=='R'&&graphsta[0][3]==s[1]&&graphsta[9][3]==s[0])||  //角块五第二种情况
		(graphsta[3][0]=='R'&&graphsta[0][3]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=2;
			//expert1_2();
			break;
		}
		if(i==1&&j==0)back_1();//恢复到转动前的状态
		if(i>=1)//顺时针
		{
			back_1();
			j++;
			i--;
		}
	}
	if(i==1&&j==0)rc.push(4);
	if(j==1)rc.push(3);
	if(j==2)
	{
		rc.push(3);
		rc.push(3);
	}
	if(z==1)expert1_1();
	if(z==2)expert1_2();
}
/*----------------------------------------------*/
/*两种特殊的旋转序列，在恢复边块色向的时候要用到*/
/*----------------------------------------------*/
void v1()
{
	left_1();		rc.push(5);
	right_2();		rc.push(8);
	front_down();	rc.push(13);
	front_down();	rc.push(13);
	front_down();	rc.push(13);
}

void v3()
{
	left_2();		rc.push(6);
	right_1();		rc.push(7);
	front_down();	rc.push(13);
}
/*---------*/
/*恢复R-W-G*/
/*---------*/
void compara1()
{
	solve_1=false;//判断当前要找的角块是否已经被搜索到
	if(graphsta[2][3]=='W'&&graphsta[3][2]=='G'&&graphsta[3][3]=='R')		//当前角块已经在标准位置
	{
		solve1=0;//用来判断调用哪个函数
		solve_1=true;
	}
	//当前角块不是要求的角块，应当搜索到以下几种情况
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='W'&&graphsta[9][3]=='G')||	//角块五第一种情况
		(graphsta[0][3]=='R'&&graphsta[3][0]=='G'&&graphsta[9][3]=='W'))
	{
		solve1=1;
		solve_1=true;
	}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='W'&&graphsta[9][3]=='G')||	 //角块五第二种情况
		(graphsta[3][0]=='R'&&graphsta[0][3]=='G'&&graphsta[9][3]=='W'))
	{
		solve1=2;
		solve_1=true;	
	}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='W'&&graphsta[3][0]=='G')||
		(graphsta[9][3]=='R'&&graphsta[0][3]=='G'&&graphsta[3][0]=='W'))	//角块五第三种情况
	{
		solve1=3;
		solve_1=true;	
	}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='W'&&graphsta[3][3]=='G')||	//角块一的第一种情况
		(graphsta[2][3]=='R'&&graphsta[3][2]=='G'&&graphsta[3][3]=='W'))
	{
		solve1=4;
		solve_1=true;	
	}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='W'&&graphsta[3][3]=='G')||	//角块一的第二种情况
		(graphsta[3][2]=='R'&&graphsta[2][3]=='G'&&graphsta[3][3]=='W')) 
	{
		solve1=5;
		solve_1=true;	
	}
}

/*---------*/
/*恢复R-W-B*/
/*---------*/
void compara2()
{
	solve_1=false;
	if(graphsta[2][3]=='B'&&graphsta[3][2]=='W'&&graphsta[3][3]=='R')		//当前角块已经在标准位置
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=0;
			solve_1=true; 
		}
	//当前角块不是要求的角块，应当搜索到以下几种情况
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='W'&&graphsta[9][3]=='B')||	//角块五第一种情况
		(graphsta[0][3]=='R'&&graphsta[3][0]=='B'&&graphsta[9][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=1;
			solve_1=true; 
		}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='W'&&graphsta[9][3]=='B')||	//角块五第二种情况
		(graphsta[3][0]=='R'&&graphsta[0][3]=='B'&&graphsta[9][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G') 
		{
			solve1=2;
			solve_1=true; 
		}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='W'&&graphsta[3][0]=='B')||	//角块五第三种情况
		(graphsta[9][3]=='R'&&graphsta[0][3]=='B'&&graphsta[3][0]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=3;
			solve_1=true;  
		}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='W'&&graphsta[3][3]=='B')||	//角块一的第一种情况
		(graphsta[2][3]=='R'&&graphsta[3][2]=='B'&&graphsta[3][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=4;
			solve_1=true;  
		}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='W'&&graphsta[3][3]=='B')||	//角块一的第二种情况
		(graphsta[3][2]=='R'&&graphsta[2][3]=='B'&&graphsta[3][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=5;
			solve_1=true;  
		}
}

/*---------*/
/*恢复R-Y-B*/
/*---------*/
void compara3()
{
	solve_1=false;
	if(graphsta[2][3]=='Y'&&graphsta[3][2]=='B'&&graphsta[3][3]=='R')		//当前角块已经在标准位置
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=0;
				solve_1=true; 
			}
	//当前角块不是要求的角块，应当搜索到以下几种情况
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='Y'&&graphsta[9][3]=='B')||	//角块五第一种情况
		(graphsta[0][3]=='R'&&graphsta[3][0]=='B'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=1;
				solve_1=true; 
			}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='Y'&&graphsta[9][3]=='B')||	//角块五第二种情况
		(graphsta[3][0]=='R'&&graphsta[0][3]=='B'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W') 
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=2;
				solve_1=true; 
			}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='Y'&&graphsta[3][0]=='B')||	//角块五第三种情况
		(graphsta[9][3]=='R'&&graphsta[0][3]=='B'&&graphsta[3][0]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=3;
				solve_1=true; 
			}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='Y'&&graphsta[3][3]=='B')||	//角块一的第一种情况
		(graphsta[2][3]=='R'&&graphsta[3][2]=='B'&&graphsta[3][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=4;
				solve_1=true;  
			}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='Y'&&graphsta[3][3]=='B')||	//角块一的第二种情况
		(graphsta[3][2]=='R'&&graphsta[2][3]=='B'&&graphsta[3][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=5;
				solve_1=true;  
			}
}

/*---------*/
/*恢复R-Y-G*/
/*---------*/
void compara4()
{
	solve_1=false;
	if(graphsta[2][3]=='G'&&graphsta[3][2]=='Y'&&graphsta[3][3]=='R')		//当前角块已经在标准位置
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=0;
					solve_1=true; 
				}
	//当前角块不是要求的角块，应当搜索到以下几种情况
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='Y'&&graphsta[9][3]=='G')||	//角块五第一种情况
		(graphsta[0][3]=='R'&&graphsta[3][0]=='G'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=1;
					solve_1=true; 
				}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='Y'&&graphsta[9][3]=='G')||	//角块五第二种情况
		(graphsta[3][0]=='R'&&graphsta[0][3]=='G'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B') 
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=2;
					solve_1=true; 
				}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='Y'&&graphsta[3][0]=='G')||	//角块五第三种情况
		(graphsta[9][3]=='R'&&graphsta[0][3]=='G'&&graphsta[3][0]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=3;
					solve_1=true;  
				}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='Y'&&graphsta[3][3]=='G')||	//角块一的第一种情况
		(graphsta[2][3]=='R'&&graphsta[3][2]=='G'&&graphsta[3][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=4;
					solve_1=true;  
				}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='Y'&&graphsta[3][3]=='G')||	//角块一的第二种情况
		(graphsta[3][2]=='R'&&graphsta[2][3]=='G'&&graphsta[3][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=5;
					solve_1=true;  
				}
}

void decide(const char s[2])
{
	if(solve1==1)
		expert1_1();
	if(solve1==2)
		expert1_2();
	if(solve1==3)
		expert1_3(s);
	if(solve1==4)
		expert1_4(s);
	if(solve1==5)
		expert1_5(s);
}


/*--------------------------------------------*/
/*恢复在当前状态下的上面角块向上的颜色专家序列*/
/*--------------------------------------------*/
void compara5(int *p)
{	
	if(graphsta[3][3]=='O'&&graphsta[0][5]=='O'&&graphsta[3][0]=='O'&&graphsta[3][6]=='O')
	{
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		up_2();			rc.push(10);
		right_2();		rc.push(8);
		up_2();			rc.push(10);
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		right_2();		rc.push(8);
		*p=1;
	}
	if(graphsta[2][3]=='O'&&graphsta[3][5]=='O'&&graphsta[3][8]=='O'&&graphsta[9][3]=='O')
	{
		right_1();		rc.push(7);
		up_1();			rc.push(9);
		right_2();		rc.push(8);
		up_1();			rc.push(9);
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		up_2();			rc.push(10);
		right_2();		rc.push(8);
		*p=1;
	}
	if(graphsta[3][3]=='O'&&graphsta[3][5]=='O'&&graphsta[9][5]=='O'&&graphsta[9][3]=='O')
	{
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		up_2();			rc.push(10);
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		up_2();			rc.push(10);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		*p=1;
	}
	if(graphsta[3][3]=='O'&&graphsta[3][5]=='O'&&graphsta[3][0]=='O'&&graphsta[3][8]=='O')
	{
		right_1();		rc.push(7);
		up_1();			rc.push(9);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		front_2();		rc.push(2);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		up_1();			rc.push(9);
		right_2();		rc.push(8);
		*p=1;
	}
	if(graphsta[3][3]=='O'&&graphsta[3][5]=='O'&&graphsta[0][3]=='O'&&graphsta[0][5]=='O')
	{
		right_2();		rc.push(8);
		up_2();			rc.push(10);
		front_2();		rc.push(2);
		up_1();			rc.push(9);
		front_1();		rc.push(1);
		right_1();		rc.push(7);
		*p=1;
	}
	if(graphsta[2][3]=='O'&&graphsta[2][5]=='O'&&graphsta[3][8]=='O'&&graphsta[3][0]=='O')
	{
		right_1();		rc.push(7);
		up_1();			rc.push(9);
		right_2();		rc.push(8);
		up_2();			rc.push(10);
		front_2();		rc.push(2);
		up_2();			rc.push(10);
		front_1();		rc.push(1);
		*p=1;
	}
	if(graphsta[2][3]=='O'&&graphsta[0][5]=='O'&&graphsta[3][6]=='O'&&graphsta[9][3]=='O')
	{
		front_2();		rc.push(2);
		up_1();			rc.push(9);
		front_1();		rc.push(1);
		up_1();			rc.push(9);
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		right_2();		rc.push(8);
		*p=1;
	}
	if(graphsta[2][3]=='O'&&graphsta[2][5]=='O'&&graphsta[0][5]=='O'&&graphsta[0][3]=='O')
		*p=1;
}

/*------------------------------------------*/
/*恢复在当前状态下魔方上角块的位置的专家序列*/
/*------------------------------------------*/
void compara6(int *p)
{
	int i=0,j=0;
	//统计上角块边色成对的个数
	if(graphsta[3][0]==graphsta[3][2])i++;
	if(graphsta[3][3]==graphsta[3][5])i++;
	if(graphsta[3][6]==graphsta[3][8])i++;
	if(graphsta[9][3]==graphsta[9][5])i++;
	//统计下角块边色成对的个数
	if(graphsta[5][0]==graphsta[5][2])j++;
	if(graphsta[5][3]==graphsta[5][5])j++;
	if(graphsta[5][6]==graphsta[5][8])j++;
	if(graphsta[11][3]==graphsta[11][5])j++;
	//通过判断i,j的个数来采取具体的专家序列
	if(i==0&&j==0)									//上角无，下角无
	{
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		*p=1;
	}
	if(i==0&&j==1)									//上角无，下角一对
	{
		while(graphsta[5][3]!=graphsta[5][5])		//下角成对的摆到前面
		{
			down_1();	rc.push(11);
		}
		right_2();		rc.push(8);
		up_1();			rc.push(9);
		front_2();		rc.push(2);
		left_1();		rc.push(5);
		left_1();		rc.push(5);
		front_1();		rc.push(1);
		up_2();			rc.push(10);
		right_1();		rc.push(7);
		*p=1;
	}
	if(i==1&&j==1)									//上角一对，下角一对
	{
		while(graphsta[3][0]!=graphsta[3][2])		//上下两对都放到左面
		{
			up_1();		rc.push(9);
		}
		while(graphsta[5][0]!=graphsta[5][2])
		{
			down_1();	rc.push(11);
		}
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		up_1();			rc.push(9);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		down_2();		rc.push(12);
		down_2();		rc.push(12);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		up_1();			rc.push(9);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		*p=1;
	}
	if(i==4&&j==1)									//上角四对，下角一对
	{
		while(graphsta[11][3]!=graphsta[11][5])		//下角成对的摆到后面
		{
			down_1();	rc.push(11);
		}
		right_2();		rc.push(8);
		up_1();			rc.push(9);
		front_2();		rc.push(2);
		left_1();		rc.push(5);
		left_1();		rc.push(5);
		front_1();		rc.push(1);
		up_2();			rc.push(10);
		right_2();		rc.push(8);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		*p=1;
	}
	if(i==0&&j==4)									//上角无，下角四对
	{
		right_2();		rc.push(8);
		front_1();		rc.push(1);
		right_1();		rc.push(7);
		up_1();			rc.push(9);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		up_1();			rc.push(9);
		right_2();		rc.push(8);
		front_2();		rc.push(2);
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		*p=1;
	}
	if(i==4&&j==4)//上角和下角已经为要求状态
		*p=1;
}

/*--------------------------*/
/*恢复顶面三个边块的专家序列*/
/*--------------------------*/
void compara7(int *p,const char s[2])
{
	while(1)
	{
		if(graphsta[2][4]==s[0]&&graphsta[3][4]==s[1])		//已经为要求的状态
		{	
			*p=1;
			break;
		}
		while(graphsta[3][3]!=s[1])					//朝前的边块不是要求的
		{
			up_1();		rc.push(9);
		}
		while(1)
		{
			if(graphsta[2][4]==s[0]&&graphsta[3][4]==s[1])	//已经为要求的状态
				break;
			if(graphsta[10][5]==s[0]&&graphsta[4][8]==s[1])	//BR-UF
			{
				front_1();		rc.push(1);
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);
				*p=*p+1;		break;
			}
			if(graphsta[10][3]==s[0]&&graphsta[4][0]==s[1])	//BL-UF
			{
				front_2();		rc.push(2);
				up_1();			rc.push(9);
				down_2();		rc.push(12);
				left_1();		rc.push(5);
				*p=*p+1;		break;
			}
			if(graphsta[6][4]==s[0]&&graphsta[5][4]==s[1])	//DF-UF
			{
				left_2();		rc.push(6);
				right_1();		rc.push(7);
				front_1();		rc.push(1);
				front_1();		rc.push(1);
				left_1();		rc.push(5);
				right_2();		rc.push(8);
				*p=*p+1;		break;
			}
			if(graphsta[5][7]==s[0]&&graphsta[7][5]==s[1])	//RD-UF
			{
				left_2();		rc.push(6);
				right_1();		rc.push(7);
				front_2();		rc.push(2);
				left_1();		rc.push(5);
				right_2();		rc.push(8);
				*p=*p+1;		break;
			}
			if(graphsta[5][1]==s[0]&&graphsta[7][3]==s[1])	//LD-UF
			{
				left_2();		rc.push(6);
				right_1();		rc.push(7);
				front_1();		rc.push(1);
				left_1();		rc.push(5);
				right_2();		rc.push(8);
				*p=*p+1;		break;
			}
			//以下为特殊情况，要求的边块在顶面
			if(graphsta[3][4]==s[0]&&graphsta[2][4]==s[1])	//要求块已经在正确位置，只是色向不对，利用BR-UF将它弹出
			{
				front_1();		rc.push(1);
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);
				
				while(graphsta[3][3]!=s[1])					//朝前的边块不是要求的
				{
					up_1();		rc.push(9); 
				}
				continue;
			}
			if((graphsta[1][3]==s[0]&&graphsta[3][1]==s[1])||(graphsta[1][3]==s[1]&&graphsta[3][1]==s[0]))//在左面
			{
				up_2();			rc.push(10);				//转到前面
				
				front_1();		rc.push(1);					//弹出
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);
				
				while(graphsta[3][3]!=s[1])					//朝前的边块不是要求的
				{
					up_1();		rc.push(9); 
				}
				continue;
			}
			if((graphsta[0][4]==s[0]&&graphsta[9][4]==s[1])||(graphsta[0][4]==s[1]&&graphsta[9][4]==s[0]))//在后面
			{
				up_2();			rc.push(10);
				up_2();			rc.push(10);

				front_1();		rc.push(1);					//弹出
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);

				while(graphsta[3][3]!=s[1])					//朝前的边块不是要求的
				{
					up_1();		rc.push(9);
				}
				continue;
			}
			if((graphsta[1][5]==s[0]&&graphsta[3][7]==s[1])||(graphsta[1][5]==s[1]&&graphsta[3][7]==s[0]))//在右面
			{
				up_1();			rc.push(9);

				front_1();		rc.push(1);					//弹出
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);

				while(graphsta[3][3]!=s[1])					//朝前的边块不是要求的
				{
					up_1();		rc.push(9);
				}
				continue;
			}
			up_1();				//第二次搜索
			rc.push(9);
			left_front();
			rc.push(14);
		}		
	}
}

/*--------------------------*/
/*恢复底面四个边块的专家序列*/
/*--------------------------*/
void compara8(int *p,const char s[2])
{
	while(1)
	{
		if(graphsta[6][4]==s[0]&&graphsta[5][4]==s[1])		//已经为要求的状态
		{	
			*p=1;
			break;
		}
		while(graphsta[5][3]!=s[1])							//朝前的边块不是要求的"A"
		{
			down_1();		rc.push(11); 
		}
		while(1)
		{
			if(graphsta[6][4]==s[0]&&graphsta[5][4]==s[1])	//经过"A"的调整已经为要求的状态
			{	
				*p=1;
				break;
			}
			/*while(graphsta[5][3]!=s[1])						//朝前的底边块不是要求的，可以优化
			{
				down_1();		rc.push(11); 
			}*/
			int i=0;
			while(graphsta[2][3]==graphsta[2][4])			//顶面找洞，可以优化
			{
				up_1();			rc.push(9);
				i++;
				if(i==4)									//顶面没有洞
					break;								
			}
			
			//专家序列
			if(graphsta[10][5]==s[0]&&graphsta[4][8]==s[1])
			{
				front_2();		rc.push(2);
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_1();		rc.push(7);
				*p=1;			break;
			}
			if(graphsta[10][3]==s[0]&&graphsta[4][0]==s[1])
			{
				front_1();		rc.push(1);
				up_1();			rc.push(9);
				down_2();		rc.push(12);
				left_2();		rc.push(6);
				*p=1;			break;
			}
			if(graphsta[3][4]==s[0]&&graphsta[2][4]==s[1])
			{
				front_1();		rc.push(1);
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);
				*p=1;			break;
			}
			//特殊情况
			if(graphsta[6][4]==s[1]&&graphsta[5][4]==s[0])	//已经在正确位置，只是色向不对？？？？？？？？？？
			{
				front_2();		rc.push(2);					//用一种专家序列，弹出
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//朝前的底边块不是要求的，可以优化
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			if((graphsta[5][1]==s[0]&&graphsta[7][3]==s[1])||(graphsta[5][1]==s[1]&&graphsta[7][3]==s[0]))//在左面
			{
				down_1();		rc.push(11);				//转到前面
				
				front_2();		rc.push(2);					//用一种专家序列，弹出
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//朝前的底边块不是要求的，可以优化
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			if((graphsta[5][7]==s[0]&&graphsta[7][5]==s[1])||(graphsta[5][7]==s[1]&&graphsta[7][5]==s[0]))//在右面
			{
				down_2();		rc.push(12);

				front_2();		rc.push(2);					//用一种专家序列，弹出
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//朝前的底边块不是要求的，可以优化
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			if((graphsta[8][4]==s[0]&&graphsta[11][4]==s[1])||(graphsta[8][4]==s[1]&&graphsta[11][4]==s[0]))//在后面
			{
				down_1();		rc.push(11);
				down_1();		rc.push(11);

				front_2();		rc.push(2);					//用一种专家序列，弹出
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//朝前的底边块不是要求的，可以优化
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			//有可能使程序进入死循环的状况,但当魔方遇到这种状态的时候还不知如何解决
			if(graphsta[2][4]==s[0]&&graphsta[3][4]==s[1])	//在上面，但色向不对，不能用专家序列????????????????????
			{
				front_2();		rc.push(2);					//用一种专家序列，弹出
				down_1();		rc.push(11);
				up_2();			rc.push(10);
				right_1();		rc.push(7);

				while(graphsta[5][3]!=s[1])					//朝前的底边块不是要求的，可以优化
				{
					down_1();		rc.push(11); 
				}
				continue;
			}

			up_1();				//第二次搜索,第一次搜索后要求的边块并不在可以解决的位置上
			rc.push(9);
			down_2();
			rc.push(12);
			left_front();
			rc.push(14);
		}
	break;
	}
}

/*--------------------------*/
/*处理顶面最后一块的专家序列*/
/*--------------------------*/
void compara9()
{
	int i=0;
	while(1)
	{
		if(graphsta[0][4]=='R'&&graphsta[1][3]=='R'&&graphsta[1][5]=='R'&&graphsta[2][4]=='R')//已经为标准状态
			break;
		while((graphsta[3][3]==graphsta[3][4])&&(graphsta[2][3]==graphsta[2][4]))		//找到上面的洞
		{
			up_1();		rc.push(9);//cout<<"1";
		}
		//rc.push(1);rc.push(12);rc.push(9);rc.push(6);
		while(1)
		{
			if(graphsta[4][8]=='R')//最后一块所在的位置
			{
				front_1();		rc.push(1);
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				right_1();		rc.push(7);
				right_1();		rc.push(7);
				down_1();		rc.push(11);
				up_2();			rc.push(10);
				back_2();		rc.push(4);
				back_2();		rc.push(4);
				front_2();		rc.push(2);//cout<<"a";
				break;
			}
			if(graphsta[4][0]=='R')//最后一块所在的位置
			{
				front_2();		rc.push(2);
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				left_1();		rc.push(5);
				left_1();		rc.push(5);
				up_1();			rc.push(9);
				down_2();		rc.push(12);
				back_2();		rc.push(4);
				back_2();		rc.push(4);
				front_1();		rc.push(1);//cout<<"b";
				break;
			}
			//特殊情况
			if(graphsta[3][4]=='R')					//在正确位置，只是色向不对???????????????????
			{
				i=1;
				break;								//暂时没有找到合适的序列恢复
				front_2();		rc.push(2);
				down_1();		rc.push(11);
				up_2();			rc.push(10);
				right_1();		rc.push(7);
				//continue;
			}
			if(i==0)
			{
				up_1();				rc.push(9);
				left_front();		rc.push(14);
			}
			else break;
		}
		break;
	}
}

/*----------------------*/
/*恢复中块位置的专家序列*/
/*----------------------*/
void compara10(const int k)
{
	if(k==1)	//边块UF-DF-BD-UF
	{
		left_2();		rc.push(6);
		right_1();		rc.push(7);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		left_1();		rc.push(5);
		right_2();		rc.push(8);
		down_2();		rc.push(12);
		down_2();		rc.push(12);
	}
	if(k==2)	//边块UF-BD-DF-UF
	{
		down_2();		rc.push(12);
		down_2();		rc.push(12);
		left_2();		rc.push(6);
		right_1();		rc.push(7);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		left_1();		rc.push(5);
		right_2();		rc.push(8);
	}
	if(k==3)	//边块UF-DF,UB-DB
	{
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		left_1();		rc.push(5);
		left_1();		rc.push(5);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		back_1();		rc.push(3);
		back_1();		rc.push(3);
		left_1();		rc.push(5);
		left_1();		rc.push(5);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
	}
}

/*----------------------*/
/*恢复边块色向的专家序列*/
/*----------------------*/
void compara11(const int k)
{
	if(k==1)	//FU BU
	{
		v3();
		up_1();			rc.push(9);
		v3();
		up_1();			rc.push(9);
		v3();
		up_1();			rc.push(9);
		up_1();			rc.push(9);
		v1();
		up_1();			rc.push(9);
		v1();
		up_1();			rc.push(9);
		v1();
		up_1();			rc.push(9);
		up_1();			rc.push(9);
	}
	if(k==2)	//FU BD
	{
		back_1();		rc.push(3);
		back_1();		rc.push(3);
		v3();
		up_1();			rc.push(9);
		v3();
		up_1();			rc.push(9);
		v3();
		up_1();			rc.push(9);
		up_1();			rc.push(9);
		v1();
		up_1();			rc.push(9);
		v1();
		up_1();			rc.push(9);
		v1();
		up_1();			rc.push(9);
		up_1();			rc.push(9);
		back_1();		rc.push(3);
		back_1();		rc.push(3);
	}
	if(k==3)	//FU RU
	{
		front_1();		rc.push(1);
		back_1();		rc.push(3);
		up_1();			rc.push(9);
		front_2();		rc.push(2);
		up_2();			rc.push(10);
		back_2();		rc.push(4);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		front_1();		rc.push(1);
		right_1();		rc.push(7);
		front_1();		rc.push(1);
		right_2();		rc.push(8);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
	}
	if(k==4)	//FU FD BD RU
	{
		v3();
		up_1();			rc.push(9);
		v3();
		up_1();			rc.push(9);
		v3();
		up_1();			rc.push(9);
		v3();
		up_1();			rc.push(9);
	}
	if(k==5)	//FU FD BD BU
	{
		front_1();		rc.push(1);
		left_1();		rc.push(5);
		left_1();		rc.push(5);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		up_1();			rc.push(9);
		down_2();		rc.push(12);
		left_2();		rc.push(6);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		back_1();		rc.push(3);
		back_1();		rc.push(3);
		right_2();		rc.push(8);
		back_1();		rc.push(3);
		back_1();		rc.push(3);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		up_2();			rc.push(10);
		down_1();		rc.push(11);
		back_1();		rc.push(3);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		left_1();		rc.push(5);
		left_1();		rc.push(5);
	}
}
/*------------------------*/
/*复原魔方前面的的四个角块*/
/*------------------------*/
void first_stage()
{
	front_down();
	rc.push(13);
	char s[2];

	//恢复R-W-G
	s[0]='W'; s[1]='G';
	p=compara1;// 找到函数入口
	bfs_mf();//搜索适合条件的位置
	if(solve1!=0)
		decide(s); 
	front_2();
	rc.push(2);
	
	//恢复R-W-B
	s[0]='W'; s[1]='B';
	p=compara2;
	bfs_mf();
	if(solve1!=0)
		decide(s);
	front_2();
	rc.push(2);

	//恢复R-Y-B
	s[0]='Y'; s[1]='B';
	p=compara3;
	bfs_mf();
	if(solve1!=0)
		decide(s);
	front_2();
	rc.push(2);

	//恢复R-G-Y
	s[0]='Y'; s[1]='G';
	p=compara4;
	bfs_mf();
	if(solve1!=0)
		decide(s);
	front_2();
	rc.push(2);
}

/*------------------------------------*/
/*恢复在当前状态下的上面角块向上的颜色*/
/*------------------------------------*/
void second_stage()
{
	int k=0;
	front_down();//将输入时做为魔方底面的那个面挪到上面来
	rc.push(13);
	while(k==0)
	{	
		compara5(&k);
		if(k==0)	//交换左面和前面的位置
		{
			left_front();
			rc.push(14);
		}
	}
}

/*--------------------------------*/
/*恢复在当前状态下魔方上角块的位置*/
/*--------------------------------*/
void third_stage()
{
	int k=0;
	while(k==0)
	{
		compara6(&k);
		if(k==0)	//交换顶面和底面的位置
		{
			front_down();
			rc.push(13);
			front_down();
			rc.push(13);
		}
	}
}

/*----------------*/
/*恢复顶面三个边块*/
/*----------------*/
void forth_stage()
{
	while(graphsta[1][4]!='R')	//将红色面做为顶面来处理，当然这回增加求解步骤，但方便程序的编写
	{
		front_down();		rc.push(13);
	}
	char s[2];					//记录要恢复的边块颜色，也会增加求解步骤，但这样做的理由同上
	int k=0;
	//先恢复R-Y边块
	s[0]='R'; s[1]='Y';
	while(k==0)
	{
		compara7(&k,s);
	}
	//恢复R-B，从这下面的程序可以优化，当上面的操作结束后要是除了R-B都在正确位置，则不应在搜索？？？？？？？
	k=0;
	s[0]='R'; s[1]='B';
	while(k==0)
	{
		compara7(&k,s);
	}
	//恢复R-W
	k=0;
	s[0]='R'; s[1]='W';
	while(k==0)
	{
		compara7(&k,s);
	}
	//恢复R-G
	k=0;
	s[0]='R'; s[1]='G';
	while(k==0)
	{
		compara7(&k,s);
	}
}

/*------------------*/
/*恢复魔方下面的边块*/
/*------------------*/
void fifth_stage()
{
	char s[2];
	int k=0;
	while(1)//有的时候下面四个操作结束后也有可能有一块没有回到正确的位置，可能是由于对于在正确位置是色向不对时的处理序列不对
	{
		if((graphsta[5][0]==graphsta[5][1])&&(graphsta[5][3]==graphsta[5][4])&&
			(graphsta[5][7]==graphsta[5][6])&&(graphsta[11][3]==graphsta[11][4]))
			break;
		//恢复O-Y
		s[0]='O'; s[1]='Y';
		while(k==0)
		{
			compara8(&k,s);
		}
		k=0;
		s[0]='O'; s[1]='B';
		while(k==0)
		{
			compara8(&k,s);
		}
		k=0;
		s[0]='O'; s[1]='W';
		while(k==0)
		{
			compara8(&k,s);
		}
		k=0;
		s[0]='O'; s[1]='G';
		while(k==0)
		{
			compara8(&k,s);
		}
		//第二次执行这个序列，保证在这个阶段过后，魔方的底面为标准状态
		k=0;
		s[0]='O'; s[1]='Y';
		while(k==0)
		{
			compara8(&k,s);
		}
		k=0;
		s[0]='O'; s[1]='B';
		while(k==0)
		{
			compara8(&k,s);
		}
		k=0;
		s[0]='O'; s[1]='W';
		while(k==0)
		{
			compara8(&k,s);
		}
		k=0;
		s[0]='O'; s[1]='G';
		while(k==0)
		{
			compara8(&k,s);
		}
	}
}

/*----------------*/
/*恢复顶边最后一块*/
/*----------------*/
void sixth_stage()
{
	compara9();
}
/*------------*/
/*恢复中块位置*/
/*------------*/
void seventh_stage()
{
	while(1)//恢复边块，角块的正确位置
	{
		if(graphsta[3][3]!=graphsta[4][4])//可以优化？？？？？？？？？？？
		{
			up_1();		rc.push(9);
		}
		else break;
	}
	while(1)//恢复边块，角块的正确位置
	{
		if(graphsta[5][3]!=graphsta[4][4])//可以优化？？？？？？？？？？？
		{
			down_1();	rc.push(11);
		}
		else break;
	}
	front_down();	rc.push(13);
	left_front();	rc.push(14);
	
	//判断采用哪种专家序列
	int i=0;
	while(1)
	{
		if(((graphsta[2][4]==graphsta[1][4])&&(graphsta[3][4]==graphsta[4][4]))||
			((graphsta[2][4]==graphsta[4][4])&&(graphsta[3][4]==graphsta[1][4])))//边块2在正确位置，有可能色向不对
		{
			i=1;	break;
		}
		if(((graphsta[5][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[7][4]))||
			((graphsta[5][4]==graphsta[7][4])&&(graphsta[6][4]==graphsta[4][4])))//边块4在正确位置，有可能色向不对
		{
			i=1;	break;
		}
		if(((graphsta[0][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[10][4]))||
			((graphsta[0][4]==graphsta[10][4])&&(graphsta[9][4]==graphsta[1][4])))//边块6在正确位置，有可能色向不对
		{
			i=1;	break;
		}
		if(((graphsta[8][4]==graphsta[7][4])&&(graphsta[11][4]==graphsta[10][4]))||
			((graphsta[8][4]==graphsta[10][4])&&(graphsta[11][4]==graphsta[7][4])))//边块10在正确位置，有可能色向不对
		{
			i=1;	break;
		}
		break;//四个边块都不在正确位置
	}
	//cout<<endl<<i;
	while(i==1)//如果有正确的边块，则将它挪到边块六的位置
	{
		if(((graphsta[0][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[10][4]))||
			((graphsta[0][4]==graphsta[10][4])&&(graphsta[9][4]==graphsta[1][4])))//挪到了正确位置
			break;
		else
		{
			front_down();	rc.push(13);
		}
	}
	if(i==1)//在有一块为正确边块的时候，判断用哪种专家序列
	{
		if(((graphsta[2][4]==graphsta[4][4])&&(graphsta[3][4]==graphsta[7][4]))||
			((graphsta[2][4]==graphsta[7][4])&&(graphsta[3][4]==graphsta[4][4])))//调用2
			compara10(2);
		
		if(((graphsta[5][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[1][4]))||
			((graphsta[5][4]==graphsta[1][4])&&(graphsta[6][4]==graphsta[4][4])))//调用1
			compara10(1);
	
	
	}
	if(i==0)//边块都不在正确位置的时候
	{
		int j=0;
		while(1)//通过查找边块的对应位置，来判断几次调用专家序列
		{
			if(((graphsta[3][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[4][4]))||
				((graphsta[2][4]==graphsta[4][4])&&(graphsta[5][4]==graphsta[4][4]))||
				((graphsta[3][4]==graphsta[4][4])&&(graphsta[5][4]==graphsta[4][4]))||
				((graphsta[2][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[4][4])))//判断对应位置是否在前面
			{
				j=1;	break;
			}
			if(((graphsta[3][4]==graphsta[1][4])&&(graphsta[0][4]==graphsta[1][4]))||
				((graphsta[2][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[1][4]))||
				((graphsta[0][4]==graphsta[1][4])&&(graphsta[2][4]==graphsta[1][4]))||
				((graphsta[3][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[1][4])))//判断对应位置是否在上面
			{
				j=1;	break;
			}
			if(((graphsta[0][4]==graphsta[10][4])&&(graphsta[11][4]==graphsta[10][4]))||
				((graphsta[9][4]==graphsta[10][4])&&(graphsta[8][4]==graphsta[10][4]))||
				((graphsta[9][4]==graphsta[10][4])&&(graphsta[11][4]==graphsta[10][4]))||
				((graphsta[0][4]==graphsta[10][4])&&(graphsta[8][4]==graphsta[10][4])))//判断对应位置是否在后面
			{
				j=1;	break;
			}
			if(((graphsta[11][4]==graphsta[7][4])&&(graphsta[6][4]==graphsta[7][4]))||
				((graphsta[8][4]==graphsta[7][4])&&(graphsta[5][4]==graphsta[7][4]))||
				((graphsta[5][4]==graphsta[7][4])&&(graphsta[11][4]==graphsta[7][4]))||
				((graphsta[6][4]==graphsta[7][4])&&(graphsta[8][4]==graphsta[7][4])))//判断对应位置是否在下面
			{
				j=1;	break;
			}
			break;
		}
		while(j==1)
		{
			if(((graphsta[3][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[4][4]))||
				((graphsta[2][4]==graphsta[4][4])&&(graphsta[5][4]==graphsta[4][4]))||
				((graphsta[3][4]==graphsta[4][4])&&(graphsta[5][4]==graphsta[4][4]))||
				((graphsta[2][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[4][4])))//将对应位置挪到前面
				break;
			else
			{
				front_down();	rc.push(13);
			}
		}
		if(j==1)//有边块在相互对应位置
			compara10(3);
		else
		{
			compara10(3);
			front_down();	rc.push(13);
			compara10(3);
		}
	}
}

/*--------------*/
/*恢复边块的色向*/
/*--------------*/
void eighth_stage()
{
	int i=0;
	//判断有几个边块的色向不正确
	if(graphsta[4][3]!=graphsta[4][4]) i++;
	if(graphsta[3][4]!=graphsta[4][4]) i++;
	if(graphsta[4][5]!=graphsta[4][4]) i++;
	if(graphsta[5][4]!=graphsta[4][4]) i++;
	if(graphsta[1][3]!=graphsta[1][4]) i++;
	if(graphsta[0][4]!=graphsta[1][4]) i++;
	if(graphsta[1][5]!=graphsta[1][4]) i++;
	if(graphsta[4][8]!=graphsta[4][7]) i++;
	if(graphsta[5][7]!=graphsta[4][7]) i++;
	if(graphsta[8][4]!=graphsta[7][4]) i++;
	if(graphsta[7][3]!=graphsta[7][4]) i++;
	if(graphsta[10][3]!=graphsta[10][4]) i++;
	
	int e=0;
	//有两个边块的色向不正确
	if(i==2)
	{
		//FU BU
		if((graphsta[2][4]!=graphsta[1][4])&&(graphsta[0][4]!=graphsta[1][4])&&e==0)//在顶面
		{
			compara11(1);		e=1;	
		}
		if((graphsta[9][4]!=graphsta[10][4])&&(graphsta[11][4]!=graphsta[10][4])&&e==0)//在后面
		{
			front_down();		rc.push(13);
			compara11(1);		e=1;
		}
		if((graphsta[6][4]!=graphsta[7][4])&&(graphsta[8][4]!=graphsta[7][4])&&e==0)//在下面
		{
			front_down();		rc.push(13);
			front_down();		rc.push(13);
			compara11(1);		e=1;
		}
		if((graphsta[3][4]!=graphsta[4][4])&&(graphsta[5][4]!=graphsta[4][4])&&e==0)//在前面
		{
			front_down();		rc.push(13);
			front_down();		rc.push(13);
			front_down();		rc.push(13);
			compara11(1);		e=1;
		}
		
		//FU BD
		if((graphsta[2][4]!=graphsta[1][4])&&(graphsta[11][4]!=graphsta[10][4])&&e==0)//副对角线
		{
			compara11(2);		e=1;
		}
		if((graphsta[0][4]!=graphsta[1][4])&&(graphsta[5][4]!=graphsta[4][4])&&e==0)//主对角线
		{
			front_down();		rc.push(13);
			compara11(2);		e=1;
		}		

		//FU RU
		int j=0;//用来判断极为特殊的情况
		while(e==0)
		{
			if((graphsta[2][4]!=graphsta[1][4])&&(graphsta[1][5]!=graphsta[1][4])&&j==0)//在上面
			{
				j=1;//用来判断极为特殊的情况
				compara11(3);	
			}
			if((graphsta[9][4]!=graphsta[10][4])&&(graphsta[10][5]!=graphsta[10][4])&&j==0)//在后面
			{
				j=1;//用来判断极为特殊的情况
				front_down();		rc.push(13);
				compara11(3);		
			}
			if((graphsta[8][4]!=graphsta[7][4])&&(graphsta[7][5]!=graphsta[7][4])&&j==0)//在下面
			{
				j=1;//用来判断极为特殊的情况
				front_down();		rc.push(13);
				front_down();		rc.push(13);
				compara11(3);		
			}
			if((graphsta[5][4]!=graphsta[4][4])&&(graphsta[4][5]!=graphsta[4][4])&&j==0)//在前面
			{
				j=1;//用来判断极为特殊的情况
				front_down();		rc.push(13);
				front_down();		rc.push(13);
				front_down();		rc.push(13);
				compara11(3);		
			}
			//以下这种情况是在解决10.txt运行完第七阶段遇到的，所以，经过各种考虑，得出以下的处理方法
			//这些方法也是通过转动魔方，使它能用 FU RU 来处理，由于是自己考虑的结果，可能会求不出解
			if(j==0)//处理几极为种特殊的情况
			{
				if((graphsta[0][4]!=graphsta[1][4])&&(graphsta[1][5]!=graphsta[1][4])&&j==0)//在上面
			{
				j=1;
				front_down();	rc.push(13);
				right_1();		rc.push(7);
				compara11(3);
			}
			if((graphsta[11][4]!=graphsta[10][4])&&(graphsta[10][5]!=graphsta[10][4])&&j==0)//在后面
			{
				j=1;
				front_down();	rc.push(13);
				front_down();	rc.push(13);
				right_1();		rc.push(7);
				compara11(3);
			}
			if((graphsta[9][4]!=graphsta[7][4])&&(graphsta[7][5]!=graphsta[7][4])&&j==0)//在下面
			{
				j=1;
				front_down();	rc.push(13);
				front_down();	rc.push(13);
				front_down();	rc.push(13);
				right_1();		rc.push(7);
				compara11(3);
			}
			if((graphsta[3][4]!=graphsta[4][4])&&(graphsta[4][5]!=graphsta[4][4])&&j==0)//在前面
			{
				j=1;
				right_1();		rc.push(7);
				compara11(3);
			}
			if(j==1)rc.push(8);//恢复特殊情况中执行的r+
			}
			if(j==0)//如果整个右面都没有的话，则说明另个不在正确位置的边块在左面
			{
				left_front();		rc.push(14);//挪到右面进行操作
				left_front();		rc.push(14);
				continue;
			}
			else	break;	
		}
	}
	
	//有四个色向不正确
	int j=0;
	if(i==4)
	{
		if((graphsta[3][4]!=graphsta[4][4])&&(graphsta[0][4]!=graphsta[1][4])&&
			(graphsta[11][4]!=graphsta[10][4])&&(graphsta[6][4]!=graphsta[5][4]))//FU,FD,BD和BU
		{
			j=1;
			compara11(5);
		}
		//一种很特殊的情况,很少遇到
		if(j==0)	
		{	
			if((graphsta[4][6]!=graphsta[4][7])||(graphsta[3][7]!=graphsta[4][7])||
				(graphsta[4][8]!=graphsta[4][7])||(graphsta[5][7]!=graphsta[4][7]))//说明在右边
			{
				while((graphsta[0][4]!=graphsta[1][4])&&(graphsta[9][4]!=graphsta[10][4]))//中间的三个边块找到可以正确解决的位置
				{
					front_down();
					rc.push(13);
				}
				int i=0;
				while(graphsta[1][5]==graphsta[2][5])//右面边块找到正确可以解决的位置
				{
					i++;//记录经过几次旋转才找到合适的位置,以便恢复了边块的颜色后让魔方回到正确的状态
					right_1();
					rc.push(7);
				}
				compara11(4);
				for(int z=0;z<i;z++)
				{
					right_2();
					rc.push(8);
				}
			}
			else //说明在左面
			{
				left_front();		rc.push(14);
				left_front();		rc.push(14);
				while((graphsta[0][4]!=graphsta[1][4])&&(graphsta[9][4]!=graphsta[10][4]))//中间的三个边块找到可以正确解决的位置
				{
					front_down();
					rc.push(13);
				}
				int i=0;
				while(graphsta[1][5]==graphsta[2][5])//面边块找到正确可以解决的位置
				{
					i++;
					right_1();
					rc.push(7);
				}
				compara11(4);
				for(int z=0;z<i;z++)
				{
					right_2();
					rc.push(8);
				}
			}
		}
	}
}