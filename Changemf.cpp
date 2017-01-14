/*-------------------------*/
/*  魔方各面旋转后的状态   */
/*-------------------------*/
#include "StdAfx.h"
#include"All_Function.h"


/*----------------------*/
/*实现前面顺时针旋转操作*/
/*----------------------*/

void front_1()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							

	/*对角块操作*/
	
	//存储2到临时变量
	temporary0[0]=graphsta[3][5];	        
	temporary0[1]=graphsta[3][6];	        
	temporary0[2]=graphsta[2][5];			
	
	//1->2
	graphsta[3][5]=graphsta[3][3];	
	graphsta[3][6]=graphsta[2][3];	
	graphsta[2][5]=graphsta[3][2];	
	
	//4->1
	graphsta[3][3]=graphsta[5][3];	
	graphsta[2][3]=graphsta[5][2];	
	graphsta[3][2]=graphsta[6][3];	
	
	//3->4
	graphsta[5][3]=graphsta[5][5];	
	graphsta[5][2]=graphsta[6][5];	
	graphsta[6][3]=graphsta[5][6];	
	
	//2->3
	graphsta[5][5]=temporary0[0];	        
	graphsta[6][5]=temporary0[1];	        
	graphsta[5][6]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储2到临时变量
	temporary1[0]=graphsta[3][4];	        
	temporary1[1]=graphsta[2][4];			
	
	//1->2
	graphsta[3][4]=graphsta[4][3];	
	graphsta[2][4]=graphsta[4][2];	
	
	//4->1
	graphsta[4][3]=graphsta[5][4];	
	graphsta[4][2]=graphsta[6][4];	
	
	//3->4
	graphsta[5][4]=graphsta[4][5];	
	graphsta[6][4]=graphsta[4][6];	
	
	//2->3
	graphsta[4][5]=temporary1[0];	        
	graphsta[4][6]=temporary1[1];			
}

/*----------------------*/
/*实现前面逆时针旋转操作*/
/*----------------------*/

void front_2()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储2到临时变量
	temporary0[0]=graphsta[3][5];			
	temporary0[1]=graphsta[3][6];			
	temporary0[2]=graphsta[2][5];			
	
	//3->2
	graphsta[3][5]=graphsta[5][5];	
	graphsta[3][6]=graphsta[6][5];	
	graphsta[2][5]=graphsta[5][6];	
	
	//4->3
	graphsta[5][5]=graphsta[5][3];	
	graphsta[6][5]=graphsta[5][2];	
	graphsta[5][6]=graphsta[6][3];	
	
	//1->4
	graphsta[5][3]=graphsta[3][3];	
	graphsta[5][2]=graphsta[2][3];	
	graphsta[6][3]=graphsta[3][2];	
	
	//2->1
	graphsta[3][3]=temporary0[0];			
	graphsta[2][3]=temporary0[1];			
	graphsta[3][2]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储2到临时变量
	temporary1[0]=graphsta[3][4];			
	temporary1[1]=graphsta[2][4];			
	
	//3->2
	graphsta[3][4]=graphsta[4][5];	
	graphsta[2][4]=graphsta[4][6];	
	
	//4->3
	graphsta[4][5]=graphsta[5][4];	
	graphsta[4][6]=graphsta[6][4];	
	
	//1->4
	graphsta[5][4]=graphsta[4][3];	
	graphsta[6][4]=graphsta[4][2];	
	
	//2->1
	graphsta[4][3]=temporary1[0];			
	graphsta[4][2]=temporary1[1];			
}

/*----------------------*/	
/*实现后面顺时针旋转操作*/
/*----------------------*/

