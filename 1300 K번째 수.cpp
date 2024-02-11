#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;

long long get(long long index) {
	long long re = 0;
	for (int i = 1; i <= n; i++) {
		re += index/i < n ? index/i : n;
	}
	return re;
}

int main() {
	int k;
	scanf("%d %d", &n,&k);

	long long start = 1, end = n * (long long)n, buff;

	if (n == 1) {
		printf("1"); return 0;
	}

	while (start != end) {
		buff = (start + end) >> 1;
		
		//printf(">%llu %llu %llu = %llu <> %d\n", start, buff, end, get(buff), k);
		if (get(buff) < k) {
			start = buff + 1;
		}
		else {
			end = buff;
		}
	}

	printf("%llu", end);
}

