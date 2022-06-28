#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) {
        if (b > c) cout << b;
        else if (a > c) cout << c;
        else cout << a;
    }
    else {
        if (a > c) cout << a;
        else if (b > c) cout << c;
        else cout << b;
    }
    return 0;
}