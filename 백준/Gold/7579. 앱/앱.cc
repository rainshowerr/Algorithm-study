#include <iostream>
#include <algorithm>

using namespace std;

int memory[101];
int cost[101];
int d[10001][101]; // j까지 봤을 때 i비용을 써서 확보할 수 있는 최대 메모리

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, mm, cc;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> mm;
        memory[i] = mm;
    }
    for(int i = 1; i <= n; i++) {
        cin >> cc;
        cost[i] = cc;
    }

    // DP
    for(int i = 10000; i >= cost[1]; i--) // 초기값 설정 
        d[i][1] = memory[1];

    for(int i = 0; i <= 10000; i++) {
        for(int j = 2; j <= n; j++) {
            if (i >= cost[j])
                d[i][j] = max(d[i-cost[j]][j-1] + memory[j], d[i][j-1]);
            else
                d[i][j] = d[i][j-1];
        }
    }

    // 최소 비용 찾기
    int min = 1e9;
    for(int j = 1; j <= n; j++) {
        for(int i = 0; i <= 10000; i++) {
            if (d[i][j] >= m && min > i)
                min = i;
        }
    }
    cout << min;
}