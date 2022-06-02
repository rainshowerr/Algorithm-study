#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;
vector<pair<long long, int>> node[1001]; // 노드 간의 관계를 담은 벡터
long long c[1001]; // 비용 배열
int path[1001]; // 이전에 거쳐온 도시 번호를 저장하는 배열

void dijkstra(int cost, int city, int dest) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ cost, city });
	c[city] = 0;
	path[city] = 0;
	while (!pq.empty()) {
		long long cost = pq.top().first;
		int city = pq.top().second;
		pq.pop();
		if (city == dest) {
			cout << c[city] << '\n';
			return;
		}
		if (cost > c[city]) continue;
		for (int i = 0; i < node[city].size(); i++) {
			long long n_cost = node[city][i].first;
			int n_city = node[city][i].second;
			if (c[n_city] > cost + n_cost) {
				pq.push({ cost + n_cost, n_city });
				c[n_city] = cost + n_cost;
				path[n_city] = city;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, start, dest;
	vector<int> p;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({ cost, to });
	}
	for (int i = 1; i <= n; i++)
		c[i] = INF;
	cin >> start >> dest;
	dijkstra(0, start, dest);
	// 경로 구하기
	p.push_back(dest);
	for (int i = dest; i != start; i = path[i]) // path[도시] = 이전 도시 / 경로를 p 벡터에 넣음
		p.push_back(path[i]);
	cout << p.size() << '\n';
	for (int i = p.size() - 1; i >= 0; i--) // 거꾸로 출력
		cout << p[i] << ' ';
}