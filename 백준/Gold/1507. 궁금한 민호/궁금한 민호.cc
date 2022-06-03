#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, map[20][20], sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	// 어딘가를 경유해서 갈 수 있는 도시인 경우 도로를 0으로 만들어준다. (못 가는 도로라는 의미)
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || i == k || j == k) continue;
				else if (map[i][k] != 0 && map[k][j] != 0 && map[i][j] == map[i][k] + map[k][j])
					map[i][j] = 0;
				// 최단거리가 따로 존재하는 경우 예외처리 (잘못된 지도)
				else if (map[i][k] != 0 && map[k][j] != 0 && map[i][k] + map[k][j] < map[i][j]) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	// 정답 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += map[i][j];
		}
	}
	cout << sum / 2;
	return 0;
}