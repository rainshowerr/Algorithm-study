#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define INF 1e9

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
    vector<pair<int, int> > adjlist[20001];
    int dist[20001];
    int v, e, k;
    cin >> v >> e >> k;
    for(int i = 1; i <= v; i++)
        dist[i] = INF;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjlist[u].push_back(make_pair(v, w));
    }
    pq.push(make_pair(k, 0));
    dist[k] = 0;
    while(!pq.empty()) {
        int curr = pq.top().first;
        int curr_dist = pq.top().second;
        pq.pop();
        for(pair<int, int> e: adjlist[curr]) {
            int next = e.first;
            int next_cost = e.second;
            if (dist[next] > curr_dist + next_cost) {
                dist[next] = curr_dist + next_cost;
                pq.push(make_pair(next, dist[next]));
            }
        }
    }
    for(int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}