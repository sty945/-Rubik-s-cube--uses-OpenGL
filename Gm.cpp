/*----------------------------*/
/*魔方文件读取，完成魔方状态图*/
/*----------------------------*/
#include "StdAfx.h"
#include "All_Function.h"
#include <iostream>
#include <fstream>

/*----------------------*/
/*    构建魔方状态图    */
/*----------------------*/

void makegraph(char s[6][20])
{
	int i,j;
	
	//魔方上面状态图的构建
	graphmf[0][3]=s[0][0];
	graphmf[0][4]=s[0][1];
	graphmf[0][5]=s[0][2];
	graphmf[1][3]=s[0][3];
	graphmf[1][4]=s[0][4];
	graphmf[1][5]=s[0][5];
	graphmf[2][3]=s[0][6];
	graphmf[2][4]=s[0][7];
	graphmf[2][5]=s[0][8];
	
	//魔方左面状态图的构建
	graphmf[3][0]=s[1][0];
	graphmf[3][1]=s[1][1];
	graphmf[3][2]=s[1][2];
	graphmf[4][0]=s[1][3];
	graphmf[4][1]=s[1][4];
	graphmf[4][2]=s[1][5];
	graphmf[5][0]=s[1][6];
	graphmf[5][1]=s[1][7];
	graphmf[5][2]=s[1][8];
	
	//魔方前面状态图的构建
	graphmf[3][3]=s[2][0];
	graphmf[3][4]=s[2][1];
	graphmf[3][5]=s[2][2];
	graphmf[4][3]=s[2][3];
	graphmf[4][4]=s[2][4];
	graphmf[4][5]=s[2][5];
	graphmf[5][3]=s[2][6];
	graphmf[5][4]=s[2][7];
	graphmf[5][5]=s[2][8];
	
	//魔方右面状态图的构建
	graphmf[3][6]=s[3][0];
	graphmf[3][7]=s[3][1];
	graphmf[3][8]=s[3][2];
	graphmf[4][6]=s[3][3];
	graphmf[4][7]=s[3][4];
	graphmf[4][8]=s[3][5];
	graphmf[5][6]=s[3][6];
	graphmf[5][7]=s[3][7];
	graphmf[5][8]=s[3][8];
	
	//魔方下面状态图的构建
	graphmf[6][3]=s[4][0];
	graphmf[6][4]=s[4][1];
	graphmf[6][5]=s[4][2];
	graphmf[7][3]=s[4][3];
	graphmf[7][4]=s[4][4];
	graphmf[7][5]=s[4][5];
	graphmf[8][3]=s[4][6];
	graphmf[8][4]=s[4][7];
	graphmf[8][5]=s[4][8];
	
	//魔方后面状态图的构建
	graphmf[9][3]=s[5][0];
	graphmf[9][4]=s[5][1];
	graphmf[9][5]=s[5][2];
	graphmf[10][3]=s[5][3];
	graphmf[10][4]=s[5][4];
	graphmf[10][5]=s[5][5];
	graphmf[11][3]=s[5][6];
	graphmf[11][4]=s[5][7];
	graphmf[11][5]=s[5][8];

	for(i=0;i<12;i++)
		for(j=0;j<9;j++)
		{
			graphmf1[i][j]=graphmf[i][j];
			graphsta[i][j]=graphmf[i][j];
		}
}

