#include <iostream>
using namespace std;
int go(int);
int d[1001] = { 0 }, dnum[1001][1001] = { 0 }, arr[1001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int max = 1; // 길이는 1 이상
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			max = go(i);
			p = i;
		}
		else
			if (go(i) > max) {
				max = go(i);
				p = i;
			}
	}
	cout << max <<'\n';
	for (int i = 1; dnum[p][i] != 0; i++) {
		cout << dnum[p][i] << ' ';
	}
	return 0;
}
int go(int n) {
	d[1] = 1; dnum[1][1] = arr[1];
	if (d[n])
		return d[n];
	int k;
	// d[n]을 가능한 한 최댓값으로 갱신
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[n]) {
			if (d[n] < d[i] + 1) {
				d[n] = max(d[n], d[i] + 1);
				k = i;
			}
		}
	}
	// dnum 배열에 값 넣어주기
	if (d[n] != 0) {
		for (int i = 1; i <= n-1; i++) {
			dnum[n][i] = dnum[k][i]; // 새로운 배열에 가장 긴 배열 복붙
		}
		for (int i = 1; i <= n ; i++) { // 배열의 마지막에 arr[n] 추가
			if (dnum[n][i] == 0) {
				dnum[n][i] = arr[n];
				break;
			}
		}
	}
	else { // arr[n]이 배열에서 가장 작은 수일 경우
		d[n] = 1;
		dnum[n][1] = arr[n];
	}
	return d[n];
}