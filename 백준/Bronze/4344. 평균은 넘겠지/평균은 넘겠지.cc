#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, score[1000],sum=0, ranker=0;
		double avg;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			sum += score[i];
		}
		avg = (double)sum / n;
		for (int i = 0; i < n; i++) {
			if (score[i] > avg)
				ranker++;
		}
		printf("%.3lf%%\n", (double)ranker / n * 100);
	}
	return 0;
}