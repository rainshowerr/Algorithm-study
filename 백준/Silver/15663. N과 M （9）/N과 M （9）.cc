#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n, m, num[8], tmp[8];
bool visited[8] = { false };
vector<int> ans;
set<vector<int>> s;

void go(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			ans.push_back(tmp[i]);
		s.insert(ans);
		ans.clear();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			tmp[idx] = num[i];
			go(idx + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	go(0);
	for (auto i : s) {
		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}
}