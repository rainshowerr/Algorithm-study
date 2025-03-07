#include <string>
#include <vector>

using namespace std;

string binary(int len) {
    string bin = "";
    while (len > 0) {
        bin += to_string(len % 2);
        len /= 2;
    }
    return bin;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while(s != "1") {
        int zero_cnt = 0;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '0') zero_cnt++;
        }
        answer[0]++; // 이진 변환 횟수 업데이트
        answer[1] += zero_cnt;
        s = binary(s.length() - zero_cnt);
    }
    return answer;
}