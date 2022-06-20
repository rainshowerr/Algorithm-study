#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	stack<int> st;
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "pop") {
			if (st.empty()) cout << "-1\n";
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (s == "size") cout << st.size() << '\n';
		else if (s == "empty") {
			if (st.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (s == "top") {
			if (st.empty()) cout << "-1\n";
			else cout << st.top() << '\n';
		}
	}
	return 0;
}