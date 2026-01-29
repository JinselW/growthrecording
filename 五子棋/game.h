#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
//初始化表格
void new_broad(char broad[ROW][COL], int row, int col);
//打印表格
void display_broad(char broad[ROW][COL], int row, int col);
//玩家play
void player(char broad[ROW][COL], int row, int col);
//电脑play
void computer(char broad[ROW][COL], int row, int col);
//判断输赢
char Iswin(char broad[ROW][COL], int row, int col);