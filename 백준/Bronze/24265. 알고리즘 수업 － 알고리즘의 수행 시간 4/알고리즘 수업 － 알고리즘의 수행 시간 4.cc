#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    long long cnt = 0;
    cin >> n;
    for(int i = n - 1; i >= 1; i--)
        cnt += i;
    cout << cnt << '\n' << 2;
}