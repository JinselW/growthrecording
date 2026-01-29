#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meau()
{
	printf("########################################\n");
	printf("#########1.开始游戏  0.退出游戏#########\n");
	printf("########################################\n");
}
void game()
{
	char ret = 0;
	char broad[ROW][COL] = { 0 };
	new_broad(broad, ROW, COL);
	display_broad(broad, ROW, COL);
	//开始下棋
	while (1)
	{
		player(broad, ROW, COL);
		//判断输赢
		//玩家赢了返回“*”
		//电脑赢了返回“#”
		//平局返回“Q”
		//游戏继续“C”
		ret=Iswin(broad, ROW, COL);
		if (ret != 'C')
			break;
		display_broad(broad, ROW, COL);
		computer(broad, ROW, COL);
		//判断输赢
		if (ret != 'C')
			break;
		ret = Iswin(broad, ROW, COL);
		display_broad(broad, ROW, COL);
		}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == "#")
		printf("电脑赢\n");
	else
		printf("平局\n");
	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		meau();//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
		meau();//打印菜单
		printf("请选择:>");
		scanf("%d", &input);
	} while (input);
	

	return 0;
}