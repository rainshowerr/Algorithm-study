#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, map[9][9],temp[9][9], visited[9][9] = { false }, ans = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 바이러스를 퍼뜨리는 함수
void virus() {
	queue<pair<int, int>> q;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 2 && !visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= m && temp[nx][ny] == 0 && !visited[nx][ny]) {
							q.push({ nx, ny });
							temp[nx][ny] = 2;
							visited[nx][ny] = true;
						}
					}
				}
			}
		}
	}
}

// 안전구역의 개수를 세는 함수
int safty() {
	int safe = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (temp[i][j] == 0) {
				safe++;
			}
		}
	}
	return safe;
}

// 벽을 세우는 함수
void makewall(int cnt) {
	if (cnt == 3) {
		// 지도 복사
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= m; b++) {
				temp[a][b] = map[a][b];
			}
		}
		// 바이러스를 퍼뜨린 후 안전구역 카운트
		virus();
		ans = max(ans, safty());
		return;
	}
	// 벽 세우기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				makewall(cnt + 1);
				map[i][j] = 0; // 지도 원상복구
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	}
	makewall(0);
	cout << ans;
}