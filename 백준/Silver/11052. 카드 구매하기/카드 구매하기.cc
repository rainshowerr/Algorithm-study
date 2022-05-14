#include <iostream>
using namespace std;
int go(int);
int p[1001] = { 0 }, d[1001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i < n + 1; i++)
		cin >> p[i];
	cout << go(n);
	return 0;
}
int go(int n) {
	if (d[n])
		return d[n];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (d[i] < d[i - j] + p[j]) {
				d[i] = d[i - j] + p[j];
			}
		}
	}
	return d[n];
}