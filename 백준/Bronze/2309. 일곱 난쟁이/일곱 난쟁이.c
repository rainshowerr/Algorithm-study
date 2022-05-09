#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int dwarf[9], total = 0, sum, temp, flag = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &dwarf[i]);
		total += dwarf[i];
	}
	sum = total - 100; // 두 가짜 난쟁이 키의 합
	for (int i = 0; i < 8; i++)
	{
		if (flag)
			break;
		for (int j = i + 1; j < 9; j++)
		{
			if (dwarf[i] + dwarf[j] == sum)
			{
				dwarf[i] = 0;
				dwarf[j] = 0;
				flag = 1;
				break;
			}
		}
	}
	// 버블정렬
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8 - i; j++)
		{
			if (dwarf[j] > dwarf[j + 1])
			{
				temp = dwarf[j];
				dwarf[j] = dwarf[j + 1];
				dwarf[j + 1] = temp;
			}
		}
	}
	for (int i = 2; i < 9; i++)
	{
		printf("%d\n", dwarf[i]);
	}
	return 0;
}