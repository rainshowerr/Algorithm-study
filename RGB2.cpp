#include <iostream>
using namespace std;
int a[1001][3], d[1001][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	int mini=1000*1000+1;
	for (int k = 0; k <= 2; k++) { // 첫번째 집의 색깔
		for (int j = 0; j <= 2; j++) { // 첫번째 집
			if (k == j) {
				d[1][j] = a[1][j];
			}
			else {
				d[1][j] = 1000 * 1000 + 1;
			}
		}
		for (int i = 2; i <= n; i++) { // 두번째~마지막 집
			d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
			d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
			d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
		}
		for (int j = 0; j <= 2; j++) { // 첫번째 집의 색깔과 마지막 집의 색깔이 다른 경우 중 최솟값
			if (k == j)
				continue;
			mini = min(mini, d[n][j]);
		}
	}
	cout << mini;
	return 0;
}