#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, ans = 0, one = 0, zero = 0;
	cin >> n;
	vector<int> positive, negative;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) // 0은 음수의 개수가 홀수인 경우 사용될 예정
			zero++;
		else if (temp == 1) // 1은 다른 숫자와 곱해지면 무조건 손해. 나중에 한꺼번에 더해줄 예정!
			one++;
		else if (temp > 0)
			positive.push_back(temp);
		else
			negative.push_back(temp);
	}
	sort(positive.begin(), positive.end(), greater<>());
	sort(negative.begin(), negative.end());
	int i = 0;
	// 벡터에 담긴 숫자의 개수를 짝수로 만들어주기 (짝지어 곱해줄거니까)
	if (positive.size() % 2 == 1)
		positive.push_back(1);
	if (negative.size() % 2 == 1) {
		if (zero > 0) { // 숫자의 개수가 홀수인 경우 가장 작은 음수를 0으로 만들어줌
			negative.push_back(0);
			zero--;
		}
		else
			negative.push_back(1);
	}
	// 답 구하기
	for (int i = 0; i < positive.size(); i += 2)
		ans += positive[i] * positive[i + 1];
	for (int i = 0; i < negative.size(); i += 2)
		ans += negative[i] * negative[i + 1];
	ans += one;
	cout << ans;
}