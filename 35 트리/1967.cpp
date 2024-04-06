#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct child {
	int node;
	int value;

	struct child* next;

	child(int n, int v, struct child* ne) {
		node = n; value = v; next = ne;
	}
	child() {
		next = NULL;
	}
};

struct vertex {
	int parent;
	int parentV;
	struct child child;
	vertex() {
		parent = 0; parentV = 0;
	}
};

void findLastNode(int node);
void getLength(int node, int value);

int n, re = 0, *history;
struct vertex* vs;

int main() {
	scanf("%d", &n);
	vs = new struct vertex[n+1];

	for (int i = n - 1, parent,node,value; i != 0; i--) {
		scanf("%d %d %d", &parent, &node, &value);
		vs[parent].child.next = new struct child(node,value,vs[parent].child.next);
		vs[node].parent = parent;
		vs[node].parentV = value;
	}
	findLastNode(1);
	
	printf("%d", re - 1);
}

void findLastNode(int node) {
	if (!vs[node].child.next) {
//printf("find last node : %d\n", node);
		history = new int [n+1] {1,0, };
		getLength(node,1);
		delete[] history;
//printf("\n");
	}
	else {
		for (struct child* i = vs[node].child.next; i; i = i->next) {
			findLastNode(i->node);
		}
	}
}

void getLength(int node, int value) {
	history[node] = value;
	if (re < value) re = value;

//printf("->%d:%d  ", node, value);
//printf("(%d:%d,%d:%d,%d:%d)", vs[node].parent,history[vs[node].parent], vs[node].left, history[vs[node].left], vs[node].right, history[vs[node].right]);
	if (!history[vs[node].parent])
		getLength(vs[node].parent, vs[node].parentV + value);
	for (struct child* i = vs[node].child.next; i; i = i->next) {
		if(!history[i->node])
			getLength(i->node, value + i->value);
	}
}

/*
12
1 3 2
1 2 3
2 4 5
4 7 1
4 8 7
3 5 11
3 6 9
5 9 15
5 10 4
6 11 6
6 12 10
*/