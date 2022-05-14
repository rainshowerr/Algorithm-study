#include <iostream>
using namespace std;
long long mod = 1000000000LL;
long long d[201][201] = { 0 };
long long go(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; int k; cin >> n; cin >> k;
	cout << go(n, k);
	return 0;
}
long long go(int n, int k) {
	for (int i = 0; i <= n; i++)
		d[i][1] = 1LL;
	if (d[n][k])
		return d[n][k];
	for (int i = 0; i <= n; i++) {
		d[n][k] += go(n - i, k - 1)%mod;
	}
	d[n][k] = d[n][k] % mod;
	return d[n][k];
}