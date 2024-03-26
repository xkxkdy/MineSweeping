#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void Game()
{
	//1.定义数组
	char mine[ROWS][COLS] = { 0 };//放雷的数组
	char show[ROWS][COLS] = { 0 };//放信息的数组，
	//2.初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//3.打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//4.布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//5.排雷
	Find_Mine(mine, show, ROW, COL);


}


void menu()
{
	printf("1.进入游戏    2.离开游戏\n");
}


void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	do
	{
		printf("请输入: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("离开游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}