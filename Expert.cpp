#include "StdAfx.h"
#include "All_Function.h"

int solve1;				//�жϽǿ��λ��,����ȡ�������ת����

/*--------------------------*/
/*�ָ�ǰ���ĸ��ǿ��ר������*/
/*--------------------------*/
void expert1_1()		//�ǿ����һ�����
{
	up_1();		rc.push(9);
	back_1();	rc.push(3);
	up_2();		rc.push(10);
}

void expert1_2()		//�ǿ���ڶ������
{
	left_2();	rc.push(6);
	back_2();	rc.push(4);
	left_1();	rc.push(5);
}
	
void expert1_3(const char s[2])	//�ǿ�����������
{
	int i=0,j=0,z=0;
	up_1();		rc.push(9);
	back_2();	rc.push(4);
	up_2();		rc.push(10);
	while(1)				//ͨ������ת��,�ָ����ǿ���ĵ�һ�ֻ�ڶ������,�������һ����ʱ���һ����ʱ�붼û��
	{						//����׼λ�þ�˵������Ҫ��Ľǿ��ڶԽ��ߵ�λ��,���Ծ�����˳ʱ��任�����׼λ��
		if(j==0)//��ʱ��
		{
			back_2();
			i++;
		}
		//rc.push(4);
		if((graphsta[0][3]=='R'&&graphsta[3][0]==s[0]&&graphsta[9][3]==s[1])||  //�ǿ����һ�����
		(graphsta[0][3]=='R'&&graphsta[3][0]==s[1]&&graphsta[9][3]==s[0]))
		{
			z=1;
			//expert1_1();
			break;
		}
		if((graphsta[3][0]=='R'&&graphsta[0][3]==s[1]&&graphsta[9][3]==s[0])||  //�ǿ���ڶ������
		(graphsta[3][0]=='R'&&graphsta[0][3]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=2;
			//expert1_2();
			break;
		}
		if(i==1&&j==0)back_1();//�ָ���ת��ǰ��״̬
		if(i>=1)//˳ʱ��
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

void expert1_4(const char s[2])	//�ǿ�һ��һ�����
{
	int i=0,j=0,z=0;
	up_1();		rc.push(9);
	back_1();	rc.push(3);
	up_2();		rc.push(10);
	while(1)				//ͨ�������ת�����ָ����ǿ���ĵ�һ�ֻ�ڶ������
	{
		if(j==0)//��ʱ��
		{
			back_2();
			i++;
		}
		//rc.push(4);
		if((graphsta[0][3]=='R'&&graphsta[3][0]==s[1]&&graphsta[9][3]==s[0])||  //�ǿ����һ�����
		(graphsta[0][3]=='R'&&graphsta[3][0]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=1;
			//expert1_1();
			break;
		}
		if((graphsta[3][0]=='R'&&graphsta[0][3]==s[1]&&graphsta[9][3]==s[0])||  //�ǿ���ڶ������
		(graphsta[3][0]=='R'&&graphsta[0][3]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=2;
			//expert1_2();
			break;
		}
		if(i==1&&j==0)back_1();//�ָ���ת��ǰ��״̬
		if(i>=1)//˳ʱ��
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

void expert1_5(const char s[2])	//�ǿ�һ�ڶ������
{
	int i=0,j=0,z=0;
	left_2();	rc.push(6);
	back_2();	rc.push(4);
	left_1();	rc.push(5);
	while(1)				//ͨ�������ת�����ָ����ǿ���ĵ�һ�ֻ�ڶ������
	{
		if(j==0)//��ʱ��
		{
			back_2();
			i++;
		}
		//rc.push(4);
		if((graphsta[0][3]=='R'&&graphsta[3][0]==s[1]&&graphsta[9][3]==s[0])||  //�ǿ����һ�����
		(graphsta[0][3]=='R'&&graphsta[3][0]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=1;
			//expert1_1();
			break;
		}
		if((graphsta[3][0]=='R'&&graphsta[0][3]==s[1]&&graphsta[9][3]==s[0])||  //�ǿ���ڶ������
		(graphsta[3][0]=='R'&&graphsta[0][3]==s[0]&&graphsta[9][3]==s[1]))
		{
			z=2;
			//expert1_2();
			break;
		}
		if(i==1&&j==0)back_1();//�ָ���ת��ǰ��״̬
		if(i>=1)//˳ʱ��
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
/*�����������ת���У��ڻָ��߿�ɫ���ʱ��Ҫ�õ�*/
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
/*�ָ�R-W-G*/
/*---------*/
void compara1()
{
	solve_1=false;//�жϵ�ǰҪ�ҵĽǿ��Ƿ��Ѿ���������
	if(graphsta[2][3]=='W'&&graphsta[3][2]=='G'&&graphsta[3][3]=='R')		//��ǰ�ǿ��Ѿ��ڱ�׼λ��
	{
		solve1=0;//�����жϵ����ĸ�����
		solve_1=true;
	}
	//��ǰ�ǿ鲻��Ҫ��Ľǿ飬Ӧ�����������¼������
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='W'&&graphsta[9][3]=='G')||	//�ǿ����һ�����
		(graphsta[0][3]=='R'&&graphsta[3][0]=='G'&&graphsta[9][3]=='W'))
	{
		solve1=1;
		solve_1=true;
	}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='W'&&graphsta[9][3]=='G')||	 //�ǿ���ڶ������
		(graphsta[3][0]=='R'&&graphsta[0][3]=='G'&&graphsta[9][3]=='W'))
	{
		solve1=2;
		solve_1=true;	
	}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='W'&&graphsta[3][0]=='G')||
		(graphsta[9][3]=='R'&&graphsta[0][3]=='G'&&graphsta[3][0]=='W'))	//�ǿ�����������
	{
		solve1=3;
		solve_1=true;	
	}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='W'&&graphsta[3][3]=='G')||	//�ǿ�һ�ĵ�һ�����
		(graphsta[2][3]=='R'&&graphsta[3][2]=='G'&&graphsta[3][3]=='W'))
	{
		solve1=4;
		solve_1=true;	
	}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='W'&&graphsta[3][3]=='G')||	//�ǿ�һ�ĵڶ������
		(graphsta[3][2]=='R'&&graphsta[2][3]=='G'&&graphsta[3][3]=='W')) 
	{
		solve1=5;
		solve_1=true;	
	}
}

