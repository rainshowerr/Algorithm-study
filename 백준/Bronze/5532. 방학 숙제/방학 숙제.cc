#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l, a, b, c, d;
    cin >> l >> a >> b >> c >> d;
    if (a % c == 0)
        a = a / c;
    else
        a = (a / c) + 1;
    if (b % d == 0)
        b = b / d;
    else
        b = (b / d) + 1;
    cout << l - max(a, b);
}