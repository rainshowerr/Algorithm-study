#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y, length, sq, ans;
		cin >> x >> y;
		length = y - x;
		sq = sqrt(length);
		ans = sq * sq == length ? 2 * sq - 1 : 2 * sq; // 규칙 : 제곱수면 제곱근 - 1, 아니면 2 * 제곱근
		if (length > sq * sq + sq) ans += 1; // 제곱수와 다음 제곱수 사이 중간값 이상일 경우 + 1
		cout << ans << '\n';
	}
}