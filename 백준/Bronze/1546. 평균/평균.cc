#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(){
	int n, score[1000], max;
	double  newscore[1000], sum = 0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0)
			max = score[i];
		else
			if (score[i] > max)
				max = score[i];
	}
	for (int i = 0; i < n; i++) {
		newscore[i] = (double)score[i] * 100 / max;
		sum += newscore[i];
	}
	printf("%lf", sum / n);
	return 0;
}