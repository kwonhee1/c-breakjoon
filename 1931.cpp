#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct dis {
	int start;
	int end;
};

int compare(const void *a, const void* b) {
	return ((struct dis*)a)->end > ((struct dis*)b)->end;
}

int main() {
	int n;
	scanf("%d", &n);
	struct dis* arr = new struct dis[n];

	//struct dis arr �Է�
	for (struct dis* arr_ = arr; arr_ < arr + n; arr_++) {
		scanf("%d %d", &arr_->start, &arr_->end);
	}

	//����
	qsort(arr, n, sizeof(struct dis), compare);

	//���� Ȯ��
	/*for (struct dis* arr_ = arr; arr_ < arr + n; arr_++) {
		printf("(%d,%d) ", arr_->start, arr_->end);
	}*/

	//���� ���ĵ� �迭�� ���鼭 �����ϴٸ� �ޱ�
	int end_time = 0, re = 0;
	for (struct dis* arr_ = arr; arr_ < arr + n; arr_++) {
		if (end_time < arr_->start) {
			// ��밡��
			re++;
			end_time = arr_->end;
		}
	}

	printf("%d", re);

	delete[] arr;
}