#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k, s = 0, maxi = 0;
	string word[50];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> word[i];
	if (k < 5) {
		cout << '0';
		return 0;
	}
	// s에 필수 문자 5개 추가
	s = (s | (1 << ('a' - 'a')));
	s = (s | (1 << ('c' - 'a')));
	s = (s | (1 << ('i' - 'a')));
	s = (s | (1 << ('n' - 'a')));
	s = (s | (1 << ('t' - 'a')));
	// 모든 부분집합 탐색
	for (int bit = s; bit < (1 << 26); bit++) {
		if ((bit & s) != s) continue; // bit가 s를 포함하고 있지 않다면 바로 continue
		int cnt = 0;
		// 원소 개수 검사
		for (int i = 0; i < 26; i++) {
			if (bit & (1 << i))
				cnt++;
		}
		// 필수 문자 5개를 포함해 k개를 골랐을 경우
		if (cnt == k) {
			int wc = 0;
			for (int i = 0; i < n; i++) {
				bool flag = true;
				for (int j = 4; j < word[i].length() - 4; j++) { // anta ~ tica의 ~ 부분만 탐색
					if (!(bit & (1 << (word[i][j] - 'a')))) {
						flag = false;
						break;
					}
				}
				if (flag)
					wc++;
			}
			maxi = max(maxi, wc);
		}
	}
	cout << maxi;
}