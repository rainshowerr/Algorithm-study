#include <iostream>

using namespace std;

long long memo[1001][1001];

long long combi(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (memo[n][k] != 0) return memo[n][k];
    return memo[n][k] = (combi(n - 1, k) + combi(n - 1, k - 1)); // 그냥 돌면 연산이 너무 많아지므로 메모
}

int main() {
    int t, n, m;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << combi(m, n) << '\n';
    }

}