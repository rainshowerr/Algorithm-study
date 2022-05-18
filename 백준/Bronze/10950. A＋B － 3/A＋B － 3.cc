#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num, n1,n2;
	scanf("%d", &num);
	while(num--)
	{
		scanf("%d %d", &n1, &n2);
		printf("%d\n", n1 + n2);
	}
	return 0;
}