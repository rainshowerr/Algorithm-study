#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    cin >> n;
    while(n--)
    {
        int k;
        cin >> k;
        if (k) ans++;
        else ans--;
    }
    if (ans > 0) cout << "Junhee is cute!";
    else cout << "Junhee is not cute!";
}