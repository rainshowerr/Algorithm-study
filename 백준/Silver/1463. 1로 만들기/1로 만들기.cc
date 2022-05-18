#include <iostream>
using namespace std;
int memo[1000001] = { 0 };
int route(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x;
	cin >> x;
	cout<<route(x);
	return 0;
}
int route(int n) {
	if (n == 1) return 0;
	if (memo[n] > 0) return memo[n];
	memo[n] = route(n-1) + 1;
	if (n % 2 == 0) {
		int temp = route(n/2) + 1;
		if (memo[n] > temp) memo[n] = temp;
	}
	if (n%3 == 0) {
		int temp = route(n/3) + 1;
		if (memo[n] > temp) memo[n] = temp;
	}
	return memo[n];
	}