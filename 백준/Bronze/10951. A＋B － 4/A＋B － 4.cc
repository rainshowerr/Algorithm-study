#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n1,n2;
	while(scanf("%d %d",&n1,&n2)==2)
	{
		printf("%d\n", n1 + n2);
	}
	return 0;
}