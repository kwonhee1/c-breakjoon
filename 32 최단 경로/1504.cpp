#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct vertex {
	int end;
	int value;

	struct vertex* next;

	vertex() {
		next = NULL;
	}
	vertex(int e, int v, struct vertex* n) {
		next = n;
		end = e; value = v;
	}
};

int get(int end);
void f();

int n, m, start_node, * visit, ** arr;
struct vertex* vs;

int main() {
	int a1, a2, b1, b2, ab, a,b;
	// a1 ab b2 | b1 ab a2

	scanf("%d %d", &n, &m);

	visit = new int[n + 1];
	vs = new struct vertex[n + 1];
	arr = new int* [n + 1];
	for (int** i = arr, *j = visit; i <= arr + n; i++, j++) {
		*i = j;
		*j = 2e9;
	}

	while (m--) {
		int start, end, value;
		scanf("%d %d %d", &start, &end, &value);

		vs[start].next = new struct vertex(end, value, vs[start].next);
		vs[end].next = new struct vertex(start,value,vs[end].next);
	}
	
	scanf("%d %d", &a, &b);

	//a1, b1 구하기
	visit[1] = 0;
	f();
	a1 = visit[a];
	b1 = visit[b];
	//a2,b2 구하기
	for (int *j = visit; j <= visit + n; j++) {
		*j = 2e9;
	}
	visit[n] = 0;
	f();
	a2 = visit[a]; b2 = visit[b];
	//ab 구하기
	for (int* j = visit; j <= visit + n; j++) {
		*j = 2e9;
	}
	visit[a] = 0;
	f();
	ab = visit[b];

	//경로가 없을때
	if (ab == 2e9 || a1 == 2e9 || a2 == 2e9) {printf("-1"); return 0;}

	//printf("a1:%d a2:%d b1:%d b2:%d ab:%d\n", a1, a2, b1, b2, ab);
	if (a1 + ab + b2 > b1 + ab + a2) {
		 printf("%d", b1 + ab + a2); 
	}
	else {
		printf("%d", a1 + ab + b2); 
	}
}

void f() {
	//start
	for (int end = n; end > 1;) {
		int start = get(end--);
		int v = visit[start];
		//printf("start : %d, value : %d", start, v);
		for (struct vertex* i = vs[start].next; i; i = i->next) {
			if (visit[i->end] > i->value + v) {
				visit[i->end] = i->value + v;
				//printf(" %d->%d : %d ", start, i->end, i->value + v);
			}
		}
		//printf("\n");
	}
}

int get(int end) {
	// end~2까지 부모노드 : i>>1
	for (int i = end; i > 1; i--) {
		if (*arr[i] < *arr[i >> 1]) {
			//swap
			int* buff = arr[i];
			arr[i] = arr[i >> 1];
			arr[i >> 1] = buff;
		}
	}

	//첫번째와 마지막 교환
	int* buff = arr[1];
	arr[1] = arr[end];
	arr[end] = buff;

	//다음에로 갈 노드 (몇번째 노드인지)
	return arr[end] - visit;
}