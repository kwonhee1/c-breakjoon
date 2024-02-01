#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* out_arr, *out_arr_, *arr, *arr_;
int arr_count, out_count;

void f(int count) {
	/*printf("출력확인");
	for (int i = out_count-1; i != 0; i--) {
		printf("%d ", out_arr[i]);
	}
	printf("\n");*/

	//만약 마지막 이라면
	if(!count) { //out_count == 0 이라면
		//arr_ = arr;
		for (int i = 1; i<=arr_count; i++) {
		//for(arr_ = arr; arr_!= arr+arr_count; arr_++){
			// 해당 값이 들린 값이 아니라면
			if(!arr[i]) {
				//out_arr 에 값하고 출력
				for (out_arr_ = &out_arr[out_count - 1]; out_arr_ > out_arr; out_arr_--){
					printf("%d ", *out_arr_); 
				}
				printf("%d\n", i);
			}
		}
	}
	// 마지막이 아니라면
	else {
		for(int i = 1; i<=arr_count; i++){
			if (!arr[i]) {
				arr[i] = 1; out_arr[count] = i;
				f(count - 1);
				arr[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &arr_count, &out_count);
	out_arr = new int[out_count];
	arr = new int[arr_count+1];
	
	//arr 초기화
	arr_ = arr;
	for (int i = arr_count+1; i; i--) {
		*arr_++ = 0;
	}

	// 함수 실행
	f(out_count - 1);
}