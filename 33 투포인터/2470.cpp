#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b)return 1;
	else return -1;
}

int main() {
	int n, *arr,  *left, *right, re, buffl, buffr, buff;
	scanf("%d", &n);

	arr = new int[n];
	scanf("%d", arr);

	for (int* i = arr + 1; i < arr + n; i++) {
		scanf("%d", i);

	}
	
	qsort(arr, n, sizeof(int), compare);

	left = arr; right = arr + n - 1;
	buffl = *left; buffr = *right; 
	re = *left+*right>0?*left+*right:-(*left+*right);
	while (left != right) {
		buff = *left+*right>0?*left+*right:-(*left+*right);
		if (re > buff) {
			re = buff;
			buffr = *right; buffl = *left;
		}

		if (*left + *right >= re) {
			right--;
		}
		else {
			left++;
		}
	}

	printf("%d %d", buffl, buffr);
}