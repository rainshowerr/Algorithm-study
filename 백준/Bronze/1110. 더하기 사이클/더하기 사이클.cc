#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	int n, newn, count=0;
	scanf("%d", &n);
	if (n < 10)
		n *= 10;
	newn = (n % 10) * 10 + (n / 10 + n % 10) % 10;
	count++;
	while (newn != n) {
		newn= (newn % 10) * 10 + (newn / 10 + newn % 10) % 10;
		count++;
	}
	printf("%d", count);
	return 0;
}