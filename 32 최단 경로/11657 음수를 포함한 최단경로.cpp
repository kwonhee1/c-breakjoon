#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct vertex {
	int start;
	int end;
	int value;
};

void solution(int start, int value);
void add_vs(int start, int end, int value);

struct vertex** vs; //vs[3][4]
int n, m, *visit, *visit_, flag = 0;

int main() {
	scanf("%d %d", &n, &m);
	
	//�������� �迭 vs����
	vs = new struct vertex*[n+1];
	for (struct vertex** i = vs; i <= vs + n; i++) {
		*i = new struct vertex[m+1]; //0��°�� ���� ������ ����
		(**i).value = 0; //���� 0�� ��Ұ� �������� �ǹ�
	}
	visit = new int[n+1];
	for (int* i = visit + 1; i <= visit + n; i++) {
		*i = 2e9;
	}
	visit_ = new int[n + 1] {0, };
	
	// ������ �Է�
	for (int i = m; i; i--) {
		int start, end, value;
		scanf("%d %d %d", &start, &end, &value);
		vs[start][++vs[start][0].value] = {start,end,value};
	}

	// ����
	solution(1,0);

	// visit���� ���
	if (!flag) {
		for (int* i = visit + 2; i <= visit + n; i++) {
			if (*i == 2e9) { printf("-1"); }
			else { printf("%d\n", *i); }
		}
	}
}

void solution(int start, int value) {
	//���� start�� �������� Ȯ��
		// �����ְ� ���������� value�� ũ�ų� ������ ����
	if (visit[start] <= value || flag) { return; }
		// ���ѷ������ ���α׷� ����
	else if (visit_[start]) { printf("-1"); flag = 1; return; }

	else {
		// start�� visit
		visit_[start] = 1; visit[start] = value;

		//��� �����鿡 ���� ����
		for (struct vertex* i = &vs[start][vs[start][0].value]; i > &vs[start][0]; i--) {
			solution(i->end, i->value + value);
		}

		//�迭 ����
		visit_[start] = 0;
	}
}

void add_vs(int start, int end, int value) {
	vs[start][++vs[start]->value] = {start, end, value};
}

/*
	6000*500 + 6000 = �� 300 0000 => �޸𸮴� �����
	������ ������ ������ �迭�� ��� ���� �ְ� �������� ����
	  => 6000+����*500 => 500*log500 < 2000��
	�켱���� �迭 ť ���

	���������� ������� ����
		������ ���� ������ ���� �����̰� ���������� �۴ٸ�
				=> ���Ѵ��� ���� ���� -> -1����� ���α׷� ����
		������ ���� ���� ���� ���, ���������� �۴ٸ�
				=> ���� ������ que�� ����
		������ ���� ���簪�� ���������� ũ�ٸ�
				=> �̹� ��� �Ϸ� ����
		������ ���ٸ� => que����
	���� �ִ� ��� ������ �����Ҷ� ����(que�� ����������)
	6000*6000�� ���� => �� 36000000�� 3õ���� => �ð� ���

	36000000
*/