#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

pair<int, int> incident[1001];
int dp[1001][1001]; // 1번경찰차가 마지막으로 i번사건을 해결하고 2번경찰차가 마지막으로 j번사건을 해결하는 최적해
pair<int, int> from[1001][1001]; // 경로 역추적
vector<int> path;

int distance(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= w; i++) {
		int x, y;
		cin >> x >> y;
		incident[i] = { x, y };
	}

	// 초기값 설정
	for (int i = 0; i <= w; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j] = 1e9;
		}
	}
	dp[0][0] = 0;
	dp[1][0] = distance({ 1, 1 }, incident[1]);
	dp[0][1] = distance({ n, n }, incident[1]);
	from[1][0] = { 1, 0 };
	from[0][1] = { 2, 0 };
	for (int i = 0; i <= w; i++) {
		for (int j = 0; j <= w; j++) {
			if (dp[i][j] != 1e9 || i == j) continue;
			if (i + 1 == j) { // ex. i = 2, j = 3 -> j가 어디에서 왔을지 모름
				incident[0] = { n, n };
				for(int k = 0; k < i; k++) {
					if (dp[i][j] > dp[i][k] + distance(incident[k], incident[j])) {
						dp[i][j] = dp[i][k] + distance(incident[k], incident[j]);
						from[i][j] = { 2, k };
					};
				}
			}
			else if (j + 1 == i) { // ex. i = 3, j = 2 -> i가 어디에서 왔을지 모름
				for (int k = 0; k < j; k++) {
					incident[0] = { 1, 1 };
					if (dp[i][j] > dp[k][j] + distance(incident[k], incident[i])) {
						dp[i][j] = dp[k][j] + distance(incident[k], incident[i]);
						from[i][j] = { 1, k };
					};
				}
			}
			else if (i + 1 < j) { // ex. i = 1, j = 3 -> j는 바로 전에서 온 게 확실
				dp[i][j] = dp[i][j - 1] + distance(incident[j - 1], incident[j]);
				from[i][j] = { 2, j - 1 };
			}
			else if (j + 1 < i) { // ex. i = 3, j = 1 -> i는 바로 전에서 온 게 확실
				dp[i][j] = dp[i - 1][j] + distance(incident[i - 1], incident[i]);
				from[i][j] = { 1, i - 1 };
			};
			//cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << from[i][j].first << ' ' << from[i][j].second << '\n';
		}
	}
	int ans = 1e9;
	int x, y;
	for (int i = 0; i < w; i++) {
		if (ans > dp[w][i]) {
			ans = dp[w][i];
			x = w; y = i;
		}
		if (ans > dp[i][w]) {
			ans = dp[i][w];
			x = i; y = w;
		}
	}

	cout << ans << '\n';
	//// 경로 역추적
	while (!(x == 0 && y == 0)) {
		path.push_back(from[x][y].first);
		if (from[x][y].first == 1) {
			x = from[x][y].second;
		}
		else {
			y = from[x][y].second;
		}
	}
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << '\n';
}