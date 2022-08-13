#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c, d, t, m, s;
    cin >> a >> b >> c >> d;
    t = a + b + c + d;
    s = t % 60;
    m = (t - s) / 60;
    cout << m << '\n' << s;
}