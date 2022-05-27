#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string str; int i, j, k = 0, cnt = 0;
	bool is_croatia;
	string croatia[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	cin >> str;
	for (i = 0; str[i]; i++) {
		is_croatia = false;
		for (j = 0; j < 8; j++) {
			if (str[i] == croatia[j][0]) { // 첫 글자가 크로아티아 글자일 가능성이 있다면
				for (k = 0; str[i + k] && str[i + k] == croatia[j][k]; k++); // 끝까지 탐색
				if (k == croatia[j].length()) {
					cnt++;
					is_croatia = true; // cnt가 두 번 증가하지 않도록 표시
					i += k - 1; // i를 k만큼 밀어줘야 하는데 나중에 i++되기 때문에 k-1만 더해줌
					break;
				}
			}
		}
		if (!is_croatia)
			cnt++;
	}
	cout << cnt;
}