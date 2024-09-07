#include <string>
#include <vector>

using namespace std;

int visited[200] = {0,};

void dfs(int n, vector<vector<int>> computers, int num) {
    for(int i = 0; i < n; i++) {
        int connected = computers[num][i];
        if (connected && !visited[i]) {
            visited[i] = 1;
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(n, computers, i);
            answer++;
        }
    }
    return answer;
}