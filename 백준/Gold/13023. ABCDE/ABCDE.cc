#include <iostream>
#include <vector>
using namespace std;

vector<int> v[2000];
bool ans = false, visited[2000] = { false };

void go(int cnt, int idx)
{
	if (cnt == 4)
	{
		ans = true;
		return;
	}
	for (int i = 0; i < v[idx].size(); i++)
	{
		visited[idx] = true;
		if (!visited[v[idx][i]]) // 다음 노드가 방문하지 않은 노드일 때만 go!
			go(cnt + 1, v[idx][i]);
		visited[idx] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to; cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for (int i = 0; i < n; i++)
	{
		go(0, i);
		if (ans == true)
			break;
	}
	if (ans)
		cout << 1;
	else
		cout << 0;
	return 0;
}