#include <iostream>
#include<algorithm>
using namespace std;
int a[3][100001];
int d[3][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		}
		d[0][0] = 0; d[1][0] = 0; d[2][0] = 0;
		for (int k = 1; k <= n; k++) {
			d[0][k] = max({ d[0][k - 1], d[1][k - 1], d[2][k - 1] });
			d[1][k] = max(d[0][k - 1], d[2][k - 1]) + a[1][k];
			d[2][k] = max(d[0][k - 1], d[1][k - 1]) + a[2][k];
		}
		cout << max({ d[0][n], d[1][n], d[2][n] }) << '\n';
	}
	return 0;
}