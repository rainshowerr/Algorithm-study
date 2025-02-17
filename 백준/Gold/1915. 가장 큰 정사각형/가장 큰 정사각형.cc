#include <iostream>
#include <algorithm>

using namespace std;

int square[1001][1001];
int dp[1001][1001]; // i, j를 오른쪽 끝점으로 하는 정사각형의 최대 넓이

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, maxx = 0;
	string s;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		for(int j = 1; j <= m; j++) {
			square[i][j] = s[j - 1] - '0';
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (square[i][j]) {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			maxx = max(maxx, dp[i][j]);
		}
	}
	cout << maxx * maxx;
}