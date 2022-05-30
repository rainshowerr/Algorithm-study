#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 987654321;

int map[251][251];
vector<int> node[251];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;
		if (!b) {
			map[v][u] = 1;
			map[u][v] = 0;
		}
		if (b) {
			map[v][u] = 0;
			map[u][v] = 0;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	cin >> t;
	while (t--) {
		int from, go;
		cin >> from >> go;
		cout << map[from][go] << '\n';
	}
	return 0;
}