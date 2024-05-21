#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> edge[30001];
int d[30001];

void dijkstra(int start) {
	d[start] = 0;
	pq.push({0, start});
	while(!pq.empty()) {
		int time = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if(d[curr] < time) continue;
		for (int i = 0; i < edge[curr].size(); i++) {
			int n_time = edge[curr][i].first;
			int n_curr = edge[curr][i].second;
			if (d[n_curr] > time + n_time)
				d[n_curr] = time + n_time;
				pq.push({time + n_time, n_curr});
		}
	}
}

int main(){
	int n, m, c;
	cin >> n >> m >> c;
	for(int i = 1; i <= n; i++)
		d[i] = 2147483647;
	for(int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge[x].push_back({z, y});
	}
	dijkstra(c);
	int cnt = -1, alltime = 0;
	for(int i = 1; i <= n; i++){
		if (d[i] != 2147483647)
			cnt++;
			alltime = max(alltime, d[i]);
	}
	cout << cnt << ' ' << alltime;
}