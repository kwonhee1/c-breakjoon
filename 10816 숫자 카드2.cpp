#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void*a, const void* b) {
	if (*(int*)a > *(int*)b) { return 1; }
	else { return -1; }
}
int compare2(const void* a, const void* b) {
	if (**(int**)a > **(int**)b) {return 1;}
	else { return -1; }
}

int main() {
	int n, m;
	scanf("%d", &n);
	int *narr = new int[n];
	for (int* i = narr; i < narr + n; i++) {
		scanf("%d",i);
	}
	scanf("%d", &m);
	int* marr = new int[m<<1] {0,}; // m�� 2��
	for (int* i = marr; i < marr + m; i++) {
		scanf("%d", i);
	}
	//������ �迪 ���� �� ��Ī
	int** parr = new int* [m];
	int** parr_ = parr;
	int* j = marr;
	while (parr_ < parr + m) {
		*parr_++ = j++;
		//parr_++; j++;
	}

	// ���� ������ ������ ����
	qsort(narr, n,sizeof(int),compare);
	/*printf("����Ȯ��\n");
	for (int* i = narr; i < narr + n; i++) {
		printf("%d ", *i);
	}*/

	qsort(parr, m,sizeof(int*),compare2);
	/*printf("\n");
	for (int** i = parr; i < parr + m; i++) {
		printf("%d ", **i);
	}
	printf("\n");*/
	// start
	int *i = narr;
	parr_ = parr;
	while(parr_ < parr + m && i<narr+n) {
		if (parr_!=parr && **(parr_-1) == **parr_) {
			*(*parr_ + m) = *(*(parr_-1) + m);
			parr_++;
		}
		else if (*i == **parr_) {
			//���� ���� ã������
			*(*parr_ + m)+=1;
			i++;
		}
		else if (*i > **parr_) {
			// i�� ���� �� Ŭ��
			parr_++;
		}
		else{
			// j�� ���� �� Ŭ��
			i++;
		}
	}
	// �����ִ� ������ ������ ���̶� ���� ���� �����Ѵٸ�
	parr_++;
	while (parr_ < parr + m) {
		if ( **(parr_ - 1) == **parr_) {
			*(*parr_ + m) = *(*(parr_ - 1) + m);
			parr_++;
		}
		else {
			break;
		}
	}

	// ��� 
	//printf("\n���\n");
	for (int* i = marr+m; i < marr + (m<<1); i++) {
		printf("%d ", *i);
	}
}