#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
int main() {
	int n, arr[8];
	bool flag1 = true, flag2 = true;
	scanf("%d %d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7]);
	for (int i = 0; i < 8; i++) {
		if (*(arr+i) != i+1)
			flag1 = false;
		if (*(arr+i) != 8 - i)
			flag2 = false;
	}
	if (flag1 == true)
		printf("ascending");
	else if (flag2 == true)
		printf("descending");
	else
		printf("mixed");
}