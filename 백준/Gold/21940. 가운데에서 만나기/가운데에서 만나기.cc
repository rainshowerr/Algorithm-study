#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, k, ans_time;
	int t[201][201], fr[201];
	cin >> n >> m;
	// 플로이드
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			t[i][j] = i == j ? 0 : INF;
	}
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		t[from][to] = time;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
		}
	}

	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> fr[i];

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int mini = 2147483647;
	for (int i = 1; i <= n; i++) {
		int maxi = 0;
		// 최대 왕복시간 구하기
		for (int j = 1; j <= k; j++) {
			if (maxi < t[fr[j]][i] + t[i][fr[j]])
				maxi = t[fr[j]][i] + t[i][fr[j]];
		}
		pq.push({ maxi, i }); // 우선순위 큐에 최대 왕복시간이 작은 순서로 자동 정렬
	}
	// 정답 출력
	cout << pq.top().second << ' ';
	ans_time = pq.top().first;
	pq.pop();
	while (!pq.empty() && pq.top().first == ans_time) {
		cout << pq.top().second << ' ';
		pq.pop();
	}
	return 0;
}