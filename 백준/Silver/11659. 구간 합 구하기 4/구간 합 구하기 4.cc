#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, num[100001], i, j;
	long long sum[100001];
	cin >> n >> m;
	for(int idx = 1; idx <= n; idx++) {
		cin >> num[idx];
		sum[idx] = sum[idx - 1] + num[idx];
	}
	for(int idx = 0; idx < m; idx++) {
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << '\n';
	}
}