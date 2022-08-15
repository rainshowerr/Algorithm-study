#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, t[20], Y = 0, M = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    for(int i = 0; i < n; i++) {
        Y += 10 * ((t[i] / 30) + 1);
        M += 15 * ((t[i] / 60) + 1);
    }
    if (Y == M)
            cout << "Y M " << Y;
        else if (Y < M)
            cout << "Y " << Y;
        else
            cout << "M " << M;
}