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

int f(int node);

int n, re = 0, *arr;
struct child* vs;

int main() {
	scanf("%d", &n);
	vs = new struct child[n+1];
	arr = new int[n + 1] {0, };

	for (int i = n, parent,node,value; i != 0; i--) {
		scanf("%d %d", &parent, &node);
		while(node!=-1) {
			scanf("%d", &value);
			vs[parent].next = new struct child(node, value, vs[parent].next);
			scanf("%d", &node);
		}
	}
	f(1);
	printf("%d", re);
}

int f(int node) {
	int max = 0, max_ = 0, buff;
	arr[node] = -1;
	for (struct child* i = vs[node].next; i; i = i->next) {
		if (!arr[i->node]) {
			buff = f(i->node) + i->value;
			if (max_ < buff) {
				if (max < buff) {
					max_ = max;
					max = buff;
				}
				else
					max_ = buff;
			}
		}
	}
	if (re < max + max_) re = max + max_;
	//printf("%d(%d %d)=%d ", node, max, max_,re);
	return max;
}