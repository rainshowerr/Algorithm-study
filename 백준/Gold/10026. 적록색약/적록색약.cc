#include <iostream>
#include <cstring>
using namespace std;

char map[100][100];
bool visited[100][100] = { false };
int n, ans1 = 0, ans2 = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 구역 개수를 구하기 위한 dfs
void dfs(int x, int y, char c) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && map[nx][ny] == c)
			dfs(nx, ny, c);
	}
}

// 빨강색을 초록색으로 바꿔주는 함수
void RtoG(int x, int y) {
	map[x][y] = 'G';
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && map[x][y] == 'R')
			RtoG(nx, ny);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	// 적록색약 아닌 사람의 답 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, map[i][j]);
				ans1++;
			}
		}
	}
	// 빨강색을 초록색으로 물들여주기
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 'R')
				RtoG(i, j);
		}
	}
	// 적록색약인 사람의 답 구하기
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, map[i][j]);
				ans2++;
			}
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';
}