#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cp(const void*a, const void *b) {
	if( *(char*)a > *(char*)b ) return 1;
	else return -1;
}

int ca(const void* a, const void* b) {
	if (**(char**)a > **(char**)b) { return 1; }
	else { return -1; }
}

int main() {
	int n, m = 0;
	char *str,  **arr;
	
	str = new char[1000001] {0, };
	arr = new char* [1000001] {0, };
	
	char* str_ = str - 1, ** arr_ = arr;

	while (*str_++ != 10) {
		scanf("%c", str_);
		*arr_++ = str_;
	}
	n = str_ - str-1;
	char pop[37]{ 0, }, *pop_ = pop;
	scanf("%s", pop);

	while (*pop_++) { m++; }
	//정렬 
	// 정렬이 정상 작동 하지 않음 수정 하면 완료!
	qsort(arr, n, sizeof(char*), ca);
	qsort(pop, m, sizeof(char), cp);

	//printf("n=%d m=%d\n", n, m);

	//확인
	/*printf(" pop \n");
	for (char* i = pop; i < pop + m; i++) {
		printf("%c", *i);
	}
	printf("\n str \n");
	for (char* i = str; i < str + n; i++) {
		printf("%c", *i);
	}
	printf("\n arr \n");
	for (char** i = arr; i < arr + n; i++) {
		printf("%c", **i);
	}
	printf("\n");*/

	// 실행
	arr_ = arr; pop_ = pop;
	while (arr_ < arr+n && pop_ < pop+m) {
		//printf("arr = %c | pop = %c\n", **arr_, *pop_);
		if (**arr_ == *pop_) { **arr_++ = 0; }
		else if (**arr_ < *pop_) { arr_++; }
		else { pop_++; }
		
		//printf("arr = %c | pop = %c\n", **arr_, *pop_);
	}

	// 출력
	int p = 0;
	for (char* i = str; i < str + n; i++) {
		if (*i) { printf("%c", *i); p++; }
	}
	if (!p) { printf("FRULA"); }
}