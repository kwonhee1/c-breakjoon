#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, m, ** dp, * arr, * value, a, b;
	scanf("%d %d", &n, &m);

	arr = new int[n]; value = new int[n];

	for (int* i = arr, *j = value; i < arr + n; i++, j++) {
		scanf("%d %d", &a, &b);
		*i = a; *j = b;
	}

	dp = new int* [n];
	*dp = new int[m + 1];
	for (int i = 0; i < *arr; i++) {
		(*dp)[i] = 0;
	}
	for (int i = *arr; i <= m; i++) {
		(*dp)[i] = *value;
	}

	for (int i = 1; i < n; i++) {
		dp[i] = new int[m + 1];
		for (int j = 0; j <= m; j++) {
			if (j < arr[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j] < dp[i - 1][j - arr[i]] + value[i])
					dp[i][j] = dp[i - 1][j - arr[i]] + value[i];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/

	printf("%d", dp[n - 1][m]);
}