#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
bool visited[100001] = { false };
int n, k;

void dijkstra(int n, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 가중치가 작은 순서대로 정렬
	pq.push({ 0, n }); //시작점 push! 가중치 0, 시작점 n
	visited[n] = true;
	while (!pq.empty()) {
		int sec = pq.top().first;
		int cur = pq.top().second;
		if (cur == k) {
			cout << sec;
			return;
		}
		pq.pop();
		if (cur * 2 < 100001 && !visited[cur * 2]) {
			pq.push({ sec, 2 * cur });
			visited[2 * cur] = true;
		}
		if (cur + 1 < 100001 && !visited[cur + 1]) {
			pq.push({ sec + 1, cur + 1 });
			visited[cur + 1] = true;
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			pq.push({ sec + 1, cur - 1 });
			visited[cur - 1] = true;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	dijkstra(n, k);
	return 0;
}