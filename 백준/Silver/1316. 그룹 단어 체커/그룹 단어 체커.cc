#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	while (n--) {
		bool is_group = true;
		bool visited[26] = { false };
		char word[101];
		cin >> word;
		for (int i = 0; word[i]; i++)
			if (!visited[word[i] - 'a'])
				visited[word[i] - 'a'] = true;
			else if (visited[word[i] - 'a'] && word[i - 1] != word[i]) // 이미 방문한 글잔데 그룹지어져 있지 않은 경우
				is_group = false;
		if (is_group)
			ans++;
	}
	cout << ans;
}