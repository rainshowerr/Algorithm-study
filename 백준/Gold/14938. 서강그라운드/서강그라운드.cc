#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, r, item[101], map[101][101], ans = 0;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> item[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			map[i][j] = i == j ? 0 : INF;
	}
	for (int i = 0; i < r; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		map[from][to] = dist;
		map[to][from] = dist;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] <= m)
				temp += item[j];
		}
		ans = max(ans, temp);
	}
	cout << ans;
}