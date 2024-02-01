#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <bitset>

int start, end, arr_count;
int* arr_, *arr_end, *arr;

void f(int start, int count) {
	// 출력 arr에 start 저장
	//printf("arr[%d] = %d\n",count,start);
	arr[count] = start;

	//마지막 루프의 함수일때
	if (count == arr_count-1) {
		//arr에 있는 내용물 출력하기
		arr_ = arr; while(arr_<=arr_end) { printf("%d ", *arr_++); }
		printf("\n");
	}
	//마지막 루프가 아닐때
	else {
		for (int i = start+1; i <= end; i++) {
			f(i, count + 1);
		}
	}
}

int main() {
	scanf("%d %d", &end, &arr_count);
	arr = new int[arr_count];

	arr_ = arr;
	arr_end = &arr[arr_count-1];

	//f(1,0);
	for (int i = 1; i <= end; i++) {
		f(i, 0);
	}
}