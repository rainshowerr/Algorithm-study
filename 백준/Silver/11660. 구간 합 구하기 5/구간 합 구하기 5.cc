#include <iostream>

using namespace std;

int num[1025][1025], sum[1025][1025];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, x1, x2, y1, y2;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> num[i][j];
			sum[i][j] = sum[i][j - 1] + num[i][j];
		}
	}
	for(int i = 1; i <= m; i++) {
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int row = x1; row <= x2; row++) {
			ans += sum[row][y2];
			ans -= sum[row][y1 - 1];
		}
		cout << ans << '\n';
	}
}