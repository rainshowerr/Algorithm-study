#include <iostream>
using namespace std;
long long d[91][2];
long long go(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++)
			d[i][j] = -1;
	}
	cout << go(n, 0) + go(n, 1);
	return 0;
}
long long go(int n, int x) {
	d[1][0] = 0; d[1][1] = 1;
	if (d[n][x] != -1) {
		return d[n][x];
	}
	if (x == 0) {
		d[n][x] = go(n - 1, x + 1) + go(n - 1, x);
	}
	if (x == 1) {
		d[n][x] = go(n - 1, x - 1);
	}
	return d[n][x];
}