#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l;
	cin >> l;
	if (l % 5 == 0)
		cout << l / 5;
	else
		cout << (l / 5) + 1;
}