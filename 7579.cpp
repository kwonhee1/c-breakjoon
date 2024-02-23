#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct st {
	int mem;
	int value;
};

int n, m, **dp;
struct st* arr;

int main() {
	scanf("%d %d", &n, &m);
	arr = new struct st[n];
	for (struct st* i = arr; i < arr + n; i++) {
		scanf("%d", &i->mem);
	}
	for (struct st* i = arr; i < arr + n; i++) {
		scanf("%d", &i->value);
	}

	if (n == 1) {
		printf("%d", arr[0].value);
		return 0;
	}

	//dp 생성
	dp = new int* [n];

	dp[0] = new int[10001] {0, };
	//y = 0일때 값 설정
	int buff = arr[0].value, buff2 = arr[0].mem;
	for (int x = 0; x < 10001; x++) {
		if (x < buff) dp[0][x] = 0;
		else dp[0][x] = buff2;

		//printf("dp[%d][%d] = %d\n", 0, x, dp[0][x]);
	}

	for (int y = 1; y < n-1; y++) {
		dp[y] = new int[10001] {0, };
		for (int x = 0; x < 10001; x++) {
			if (x >= arr[y].value) {
				dp[y][x] = dp[y - 1][x] > dp[y - 1][x - arr[y].value] + arr[y].mem ? dp[y - 1][x] : dp[y - 1][x - arr[y].value] + arr[y].mem;
			}
			else { dp[y][x] = dp[y - 1][x]; }

			//printf("dp[%d][%d] = %d | %d %d\n", y, x, dp[y][x], dp[y - 1][x], dp[y - 1][x - arr[y].value] + arr[y].mem);
		}
	}

	int y = n - 1;
	dp[y] = new int[10001] {0, };
	for (int x = 0; x < 10001; x++) {
		if (x >= arr[y].value) {
			dp[y][x] = dp[y - 1][x] > dp[y - 1][x - arr[y].value] + arr[y].mem ? dp[y - 1][x] : dp[y - 1][x - arr[y].value] + arr[y].mem;
		}
		else { dp[y][x] = dp[y - 1][x]; }
	//printf("dp[%d][%d] = %d | %d %d\n", y, x, dp[y][x], dp[y - 1][x], dp[y - 1][x - arr[y].value] + arr[y].mem);
		if (dp[y][x] >= m) { printf("%d", x); break; }
	}
}