#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int r, c;
int map[51][51], water[51][51];
bool visit[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<pair<int, int>, int>> waterq, dochiq;

// 미리 물 엎질러놓기
void water_bfs() {
    while (waterq.empty() == false) {
        pair<pair<int, int>, int> curr = waterq.front();
        int x = waterq.front().first.first;
        int y = waterq.front().first.second;
        waterq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
            if (visit[nx][ny]) continue;
            if (map[nx][ny] == 'X' || map[nx][ny] == 'D') continue;
            waterq.push({{nx, ny}, curr.second + 1});
            water[nx][ny] = curr.second + 1;
            visit[nx][ny] = true;
        }
    }
}

// 도치 고
void dochi() {
    while (dochiq.empty() == false) {
        pair<pair<int, int>, int> curr = dochiq.front();
        int x = dochiq.front().first.first;
        int y = dochiq.front().first.second;
        dochiq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
            if (visit[nx][ny]) continue;
            if (map[nx][ny] == 'X') continue;
            if (water[nx][ny] != -1 && water[nx][ny] <= curr.second + 1) continue;
            else if (map[nx][ny] == 'D') {
                cout << curr.second + 1;
                exit(0);
            }
            dochiq.push({{nx, ny}, curr.second + 1});
            visit[nx][ny] = true;
        }
    }
    cout << "KAKTUS";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> r >> c;
    pair<int, int> start;

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            water[i][j] = -1;
        }
    }

    for(int i = 1; i <= r; i++) {
        cin >> s;
        for(int j = 1; j <= c; j++) {
            map[i][j] = s[j - 1];
            if (map[i][j] == 'S') dochiq.push({{i, j}, 0});
            if (map[i][j] == '*') {
                waterq.push({{i, j}, 0});
                water[i][j] = 0;
                visit[i][j] = true;
            }
        }
    }

    water_bfs();
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            visit[i][j] = false;
        }
    }
    dochi();
}