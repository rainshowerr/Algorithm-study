#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, ans = 0;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        ans += b % a;
    }
    cout << ans;
}