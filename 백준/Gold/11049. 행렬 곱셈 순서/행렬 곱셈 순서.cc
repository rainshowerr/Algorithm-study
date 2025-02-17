#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> square[501];
int dp[501][501]; // i부터 j까지 최소연산횟수

int cal(int i, int j) {
	if (dp[i][j] != 1e9) return dp[i][j];
	if (i == j) return 0;
	int minn = 2147483647;
	for (int k = i; k < j; k++) { // k는 나누는 지점
		minn = min(minn, cal(i, k) + cal(k + 1, j) + square[i].first * square[k].second * square[j].second);
	}
	return dp[i][j] = minn;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = 1e9;
		}
	}
	for(int i = 0; i < n; i++) {
		cin >> square[i].first >> square[i].second;
	}
	cout << cal(0, n - 1);
}