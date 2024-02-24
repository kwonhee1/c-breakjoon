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
		// stack 값이 없는 경우 
		if (!stack.next) {
			add(buff, *i);
			*i = -1;
		}
		//stack첫번째와 비교
		// 더 작은 수 인경우 
		else if (stack.next->value > v[*i]) {
			// *i = stack->next의 값
			add(buff,*i);
			*i = stack.next->next->a;
			//stack에 현재의 값 추가
		}
		//더 큰 수 인경우
		else {
			//stack에서 나보다 작거나 같은 값 제거
			stack.next->del();
			for (struct st* j = stack.next; j; j= stack.next) {
				if (j->value <= v[*i])
					stack.next->del();
				else
					break;
			}
			i++;
		}

		//확인 코드
		/*printf("%d\n스택", *i);
		for (struct st* i = stack.next; i; i = i->next) {
			printf("%d ", i->value);
		}
		printf("\n");*/
	}

	for (int* i = arr; i < arr + n; i++) {
		printf("%d ", *i);
	}
}