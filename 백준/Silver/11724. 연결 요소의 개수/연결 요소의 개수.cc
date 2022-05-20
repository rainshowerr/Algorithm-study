#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1001];
bool visited[1001] = { false };

void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];
		if (!visited[next])
			dfs(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}