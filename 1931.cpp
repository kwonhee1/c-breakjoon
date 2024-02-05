#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct dis {
	int start;
	int end;
};

int compare(const void* a, const void* b) {
	// 끝 시간이 같다면 시작 시간 기준
	if (((struct dis*)a)->end == ((struct dis*)b)->end) {
		return ((struct dis*)a)->start > ((struct dis*)b)->start;
	}
	else {
		return ((struct dis*)a)->end > ((struct dis*)b)->end;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	struct dis* arr = new struct dis[n];

	//struct dis arr 입력
	for (struct dis* arr_ = arr; arr_ < arr + n; arr_++) {
		scanf("%d %d", &arr_->start, &arr_->end);
	}

	//정렬
	qsort(arr, n, sizeof(struct dis), compare);

	//정렬 확인
	/*for (struct dis* arr_ = arr; arr_ < arr + n; arr_++) {
		printf("(%d,%d) ", arr_->start, arr_->end);
	}*/

	//실행 정렬된 배열을 돌면서 가능하다면 받기
	int end_time = 0, re = 0;
	for (struct dis* arr_ = arr; arr_ < arr + n; arr_++) {
		if (end_time <= arr_->start) {
			// 사용가능
			re++;
			end_time = arr_->end;
		}
	}

	printf("%d", re);

	delete[] arr;
}
