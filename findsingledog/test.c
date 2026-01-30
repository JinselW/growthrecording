#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//找出一个单生狗
void one_find_single_dog(int arr[], int sz, int* p) {
	*p = 0;
	for (int i = 0; i < sz; i++) {
		*p ^= arr[i];
	}
}
//找出两个单生狗
void two_find_single_dog(int arr[], int sz, int* p1, int *p2) {
	int ret = 0;
	one_find_single_dog(arr, sz, &ret);
	int i = 1;
	while (!(ret & i)) {
		i <<= 1;
	}
	for (ret = 0; ret < sz; ret++) {
		if (arr[ret] & i) {
			*p1 ^= arr[ret];
		}
		else
			*p2 ^= arr[ret];
	}
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4};
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int ret = 0;
	one_find_single_dog(arr1, sz1, &ret);
	printf("%d\n", ret);

	int arr2[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int num1 = 0, num2 = 0;
	two_find_single_dog(arr2, sz2, &num1, &num2);
	printf("%d %d\n", num1, num2);

	return 0;
}
