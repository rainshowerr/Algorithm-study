#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, map[1001][1001];
int visited[1001][1001][11]; // 거리 배열 역할 동시에 수행

int main() {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);
	}
	// visited 배열 초기화
	memset(visited, -1, sizeof(visited));
	// BFS
	queue <tuple<int, int, int >> q;
	q.push({ 1, 1, 0 });
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int broken = get<2>(q.front());
		if (x == n && y == m){
			cout << visited[x][y][broken];
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 길이 뚫려있는 경우
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && visited[nx][ny][broken] == -1 && map[nx][ny] == 0) {
				q.push({ nx, ny, broken });
				visited[nx][ny][broken] = visited[x][y][broken] + 1;
			}
			// 벽이 마주친 경우
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && broken < k && visited[nx][ny][broken + 1] == -1 && map[nx][ny] == 1) {
				q.push({ nx, ny, broken + 1 });
				visited[nx][ny][broken + 1] = visited[x][y][broken] + 1;
			}
		}
	}
	cout << "-1";
	return 0;
}