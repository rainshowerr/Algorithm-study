#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    if (a < 2)
        cout << "Before";
    else if (a == 2) {
        if (b == 18) cout << "Special";
        else if (b < 18) cout << "Before";
        else cout << "After";
    }
    else
        cout << "After";
}