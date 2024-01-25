#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#define swap(a,b); {int buff = a; a = b; b= buff;}
void sort(int* arr, int start, int end);
int main() {
	int m;
	scanf("%d", &m);
	int* arr_ = new int[m];
	//arr_ �Է� �ޱ�
	int** arr = new int*[m];

	int* ar_ = arr_;
	int** ar_ = arr;
	for (int i = 0; i < m; i++) {
		arr[i] = &arr_[i];
	}

}

void sort_() {

}

void sort(int* arr, int start, int end) {
	if (end - start < 1) {
	}
	else if (end - start == 1) {
		if (arr[start] > arr[end]) { swap(arr[start], arr[end]); }
	}
	else {
		int stand = arr[start]; //������ �����

		int* left = &arr[start + 1];
		int* right = &arr[end];

		while (left < right) {
			while (left < right && *left <= stand) { left++; }
			while (left < right && stand <= *right) { right--; }

			swap(*left, *right);
		}
		//���� left == right �� ���� 

		if (*left < stand) {
			swap(*left, arr[start]);
		}
		else {
			left--;
			swap(*left, arr[start]);
		}
		int left_ =  (int)(left - &arr[start]) + start; //left�� �ε����� ����
		sort(arr, start, left_-1);
		sort(arr, left_+1, end);
	}
}


void sort2(int* arr, int start, int end) {
	if (end - start < 1) {
	}
	else if (end - start == 1) {
		if (arr[start] > arr[end]) { swap(arr[start], arr[end]); }
	}
	else {
		int stand = arr[start];

		int left = start + 1;
		int right = end;

		while (left < right) {
			while (left < right && arr[left] <= stand) { left++; }
			while (left < right && stand <= arr[right]) { right--; }

			swap(arr[left], arr[right]);
		}
		//���� left == right �� ���� 

		if (arr[left] < stand) {
			swap(arr[left], arr[start]);
		}
		else {
			left--;
			swap(arr[left], arr[start]);
		}

		sort(arr, start, left - 1);
		sort(arr, left + 1, end);
	}
}