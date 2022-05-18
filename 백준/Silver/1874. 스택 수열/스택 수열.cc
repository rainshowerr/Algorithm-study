#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> st;
	int n, m = 0;
	string ans;
	cin >> n;

	while (n--) {
		int x;
		cin >> x;
		if (x > m) {
			while (x > m) {
				st.push(++m);
				ans += '+';
			}
			st.pop();
			ans += '-';
		}
		else {
			bool judge = false;
			if (!st.empty()) {
				if (st.top() == x)
					judge = true;
				st.pop();
				ans += '-';
			}
			if (!judge) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}

	for (auto c : ans)
		cout << c << '\n';

	return 0;
}