void back_2()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储6到临时变量
	temporary0[0]=graphsta[9][5];			
	temporary0[1]=graphsta[3][8];			
	temporary0[2]=graphsta[0][5];			
	
	//5->6
	graphsta[9][5]=graphsta[9][3];	
	graphsta[3][8]=graphsta[0][3];	
	graphsta[0][5]=graphsta[3][0];	
	
	//8->5
	graphsta[9][3]=graphsta[11][3];	
	graphsta[0][3]=graphsta[5][0];	
	graphsta[3][0]=graphsta[8][3];	
	
	//7->4
	graphsta[11][3]=graphsta[11][5];	
	graphsta[5][0]=graphsta[8][5];	
	graphsta[8][3]=graphsta[5][8];	
	
	//6->7
	graphsta[11][5]=temporary0[0];			
	graphsta[8][5]=temporary0[1];			
	graphsta[5][8]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储6到临时变量
	temporary1[0]=graphsta[9][4];			
	temporary1[1]=graphsta[0][4];			
	
	//12->6
	graphsta[9][4]=graphsta[10][3];	
	graphsta[0][4]=graphsta[4][0];	
	
	//10->12
	graphsta[10][3]=graphsta[11][4];	
	graphsta[4][0]=graphsta[8][4];	
	
	//8->10
	graphsta[11][4]=graphsta[10][5];	
	graphsta[8][4]=graphsta[4][8];	
	
	//6->8
	graphsta[10][5]=temporary1[0];			
	graphsta[4][8]=temporary1[1];			
}

/*----------------------*/
/*实现后面逆时针旋转操作*/
/*----------------------*/

void back_1()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储6到临时变量
	temporary0[0]=graphsta[9][5];			
	temporary0[1]=graphsta[3][8];			
	temporary0[2]=graphsta[0][5];			
	
	//7->6
	graphsta[9][5]=graphsta[11][5];	
	graphsta[3][8]=graphsta[8][5];	
	graphsta[0][5]=graphsta[5][8];	
	
	//8->7
	graphsta[11][5]=graphsta[11][3];	
	graphsta[8][5]=graphsta[5][0];	
	graphsta[5][8]=graphsta[8][3];	
	
	//5->8
	graphsta[11][3]=graphsta[9][3];	
	graphsta[5][0]=graphsta[0][3];	
	graphsta[8][3]=graphsta[3][0];	
	
	//6->5
	graphsta[9][3]=temporary0[0];			
	graphsta[0][3]=temporary0[1];			
	graphsta[3][0]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储6到临时变量
	temporary1[0]=graphsta[9][4];			
	temporary1[1]=graphsta[0][4];			
	
	//8->6
	graphsta[9][4]=graphsta[10][5];	
	graphsta[0][4]=graphsta[4][8];	
	
	//10->8
	graphsta[10][5]=graphsta[11][4];	
	graphsta[4][8]=graphsta[8][4];	
	
	//12->10
	graphsta[11][4]=graphsta[10][3];	
	graphsta[8][4]=graphsta[4][0];	
	
	//6->12
	graphsta[10][3]=temporary1[0];			
	graphsta[4][0]=temporary1[1];			
}

/*----------------------*/
/*实现上面顺时针旋转操作*/
/*----------------------*/

void up_1()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储2到临时变量
	temporary0[0]=graphsta[3][5];			
	temporary0[1]=graphsta[3][6];			
	temporary0[2]=graphsta[2][5];			
	
	//6->2
	graphsta[3][5]=graphsta[3][8];	
	graphsta[3][6]=graphsta[9][5];	
	graphsta[2][5]=graphsta[0][5];	
	
	//5->6
	graphsta[3][8]=graphsta[9][3];	
	graphsta[9][5]=graphsta[3][0];	
	graphsta[0][5]=graphsta[0][3];	
	
	//1->5
	graphsta[9][3]=graphsta[3][2];	
	graphsta[3][0]=graphsta[3][3];	
	graphsta[0][3]=graphsta[2][3];	
	
	//2->1
	graphsta[3][2]=temporary0[0];			
	graphsta[3][3]=temporary0[1];			
	graphsta[2][3]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储2到临时变量
	temporary1[0]=graphsta[2][4];			
	temporary1[1]=graphsta[3][4];			
	
	//7->2
	graphsta[2][4]=graphsta[1][5];	
	graphsta[3][4]=graphsta[3][7];	
	
	//6->7
	graphsta[1][5]=graphsta[0][4];	
	graphsta[3][7]=graphsta[9][4];	
	
	//5->6
	graphsta[0][4]=graphsta[1][3];	
	graphsta[9][4]=graphsta[3][1];	
	
	//2->1
	graphsta[1][3]=temporary1[0];			
	graphsta[3][1]=temporary1[1];			
}

