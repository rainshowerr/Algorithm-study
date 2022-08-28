#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int day, car[5], cnt = 0;
	cin >> day >> car[0] >> car[1] >> car[2] >> car[3] >> car[4];
	for(int i = 0; i < 5; i++) {
		if (day == car[i])
			cnt++;
	}
	cout << cnt;
}