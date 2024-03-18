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

int n, m,start_node, *visit, **arr;
struct vertex* vs;

int main() {
	scanf("%d %d %d", &n, &m, &start_node);

	visit = new int[n+1];
	for (int* i = visit + n; i != visit; i--) {
		*i = 2e9;
	}
	vs = new struct vertex[n+1];
	arr = new int* [n + 1];
	for (int** i = arr, *j=visit; i <= arr + n; i++,j++) {
		*i = j;
	}

	while(m--) {
		int start, end, value;
		scanf("%d %d %d", &start, &end, &value);
		
		vs[start].next = new struct vertex(end, value, vs[start].next);
	}

	if (n == 1) {
		printf("0");
		return 1;
	}

	//첫번째 값 입력
	visit[start_node] = 0;

	//start
	for (int end = n; end>1;) {
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

	for (int* i = visit + 1; i <= visit + n; i++) {
		if (*i == 2e9) {printf("INF\n");}
		else { printf("%d\n", *i); }
	}
}

int get(int end) {
	// end~2까지 부모노드 : i>>1
	for (int i = end; i > 1; i--) {
		if (*arr[i]< *arr[i >> 1]) {
			//swap
			int* buff = arr[i];
			arr[i] = arr[i>>1];
			arr[i>>1] = buff;
		}
	}

	//첫번째와 마지막 교환
	int* buff = arr[1];
	arr[1] = arr[end];
	arr[end] = buff;

	//다음에로 갈 노드 (몇번째 노드인지)
	return arr[end] - visit;
}