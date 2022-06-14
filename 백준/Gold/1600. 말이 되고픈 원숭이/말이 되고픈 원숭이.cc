#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, w, h, map[200][200], visited[200][200][31];
    int dx1[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int dy1[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dx2[4] = { -1, 1, 0, 0 };
    int dy2[4] = { 0, 0, -1, 1 };
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> map[i][j];
    fill(&visited[0][0][0], &visited[h - 1][w - 1][k + 1], -1);
    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = 0;
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        if (x == h - 1 && y == w - 1) {
            cout << visited[x][y][z] << '\n';
            return 0;
        }
        // 원숭이가 말을 따라하는 경우
        for (int i = 0; i < 8; i++) {
            int nx = x + dx1[i];
            int ny = y + dy1[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || map[nx][ny] == 1) continue;
            if (z + 1 <= k && visited[nx][ny][z + 1] == -1) {
                q.push({ nx, ny, z + 1 });
                visited[nx][ny][z + 1] = visited[x][y][z] + 1;
            }
        }
        // 원숭이가 상하좌우로 움직이는 경우
        for (int i = 0; i < 4; i++) {
            int nx = x + dx2[i];
            int ny = y + dy2[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || map[nx][ny] == 1) continue;
            if (visited[nx][ny][z] == -1) {
                q.push({ nx, ny, z });
                visited[nx][ny][z] = visited[x][y][z] + 1;
            }
        }
    }
    cout << "-1" << '\n';
    return 0;
}