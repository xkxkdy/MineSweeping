#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int x = 0;
	for (x = 0; x <= row; x++)
	{
		printf("%d ", x);
	}
		printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Game;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;//1-9   数组都是11x11的
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
				count--;
		}
	}
}

//(x,y)周围的8个数字
int show_mine_num(char mine[ROWS][COLS], int x, int  y)//字符'1'不能直接相加减，但'1'-'0'=0(
{
	int num = 
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y] - 8 * '0';
	return num;
}


void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win< row* col - Easy_Game)
	{
		printf("请输入要排雷的坐标:>");
		scanf("%d%d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int ret = show_mine_num(mine, x, y);
				show[x][y] = ret+'0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - Easy_Game)//除了雷全排完了
	{
		printf("恭喜你，获胜\n");
	}
}

