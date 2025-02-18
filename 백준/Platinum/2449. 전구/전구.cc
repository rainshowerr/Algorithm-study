#include <iostream>
#include <algorithm>

using namespace std;

int dp[201][201]; // i부터 j까지 j번 색으로 맞추는 데 드는 최소횟수
int color[201];

int dynamic(int i, int j) {
	if (dp[i][j] != 1e9) return dp[i][j];
	if (i == j) return 0;

	for (int k = i; k <= j; k++) { // k를 기준으로 다시 나눠서 계산
		if (color[k] == color[j]) dp[i][j] = min(dp[i][j], dynamic(i, k) + dynamic(k + 1, j));
		else dp[i][j] = min(dp[i][j], dynamic(i, k) + dynamic(k + 1, j) + 1);
	}
	return dp[i][j];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		color[i] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = 1e9;
		}
	}
	cout << dynamic(1, n);
}