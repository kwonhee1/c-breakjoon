#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct que {
	int value;
	int x;
	int y;
	struct que* next;

	que(int v, int x_, int y_) {
		x = x_; y = y_; value = v; next = NULL;
	}
};

//add que 
// end = end->next = new struct que(v,x,y);

struct que* start, * end;

int n, m, **arr;

int main() {
	int dx[5] = {0, 1,-1,0,0 }, dy[5] = {0, 0,0,1,-1 };

	scanf("%d %d", &n, &m);
	arr = new int* [m];

	start = end = new struct que(0,0,0); //trash value -> erase before start

	for (int y = 0; y < m; y++) {
		arr[y] = new int[n];
		for (int x = 0, buff; x < n; x++) {
			scanf("%d", &buff);
			arr[y][x] = buff;
			if(buff == 1)
				end = end->next = new struct que(1, x, y);
		}
	}

	//check input
	/*for (int y = 0; y < m; y++) {
		for (int x = 0, buff; x < n; x++) {
			printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
	printf("end check\n");*/

	start = start->next;
	if (start == NULL) {
		// no ripe tomato
		printf("-1");
		return 0;
	}

	int v;
	do {
		int x = start->x, y = start->y; v = start->value;
		
		//printf("(%d,%d)=%d\n", x, y, v);

		//if updated by other -> continue
		if (arr[y][x] < v) { continue; }
		arr[y][x] = v++;
		for (int i = 4; i != 0; i--) {
			int x_ = x + dx[i], y_ = y + dy[i];
			if(0<=x_ && x_<n && 0<=y_ && y_<m){
				if (arr[y_][x_] && arr[y_][x_] <= v) { continue; }
				arr[y_][x_] = v;
				end = end->next = new struct que(v, x_, y_);
			}
		}

		struct que* old = start;
		start = start->next;
		delete old;
	} while (start);

	/*printf("end and check again\n");
	for (int y = 0; y < m; y++) {
		for (int x = 0, buff; x < n; x++) {
			printf("%d ", arr[y][x]);
		}
		printf("\n");
	}
	printf("end check\n");*/

	// check left 0 in arr -> all tomato cannot be ripe
	int flag = 0;
	for (int** i = arr; i < arr + m; i++) {
		for (int* j = *i; j < *i + n; j++) {
			if (!*j) { printf("-1"); flag = 1; break; }
		}
		if (flag) { break; }
	}
	if (!flag) {
		printf("%d", v - 2);
	}
}