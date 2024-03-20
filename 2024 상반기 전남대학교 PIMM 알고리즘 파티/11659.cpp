#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f(int a, int b);

int* arr, n, *dp;

int main() {
    int m, weight = -1, order,a,b;
    scanf("%d %d", &n, &m);
    
    arr = new int[n];
    for (int* i = arr; i < arr + n; i++) {
        scanf("%d", i);
    }

    //dp[y][x] => y~x 까지의 합
    dp = new int[n];
    *dp = *arr;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }

    while (m--) {
        scanf("%d", &order);
        switch (order) {
        case 1:
            scanf("%d", &a);
            weight -= a;
            break;
        case 2:
            scanf("%d", &a);
            weight += a;
            break;
        case 3:
            scanf("%d %d", &a, &b);
            f(a+weight,b+weight);
            break;
        }
    }
}

void f(int a, int b) {
    if (a < 0) { a += n; }
    else if (a >= n) { a -= n; }
    if (b < 0) { b += n; }
    else if (b >= n) { b -= n; }
    //printf("출력 : %d->%d \n", a, b);
    if (a <= b) {
        if (a == 0) { printf("%d\n", dp[b]); }
        else { printf("%d\n", dp[b] - dp[a - 1]); }
    }
    else {
        if (a == 0) printf("%d\n", dp[0]);
        else printf("%d\n", dp[n-1] - dp[a-1] + dp[b]);
    }
}