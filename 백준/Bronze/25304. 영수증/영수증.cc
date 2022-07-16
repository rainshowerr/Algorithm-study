#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, n, sum = 0;
	cin >> x >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}
	if (sum == x) cout << "Yes";
	else cout << "No";
}