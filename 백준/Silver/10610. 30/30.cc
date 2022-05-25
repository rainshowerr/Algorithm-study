#include <iostream>
#include <algorithm>
using namespace std;

bool descending(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string n;
	int sum = 0;
	bool is_zero = false;
	cin >> n;
	// 30의 배수 조건 : 각 자리수의 합이 3의 배수 && 1의 자리 숫자가 0
	for (int i = 0; i < n.length(); i++) {
		if (n[i] == '0')
			is_zero = true;
		sum += n[i] - '0';
	}
	// 정렬 및 출력
	if (is_zero && sum % 3 == 0) {
		sort(&n[0], &n[n.length()], descending);
		cout << n;
	}
	else
		cout << "-1";
}