#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int m, s = 0;
	cin >> m;
	while (m--) {
		string command;
		int num;
		cin >> command;
		if (command == "add") {
			cin >> num;
			s = s | (1 << num);
		}
		else if (command == "remove") {
			cin >> num;
			s = s & ~(1 << num);
		}
		else if (command == "check") {
			cin >> num;
			if (s & (1 << num))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "toggle") {
			cin >> num;
			s = s ^ (1 << num);
		}
		else if (command == "all")
			s = (1 << 21) - 1;
		else if (command == "empty")
			s = 0;
	}
	return 0;
}