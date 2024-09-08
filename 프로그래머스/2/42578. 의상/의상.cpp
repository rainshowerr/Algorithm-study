#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> map;
    for(vector<string> cloth : clothes) { // 종류별 옷 개수 저장
        map[cloth[1]]++;
    }
    for(pair<string,int> e : map){ // 경우의 수 계산
        if (answer == 0) answer = e.second + 1;
        else answer *= (e.second + 1);
    }
    answer--; // 알몸 삭제
    return answer;
}