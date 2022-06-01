#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> node[100001];
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	bool visited[100001] = { false };
	int parent[100001];
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < node[curr].size(); i++) {
			int next = node[curr][i];
			if (!visited[next]) {
				visited[next] = true;
				parent[next] = curr;
				q.push(next);
			}
		}
	}
	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}