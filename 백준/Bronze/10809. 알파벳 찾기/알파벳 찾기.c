#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char s[101] = { 0 };
	int arr[123], len;
	// 배열 초기화
	for (int i = 97; i < 123; i++) {
		arr[i] = -1;
	}
	scanf("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++) {
		// 알파벳이 처음 등장할 경우
		if (arr[s[i]] == -1)
			arr[s[i]] = i;
	}
	for (int i = 97; i < 123; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}