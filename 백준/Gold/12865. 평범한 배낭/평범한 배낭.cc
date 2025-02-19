#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int w[101];
int v[101];
int d[101][100001]; // i번까지 봤을 때 j무게를 버티는 가방 안 물건들의 가치의 최댓값

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, k, maxx = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for(int j = w[1]; j <= k; j++) { // 초기값 설정
		d[1][j] = v[1];
	}
	maxx = d[1][w[1]];

	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if (j < w[i]) { // 무게가 가방 무게를 초과하면 담을 수 없음
				d[i][j] = d[i - 1][j];
			} else { // i 포기하고 다른걸로 채운 최대가치 vs i 선택한 최대가치
				d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]);
			}
			maxx = max(maxx, d[i][j]);
		}
	}
	cout << maxx;
}