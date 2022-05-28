#include <iostream>
#include <queue>
using namespace std;

int n, m, c[50001];
vector<pair<int, int>> node[50001];

int dijkstra(int cost, int curr) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>> pq;
	pq.push({ cost, curr });
	c[curr] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (curr == n)
			return c[curr];
		for (int i = 0; i < node[curr].size(); i++) {
			int n_cost = node[curr][i].first;
			int n_curr = node[curr][i].second;
			if (c[n_curr] > cost + n_cost) {
				c[n_curr] = cost + n_cost;
				pq.push({ cost + n_cost, n_curr });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({ cost, to });
		node[to].push_back({ cost, from });
	}
	for (int i = 1; i <= n; i++)
		c[i] = 2147483647;
	cout << dijkstra(0, 1);
	return 0;
}