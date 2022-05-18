#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}