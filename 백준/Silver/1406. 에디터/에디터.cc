#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
char str[600000];

int main() {
	stack<char> left, right;
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		left.push(str[i]);
	}
	int num;
	scanf("%d", &num);
	while (num--) {
		char what;
		scanf(" %c", &what);
		if (what == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (what == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (what == 'B') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (what == 'P') {
			char addc;
			scanf(" %c", &addc);
			left.push(addc);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
	return 0;
}