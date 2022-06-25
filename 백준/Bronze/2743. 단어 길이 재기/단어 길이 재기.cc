#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; int n = 0;
    cin >> s;
    for(int i = 0; s[i]; i++)
        n++;
    cout << n;
}