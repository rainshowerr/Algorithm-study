#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct queue {
	int q[10000];
	int begin = 0;
	int end = 0;
	void push(int num) {
		q[end] = num;
		end++;
	}
	int pop() {
		if (!empty()) {
			int temp;
			temp = q[begin];
			q[begin] = 0;
			begin++;
			return temp;
		}
		return -1;
	}
	int size() {
		return end - begin;
	}
	int empty() {
		if (begin == end)
			return 1;
		return 0;
	}
	int front() {
		return q[begin];
	}
	int back() {
		return q[end - 1];
	}
};

int main() {
	queue q;
	int n;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int pnum;
			cin >> pnum;
			q.push(pnum);
		}
		else if (cmd == "pop") {
			cout << q.pop() << '\n';
		}
		else if (cmd == "size") {
			cout << q.size()<<'\n';
		}
		else if (cmd == "empty") {
			cout << q.empty()<<'\n';
		}
		else if (cmd == "front") {
			if (!q.empty()) {
				cout << q.front()<<'\n';
			}
			else
				cout << "-1\n";
		}
		else if (cmd == "back") {
			if (!q.empty()) {
				cout << q.back()<<'\n';
			}
			else
				cout << "-1\n";
		}
	}
	return 0;
}