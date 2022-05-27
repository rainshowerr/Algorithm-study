#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long long n, dist[100000], p_oil[100000], min_oil, sum = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> dist[i];
	for (int i = 0; i < n; i++)
		cin >> p_oil[i];
	min_oil = p_oil[0];
	for (int i = 0; i < n - 1; i++) {
		min_oil = min(min_oil, p_oil[i]);
		sum += dist[i] * min_oil;
	}
	cout << sum;
}