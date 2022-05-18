#include <iostream>
using namespace std;
int d[100001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	if (d[n] == 1) {
		cout << d[n];
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j * j <= i; j++) {
			d[i] = min(d[i], d[i - j * j] + 1);
		}
	}
	cout << d[n];
	return 0;
}