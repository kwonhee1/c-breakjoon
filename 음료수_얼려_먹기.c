#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// p. 149

int re = 0;
char* arr;
int width, height;

void add(int x, int y) {
	arr[y * width + x] = 1;
	int x_, y_;
	//우
	if ( (x_ = x + 1) < width) {
		if (arr[y * width + x_] == 0) {
			add(x_, y);
		}
	}
	// 좌
	if (0 < (x_ = x - 1) ) {
		if (arr[y * width + x_] == 0) {
			add(x_, y);
		}
	}
	//상
	if ((y_ = y + 1) < height) {
		if (arr[y_ * width + x] == 0) {
			add(x, y_);
		}
	}
	//하
	if (0<(y_ = y - 1) ) {
		if (arr[y_ * width + x] == 0) {
			add(x, y_);
		}
	}
}

int main() {
	
	scanf("%c %c ", &width, &height);
	width -= '0'; height -= '0';
	//printf("%d %d", width, height);
	arr = (char*)calloc(width*height,sizeof(char));

	//입력
	char* arr_ = arr;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			scanf(" %c", arr_);
			*arr_++ -= '0';
			//printf("%d", *arr_++);
		}
		
	}

	/*arr_ = arr;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%d", *arr_++);
		}
		printf("\n");
	}*/

	//실행
	arr_ = arr;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {//arr 전체에 대하여 스캔 진행
			if (arr[(i * width) + j] == 0) { //(x,y)가 0인경우
				re++;
				add(j, i);
			}
		}
	}

	printf("%d", re);
}