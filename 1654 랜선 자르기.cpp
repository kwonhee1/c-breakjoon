#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, length;
long long min = 1, max = -1, stand; 
long long buff = 0;

int main() {
	scanf("%d %d", &n, &length);
	int* arr = new int[n];
	for (int* i = arr; i < arr + n; i++) {
		scanf("%d", i);
		if (max < *i) { max = *i; }
	}

	//if (buff < length) { printf("1"); return 0; }

	// start
	while (max - min > 2) {// 사이 값이 3개 초과일때
		stand = (max + min) >> 1;
		//printf("\n>> %d %d %d", min, stand, max);
		//get
		buff = 0;
		for(int *i = arr; i<arr+n; i++){
			buff += *i / stand;
		}
		//printf(" = %d", buff);
		if(buff >= length){ // 
			min = stand;
		}
		else { max = stand - 1; }
	}

	while (max >= min) {
		//printf("들어옴");
		//get
		buff = 0;
		for (int* i = arr; i < arr + n; i++) {
			buff += *i / max;
		}
		//printf("\n>> %d %d %d", min, max, buff);
		if (buff >= length) { printf("%llu", max); break;  }
		max--;
	}

	//printf("끝");
}