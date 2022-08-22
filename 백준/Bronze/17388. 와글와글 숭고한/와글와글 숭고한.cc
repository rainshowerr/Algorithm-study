#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b + c >= 100)
		cout << "OK";
	else {
		if (a < b && a < c)
			cout << "Soongsil";
		else if (b < a && b < c)
			cout << "Korea";
		else
			cout << "Hanyang";
	}
}