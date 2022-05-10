#include <stdio.h>

int main()
{
	int mk[4], ms[4], sum_mk = 0, sum_ms = 0;
	
	scanf("%d %d %d %d", &mk[0], &mk[1], &mk[2], &mk[3]);
	scanf("%d %d %d %d", &ms[0], &ms[1], &ms[2], &ms[3]);
	sum_mk = mk[0] + mk[1] + mk[2] + mk[3];
	sum_ms = ms[0] + ms[1] + ms[2] + ms[3];
	if (sum_mk >= sum_ms)
		printf("%d", sum_mk);
	else
		printf("%d", sum_ms);
}