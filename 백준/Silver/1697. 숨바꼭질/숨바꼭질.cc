#include <iostream>
using namespace std;
#include <queue>

queue<int> q;
int dist[100002] = { 0 };
bool visited[100002] = { false };
int n, k;
int ans;

void bfs() {
	q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		int go[3] = { n - 1, n + 1, 2 * n }; // 한 칸 앞, 한 칸 뒤, 두배 점프
		for (int i = 0; i < 3; i++) {
			int nx = go[i];
			if (0 <= nx && nx <= 100001 && !visited[nx]) {
				q.push(nx);
				visited[nx] = true;
				dist[nx] = dist[n] + 1;
			}
			if (nx == k) {
				ans = dist[nx];
				return;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	if (n == k) {
		cout << '0';
	}
	else if (n > k) {
		cout << n - k;
	}
	else {
		bfs();
		cout << ans;
	}
}