#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col ; j++)
		{
			board[i][j] = ' ';
		}
	}

}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf("%c",board[i][j]);
			if (j < col - 1)
				printf("  |");
		}
		printf("\n");
		if (i < row - 1)
		{
			j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走>\n");
		printf("请选择所下位置>:");
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col && x >= 1 && y >= 1)
		{
			if (board[x - 1][y - 1] == ' '||board[x-1][y-1]!='#')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("被占用了,重新输入>");
			}
		}
		else
		{
			printf("选择错误,重新选择》");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");
	while (1)
	{ 
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char isWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return  board[i][1];//
		}
	}

	//判断三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//判断平局
	//如果棋盘满了返回1， 不满返回0
	int ret = isFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}

	//继续
	return 'C';
}
int isFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}