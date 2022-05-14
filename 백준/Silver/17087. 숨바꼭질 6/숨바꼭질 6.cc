#include <iostream>
using namespace std;
long long arr[100000];
long long newarr[100000];
long long gcd(long long, long long);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	long long x; cin >> x;
	// 수빈이와 각 동생들 사이 거리를 newarr에 저장
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (x > arr[i])
			newarr[i] = x - arr[i];
		else
			newarr[i] = arr[i] - x;
	}
	// 최대공약수 구하기
	int i = 1;
	if (n == 1)
		cout << newarr[0];
	else {
		while (1) {
			newarr[i] = gcd(newarr[i - 1], newarr[i]);
			if (i == n - 1) {
				cout << newarr[i];
				break;
			}
			i++;
		}
	}
	return 0;
}
long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}