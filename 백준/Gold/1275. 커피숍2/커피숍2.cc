#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> num(100001);
vector<long long> idx(300000);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q, leaf;
    cin >> n >> q;

    for(leaf = 1; leaf < n; leaf *= 2);

    for(int i = 0; i < n; i++) {
        long long nn;
        cin >> nn;
        num[i] = nn;
        idx[i + leaf] = nn;
    }

    for(int node = leaf - 1; node >= 1; node--) {
        idx[node] = idx[node * 2] + idx[node * 2 + 1];
    }

    for(int i = 0; i < q; i++) {
        int x, y, a;
        long long b;
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);

        // 구간합
        long long sum = 0;
        x += leaf - 1;
        y += leaf - 1;
        while (x <= y) {
            if (x % 2 == 1) sum += idx[x++];
            if (y % 2 == 0) sum += idx[y--];
            x /= 2;
            y /= 2;
        }
        cout << sum << '\n';

        // 변경
        a += leaf - 1;
        idx[a] = b;
        a /= 2;
        while (a >= 1) {
            idx[a] = idx[a * 2] + idx[a * 2 + 1];
            a /= 2;
        }
    }
}