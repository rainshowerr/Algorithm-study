#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> v[3001]; // 역 그래프 정보를 담은 배열
bool circle[3001] = { false }; // 순환선 여부를 알려주는 배열
int ans[3001] = { 0 }; // 순환선이 아닐 경우 거리를 담은 배열
bool visited[3001];

// DFS를 이용해 순환선일 경우 circle배열에 true를 채워줌
void dfs(int node, int start, int cnt)
{
	if (node == start && cnt >= 3)
	{
		circle[node] = true;
		return;
	}
	visited[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		if (visited[v[node][i]] == false || (v[node][i] == start && cnt >= 2))
			dfs(v[node][i], start, cnt + 1);
	}
}

// BFS를 이용해 지선일 경우 ans배열에 순환선까지의 거리를 채워줌
void bfs(queue<int> q)
{
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); i++)
		{
			int next = v[node][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
				ans[next] = ans[node] + 1;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	// 배열에 그래프 정보 담기
	for (int i = 1; i <= n; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	// DFS
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		int start = i;
		dfs(i, start, 0);
	}
	// BFS
	queue<int> q;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++)
	{
		// 순환선과 지점의 연결점을 큐에 push!
		if (circle[i] == true && v[i].size() > 2)
		{
			q.push(i);
			visited[i] = true;
		}
	}
	bfs(q);
	// 결과 출력
	for (int i = 1; i <= n; i++)
	{
		if (circle[i] == true)
			cout << "0 ";
		else
			cout << ans[i] << ' ';
	}
}