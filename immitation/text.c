#define _CRT_SECURE_NO_WARNINGS
 
#include "headfile.h"

int compare(void* e1, void* e2) {
    return *(int*)e1 - *(int*)e2;
}


int main() {
    int arr[] = { 5,4,6,5,6,2,1,8,9 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    my_qsort(arr, sizeof(int), sz, compare);
    for (int i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    return 0;
}