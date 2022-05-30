#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n, m, map[1001][1001];
int visited[1001][1001][2]; // 거리 배열 역할 동시에 수행

int main() {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	cin >> n >> m;
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
		if (x == n && y == m) {
			if (broken)
				cout << visited[n][m][1];
			else
				cout << visited[n][m][0];
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 벽을 부순 적 없고 벽을 마주쳐서 부수는 경우
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && visited[nx][ny][1] == -1 && !broken && map[nx][ny] == 1) {
				q.push({ nx, ny, 1 });
				visited[nx][ny][1] = visited[x][y][0] + 1;
			}
			// 벽을 부순 적 없고 길이 뚫려있는 경우
			else if (1 <= nx && nx <= n && 1 <= ny && ny <= m && visited[nx][ny][0] == -1 && !broken && map[nx][ny] == 0) {
				q.push({ nx, ny, 0 });
				visited[nx][ny][0] = visited[x][y][0] + 1;
			}
			// 벽을 부순 적 있고 길이 뚫려있는 경우
			else if (1 <= nx && nx <= n && 1 <= ny && ny <= m && visited[nx][ny][1] == -1 && broken && map[nx][ny] == 0) {
				q.push({ nx, ny, 1 });
				visited[nx][ny][1] = visited[x][y][1] + 1;
			}
		}
	}
	cout << "-1";
	return 0;
}