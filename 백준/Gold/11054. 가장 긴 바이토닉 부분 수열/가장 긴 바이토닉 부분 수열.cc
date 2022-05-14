#include <iostream>
using namespace std;
int a[1001], p[1001], m[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		p[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && p[i] < p[j] + 1) {
				p[i] = p[j] + 1;
			}
		}
	}
	for (int i=n; i >= 1; i--) {
		m[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j] && m[i] < m[j] + 1) {
				m[i] = m[j] + 1;
			}
		}
	}
	int max;
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			max = p[1] + m[1] - 1;
		else
			if (max < p[i] + m[i] - 1) {
				max = p[i] + m[i] - 1;
			}
	}
	cout << max;
	return 0;
}