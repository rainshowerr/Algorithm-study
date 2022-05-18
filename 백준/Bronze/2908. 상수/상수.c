#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a, b, c = 0, d = 0;
	scanf("%d %d", &a, &b);
	c += (a / 100) + ((a % 100) / 10) * 10 + (a % 10) * 100;
	d += (b / 100) + ((b % 100) / 10) * 10 + (b % 10) * 100;
	if (c > d)
		printf("%d", c);
	else
		printf("%d", d);
}