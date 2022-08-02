#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int arr[7], mini = 100, sum = 0;
    bool exist = false;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >> arr[6];
    for(int i = 0; i < 7; i++) {
        if (arr[i] % 2 == 1) {
            sum += arr[i];
            mini = min(mini, arr[i]);
            exist = true;
        }
    }
    if (exist)
        cout << sum << '\n' << mini;
    else
        cout << -1;
}