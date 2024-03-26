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
		x = rand() % row + 1;//1-9   ���鶼��11x11��
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
				count--;
		}
	}
}

//(x,y)��Χ��8������
int show_mine_num(char mine[ROWS][COLS], int x, int  y)//�ַ�'1'����ֱ����Ӽ�����'1'-'0'=0(
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
		printf("������Ҫ���׵�����:>");
		scanf("%d%d", &x, &y);
		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը����\n");
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
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row * col - Easy_Game)//������ȫ������
	{
		printf("��ϲ�㣬��ʤ\n");
	}
}

