/*-------------------------------*/
/*函数声明的头文件:All_Function.h*/
/*-------------------------------*/
#include <queue>
#include <stack>
using namespace std;

#ifdef _FIRST_
#define EXTERN 
#else
#define EXTERN extern
#endif
//The operations
#define FRONT_POS 1
#define FRONT_NEG 2
#define BACK_POS 3
#define BACK_NEG 4
#define LEFT_POS 5
#define LEFT_NEG 6
#define RIGHT_POS 7
#define RIGHT_NEG 8
#define UPPER_POS 9
#define UPPER_NEG 10
#define DOWN_POS 11
#define DOWN_NEG 12
#define WHOLE_LF 13
#define WHOLE_FD 14
#define HINT_BRD 15
//定义魔方矩阵,全局变量
EXTERN char graphmf[12][9];	//接收文件的数组		
EXTERN char graphsta[12][9];	//实际操作的数组
EXTERN char graphmf1[12][9];	//用来记录魔方初始状态的数组
EXTERN queue<int> rc;			//存储魔方操作的步骤
EXTERN bool solve_1;
EXTERN void (*p)();			//函数指针,用在魔方复原第一阶段的bfs中
 

//以下函数在gm.cpp中给出具体定义
void getgraph();
void makegraph(char s[6][20]);
void extractgraph(char s[6][20]);
void initgraph();

//以下函数在search.cpp中给出具体定义
bool compara();
void change();
void reback();
void bfs_solve();
void node_operation();
void release_t();
void mission_compelet();
void bfs_mf();

//以下函数在change.cpp中给出具体定义
void front_1();
void front_2();
void back_1();
void back_2();
void up_1();
void up_2();
void down_1();
void down_2();
void left_1();
void left_2();
void right_1();
void right_2();
void display_mf();
void left_front();
void front_down();

//以下函数在begin.cpp中给出具体定义
//bool choice();
bool solve_rubik();

//以下函数在expert.cpp中给出定义
void first_stage();
void second_stage();
void third_stage();
void forth_stage();
void fifth_stage();
void sixth_stage();
void seventh_stage();
void eighth_stage();