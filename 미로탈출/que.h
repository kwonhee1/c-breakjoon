// que.h

#include<stdlib.h>
#define Absolute(a) a>0?a:-a

int X = 5, Y = 5;

//헤더파일서 정의 하지 않으면 더른 파일에서 사용을 할수가 없음
struct xy { 
	int x;
	int y;
};

char get_di(struct que* q, int x, int y);

void que_add(int x, int y);

struct xy que_pop();
