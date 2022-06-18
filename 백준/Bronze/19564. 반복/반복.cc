#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int memo = -1, ans = 1; string s; cin >> s;
    for(int i = 0; s[i]; i++) {
        if (s[i] - 'a' <= memo) ans++;
        memo = s[i] - 'a';
    }
    cout << ans;
}