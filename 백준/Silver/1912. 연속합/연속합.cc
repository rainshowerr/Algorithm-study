#include <iostream>
using namespace std;
int go(int);
int a[100001];
int d[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int max;
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			max = go(i);
		else {
			if (go(i) > max)
				max = go(i);
		}
	}
	cout << max;
	return 0;
}
int go(int n) {
	if (n == 1)
		d[n] = a[n];
	if (d[n])
		return d[n];
	if (go(n - 1) > 0)
		d[n] = go(n - 1) + a[n];
	else
		d[n] = a[n];
	return d[n];
}