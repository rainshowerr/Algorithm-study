#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int cnt[2] = { 0 };
	char num[1000000];
	cin >> num;
	// 0, 1, 묶음이 몇 번 나오는지 세서 cnt 배열에 담기
	for (int i = 0; num[i] != '\0'; i++) {
		if (num[i] == '0') {
			if (num[i + 1] != '0')
				cnt[0]++;
		}
		else {
			if (num[i] == '1') {
				if (num[i + 1] != '1')
					cnt[1]++;
			}
		}
	}
	if (cnt[0] + cnt[1] == 1)
		cout << '0';
	else {
		cout << min(cnt[0], cnt[1]);
	}
}