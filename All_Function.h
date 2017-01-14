/*-------------------------------*/
/*����������ͷ�ļ�:All_Function.h*/
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
//����ħ������,ȫ�ֱ���
EXTERN char graphmf[12][9];	//�����ļ�������		
EXTERN char graphsta[12][9];	//ʵ�ʲ���������
EXTERN char graphmf1[12][9];	//������¼ħ����ʼ״̬������
EXTERN queue<int> rc;			//�洢ħ�������Ĳ���
EXTERN bool solve_1;
EXTERN void (*p)();			//����ָ��,����ħ����ԭ��һ�׶ε�bfs��
 

//���º�����gm.cpp�и������嶨��
void getgraph();
void makegraph(char s[6][20]);
void extractgraph(char s[6][20]);
void initgraph();

//���º�����search.cpp�и������嶨��
bool compara();
void change();
void reback();
void bfs_solve();
void node_operation();
void release_t();
void mission_compelet();
void bfs_mf();

//���º�����change.cpp�и������嶨��
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

//���º�����begin.cpp�и������嶨��
//bool choice();
bool solve_rubik();

//���º�����expert.cpp�и�������
void first_stage();
void second_stage();
void third_stage();
void forth_stage();
void fifth_stage();
void sixth_stage();
void seventh_stage();
void eighth_stage();