#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(&a[0], &a[3]);
	cout << a[0] << ' ' << a[1] << ' ' << a[2];
}