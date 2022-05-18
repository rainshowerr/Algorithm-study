#include <iostream>
using namespace std;
int go(int);
int n[12] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << go(n)<<'\n';
	}
	return 0;
}
int go(int x) {
	n[0] = 1; n[1] = 1; n[2] = 2;
	if (n[x])
		return n[x];
	n[x] = go(x - 1) + go(x - 2) + go(x - 3);
	return n[x];
}