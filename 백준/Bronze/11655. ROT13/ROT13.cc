#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    getline(cin, s);
    for(int i = 0; s[i]; i++) {
        if (('A' <= s[i] && s[i] <= 'M') || ('a' <= s[i] && s[i] <= 'm'))
            s[i] = s[i] + 13;
        else if (('N' <= s[i] && s[i] <= 'Z') || ('n' <= s[i] && s[i] <= 'z'))
            s[i] = s[i] - 13;
    }
    for(int i = 0; s[i]; i++)
        cout << s[i];
    return 0;
}