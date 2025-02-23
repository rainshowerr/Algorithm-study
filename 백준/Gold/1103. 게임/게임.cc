#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[51][51], dp[51][51];
bool visit[51][51], flag = true;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// DP를 사용하지 않을 경우 O(4^NM)

int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y]; 
    visit[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i] * arr[x][y];
        int ny = y + dy[i] * arr[x][y];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (arr[nx][ny] == 0) continue;
        if (visit[nx][ny]) {
            flag = false;
            return 0;
        };
        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    visit[x][y] = false;
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    char c;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c;
            if (c == 'H') arr[i][j] = 0;
            else arr[i][j] = c - '0';
        }
    }
    int ans = dfs(1, 1);
    if (flag) cout << ans + 1;
    else cout << -1;
}