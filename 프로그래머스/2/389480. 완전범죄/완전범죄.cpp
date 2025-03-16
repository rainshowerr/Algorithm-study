#include <string>
#include <vector>

using namespace std;

int minn = 1e9, nn, mm, rows;
bool memo[121][121][41];

void dfs(int a, int b, int k, vector<vector<int>>& info) {
    if (a >= nn || b >= mm) return;
    if (memo[a][b][k]) return;
    if (k == rows) {
        minn = min(minn, a);
        return;
    }
    dfs(a + info[k][0], b, k + 1, info);
    dfs(a, b + info[k][1], k + 1, info);
    memo[a + info[k][0]][b][k + 1] = true;
    memo[a][b + info[k][1]][k + 1] = true;
}

int solution(vector<vector<int>> info, int n, int m) {
    nn = n; mm = m; rows = info.size();
    dfs(0, 0, 0, info);
    if (minn == 1e9) return -1;
    else return minn;
}