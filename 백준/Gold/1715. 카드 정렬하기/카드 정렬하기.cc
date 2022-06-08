#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, num[100000], sum = 0, temp;
	priority_queue<int, vector<int>, greater<int>> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		q.push(num[i]);
	}
	while (q.size() != 1) {
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		sum += x + y;
		q.push(x + y);
	}
	cout << sum;
}