#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int re, now=0, n;
	scanf("%d", &n);

	// 선언부
	int* arr = new int[n];

	//입력
	for (int* arr_ = arr; arr_ < arr + n; arr_++) {
		scanf("%d", arr_);
	}
	//첫번째 값 강제 설정
	now = re = *arr;
	//실행
	for (int* arr_ = arr+1; arr_ < arr + n; arr_++) {
		int buff = *arr_;
		now = buff > now + buff ? buff : buff+now;
		if (now > re) { re = now; }
	}
	// 마지막 값 re 값과 비교
	// if (now > re) { re = now; }

	printf("%d", re);

	delete[] arr;
}