/*----------------------*/
/*实现上面逆时针旋转操作*/
/*----------------------*/

void up_2()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储2到临时变量
	temporary0[0]=graphsta[3][5];			
	temporary0[1]=graphsta[3][6];			
	temporary0[2]=graphsta[2][5];			
	
	//1->2
	graphsta[3][5]=graphsta[3][2];	
	graphsta[3][6]=graphsta[3][3];	
	graphsta[2][5]=graphsta[2][3];	
	
	//5->1
	graphsta[3][2]=graphsta[9][3];	
	graphsta[3][3]=graphsta[3][0];	
	graphsta[2][3]=graphsta[0][3];	
	
	//6->5
	graphsta[9][3]=graphsta[3][8];	
	graphsta[3][0]=graphsta[9][5];	
	graphsta[0][3]=graphsta[0][5];	
	
	//2->6
	graphsta[3][8]=temporary0[0];			
	graphsta[9][5]=temporary0[1];			
	graphsta[0][5]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储2到临时变量
	temporary1[0]=graphsta[2][4];			
	temporary1[1]=graphsta[3][4];			
	
	//5->2
	graphsta[2][4]=graphsta[1][3];	
	graphsta[3][4]=graphsta[3][1];	
	
	//6->5
	graphsta[1][3]=graphsta[0][4];	
	graphsta[3][1]=graphsta[9][4];	
	
	//7->6
	graphsta[0][4]=graphsta[1][5];	
	graphsta[9][4]=graphsta[3][7];	
	
	//2->1
	graphsta[1][5]=temporary1[0];			
	graphsta[3][7]=temporary1[1];			
}

/*----------------------*/
/*实现下面顺时针旋转操作*/
/*----------------------*/

void down_1()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储3到临时变量

	temporary0[0]=graphsta[5][5];			
	temporary0[1]=graphsta[5][6];			
	temporary0[2]=graphsta[6][5];			
	
	//4->3
	graphsta[5][5]=graphsta[5][2];	
	graphsta[5][6]=graphsta[5][3];	
	graphsta[6][5]=graphsta[6][3];	
	
	//8->4
	graphsta[5][2]=graphsta[11][3];	
	graphsta[5][3]=graphsta[5][0];	
	graphsta[6][3]=graphsta[8][3];	
	
	//7->8
	graphsta[11][3]=graphsta[5][8];	
	graphsta[5][0]=graphsta[11][5];	
	graphsta[8][3]=graphsta[8][5];	
	
	//3->7
	graphsta[5][8]=temporary0[0];			
	graphsta[11][5]=temporary0[1];			
	graphsta[8][5]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储4到临时变量
	temporary1[0]=graphsta[6][4];			
	temporary1[1]=graphsta[5][4];			
	
	//11->4
	graphsta[6][4]=graphsta[7][3];	
	graphsta[5][4]=graphsta[5][1];	
	
	//10->11
	graphsta[7][3]=graphsta[8][4];	
	graphsta[5][1]=graphsta[11][4];	
	
	//9->10
	graphsta[8][4]=graphsta[7][5];	
	graphsta[11][4]=graphsta[5][7];	
	
	//4->9
	graphsta[7][5]=temporary1[0];			
	graphsta[5][7]=temporary1[1];			
}

/*----------------------*/
/*实现下面逆时针旋转操作*/
/*----------------------*/

