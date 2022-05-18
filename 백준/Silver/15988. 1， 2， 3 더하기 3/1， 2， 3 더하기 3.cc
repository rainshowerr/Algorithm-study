#include <iostream>
using namespace std;
long long go(int);
long long mod = 1000000009;
long long n[1000001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << go(n) << '\n';
	}
	return 0;
}
long long go(int x) {
	n[0] = 1; n[1] = 1; n[2] = 2;
	if (n[x])
		return n[x];
	n[x] = (go(x - 1)%mod + go(x - 2)%mod + go(x - 3)%mod)%mod;
	return n[x];
}