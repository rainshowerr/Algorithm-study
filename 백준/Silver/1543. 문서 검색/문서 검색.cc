#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string str, to_find;
	getline(cin, str);
	getline(cin, to_find);
	int i, j, ans = 0;
	for (i = 0; str[i] ; i++) { // i는 str을 탐색하는 기준 인덱스, j는 to_find를 탐색하는 인덱스
		for (j = 0; str[i + j] && str[i + j] == to_find[j]; j++) { // str[i+j] == to_find[j]일 경우 j만 늘려주면서 계속 탐색
			if (to_find[j + 1] == '\0') { // 문자열을 찾았을 경우
				ans++;
				i += j;
				break;
			}
		}
	}
	cout << ans;
}