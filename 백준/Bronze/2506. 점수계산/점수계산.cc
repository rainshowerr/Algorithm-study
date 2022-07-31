#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, sum = 0, current = 1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 0)
            current = 1;
        else if (k == 1) {
            sum += current;
            current++;
        }
    }
    cout << sum;
}
