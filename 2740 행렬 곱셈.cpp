#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ya, x, yb;
int* a, * b;
int f(int i, int j);
int main() {
	scanf("%d %d", &ya, &x);
	a = new int[ya*x +1];

	for (int j = 1; j <= ya; j++) {
		for (int i = 0; i < ya*x; i += ya) {
			scanf("%d", &a[j + i]);
			//printf("a[%d] = %d\n", j + i, a[j + i]);
		}
	}

	/*for (int i = 1; i <= ya * x; i++) {
		printf("%d ", a[i]);
	}*/

	scanf("%d %d", &x, &yb);
	b = new int[yb*x+1];
	for (int* b_ = b + 1; b_ < b + yb * x + 1; b_++) {
		scanf("%d", b_);
	}

	for (int j = 1; j <= ya; j++) {
		for (int i = 1; i <= yb; i++) {
			printf("%d ", f(i,j));
		}
		printf("\n");
	}
}

int f(int i,int j) {
	int re = 0;
	for (int n = 0; n < x; n++) {
		//re += a[j][n * ya + j] * b[i][i + n*yb];
		re += a[n * ya + j] * b[i + n*yb];
	}
	return re;
}