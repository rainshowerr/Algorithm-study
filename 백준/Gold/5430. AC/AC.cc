#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		// 함수, 배열 입력받기
		string p, num;
		int n, cnt = 0;
		cin >> p >> n >> num;
		// 숫자만 덱에 push!
		deque<int> q;
		string temp = "";
		for (int i = 1; i < num.length(); i++) {
			if (isdigit(num[i]))
				temp += num[i];
			else {
				if (!temp.empty()) { // []이 입력될 경우를 제외하고 숫자 push
					q.push_back(stoi(temp));
					temp = "";
				}
			}
		}
		// 함수 수행
		bool error = false;
		bool reverse = false;
		for (int i = 0; i < p.length(); i++) {
			// reverse를 true면 false, false면 true로 바꿔줌
			if (p[i] == 'R')
				reverse = reverse ? false : true;
			// 삭제 연산
			else if (!q.empty() && p[i] == 'D') {
				if (reverse)
					q.pop_back();
				else
					q.pop_front();
			}
			// 큐가 비어있는데 삭제연산이 들어옴 (오류)
			else if (q.empty() && p[i] == 'D') {
				error = true;
				break;
			}
		}
		// 결과 출력
		if (error) cout << "error" << '\n';
		else {
			cout << '[';
			while(!q.empty()) {
				// 뒤집혀있으면 뒤에서부터 pop
				if (reverse) {
					cout << q.back();
					q.pop_back();
				}
				// 뒤집혀있지 않으면 앞에서부터 pop
				else {
					cout << q.front();
					q.pop_front();
				}
				if (q.size() != 0)
					cout << ',';
			}
			cout << ']' << '\n';
		}
	}
}