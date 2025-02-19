#include <iostream>
#include <algorithm>

using namespace std;

int cake[2001];
long long dp[2001][2001]; // i부터 j까지 avalible할 때 최대값
int n;

bool turn(int i, int j) { // 케이크의 남은 조각 개수로 누구의 턴인지 판단
	if (j < i) j += n;
	return ((j - i + 1) % 2) == (n % 2); // true면 JOI, false면 IOI 턴;
}

int left(int i) {
	if (i == 1) return n;
	return i - 1;
}

int right(int i) {
	if (i == n) return 1;
	return i + 1;
}

long long dynamic(int i, int j) {
	if (dp[i][j]) return dp[i][j];
	if (i == j && turn(i, j)) return cake[i];
	else if (i == j && !turn(i, j)) return 0;

	if (turn(i, j)) { // JOI는 최댓값을 원함
		dp[i][j] = max(dynamic(right(i), j) + cake[i], dynamic(i, left(j)) + cake[j]);
	} else { // IOI는 가장 큰 조각을 가져감!
		if (cake[i] > cake[j])
			dp[i][j] = dynamic(right(i), j);
		else
			dp[i][j] = dynamic(i, left(j));
	}
	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	long long maxx = 0;
	for(int i = 1; i <= n; i++) {
		cin >> cake[i];
	}
	if (n == 1) { // 케이크가 한 조각인 경우
		cout << cake[1];
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		maxx = max(maxx, dynamic(right(i), left(i)) + cake[i]);
	}
	cout << maxx;
}