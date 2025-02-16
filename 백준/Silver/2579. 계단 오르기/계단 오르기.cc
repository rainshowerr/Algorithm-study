#include <iostream>
#include <algorithm>

using namespace std;

int stair[301];
int sum[301][3]; // i번째 계단까지 마지막에 j만큼 올라온 경우 점수의 최댓값

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> stair[i];
	}
	for(int i = 1; i <= n; i++) {
		sum[i][1] = sum[i - 1][2] + stair[i];
		sum[i][2] = max(sum[i - 2][1], sum[i - 2][2]) + stair[i];
	}
	cout << max(sum[n][1], sum[n][2]);
}