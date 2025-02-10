#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int parent[1001];
vector<pair<int, int> > adjlist[1001];

struct compare{
    bool operator()(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
        return a.second.second >= b.second.second;
    }
};

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > edge;

int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge.push(make_pair(a, make_pair(b, c)));
    }

    for(int i = 1; i <= n; i++) { // union-find 초기화
        parent[i] = i;
    }

    int sum = 0;
    int cnt = n - 1;
    while(cnt > 0) {
        pair<int, pair<int, int> > e = edge.top();
        int x = e.first;
        int y = e.second.first;
        int cost = e.second.second;
        adjlist[x].push_back(make_pair(y, cost));
        adjlist[y].push_back(make_pair(x, cost));
        if (find(x) != find(y)) {
            uni(x, y);
            sum += cost;
            cnt--;
        }
        edge.pop();
    }
    cout << sum;
}