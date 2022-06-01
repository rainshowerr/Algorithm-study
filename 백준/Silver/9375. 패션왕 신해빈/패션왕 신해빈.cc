#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		unordered_map<string, int> m;
		int n, ans;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			m[b]++;
		}
		ans = 1;
		for (auto x : m)
			ans *= x.second + 1; // ans *= 그룹별 옷 개수 + 1 (안입는경우 포함)
		ans--; // 아예 안입는경우 제외
		cout << ans << '\n';
	}
}