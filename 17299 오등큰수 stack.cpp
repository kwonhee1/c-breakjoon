#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct st {
	int value;
	int a;
	struct st* next;
	struct st* old;

	void del() {
		old->next = next;
		if(next)
			next->old = old;
		delete this;
	};
};

struct st stack { 0 };

void add(int v, int a) {
	struct st *n = new struct st;
	n->value = v;
	n->a = a;
	
	n->next = stack.next;
	n->old = &stack;
	if(stack.next)
		stack.next->old = n;

	stack.next = n;
};

int n, * arr, v[1000001]{ 0, }; // 1~1000000

int main() {
	scanf("%d", &n);

	stack.next = NULL;

	arr = new int[n];

	for (int* i = arr; i < arr + n; i++) {
		scanf("%d", i);
		v[*i]++;
	}

	for (int* i = arr + n - 1; i>=arr; i--) {
		//printf("%d=> ", *i);
		int buff = v[*i];
		// stack ���� ���� ��� 
		if (!stack.next) {
			add(buff, *i);
			*i = -1;
		}
		//stackù��°�� ��
		// �� ���� �� �ΰ�� 
		else if (stack.next->value > v[*i]) {
			// *i = stack->next�� ��
			add(buff,*i);
			*i = stack.next->next->a;
			//stack�� ������ �� �߰�
		}
		//�� ū �� �ΰ��
		else {
			//stack���� ������ �۰ų� ���� �� ����
			stack.next->del();
			for (struct st* j = stack.next; j; j= stack.next) {
				if (j->value <= v[*i])
					stack.next->del();
				else
					break;
			}
			i++;
		}

		//Ȯ�� �ڵ�
		/*printf("%d\n����", *i);
		for (struct st* i = stack.next; i; i = i->next) {
			printf("%d ", i->value);
		}
		printf("\n");*/
	}

	for (int* i = arr; i < arr + n; i++) {
		printf("%d ", *i);
	}
}