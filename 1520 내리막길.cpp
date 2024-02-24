#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �� �� �� ��
int dx[4] = { 0,0,-1,1};
int dy[4] = { -1,1,0,0};

int** arr, **re;
int n, m;

int dfs(int x, int y);

int main() {
	scanf("%d %d", &n, &m);
	
	arr = new int* [n];
	for (int** arr_ = arr; arr_ < arr + n; arr_++) {
		*arr_ = new int[m];
		for (int* arr__ = *arr_; arr__ < *arr_ + m; arr__++) {
			scanf("%d", arr__);
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}*/

	re = new int* [n];
	for (int** re_ = re; re_ < re + n; re_++) {
		*re_ = new int[m];
		for (int* re__ = *re_; re__ < *re_ + m; re__++) {
			*re__ = -1;
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", re[i][j]);
		}
		printf("\n");
	}*/

	if (n == 1 && m == 1) { printf("1"); return 0; }

	re[n - 1][m - 1] = 1;

	int res = dfs(0, 0);
	if (res == -1) { printf("0"); }
	else { printf("%d", res); }
}

int dfs(int x, int y) {
	int x_, y_;
	re[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		x_ = dx[i] + x;
		y_ = dy[i] + y;
		//���� Ȯ��
		if (0 > x_ || 0 > y_ || m <= x_ || n <= y_) { continue; }		
		// (x,y) -> (x_,y_)�� ���� �ִ��� Ȯ��
		if (arr[y][x] <= arr[y_][x_]) { continue; }
		int re_ = re[y_][x_];
		//printf("���� : re[%d][%d]->(%d,%d) = %d\n", y, x, y_, x_, re[y][x]);
		
		// ��ǥ ����
		
		// ���� �� ����
		if (re_ == -1) {
			re[y][x] += dfs(x_, y_);
		}
		// �̹� Ž���� ����
		else {
			re[y][x] += re_;
		}
		//printf("�� : re[%d][%d] = %d", y, x, re[y][x]);
	}
	//printf("��ȯ : %d\n", re[y][x]);
	return re[y][x];
}