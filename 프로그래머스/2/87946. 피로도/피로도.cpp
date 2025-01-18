#include <string>
#include <vector>

using namespace std;

bool visited[8] = {false,};
int max_depth = 0;

void dfs(int n, int depth, int k, vector<vector<int>> dungeons) {
    k -= dungeons[n][1];
    visited[n] = true;
    if (depth > max_depth) max_depth = depth;
    for(int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            dfs(i, depth + 1, k, dungeons);       
        }
    }
    visited[n] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
    for(int i = 0; i < dungeons.size(); i++) {
        if (k >= dungeons[i][0])
            dfs(i, 1, k, dungeons);
    }
    return max_depth;
}