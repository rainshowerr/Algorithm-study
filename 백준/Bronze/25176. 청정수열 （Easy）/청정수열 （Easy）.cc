#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> v;
    int n, ans = 1;
    cin >> n;
    // 청정수열의 최소 점수 sum 구하기
    for(int i = 1; i <= n; i++) {
        ans *= i;
    }
    cout << ans;
}