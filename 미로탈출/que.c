// que.h
#include "que.h"

// p. 152

struct que {
	int x; int y;
	struct que* next;
};

struct que* que = NULL;

char get_di(struct que* q, int x, int y) {
	// 이전꺼 < 이후꺼 : return true (다음껄로 넘어감)
	//		| X - x | + | Y - y |  <  |X-x| + |Y-y|
	//return (X-q->x + Y - q->y) < (X - x + Y - y);
	return Absolute(X - q->x) + Absolute(Y - q->y) < Absolute(X - x) + Absolute(Y - y);
}

void que_add(int x, int y) {
	struct que* n = (struct que*)malloc(sizeof(struct que));
	n->x = x; n->y = y; n->next = NULL;

	//처음일때
	if (que == NULL) {
		que = n;
	}
	//1번째값보다 더 작을때
	else if (get_di(que, x, y)) {
		n->next = que;
		que = n;
	}
	//n번째 일때
	else {
		struct que* q = que;
		//정렬해서 삽입
		while (q->next != NULL) {
			if (get_di(q->next, x, y)) {
				n->next = q->next;
				q->next = n;
				return;
			}
			q = q->next;
		}
		q->next = n;
	}
}

struct xy; //이미 헤더 파일에서 정의함 다시 정의 하면 재정의 오류 줄력

struct xy que_pop() {
	struct xy re = { -1,-1 };
	if (que != NULL) {
		struct que* q = que;
		re.x = q->x; re.y = q->y;
		que = que->next;
		free(q);
	}
	return re;
}
