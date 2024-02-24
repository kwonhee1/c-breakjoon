#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long* arr;

int get(int n) { // 2747¹ø
	if (n == 1) { return 1; }
	if (n == 2) { return 1; }
	return get(n - 1) + get(n - 2);
}

long long get2(int n) { //2748¹ø
	arr[1] = 1; arr[2] = 1;
	for (int i = 3; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n-2]+arr[n-1];
}
int get3(int n) { //1904
	int buff1=1, buff2=1, re=2;
	for (int i = 3; i < n; i++) {
		buff2 = buff1% 15746;
		buff1 = re%15746;
		re = buff1 + buff2;
	}
	return re%15746;
}

int main() {
	int n;
	scanf("%d", &n);
	//arr = new long long[n]; // 1 ~ n-1

	if (!n) { printf("%d", 0); }
	else if (n == 1) { printf("%d", 1); }
	else if (n == 2) { printf("%d", 2); }
	else if (n == 3) { printf("%d", 3); }
	else { printf("%llu", get3(n+1)); }
}