#include <iostream>

using namespace std;

int n, h, stone, idx[1060000], cnt = 0;
int leaf;

void edit(int x, int y) {
    x += leaf - 1;
    y += leaf - 1;
    while(x <= y) {
        if (x % 2 == 1) idx[x++]++;
        if (y % 2 == 0) idx[y--]++;
        x /= 2;
        y /= 2;
    }
}

int query(int floor) {
    int ans = 0;
    floor += leaf - 1;
    while(floor >= 1) {
        ans += idx[floor];
        floor /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> h;
    for(leaf = 1; leaf < h; leaf *= 2);

    for(int i = 1; i <= n; i++) {
        cin >> stone;
        if (i % 2 == 1) {
            edit(1, stone); // 석순
        }
        else {
            edit(h - stone + 1, h); // 종유석
        }
    }

    int minn = 1e9;
    int cnt = 0;
    for(int i = 1; i <= h; i++) {
        if (query(i) < minn) {
            minn = query(i);
            cnt = 1;
        } else if (query(i) == minn) {
            cnt++;
        }
    }
    cout << minn << ' ' << cnt;
}