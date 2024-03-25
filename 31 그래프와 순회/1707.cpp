#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct vertex {
	int node;
	struct vertex* next;

	vertex(int no, struct vertex* n) {
		node = no; next = n;
	}
	vertex() { next = NULL; node = 0; }
};

struct que {
	int node;
	int value;
	struct que* next;
	que(int n, int v) {
		node = n; value = v;
		next = NULL;
	}
};

int flag;
struct vertex* arr;

int f(struct que* start, struct que* end);

int main() {
	int n, m, all;
	scanf("%d", &all);
	while (all--) {

		flag = 1;
		scanf("%d %d", &n, &m);
		arr = new struct vertex[n + 1];

		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a].next = new struct vertex(b, arr[a].next);
			arr[b].next = new struct vertex(a, arr[b].next);
		}

		/*for (int i = 1; i <= n; i++) {
			for (struct vertex* k = arr[i].next; k; k = k->next) {
				printf("%d -> %d\n", i, k->node);
			}
		}*/

		// input any first node to start
		struct que* start;
		arr[1].node = 1;
		struct que* end = start = new struct que(1, -1);

		while (f(start,end)) {
			int flag2 = 1;
			int i  = 1;
			while(i<=n){
				if (!arr[i].node) { flag2 = 0; break; }
				i++;
			}
			if (flag2) { break; }
			else {
				arr[i].node = 1;
				start = end = new struct que(i,-1);
			}
		}

		if (flag) printf("YES\n");
		else printf("NO\n");

		for (struct vertex* i = arr; i <= arr + n; i++) {
			while (i->next) {
				struct vertex* old = i->next;
				i->next = i->next->next;
				delete old;
			}
		}
		delete[] arr;
	}
}

int f(struct que*start, struct que*end) {

	while (start) {
		//printf("\n%d(%d) >> ", start->node, start->value);
		for (struct vertex* i = arr[start->node].next; i; i = i->next) {
			//printf("%d(%d) ", i->node, arr[i->node].node);
			if (!arr[i->node].node) { //empty -> input que
				arr[i->node].node = start->value;
				end = end->next = new struct que(i->node, start->value > 0 ? -1 : 1);
				//printf("->%d ", start->value > 0 ? -1 : 1);
			}
			else if (arr[i->node].node != start->value) { //NO
				start->next = NULL; flag = 0; return 0;
			}
			// continue;
		}
		struct que* old = start;
		start = start->next;
		delete old;
	}
	return 1;
}