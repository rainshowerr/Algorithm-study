#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, a[80001];
	long long ans = 0;
	stack<int> s;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		// 현재 빌딩이 크거나 같은 경우 pop
		while (!s.empty() && a[s.top()] <= a[i])
			s.pop();
		ans += s.size();
		s.push(i);
	}
	cout << ans;
}