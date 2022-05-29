#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e, map[401][401];
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++)
			map[i][j] = i == j ? 0 : INF;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		}
	}
	int ans = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i != j && map[i][j] != INF && map[j][i] != INF)
				ans = min(ans, map[i][j] + map[j][i]);
		}
	}
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;
	return 0;
}