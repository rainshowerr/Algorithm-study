#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000000000;
using namespace std;

int n, m, visible[100000];
long long t[100000];
vector<pair<long long, int>> node[100000];

long long dijkstra(int time, int curr) {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ time, curr });
	t[curr] = 0;
	while (!pq.empty()) {
		long long time = pq.top().first;
		int curr = pq.top().second;
		if (curr == n - 1)
			return t[curr];
		pq.pop();
		if (time > t[curr]) // 안해주면 시간초과 발생!!
			continue;
		for (int i = 0; i < node[curr].size(); i++) {
			long long n_time = node[curr][i].first;
			int n_curr = node[curr][i].second;
			if (t[n_curr] > (long long)time + (long long)n_time) {
				t[n_curr] = (long long)time + (long long)n_time;
				pq.push({ t[n_curr], n_curr });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> visible[i];
		t[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		// 적의 시야에 보이면 애초에 간선을 연결하지 않음
		if ((!visible[from] && !visible[to]) || (from == n - 1 || to == n - 1)) {
			node[from].push_back({ time, to });
			node[to].push_back({ time, from });
		}
	}
	cout << dijkstra(0, 0);
}