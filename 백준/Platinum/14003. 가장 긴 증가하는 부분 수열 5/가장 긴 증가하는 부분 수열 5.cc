#include <iostream>
#include <vector>

using namespace std;

int n, num[1000001], arr[1000001], loc[1000001];

/*
가장 긴 증가하는 부분 수열 3
늘 완벽하게 증가하는 수열을 만드는 게 아니라, 정확한 길이만 출력하면 됨
그러므로 새로 들어온 num이 배열의 마지막 원소보다 크다면 push, 
아니라면 배열에서 num보다 크거나 같은 수를 찾아 num으로 바꿔치기

+ 가장 긴 증가하는 부분 수열 5
길이뿐만 아니라 수열도 출력해야 함
각 수가 수열에 들어간 index를 저장 후 역순으로 찾아 출력
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
	vector<int> ans_reverse;
	int idx = -1, change_idx;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> num[i];
		if (idx == -1) {
			arr[++idx] = num[i];
			loc[i] = idx;
		}
		else if (num[i] > arr[idx]) {
			arr[++idx] = num[i];
			loc[i] = idx;
		}
		else {
			change_idx = find_idx(0, idx, num[i]);
			arr[change_idx] = num[i];
			loc[i] = change_idx;
		}
	}
	cout << idx + 1 << '\n';
	// 경로 추적
	for(int i = n - 1; i >= 0; i--) {
		if (loc[i] == idx) {
			ans_reverse.push_back(num[i]);
			idx--;
		}
	}
	for(int i = ans_reverse.size() - 1; i >= 0; i--)
		cout << ans_reverse[i] << ' ';
}