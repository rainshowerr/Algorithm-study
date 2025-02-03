#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int main() {
	while (1) {
		// 프로그램 입력받기
		vector<string> program;
		while (1) {
			string s;
			cin >> s;
			if (s == "QUIT")
				return 0;
			else if (s == "END")
				break;
			else if (s == "NUM") {
				string n;
				cin >> n;
				program.push_back(s + " " + n);
			}
			else
				program.push_back(s);
		}
		// 수 입력받고 프로그램 실행
		int repeat;
		cin >> repeat;
		for (int i = 0; i < repeat; i++) {
			stack<long long> st;
			long long initial_num;
			bool flag = true;
			cin >> initial_num;
			st.push(initial_num);

			for (int j = 0; j < program.size(); j++) {
				if (program[j].substr(0, 3) == "NUM") {
					int num = stoi(program[j].substr(4));
					st.push(num);
				}
				else if (program[j] == "POP") {
					if (st.size() == 0) {
						flag = false;
						break;
					}
					st.pop();
				}
				else if (program[j] == "INV") {
					if (st.size() == 0) {
						flag = false;
						break;
					}
					int num = st.top();
					st.pop();
					st.push((long long)num * -1);
				}
				else if (program[j] == "DUP") {
					if (st.size() == 0) {
						flag = false;
						break;
					}
					st.push(st.top());
				}
				else if (program[j] == "SWP") {
					if (st.size() < 2) {
						flag = false;
						break;
					}
					int first = st.top();
					st.pop();
					int second = st.top();
					st.pop();
					st.push(first);
					st.push(second);
				}
				else if (program[j] == "ADD") {
					if (st.size() < 2) {
						flag = false;
						break;
					}
					int first = st.top();
					st.pop();
					int second = st.top();
					st.pop();
					if (abs((long long)first + second) > pow(10, 9)) {
						flag = false;
						break;
					}
					st.push((long long)first + second);
				}
				else if (program[j] == "SUB") {
					if (st.size() < 2) {
						flag = false;
						break;
					}
					int first = st.top();
					st.pop();
					int second = st.top();
					st.pop();
					if (abs((long long)second - first) > pow(10, 9)) {
						flag = false;
						break;
					}
					st.push((long long)second - first);
				}
				else if (program[j] == "MUL") {
					if (st.size() < 2) {
						flag = false;
						break;
					}
					int first = st.top();
					st.pop();
					int second = st.top();
					st.pop();
					if (abs((long long)first * second) > pow(10, 9)){
						flag = false;
						break;
					}
					st.push((long long)first * second);
				}
				else if (program[j] == "DIV") {
					if (st.size() < 2) {
						flag = false;
						break;
					}
					int first = st.top();
					if (first == 0) {
						flag = false;
						break;
					}
					st.pop();
					int second = st.top();
					st.pop();
					if (!((first >= 0 && second >= 0) || (first < 0 && second < 0)))
						st.push(abs(second) / abs(first) * -1);
					else
						st.push(abs(second) / abs(first));
				}
				else if (program[j] == "MOD") {
					if (st.size() < 2) {
						flag = false;
						break;
					}
					int first = st.top();
					if (first == 0) {
						flag = false;
						break;
					}
					st.pop();
					int second = st.top();
					st.pop();
					if (second < 0)
						st.push(abs(second) % abs(first) * -1);
					else
						st.push(abs(second) % abs(first));
				}
			}
			if (flag == true && st.size() == 1)
				cout << st.top() << endl;
			else
				cout << "ERROR" << endl;
		}
		cout << endl;
	}
}