#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int map[100][100];
int dist[1001][1001] = { 0 };
bool visited[100][100];
queue <pair<int, int>> q;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, min_dist = 10001;

// 섬 넘버링
void dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	map[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && map[nx][ny])
			dfs(nx, ny, cnt);
	}
}

// 섬의 가장자리인지 체크
bool is_edge(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
		if (0 <= cx && cx < n && 0 <= cy && cy < n && map[x][y] == cnt && map[cx][cy] == 0)
			return true;
	}
	return false;
}

// 다리 최소 길이 구하기
void bfs(int x, int y, int cnt) {
	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
				// 바다 항해중
				if (map[nx][ny] == 0) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
				}
				// 다른 섬 도착
				else if (map[nx][ny] != cnt) {
					dist[nx][ny] = dist[x][y];
					min_dist = min(dist[nx][ny], min_dist);
					while (!q.empty()) // 큐 비워주기!!!!!!
						q.pop();
					return;
				}
			}
			
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	// 지도 입력받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	// 섬 넘버링
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j])
				dfs(i, j, cnt++);
		}
	}
	// 다리 최소 길이 구하기(모든 섬 -> 섬 체크)
	int mini = 10001;
	for (int i = 1; i < cnt; i++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {
				if (is_edge(a, b, i)) { // 섬의 가장자리에서 출발하는 BFS
					memset(visited, false, sizeof(visited));
					memset(dist, 0, sizeof(dist));
					bfs(a, b, i);
				}
			}
		}
	}
	// 결과 출력
	cout << min_dist;
}