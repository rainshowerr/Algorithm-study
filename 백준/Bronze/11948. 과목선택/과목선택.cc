#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a[4], b[2];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	cin >> b[0] >> b[1];
	sort(&a[0], &a[4]);
	sort(&b[0], &b[2]);
	cout << a[1] + a[2] + a[3] + b[1];
}