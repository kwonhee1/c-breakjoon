// que.h

#include<stdlib.h>
#define Absolute(a) a>0?a:-a

int X = 5, Y = 5;

//������ϼ� ���� ���� ������ ���� ���Ͽ��� ����� �Ҽ��� ����
struct xy { 
	int x;
	int y;
};

char get_di(struct que* q, int x, int y);

void que_add(int x, int y);

struct xy que_pop();
