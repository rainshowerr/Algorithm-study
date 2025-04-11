#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[101][101] = {false,};
int cnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, vector<string>& maps) {
    visited[x][y] = true;
    cnt += maps[x][y] - '0';
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].length()) continue;
        if (!visited[nx][ny] && maps[nx][ny] != 'X') dfs(nx, ny, maps);
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] == 'X') continue;
            if (!visited[i][j]) {
                cnt = 0;
                dfs(i, j, maps);
                answer.push_back(cnt);
            }
        }
    }
    if (answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}