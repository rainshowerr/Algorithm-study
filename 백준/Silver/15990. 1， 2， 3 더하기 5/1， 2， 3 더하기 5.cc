#include <iostream>
using namespace std;
const long long mod = 1000000009LL;
long long d[100001][4] = { 0 };
long long go(long long, long long);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t; cin >> t;
	while (t--) {
		long long n; cin >> n;
		cout << (go(n, 1) + go(n, 2) + go(n, 3))%mod << '\n';
	}
	return 0;
}
long long go(long long n, long long i) {
	d[1][1] = 1; d[1][2] = 0; d[1][3] = 0;
	d[2][1] = 0; d[2][2] = 1; d[2][3] = 0;
	d[3][1] = 1; d[3][2] = 1; d[3][3] = 1;
	if (d[n][i])
		return d[n][i];
	if(n>3)
		d[n][i] = go(n - i, 1) % mod + go(n - i, 2) % mod + go(n - i, 3) % mod - go(n - i, i) % mod; //점화식
	return d[n][i];
}