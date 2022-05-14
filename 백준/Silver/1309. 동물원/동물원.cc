#include <iostream>
using namespace std;
long long d[100001][3] = { 0 };
int mod = 9901;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	d[1][0] = 1; d[1][1] = 1; d[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i - 1][0] % mod + d[i - 1][1] % mod + d[i - 1][2] % mod) % mod;
		d[i][1] = (d[i - 1][2] % mod + d[i - 1][0] % mod) % mod;
		d[i][2] = (d[i - 1][1] % mod + d[i - 1][0] % mod) % mod;
	}
	cout << (d[n][0] + d[n][1] + d[n][2]) % mod;
	return 0;
}