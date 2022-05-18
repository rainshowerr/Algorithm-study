#include <iostream>
#include <math.h>
using namespace std;
int go(int);
int d[1001] = { 0 };
int arr[1001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int max = 1; // 길이는 1 이상
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			max = go(i);
		else
			if (go(i) > max)
				max = go(i);
	}
	cout << max;
	return 0;
}
int go(int n) {
	d[1] = 1;
	if (d[n])
		return d[n];
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[n])
			d[n] = max(d[n], d[i] + 1);
	}
	if (d[n] == 0) // arr[n]이 배열에서 가장 작은 수일 경우
		d[n] = 1;
	return d[n];
}