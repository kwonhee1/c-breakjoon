// 프로그래머스 1단계 문제 https://school.programmers.co.kr/learn/courses/30/lessons/172928
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
/*
// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(1);
    return answer;
}
*/
/*입력값:
공원의 w h (0,0) ~ (w-1,h-1) 의 직사각형 공원
공원 지도(0빙공간, 1장해물) {0 0 0 0 1} {1 0 0 0 1} ...
명령 모음 길이 {5} : 총 5개 명령
강아지 명령 모음 {e 5} {w 3} {n 1} {s 2} ....
구하는 값 : 마지막 강아지의 위치 {5 5}
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