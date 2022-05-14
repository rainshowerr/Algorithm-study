#include <iostream>
using namespace std;
int a[100001], DL[100001] = { 0 }, DR[100001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	DL[1] = a[1];
	for (int i = 2; i <= n; i++) {
		DL[i] = a[i];
		if (DL[i-1] > 0)
			DL[i] += DL[i - 1];
	}
	DR[n] = a[n];
	for (int i = n-1; i >= 1; i--) {
		DR[i] = a[i];
		if (DR[i + 1] > 0)
			DR[i] += DR[i + 1];
	}
	int max = DL[1];
	for (int i = 2; i <= n; i++) {
		if (max < DL[i])
			max = DL[i];
	}
	for (int i = 2; i <= n-1; i++) {
		if (max < DL[i - 1] + DR[i + 1])
			max = DL[i - 1] + DR[i + 1];
	}
	cout << max;
	return 0;
}