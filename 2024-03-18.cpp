#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f(int a, int b);

int* arr, n;

int main() {
    int m, weight = -1, order,a,b;
    scanf("%d %d", &n, &m);
    
    arr = new int[n];
    for (int* i = arr; i < arr + n; i++) {
        scanf("%d", i);
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
    int re = 0;
    if (a <= b) {
        for (int* i = arr + a; i <= arr + b; i++) { re += *i; }
    }
    else {
        for (int* i = arr + a; i < arr + n; i++) { re += *i; }
        for (int* i = arr; i <= arr + b; i++) { re += *i; }
    }
    printf("%d\n", re);
}