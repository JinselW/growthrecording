#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void print_calendar(int year);
void print_headline(int year, int month);
void print_date(int year, int month);
int first_day(int year);
int is_leapyear(int year);
int month_day(int year, int month);
int first_monthday(int year, int month, int firstday);
int main()
{
	int year;
	scanf("%d", &year);
	print_calendar(year);
	return 0;
}
//打印程序
void print_calendar(int year)
{
	for (int month = 1; month <= 12; month++) {
		printf("\n");
		print_headline(year, month);
		print_date(year, month);
		printf("\n");
	}
}
//打印头标
void print_headline(int year, int month)
{
	printf("     %d年%d月\n", year, month);
	printf("日 一 二 三 四 五 六\n");
}
//具体打印每月的日期
void print_date(int year, int month)
{
	//每年的第一天的星期数
	int firstday = first_day(year) % 7;
	//每月的总天数
	int monthday = month_day(year, month);
	//每月的第一天的星期数
	int firstmonthday = first_monthday(year, month, firstday) % 7;
	//打印第一天之前的空格
	int count = firstmonthday;
	for (int j = 1; j <= count; j++) printf("   ");
	//打印日期
	for (int j = 1; j <= monthday; j++) {
		printf("%2d", j);
		count++;
		if (count < 7) printf(" ");
		else {
			printf("\n");
			count = 0;
		}
	}
}
int first_day(int year)
{
	if (year == 1900) return 1;
	return (first_day(year - 1) + 1 + is_leapyear(year - 1));
}
int is_leapyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 1;
	return 0;
}
int month_day(int year, int month)
{
	switch (month) {
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: return 31;
	case 2:
		if (is_leapyear(year)) return 29;
		return 28;
	case 4:case 6:case 9:case 11: return 30;
	}
}
int first_monthday(int year, int month, int firstday)
{
	if (month == 1) return firstday;
	return (first_monthday(year, month - 1, firstday) + month_day(year, month - 1) % 7);
}