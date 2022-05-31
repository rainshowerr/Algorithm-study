#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, skill[20][20], ans = 2147483647;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> skill[i][j];
	}
	// 비트마스크로 전체 경우의 수 탐색
	for (int s = 0; s < (1 << n); s++) {
		vector<int> A, B;
		int cnt = 0;
		// 팀 명수 세기
		for (int i = 0; i < n; i++) {
			if (s & (1 << i))
				cnt++;
		}
		// 0명인 팀이 있으면 continue
		if (cnt == 0 || cnt == n)
			continue;
		// 팀 구성
		for (int i = 0; i < n; i++) {
			if (s & (1 << i))
				A.push_back(i);
			else
				B.push_back(i);
		}
		// 팀별 능력치 계산 및 결과 출력
		int A_skill = 0, B_skill = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A.size(); j++) {
				if (i == j) continue;
				A_skill += skill[A[i]][A[j]];
			}		
		}
		for (int i = 0; i < B.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				if (i == j) continue;
				B_skill += skill[B[i]][B[j]];
			}
		}
		ans = min(ans, abs(A_skill - B_skill));
	}
	cout << ans;
}