#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, re = 1e7, **arr;
int main() {
	int m;
	scanf("%d %d", &n, &m);

	arr = new int* [n + 1];

	// set arr
	for (int** i = arr + 1; i <= arr + n; i++) {
		*i = new int[n + 1];
		for (int* j = *i; j <= *i + n; j++) {
			*j = 1e7;
		}
	}

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int y = 1; y < i; y++) {
			for (int x = 1; x < i; x++) {
				if (arr[y][x] > arr[y][i] + arr[i][x])
					arr[y][x] = arr[y][i] + arr[i][x];
			}
			for (int x = i+1; x <= n; x++) {
				if (arr[y][x] > arr[y][i] + arr[i][x])
					arr[y][x] = arr[y][i] + arr[i][x];
			}
		}
		for (int y = i+1; y <=n; y++) {
			for (int x = 1; x < i; x++) {
				if (arr[y][x] > arr[y][i] + arr[i][x])
					arr[y][x] = arr[y][i] + arr[i][x];
			}
			for (int x = i + 1; x <= n; x++) {
				if (arr[y][x] > arr[y][i] + arr[i][x])
					arr[y][x] = arr[y][i] + arr[i][x];
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/

	for (int i = 1; i <= n; i++) {
		if (re > arr[i][i])
			re = arr[i][i];
	}

	if (re == 1e7)
		printf("-1");
	else
		printf("%d", re);
}
