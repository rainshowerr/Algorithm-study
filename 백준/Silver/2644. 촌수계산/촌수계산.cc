#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> fam[101];
queue<pair<int, int>> q;
bool visit[101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b, m;
	cin >> n >> a >> b >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		fam[x].push_back(y);
		fam[y].push_back(x);
	}
	q.push({a, 0});
	while(!q.empty()) {
		pair<int, int> curr = q.front();
		visit[curr.first] = true;
		q.pop();
		if (curr.first == b) {
			cout << curr.second;
			return 0;
		}
		for(int next : fam[curr.first]) {
			if (!visit[next]) {
				q.push({next, curr.second + 1});
			}
		}
	}
	cout << -1;
}