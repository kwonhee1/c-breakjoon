#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long* arr;

int get(int n) {
	if (n == 1) { return 1; }
	if (n == 2) { return 1; }
	return get(n - 1) + get(n - 2);
}

long long get2(int n) {
	arr[1] = 1; arr[2] = 1;
	for (int i = 3; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n-2]+arr[n-1];
}

int main() {
	int n;
	scanf("%d", &n);
	arr = new long long[n]; // 1 ~ n-1

	if (!n) { printf("%d", 0); }
	else if (n == 1) { printf("%d", 1); }
	else if (n == 2) { printf("%d", 1); }
	else { printf("%llu", get2(n)); }
}