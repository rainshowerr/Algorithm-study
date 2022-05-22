#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int l;
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2 , -2, -1, 1, 2};
int visited[300][300]; // -1이면 미방문, 아니면 이동횟수

void bfs(int x, int y)
{
	queue <pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < l && 0 <= ny && ny < l && visited[nx][ny] == -1)
			{
				q.push({ nx, ny });
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, x, y, res_x, res_y;
	cin >> t;
	while (t--)
	{
		cin >> l >> x >> y >> res_x >> res_y;
		// visited 배열 -1로 초기화
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				visited[i][j] = -1;
			}
		}
		bfs(x, y);
		cout << visited[res_x][res_y] << '\n';
	}
}