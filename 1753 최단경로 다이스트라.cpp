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
//	//�� �� Ȯ��
//	/*printf("%d�� vertex ", start);
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
//int que_max = 0; // 0��° que_max��� ����
//
//void add_q(int n, int v) {
//	struct q* nq = new struct q;
//	nq->node = n; nq->value = v;
//	//�� �������� �ִ´�
//	que[++que_max] = nq;
//
//	//Ȯ��
//	/*printf("que �Է� Ȯ��\n");
//	for (int i = 1; i <= que_max; i++) {
//		printf("(n %d v %d) -> ", que[i]->node, que[i]->value);
//	}
//	printf("\n");*/
//}
///*
//      0
//   1     2
//3    4  5  6
//�θ� : n/2 -1  
//
//      1
//   2     3
// 4   5  6  7
// �θ� : n/2      -> ����!!
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
//	// ���� Ȯ�� �� ����
//		// ���� ������ ������ �ø���
//	fa(que_max);
//	que_max--;
//
//	//printf("���� �� que Ȯ��");
//	//for (int i = 1; i <= que_max; i++) {
//	//	printf("(n %d v %d) -> ", que[i]->node, que[i]->value);
//	//}
//	//printf("\n");
//
//	////Ȯ��
//	//printf("delete Ȯ�� : n:%d v:%d\n", del->node, del->value);
//	//
//	return del;
//}
//
//void fa(int node) {
//	int parent = node >> 1;
//	// �θ��尡 1�� �����
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
//		(**i).value = 0; //������ ������ 0������ ��Ÿ��
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
//	// ��� ���� �Է� �Ϸ� Ȯ��
//
//	// start_node�� ���� ���� que ����
//	add_q(start_node, 0);
//
//	f();
//	
//	//visit���� ����ϱ�
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
//		// �� ��带 ������ �湮���� �ְ�, �� ���� ũ�ٸ� ����
//		if (!(visit[node] && visit[node] <= value)) {
//			visit[node] = value;
//
//			//�ش� ����� �������� ��� Ȯ��
//			struct vertex* max = &vs[node][vs[node]->value];
//			for (struct vertex* i = &vs[node][1]; i<=max; i++) {
//				//����->e �� �湮����<�� �ְ�, �� ������ ũ�ٸ� ����
//				if (visit[i->end] && visit[i->end] <= value + i->value) { continue; }
//
//				// ������ �� que�� �ֱ�
//				add_q(i->end,i->value+value);
//			}
//		}
//
//		//����� que delete
//		delete qi;
//
//		// ��� node�� ���� �Ͽ��ٸ� ���� ���� ?
//	}
//}
//
//
//
///*
//�������� Ȯ��
//���� ���� que�� �ֱ� 
//	������ ������ �ִٸ� �� ū ���� ����
//que�� ���� ���� ������ ����
//	������ �ִٸ� �� ū ���� ����(������ ����)
//que�� ��� ���� ����Ҷ����� �Ǵ�
//	������� �� �������
//
//	�ð���굵 ��� => �ʰ���!!
//	�������� * �������� = 1000000000 * 90
//
//*/