#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // 한 시간당 피로도 A만큼 쌓이고 B만큼 일처리, 쉬면 C 감소, 최대 M
    int A, B, C, M, time = 0, tired = 0, ans = 0;
    cin >> A >> B >> C >> M;
    while(time < 24) {
        if (tired + A <= M) {
            tired += A;
            ans += B;
        }
        else
            tired = max(0, tired - C);
        time++;
    }
    cout << ans;
}