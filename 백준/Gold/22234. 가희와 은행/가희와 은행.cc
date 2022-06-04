#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<pair<int, int>> q;
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
	int N, T, W, M;
	cin >> N >> T >> W;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		q.push({ a, b });
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c, {a, b} });
	}
	int time = 0;
	while (!q.empty()) {
		int front_p = q.front().first;
		int front_t = q.front().second;
		int temp_t = T;
		while ( front_t && temp_t) {
			cout << front_p << '\n';
			front_t--;
			temp_t--;
			time++;
			if (time == W)
				return 0;
		}
		q.pop();
		// 새로운 고객이 들어오는 경우
		while (!pq.empty() && time >= pq.top().first) {
			q.push(pq.top().second);
			pq.pop();
		}
		if (front_t != 0) // 고객이 다시 줄서는 경우
			q.push({ front_p, front_t });
	}
}