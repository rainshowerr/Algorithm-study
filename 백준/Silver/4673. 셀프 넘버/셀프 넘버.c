#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int selfnum(int);

int main(void)
{
	for (int i = 1; i <= 10000; i++)
	{
		if (selfnum(i))
			printf("%d\n", i);
	}
	return 0;
}

int selfnum(int x)
{
	for (int j = 1; j < x; j++)
	{
		if (x < 100)
		{
			if (x == j + (j / 10) + (j % 10))
			{
				return 0;
			}
		}
		if (x < 1000)
		{
			if (x == j + (j / 100) + (j / 10) % 10 + (j % 10))
			{
				return 0;
			}
		}
		if (x < 10000)
		{
			if (x == j + (j / 1000) + (j/100)%10 + (j/10)%10 + (j % 10))
			{
				return 0;
			}
		}
		if (x == 10000)
		{
			if (x == j + (j / 10000) + (j/1000)%10 + (j/100)%10 + (j/10)%10 + (j % 10))
			{
				return 0;
			}
		}
	}
	return 1;
}