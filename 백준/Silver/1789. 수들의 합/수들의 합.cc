#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	long long s, sum = 0, cnt = 0;
	cin >> s;
	for (int i = 1; sum <= s; i++) {
		sum += i;
		cnt++;
	}
	cnt--;
	cout << cnt;
}