#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f(int x, int y, int value);

int n, m, ** arr,
	dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int main() {
	scanf("%d %d", &m, &n);

	arr = new int*[m];
	for (int** i = arr, buff; i < arr + m; i++) {
		*i = new int[n] {0, };
		for (int * j = *i; j<*i+n; j++) {
			buff = getchar();
			if (buff == '\n') { j--; }
			else if (buff == 49) { *j = 2e9; }
		}
	}

	/*printf("\n");
	for (int** i = arr; i < arr + m; i++) {
		for (int* j = *i; j < *i + n; j++) {
			printf("%d ", *j);
		}
		printf("\n");
	}*/

	f(0, 0, 1);

	printf("%d", arr[m - 1][n - 1]);
}

void f(int x, int y,int value) {
	arr[y][x] = value++;

	//printf("(%d,%d)=%d\n", x, y, arr[y][x]);

	for (int i = 0; i < 4; i++) {
		int x_ = x + dx[i], y_ = y+dy[i];
		// check x_,y_ 
		if (0 <= x_ && x_ < n && 0 <= y_ && y_ < m) {
			if (arr[y_][x_] && value < arr[y_][x_]) {
				f(x_, y_, value);
			}
		}

	}
}