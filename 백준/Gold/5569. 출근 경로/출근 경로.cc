#include <iostream>

using namespace std;

bool is_known[101][101][4];
int memo[101][101][4];

int path(int w, int h, int k) { // w, h까지 화살표 방법으로 도착
    if (is_known[w][h][k]) return memo[w][h][k];

    if (w < 1 || h < 1) {
        return 0;
    }

    if (k == 0) { // →→
        memo[w][h][k] = path(w - 1, h, 0) + path(w - 1, h, 1) % 100000;
    } else if (k == 1) { // ↑→
        memo[w][h][k] = path(w - 1, h, 3) % 100000;
    } else if (k == 2) { // →↑
        memo[w][h][k] = path(w, h - 1, 0) % 100000;
    } else if (k == 3) { // ↑
        memo[w][h][k] = path(w, h - 1, 2) + path(w, h - 1, 3) % 100000;
    }

    is_known[w][h][k] = true;
    return memo[w][h][k];
}


int main() {
    int w, h;
    cin >> w >> h;

    // 초기값 설정
    memo[1][2][0] = 0; // (1, 2)
    memo[1][2][1] = 0;
    memo[1][2][2] = 0;
    memo[1][2][3] = 1;
    memo[2][1][0] = 1; // (2, 1)
    memo[2][1][1] = 0;
    memo[2][1][2] = 0;
    memo[2][1][3] = 0;
    for(int i = 0; i < 4; i++) {
        is_known[1][2][i] = true;
        is_known[2][1][i] = true;
    }

    cout << (path(w, h, 0) + path(w, h, 1) + path(w, h, 2) + path(w, h, 3)) % 100000;
}