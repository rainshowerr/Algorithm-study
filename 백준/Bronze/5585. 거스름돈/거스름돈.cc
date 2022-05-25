#include <iostream>
using namespace std;

int main() {
	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	int money, cnt = 0;;
	cin >> money; // 지불해야하는 돈ㅁ
	money = 1000 - money; // 거스름돈
	for (int i = 0; i < 6 && money; i++) {
		int n = money / coin[i];
		if (n) {
			cnt += n;
			money = money % coin[i];
		}
	}
	cout << cnt;
}