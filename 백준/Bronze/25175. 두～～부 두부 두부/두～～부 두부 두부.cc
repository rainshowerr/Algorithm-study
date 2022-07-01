#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int move = (k - 3) % n;
    if ((m + move) % n == 0) cout << n;
    else cout << (m + move + n) % n;
}