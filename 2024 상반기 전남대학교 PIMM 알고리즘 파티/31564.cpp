#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f();

struct que {
	int value;
	int node_x;
	int node_y;
	struct que* next;

	que(int n_y,int n_x,int v, struct que*n) {
		value = v; next = n;
		node_y = n_y; node_x = n_x;
	}
};

int y, x, k, ** arr, 
	dx[6] = {0,1,1,1,0,-1}, dy[6] = {-1,-1,0,1,1,0} ,
	dx1[6] = {-1,0,1,0,-1,-1};
struct que *start, * end;

int main() {
	scanf("%d %d %d", &y, &x, &k);
	
	// setting arr
	arr = new int* [y];
	for (int** i = arr; i < arr + x; i++) {
		*i = new int[x] {0,};
	}

	//input block
	while (k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = -1;
	}

	// set first
	end = start = new que(0,0,0,NULL);

	f();
}

void f() {
	do{
		//printf("(%d,%d)=%d  >> ", start->node_y, start->node_x, start->value);

		if (start->node_x == x - 1 && start->node_y == y - 1) {
			printf("%d", start->value); return;
		}
		
		int v = start->value;
		for (int i = 0; i < 6; i++) {
			int x_, y_ = start->node_y + dy[i];
			if (start->node_y % 2) {
				x_ = start->node_x + dx[i];
			}
			else {
				x_ = start->node_x + dx1[i];
			}
			if (0 <= x_ && x_ < x && 0 <= y_ && y_ < y) {
				// if not empty + smaller than v
				//printf("(%d,%d)=%d ", y_, x_, arr[y_][x_]);
				if (arr[y_][x_] && v+1 >= arr[y_][x_])
					continue;
				arr[y_][x_] = v + 1;
				//printf(">%d ", arr[y_][x_]);
				end = end->next = new struct que(y_, x_, v + 1, NULL);
			}
		}
		//printf("\n");

		struct que* old = start;
		start = start->next;
		delete old;
	} while (start);

	//if end que => no way
	printf("-1"); return;
}