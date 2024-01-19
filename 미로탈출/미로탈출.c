#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include "que.h"

int main() {
	int width, height;
	scanf("%d %d", &width, &height);
	int px = 1, py = 1, re = 0;
	X = width; Y = height;
	
	int* arr = (int*)malloc(sizeof(int) * width * height);
	int* arr_ = arr;
	for (int i = width * height; i != 0; i--) {
		scanf(" %d", arr_++);
	}

	//arr[py][px] = ++re;
	arr[py*width+px] = ++re;
	que_add(px,py);

	struct xy t;
	while( (t = que_pop() ).x != -1) {
		px = t.x; py = t.y;
		arr[py * width + px] = ++re;
		que_add(px, py);

		//»ó
		//if (arr[py - 1][px] != 1 && >re) { que_add(px, py - 1); }
		if (arr[(py-1)*width+px]!=1 && arr[(py - 1) * width + px]>=re) { que_add(px, py - 1); }
	}
}