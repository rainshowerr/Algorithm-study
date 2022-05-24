#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int m, n, h, ans = 0;
int tmt[100][100][100];
int day[100][100][100]; // 방문 안했으면 -1, 방문했으면 day 수 기록
vector<tuple<int, int, int>> start;
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
queue<tuple<int, int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && 0 <= nz && nz < h
				&& day[nx][ny][nz] == -1 && tmt[nx][ny][nz] == 0)
			{
				q.push({ nx,ny, nz });
				day[nx][ny][nz] = day[x][y][z] + 1;
				ans = max(ans, day[nx][ny][nz]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> m >> n >> h;
	// 토마토 맵 초기화, day배열 -1로 초기화(접근이 안된 상태)
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				day[i][j][k] = -1;
				cin >> tmt[i][j][k];
			}
		}
	}
	// 익은 토마토가 있고 아직 접근이 안된 상태면 큐에 push!
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tmt[i][j][k] == 1 && day[i][j][k] == -1)
				{
					q.push({ i, j, k });
					day[i][j][k] = 0;
				}
			}
		}
	}
	// bfs로 토마토 익히기 (day배열 수정해주기)
	bfs();
	// 예외 처리
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tmt[i][j][k] == 0 && day[i][j][k] == -1) // 안익은 토마토가 존재!
				{
					cout << "-1" << '\n';
					return 0;
				}
			}
		}
	}
	// 결과 출력
	cout << ans << '\n';
	return 0;
}