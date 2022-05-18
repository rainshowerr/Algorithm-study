#include <iostream>
using namespace std;
int a[1001], d[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}
	int max;
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			max = d[i];
		else {
			if (d[i] > max)
				max = d[i];
		}
	}
	cout << max;
	return 0;
}