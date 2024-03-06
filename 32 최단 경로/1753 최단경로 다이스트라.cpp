//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//struct vertex {
//	int end;
//	int value;
//};
//
//struct vertex** vs;
//
//void add_v(int start, int e, int v) {
//	struct vertex* newo = new struct vertex;
//	newo->end = e; newo->value = v;
//
//	vs[start][++vs[start]->value] = *newo;
//
//	//들어간 값 확인
//	/*printf("%d번 vertex ", start);
//	for (struct vertex* i = vs[start].next; i; i = i->next) {
//		printf("e=%d,v=%d->", i->end, i->value);
//	}
//	printf("\n");*/
//}
//
//struct q {
//	int node;
//	int value;
//};
//
//struct q** que;
//int que_max = 0; // 0번째 que_max사용 안함
//
//void add_q(int n, int v) {
//	struct q* nq = new struct q;
//	nq->node = n; nq->value = v;
//	//맨 마지막에 넣는다
//	que[++que_max] = nq;
//
//	//확인
//	/*printf("que 입력 확인\n");
//	for (int i = 1; i <= que_max; i++) {
//		printf("(n %d v %d) -> ", que[i]->node, que[i]->value);
//	}
//	printf("\n");*/
//}
///*
//      0
//   1     2
//3    4  5  6
//부모 : n/2 -1  
//
//      1
//   2     3
// 4   5  6  7
// 부모 : n/2      -> 선택!!
//*/
//void fa(int node);
//
//struct q* delete_q() {
//	if (que_max == 0) { return NULL; }
//
//	for (int i = que_max; i > 1; i--) {
//		if (que[i >> 1]->value > que[i]->value) {
//			//swap
//			struct q* buff = que[i >> 1];
//			que[i >> 1] = que[i];
//			que[i] = buff;
//		}
//	}
//
//	struct q* del = que[1];
//
//	// 제거 확인 후 정리
//		// 제일 마지막 꺼부터 올리기
//	fa(que_max);
//	que_max--;
//
//	//printf("삭제 후 que 확인");
//	//for (int i = 1; i <= que_max; i++) {
//	//	printf("(n %d v %d) -> ", que[i]->node, que[i]->value);
//	//}
//	//printf("\n");
//
//	////확인
//	//printf("delete 확인 : n:%d v:%d\n", del->node, del->value);
//	//
//	return del;
//}
//
//void fa(int node) {
//	int parent = node >> 1;
//	// 부모노드가 1번 노드라면
//	if (parent > 1) {
//		fa(parent);
//	}
//
//	que[parent] = que[node];
//}
//
//int v, e, start_node, *visit; 
//
//void f();
//
//int main() {
//	scanf("%d %d %d", &v, &e, &start_node);
//	vs = new struct vertex*[v+1];
//	for (struct vertex** i = vs; i<=vs+v;i++) {
//		*i = new struct vertex[e+1];
//		(**i).value = 0; //현재의 개수가 0개임을 나타냄
//	}
//	visit = new int[v+1] {0, };
//	que = new struct q*[e+1];
//
//	while (e--) {
//		int s, e, v;
//		scanf("%d %d %d", &s, &e, &v);
//		if(s == e)
//			continue;
//		add_v(s, e, v);
//	}
//	// 모든 간선 입력 완료 확인
//
//	// start_node로 가는 임의 que 설정
//	add_q(start_node, 0);
//
//	f();
//	
//	//visit내부 출력하기
//	for (int* i = visit+1; i <= visit + v; i++) {
//		if (*i)
//			printf("%d\n", *i);
//		else if (i == visit + start_node)
//			printf("0\n");
//		else
//			printf("INF\n");
//	}
//}
//
//void f() {
//	for (struct q* qi = delete_q(); qi; qi = delete_q()) {
//		int node = qi->node, value = qi->value;
//		// 현 노드를 이전에 방문한적 있고, 그 값이 크다면 무시
//		if (!(visit[node] && visit[node] <= value)) {
//			visit[node] = value;
//
//			//해당 노드의 간선들을 모두 확인
//			struct vertex* max = &vs[node][vs[node]->value];
//			for (struct vertex* i = &vs[node][1]; i<=max; i++) {
//				//간선->e 를 방문한적<이 있고, 그 값보다 크다면 무시
//				if (visit[i->end] && visit[i->end] <= value + i->value) { continue; }
//
//				// 나머지 모땅 que에 넣기
//				add_q(i->end,i->value+value);
//			}
//		}
//
//		//사용한 que delete
//		delete qi;
//
//		// 모든 node를 조사 하였다면 강제 종료 ?
//	}
//}
//
//
//
///*
//시작지점 확인
//다음 갈곳 que에 넣기 
//	갈곳이 간적이 있다면 더 큰 값은 무시
//que에 값중 가장 작은값 실행
//	간적이 있다면 더 큰 값은 무시(작은값 진행)
//que의 모든 값을 계산할때까지 또는
//	모든점을 다 들렸을때
//
//	시간계산도 계산 => 초과임!!
//	간선개수 * 간선개수 = 1000000000 * 90
//
//*/