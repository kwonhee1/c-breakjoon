#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct vertex {
	int value;
	int start;
	int end;
	vertex(int s, int e, int v) {
		value = v; start = s; end = e;
	}
	vertex() {
		value = 0; start = -1; end = -1;
	}
};

int compare(const void *a, const void *b) {
	if ( ((struct vertex*)a)->value > ((struct vertex*)b)->value )
		return 1;
	else
		return -1;
}

struct vertex *vs;
int n, *visite;
long long re = 0;

int get(int node);

int main() {
	int m,a,b,c,min, *s, *e;
	scanf("%d %d",&n,&m);

	vs = new struct vertex[m];
	visite = new int[n+1] {};

	for (struct vertex* i = vs + m - 1; i >= vs; i--) {
		scanf("%d %d %d", &i->start, &i->end, &i->value);
	}

	qsort(vs,m,sizeof(struct vertex),compare);

	/*for (struct vertex* i = vs; i < vs + m; i++) {
		printf("%d <> %d :  %d\n", i->start, i->end, i->value);
	}*/

	for (struct vertex* i = vs; i < vs + m; i++) {
		//s = visite+i->start; e = visite+i->end;
		//printf("%d[%d]<>%d[%d] : %d = ", i->start,visite[i->start], i->end,visite[i->end], i->value);
		if (visite[i->start] && visite[i->end]) { //둘다 방문 했음
			a = get(i->start); b = get(i->end);
			if (a != b) {
				if (visite[a] > visite[b]) {
					// b에 더 많은 값들이 연동됨
					visite[b] += visite[a];
					visite[a] = b;
				}
				else {
					visite[a] += visite[b];
					visite[b] = a;
				}
				re += i->value;
				//printf("둘다 방분한적 있고 별개의 방문임\n");
			}
			/*else 
				printf("false\n");*/
		}
		else if (visite[i->start]) { // s에 방문한적 있음
			re += i->value;
			a = get(i->start);
			visite[a] += -1;
			visite[i->end] = a;
			//printf("start에 방문한적 있음\n");
		}
		else if (visite[i->end]) {
			re += i->value;
			b = get(i->end);
			visite[b] += -1;
			visite[i->start] = b;
			//printf("end에 방문한적 있음\n");
		}
		else { //둘다 방문한적없음 
			re += i->value;
			visite[i->start] = -2; visite[i->end] = i->start;
			//printf("둘다 방문한적 없음\n");
		}
	}

	printf("%d", re);
}

int get(int node) {
	if (visite[node] < 0)
		return node;
	
	return ( visite[node] = get(visite[node]) );
}