#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m, num[8], tmp[8];
vector<int> ans;
set<vector<int>> s;

void go(int depth, int idx) {
	if (depth == m) {
		for (int i = 0; i < m; i++)
			ans.push_back(tmp[i]);
		s.insert(ans);
		ans.clear();
		return;
	}
	for (int i = 0; i < n; i++) {
		tmp[depth] = num[i];
		if (depth == 0 || tmp[depth] >= tmp[depth - 1])
			go(depth + 1, i);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	go(0, 0);
	for (auto i : s) {
		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}
}