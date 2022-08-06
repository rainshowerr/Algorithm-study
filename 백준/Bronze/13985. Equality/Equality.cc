#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c;
    char op, eq;
    cin >> a >> op >> b >> eq >> c;
    if (a + b == c) cout << "YES";
    else cout << "NO";
}