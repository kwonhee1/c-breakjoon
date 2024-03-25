#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct que {
	int value;
	int node;
	struct que* next;

	que(int v, int no) {
		value = v; node = no; next = NULL;
	}
};

struct que* que_start, *que_end;

int start, end, *arr;

int main() {
	scanf("%d %d", &start, &end);

	if (start > end) { printf("%d", start - end); return 0; }
	if (start == 1) { printf("0"); return 0; }
	if (start == 2) {
		if (end % 2) printf("1");
		else  printf("0");
		return 0;
	}

	arr = new int[150001] {0, };
	que_start = que_end = new struct que(1, start);

	do {
		// 이전에 계산한적이 없다면
		if (!arr[que_start->node]) {
			//printf("%d >> ", que_start->node);
			for(int i = que_start->node; i<150001; i=i<<1){
				if (!arr[i]) {
					arr[i] = que_start->value;
					//printf("%d->%d ", i, que_start->value);
					if (i > 1) {
						if (!arr[i - 1]) {
							que_end = que_end->next = new struct que( que_start->value + 1, i - 1);
							//printf("%d->%d ", i - 1, que_start->value + 1);
						}
					}
					if (i < 150000) {
						if (!arr[i + 1]) {
							//printf("%d->%d ", i + 1, que_start->value + 1);
							que_end = que_end->next = new struct que(que_start->value + 1, i + 1);
						}
					}
				}
			}
			//printf("::: %d\n", arr[end]);
		}

		struct que* old = que_start;
		que_start = que_start->next;
		delete old;
	} while (que_start && !arr[end]);

	printf("%d", arr[end]-1);
}