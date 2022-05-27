#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> node[1001]; // 노드 간의 관계를 담은 벡터
int c[1001];

void dijkstra(int cost, int city, int dest) {
	pq.push({ cost, city });
	c[city] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int city = pq.top().second;
		pq.pop();
		if (city == dest) {
			cout << c[city];
			return;
		}
		for (int i = 0; i < node[city].size(); i++) {
			int n_cost = node[city][i].first;
			int n_city = node[city][i].second;
			if (c[n_city] > cost + n_cost) {
				c[n_city] = cost + n_cost;
				pq.push({ cost + n_cost, n_city });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, start, dest;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({ cost, to });
	}
	for (int i = 1; i <= n; i++)
		c[i] = 2147483647;
	cin >> start >> dest;
	dijkstra(0, start, dest);
}