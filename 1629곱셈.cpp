#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int a,c;

long long f(int b) { 
	long long buff;
	// a^1�� ���
	if (b == 1) { return a; }
	// b�� Ȧ�� => a^b = a^{(b-1)/2} * a^{(b-1)/2} * a^1
	else if (b % 2) { buff = f(b >> 1); return ((buff * buff)%c * a) % c; }
	// b�� ¦�� => a^b = a^(b/2) * a^(b/2)
	else { buff = f(b >> 1); return (buff * buff) % c; }
}

int main() {
	int  b;
	scanf("%d %d %d", &a, &b, &c);
	a = a % c;

	printf("%llu", f(b));
}