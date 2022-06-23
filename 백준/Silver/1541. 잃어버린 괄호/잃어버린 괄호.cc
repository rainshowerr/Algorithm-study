#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s, num;
    int ans = 0;
    bool flag = false;
    cin >> s;
    // -가 나타나면 그 뒤의 값은 무조건 빼주기
    for(int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || !s[i]) {
            if (flag)
                ans -= stoi(num);
            else
                ans += stoi(num);
            num = "";
            if (s[i] == '-') flag = true;
        }
        else // s[i]가 숫자
            num += s[i];
    }
    cout << ans;
}