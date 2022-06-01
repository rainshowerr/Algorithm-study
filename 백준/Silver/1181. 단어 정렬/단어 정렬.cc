#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_len(string a, string b) {
	return a.length() < b.length();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; string str[20000]; set<string> s; vector<string> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		s.insert(str[i]);
	}
	for (auto i : s)
		ans.push_back(i);
	sort(ans.begin(), ans.end());
	stable_sort(ans.begin(), ans.end(), cmp_len);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}