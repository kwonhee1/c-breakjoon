#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

_Bool* visite;
struct vertex** node;
struct que* que;

struct vertex {
	int node;
	struct vertex *next;
};

struct que {
	int value;
	struct que* next;
};

void que_add(int node) {
	struct que* new = (struct que*)malloc(sizeof(struct que));
	new->value = node; new->next = NULL;

	if (que == NULL) {
		que = new;
	}else{
		struct que* q = que;
		while (q->next != NULL) { q = q->next; }
		q->next = new;
	}
}

int que_pop() {
	struct que* q = que;
	int re;
	if (q->next == NULL) {
		re = q->value;
		free(q);
		que = NULL;
	}else{
		re = q->value;
		que = que->next;
		free(q);
	}
	return re;
}

void add(int start, int end) {
	struct vertex* new = (struct vertex*)malloc(sizeof(struct vertex));
	new->node = end; new->next = NULL;

	if (node[start] == NULL) {// 첫번쨰 일경우
		node[start] = new;
	}else if (node[start]->node > end) { //첫번째 값보다 더 작은 경우
		new->next = node[start];
		node[start] = new;
	}else {
		struct vertex* old = node[start];
		struct vertex* v = node[start];
		while (v->node < end) {
			if (v->next == NULL) {
				v->next = new;
				return;
			}
			old = v;
			v = v->next;
		}

		new->next = old->next;
		old->next = new;
	}
}


void dfs(int start_node) {
	visite[start_node] = 1;
	printf("%d ", start_node);
	for (struct vertex* i = node[start_node]; i != NULL; i = i->next) {
		if (visite[i->node] == 0) {
			dfs(i->node);
		}
		// 다돌았으면 break
	}
}
void bfs() {
	printf("%d ", que->value);
	visite[que->value] = 1;
	int buff;
	while (que) {
		//printf("%d\n", que->value);
		for (struct vertex* i = node[buff = que_pop()]; i != NULL; i = i->next) {
			if (visite[i->node] == 0) {
				que_add(i->node);
				visite[i->node] = 1;
				printf("%d ", i->node);
			}
		}
	}
}
int main() {

	int buff1, buff2;
	int node_n, vertex_n, start_node;
	scanf("%d %d %d", &node_n, &vertex_n, &start_node);
	visite = (int*)calloc(node_n+1,sizeof(int));
	// _Bool visite[node_n];
	node = (struct vertex**)calloc(node_n+1, sizeof(struct vertex *));
	for (int i = vertex_n; i != 0; i--) {
		scanf("%d %d", &buff1, &buff2);
		add(buff1, buff2);
		add(buff2, buff1); // 양방향 연결노드
	}

	/*for (int i = 1; i <= node_n; i++) {
		for(struct vertex *v = node[i]; v!=NULL; v=v->next){
			printf("%d -> %d \n", i, v->node);
		}
	}*/

	dfs(start_node);
	printf("\n");
	que = (struct que*)malloc(sizeof(struct que));
	que->value = start_node;
	que->next = NULL;
	for (int i = 1; i <= node_n; i++) {
		visite[i] = 0;
	}
	bfs();

	/*que_add(5); que_add(3); que_add(8);

	for (struct que* q = que; q != null; q = q->next) {
		printf("%d ", q->value);
	}
	printf("\n");

	printf("%d",que_pop());
	printf("%d", que_pop());
	printf("%d", que_pop());*/
}
