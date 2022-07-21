#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v[101];
bool visited[101] = { false, };

void dfs(int i) {
	for(int j = 0; j < v[i].size(); j++) {
		if (!visited[v[i][j]]) {
			visited[v[i][j]] = true;
			dfs(v[i][j]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int k;
			cin >> k; 
			if (k)
				v[i].push_back(j);
		}
	}
	for(int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i);
		for(int j = 1; j <= n; j++) {
			if (visited[j]) cout << 1 << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}
}