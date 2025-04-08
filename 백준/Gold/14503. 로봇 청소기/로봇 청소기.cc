#include <iostream>

using namespace std;

int n, m, r, c;
int d; // 0 북쪽, 1 동쪽, 2 남쪽, 3 서쪽
int map[51][51], clean = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[51][51];

int rotate(int dir) {
    return ((dir + 4) - 1) % 4;
}

bool check_near(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (map[nx][ny] == 0 && !visited[nx][ny]) return true;
    }
    return false;
}

void simulate(int x, int y, int dir) {
    while(1) {
        if (!visited[x][y]) clean++;
        visited[x][y] = true;
        if (check_near(x, y) == false) { // 근처가 깨끗한 경우
            int bx = x, by = y;
            int back = rotate(rotate(dir));
            if (back == 0) bx--; // 북
            if (back == 1) by++; // 동
            if (back == 2) bx++; // 남
            if (back == 3) by--; // 서
            if (map[bx][by] == 1) { // 뒤가 벽이면 끝냄
                cout << clean;
                exit(0);
            }
            x = bx, y = by;
        }
        else { // 근처를 청소해야 하는 경우
            int nx, ny, ndir = dir;
            for(int i = 0; i < 4; i++) {
                nx = x, ny = y;
                ndir = rotate(ndir);
                if (ndir == 0) nx--; // 북
                if (ndir == 1) ny++; // 동
                if (ndir == 2) nx++; // 남
                if (ndir == 3) ny--; // 서
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (map[nx][ny] == 0 && !visited[nx][ny])
                    break;
            }
            x = nx, y = ny, dir = ndir;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> r >> c >> d;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            cin >> map[x][y];
        }
    }
    simulate(r, c, d);
}