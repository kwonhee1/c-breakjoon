#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <list>
//using namespace std;
// 25192�� �λ缺 ���� ������

bool equal(char* str1, char* str2) {
	while (*str1||*str2) {
		if (*str1 != *str2) {
			return 0;
		}
		str1++; str2++;
	}
	if (!*str1&& !*str2) { return 1; }
	return 0;
}

void cpy(char* str1, char* str2) {
	// str1 -> str2
	for (int i = 20; i != 0 || str1; i--, str2++, str1++) {
		*str2 = *str1;
	}
}

int main() {
	int n, re = 0;
	char str[20];
	char ENTER[6] = "ENTER";

	std::list<char*> arr;

	scanf("%d", &n);
	for (; n != 0; n--) {
		// str �ʱ�ȭ ���� ����
		scanf("%s", &str);
		if (equal(str,ENTER)) {
			//arr �ʱ�ȭ
			arr.clear();
		}
		else {
			//arr�� ���� ���� �ִ��� Ȯ��
			for (std::list<char*>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
				if(equal(str,(char*)iter))
			}
			//arr�� ���� ���� ���ٸ� arr�� �ֱ�
			re++;
		}
	}
	printf("%d", re);
}