#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define swap(a,b) {buff = a; a = b; b = buff;}

int n, * arr, buff;

void print_all(int* start, int* end) {
	printf("%d %d >> \n", start - arr, end - arr);
	for (int* i = arr; i < arr + n; i++) {
		printf("%d ", *i);
	}
	printf("\n");
}

void qsort(int* start, int* end) {
	print_all(start, end);

	if (end - start < 1) {
		return;
	}
	else if(end - start == 1) { // end , start 
		if (*start > *end) swap(*end, *start)
		return;
	}

	// 3개 이상일시 돌리겠음
	int* stand = start, *left = start + 1, *right = end;
	while (1) {
		while (*left <= *stand && left < right) { left++; }
		while (*stand <= *right && left < right) { right--; }

		if (left == right) {
			break;
		}
		swap(*left, *right)
	}
	if (*left > *stand) {
		left--;
	}
	swap(*left, *stand)
	qsort(start, left - 1);
	qsort(left + 1, end);
}

int main() {
	printf("input int of number to sort >>");
	scanf("%d", &n);
	
	arr = malloc(sizeof(int) * n);

	for (int i = 1, *j = arr; i <= n; i++,j++) {scanf("%d", j);}

	//sort
	qsort(arr, arr+n-1);

	for (int* i = arr; i < arr + n; i++) {
		printf("%d", *i);
	}
}