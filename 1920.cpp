#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

#define swap(a,b); {int buff = a; a = b; b= buff;}
#define swap_(a,b); {int* buff =a; a=b; b=buff;}

void sort(int* arr, int* start, int* end);
//void sort2(int* arr, int start, int end);
int find(int* arr, int start, int end, int value);
int main() {
	
	int n;
	scanf("%d", &n);
	int* n_arr = new int[n];
	int* n_arr_ = n_arr;
	for (int i = 0; i < n; i++) {
		//scanf("%d", &n_arr_[i]);
		scanf("%d", n_arr_++);
	}

	//sort2(n_arr, 0, n-1);
	sort(n_arr, n_arr, &n_arr[n-1]);
	
	int m, in;
	scanf("%d", &m);
	for (; m != 0; m--) {
		scanf("%d", &in);
		printf("%d\n", find(n_arr, 0, n - 1, in)!=-1);
	}
	
}

int find(int* arr, int start, int end, int value) { // return index or -1
	int stand; 
	while (end - start > 1) { // 2개 이상
		stand = (start + end) >> 1;
		if (arr[stand] == value) { return stand; }
		else if (arr[stand] < value) { start = stand+1; }
		else { end = stand-1; }
	}
	if (arr[start] == value) { return start; }
	else if(arr[end] == value) {return end; }
	else {return -1;}
}

void sort(int* arr, int* start, int* end) { //3
	if (end - start < 1) {
	}
	else if (end - start == 1) {
		if (*start > *end) { swap(*start, *end); }
	}
	else {
		int stand = *start; //값으로 저장됨

		int* left = start+1;
		int* right = end;

		while (left < right) {
			while (left < right && *left <= stand) { left++; }
			while (left < right && stand <= *right) { right--; }

			swap(*left, *right);
		}
		//종료 left == right 인 상태 

		if (*left < stand) {
			swap(*left, *start);
		}
		else {
			left--;
			swap(*left, *start);
		}
		sort(arr, start, left-1);
		sort(arr, left+1, end);
	}
}

//
//void sort2(int* arr, int start, int end) { //측정 불가
//	if (end - start < 1) {
//	}
//	else if (end - start == 1) {
//		if (arr[start] > arr[end]) { swap(arr[start], arr[end]); }
//	}
//	else {
//		int stand = arr[start];
//
//		int left = start + 1;
//		int right = end;
//
//		while (left < right) {
//			while (left < right && arr[left] <= stand) { left++; }
//			while (left < right && stand <= arr[right]) { right--; }
//
//			swap(arr[left], arr[right]);
//		}
//		//종료 left == right 인 상태 
//
//		if (arr[left] < stand) {
//			swap(arr[left], arr[start]);
//		}
//		else {
//			left--;
//			swap(arr[left], arr[start]);
//		}
//
//		sort2(arr, start, left - 1);
//		sort2(arr, left + 1, end);
//	}
//}

//10
//5 4 8 7 9 6 1 3 10 2
