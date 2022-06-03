#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[100001] = { false };
vector<int> v[100001];
int order[100001];
vector<int> user;
vector<int> ans;

bool cmp(int a, int b) {
	return (order[a] < order[b]);
}

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		user.push_back(num);
		order[num] = i;
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end(), cmp);
	bfs(1);
	if (ans == user)
		cout << '1';
	else
		cout << '0';
}