#include <iostream>
#include <queue>
#include <utility>

using namespace std;

queue<pair<int, int>> q;
bool visit[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int f, s, g, u, d; // 총 높이, 강호, 스타트링크, up, down
	cin >> f >> s >> g >> u >> d;
	q.push({s, 0});
	visit[s] = true;
	while(!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		if (curr.first == g) {
			cout << curr.second;
			return 0;
		}
		if (curr.first + u <= f && !visit[curr.first + u]) {
			q.push({curr.first + u, curr.second + 1});
			visit[curr.first + u] = true;
		}
		if (curr.first - d > 0 && !visit[curr.first - d]) {
			q.push({curr.first - d, curr.second + 1});
			visit[curr.first - d] = true;
		}
	}
	cout << "use the stairs";
}