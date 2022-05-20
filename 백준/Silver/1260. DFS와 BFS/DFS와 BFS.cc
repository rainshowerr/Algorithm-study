#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> alist[1001];
bool check[1001] = { false };
int n, m, v;

void dfs(int idx)
{
	cout << idx << ' ';
	check[idx] = true;
	for (int i = 0; i < alist[idx].size(); i++)
	{
		int next = alist[idx][i];
		if (!check[next])
			dfs(next);
	}
}

void bfs(int idx)
{
	queue<int> q;
	check[idx] = true;
	q.push(idx);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		cout << temp << ' ';
		for (int i = 0; i < alist[temp].size(); i++)
		{
			int next = alist[temp][i];
			if (!check[next])
			{
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(alist[i].begin(), alist[i].end());
	}
	dfs(v);
	cout << '\n';
	memset(check, false, sizeof(check)); // check배열 초기화
	bfs(v);
}