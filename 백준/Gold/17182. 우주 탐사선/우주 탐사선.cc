#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321;

int n, ans = 2147483647, t[10][10];
bool visited[10] = { false };

void go(int idx, int planet, int sum) {
	if (idx == n) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		visited[planet] = true;
		if (!visited[i] && planet != i)
			go(idx + 1, i, sum + t[planet][i]);
		visited[planet] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> t[i][j];
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
		}
	}
	go(1, k, 0);
	cout << ans;
}