#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int n, m, ** arr;
	scanf("%d %d", &n, &m);

	arr = new int* [n];

	for (int y = 0; y < n; y++) {
		arr[y] = new int[n];
		for (int x = 0; x < y; x++) {
			getchar();
			arr[y][x] = getchar() - 48;
		}
		getchar(); getchar();
		arr[y][y] = 1;
		for (int x = y+1; x < n; x++) {
			getchar();
			arr[y][x] = getchar() - 48;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < y; x++) {
				if (!arr[y][x]) {
					for (int z = 0; z < n; z++) {
						if (arr[y][z] && arr[z][x]) {
							arr[y][x] = 1; break;
						}
					}
				}
			}
			// y == x
			for (int x = y + 1; x < n; x++) {
				if (!arr[y][x]) {
					for (int z = 0; z < n; z++) {
						if (arr[y][z] && arr[z][x]) {
							arr[y][x] = 1; break;
						}
					}
				}
			}
		}
	}

	/*printf("\n");
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
	printf("\n");*/
	
	int a, b;
	scanf("%d", &a);
	a--;
	while (--m) {
		scanf("%d", &b);
		b--;
		if (!arr[a][b]) {
			printf("NO"); return 0;
		}
		a = b;
	}
	printf("YES");
	return 0;
}