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
	
	//간선들의 배열 vs설정
	vs = new struct vertex*[n+1];
	for (struct vertex** i = vs; i <= vs + n; i++) {
		*i = new struct vertex[m+1]; //0번째에 현개 개수를 저장
		(**i).value = 0; //현재 0개 요소가 존재함을 의미
	}
	visit = new int[n+1];
	for (int* i = visit + 1; i <= visit + n; i++) {
		*i = 2e9;
	}
	visit_ = new int[n + 1] {0, };
	
	// 간선들 입력
	for (int i = m; i; i--) {
		int start, end, value;
		scanf("%d %d %d", &start, &end, &value);
		vs[start][++vs[start][0].value] = {start,end,value};
	}

	// 실행
	solution(1,0);

	// visit값들 출력
	if (!flag) {
		for (int* i = visit + 2; i <= visit + n; i++) {
			if (*i == 2e9) { printf("-1"); }
			else { printf("%d\n", *i); }
		}
	}
}

void solution(int start, int value) {
	//현재 start가 적정한지 확인
		// 온적있고 이전값보다 value가 크거나 같으면 무시
	if (visit[start] <= value || flag) { return; }
		// 무한루프라면 프로그램 종료
	else if (visit_[start]) { printf("-1"); flag = 1; return; }

	else {
		// start에 visit
		visit_[start] = 1; visit[start] = value;

		//모든 간선들에 대한 실행
		for (struct vertex* i = &vs[start][vs[start][0].value]; i > &vs[start][0]; i--) {
			solution(i->end, i->value + value);
		}

		//배열 수정
		visit_[start] = 0;
	}
}

void add_vs(int start, int end, int value) {
	vs[start][++vs[start]->value] = {start, end, value};
}

/*
	6000*500 + 6000 = 약 300 0000 => 메모리는 충분함
	각각의 역마다 간선을 배열로 잡고 가다 넣고 마지막에 정렬
	  => 6000+정렬*500 => 500*log500 < 2000번
	우선순위 배열 큐 사용

	시작점부터 간선모두 조사
		이전에 갔고 현재의 값이 음수이고 이전값보다 작다면
				=> 무한대의 음수 가능 -> -1출력후 프로그램 종료
		이전에 갔고 현재 값이 양수, 이전값보다 작다면
				=> 다음 목적지 que에 넣음
		이전에 갔고 현재값이 이전값보다 크다면
				=> 이미 계산 완료 버림
		간적이 없다면 => que삽입
	갈수 있는 모든 간선을 조사할때 까지(que가 끝날때까지)
	6000*6000의 정렬 => 약 36000000번 3천만번 => 시간 통과

	36000000
*/