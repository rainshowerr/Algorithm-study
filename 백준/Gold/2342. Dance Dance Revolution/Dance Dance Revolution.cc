#include <iostream>
#include <algorithm>

using namespace std;

int ddr[100001];
int dp[100001][5][5]; // i번째에 x, y에 있을 때 최소값
// dp[i][x][y] = min(dp[i-1][이전x][y] + x_cost, dp[i-1][x][이전y] + y_cost)

int cost(int x, int y) {
	if (x == y) return 1;
	if (x == 0 || y == 0) return 2;
	if (abs(x - y) == 2) return 4;
	else return 3;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, i = 1, ddr_len;
	cin >> n;
	while(n) {
		ddr[i++] = n;
		cin >> n;
	}

	// dp배열 초기화
	ddr_len = i;
	for(int i = 1; i < ddr_len; i++) {
		for(int x = 0; x <= 4; x++) {
			for(int y = 0; y <= 4; y++) {
				dp[i][x][y] = 1e9;
			}
		}
	}

	// DP
	dp[1][ddr[1]][0] = cost(ddr[1], 0); // 초기값 설정
	for(int i = 2; i < ddr_len; i++) {
		for(int x = 0; x <= 4; x++) {
			for(int y = 0; y <= 4; y++) {
				if (dp[i - 1][x][y] != 1e9) {
					dp[i][ddr[i]][y] = min(dp[i][ddr[i]][y], dp[i - 1][x][y] + cost(x, ddr[i]));
					dp[i][x][ddr[i]] = min(dp[i][x][ddr[i]], dp[i - 1][x][y] + cost(y, ddr[i]));
					// cout << i << ' ' << x << ' ' << ddr[i] << ' ' << dp[i][x][ddr[i]] << '\n';
					// cout << i << ' ' << ddr[i] << ' ' << y << ' ' << dp[i][ddr[i]][y] << '\n';
				}
			}
		}
	}

	int minn = 1e9;
	for(int i = 0; i <= 4; i++) {
		minn = min(minn, dp[ddr_len - 1][ddr[ddr_len - 1]][i]);
		minn = min(minn, dp[ddr_len - 1][i][ddr[ddr_len - 1]]);
	}
	cout << minn;
}