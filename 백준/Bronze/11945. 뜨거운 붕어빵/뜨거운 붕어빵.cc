#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s[10];
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = s[i].length() - 1; j >= 0; j--)
            cout << s[i][j];
        cout << '\n';
    }
}