#include <iostream>
#include<algorithm>
int a[501][501];
int d[501][501];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	d[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				d[i][j] = d[i - 1][j] + a[i][j];
			if (j == i)
				d[i][j] = d[i - 1][j - 1] + a[i][j];
			else
			d[i][j] = max(d[i - 1][j-1], d[i - 1][j]) + a[i][j];
		}
	}
	int max;
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			max = d[n][i];
		else {
			if (d[n][i] > max)
				max = d[n][i];
		}
	}
	cout << max;
	return 0;
}