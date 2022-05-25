#include <iostream>
#include <queue>
using namespace std;

int s, answer;
bool visited[1001][1001] = { false };
int t[1001][1001];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1][0] = true;
	t[1][0] = 0;
	while (!q.empty()) {
		int n = q.front().first;
		int c = q.front().second;
		q.pop();
		if (n == s) {
			cout << t[n][c];
			return;
		}
		// 복사
		// 화면의 임티 수와 클립보드의 임티 수가 다른 경우 && 복사가 진행되지 않았을 경우
		if (c != n && !visited[n][n]) {
			q.push({ n, n });
			visited[n][n] = true;
			t[n][n] = t[n][c] + 1;
		}
		// 붙여넣기
		// 클립보드 임티 수 > 0 && 붙여넣었을 때 임티 수가 1000개를 넘으면 안 됨 && 붙여넣기가 진행되기 않았을 경우
		if (c && n + c <= 1000 && !visited[n + c][c]) {
			q.push({ n + c, c });
			visited[n + c][n] = true;
			t[n + c][c] = t[n][c] + 1;
		}
		// 삭제
		// 삭제했을 때 임티 수가 0개 이상이어야 함 && 삭제가 진행되지 않았을 경우
		if (0 <= n - 1 && !visited[n - 1][c]) {
			q.push({ n - 1, c });
			visited[n-1][c] = true;
			t[n-1][c] = t[n][c] + 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> s;
	bfs();
}