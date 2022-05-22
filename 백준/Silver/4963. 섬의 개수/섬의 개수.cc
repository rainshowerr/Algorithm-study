#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int map[51][51];
bool visited[51][51] = { false };
// 상, 하, 좌, 우로 가기 위한 배열
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1};

void bfs(int row, int col, int *cnt)
{
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = true;
	(*cnt)++;
	while (!q.empty())
	{
		int front_x = q.front().first;
		int front_y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			// next_x, next_y는 다음으로 push할 인덱스 후보
			int next_x = front_x + dx[i];
			int next_y = front_y + dy[i];
			if (0 <= next_x && next_x < h && 0 <= next_y && next_y < w // 범위는 지도를 넘어가면 안됨
				&& visited[next_x][next_y] == false && map[next_x][next_y] == 1)
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
			}
		}
	}
}

int main()
{
	cout.tie(nullptr);
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		// 지도 입력받기
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		// 지도 탐색
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == false && map[i][j] == 1)
				{
					bfs(i, j, &cnt);
				}
			}
		}
		// 결과 도출
		cout << cnt << '\n';
	}
}