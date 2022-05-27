#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> edge[20001]; // 노드 간의 관계를 담은 벡터
int d[20001];
int V, E, st;

void dijkstra() {
	pq.push({ 0, st });
	d[st] = 0;
	while (!pq.empty()) {
		int dist = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		for (int i = 0; i < edge[curr].size(); i++) {
			int n_dist = edge[curr][i].first;
			int n_curr = edge[curr][i].second;
			if (d[n_curr] > dist + n_dist) {
				d[n_curr] = dist + n_dist;
				pq.push({ dist + n_dist, n_curr });
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> V >> E >> st;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({ w, v });
	}
	for (int i = 1; i <= V; i++)
		d[i] = 2147483647;
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (d[i] == 2147483647)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';
	}
}