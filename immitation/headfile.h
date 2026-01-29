#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t my_strlen(const char* p);
char* my_strcpy(char* goal, const char* source);
char* my_strcat(char* goal, const char* source);
int my_strcmp(const char* str1, const char* str2);
char* my_strstr(const char* str1, const char* str2);
void* my_memmove(void* goal, const void* source, size_t num);
void my_qsort(void* arr, size_t size, size_t num, int (*fun)(void* e1, void* e2));
