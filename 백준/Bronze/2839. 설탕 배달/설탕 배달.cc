#include <iostream>
using namespace std;

int main() {
	int n, cnt = 0;;
	cin >> n;
	while (n % 5 != 0) {
		n -= 3;
		cnt++;
		if (n == 0) {
			cout << cnt;
			return 0;
		}
		else if (n < 0) {
			cout << -1;
			return 0;
		}
	}
	cnt += n / 5;
	cout << cnt;
}