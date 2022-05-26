#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	// 윗줄
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++)
			cout << ' ';
		for (int j = 0; j < 2 * i + 1; j++)
			cout << '*';
		cout << '\n';
	}
	// 중간줄
	for (int i = 0; i < 2 * n - 1; i++)
		cout << '*';
	cout << '\n';
	// 아랫줄
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < n - i; j++)
			cout << ' ';
		for (int j = 0; j < 2 * i - 1; j++)
			cout << '*';
		cout << '\n';
	}
}