void down_2()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储3到临时变量
	temporary0[0]=graphsta[5][5];			
	temporary0[1]=graphsta[5][6];			
	temporary0[2]=graphsta[6][5];			
	
	//7->3
	graphsta[5][5]=graphsta[5][8];	
	graphsta[5][6]=graphsta[11][5];	
	graphsta[6][5]=graphsta[8][5];	
	
	//8->7
	graphsta[5][8]=graphsta[11][3];	
	graphsta[11][5]=graphsta[5][0];	
	graphsta[8][5]=graphsta[8][3];	
	
	//4->8
	graphsta[11][3]=graphsta[5][2];	
	graphsta[5][0]=graphsta[5][3];	
	graphsta[8][3]=graphsta[6][3];	
	
	//3->4
	graphsta[5][2]=temporary0[0];			
	graphsta[5][3]=temporary0[1];			
	graphsta[6][3]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储4到临时变量
	temporary1[0]=graphsta[6][4];			
	temporary1[1]=graphsta[5][4];			
	
	//9->4
	graphsta[6][4]=graphsta[7][5];	
	graphsta[5][4]=graphsta[5][7];	
	
	//10->9
	graphsta[7][5]=graphsta[8][4];	
	graphsta[5][7]=graphsta[11][4];	
	
	//11->10
	graphsta[8][4]=graphsta[7][3];	
	graphsta[11][4]=graphsta[5][1];	
	
	//4->11
	graphsta[7][3]=temporary1[0];			
	graphsta[5][1]=temporary1[1];			
}

/*----------------------*/
/*实现左面顺时针旋转操作*/
/*----------------------*/

void left_1()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储1到临时变量
	temporary0[0]=graphsta[3][2];			
	temporary0[1]=graphsta[3][3];			
	temporary0[2]=graphsta[2][3];			
	
	//5->1
	graphsta[3][2]=graphsta[3][0];	
	graphsta[3][3]=graphsta[0][3];	
	graphsta[2][3]=graphsta[9][3];	
	
	//8->5
	graphsta[3][0]=graphsta[5][0];	
	graphsta[0][3]=graphsta[11][3];	
	graphsta[9][3]=graphsta[8][3];	
	
	//4->8
	graphsta[5][0]=graphsta[5][2];	
	graphsta[11][3]=graphsta[6][3];	
	graphsta[8][3]=graphsta[5][3];	
	
	//1->4
	graphsta[5][2]=temporary0[0];			
	graphsta[6][3]=temporary0[1];			
	graphsta[5][3]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储1到临时变量
	temporary1[0]=graphsta[4][2];			
	temporary1[1]=graphsta[4][3];			
	
	//5->1
	graphsta[4][2]=graphsta[3][1];	
	graphsta[4][3]=graphsta[1][3];	
	
	//12->5
	graphsta[3][1]=graphsta[4][0];	
	graphsta[1][3]=graphsta[10][3];	
	
	//11->12
	graphsta[4][0]=graphsta[5][1];	
	graphsta[10][3]=graphsta[7][3];	
	
	//1->11
	graphsta[5][1]=temporary1[0];			
	graphsta[7][3]=temporary1[1];			
}

/*----------------------*/
/*实现左面逆时针旋转操作*/
/*----------------------*/

void left_2()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储1到临时变量
	temporary0[0]=graphsta[3][2];			
	temporary0[1]=graphsta[3][3];			
	temporary0[2]=graphsta[2][3];			
	
	//4->1
	graphsta[3][2]=graphsta[5][2];	
	graphsta[3][3]=graphsta[6][3];	
	graphsta[2][3]=graphsta[5][3];	
	
	//8->4
	graphsta[5][2]=graphsta[5][0];	
	graphsta[6][3]=graphsta[11][3];	
	graphsta[5][3]=graphsta[8][3];	
	
	//5->8
	graphsta[5][0]=graphsta[3][0];	
	graphsta[11][3]=graphsta[0][3];	
	graphsta[8][3]=graphsta[9][3];	
	
	//1->5
	graphsta[3][0]=temporary0[0];			
	graphsta[0][3]=temporary0[1];			
	graphsta[9][3]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储1到临时变量
	temporary1[0]=graphsta[4][2];			
	temporary1[1]=graphsta[4][3];			
	
	//11->1
	graphsta[4][2]=graphsta[5][1];	
	graphsta[4][3]=graphsta[7][3];	
	
	//12->11
	graphsta[5][1]=graphsta[4][0];	
	graphsta[7][3]=graphsta[10][3];	
	
	//5->12
	graphsta[4][0]=graphsta[3][1];	
	graphsta[10][3]=graphsta[1][3];	
	
	//1->5
	graphsta[3][1]=temporary1[0];			
	graphsta[1][3]=temporary1[1];			
}

