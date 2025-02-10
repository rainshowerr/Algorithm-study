#include <iostream>

using namespace std;

int parent[1000001];

int find(int a) {
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
        parent[i] = i;
    for(int i = 0; i < m; i++) {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0) {
            uni(a, b);
        } else if (c == 1) {
            if (find(a) == find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}