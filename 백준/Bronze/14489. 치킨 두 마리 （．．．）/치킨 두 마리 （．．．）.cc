#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 2 * c)
        cout << (a + b) - (2 * c);
    else
        cout << a + b;
}