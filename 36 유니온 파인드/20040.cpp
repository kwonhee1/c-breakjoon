#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* arr;
int getParent(int a);
int main() {
	int n, m_, a,b;
	scanf("%d %d", &n, &m_);

	arr = new int[n];
	for (int* i = arr + n - 1; i >= arr; i--) {
		*i = -1;
	}

	for (int m = 1; m <= m_; m++) {
		int a_, b_;
		scanf("%d %d", &a_, &b_);
		a = getParent(a_);
		b = getParent(b_);

		if (a == b) {
			// ����Ŭ ���� => ����
			printf("%d", m);
			return 0;
		}
		
		if (arr[a] > arr[b]) { // b �� ������ �� ����
			arr[b] += arr[a];
			arr[a] = b;
		}
		else {
			arr[a] += arr[b];
			arr[b] = a;
		}
		//printf("input %d,%d => %d %d || arr[%d]=%d, arr[%d]=%d   ", a_, b_, a, b,a,arr[a],b,arr[b]);
	}

	printf("0");
}

int getParent(int a) {
	if (arr[a] >= 0) { // �θ� �ִٸ�
		return (arr[a] = getParent(arr[a]));
	}
	else
		return a;
}