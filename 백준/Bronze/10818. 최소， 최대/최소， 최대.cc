#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	int n;
	scanf("%d", &n);
	int max = -1000000, min = 1000000;
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x > max)
			max = x;
		if (x < min)
			min = x;
	}
	printf("%d %d", min, max);
	return 0;
}