#include <iostream>

using namespace std;

int n, m, ans = 0;
int map[51][51];
bool cloud[51][51] = {false, };
bool cloud_temp[51][51];
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};

// 테스트
void test() {
    cout << '\n';
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            cout << map[x][y] << ' ';
        }
        cout << '\n';
    }
}

// 구름 이동
void move(int d, int s) {
    int r = 0, c = 0;
    // d, s에 따라 row, col 방향으로 얼마만큼 옮길지 결정
    if (d == 1) { // ←
        c -= s;
    } else if (d == 2) { // ↖ 
        r -= s; c -= s;
    } else if (d == 3) { // ↑
        r -= s;
    } else if (d == 4) { // ↗
        r -= s; c += s;
    } else if (d == 5) { // →
        c += s;
    } else if (d == 6) { // ↘
        r += s; c += s;
    } else if (d == 7) { // ↓
        r += s;
    } else if (d == 8) { // ↙
        r += s; c -= s;
    }

    // 배열에 구름 표시
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cloud_temp[(i + r + n * 30) % n][(j + c + n * 30) % n] = cloud[i][j]; // 음수 방지를 위해 30을 곱해줌
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cloud[i][j] = cloud_temp[i][j];
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
        // 초기 구름 설정
    cloud[n-2][0] = true;
    cloud[n-2][1] = true;
    cloud[n-1][0] = true;
    cloud[n-1][1] = true;
    // 구름 이동
    for(int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        move(d, s);
        // 비내리기
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (cloud[i][j]) map[i][j]++;
            }
        }
        // 구름 사라짐
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cloud[i][j] = false;
            }
        }

        // 물복사버그 시전
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if (cloud_temp[x][y]) {
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (map[nx][ny]) map[x][y]++;
                    }
                }
            }
        }
        // 물 양 2 이상인 칸 물조절 (구름칸 제외)
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if (cloud_temp[x][y]) continue;
                if (map[x][y] >= 2) {
                    cloud[x][y] = true;
                    map[x][y] -= 2;
                }
            }
        }    
        //test();
    }
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            ans += map[x][y];
        }
    }
    cout << ans;
}