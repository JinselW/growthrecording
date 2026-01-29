#define _CRT_SECURE_NO_WARNINGS

#include "headfile.h" 

size_t my_strlen(const char* p) 
{
    assert(p);
    size_t count = 0;
    while (*(p++))
        count++;
    return count;
}

char* my_strcpy(char* goal, const char* source) 
{
    assert(goal && source);
    int i = -1, j = -1;
    while (1) {
        i++; j++;
        goal[i] = source[j];
        if (!source[j]) return goal;
    }
}

char* my_strcat(char* goal, const char* source) 
{
    assert(goal && source);
    int i = 0, j = -1;
    while (goal[i++]);
    i -= 2;
    while (1) {
        i++; j++;
        goal[i] = source[j];
        if (!source[j]) return goal;
    }
}

int my_strcmp(const char* str1, const char* str2)
{
    assert(str1 && str2);
    int i = 0, j = 0;
    while (1) {
        if (str1[i] && str2[j] && str1[i] == str2[j]) {
            i++; j++;
        }
        else return str1[i] - str2[j];
    }
}

char* my_strstr(const char* str1, const char* str2)
{
    assert(str1 && str2);
    int i = 0, j = 0;
    while (str1[i]) {
        if (str1[i] == str2[j]) {
            i++; j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
        if (!str2[j]) return str1 + i - j;
    }
    if (str2[j]) return NULL;
    else return str1;


}

void* my_memmove(void* goal, const void* source, size_t num) 
{
    assert(goal && source);
    char* ret1 = (char*)goal;
    char* ret2 = (char*)source;
    if (source < goal) {
        for (int i = num - 1; i >= 0; i--) {
            ret1[i] = ret2[i];
        }
    }
    else {
        for (int i = 0; i < num; i++) {
            ret1[i] = ret2[i];
        }
    }
    return source;

}

void my_qsort(void* arr, size_t size, size_t num, int (*fun)(void* e1, void* e2))
{
    char* sub = (char*)arr;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - 1 - i; j++) {
            if (fun(sub + j * size, sub + (j + 1) * size) > 0) {
                for (int p = 0; p < size; p++) {
                    char ret = *(sub + (j + 1) * size + p);
                    *(sub + (j + 1) * size + p) = *(sub + j * size + p);
                    *(sub + j * size + p) = ret;
                }
            }
        }
    }
}

