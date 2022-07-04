#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long a, b, c, n;
    cin >> a >> b >> c;
    if (c - b > 0) cout << a / (c - b) + 1;
    else cout << -1;
}