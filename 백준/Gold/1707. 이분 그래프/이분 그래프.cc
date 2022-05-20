#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int k, v, e;
vector<int> ilist[20001];
int group[20001]; // 방문 안했으면 0, 방문했고 그룹1이면 1, 방문했고 그룹2면 2를 표시하기 위한 배열
bool ans;

void bfs(int node)
{
	queue<int> q;
	group[node] = 1;
	q.push(node);
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i < ilist[temp].size(); i++)
		{
			int next = ilist[temp][i];
			if (group[next] == 0) // 방문하지 않았던 노드일 경우
			{
				group[next] = 3 - group[temp]; // 전 값이 1그룹이면 2그룹으로, 2그룹이면 1그룹으로 초기화
				q.push(next);
			}
		}
	}
}

// 인접한 두 노드가 같은 색이면 바로 false 반환!
bool is_okay()
{
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < ilist[i].size(); j++)
			if (group[i] == group[ilist[i][j]])
				return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> k;
	while (k--)
	{
		cin >> v >> e;
		// 테스트케이스가 들어올 때마다 초기화
		ans = true;
		memset(group, 0, sizeof(group));
		for (int i = 1; i <= v; i++)
			ilist[i].clear();
		// 그래프 만들어주기
		for (int i = 0; i < e; i++)
		{
			int from, to;
			cin >> from >> to;
			ilist[from].push_back(to);
			ilist[to].push_back(from);
		}
		// 연결 요소가 두 개 이상일 가능성 고려(끊어진 그래프일 수도 있음)
		for (int i = 1; i <= v; i++)
		{
			if (group[i] == 0)
				bfs(i);
		}
		// 검사 후 결과 출력
		if (is_okay())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}