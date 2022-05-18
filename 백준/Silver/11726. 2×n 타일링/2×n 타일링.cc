#include <iostream>
using namespace std;
int go(int n);
int d[1001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	cout << go(n);
	return 0;
}
int go(int n) {
	d[1] = 1; d[2] = 2;
	if (d[n])
		return d[n];
	d[n] = (go(n-1) + go(n - 2))%10007;
	return d[n];
}