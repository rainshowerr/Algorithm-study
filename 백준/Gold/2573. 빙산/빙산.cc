#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m, map[301][301], map2[301][301];

void dfs(int x, int y) {
	map2[x][y] = 0;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (map2[nx][ny]) dfs(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for(int t = 1;; t++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					map2[i][j] = 0;
					continue;
				}
				int cnt = 0;
				for(int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (map[nx][ny] == 0) cnt++;
				}
				map2[i][j] = map[i][j] - cnt >= 0 ? map[i][j] - cnt : 0;
			}	
		}
		// 원본으로 저장
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				map[i][j] = map2[i][j];
			}
		}

		// 딱 한 덩이만 dfs
		bool flag = false;
		bool is_all_zero = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (map2[i][j]) {
					is_all_zero = false;
					dfs(i, j);
					flag = true;
				}
				if (flag) break;
			}
			if (flag) break;
		}

		// 이미 모두 녹은 경우
		if (is_all_zero) {
			cout << 0;
			return 0;
		}

		// dfs 후에도 남은 덩어리가 있는 경우
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (map2[i][j]) {
					cout << t;
					return 0;
				}
			}
		}
	}
}