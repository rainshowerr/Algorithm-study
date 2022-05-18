#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str[1000000];
int main() {
	int check[123] = { 0 };
	int len, max, flag=0, maxc;
	scanf("%[^\n]", str);
	len = strlen(str);
	// 각 알파벳이 사용된 횟수 파악
	for (int i = 0; i < len; i++) {
		for (int j = 97; j <= 122; j++) {
			if (((int)str[i] == j)||((int)str[i]==j-32))
				check[j]++;
		}
	}
	for (int j = 97; j <= 122; j++) {
		if (j == 97) { // max를 97로 초기화
			max = check[j];
			maxc = j;
			continue;
		}
		if (max < check[j]) {
			max = check[j];
			maxc = j;
		}
	}
	for (int j = 97; j <= 122; j++) {
		if ((max == check[j])) {
			flag++;
		}
	}
	// 가장 많이 사용된 알파벳이 두 개 이상일 경우
	if (flag > 1) {
		printf("?");
		return 0;
	}

	printf("%c", maxc-32); // 대문자로 바꿔주기
	return 0;
}