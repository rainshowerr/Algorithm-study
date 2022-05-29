#include <iostream>
using namespace std;
#define INF 987654321;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, t[201][201], map[201][201];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				t[i][j] = 0;
				map[i][j] = 0;
			}
			else
				t[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		t[from][to] = time;
		t[to][from] = time;
		map[from][to] = to;
		map[to][from] = from;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (t[i][j] > t[i][k] + t[k][j]) {
					t[i][j] = t[i][k] + t[k][j];
					map[i][j] = map[i][k]; // i에서 j로 가는 최단경로가 추가되어도 값이 바뀌지 않음!
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0)
				cout << '-' << ' ';
			else
				cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}