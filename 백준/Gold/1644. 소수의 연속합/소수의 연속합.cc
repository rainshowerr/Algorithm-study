#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<bool> visited(4000001);
	vector<int> sosu;
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}

    // 에라토스테네스의 체
    for(int i = 2; i * i <= n; i++) {
        if (!visited[i]) {
            for(int j = i * i; j <= n; j += i) {
                visited[j] = true;
            }
        }
    }
    // 소수 배열 생성
	for(int i = 2; i <= n; i++) {
        if (!visited[i]) sosu.push_back(i);
    }

	// 투포인터
	int l = 0, r = 0, cnt = 0;
	int sum = sosu[0];
	while (l <= r && r < sosu.size()) {
		if (sum == n) {
			sum -= sosu[l++];
			cnt++;
		}
		else if (sum < n) {
			if (r < sosu.size() - 1) sum += sosu[++r];
			else break;
		}
		else sum -= sosu[l++];
	}
	cout << cnt;
}