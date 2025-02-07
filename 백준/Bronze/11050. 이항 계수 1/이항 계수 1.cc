// 이항계수: (x+1)^n을 계산했을 때 x^k의 계수
// nCk = n! / (n-k)!k!

#include <iostream>

using namespace std;

int factorial(int n) {
    int ans = 1;
    for(int i = 1; i <= n; i++)
        ans *= i;
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << factorial(n) / (factorial(n-k) * factorial(k));
}