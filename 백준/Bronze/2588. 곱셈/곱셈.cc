#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int A,B;
	int b1, b2, b3;
	scanf("%d %d", &A, &B);
	b1 = B / 100;
	b2 = (B - b1*100) / 10;
	b3 = B - (b1 * 100 + b2 * 10);
	printf("%d\n%d\n%d\n", b3*A,b2*A,b1*A);
	printf("%d", A * B);
	return 0;
}