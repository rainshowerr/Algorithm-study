#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long memo[21];
bool visit[21];

long long factorial(int n) {
	if (n <= 1) return 1;
	if (memo[n]) return memo[n];

	return memo[n] = n * factorial(n - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, t;
	long long k;
	vector<int> v;
	cin >> n >> t;
	if (t == 1) { // k번째 수열 구하기
		cin >> k;
		while(v.size() < n) {
			long long order = factorial(n - (v.size() + 1));
			for(int i = 1; i <= n; i++) {
				if (!visit[i]) {
					if (order < k) {
						k -= order;
					} else {
						v.push_back(i);
						cout << i << ' ';
						visit[i] = true;
						break;
					}
				}
			}
		}
	} else { // k 구하기
		int num;
		k = 1;
		for(int i = 1; i <= n; i++) {
			cin >> num;
			for(int j = 1; j <= n; j++) {
				if (!visit[j]) {
					if (j == num) {
						visit[j] = true;
						break;
					}
					else k += factorial(n - i);
				}
			}
		}
		cout << k;
	}
}