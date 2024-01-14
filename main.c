#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

_Bool* visite; struct vertex** node;

struct vertex {
	int node;
	struct vertex *next;
};

void add(struct vertex *v, int node) {
	if (v == NULL) {// 첫번쨰 일경우
		v = (struct vertex*)malloc(sizeof(struct vertex));
		v->node = node;
		v->next = NULL;
	}
	while (v->next != NULL) { v = v->next; }
	v->next = (struct vertex*)malloc(sizeof(struct vertex));
	v->next->node = node;
	v->next->next = NULL;
}

void bfs(int start_node) {
	visite[start_node] = 1;
	printf("%d ", start_node);
	for (struct vertex* i = node[start_node]; i->node != 0; i = i->next) {
		if (visite[i->node] == 0) {
			bfs(i->node);
		}
		// 전부 돌았다면 break;
	}
}

int main() {
	int buff1, buff2;
	int node_n, vertex_n, start_node;
	scanf("%d %d %d", &node_n, &vertex_n, &start_node);
	visite = (int*)calloc(node_n,sizeof(int));
	// _Bool visite[node_n];
	node = (struct vertex**)calloc(node_n, sizeof(struct vertex *));
	for (int i = vertex_n; i != 0; i--) {
		scanf("%d %d", &buff1, &buff2);
		add(node[buff1], buff2);
	}
	bfs(start_node);
}