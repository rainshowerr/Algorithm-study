#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, n, m;
    cin >> k >> n >> m;
    if (k * n > m)
        cout << (k * n) - m;
    else
        cout << 0;
}