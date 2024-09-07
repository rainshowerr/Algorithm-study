#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool used[10000] = {false,};

bool compare(vector<string> a, vector<string> b) {
    if (a[0] == b[0]) return a[1] < b[1];
}

void dfs(string airport, vector<string> ans, vector<vector<string>> tickets) {
    ans.push_back(airport);
    if (ans.size() == tickets.size() + 1) {
        if (answer.size() == 0) // 가장 처음 경로가 답이 됨
            answer = ans;
        return;
    }
    for(int i = 0; i < tickets.size(); i++) {
        if (used[i]) continue;
        if (tickets[i][0] == airport) {
            used[i] = true;
            dfs(tickets[i][1], ans, tickets);
            used[i] = false; // 모든 도시를 방문하지 못하는 경우 백트래킹 필요 (티켓 사용 순서에 따라 결과가 바뀜)
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), compare);
    dfs("ICN", answer, tickets);
    return answer;
}