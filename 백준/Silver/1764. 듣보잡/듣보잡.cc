#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	unordered_set<string> a, b;
	int n, m;
	vector<string> ans;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		a.insert(name);
	}
	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		b.insert(name);
	}
	for (auto x : a) {
		if (b.find(x) != b.end())
			ans.push_back(x);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << '\n';
}