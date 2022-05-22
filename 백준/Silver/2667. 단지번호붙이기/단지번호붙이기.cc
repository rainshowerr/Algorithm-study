#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int map[26][26];
vector<int> ans;
bool visited[26][26] = { false };
// 상, 하, 좌, 우로 가기 위한 배열
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int row, int col)
{
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = true;
	int cnt = 0;
	cnt++;
	while (!q.empty())
	{
		int front_x = q.front().first;
		int front_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			// next_x, next_y는 다음으로 push할 인덱스 후보
			int next_x = front_x + dx[i];
			int next_y = front_y + dy[i];
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n // 범위는 지도를 넘어가면 안됨
				&& visited[next_x][next_y] == false && map[next_x][next_y] == 1)
			{
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
				cnt++;
			}
		}
	}
	ans.push_back(cnt);
}

int main()
{
	cout.tie(nullptr);
	cin >> n;
	// 지도 입력받기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	// 지도 탐색
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == false && map[i][j] == 1)
			{
				bfs(i, j);
			}
		}
	}
	// 결과 도출
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}