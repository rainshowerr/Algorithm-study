#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v, num;
set<vector<int>> s;

void dfs(int idx, int cnt) {
	if (cnt == m) {
		s.insert(v);
		return;
	}
	for (int i = 0; i < num.size(); i++) {
		v.push_back(num[i]);
		dfs(i, cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	// 수 중복 없이 입력받기
	for (int i = 0; i < n; i++) {
		bool flag = true;
		int temp;
		cin >> temp;
		for (int j = 0; j < num.size(); j++) {
			if (temp == num[j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			num.push_back(temp);
	}
	sort(num.begin(), num.end());
	dfs(0, 0);
	for (auto x : s) {
		for (int y = 0; y < x.size(); y++)
			cout << x[y] << ' ';
		cout << '\n';
	}
}