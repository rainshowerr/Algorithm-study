#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; int alpha[26] = { 0, };
    cin >> s;
    for(int i = 0; i < s.length(); i++)
        alpha[s[i] - 'a']++;
    for(int i = 0; i < 26; i++)
        cout << alpha[i] << ' ';
}