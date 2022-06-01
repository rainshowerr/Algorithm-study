#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, arr[1000], ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			ans += arr[j];
	}
	cout << ans;
	return 0;
}