#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int re, now=0, n;
	scanf("%d", &n);

	// �����
	int* arr = new int[n];

	//�Է�
	for (int* arr_ = arr; arr_ < arr + n; arr_++) {
		scanf("%d", arr_);
	}
	//ù��° �� ���� ����
	now = re = *arr;
	//����
	for (int* arr_ = arr+1; arr_ < arr + n; arr_++) {
		int buff = *arr_;
		now = buff > now + buff ? buff : buff+now;
		if (now > re) { re = now; }
	}
	// ������ �� re ���� ��
	// if (now > re) { re = now; }

	printf("%d", re);

	delete[] arr;
}