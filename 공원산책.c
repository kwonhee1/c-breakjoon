// ���α׷��ӽ� 1�ܰ� ���� https://school.programmers.co.kr/learn/courses/30/lessons/172928
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
/*
// park_len�� �迭 park�� �����Դϴ�.
// routes_len�� �迭 routes�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(1);
    return answer;
}
*/
/*�Է°�:
������ w h (0,0) ~ (w-1,h-1) �� ���簢�� ����
���� ����(0������, 1���ع�) {0 0 0 0 1} {1 0 0 0 1} ...
��� ���� ���� {5} : �� 5�� ���
������ ��� ���� {e 5} {w 3} {n 1} {s 2} ....
���ϴ� �� : ������ �������� ��ġ {5 5}
*/
/*
int* PARK_function() {
    int w,h = malloc(sizeof(int));
    scanf("%d %d",&w,&h);
    int* array = new int[5];
    for (int i = 0; i < h; i++) {

    }
}
*/