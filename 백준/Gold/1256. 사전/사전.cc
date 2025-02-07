#include <iostream>
#include <string>
#define INF 1e9

using namespace std;

long long memo[201][201];

long long combi(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (memo[n][k] != 0) return memo[n][k];

    // 가능한 콤비가 너무 커서 터지는 거 방지
    if (combi(n - 1, k) + combi(n - 1, k - 1) > INF) return memo[n][k] = INF;
    else return memo[n][k] = (combi(n - 1, k) + combi(n - 1, k - 1)); // 그냥 돌면 연산이 너무 많아지므로 메모
}

// 전체 문자열의 개수 n+mCn
// 첫글자 a인 경우: n+m-1Cm
// 첫글자 z인 경우: n+m-1Cn

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k, length;
    cin >> n >> m >> k;

    if (combi(n + m, n) < k) {
        cout << -1;
        return 0;
    }

    string s;
    length = n + m;
    while(s.length() < length) {
        // a인 경우
        if (combi(n + m - 1, m) >= k) {
            n--;
            s += 'a';
            if (n == 0) { // 0Cm 방지
                for(int i = 0; i < m; i++)
                    s += 'z';
                break;
            }
        }
        // z인 경우
        else {
            k -= combi(n + m - 1, m);
            m--;
            s += 'z';
        }
    }
    cout << s;
}

// 3C2 >= 2 -> 'a', n-- -> n=1, m=2
// 2C2 < 2 -> 'z', m--, k -= 2C2 -> n=1, m=1, k = 1
// 1C1 >= 1 -> 'a', n-- -> n=0, m=1
// 0C1 >= n --.......