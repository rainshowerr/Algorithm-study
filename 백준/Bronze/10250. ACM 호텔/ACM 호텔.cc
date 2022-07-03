#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, h, w, n;
    cin >> t;
    while(t--) {
        cin >> h >> w >> n;
        if (n % h == 0) {
            cout << h;
            if (1 <= n / h && n / h <= 9) cout << 0 << n / h << '\n';
            else cout << n / h << '\n';
        }
        else {
            cout << n % h;
            if (1 <= n / h + 1 && n / h + 1 <= 9) cout << 0 << n / h + 1 << '\n';
            else cout << n / h + 1 << '\n';
        }
    }
}