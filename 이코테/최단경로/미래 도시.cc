#include <iostream>
#define INF 1e9

using namespace std;

int main(){
	int n, m, x, k;
	cin >> n >> m;
	int graph[101][101];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = i == j ? 0 : INF;
		}
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	cin >> x >> k;

	// 플로이드-워셜 알고리즘
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	if (graph[1][k] + graph[k][x] >= INF)
    	cout << "INF";
	else
		cout << graph[1][k] + graph[k][x];
}