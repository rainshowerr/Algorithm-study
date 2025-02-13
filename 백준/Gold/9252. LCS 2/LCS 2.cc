#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int d[1001][1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string a, b, path;
    cin >> a >> b;
    
    a = ' ' + a; // 인덱스 밀어주기
    b = ' ' + b;

    // DP
    for(int i = 0; i < a.length(); i++) // 초기값 설정
        d[i][0] = 0;
    for(int j = 0; j < b.length(); j++)
        d[0][j] = 0;

    for(int i = 1; i < a.length(); i++) {
        for(int j = 1; j < b.length(); j++) {
            if (a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    cout << d[a.length() - 1][b.length() - 1] << '\n';

    // 경로 찾기
    int i = a.length() - 1, j = b.length() - 1;
    while (i > 0 && j > 0) {
        if (d[i][j] == d[i - 1][j]) {
            i--;
        }
        else if (d[i][j] == d[i][j - 1]) {
            j--;
        }
        else {
            path += a[i];
            i--; j--;
        }
    }

    for(int i = path.size() - 1; i >= 0; i--)
        cout << path[i];
}