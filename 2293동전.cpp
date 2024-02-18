#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n,*input, goal, **dp;

int main() {
	scanf("%d %d", &n, &goal);
	input = new int[n];
	// input �Է�
	for (int* i = input; i < input + n; i++) {
		scanf("%d", i);
	}

	// dp���� dp[i][j] 
	//	=> i���� ���� ����Ͽ� j�ݾ��� ����� ������
	//		=> dp[i][j] = 0�ΰ�� ����� ����
	dp = new int*[n];
	// input[0][ 1~input[0] ]=> 0
	dp[0] = new int[goal+2];
	int buff = input[0];
	for (int i = 0; i <= goal; i++) { 
		if (i % buff)
			dp[0][i] = 0;
		else
			dp[0][i] = 1;
	}

	for (int y = 1; y < n; y++) {
		dp[y] = new int[goal + 2] {0, };
		dp[y][0] = 1;
		for (int x = 1; x <= goal; x++) {
			for (int k = 0; k <= x / input[y]; k++) {
				dp[y][x] += dp[y-1][x - input[y] * k];
			}
			//printf("dp[%d][%d] = %d\n", y, x, dp[y][x]);
		}
		delete[] dp[y - 1];
	}

	printf("%d", dp[n-1][goal]);
}