/*----------------------*/
/*实现右面顺时针旋转操作*/
/*----------------------*/

void right_1()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储2到临时变量
	temporary0[0]=graphsta[3][5];			
	temporary0[1]=graphsta[3][6];			
	temporary0[2]=graphsta[2][5];			
	
	//3->2
	graphsta[3][5]=graphsta[6][5];	
	graphsta[3][6]=graphsta[5][6];	
	graphsta[2][5]=graphsta[5][5];	
	
	//7->3
	graphsta[6][5]=graphsta[11][5];	
	graphsta[5][6]=graphsta[5][8];	
	graphsta[5][5]=graphsta[8][5];	
	
	//6->7
	graphsta[11][5]=graphsta[0][5];	
	graphsta[5][8]=graphsta[3][8];	
	graphsta[8][5]=graphsta[9][5];	
	
	//2->6
	graphsta[0][5]=temporary0[0];			
	graphsta[3][8]=temporary0[1];			
	graphsta[9][5]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储3到临时变量
	temporary1[0]=graphsta[4][5];			
	temporary1[1]=graphsta[4][6];			
	
	//9->3
	graphsta[4][5]=graphsta[7][5];	
	graphsta[4][6]=graphsta[5][7];	
	
	//8->9
	graphsta[7][5]=graphsta[10][5];	
	graphsta[5][7]=graphsta[4][8];	
	
	//7->8
	graphsta[10][5]=graphsta[1][5];	
	graphsta[4][8]=graphsta[3][7];	
	
	//3->7
	graphsta[1][5]=temporary1[0];			
	graphsta[3][7]=temporary1[1];			
}

/*----------------------*/
/*实现右面逆时针旋转操作*/
/*----------------------*/

void right_2()
{
	//存储角块的临时变量
	char temporary0[3];							
	
	//存储边块的临时变量
	char temporary1[2];							
	
	/*对角块操作*/
	
	//存储2到临时变量
	temporary0[0]=graphsta[3][5];			
	temporary0[1]=graphsta[3][6];			
	temporary0[2]=graphsta[2][5];			
	
	//6->2
	graphsta[3][5]=graphsta[0][5];	
	graphsta[3][6]=graphsta[3][8];	
	graphsta[2][5]=graphsta[9][5];	
	
	//7->6
	graphsta[0][5]=graphsta[11][5];	
	graphsta[3][8]=graphsta[5][8];	
	graphsta[9][5]=graphsta[8][5];	
	
	//3->7
	graphsta[11][5]=graphsta[6][5];	
	graphsta[5][8]=graphsta[5][6];	
	graphsta[8][5]=graphsta[5][5];	
	
	//2->3
	graphsta[6][5]=temporary0[0];			
	graphsta[5][6]=temporary0[1];			
	graphsta[5][5]=temporary0[2];			
	
	/*对边块操作*/
	
	//存储3到临时变量
	temporary1[0]=graphsta[4][5];			
	temporary1[1]=graphsta[4][6];			
	
	//7->3
	graphsta[4][5]=graphsta[1][5];	
	graphsta[4][6]=graphsta[3][7];	
	
	//8->7
	graphsta[1][5]=graphsta[10][5];	
	graphsta[3][7]=graphsta[4][8];	
	
	//9->8
	graphsta[10][5]=graphsta[7][5];	
	graphsta[4][8]=graphsta[5][7];	
	
	//3->9
	graphsta[7][5]=temporary1[0];			
	graphsta[5][7]=temporary1[1];			
}

/*--------------------*/	
/*显示魔方旋转后的状态*/
/*--------------------*/

