#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adjlist[100001];
int parent[18][100001]; // parents 저장할 공간 17개 필요
int depth[100001];
int visited[100001];

// 노드의 depth와 parents 저장
void make_tree(int node, int h) {
    depth[node] = h;
    visited[node] = true;
    for(int next: adjlist[node]) {
        if (visited[next]) continue;
        // parents 저장
        parent[0][next] = node;
        for (int k = 1; k <= 17; k++)
            parent[k][next] = parent[k - 1][parent[k - 1][next]]; // ex. 2^3 = 2^2 + 2^2
        make_tree(next, h + 1);
    }
}

int getLCA(int a, int b)
{
    // 1. 두 노드의 높이를 맞춰줌
    if (depth[a] < depth[b])
        swap(a, b); // a의 depth가 더 크다고 치자

    // depth의 차이만큼 a를 올려줌
    for (int i = 17; i >= 0; i--)
    {
        if (depth[a] - depth[b] >= (1 << i)) // 1 << i는 2의 i승
            a = parent[i][a];
    }

    if (a == b) return a; // 2-1. depth가 같아졌을 때 a와 b가 동일하다면 조상

    // 2-2. 다르다면 조상으로 올라가면서 같아질때까지 찾기
    for (int i = 17; i >= 0; i--)
    {
        if (parent[i][a] == parent[i][b]) continue; // 같으면 낮아지고
        else // 다르면 올라감
        {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    make_tree(1, 0);
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        int lca = getLCA(a, b);
        cout << lca << '\n';
    }
}