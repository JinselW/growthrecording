#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBroad(char broad[][COLS], int rows, int cols, char ch);
void DisplayBroad(char broad[][COLS], int row, int col);
void SetMine(char broad[][COLS], int row, int col);
void FindMine(char mine[][COLS], char show[][COLS], int row, int col);


