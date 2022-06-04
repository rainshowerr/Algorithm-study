#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

char map[5][5], temp[5][5];
int ans = 0;
bool visited[5][5] = { false };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	memset(visited, false, sizeof(visited));
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && !visited[nx][ny] && temp[nx][ny] == 'P') {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	for (int s = 0; s < (1 << 25); s++) {
		int cnt = 0;
		for (int i = 0; i < 25; i++) {
			if (s & (1 << i))
				cnt++;
		}
		if (cnt == 7) {
			// 임시지도에 map 복사
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					temp[i][j] = map[i][j];
			// princess벡터에 공주 정보 담기, 임시지도의 공주 자리에 P 표시, 다솜파가 네명 이상인지 체크
			vector<pair<int, int>> princess;
			int dasom = 0;
			for (int i = 0; i < 25; i++) {
				if (s & (1 << i)) {
					princess.push_back({ i / 5, i % 5 });
					if (map[i / 5][i % 5] == 'S') dasom++;
					temp[i / 5][i % 5] = 'P';
				}
			}
			// 공주들의 자리가 인접해 있는지 체크
			bfs(princess[0].first, princess[0].second);
			bool check = true;
			for (int i = 0; i < 7; i++) {
				if (!visited[princess[i].first][princess[i].second]) {
					check = false;
					break;
				}
			}
			if (check && dasom >= 4)
				ans++;
		}
	}
	cout << ans;
	return 0;
}