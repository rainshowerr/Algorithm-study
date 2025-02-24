#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> edge[501];
int n, m, indegree[501], outdegree[501];
bool visit[501];

// dfs로 방문할 수 있는 노드를 탐색함과 동시에 indegree 계산

void dfs(int node) {
    visit[node] = true;
    for(int next : edge[node]) {
        if (visit[next] == false) {
            indegree[next]++;
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {
        dfs(i);
        for(int j = 1; j <= n; j++) {
            if (visit[j]) outdegree[i]++;
            visit[j] = false;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if (indegree[i] + outdegree[i] == n) cnt++;
    }
    cout << cnt;
}