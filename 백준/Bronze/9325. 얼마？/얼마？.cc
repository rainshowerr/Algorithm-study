#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int s, n;
        cin >> s >> n;
        for(int i = 0; i < n; i++) {
            int p, q;
            cin >> p >> q;
            s += p * q;
        }
        cout << s << '\n';
    }
}