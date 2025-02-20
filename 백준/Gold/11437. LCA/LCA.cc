#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adjlist[50001];
int parent[17][50001];
int depth[50001];

void make_tree(int a, int d, int p) { // 노드의 parent와 depth를 지정
	parent[0][a] = p;
	depth[a] = d;
	for(int x: adjlist[a]) {
		if (x == p) continue;
		make_tree(x, d + 1, a);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	for (int i = 16; i >= 0; i--)
	{
		if (depth[a] - depth[b] >= (1 << i))
			a = parent[i][a];
	}
	if (a == b) return a; // 조상을 찾았다면 바로 리턴
	for(int i = 16; i >= 0; i--) { // 아니라면 찾아감
		if (parent[i][a] == parent[i][b]) continue;
		else {
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b;
	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	// tree 생성, parent 매칭
	make_tree(1, 0, 0);
	for(int i = 1; i <= 16; i++) {
		for(int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	cin >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
}