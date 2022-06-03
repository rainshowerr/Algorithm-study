#include <iostream>
using namespace std;

int n, ans[10];
char sign[10][10];

bool check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum += ans[i];
		if (sum <= 0 && sign[i][idx] == '+')
			return false;
		if (sum >= 0 && sign[i][idx] == '-')
			return false;
		if (sum != 0 && sign[i][idx] == '0')
			return false;
	}
	return true;
}

void go(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
		exit(0); // 정답 하나만 출력
	}
	for (int i = -10; i <= 10; i++) {
		ans[cnt] = i;
		if (check(cnt)) // ans[cnt]가 정해질 때마다 검사
			go(cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
			cin >> sign[i][j];
	}
	go(0);
}