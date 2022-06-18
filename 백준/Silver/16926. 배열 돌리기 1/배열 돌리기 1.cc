#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, r, map[301][301], temp[301][301];
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> map[i][j];
    while(r--) {
        for(int depth = 0; depth < min(n, m) / 2; depth++) { // 점점 안쪽으로 들어오며 탐색
            int start_n = 1 + depth, start_m = 1 + depth; // 탐색을 시작할 좌표
            int end_n = n - depth, end_m = m - depth; // 탐색을 끝낼 좌표
            for(int i = end_m - 1; i >= start_m; i--) temp[start_n][i] = map[start_n][i + 1]; // 상
            for(int i = start_m + 1; i <= end_m; i++) temp[end_n][i] = map[end_n][i - 1]; // 하
            for(int i = start_n + 1; i <= end_n; i++) temp[i][start_m] = map[i - 1][start_m]; // 좌
            for(int i = end_n - 1; i >= start_n; i--) temp[i][end_m] = map[i + 1][end_m]; // 우
        }
        // map에 배열 다시 복사
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                map[i][j] = temp[i][j];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            cout << map[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}