#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, a[500001], ans[500001];
	stack<int> s;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		ans[i] = 0;
		// 이전 숫자보다 큰 숫자가 들어오는 경우 pop (이전 탑은 필요 없어짐)
		while (!s.empty() && a[s.top()] <= a[i]) {
			s.pop();
		}
		// 이전 숫자보다 작은 숫자가 들어오는 경우 답 결정
		if (!s.empty() && a[s.top()] > a[i]) {
			ans[i] = s.top();
		}
		s.push(i);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}