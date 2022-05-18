#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int judge(int);

int main(void)
{
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (judge(i))
			count++;
	}
	printf("%d", count);
	return 0;
}

int judge(int x)
{
	int a, b, c;
	if (x < 100)
		return 1;
	else if (x < 1000)
	{
		a = x / 100; b = (x / 10) % 10; c = x % 10;
		if ((a - b) == (b - c))
			return 1;
		else
			return 0;
	}
	else
		return 0;
}