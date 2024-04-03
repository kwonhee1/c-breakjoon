#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, target, len = 2e9, len_;
	long* arr;
	scanf("%d %d", &n, &target);
	arr = new long[n+1];
	*arr = 0;
	
	for (long *i = arr+1,buff=0; i <= arr+n; i++) {
		scanf("%d", i);
		buff = *i += buff;
	}

	for (int i = 1, left, right; i <= n; i++) {
		long t = target + arr[i-1];
		if (arr[n] < t) break;
		else if (t <= arr[i]) {
			printf("1"); return 0;
		}

		len_ = 0; left = i; right = n;
		while (left < right) {
			//printf("%d %d %d , ", left, right, arr[(left+right)>>1]);
			if (arr[(left + right) >> 1] == t) {
				len_ = (left + right) >> 1; break;
			}
			else if( arr[(left+right)>>1] < t) left=((left+right)>>1)+1;
			else right = (right + left) >> 1;
		}
		if (!len_) len_ = right-i+1;
		//printf(" => %d %d\n",i, len_);
		if (len_ < len) len = len_;
	}

	if (len == 2e9) { printf("0"); }
	else printf("%d", len);
}