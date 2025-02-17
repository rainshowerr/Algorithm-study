#include <iostream>
#include <vector>

using namespace std;

int n, arr[1000001];

/*
늘 완벽하게 증가하는 수열을 만드는 게 아니라, 정확한 길이만 출력하면 됨
그러므로 새로 들어온 num이 배열의 마지막 원소보다 크다면 push, 
아니라면 배열에서 num보다 크거나 같은 수를 찾아 num으로 바꿔치기
*/

// 수열에서 n보다 큰 수의 인덱스를 찾아서 반환
int find_idx(int i, int j, int n) {
	int mid, ans;
	while(i <= j) {
		mid = (i + j) / 2;
		if (arr[mid] == n)
			return mid;
		else if (arr[mid] > n) {
			j = mid - 1;
			ans = mid; // 답 후보 찍어놓기
		}
		else if (arr[mid] < n) {
			i = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	int num, idx = -1, change_idx;
	for(int i = 0; i < n; i++) {
		cin >> num;
		if (idx == -1) arr[++idx] = num;
		else if (num > arr[idx]) arr[++idx] = num;
		else {
			change_idx = find_idx(0, idx, num);
			arr[change_idx] = num;
		}
	}
	cout << idx + 1;
}