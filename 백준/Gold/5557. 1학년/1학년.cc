#include <iostream>
#include <vector>

using namespace std;

bool is_known[101][101];
long long memo[101][101];
vector<int> num;

long long dp(int idx, int n) { // idx번째에 n이 나오는 경우의 수
    if (is_known[idx][n]) return memo[idx][n];
    if (idx < 0 || n < 0 || n > 20) return 0;

    memo[idx][n] = dp(idx - 1, n + num[idx]) + dp(idx - 1, n - num[idx]);
    is_known[idx][n] = true;
    return memo[idx][n];
}

int main() {
    int n;
    cin >> n;
    num.push_back(0); // 인덱스 조정 
    for(int i = 0; i < n; i++) {
        int nn;
        cin >> nn;
        num.push_back(nn);
    }

    memo[1][num[1]] = 1;
    is_known[1][num[1]] = true;
    cout << dp(n - 1, num[n]) << '\n';
}