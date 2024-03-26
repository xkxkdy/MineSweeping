#pragma once

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define Easy_Game 80     //��Ϸ�׵ĸ���

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char board[ROWS][COLS],int rows, int cols,char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void SetMine(char board[ROWS][COLS], int row, int col);

void Find_Mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

