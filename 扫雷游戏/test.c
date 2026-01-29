#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

static void meau()
{
	printf("***************************\n");
	printf("******    1. play    ******\n");
	printf("******    0. exit    ******\n");
	printf("***************************\n");

}

void game()
{	
	char mine[ROWS][COLS] = { 0 }; //存放雷的信息
	char show[ROWS][COLS] = { 0 }; //存放排查出的雷的信息

	//初始化数组的内容为指定的
	//mine数组的全体元素为'0'
	InitBroad(mine, ROWS, COLS, '0');
	//show数组的全体元素为'*'
	InitBroad(show, ROWS, COLS, '*');
	//设置雷
	SetMine(mine, ROW, COL);
	/*DisplayBroad(mine, ROW, COL);*/
	DisplayBroad(show, ROW, COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int choice;
	//设置随机数的生成起点
	srand((unsigned int)time(NULL));
	do {
		meau();
		printf("请选择:>");
		scanf("%d", &choice);
		switch (choice) {
		case 1: 
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
		}
	} while (choice);

	return 0;
}