#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	int sum = 0;
	string str;
	stack<char> s;
	cin >> str;
	int flag;
	for (char c : str) {
		if (c == '(') {
			s.push('(');
			flag = 1;
		}
		else {
			s.pop();
			if (flag == 1) { // 레이저
				if (s.size()) {
					sum += s.size();
				}
			}
			else
				sum += 1;
			flag = 0;
		}
	}
	cout << sum;
	return 0;
}