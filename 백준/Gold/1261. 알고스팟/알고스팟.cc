#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, map[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int d[101][101] = { 0 };
bool visited[101][101] = { false };

void dijkstra(int dist, int x, int y) {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push(make_tuple(dist, x, y));
	while (!pq.empty()) {
		int dist, x, y;
		tie(dist, x, y) = pq.top();
		if (x == m && y == n) {
			cout << d[x][y];
			return;
		}
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= m && 1 <= ny && ny <= n && !visited[nx][ny])
			{
				if (map[nx][ny] == 0)
					d[nx][ny] = d[x][y];
				else
					d[nx][ny] = d[x][y] + 1;
				pq.push({ d[nx][ny], nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%1d", &map[i][j]);
	}
	dijkstra(0, 1, 1);
}