#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int indegree[501];
int t[501];
int dist[501];
queue<int> q;
vector<int> adjlist[501];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        t[i] = a;
        dist[i] = a;
        while (1) {
            cin >> b;
            if (b == -1) break;
            indegree[i]++;
            adjlist[b].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++) { // in-degree가 0인 노드를 큐에 push
        if (!indegree[i])
            q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int next: adjlist[node]) { // in-degree 조정 후 새롭게 갈 수 있는 노드 push
            indegree[next]--;
            dist[next] = max(dist[next], dist[node] + t[next]);
            if (!indegree[next])
                q.push(next);
        }
    }

    for(int i = 1; i <= n; i++)
        cout << dist[i] << '\n';
}

// 반례
// 1
// 1 -> 2
// 2 -> 3
// 3, 5 -> 4
// 5