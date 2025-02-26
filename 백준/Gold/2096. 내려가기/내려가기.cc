#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int maxd[2][3] = {0,}, mind[2][3] = {0,}, n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        int curr = i % 2 == 0 ? 0 : 1;
        int prev = i % 2 == 0 ? 1 : 0;
        maxd[curr][0] = max(maxd[prev][0], maxd[prev][1]) + a;
        maxd[curr][1] = max(max(maxd[prev][0], maxd[prev][1]), maxd[prev][2]) + b;
        maxd[curr][2] = max(maxd[prev][1], maxd[prev][2]) + c;
        mind[curr][0] = min(mind[prev][0], mind[prev][1]) + a;
        mind[curr][1] = min(min(mind[prev][0], mind[prev][1]), mind[prev][2]) + b;
        mind[curr][2] = min(mind[prev][1], mind[prev][2]) + c;
    }
    int maxx = 0;
    int minn = 1e9;
    if (n % 2 == 0) {
        maxx = max(max(maxd[1][0], maxd[1][1]), maxd[1][2]);
        minn = min(min(mind[1][0], mind[1][1]), mind[1][2]);
    }
    else {
        maxx = max(max(maxd[0][0], maxd[0][1]), maxd[0][2]);
        minn = min(min(mind[0][0], mind[0][1]), mind[0][2]);
    }
    cout << maxx << ' ' << minn;
}