void extractgraph(char s[6][20])
{
	//魔方上面状态图的构建
	s[0][0] = graphsta[0][3];
	s[0][1] = graphsta[0][4];
	s[0][2] = graphsta[0][5];
	s[0][3] = graphsta[1][3];
	s[0][4] = graphsta[1][4];
	s[0][5] = graphsta[1][5];
	s[0][6] = graphsta[2][3];
	s[0][7] = graphsta[2][4];
	s[0][8] = graphsta[2][5];
	
	//魔方左面状态图的构建
	s[1][0] = graphsta[3][0];
	s[1][1] = graphsta[3][1];
	s[1][2] = graphsta[3][2];
	s[1][3] = graphsta[4][0];
	s[1][4] = graphsta[4][1];
	s[1][5] = graphsta[4][2];
	s[1][6] = graphsta[5][0];
	s[1][7] = graphsta[5][1];
	s[1][8] = graphsta[5][2];
	
	//魔方前面状态图的构建
	s[2][0] = graphsta[3][3];
	s[2][1] = graphsta[3][4];
	s[2][2] = graphsta[3][5];
	s[2][3] = graphsta[4][3];
	s[2][4] = graphsta[4][4];
	s[2][5] = graphsta[4][5];
	s[2][6] = graphsta[5][3];
	s[2][7] = graphsta[5][4];
	s[2][8] = graphsta[5][5];
	
	//魔方右面状态图的构建
	s[3][0] = graphsta[3][6];
	s[3][1] = graphsta[3][7];
	s[3][2] = graphsta[3][8];
	s[3][3] = graphsta[4][6];
	s[3][4] = graphsta[4][7];
	s[3][5] = graphsta[4][8];
	s[3][6] = graphsta[5][6];
	s[3][7] = graphsta[5][7];
	s[3][8] = graphsta[5][8];
	
	//魔方下面状态图的构建
	s[4][0] = graphsta[6][3];
	s[4][1] = graphsta[6][4];
	s[4][2] = graphsta[6][5];
	s[4][3] = graphsta[7][3];
	s[4][4] = graphsta[7][4];
	s[4][5] = graphsta[7][5];
	s[4][6] = graphsta[8][3];
	s[4][7] = graphsta[8][4];
	s[4][8] = graphsta[8][5];
	
	//魔方后面状态图的构建
	s[5][0] = graphsta[9][3];
	s[5][1] = graphsta[9][4];
	s[5][2] = graphsta[9][5];
	s[5][3] = graphsta[10][3];
	s[5][4] = graphsta[10][4];
	s[5][5] = graphsta[10][5];
	s[5][6] = graphsta[11][3];
	s[5][7] = graphsta[11][4];
	s[5][8] = graphsta[11][5];
}

void initgraph()
{
	graphmf[0][3] = 'R';
	graphmf[0][4] = 'R';
	graphmf[0][5] = 'R';
	graphmf[1][3] = 'R';
	graphmf[1][4] = 'R';
	graphmf[1][5] = 'R';
	graphmf[2][3] = 'R';
	graphmf[2][4] = 'R';
	graphmf[2][5] = 'R';
	graphmf[3][0] = 'G';
	graphmf[3][1] = 'G';
	graphmf[3][2] = 'G';
	graphmf[4][0] = 'G';
	graphmf[4][1] = 'G';
	graphmf[4][2] = 'G';
	graphmf[5][0] = 'G';
	graphmf[5][1] = 'G';
	graphmf[5][2] = 'G';
	graphmf[3][3] = 'Y';
	graphmf[3][4] = 'Y';
	graphmf[3][5] = 'Y';
	graphmf[4][3] = 'Y';
	graphmf[4][4] = 'Y';
	graphmf[4][5] = 'Y';
	graphmf[5][3] = 'Y';
	graphmf[5][4] = 'Y';
	graphmf[5][5] = 'Y';
	graphmf[3][6] = 'B';
	graphmf[3][7] = 'B';
	graphmf[3][8] = 'B';
	graphmf[4][6] = 'B';
	graphmf[4][7] = 'B';
	graphmf[4][8] = 'B';
	graphmf[5][6] = 'B';
	graphmf[5][7] = 'B';
	graphmf[5][8] = 'B';
	graphmf[6][3] = 'O';
	graphmf[6][4] = 'O';
	graphmf[6][5] = 'O';
	graphmf[7][3] = 'O';
	graphmf[7][4] = 'O';
	graphmf[7][5] = 'O';
	graphmf[8][3] = 'O';
	graphmf[8][4] = 'O';
	graphmf[8][5] = 'O';
	graphmf[9][3] = 'W';
	graphmf[9][4] = 'W';
	graphmf[9][5] = 'W';
	graphmf[10][3] = 'W';
	graphmf[10][4] = 'W';
	graphmf[10][5] = 'W';
	graphmf[11][3] = 'W';
	graphmf[11][4] = 'W';
	graphmf[11][5] = 'W';
	for(int i=0;i<12;i++)
		for(int j=0;j<9;j++)
		{
			graphmf1[i][j]=graphmf[i][j];
			graphsta[i][j]=graphmf[i][j];
		}
}