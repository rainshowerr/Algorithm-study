#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	unordered_set<string> s;
	vector<string> ans;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string person;
		string status;
		cin >> person >> status;
		if (status == "enter")
			s.insert(person);
		else if (status == "leave")
			s.erase(person);
	}
	for (auto x : s)
		ans.push_back(x);
	sort(ans.begin(), ans.end(), greater<>());
	for (auto x : ans)
		cout << x << '\n';
}