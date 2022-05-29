#include <iostream>
using namespace std;

int num[20], n, s, ans = 0;
bool visited[20] = { false };

// choice는 선택할 숫자의 개수, idx는 지금까지 선택한 숫자의 개수, find_idx는 탐색을 시작할 배열의 인덱스, sum은 탐색한 숫자들의 합
void go(int choice, int idx, int find_idx, int sum) {
	if (idx == choice) {
		if (sum == s)
			ans++;
		return;
	}
	for (int i = find_idx; i < n; i++) {
		go(choice, idx + 1, i + 1, sum + num[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++) {
		go(i, 0, 0, 0);
	}
	cout << ans;
}