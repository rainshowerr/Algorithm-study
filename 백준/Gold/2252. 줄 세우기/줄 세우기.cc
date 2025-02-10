#include <iostream>
#include <queue>
using namespace std;

int indegree[32001];
queue<int> q;
vector<int> adjlist[32001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b; // a가 b 앞
        indegree[b]++;
        adjlist[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) { // in-degree가 0인 노드를 큐에 push
        if (!indegree[i])
            q.push(i);
    }
    while(!q.empty()) {
        int node = q.front();
        cout << node << ' ';
        q.pop();
        for(int next: adjlist[node]) { // in-degree 조정 후 새롭게 갈 수 있는 노드 push
            indegree[next]--;
            if (!indegree[next])
                q.push(next);
        }
    }
}
