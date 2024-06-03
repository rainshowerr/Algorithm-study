#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int flag = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            flag++;
        else if (s[i] == ')')
            flag --;
        
        if (flag < 0)
            return false;
    }
    if (flag != 0)
        return false;

    return answer;
}