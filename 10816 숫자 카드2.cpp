#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void*a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else { return -1; }
}
int compare2(const void* a, const void* b) {
	if (**(int**)a > **(int**)b) {return 1;}
	else { return -1; }
}

int main() {
	int n, m;
	scanf("%d", &n);
	int *narr = new int[n];
	for (int* i = narr; i < narr + n; i++) {
		scanf("%d",i);
	}
	scanf("%d", &m);
	int* marr = new int[m<<1] {0,}; // m의 2배
	for (int* i = marr; i < marr + m; i++) {
		scanf("%d", i);
	}
	//포인터 배역 생성 밑 매칭
	int** parr = new int* [m];
	int** parr_ = parr;
	int* j = marr;
	while (parr_ < parr + m) {
		*parr_++ = j++;
		//parr_++; j++;
	}

	// 정렬 작은게 앞으로 오게
	qsort(narr, n,sizeof(int),compare);
	/*printf("정렬확인\n");
	for (int* i = narr; i < narr + n; i++) {
		printf("%d ", *i);
	}*/

	qsort(parr, m,sizeof(int*),compare2);
	/*printf("\n");
	for (int** i = parr; i < parr + m; i++) {
		printf("%d ", **i);
	}
	printf("\n");*/
	// start
	int *i = narr;
	parr_ = parr;
	while(parr_ < parr + m && i<narr+n) {
		if (parr_!=parr && **(parr_-1) == **parr_) {
			*(*parr_ + m) = *(*(parr_-1) + m);
			parr_++;
		}
		else if (*i == **parr_) {
			//같은 값을 찾았을때
			*(*parr_ + m)+=1;
			i++;
		}
		else if (*i > **parr_) {
			// i의 값이 더 클때
			parr_++;
		}
		else{
			// j의 값이 더 클때
			i++;
		}
	}
	// 남아있는 값들중 마지막 값이랑 같은 값이 존재한다면
	parr_++;
	while (parr_ < parr + m) {
		if ( **(parr_ - 1) == **parr_) {
			*(*parr_ + m) = *(*(parr_ - 1) + m);
			parr_++;
		}
		else {
			break;
		}
	}

	// 출력 
	//printf("\n출력\n");
	for (int* i = marr+m; i < marr + (m<<1); i++) {
		printf("%d ", *i);
	}
}