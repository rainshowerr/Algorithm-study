#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, map[1001][1001];
int visited[1001][1001][11][2]; // 거리 배열 역할 동시에 수행. 세번째는 벽을 부순 개수, 네번째는 낮이면 0 밤이면 1

int main() {
	int dx[5] = { -1, 1, 0, 0, 0 };
	int dy[5] = { 0, 0, -1, 1, 0 };
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);
	}
	// visited 배열 초기화
	memset(visited, -1, sizeof(visited));
	// BFS
	queue <tuple<pair<int, int>, int, int>> q;
	q.push({{ 1, 1 }, 0, 0 });
	visited[1][1][0][0] = 1;
	while (!q.empty()) {
		int x = get<0>(q.front()).first;
		int y = get<0>(q.front()).second;
		int broken = get<1>(q.front());
        bool day_or_night = get<2>(q.front());
		if (x == n && y == m){
			cout << visited[x][y][broken][day_or_night];
			return 0;
		}
		q.pop();
		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
            int nextday = 1 - day_or_night;
			// 길이 뚫려있는 경우
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m 
            && visited[nx][ny][broken][nextday] == -1 && map[nx][ny] == 0) {
				q.push({ { nx, ny }, broken, nextday });
				visited[nx][ny][broken][nextday] = visited[x][y][broken][day_or_night] + 1;
			}
			// 벽이 마주친 경우 (낮)
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m 
            && broken < k && day_or_night == 0 && visited[nx][ny][broken + 1][nextday] == -1 && map[nx][ny] == 1) {
				q.push({ { nx, ny }, broken + 1, nextday });
				visited[nx][ny][broken + 1][nextday] = visited[x][y][broken][day_or_night] + 1;
			}
            // 벽을 마주친 경우 (밤) -> 제자리에 있음
            if (nx == x && ny == y && day_or_night == 1 && visited[nx][ny][broken][nextday] == -1) {
				q.push({ { nx, ny }, broken, nextday });
				visited[nx][ny][broken][nextday] = visited[x][y][broken][day_or_night] + 1;
			}
		}
	}
	cout << "-1";
	return 0;
}