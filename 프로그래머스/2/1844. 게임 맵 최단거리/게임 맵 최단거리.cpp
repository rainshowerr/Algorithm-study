#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > maps)
{
    queue<tuple<int, int, int>> q;
    int n = maps.size();
    int m = maps[0].size();
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int visited[100][100] = {0,};

    q.push(make_tuple(1, 1, 1));
    visited[0][0] = 1;
    while(!q.empty()) {
        tuple<int, int, int> curr = q.front();
        int x = get<0>(curr), y = get<1>(curr);
        q.pop();
        if (x == n && y == m) return get<2>(curr);
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int dist = get<2>(curr);
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && maps[nx - 1][ny - 1] == 1 && !visited[nx - 1][ny - 1]) {
                q.push(make_tuple(nx, ny, dist + 1));
                visited[nx- 1][ny - 1] = 1;
            }
        }
    }
    return -1;
}