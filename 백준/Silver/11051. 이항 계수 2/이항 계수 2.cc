// 이항계수: (x+1)^n을 계산했을 때 x^k의 계수
// nCk = n! / (n-k)!k!

#include <iostream>

using namespace std;

int memo[1001][1001];

int pascal(int n, int k) {
    if (k == 0 || n == k) return 1; // k가 양 끝이면 1
    if (memo[n][k] != 0) return memo[n][k];
    return memo[n][k] = (pascal(n - 1, k) + pascal(n - 1, k - 1)) % 10007; // 그냥 돌면 연산이 너무 많아지므로 메모
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << pascal(n, k);
}