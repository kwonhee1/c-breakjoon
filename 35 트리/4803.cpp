#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct vertex {
	int node;
	struct vertex* next;
	
	vertex(int n, struct vertex *ne) {
		node = n; next = ne;
	}
	vertex() {
		node = 0; next = NULL;
	}
};

struct stack {
	int value;
	struct stack* next;

	stack(int v) {
		value = v; next = NULL;
	}
};

struct vertex* vs;
struct stack* start, *end, *buff;
int n, m, re, check, ch;

int main() {
	int num = 1;
	while (true) {
		re = 0;

		start = end = new struct stack(n);
		scanf("%d %d", &n, &m);
	
		if (!n && !m) break;
		if (!n) {
			printf("No trees.");
			continue;
		}
		vs = new struct vertex[n+1];
		for (int a, b; m; m--) {
			scanf("%d %d", &a, &b);
			vs[a - 1].next = new struct vertex(b - 1, vs[a - 1].next);
			vs[b - 1].next = new struct vertex(a - 1, vs[b - 1].next);
		}


		for (struct vertex* i = vs + n - 1; i >= vs; i--) {
			if (!i->node) {
				check = 0; ch = 0;
				//printf("find new node %d ", i - vs);
				i->node = 1;
				// 한번도 확인 하지 않은 node 발견 -> 해당 노드의 간선을 모두 stavk에 넣는다
				for (struct vertex* j = i->next; j; j = j->next) {
					if (!vs[j->node].node) {
						vs[j->node].node = 1;
						end = end->next = new struct stack(j->node);
						//printf("add stack %d ", j->node);
					}else{
						check++;
					}
				}

				while (start != end) { //stack이 빌때 까지
					ch++;
					buff = start;
					start = start->next;
					//printf("pop stack %d ", start->value);
					delete buff;

					for (struct vertex* j = vs[start->value].next; j; j = j->next) {
						if (!vs[j->node].node) {
							vs[j->node].node = 1;
							end = end->next = new struct stack(j->node);
							//printf("add stack %d ", j->node);
						}
						else {
							check++;
						}
					}
				}

				//printf("end\n");

				if (check == ch) {
					re++;
				}

			}
		}
		//printf("\n");
		printf("Case %d: ", num++);
		if (!re)
			printf("No trees.");
		else if (re == 1)
			printf("There is one tree.");
		else
			printf("A forest of %d trees.", re);
		//printf("\n");
		delete start;
		delete[] vs;
	}
}