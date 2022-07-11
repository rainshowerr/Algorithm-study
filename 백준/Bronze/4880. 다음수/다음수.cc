#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(true) {
        int num[3];
        cin >> num[0] >> num[1] >> num[2];
        if (num[0] == 0 && num[1] == 0 && num[2] == 0) break;
        if (num[1] - num[0] == num[2] - num[1] && num[1] - num[0] != 0) {
            cout << "AP ";
            cout << num[2] + (num[2] - num[1]) << '\n';
        }
        else {
            cout << "GP ";
            cout << num[2] * (num[2] / num[1]) << '\n';
        }
    }
}