#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// p. 118

int dx[4] = { -1,0,1,0 }; int dy[4] = {0,1,0,-1};
// 북 동 남 서  -> 서 남 동 북

int main() {

	int height, width, re = 0;
	scanf("%d %d", &height, &width);
	int* arr = (int*)malloc(sizeof(int)*width*height);
	int* visite = (int*)calloc(sizeof(int) ,width * height);
	// arr[heght][width]
	int dir,x,y,n;
	scanf("%d %d %d", &x, &y, &dir);
	{
		int* arr_ = arr;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				scanf("%d", arr_++);
			}
		}
	}
	visite[x*width +y] = 1;
	while (1) {
		 n = 1;
		while(1) {
			//if (!arr[x_ + dx[dir]][y_ + dy[dir]]) {
			if (arr[width*(y+dy[dir]) +x+ dx[dir]] == 0 && visite[width * (y + dy[dir]) + x + dx[dir]] == 0) {
				visite[width * (y + dy[dir]) + x + dx[dir]] = 1;
				x += dx[dir]; y += dy[dir];
				n = 0; re++; dir++;
				if (dir == 4) { dir = 0; }
				break;
			}
			else {
				n++; dir++;
				if (dir == 4) { dir = 0; }
			}

			if (n == 4) {
				//if (arr[x_ - dx[dir]][y_ - dy[dir]]) {
				if (arr[width * (y - dy[dir]) -(x -dx[dir]) ] ) {
					printf("%d", re);
					return;
				}
				else {
					x -= dx[dir]; y -= dy[dir]; break;
				}
			}
		}
	}
}
