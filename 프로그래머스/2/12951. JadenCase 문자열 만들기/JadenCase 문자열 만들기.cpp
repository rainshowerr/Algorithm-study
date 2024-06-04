#include <string>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

string solution(string s) {
    int flag = 1;
    string answer = "";
    for(int i = 0; i < s.length(); i++) {
        // 단어의 첫 문자인 경우
        if (flag && s[i] != ' ') {
            if (isalpha(s[i]) && ('a' <= s[i] && s[i] <= 'z')) { 
                answer += s[i] + 'A' - 'a';
            }
            else
                answer += s[i];
            flag = 0;
        }
        // 단어의 첫 문자가 아닌 경우
        else {
            if ('A' <= s[i] && s[i] <= 'Z')
                answer += s[i] - ('A' - 'a');
            else
                answer += s[i];
            // 공백인 경우에는 플래그 올리기
            if (s[i] == ' ')
                flag = 1;
        }
    }
    return answer;
}