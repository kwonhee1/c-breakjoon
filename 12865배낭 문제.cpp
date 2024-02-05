#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct ob {
	int weight;
	int value;

};

int compare (const void* a, const void* b) {
	// 무게가 같으면 -> value높은 순
	return ((struct ob*)a)->weight > ((struct ob*) b)->weight;
}

int max_weight, max_n, min_weight;
int* arr;
struct ob* obs;

int f(int weight, int n) { //n번째 물건 + weight
	if (!arr[n * max_weight + weight]) {
		int* arr_ = &arr[n * max_weight + weight];
		// 입력된 무게가 2번째 물체의 무게보다 작을때
		// 또는 입력된 개수가 0개일때
		if (weight < min_weight || !n) { 
			if (weight < obs[0].weight) { *arr_ = 0; }
			else { *arr_ = obs[0].value; }
		}
		//구할수 없다면 나눔
		else {
			int buff, buff2;
			//arr[n][weight] = arr[n-1][weight-obs[n].weight] + obs[n].value > arr[n-1][weight] ? buff : buff2;
			*arr_ =( (buff = f(weight - obs[n].weight, n - 1) + obs[n].value) > (buff2 = f(weight, n - 1)) ? buff : buff2 );
		}

		//printf("weight: %d, n: %d => %d\n", weight, n, *arr_);
		return *arr_;
	}
	//printf("weight: %d, n: %d => %d\n", weight, n, arr[n * max_weight + weight]);
	return arr[n * max_weight + weight];
}

int main() {
	scanf("%d %d", &max_n, &max_weight);

	arr = new int[max_weight*max_n+1]{0,}; // arr[weight][n] => weight*n + n
	obs = new struct ob[max_n];

	//입력
	for (struct ob* obs_ = obs; obs_ < obs + max_n; obs_++)
		scanf("%d %d", &obs_->weight, &obs_->value);

	//정렬  무거운게 뒤로
	qsort(obs, max_n, sizeof(obs), compare);

	//정렬 확인 
	/*for (int i = 0; i < max_n; i++) {
		printf("%d > weight:%d, value:%d\n",i, obs[i].weight, obs[i].value);
	}
	printf("\n");*/

	// max_weight를 넘어가는 값 모두 제외하기
	int i= max_n-1;
	for (; i >= 0; i--) {
		//처음 max_weight보다 더 작은 i에서 멈춤
		if (obs[i].weight <= max_weight) { break; }
	}

	//주번째로 작은 값
	if (i >= 1) { 
		min_weight = obs[1].weight;
		//printf("min_weight : %d\n", min_weight);
	}
	else if (i == 0) {
		min_weight = 0;
	}
	else {
		printf("0"); return 0;
	}


	printf("%d",f(max_weight, i));

	delete[] arr;
	delete[] obs;
}
