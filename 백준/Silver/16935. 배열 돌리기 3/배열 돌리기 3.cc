#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, r, map[101][101];
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> map[i][j];
    for(int i = 0; i < r; i++){
        int k;
        cin >> k;
        int temp[101][101];
        // 상하반전
        if (k == 1) {
            for(int x = 1; x <= n; x++)
                for(int y = 1; y <= m; y++)
                    temp[x][y] = map[n - x + 1][y];
        }
        // 좌우반전
        else if (k == 2) {
            for(int x = 1; x <= n; x++)
                for(int y = 1; y <= m; y++)
                    temp[x][y] = map[x][m - y + 1];
        }
        // 오른쪽으로 90도 회전
        else if (k == 3) {
            int t; t = n; n = m; m = t;
            for(int x = 1; x <= n; x++)
                for(int y = 1; y <= m; y++)
                    temp[x][y] = map[m - y + 1][x];
        }
        // 왼쪽으로 90도 회전
        else if (k == 4) {
            int t; t = n; n = m; m = t;
            for(int x = 1; x <= n; x++)
                for(int y = 1; y <= m; y++)
                    temp[x][y] = map[y][n - x + 1];
        }
        // 1->2, 2->3, 3->4, 4->1
        else if (k == 5) {
            for(int x = 1; x <= n; x++) {
                for(int y = 1; y <= m; y++) {
                    // 4->1
                    if (1 <= x && x <= n / 2 && 1 <= y && y <= m / 2)
                        temp[x][y] = map[x + n / 2][y];
                    // 1->2
                    else if (1 <= x && x <= n / 2 && m / 2 < y && y <= m)
                        temp[x][y] = map[x][y - m / 2];
                    // 2->3
                    else if (n / 2 < x && x <= n && m / 2 < y && y <= m)
                        temp[x][y] = map[x - n / 2][y];
                    // 3->4
                    else if (n / 2 < x && x <= n && 1 <= y && y <= m / 2)
                        temp[x][y] = map[x][y + m / 2];
                }
            }
        }
        // 1->4, 4->3, 3->2, 2->1
        else if (k == 6) {
            for(int x = 1; x <= n; x++) {
                for(int y = 1; y <= m; y++) {
                    // 1->4
                   if (n / 2 < x && x <= n && 1 <= y && y <= m / 2)
                        temp[x][y] = map[x - n / 2][y];
                    // 4->3
                    else if (n / 2 < x && x <= n && m / 2 < y && y <= m)
                        temp[x][y] = map[x][y - m / 2];
                    // 3->2
                    else if (1 <= x && x <= n / 2 && m / 2 < y && y <= m)
                        temp[x][y] = map[x + n / 2][y];
                    // 2->1
                    else if (1 <= x && x <= n / 2 && 1 <= y && y <= m / 2)
                        temp[x][y] = map[x][y + m / 2];
                }
            }
        }
        for(int x = 1; x <= n; x++)
                for(int y = 1; y <= m; y++)
                    map[x][y] = temp[x][y];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}