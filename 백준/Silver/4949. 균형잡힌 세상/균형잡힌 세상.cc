#include <iostream>
#include <stack>
using namespace std;

int main() {
    while(true) {
        string str;
        getline(cin, str);
        if (str == ".") break;
        stack<char> s;
        bool flag = true;
        for(int i = 0; str[i] != '.'; i++) {
            if (str[i] == '.') break;
            if (str[i] == '(') s.push('(');
            else if (str[i] == '[') s.push('[');
            else if (str[i] == ')') {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else {
                    flag = false;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && s.empty()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}