/*---------*/
/*�ָ�R-W-B*/
/*---------*/
void compara2()
{
	solve_1=false;
	if(graphsta[2][3]=='B'&&graphsta[3][2]=='W'&&graphsta[3][3]=='R')		//��ǰ�ǿ��Ѿ��ڱ�׼λ��
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=0;
			solve_1=true; 
		}
	//��ǰ�ǿ鲻��Ҫ��Ľǿ飬Ӧ�����������¼������
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='W'&&graphsta[9][3]=='B')||	//�ǿ����һ�����
		(graphsta[0][3]=='R'&&graphsta[3][0]=='B'&&graphsta[9][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=1;
			solve_1=true; 
		}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='W'&&graphsta[9][3]=='B')||	//�ǿ���ڶ������
		(graphsta[3][0]=='R'&&graphsta[0][3]=='B'&&graphsta[9][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G') 
		{
			solve1=2;
			solve_1=true; 
		}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='W'&&graphsta[3][0]=='B')||	//�ǿ�����������
		(graphsta[9][3]=='R'&&graphsta[0][3]=='B'&&graphsta[3][0]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=3;
			solve_1=true;  
		}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='W'&&graphsta[3][3]=='B')||	//�ǿ�һ�ĵ�һ�����
		(graphsta[2][3]=='R'&&graphsta[3][2]=='B'&&graphsta[3][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=4;
			solve_1=true;  
		}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='W'&&graphsta[3][3]=='B')||	//�ǿ�һ�ĵڶ������
		(graphsta[3][2]=='R'&&graphsta[2][3]=='B'&&graphsta[3][3]=='W'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='W'&&graphsta[6][3]=='G')
		{
			solve1=5;
			solve_1=true;  
		}
}

/*---------*/
/*�ָ�R-Y-B*/
/*---------*/
void compara3()
{
	solve_1=false;
	if(graphsta[2][3]=='Y'&&graphsta[3][2]=='B'&&graphsta[3][3]=='R')		//��ǰ�ǿ��Ѿ��ڱ�׼λ��
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=0;
				solve_1=true; 
			}
	//��ǰ�ǿ鲻��Ҫ��Ľǿ飬Ӧ�����������¼������
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='Y'&&graphsta[9][3]=='B')||	//�ǿ����һ�����
		(graphsta[0][3]=='R'&&graphsta[3][0]=='B'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=1;
				solve_1=true; 
			}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='Y'&&graphsta[9][3]=='B')||	//�ǿ���ڶ������
		(graphsta[3][0]=='R'&&graphsta[0][3]=='B'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W') 
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=2;
				solve_1=true; 
			}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='Y'&&graphsta[3][0]=='B')||	//�ǿ�����������
		(graphsta[9][3]=='R'&&graphsta[0][3]=='B'&&graphsta[3][0]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=3;
				solve_1=true; 
			}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='Y'&&graphsta[3][3]=='B')||	//�ǿ�һ�ĵ�һ�����
		(graphsta[2][3]=='R'&&graphsta[3][2]=='B'&&graphsta[3][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=4;
				solve_1=true;  
			}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='Y'&&graphsta[3][3]=='B')||	//�ǿ�һ�ĵڶ������
		(graphsta[3][2]=='R'&&graphsta[2][3]=='B'&&graphsta[3][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='B'&&graphsta[6][3]=='W')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='G'&&graphsta[6][5]=='W')
			{
				solve1=5;
				solve_1=true;  
			}
}

