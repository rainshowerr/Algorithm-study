#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int m, n, ans = 0;
int tmt[1000][1000];
int day[1000][1000]; // 방문 안했으면 -1, 방문했으면 day 수 기록
vector<pair<int, int>> start;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && day[nx][ny] == -1 && tmt[nx][ny] == 0)
			{
				q.push({ nx,ny });
				day[nx][ny] = day[x][y] + 1;
				ans = max(ans, day[nx][ny]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> m >> n;
	// 토마토 맵 초기화, day배열 -1로 초기화(접근이 안된 상태)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			day[i][j] = -1;
			cin >> tmt[i][j];
		}
	}
	// 익은 토마토가 있고 아직 접근이 안된 상태면 큐에 push!
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmt[i][j] == 1 && day[i][j] == -1)
			{
				q.push({ i, j });
				day[i][j] = 0;
			}
		}
	}
	// bfs로 토마토 익히기 (day배열 수정해주기)
	bfs();
	// 예외 처리
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmt[i][j] == 0 && day[i][j] == -1) // 안익은 토마토가 존재!
			{
				cout << "-1" << '\n';
				return 0;
			}
		}
	}
	// 결과 출력
	cout << ans << '\n';
	return 0;
}