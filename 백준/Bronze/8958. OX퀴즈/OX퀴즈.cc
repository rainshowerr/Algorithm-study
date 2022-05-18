#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char x[80] = { 0 };
		scanf("%s", x);
		int temp = 0, score=0;
		for (int i=0;i<strlen(x);i++){
			if (x[i] == 'O')
				temp++;
			else if (x[i] == 'X') {
				for (int j = 1; j <= temp; j++)
					score += j;
				temp = 0;
			}
			if (i == strlen(x) - 1) {
				for(int j = 1 ; j <= temp ; j++)
					score += j;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}