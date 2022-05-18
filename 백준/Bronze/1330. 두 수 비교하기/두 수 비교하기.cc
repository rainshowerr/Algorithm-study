#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y;
	scanf("%d %d", &x, &y);
	if (x > y)
		printf(">");
	else if (x == y)
		printf("==");
	else
		printf("<");
	return 0;
}