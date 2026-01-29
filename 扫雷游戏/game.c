#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

int win;
static void print_sag()
{
	for (int i = 1; i < COL - 2; i++)
		printf("-");

	printf("扫雷游戏");

	for (int i = 1; i < COL - 2; i++)
		printf("-");

	printf("\n");

}

static int get_mine_count(char mine[][COLS], int x, int y)
{
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			count += mine[i][j] - '0';
	return count;
}

void InitBroad(char broad[][COLS], int rows, int cols, char ch)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			broad[i][j] = ch;
}

void DisplayBroad(char broad[][COLS], int row, int col)
{
	int i, j;

	print_sag();
	for (j = 0; j <= col; j++) {
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d ", i);
		for (j = 1; j <= col; j++) {
			printf("%c ", broad[i][j]);
		}
		printf("\n");

	}
	print_sag();
}

void SetMine(char broad[][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (broad[x][y] == '0') {
			broad[x][y] = '1';
			count--;
		}
	}
}

static void See_choice()
{
	printf("**********1. 排雷模式 *********\n");
	printf(" **********0. 标记模式 *********\n");
}

static void Broaden_broad(char mine[][COLS], char show[][COLS], int x, int y)
{
	int num;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i && j && i <= ROW && j <= COL && (show[i][j] == '*'|| show[i][j] == '#')) {
				num = get_mine_count(mine, i, j);
				win++;
				show[i][j] = num + '0';
				if(!num)
					Broaden_broad(mine, show, i, j);
			}
		}
	}
}
void FindMine(char mine[][COLS], char show[][COLS], int row, int col)
{
	int x, y;
	int choice;
	printf("游戏过程中的坐标输入形式均统一（请确保处于英文输入状态），示例：1,1\n ");
	while (win < row * col - EASY_COUNT) {

		See_choice();
		printf("请输入选择:>");
		scanf("%d", &choice);

		if (choice == 0) {
			while (1) {
				printf("请输入需改动标记的坐标:>");
				scanf("%d,%d", &x, &y);
				if (x >= 1 && x <= row && y >= 1 && y <= col) {
					if (show[x][y] == '*')
						show[x][y] = '#';
					else
						show[x][y] = '*';
					DisplayBroad(show, ROW, COL);
					break;
				}
				else
					printf("输入坐标违法，请重新输入！\n");
			}
		}
		else {
			while (1) {
				printf("请输入要排查的坐标:>");
				scanf("%d,%d", &x, &y);

				if (show[x][y] != '*') 
					printf("该坐标已经被排查过了，不能重复排查！\n");

				else if (x >= 1 && x <= row && y >= 1 && y <= col) {
					if (mine[x][y] == '1') {
						printf("很遗憾，你被炸死了！\n");
						DisplayBroad(mine, ROW, COL);
						return;
					}

					else {
						int count = get_mine_count(mine, x, y);
						win++;
						show[x][y] = count + '0';
						if(!count)
						Broaden_broad(mine, show, x, y);
						DisplayBroad(show, ROW, COL);
						break;
					}
				}

				else
					printf("输入坐标违法，请重新输入！\n");
			}
		}
	}
		printf("恭喜你，排雷成功！\n");
		DisplayBroad(mine, ROW, COL);
}




