#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char str[20];
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &n, str);
		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
	return 0;
}