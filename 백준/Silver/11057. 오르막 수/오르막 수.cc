#include <iostream>
using namespace std;
int mod = 10007;
long long go(int n, int k);
long long d[1001][10] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	long long num = 0;
	for (int i = 0; i < 10; i++) {
		num += go(n, i);
	}
	cout << num % mod;
	return 0;
}
long long go(int n, int k) {
	for (int i = 0; i < 10;i++)
		d[1][i] = 1;
	if (d[n][k])
		return d[n][k];
	for (int i = 0; i <= k; i++) {
		d[n][k] += go(n - 1, i) % mod;
	}
	return d[n][k] % mod;
}