/*---------*/
/*�ָ�R-Y-G*/
/*---------*/
void compara4()
{
	solve_1=false;
	if(graphsta[2][3]=='G'&&graphsta[3][2]=='Y'&&graphsta[3][3]=='R')		//��ǰ�ǿ��Ѿ��ڱ�׼λ��
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=0;
					solve_1=true; 
				}
	//��ǰ�ǿ鲻��Ҫ��Ľǿ飬Ӧ�����������¼������
	if((graphsta[0][3]=='R'&&graphsta[3][0]=='Y'&&graphsta[9][3]=='G')||	//�ǿ����һ�����
		(graphsta[0][3]=='R'&&graphsta[3][0]=='G'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=1;
					solve_1=true; 
				}
	if((graphsta[3][0]=='R'&&graphsta[0][3]=='Y'&&graphsta[9][3]=='G')||	//�ǿ���ڶ������
		(graphsta[3][0]=='R'&&graphsta[0][3]=='G'&&graphsta[9][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B') 
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=2;
					solve_1=true; 
				}
	if((graphsta[9][3]=='R'&&graphsta[0][3]=='Y'&&graphsta[3][0]=='G')||	//�ǿ�����������
		(graphsta[9][3]=='R'&&graphsta[0][3]=='G'&&graphsta[3][0]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=3;
					solve_1=true;  
				}
	if((graphsta[2][3]=='R'&&graphsta[3][2]=='Y'&&graphsta[3][3]=='G')||	//�ǿ�һ�ĵ�һ�����
		(graphsta[2][3]=='R'&&graphsta[3][2]=='G'&&graphsta[3][3]=='Y'))
		if(graphsta[5][3]=='R'&&graphsta[5][2]=='Y'&&graphsta[6][3]=='B')
			if(graphsta[5][5]=='R'&&graphsta[5][6]=='W'&&graphsta[6][5]=='B')
				if(graphsta[3][5]=='R'&&graphsta[3][6]=='W'&&graphsta[2][5]=='G')
				{
					solve1=4;
					solve_1=true;  
				}
	if((graphsta[3][2]=='R'&&graphsta[2][3]=='Y'&&graphsta[3][3]=='G')||	//�ǿ�һ�ĵڶ������
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
/*�ָ��ڵ�ǰ״̬�µ�����ǿ����ϵ���ɫר������*/
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
/*�ָ��ڵ�ǰ״̬��ħ���Ͻǿ��λ�õ�ר������*/
/*------------------------------------------*/
void compara6(int *p)
{
	int i=0,j=0;
	//ͳ���Ͻǿ��ɫ�ɶԵĸ���
	if(graphsta[3][0]==graphsta[3][2])i++;
	if(graphsta[3][3]==graphsta[3][5])i++;
	if(graphsta[3][6]==graphsta[3][8])i++;
	if(graphsta[9][3]==graphsta[9][5])i++;
	//ͳ���½ǿ��ɫ�ɶԵĸ���
	if(graphsta[5][0]==graphsta[5][2])j++;
	if(graphsta[5][3]==graphsta[5][5])j++;
	if(graphsta[5][6]==graphsta[5][8])j++;
	if(graphsta[11][3]==graphsta[11][5])j++;
	//ͨ���ж�i,j�ĸ�������ȡ�����ר������
	if(i==0&&j==0)									//�Ͻ��ޣ��½���
	{
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		front_1();		rc.push(1);
		front_1();		rc.push(1);
		right_1();		rc.push(7);
		right_1();		rc.push(7);
		*p=1;
	}
	if(i==0&&j==1)									//�Ͻ��ޣ��½�һ��
	{
		while(graphsta[5][3]!=graphsta[5][5])		//�½ǳɶԵİڵ�ǰ��
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
	if(i==1&&j==1)									//�Ͻ�һ�ԣ��½�һ��
	{
		while(graphsta[3][0]!=graphsta[3][2])		//�������Զ��ŵ�����
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
	if(i==4&&j==1)									//�Ͻ��Ķԣ��½�һ��
	{
		while(graphsta[11][3]!=graphsta[11][5])		//�½ǳɶԵİڵ�����
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
	if(i==0&&j==4)									//�Ͻ��ޣ��½��Ķ�
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
	if(i==4&&j==4)//�ϽǺ��½��Ѿ�ΪҪ��״̬
		*p=1;
}

/*--------------------------*/
/*�ָ����������߿��ר������*/
/*--------------------------*/
void compara7(int *p,const char s[2])
{
	while(1)
	{
		if(graphsta[2][4]==s[0]&&graphsta[3][4]==s[1])		//�Ѿ�ΪҪ���״̬
		{	
			*p=1;
			break;
		}
		while(graphsta[3][3]!=s[1])					//��ǰ�ı߿鲻��Ҫ���
		{
			up_1();		rc.push(9);
		}
		while(1)
		{
			if(graphsta[2][4]==s[0]&&graphsta[3][4]==s[1])	//�Ѿ�ΪҪ���״̬
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
			//����Ϊ���������Ҫ��ı߿��ڶ���
			if(graphsta[3][4]==s[0]&&graphsta[2][4]==s[1])	//Ҫ����Ѿ�����ȷλ�ã�ֻ��ɫ�򲻶ԣ�����BR-UF��������
			{
				front_1();		rc.push(1);
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);
				
				while(graphsta[3][3]!=s[1])					//��ǰ�ı߿鲻��Ҫ���
				{
					up_1();		rc.push(9); 
				}
				continue;
			}
			if((graphsta[1][3]==s[0]&&graphsta[3][1]==s[1])||(graphsta[1][3]==s[1]&&graphsta[3][1]==s[0]))//������
			{
				up_2();			rc.push(10);				//ת��ǰ��
				
				front_1();		rc.push(1);					//����
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);
				
				while(graphsta[3][3]!=s[1])					//��ǰ�ı߿鲻��Ҫ���
				{
					up_1();		rc.push(9); 
				}
				continue;
			}
			if((graphsta[0][4]==s[0]&&graphsta[9][4]==s[1])||(graphsta[0][4]==s[1]&&graphsta[9][4]==s[0]))//�ں���
			{
				up_2();			rc.push(10);
				up_2();			rc.push(10);

				front_1();		rc.push(1);					//����
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);

				while(graphsta[3][3]!=s[1])					//��ǰ�ı߿鲻��Ҫ���
				{
					up_1();		rc.push(9);
				}
				continue;
			}
			if((graphsta[1][5]==s[0]&&graphsta[3][7]==s[1])||(graphsta[1][5]==s[1]&&graphsta[3][7]==s[0]))//������
			{
				up_1();			rc.push(9);

				front_1();		rc.push(1);					//����
				up_2();			rc.push(10);
				down_1();		rc.push(11);
				right_2();		rc.push(8);

				while(graphsta[3][3]!=s[1])					//��ǰ�ı߿鲻��Ҫ���
				{
					up_1();		rc.push(9);
				}
				continue;
			}
			up_1();				//�ڶ�������
			rc.push(9);
			left_front();
			rc.push(14);
		}		
	}
}

/*--------------------------*/
/*�ָ������ĸ��߿��ר������*/
/*--------------------------*/
void compara8(int *p,const char s[2])
{
	while(1)
	{
		if(graphsta[6][4]==s[0]&&graphsta[5][4]==s[1])		//�Ѿ�ΪҪ���״̬
		{	
			*p=1;
			break;
		}
		while(graphsta[5][3]!=s[1])							//��ǰ�ı߿鲻��Ҫ���"A"
		{
			down_1();		rc.push(11); 
		}
		while(1)
		{
			if(graphsta[6][4]==s[0]&&graphsta[5][4]==s[1])	//����"A"�ĵ����Ѿ�ΪҪ���״̬
			{	
				*p=1;
				break;
			}
			/*while(graphsta[5][3]!=s[1])						//��ǰ�ĵױ߿鲻��Ҫ��ģ������Ż�
			{
				down_1();		rc.push(11); 
			}*/
			int i=0;
			while(graphsta[2][3]==graphsta[2][4])			//�����Ҷ��������Ż�
			{
				up_1();			rc.push(9);
				i++;
				if(i==4)									//����û�ж�
					break;								
			}
			
			//ר������
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
			//�������
			if(graphsta[6][4]==s[1]&&graphsta[5][4]==s[0])	//�Ѿ�����ȷλ�ã�ֻ��ɫ�򲻶ԣ�������������������
			{
				front_2();		rc.push(2);					//��һ��ר�����У�����
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//��ǰ�ĵױ߿鲻��Ҫ��ģ������Ż�
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			if((graphsta[5][1]==s[0]&&graphsta[7][3]==s[1])||(graphsta[5][1]==s[1]&&graphsta[7][3]==s[0]))//������
			{
				down_1();		rc.push(11);				//ת��ǰ��
				
				front_2();		rc.push(2);					//��һ��ר�����У�����
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//��ǰ�ĵױ߿鲻��Ҫ��ģ������Ż�
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			if((graphsta[5][7]==s[0]&&graphsta[7][5]==s[1])||(graphsta[5][7]==s[1]&&graphsta[7][5]==s[0]))//������
			{
				down_2();		rc.push(12);

				front_2();		rc.push(2);					//��һ��ר�����У�����
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//��ǰ�ĵױ߿鲻��Ҫ��ģ������Ż�
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			if((graphsta[8][4]==s[0]&&graphsta[11][4]==s[1])||(graphsta[8][4]==s[1]&&graphsta[11][4]==s[0]))//�ں���
			{
				down_1();		rc.push(11);
				down_1();		rc.push(11);

				front_2();		rc.push(2);					//��һ��ר�����У�����
				down_2();		rc.push(12);
				up_1();			rc.push(9);
				left_1();		rc.push(5);
				
				while(graphsta[5][3]!=s[1])					//��ǰ�ĵױ߿鲻��Ҫ��ģ������Ż�
				{
					down_1();		rc.push(11); 
				}
				continue;
			}
			//�п���ʹ���������ѭ����״��,����ħ����������״̬��ʱ�򻹲�֪��ν��
			if(graphsta[2][4]==s[0]&&graphsta[3][4]==s[1])	//�����棬��ɫ�򲻶ԣ�������ר������????????????????????
			{
				front_2();		rc.push(2);					//��һ��ר�����У�����
				down_1();		rc.push(11);
				up_2();			rc.push(10);
				right_1();		rc.push(7);

				while(graphsta[5][3]!=s[1])					//��ǰ�ĵױ߿鲻��Ҫ��ģ������Ż�
				{
					down_1();		rc.push(11); 
				}
				continue;
			}

			up_1();				//�ڶ�������,��һ��������Ҫ��ı߿鲢���ڿ��Խ����λ����
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
/*���������һ���ר������*/
/*--------------------------*/
void compara9()
{
	int i=0;
	while(1)
	{
		if(graphsta[0][4]=='R'&&graphsta[1][3]=='R'&&graphsta[1][5]=='R'&&graphsta[2][4]=='R')//�Ѿ�Ϊ��׼״̬
			break;
		while((graphsta[3][3]==graphsta[3][4])&&(graphsta[2][3]==graphsta[2][4]))		//�ҵ�����Ķ�
		{
			up_1();		rc.push(9);//cout<<"1";
		}
		//rc.push(1);rc.push(12);rc.push(9);rc.push(6);
		while(1)
		{
			if(graphsta[4][8]=='R')//���һ�����ڵ�λ��
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
			if(graphsta[4][0]=='R')//���һ�����ڵ�λ��
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
			//�������
			if(graphsta[3][4]=='R')					//����ȷλ�ã�ֻ��ɫ�򲻶�???????????????????
			{
				i=1;
				break;								//��ʱû���ҵ����ʵ����лָ�
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
/*�ָ��п�λ�õ�ר������*/
/*----------------------*/
void compara10(const int k)
{
	if(k==1)	//�߿�UF-DF-BD-UF
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
	if(k==2)	//�߿�UF-BD-DF-UF
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
	if(k==3)	//�߿�UF-DF,UB-DB
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
/*�ָ��߿�ɫ���ר������*/
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
/*��ԭħ��ǰ��ĵ��ĸ��ǿ�*/
/*------------------------*/
void first_stage()
{
	front_down();
	rc.push(13);
	char s[2];

	//�ָ�R-W-G
	s[0]='W'; s[1]='G';
	p=compara1;// �ҵ��������
	bfs_mf();//�����ʺ�������λ��
	if(solve1!=0)
		decide(s); 
	front_2();
	rc.push(2);
	
	//�ָ�R-W-B
	s[0]='W'; s[1]='B';
	p=compara2;
	bfs_mf();
	if(solve1!=0)
		decide(s);
	front_2();
	rc.push(2);

	//�ָ�R-Y-B
	s[0]='Y'; s[1]='B';
	p=compara3;
	bfs_mf();
	if(solve1!=0)
		decide(s);
	front_2();
	rc.push(2);

	//�ָ�R-G-Y
	s[0]='Y'; s[1]='G';
	p=compara4;
	bfs_mf();
	if(solve1!=0)
		decide(s);
	front_2();
	rc.push(2);
}

/*------------------------------------*/
/*�ָ��ڵ�ǰ״̬�µ�����ǿ����ϵ���ɫ*/
/*------------------------------------*/
void second_stage()
{
	int k=0;
	front_down();//������ʱ��Ϊħ��������Ǹ���Ų��������
	rc.push(13);
	while(k==0)
	{	
		compara5(&k);
		if(k==0)	//���������ǰ���λ��
		{
			left_front();
			rc.push(14);
		}
	}
}

/*--------------------------------*/
/*�ָ��ڵ�ǰ״̬��ħ���Ͻǿ��λ��*/
/*--------------------------------*/
void third_stage()
{
	int k=0;
	while(k==0)
	{
		compara6(&k);
		if(k==0)	//��������͵����λ��
		{
			front_down();
			rc.push(13);
			front_down();
			rc.push(13);
		}
	}
}

/*----------------*/
/*�ָ����������߿�*/
/*----------------*/
void forth_stage()
{
	while(graphsta[1][4]!='R')	//����ɫ����Ϊ������������Ȼ���������ⲽ�裬���������ı�д
	{
		front_down();		rc.push(13);
	}
	char s[2];					//��¼Ҫ�ָ��ı߿���ɫ��Ҳ��������ⲽ�裬��������������ͬ��
	int k=0;
	//�Ȼָ�R-Y�߿�
	s[0]='R'; s[1]='Y';
	while(k==0)
	{
		compara7(&k,s);
	}
	//�ָ�R-B����������ĳ�������Ż���������Ĳ���������Ҫ�ǳ���R-B������ȷλ�ã���Ӧ��������������������
	k=0;
	s[0]='R'; s[1]='B';
	while(k==0)
	{
		compara7(&k,s);
	}
	//�ָ�R-W
	k=0;
	s[0]='R'; s[1]='W';
	while(k==0)
	{
		compara7(&k,s);
	}
	//�ָ�R-G
	k=0;
	s[0]='R'; s[1]='G';
	while(k==0)
	{
		compara7(&k,s);
	}
}

/*------------------*/
/*�ָ�ħ������ı߿�*/
/*------------------*/
void fifth_stage()
{
	char s[2];
	int k=0;
	while(1)//�е�ʱ�������ĸ�����������Ҳ�п�����һ��û�лص���ȷ��λ�ã����������ڶ�������ȷλ����ɫ�򲻶�ʱ�Ĵ������в���
	{
		if((graphsta[5][0]==graphsta[5][1])&&(graphsta[5][3]==graphsta[5][4])&&
			(graphsta[5][7]==graphsta[5][6])&&(graphsta[11][3]==graphsta[11][4]))
			break;
		//�ָ�O-Y
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
		//�ڶ���ִ��������У���֤������׶ι���ħ���ĵ���Ϊ��׼״̬
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
/*�ָ��������һ��*/
/*----------------*/
void sixth_stage()
{
	compara9();
}
/*------------*/
/*�ָ��п�λ��*/
/*------------*/
void seventh_stage()
{
	while(1)//�ָ��߿飬�ǿ����ȷλ��
	{
		if(graphsta[3][3]!=graphsta[4][4])//�����Ż�����������������������
		{
			up_1();		rc.push(9);
		}
		else break;
	}
	while(1)//�ָ��߿飬�ǿ����ȷλ��
	{
		if(graphsta[5][3]!=graphsta[4][4])//�����Ż�����������������������
		{
			down_1();	rc.push(11);
		}
		else break;
	}
	front_down();	rc.push(13);
	left_front();	rc.push(14);
	
	//�жϲ�������ר������
	int i=0;
	while(1)
	{
		if(((graphsta[2][4]==graphsta[1][4])&&(graphsta[3][4]==graphsta[4][4]))||
			((graphsta[2][4]==graphsta[4][4])&&(graphsta[3][4]==graphsta[1][4])))//�߿�2����ȷλ�ã��п���ɫ�򲻶�
		{
			i=1;	break;
		}
		if(((graphsta[5][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[7][4]))||
			((graphsta[5][4]==graphsta[7][4])&&(graphsta[6][4]==graphsta[4][4])))//�߿�4����ȷλ�ã��п���ɫ�򲻶�
		{
			i=1;	break;
		}
		if(((graphsta[0][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[10][4]))||
			((graphsta[0][4]==graphsta[10][4])&&(graphsta[9][4]==graphsta[1][4])))//�߿�6����ȷλ�ã��п���ɫ�򲻶�
		{
			i=1;	break;
		}
		if(((graphsta[8][4]==graphsta[7][4])&&(graphsta[11][4]==graphsta[10][4]))||
			((graphsta[8][4]==graphsta[10][4])&&(graphsta[11][4]==graphsta[7][4])))//�߿�10����ȷλ�ã��п���ɫ�򲻶�
		{
			i=1;	break;
		}
		break;//�ĸ��߿鶼������ȷλ��
	}
	//cout<<endl<<i;
	while(i==1)//�������ȷ�ı߿飬����Ų���߿�����λ��
	{
		if(((graphsta[0][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[10][4]))||
			((graphsta[0][4]==graphsta[10][4])&&(graphsta[9][4]==graphsta[1][4])))//Ų������ȷλ��
			break;
		else
		{
			front_down();	rc.push(13);
		}
	}
	if(i==1)//����һ��Ϊ��ȷ�߿��ʱ���ж�������ר������
	{
		if(((graphsta[2][4]==graphsta[4][4])&&(graphsta[3][4]==graphsta[7][4]))||
			((graphsta[2][4]==graphsta[7][4])&&(graphsta[3][4]==graphsta[4][4])))//����2
			compara10(2);
		
		if(((graphsta[5][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[1][4]))||
			((graphsta[5][4]==graphsta[1][4])&&(graphsta[6][4]==graphsta[4][4])))//����1
			compara10(1);
	
	
	}
	if(i==0)//�߿鶼������ȷλ�õ�ʱ��
	{
		int j=0;
		while(1)//ͨ�����ұ߿�Ķ�Ӧλ�ã����жϼ��ε���ר������
		{
			if(((graphsta[3][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[4][4]))||
				((graphsta[2][4]==graphsta[4][4])&&(graphsta[5][4]==graphsta[4][4]))||
				((graphsta[3][4]==graphsta[4][4])&&(graphsta[5][4]==graphsta[4][4]))||
				((graphsta[2][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[4][4])))//�ж϶�Ӧλ���Ƿ���ǰ��
			{
				j=1;	break;
			}
			if(((graphsta[3][4]==graphsta[1][4])&&(graphsta[0][4]==graphsta[1][4]))||
				((graphsta[2][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[1][4]))||
				((graphsta[0][4]==graphsta[1][4])&&(graphsta[2][4]==graphsta[1][4]))||
				((graphsta[3][4]==graphsta[1][4])&&(graphsta[9][4]==graphsta[1][4])))//�ж϶�Ӧλ���Ƿ�������
			{
				j=1;	break;
			}
			if(((graphsta[0][4]==graphsta[10][4])&&(graphsta[11][4]==graphsta[10][4]))||
				((graphsta[9][4]==graphsta[10][4])&&(graphsta[8][4]==graphsta[10][4]))||
				((graphsta[9][4]==graphsta[10][4])&&(graphsta[11][4]==graphsta[10][4]))||
				((graphsta[0][4]==graphsta[10][4])&&(graphsta[8][4]==graphsta[10][4])))//�ж϶�Ӧλ���Ƿ��ں���
			{
				j=1;	break;
			}
			if(((graphsta[11][4]==graphsta[7][4])&&(graphsta[6][4]==graphsta[7][4]))||
				((graphsta[8][4]==graphsta[7][4])&&(graphsta[5][4]==graphsta[7][4]))||
				((graphsta[5][4]==graphsta[7][4])&&(graphsta[11][4]==graphsta[7][4]))||
				((graphsta[6][4]==graphsta[7][4])&&(graphsta[8][4]==graphsta[7][4])))//�ж϶�Ӧλ���Ƿ�������
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
				((graphsta[2][4]==graphsta[4][4])&&(graphsta[6][4]==graphsta[4][4])))//����Ӧλ��Ų��ǰ��
				break;
			else
			{
				front_down();	rc.push(13);
			}
		}
		if(j==1)//�б߿����໥��Ӧλ��
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
/*�ָ��߿��ɫ��*/
/*--------------*/
void eighth_stage()
{
	int i=0;
	//�ж��м����߿��ɫ����ȷ
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
	//�������߿��ɫ����ȷ
	if(i==2)
	{
		//FU BU
		if((graphsta[2][4]!=graphsta[1][4])&&(graphsta[0][4]!=graphsta[1][4])&&e==0)//�ڶ���
		{
			compara11(1);		e=1;	
		}
		if((graphsta[9][4]!=graphsta[10][4])&&(graphsta[11][4]!=graphsta[10][4])&&e==0)//�ں���
		{
			front_down();		rc.push(13);
			compara11(1);		e=1;
		}
		if((graphsta[6][4]!=graphsta[7][4])&&(graphsta[8][4]!=graphsta[7][4])&&e==0)//������
		{
			front_down();		rc.push(13);
			front_down();		rc.push(13);
			compara11(1);		e=1;
		}
		if((graphsta[3][4]!=graphsta[4][4])&&(graphsta[5][4]!=graphsta[4][4])&&e==0)//��ǰ��
		{
			front_down();		rc.push(13);
			front_down();		rc.push(13);
			front_down();		rc.push(13);
			compara11(1);		e=1;
		}
		
		//FU BD
		if((graphsta[2][4]!=graphsta[1][4])&&(graphsta[11][4]!=graphsta[10][4])&&e==0)//���Խ���
		{
			compara11(2);		e=1;
		}
		if((graphsta[0][4]!=graphsta[1][4])&&(graphsta[5][4]!=graphsta[4][4])&&e==0)//���Խ���
		{
			front_down();		rc.push(13);
			compara11(2);		e=1;
		}		

		//FU RU
		int j=0;//�����жϼ�Ϊ��������
		while(e==0)
		{
			if((graphsta[2][4]!=graphsta[1][4])&&(graphsta[1][5]!=graphsta[1][4])&&j==0)//������
			{
				j=1;//�����жϼ�Ϊ��������
				compara11(3);	
			}
			if((graphsta[9][4]!=graphsta[10][4])&&(graphsta[10][5]!=graphsta[10][4])&&j==0)//�ں���
			{
				j=1;//�����жϼ�Ϊ��������
				front_down();		rc.push(13);
				compara11(3);		
			}
			if((graphsta[8][4]!=graphsta[7][4])&&(graphsta[7][5]!=graphsta[7][4])&&j==0)//������
			{
				j=1;//�����жϼ�Ϊ��������
				front_down();		rc.push(13);
				front_down();		rc.push(13);
				compara11(3);		
			}
			if((graphsta[5][4]!=graphsta[4][4])&&(graphsta[4][5]!=graphsta[4][4])&&j==0)//��ǰ��
			{
				j=1;//�����жϼ�Ϊ��������
				front_down();		rc.push(13);
				front_down();		rc.push(13);
				front_down();		rc.push(13);
				compara11(3);		
			}
			//��������������ڽ��10.txt��������߽׶������ģ����ԣ��������ֿ��ǣ��ó����µĴ�����
			//��Щ����Ҳ��ͨ��ת��ħ����ʹ������ FU RU �������������Լ����ǵĽ�������ܻ��󲻳���
			if(j==0)//������Ϊ����������
			{
				if((graphsta[0][4]!=graphsta[1][4])&&(graphsta[1][5]!=graphsta[1][4])&&j==0)//������
			{
				j=1;
				front_down();	rc.push(13);
				right_1();		rc.push(7);
				compara11(3);
			}
			if((graphsta[11][4]!=graphsta[10][4])&&(graphsta[10][5]!=graphsta[10][4])&&j==0)//�ں���
			{
				j=1;
				front_down();	rc.push(13);
				front_down();	rc.push(13);
				right_1();		rc.push(7);
				compara11(3);
			}
			if((graphsta[9][4]!=graphsta[7][4])&&(graphsta[7][5]!=graphsta[7][4])&&j==0)//������
			{
				j=1;
				front_down();	rc.push(13);
				front_down();	rc.push(13);
				front_down();	rc.push(13);
				right_1();		rc.push(7);
				compara11(3);
			}
			if((graphsta[3][4]!=graphsta[4][4])&&(graphsta[4][5]!=graphsta[4][4])&&j==0)//��ǰ��
			{
				j=1;
				right_1();		rc.push(7);
				compara11(3);
			}
			if(j==1)rc.push(8);//�ָ����������ִ�е�r+
			}
			if(j==0)//����������涼û�еĻ�����˵�����������ȷλ�õı߿�������
			{
				left_front();		rc.push(14);//Ų��������в���
				left_front();		rc.push(14);
				continue;
			}
			else	break;	
		}
	}
	
	//���ĸ�ɫ����ȷ
	int j=0;
	if(i==4)
	{
		if((graphsta[3][4]!=graphsta[4][4])&&(graphsta[0][4]!=graphsta[1][4])&&
			(graphsta[11][4]!=graphsta[10][4])&&(graphsta[6][4]!=graphsta[5][4]))//FU,FD,BD��BU
		{
			j=1;
			compara11(5);
		}
		//һ�ֺ���������,��������
		if(j==0)	
		{	
			if((graphsta[4][6]!=graphsta[4][7])||(graphsta[3][7]!=graphsta[4][7])||
				(graphsta[4][8]!=graphsta[4][7])||(graphsta[5][7]!=graphsta[4][7]))//˵�����ұ�
			{
				while((graphsta[0][4]!=graphsta[1][4])&&(graphsta[9][4]!=graphsta[10][4]))//�м�������߿��ҵ�������ȷ�����λ��
				{
					front_down();
					rc.push(13);
				}
				int i=0;
				while(graphsta[1][5]==graphsta[2][5])//����߿��ҵ���ȷ���Խ����λ��
				{
					i++;//��¼����������ת���ҵ����ʵ�λ��,�Ա�ָ��˱߿����ɫ����ħ���ص���ȷ��״̬
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
			else //˵��������
			{
				left_front();		rc.push(14);
				left_front();		rc.push(14);
				while((graphsta[0][4]!=graphsta[1][4])&&(graphsta[9][4]!=graphsta[10][4]))//�м�������߿��ҵ�������ȷ�����λ��
				{
					front_down();
					rc.push(13);
				}
				int i=0;
				while(graphsta[1][5]==graphsta[2][5])//��߿��ҵ���ȷ���Խ����λ��
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