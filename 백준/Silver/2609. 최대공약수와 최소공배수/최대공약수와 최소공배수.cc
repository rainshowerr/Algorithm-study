#include <iostream>
using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);
int main() {
	int a, b;
	cin >> a; cin >> b;
	cout << gcd(a, b)<<"\n";
	cout << a * b / gcd(a, b);
	return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}