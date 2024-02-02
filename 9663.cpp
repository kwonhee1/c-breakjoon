#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, re = 0;
int* x_arr, *y_arr, *c1_arr, *c2_arr;

void f(int count, int y) {
	//for (int j = y-1; j; j--) { //y 
	//	for (int i = n; i; i--) { //x
	//		//확인
	//		if (y_arr[j]) { //  0 이면 퀸 사용 불가
	//			if (x_arr[i] && c1_arr[i + j] && c2_arr[n - j + i]) {
	//				// 가능하다면
	//				//printf("%d %d\n", i, j);

	//				if (!count) { re++; continue; }

	//				//퀸 추가
	//				//printf("add\n");
	//				x_arr[i] = 0; y_arr[j] = 0; 
	//				c1_arr[i + j] = 0; c2_arr[n - j + i] = 0;
	//				
	//				f(count - 1, j);
	//				// 퀸 삭제
	//				//printf("remove\n");
	//				x_arr[i] = 1; y_arr[j] = 1;
	//				c1_arr[i + j] = 1; c2_arr[n - j + i] = 1;
	//			}
	//		}
	//		else { break; }
	//	}
	//}
	for (int i = n; i; i--) { //x (1~n) 
		// 가능하다면 
		if (x_arr[i] && c1_arr[i + y] && c2_arr[n - y + i] && y_arr[y]) {
			if (!count) { re++; continue; }

			//퀸 생성
			x_arr[i] = 0; y_arr[y] = 0;
			c1_arr[i + y] = 0; c2_arr[n - y + i] = 0;

			f(count - 1, y - 1);

			//퀸 제거
			x_arr[i] = 1; y_arr[y] = 1;
			c1_arr[i + y] = 1; c2_arr[n - y + i] = 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	x_arr = new int[n+1];
	y_arr = new int[n+1];
	c1_arr = new int[(n << 1)+1];
	c2_arr = new int[(n << 1)+1];

	for (int i = n; i; i--) {
		x_arr[i] = y_arr[i] = 1;
	}
	for (int i = n<<1; i; i--) {
		c1_arr[i] = c2_arr[i] = 1;
	}
	
	f(n-1, n);
	printf("%d", re);

	delete[] x_arr;
	delete[] y_arr;
	delete[] c1_arr;
	delete[] c2_arr;
}