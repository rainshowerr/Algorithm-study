#include <iostream>
#include <queue>
using namespace std;
#define INF 2147483647

char map[1002][1002];
int firemap[1002][1002], timer[1002][1002]; // visited 체크 역할을 겸함

int main() {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int R, C;
	cin >> R >> C;
	for (int i = 0; i <= R + 1; i++) {
		for (int j = 0; j <= C + 1; j++) {
			firemap[i][j] = INF;
			timer[i][j] = -1;
		}
	}
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];
	// 불 퍼뜨리고 시간 저장하기
	queue<pair<int, int>> fire;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'F') {
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
			if (1 <= nx && nx <= R && 1 <= ny && ny <= C
				&& firemap[nx][ny] == INF && map[nx][ny] != '#') {
				fire.push({ nx, ny });
				firemap[nx][ny] = firemap[x][y] + 1;
			}
		}
	}
	// 지훈이 탈출시키기
	queue<pair<int, int>> q;
	bool flag = false;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'J') {
				q.push({ i, j });
				timer[i][j] = 0;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == 0 || x == R + 1 || y == 0 || y == C + 1) {
			cout << timer[x][y] << '\n';
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if ((nx == 0 || nx == R + 1 || ny == 0 || ny == C + 1)
				|| (1 <= nx && nx <= R && 1 <= ny && ny <= C
					&& timer[nx][ny] == -1 && map[nx][ny] == '.' && firemap[nx][ny] > timer[x][y] + 1)) {
				q.push({ nx, ny });
				timer[nx][ny] = timer[x][y] + 1;
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
	return 0;
}