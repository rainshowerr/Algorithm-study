#include <iostream>
#include <queue>
using namespace std;
#define INF 2147483647

char map[1002][1002];
int firemap[1002][1002], timer[1002][1002]; // visited 체크 역할을 겸함

int main() {
	int t;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	cin >> t;
	while (t--) {
		ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		int w, h;
		cin >> w >> h;
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				firemap[i][j] = INF;
				timer[i][j] = -1;
			}
		}
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> map[i][j];
		// 불 퍼뜨리고 시간 저장하기
		queue<pair<int, int>> fire;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == '*') {
					fire.push({ i, j });
					firemap[i][j] = 0;
				}
			}
		}
		while (!fire.empty()) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (1 <= nx && nx <= h && 1 <= ny && ny <= w 
					&& firemap[nx][ny] == INF && map[nx][ny] != '#') {
					fire.push({ nx, ny });
					firemap[nx][ny] = firemap[x][y] + 1;
				}
			}
		}
		// 상근이 탈출시키기
		queue<pair<int, int>> q;
		bool flag = false;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == '@') {
					q.push({ i, j });
					timer[i][j] = 0;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		bool find_answer = false;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == 0 || x == h + 1 || y == 0 || y == w + 1) {
				cout << timer[x][y] << '\n';
				find_answer = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if ((nx == 0 || nx == h + 1 || ny == 0 || ny == w + 1)
					|| (1 <= nx && nx <= h && 1 <= ny && ny <= w
					&& timer[nx][ny] == -1 && map[nx][ny] == '.' && firemap[nx][ny] > timer[x][y] + 1)) {
					q.push({ nx, ny });
					timer[nx][ny] = timer[x][y] + 1;
				}
			}
		}
		if (!find_answer)
			cout << "IMPOSSIBLE" << '\n';
	}
}