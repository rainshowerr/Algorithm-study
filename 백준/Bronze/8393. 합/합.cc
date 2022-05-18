#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int x,sum=0;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++)
		sum += i;
	printf("%d", sum);
	return 0;
}