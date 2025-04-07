#include <iostream>
#include <vector>

using namespace std;

vector<int> computer[101];
bool visit[101];
int cnt = 0;

void dfs(int num) {
	visit[num] = true;
	for(int x : computer[num]) {
		if (!visit[x]) {
			cnt++;
			dfs(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	dfs(1);
	cout << cnt;
}