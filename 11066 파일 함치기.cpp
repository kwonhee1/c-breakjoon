#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int* sum, * dp;

int main() {
	int n, all_n;
	scanf("%d", &all_n);
	while (all_n--) {
		scanf("%d", &n);

		sum = new int[n + 1];
		dp = new int[n * n + 1] {0, };
		int* arr = new int[n + 1];

		// dp[0][i] 에 입력 => i번째 값
		for (int* i = arr + 1; i <= arr + n; i++) {
			scanf("%d", i);
		}
		//입력 확인
		/*for (int* i = dp + 1; i <= dp + n; i++) {
			printf("%d ", *i);
		}
		printf("\n");*/

		//sum[i] => i번째 까지의 합
		*sum = 0;
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + arr[i];
		}
		//sum 확인 
		/*for (int i = 1; i <= n; i++) {
			printf("%d ", sum[i]);
		}
		printf("\n");*/

		int* dp_, buff;
		for (int i = 1; i < n; i++) { // dp[i][?]
			for (int j = 1; j <= n - i; j++) { // dp[i][j]
				//dp[i][j] = int 최대
				dp_ = &dp[i * n + j];
				*dp_ = 2e9;
				for (int k = j + 1; k <= i + j; k++) {
					//buff = dp[k-j-1][j] + dp[i+j-k][k]
					buff = dp[(k - j - 1) * n + j] + dp[(i + j - k) * n + k] + sum[i + j] - sum[j - 1];
					//if (buff < 0) { printf("asdf"); }
					if (buff < *dp_) { *dp_ = buff; }
				}
			}
		}

		printf("%d\n", dp[(n - 1) * n + 1]);

		delete[] arr;
		delete[] dp;
		delete[] sum;
	}
}