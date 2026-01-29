#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void new_broad(char broad[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row ; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			broad[i][j] = ' ';
		}
	}
}
void display_broad(char broad[ROW][COL], int row, int col)
{
	//初步输出表格
	int i = 0;
	int j = 0;
	for (i = 0; i < row ; i++)
	{
		for (j = 0; j < col; j++)
		{//输出数据
			printf(" %c ", broad[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{//输出分割线
				printf("---");
				if(j<col-1)
				printf("|");
			}
			printf("\n");
		}
		
			
	}
}
void player(char broad[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");
	while (1)
	{
		printf("玩家请选择位置:> ");
		scanf("%d, %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (broad[x - 1][y - 1] == ' ')
			{
				broad[x - 1][y - 1] ='*';
				break;
			}
			else
			{
				printf("坐标已被占用，不能下棋，请选择其他位置！\n");
			}
				
		}
		else
		{
			printf("坐标不在区域内，请重新选择！\n");
		}
		
		
	}
	

}
void computer(char broad[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (broad[x][y] == ' ')
		{
		    broad[x][y] = '#';
			break;
		}
		
	}

}
char Iswin(char broad[ROW][COL], int row, int col)
{
	//判断行
	int i = 0;
	int j = 0;
	for (i=0;i<row;i++)
	{
		for (j = 0; j < col-2; j++)
		{
			if (broad[i][j] == broad[i][j + 1] && broad[i][j + 1] == broad[i][j + 2] && broad[i][j + 1] != ' ')
				return broad[i][j + 1];
		}
	}
	//判断列
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 2; i++)
		{
			if (broad[i][j] == broad[i+1][j] && broad[i+1][j] == broad[i+2][j] && broad[i+1][j] != ' ')
				return broad[i+1][j];
		}
	}
	//判断对角线，两种情况
	for (i = 1; i < row-1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (broad[i][j] == broad[i-1][j-1] && broad[i][j] == broad[i+1][j+1] && broad[i][j] != ' ')
				return broad[i][j];
		}
	}
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (broad[i][j] == broad[i-1][j+1] && broad[i][j] == broad[i+1][j-1] && broad[i][j] != ' ')
				return broad[i][j];
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (broad[i][j] == ' ')
				return 'C';
		}
	}
	return 'Q';
	
}