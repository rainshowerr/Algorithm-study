#include <iostream>
#include <vector>
#include <utility>
#define INF 1e9
using namespace std;

vector<pair<int, int> > adjlist[501];
long long dist[501];

#define INF 1e9

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjlist[a].push_back(make_pair(b, c));
    }
    dist[1] = 0;
    for(int i = 2; i <= n; i++)
        dist[i] = INF;
    bool flag = true;
    for(int i = 1; i <= n; i++) { // 정점의 개수 n만큼 반복
        for(int j = 1; j <= n; j++) { // 모든 간선 테스트
            if (dist[j] == INF) continue;
            for(int k = 0; k < adjlist[j].size(); k++) {
                if (dist[adjlist[j][k].first] > dist[j] + adjlist[j][k].second) {
                    dist[adjlist[j][k].first] = dist[j] + adjlist[j][k].second;
                    if (i == n) flag = false;
                }
            }
        }
    }
    if (!flag) cout << -1;
    else {
        for(int i = 2; i <= n; i++) {
            if (dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
}