void display_mf()
{/*	
	int i,j;
	
	//打印魔方上面的状态
	for(i=0;i<3;i++)						
	{	
		//七个空格
		cout<<"       ";   					
		
		for(j=3;j<6;j++)
			cout<<graphsta[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//打印魔方左面，前面，右面的状态
	for(i=3;i<6;i++)						
	{
		for(j=0;j<9;j++)
		{
			cout<<graphsta[i][j]<<" ";
			if(j==2||j==5)
				cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//打印魔方下面的状态
	for(i=6;i<9;i++)						
	{	
		//七个空格
		cout<<"       ";					
		
		for(j=3;j<6;j++)
			cout<<graphsta[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	//打印魔方后面的状态
	for(i=9;i<12;i++)						
	{	
		//七个空格
		cout<<"       ";					
		
		for(j=3;j<6;j++)
			cout<<graphsta[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
*/
}


/*--------------------*/
/*实现由左面转换到前面*/
/*--------------------*/

void left_front()
{
	/*实现left->front->right->back->left*/
	char s[3][3];
	
	/*存储front到s*/
	s[0][0]=graphsta[3][3];
	s[0][1]=graphsta[3][4];
	s[0][2]=graphsta[3][5];
	s[1][0]=graphsta[4][3];
	s[1][1]=graphsta[4][4];
	s[1][2]=graphsta[4][5];
	s[2][0]=graphsta[5][3];
	s[2][1]=graphsta[5][4];
	s[2][2]=graphsta[5][5];
	
	/*left->front*/
	graphsta[3][3]=graphsta[3][0];
	graphsta[3][4]=graphsta[3][1];
	graphsta[3][5]=graphsta[3][2];
	graphsta[4][3]=graphsta[4][0];
	graphsta[4][4]=graphsta[4][1];
	graphsta[4][5]=graphsta[4][2];
	graphsta[5][3]=graphsta[5][0];
	graphsta[5][4]=graphsta[5][1];
	graphsta[5][5]=graphsta[5][2];

	/*back->left*/
	graphsta[3][0]=graphsta[9][5];
	graphsta[3][1]=graphsta[9][4];
	graphsta[3][2]=graphsta[9][3];
	graphsta[4][0]=graphsta[10][5];
	graphsta[4][1]=graphsta[10][4];
	graphsta[4][2]=graphsta[10][3];
	graphsta[5][0]=graphsta[11][5];
	graphsta[5][1]=graphsta[11][4];
	graphsta[5][2]=graphsta[11][3];

	/*right->back*/
	graphsta[9][5]=graphsta[3][6];
	graphsta[9][4]=graphsta[3][7];
	graphsta[9][3]=graphsta[3][8];
	graphsta[10][5]=graphsta[4][6];
	graphsta[10][4]=graphsta[4][7];
	graphsta[10][3]=graphsta[4][8];
	graphsta[11][5]=graphsta[5][6];
	graphsta[11][4]=graphsta[5][7];
	graphsta[11][3]=graphsta[5][8];

	/*s->right*/
	graphsta[3][6]=s[0][0];
	graphsta[3][7]=s[0][1];
	graphsta[3][8]=s[0][2];
	graphsta[4][6]=s[1][0];
	graphsta[4][7]=s[1][1];
	graphsta[4][8]=s[1][2];
	graphsta[5][6]=s[2][0];
	graphsta[5][7]=s[2][1];
	graphsta[5][8]=s[2][2];

	char c;
	
	/*up内角交换*/
	c=graphsta[2][5];
	graphsta[2][5]=graphsta[2][3];
	graphsta[2][3]=graphsta[0][3];
	graphsta[0][3]=graphsta[0][5];
	graphsta[0][5]=c;

	/*up内边交换*/
	c=graphsta[2][4];
	graphsta[2][4]=graphsta[1][3];
	graphsta[1][3]=graphsta[0][4];
	graphsta[0][4]=graphsta[1][5];
	graphsta[1][5]=c;

	/*down内角交换*/
	c=graphsta[8][5];
	graphsta[8][5]=graphsta[6][5];
	graphsta[6][5]=graphsta[6][3];
	graphsta[6][3]=graphsta[8][3];
	graphsta[8][3]=c;

	/*down内边交换*/
	c=graphsta[8][4];
	graphsta[8][4]=graphsta[7][5];
	graphsta[7][5]=graphsta[6][4];
	graphsta[6][4]=graphsta[7][3];
	graphsta[7][3]=c;
}

