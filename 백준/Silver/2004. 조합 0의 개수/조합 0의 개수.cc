#include <iostream>
using namespace std;

long long func2(long long);
long long func5(long long);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n, m;
	cin >> n; cin >> m;
	long long num = min(func2(n) - (func2(n - m) + func2(m)), func5(n) - (func5(n - m) + func5(m)));
	cout << num;
	return 0;
}

long long func2(long long x) {
	long long count = 0;
	for(long long i = 2; i <= x; i *= 2)
		count += x / i;
	return count;
}

long long func5(long long x) {
	long long count = 0;
	for (long long i = 5; i <= x; i *= 5)
		count += x / i;
	return count;
}