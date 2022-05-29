#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

int n, skill[21][21], ans = 100000000;
vector<int> A, B;

void go(int people, int start) {
	if (people == n / 2) {
		int A_skill = 0, B_skill = 0;
		// B 팀 구성 (A에 없는 숫자라면 B에 넣는다)
		for (int i = 1; i <= n; i++) {
			int flag = true;
			for (int j = 0; j < A.size(); j++) {
				if (i == A[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				B.push_back(i);
		}
		// A 스킬 계산
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A.size(); j++) {
				A_skill += skill[A[i]][A[j]];
			}
		}
		// B 스킬 계산
		for (int i = 0; i < B.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				B_skill += skill[B[i]][B[j]];
			}
		}
		// 결과 도출
		ans = min(ans, abs(A_skill - B_skill));
		B.clear(); // 비워주지 않으면 계속해서 쌓임!
		return;
	}
	for (int i = start; i <= n; i++) {
		A.push_back(i);
		go(people + 1, i + 1);
		A.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> skill[i][j];
		}
	}
	go(0, 1);
	cout << ans;
}