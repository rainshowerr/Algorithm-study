#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, a[1000001], ans[1000001];
	stack<int> st;
	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	// 모든 수열의 오큰수를 찾을 때까지 반복
	for (int i = 1; i <= n; i++) {
		ans[i] = -1;
		// 나중에 들어오는 수가 이전 수(들)의 오큰수인 경우
		while (!st.empty() && a[st.top()] < a[i]) {
			ans[st.top()] = a[i];
			st.pop();
		}
		// 오큰수를 찾아야 하는 수
		st.push(i);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}