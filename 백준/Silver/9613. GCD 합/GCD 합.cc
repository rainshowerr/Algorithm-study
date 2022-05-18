#include <iostream>
using namespace std;
int gcd(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	while (n--) {
		int m, arr[100] = { 0 };
		long long sum = 0;
		cin >> m;
		for(int i=0;i<m;i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < m - 1; i++) {
			for (int j = i + 1; j < m; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum<<'\n';
	}
	return 0;
}
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}