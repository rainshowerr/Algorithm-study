#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int l, p, v, sum, t = 1;
	while (true) {
		cin >> l >> p >> v;
		sum = 0;
		if (l == 0 && p == 0 && v == 0)
			break;
		sum += v / p * l;
		if (v % p < l)
			sum += v % p;
		else
			sum += l;
		cout << "Case " << t << ": " << sum << '\n';
		t++;
	}
}