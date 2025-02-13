#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, nn, cost[17][17], dp[66000][17];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> nn;
			cost[i][j] = nn;
		}
	}

	for (int i = 0; i <= (1 << n); i++) {
		for (int j = 1; j <= n; j++)
			dp[i][j] = 1e9;
	}
	dp[1][1] = 0;
	for (int i = 2; i < (1 << n); i++) { // 모든 경로
		for (int j = 1; j <= n; j++) { // 마지막 방문 노드
			if (i & (1 << (j - 1))) {
				for (int k = 1; k <= n; k++) { // 마지막 전 방문 노드
					if (cost[k][j] == 0) continue; // 불가능한 경로
					dp[i][j] = min(dp[i][j], dp[i - (1 << (j - 1))][k] + cost[k][j]); // i~k~j까지의 최소비용경로
				}
			}
		}
	}
	// 시작지점까지의 비용을 포함하여 min값 계산
	int mn = 1e9;
	for (int i = 2; i <= n; i++) {
		if (cost[i][1] == 0) continue;
		mn = min(mn, dp[(1 << n) - 1][i] + cost[i][1]); // 마지막까지 오는 데 최소비용 + 처음으로 돌아가는 비용
	}
	cout << mn;
}