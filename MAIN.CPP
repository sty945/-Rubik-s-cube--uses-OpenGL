/*-------------------*/
/*    魔方主文件     */
/*-------------------*/

#include"All_Function.h"
#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;

//定义魔方矩阵,全局变量
char graphmf[12][9];	//接收文件的数组		
char graphsta[12][9];	//实际操作的数组
char graphmf1[12][9];	//用来记录魔方初始状态的数组
queue<int> rc;			//存储魔方操作的步骤
bool solve_1=false;
void (*p)();			//函数指针,用在魔方复原第一阶段的bfs中
/*魔方文件的输入中有六行,对应六个面,必须按照R,G,Y,B,O,W面的顺序输入.*/
void main()
{
	string c;
	while(1)
	{
		search_begin();		//求解开始	
		cout<<"N/n 退出,任意键执行下一个魔方文件"<<endl;
		cin>>c;
		if(c=="N"||c=="n")
			break;
	}

	/*如果手中没有魔方,也可以通过在以下程序中任意插入旋转序列,
	来得到打乱的魔方,当然上面的求解先不要执行.*/
	
	//getgraph();
	//makegraph();
	//change();
	
	/*front_1(),front_2(),down_1(),down_()
	  left_1(),left_2(),right_1(),right_2()
	  up_1(),up_2(),back_1(),back_2()*/
	
	//在下面插入序列
	//front_1();
	//up_1();
	//down_1();
	//left_2();
	
	//display_mf();
}
