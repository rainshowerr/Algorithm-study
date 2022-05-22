#include <iostream>
#include <queue>
using namespace std;

int n, m;
string str[50];
bool visited[50][50] = { false };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool flag = false;
int s_x, s_y;

void dfs(int x, int y, int cnt)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == s_x && ny == s_y && cnt >= 4)
		{
			flag = true;
			return;
		}
		else if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny] && str[x][y] == str[nx][ny])
		{
			dfs(nx, ny, cnt + 1);
		}
	}
	visited[x][y] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s_x = i;
			s_y = j;
			dfs(i, j, 1);
			if (flag == true)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}