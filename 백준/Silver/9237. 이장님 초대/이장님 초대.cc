#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, arr[100000], maxi = 0, ans;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n, cmp);
	ans = 1;
    // 각 나무가 자라는 데 걸리는 시간 업데이트
	for (int i = 0, day = 1; i < n; i++, day++) {
		arr[i] = day + arr[i];
		maxi = max(maxi, arr[i]);
	}
	ans += maxi;
	cout << ans;
}