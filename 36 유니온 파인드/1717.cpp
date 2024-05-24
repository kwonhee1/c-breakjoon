#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int n, m, * arr;
int get(int n);
int main() {
	scanf("%d %d", &n, &m);

	arr = new int[n+1];

	for (int i = n; i >= 0; i--) {
		arr[i] = i;
	}

	int a, b, c;
	while (m--){
		scanf("%d %d %d", &a, &b, &c);
		c = get(c);
		b = get(b);
		switch (a) {
		case 0:
			arr[c] = b;
			break;
		case 1:
			if (c == b) {
				printf("YES\n");
			}
			else
				printf("NO\n");
			break;
		}
	}
	
}

int get(int in) {
	int old,n = in;

	while(true){
		old = n;
		n = arr[n];
		if (n == old)
			break;
	}
	arr[in] = n;
	return n;
}