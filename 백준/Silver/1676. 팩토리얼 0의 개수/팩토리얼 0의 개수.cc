#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, count = 0;
	cin >> n;
	while (1) {
		int k = n;
		n--;
		if (k == 0)
			break;
		while (1) {
			if (k % 5 == 0) {
				k /= 5;
				count++;
			}
			else
				break;
		}
	}
	cout << count;
	return 0;
}