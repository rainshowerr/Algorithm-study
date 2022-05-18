#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char str[1000001];
	int i, count = 0, len;
	scanf("%[^\n]", str);
	len = strlen(str);
	if (len == 1){ 
		if (str[0] == ' ') {
			printf("0");
			return 0;
		}
	}
	for (i = 1; i < len-1; i++) {
		if (str[i] == ' ')
			count++;
	}
	count++;
	printf("%d", count);
	return 0;
}