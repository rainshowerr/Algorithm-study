#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, multi=1;
	cin >> n;
	for (; n > 0; n--)
		multi *= n;
	cout << multi;
	return 0;
}