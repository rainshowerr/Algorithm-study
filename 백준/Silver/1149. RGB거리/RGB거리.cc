#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][4] = { 0 };
int a[1001][4] = { 0 };
int go(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1]; cin >> a[i][2]; cin >> a[i][3];
	}
	cout << min({ go(n,1), go(n,2), go(n,3) });
	return 0;
}
int go(int n,int k) {
	d[1][1] = a[1][1]; d[1][2] = a[1][2]; d[1][3] = a[1][3];
	if (d[n][k])
		return d[n][k];
	if (k == 1)
		d[n][1] = min(go(n - 1, 2), go(n - 1, 3)) + a[n][1];
	else if (k == 2)
		d[n][2] = min(go(n - 1, 1), go(n - 1, 3)) + a[n][2];
	else if (k == 3)
		d[n][3] = min(go(n - 1, 1), go(n - 1, 2)) + a[n][3];
	return d[n][k];
}