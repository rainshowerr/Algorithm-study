#include <iostream>
#include<algorithm>
using namespace std;
int a[10001] = { 0 };
int d[10001][2] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[0][0] = 0;  d[1][0] = 0; d[1][1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], d[i - 1][1]);
		d[i][1] = max(d[i - 1][0], d[i - 2][0] + a[i - 1]) + a[i];
	}
	cout << max(d[n][1], d[n][0]);
	return 0;
}