#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count=0, arr[10], remain[42] = { 0 };
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < 10; i++)
		arr[i] = arr[i] % 42;
	for (int i = 0; i < 42; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] == i)
				remain[i] += 1;
		}
	}
	for (int i = 0; i < 42;i++)
	{
		if (remain[i] > 0)
			count++;
	}
	printf("%d", count);
	return 0;
}