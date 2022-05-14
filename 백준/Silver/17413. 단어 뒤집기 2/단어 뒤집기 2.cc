#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
int main() {
	stack<char> s;
	queue<char> q;
	string str;
	getline(cin, str);
	for (auto x : str) {
		if (x == '<') {
			q.push('<');
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
		}
		else if (!q.empty()) {
			int count = 0;
			if (x == '>') {
				q.push('>');
				while(!q.empty()) {
					cout << q.front();
					q.pop();
				}
			}
			else {
				q.push(x);
				count++;
			}
		}
		else if (q.empty()) {
			if (x != ' ') {
				s.push(x);
			}
			else{
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}