#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int d[10001][5001]; // i번 위치까지 제단을 쌓았을 때 높이가 j가 되는 경우의 수
int h[10001];
int given[10001];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int hh;
        cin >> hh;
        given[i] = hh;
    }

    // 시작이 0층이 아닌 경우는 무조건 밴
    if (given[1] != -1 && given[1] != 0) {
        cout << 0;
        return 0;
    }

    // DP
    int max_height = n % 2 == 1 ? n / 2 : n / 2 - 1;
    d[1][0] = 1; // 초기값
    for(int i = 2; i <= n; i++) { // i번째까지 쌓았을 때
        for(int j = 0; j <= max_height; j++) { // 높이가 j인 경우
            if (given[i] != -1 && j != given[i]) // 높이가 주어진 경우 높이가 아닌 층 값은 전부 0으로 만듦
                d[i][j] = 0;
            else if (j == max_height) d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % 1000000007;
            else if (j != 0) d[i][j] = (((d[i - 1][j] + d[i - 1][j + 1]) % 1000000007) + d[i - 1][j - 1]) % 1000000007;
            else if (j == 0) d[i][j] = (d[i - 1][j] + d[i - 1][j + 1]) % 1000000007;
        }
    }
    int ans = d[n][0]; // 마지막은 0층으로 끝남
    cout << ans;
}