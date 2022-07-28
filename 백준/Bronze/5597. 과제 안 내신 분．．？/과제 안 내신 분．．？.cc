#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n = 28, arr[31] = { 0, };
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        arr[num] = 1;
    }
    for(int i = 1; i <= 30; i++) {
        if (!arr[i])
            cout << i << '\n';
    }
}