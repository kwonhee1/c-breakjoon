#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// players_len은 배열 players의 길이입니다.
// callings_len은 배열 callings의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = malloc(sizeof(char*) * (players_len));
    if (answer) {
        for (int i = 1; i <= players_len; i++) {
            answer[i - 1] = players[i];
        } //0~ sol[p_len -1]까지
        for (int i = 0; i < callings_len; i++) {
            int n = 0;
            while (strcmp(answer[n++], callings[i])) {
            }
            char* buff = answer[n - 2];
            answer[n - 2] = answer[n - 1];
            answer[n - 1] = buff;
        }

        //char** sol = (char**)malloc(sizeof(players[0]) * (players_len -1));
        return answer;
    }
    return 0;
}

int RUN_function() {

    const char* players[] = { " ","a","b","c","abc" };
    int players_len = 4;
    const char* callings[] = { "b","abc","abc","a","c" };
    int callings_len = 5;
    char** sol = solution(players, players_len, callings, callings_len);
    for (int i = 0; i < 4; i++) {
        printf("%s ", sol[i]);
    }
    if (sol) {
        free(sol);
    }

    /*
    char** a = malloc(sizeof(char*) * 4);
    if (a) {
        char b[4][5] = { "abc","ccd"};
        printf("%c %c", *b[0], *b[1]);
        for (int i = 0; i < 4; i++) {
            a[i] = b[i];
        }
        if (a[3] == b[3]) {
            printf("ok");
        }
        free(a);
    }*/
}