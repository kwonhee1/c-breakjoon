#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// #include <bitset>

int start, end, arr_count;
int* arr_, *arr_end, *arr;

void f(int start, int count) {
	// ��� arr�� start ����
	//printf("arr[%d] = %d\n",count,start);
	arr[count] = start;

	//������ ������ �Լ��϶�
	if (count == arr_count-1) {
		//arr�� �ִ� ���빰 ����ϱ�
		arr_ = arr; while(arr_<=arr_end) { printf("%d ", *arr_++); }
		printf("\n");
	}
	//������ ������ �ƴҶ�
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