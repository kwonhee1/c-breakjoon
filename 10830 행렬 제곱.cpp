#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n; long long m;
int* arr;
int* get(long long n);
int* f(int* a1, int* a2);

int main() {
	scanf("%d %llu", &n, &m);

	arr = new int[n * n + 1]; //ù��° arr[1]

	//ù��° ��� �Է�
	for (int* arr_ = arr+1; arr_ <= arr + n*n; arr_++) {
		scanf("%d", arr_);
	}
	//�Է� Ȯ��
	/*printf("�Է� Ȯ��\n");
	for (int i = 1; i <= n*n; i++) {
		printf("%d ", arr[i]);
	}*/

	if (m == 1) {
		for (int i = 1; i <= n * n;) {
			for (int j = n; j; j--, i++) {
				printf("%d ", arr[i]%1000);
			}
			printf("\n");
		}
		return 0;
	}

	int *arr_ = get(m);
	for (int i = 1; i <= n*n;) {
		for (int j = n; j; j--,i++) {
			printf("%d ", arr_[i]);
		}
		printf("\n");
	}
}

// �࿭ ���� �����ִ� �Լ�
int* get(long long n){
	if (n == 1) { return arr; }
	else if(n%2){ //Ȧ���϶�
		int* arr_ = get(n >> 1);
		return f(f(arr_, arr_), arr);
	}
	else { //¦���϶�
		int* arr_ = get(n >> 1);
		return f(arr_, arr_);
	}
	
}

int* f(int* a1, int* a2) { //��� �� �� ���ϴ� �Լ�
	int* re = new int[n * n + 1] {0, };

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			for (int i = 0; i < n; i++) {
				re[(y-1)*n+x] = ( re[(y - 1) * n + x] + a1[(y-1)*n + i+1] * a2[i*n +x] )%1000;
			}
		}
	}
	return re;
}