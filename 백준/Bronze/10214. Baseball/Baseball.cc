#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int korea = 0, yonsei = 0;
        for(int i = 0; i < 9; i++) {
            int y, k;
            cin >> y >> k;
            yonsei += y;
            korea += k;
        }
        if (korea > yonsei) cout << "Korea\n";
        else if (korea < yonsei) cout << "Yonsei\n";
        else cout << "Draw\n";
    }
}