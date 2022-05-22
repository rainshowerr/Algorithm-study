#include <iostream>
#include <queue>
using namespace std;

int n, m, map[101][101], ans[101][101];
bool visited[101][101] = { false };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	ans[x][y] = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m
				&& !visited[nx][ny] && map[nx][ny] == 1)
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
				ans[nx][ny] = ans[x][y] + 1;
				if (nx == n && ny == m)
					return;
			}
		}
	}
}

int main()
{
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(1, 1);
	cout << ans[n][m];
}