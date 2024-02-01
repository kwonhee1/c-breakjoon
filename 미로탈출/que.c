// que.h
#include "que.h"

// p. 152

struct que {
	int x; int y;
	struct que* next;
};

struct que* que = NULL;

char get_di(struct que* q, int x, int y) {
	// ������ < ���Ĳ� : return true (�������� �Ѿ)
	//		| X - x | + | Y - y |  <  |X-x| + |Y-y|
	//return (X-q->x + Y - q->y) < (X - x + Y - y);
	return Absolute(X - q->x) + Absolute(Y - q->y) < Absolute(X - x) + Absolute(Y - y);
}

void que_add(int x, int y) {
	struct que* n = (struct que*)malloc(sizeof(struct que));
	n->x = x; n->y = y; n->next = NULL;

	//ó���϶�
	if (que == NULL) {
		que = n;
	}
	//1��°������ �� ������
	else if (get_di(que, x, y)) {
		n->next = que;
		que = n;
	}
	//n��° �϶�
	else {
		struct que* q = que;
		//�����ؼ� ����
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

struct xy; //�̹� ��� ���Ͽ��� ������ �ٽ� ���� �ϸ� ������ ���� �ٷ�

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
