#include <string>
#include <vector>

using namespace std;

// 각 단어가 알맞은 단어인지 check 후 answer을 설정하는 함수
int check(vector<vector<int>> v) {
    int answer = 0;
    for(int i = 0; i < v.size(); i++) {
        bool flag = true;
        for(int j = 0; j < v[i].size(); j++) {
            if ((v[i][j] == -1) || (j != 0 && v[i][j] == v[i][j - 1])) { // 단어가 아니거나 같은 단어가 연속해서 나오면 fail
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    return answer;
}

// 단어별로 번호를 지정해주는 함수
int getWordNum(string str) {
    if (str == "aya") return 1;
    else if (str == "ye") return 2;
    else if (str == "woo") return 3;
    else if (str == "ma") return 4;
    else return 0;
}

int solution(vector<string> babbling) {
    vector<vector<int>> translate;
    // 단어를 숫자로 바꿔서 [[], [], []] 형태로 만들어줌
    for(int i = 0; i < babbling.size(); i++) {
        translate.push_back(vector<int>());
        string curr = "";
        for(int j = 0; j < babbling[i].length(); j++) {
            curr += babbling[i][j];
            int wordNum = getWordNum(curr);
            if (wordNum) { // 단어면 단어 번호로 저장
                translate[i].push_back(wordNum);
                curr = "";
            }
        }
        if (curr != "") { // 단어가 아니면 -1로 저장
            translate[i].push_back(-1);
            curr = "";
        }
    }
    return check(translate);
}