#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, a[100000], m, b[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		int min = 0, max = n - 1;
		bool flag = false;
		while (min <= max) {
			int mid = (min + max) / 2;
			if (a[mid] == b[i]) {
				flag = true;
				break;
			}
			else if (a[mid] > b[i])
				max = mid - 1;
			else
				min = mid + 1;
		}
		if (flag)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}