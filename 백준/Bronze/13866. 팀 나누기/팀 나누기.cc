#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int s[4];
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    sort(&s[0], &s[4]);
    cout << abs(s[0] + s[3] - (s[1] + s[2]));
}