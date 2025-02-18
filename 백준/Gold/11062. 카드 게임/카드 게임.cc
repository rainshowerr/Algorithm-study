#include <iostream>
#include <algorithm>

using namespace std;

int card[1001];
int dp[1001][1001]; // i ~ j번째 카드가 있을 때 근우가 얻을 수 있는 최대 점수
int t, n;

int dynamic(int turn, int i, int j) {
	if (turn % 2 == 1 && i == j) return card[i];
	else if (turn % 2 == 0 && i == j) return 0;

	if (dp[i][j]) return dp[i][j];

	if (turn % 2 == 1) { // 근우차례: 점수 최대화
		return dp[i][j] = max(card[i] + dynamic(turn + 1, i + 1, j), card[j] + dynamic(turn + 1, i, j - 1));
	} else { // 명우차례: 점수 최소화
		return dp[i][j] = min(dynamic(turn + 1, i + 1, j), dynamic(turn + 1, i, j - 1));
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> card[i];
			for(int j = 1; j <= n; j++) {
				dp[i][j] = 0;
			}
		}
		cout << dynamic(1, 1, n) << '\n';
	}
}