#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

#define swap(a,b); {int buff = a; a = b; b= buff;}
#define swap_(a,b); {int* buff =a; a=b; b=buff;}

void q_sort(int* arr, int* start, int* end);
//void q_sort2(int* arr, int start, int end);
void h_sort(int* arr, int index);

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

	//q_sort2(n_arr, 0, n-1);
	//q_sort(n_arr, n_arr, &n_arr[n-1]);

	h_sort(n_arr,n-1);
	/*n_arr_ = n_arr;
	for (int i = 0; i < n; i++) {
		printf("%d", *n_arr_++);
	}
	printf("\n");*/
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

void h_sort_(int* arr, int index) {
	if (index < 3) {
		swap(arr[0], arr[index]);
	}
	else { h_sort_(arr, (index >> 1) - 1); swap(arr[index], arr[(index >> 1) - 1]); }
}

void h_sort(int *arr, int index) { //제일 큰 값을 찾아서 뒤로 보내기 -> 오름차순 정렬
	for (; index > 2; index--) { // 맨위 3개(0~2) 는 따로 계산 
		// 한회차 정렬 ( 가장 큰값 맨 위로)
		for (int i = index; i > 2; i--) {
			// 부모 노드와 비교 후  교환
			if (arr[i] > arr[ (i>>1) - 1]) { swap(arr[i], arr[ (i>>1)-1]); }
		}
		// (0~2) 까지 계산
		if (arr[2] > arr[0]) { swap(arr[2], arr[0]); }
		if (arr[1] > arr[0]) { swap(arr[1], arr[0]); }
		//header node 맨 밑으로
		h_sort_(arr, index);
		//swap(arr[0], arr[index_]);
	}
	// 마지막 3개 정렬 -> 제일 작은 값이 앞으로 가게
	if (arr[2] < arr[1]) { swap(arr[2], arr[1]); }
	if (arr[1] < arr[0]) { swap(arr[1], arr[0]); }
	if (arr[2] < arr[1]) { swap(arr[2], arr[1]); }
}

void q_sort(int* arr, int* start, int* end) { //3
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
		q_sort(arr, start, left-1);
		q_sort(arr, left+1, end);
	}
}

//
//void q_sort2(int* arr, int start, int end) { //측정 불가
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
//		q_sort2(arr, start, left - 1);
//		q_sort2(arr, left + 1, end);
//	}
//}

//10
//5 4 8 7 9 6 1 3 10 2
