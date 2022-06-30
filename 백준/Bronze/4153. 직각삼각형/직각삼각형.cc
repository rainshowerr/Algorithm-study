#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int triangle[3];
    while(true) {
        int triangle[3];
        cin >> triangle[0] >> triangle[1] >> triangle[2];
        if (triangle[0] == 0 && triangle[1] == 0 && triangle[2] == 0)
            break;
        sort(&triangle[0], &triangle[3]);
        if (triangle[0] * triangle[0] + triangle[1] * triangle[1] == triangle[2] * triangle[2])
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';

    }
    return 0;
}