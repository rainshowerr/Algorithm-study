#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t,error;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		int error = 0;
		string str;
		getline(cin, str);
		stack<char> s;
		for (char c : str)
		{
			if (c == '(')
				s.push(c);
			else if (c ==')') {
				if (s.empty()) {
					error = 1;
					break;
				}
				s.pop();
			}
		}
		if (s.empty())
		{
			if (error == 1)
				cout << "NO\n";
			else if (error==0)
				cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}