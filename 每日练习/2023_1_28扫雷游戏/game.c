﻿#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
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
	printf("-----扫雷游戏-----\n");
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
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
void Setmine(char board[ROWS][COLS],int row,int col)
{
	int x = rand()%row+1;
	int y = rand()%col+1;
	int count = 10;
	while (count)
	{
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{

}