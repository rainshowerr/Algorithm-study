#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n * 5; i++) {
		if (0 <= i && i < n * 4) {
			for (int j = 0; j < n; j++)
				cout << '@';
		}
		else {
			for (int j = 0; j < n * 5; j++)
				cout << '@';
		}
		cout << '\n';
	}
}