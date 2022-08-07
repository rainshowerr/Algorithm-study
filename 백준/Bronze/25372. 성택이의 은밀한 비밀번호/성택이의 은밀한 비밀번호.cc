#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if (6 <= s.length() && s.length() <= 9)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}