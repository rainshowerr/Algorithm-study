#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, num[8];
	set<vector<int>> ans;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	// 비트마스크. 모든 부분집합 탐색
	for (int s = 1; s < (1 << n); s++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s & (1 << i))
				cnt++;
		}
		if (cnt == m) {
			vector<int> v;
			for (int i = 0; i < n; i++) {
				if (s & (1 << i))
					v.push_back(num[i]);
			}
			ans.insert(v);
		}
	}
	for (auto x : ans) {
		for (int y = 0; y < m; y++)
			cout << x[y] << ' ';
		cout << '\n';
	}
	return 0;
}