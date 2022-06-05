#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k, ans = 0, coin[10];
	cin >> n >> k;
	for (int i = n - 1; i >= 0; i--) {
		cin >> coin[i];
	}
	for (int i = 0; i < n; i++) {
		while (k - coin[i] >= 0) {
			k -= coin[i];
			ans++;
		}
	}
	cout << ans;
}