/*--------------------*/
/*实现前面到下面的转换*/
/*--------------------*/

void front_down()
{
	/*实现front->down->back->up->front*/
	char s[3][3];
	
	/*存储front到s*/
	s[0][0]=graphsta[3][3];
	s[0][1]=graphsta[3][4];
	s[0][2]=graphsta[3][5];
	s[1][0]=graphsta[4][3];
	s[1][1]=graphsta[4][4];
	s[1][2]=graphsta[4][5];
	s[2][0]=graphsta[5][3];
	s[2][1]=graphsta[5][4];
	s[2][2]=graphsta[5][5];
	
	/*up->front*/
	graphsta[3][3]=graphsta[0][3];
	graphsta[3][4]=graphsta[0][4];
	graphsta[3][5]=graphsta[0][5];
	graphsta[4][3]=graphsta[1][3];
	graphsta[4][4]=graphsta[1][4];
	graphsta[4][5]=graphsta[1][5];
	graphsta[5][3]=graphsta[2][3];
	graphsta[5][4]=graphsta[2][4];
	graphsta[5][5]=graphsta[2][5];

	/*back->up*/
	graphsta[0][3]=graphsta[11][3];
	graphsta[0][4]=graphsta[11][4];
	graphsta[0][5]=graphsta[11][5];
	graphsta[1][3]=graphsta[10][3];
	graphsta[1][4]=graphsta[10][4];
	graphsta[1][5]=graphsta[10][5];
	graphsta[2][3]=graphsta[9][3];
	graphsta[2][4]=graphsta[9][4];
	graphsta[2][5]=graphsta[9][5];

	/*down->back*/
	graphsta[11][3]=graphsta[6][3];
	graphsta[11][4]=graphsta[6][4];
	graphsta[11][5]=graphsta[6][5];
	graphsta[10][3]=graphsta[7][3];
	graphsta[10][4]=graphsta[7][4];
	graphsta[10][5]=graphsta[7][5];
	graphsta[9][3]=graphsta[8][3];
	graphsta[9][4]=graphsta[8][4];
	graphsta[9][5]=graphsta[8][5];

	/*s->down*/
	graphsta[6][3]=s[0][0];
	graphsta[6][4]=s[0][1];
	graphsta[6][5]=s[0][2];
	graphsta[7][3]=s[1][0];
	graphsta[7][4]=s[1][1];
	graphsta[7][5]=s[1][2];
	graphsta[8][3]=s[2][0];
	graphsta[8][4]=s[2][1];
	graphsta[8][5]=s[2][2];

	char c;
	
	/*left内角交换*/
	c=graphsta[5][2];
	graphsta[5][2]=graphsta[3][2];
	graphsta[3][2]=graphsta[3][0];
	graphsta[3][0]=graphsta[5][0];
	graphsta[5][0]=c;

	/*left内边交换*/
	c=graphsta[5][1];
	graphsta[5][1]=graphsta[4][2];
	graphsta[4][2]=graphsta[3][1];
	graphsta[3][1]=graphsta[4][0];
	graphsta[4][0]=c;

	/*right内角交换*/
	c=graphsta[5][6];
	graphsta[5][6]=graphsta[3][6];
	graphsta[3][6]=graphsta[3][8];
	graphsta[3][8]=graphsta[5][8];
	graphsta[5][8]=c;

	/*right内边交换*/
	c=graphsta[5][7];
	graphsta[5][7]=graphsta[4][6];
	graphsta[4][6]=graphsta[3][7];
	graphsta[3][7]=graphsta[4][8];
	graphsta[4][8]=c;
}
