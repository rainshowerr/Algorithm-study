#include <iostream>
using namespace std;

int parent[100001];
int dist[100001];

int find(int a) {
    if (parent[a] == a) return a;

	int a_p = find(parent[a]);
    dist[a] += dist[parent[a]];
    return parent[a] = a_p;
}

void uni(int a, int b, int w) {
    int a_p = find(a), b_p = find(b);
    parent[b_p] = a_p; // b의 부모를 a의 부모의 자식으로 만들어줌
    dist[b_p] = w + dist[a] - dist[b]; // b의 부모까지의 거리 업데이트
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for(int i = 0; i <= n; i++) // dist 초기화
            dist[i] = 0;
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        for(int i = 0; i < m; i++) {
            char command;
            int a, b, w;
            cin >> command >> a >> b;
            if (command == '!') { // 무게 측정
                cin >> w;
                uni(a, b, w);
            } else if (command == '?') { // 질문
                if (find(a) != find(b)) cout << "UNKNOWN\n";
                else cout << dist[b] - dist[a] << '\n';
            }
        }
    }
}