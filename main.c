#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void Game()
{
	//1.��������
	char mine[ROWS][COLS] = { 0 };//���׵�����
	char show[ROWS][COLS] = { 0 };//����Ϣ�����飬
	//2.��ʼ��
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//3.��ӡ����
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//4.������
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//5.����
	Find_Mine(mine, show, ROW, COL);


}


void menu()
{
	printf("1.������Ϸ    2.�뿪��Ϸ\n");
}


void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	menu();
	do
	{
		printf("������: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�뿪��Ϸ\n");
			break;
		default:
			printf("����������\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}