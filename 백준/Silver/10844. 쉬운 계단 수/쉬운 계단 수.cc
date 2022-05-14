#include <iostream>
#include <math.h>
using namespace std;
int mod = 1000000000;
int d[101][10] = { 0 };
int go(int n, int x);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	long long sum=0;
	for (int i = 1; i < 10; i++)
		sum += go(n, i);
	cout << sum % mod;
	return 0;
}
int go(int n, int x) {
	for (int i = 0; i < 10; i++)
		d[1][i] = 1;
	if (d[n][x])
		return d[n][x];
	if (x == 9)
		d[n][x] = go(n - 1, x - 1) % mod;
	else if (x == 0)
		d[n][x] = go(n - 1, x + 1) % mod;
	else
		d[n][x] = (go(n - 1, x + 1) + go(n - 1, x - 1)) % mod;
	return d[n][x];
}