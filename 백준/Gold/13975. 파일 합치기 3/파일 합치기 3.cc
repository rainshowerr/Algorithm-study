#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, n, num[1000000];
	priority_queue<long long, vector<long long>, greater<long long>> q;
	cin >> t;
	while (t--) {
		long long sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			q.push(num[i]);
		}
		while (q.size() != 1) {
			long long x = q.top();
			q.pop();
			long long y = q.top();
			q.pop();
			sum += x + y;
			q.push(x + y);
		}
		cout << sum << '\n';
		while (!q.empty())
			q.pop();
	}
}