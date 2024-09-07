#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(string a, string b) {
    int diff = 0;
    for(int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) diff++;
    }
    if (diff == 1) {
        return true;
    }
    return false;
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int> > q;
    int answer = 0;
    bool visited[50] = {false,};
    
    q.push({begin, 0});
    while(!q.empty()) {
        string word = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (word == target)
            return cnt;
        
        for(int i = 0; i < words.size(); i++) {
            if (!visited[i] && check(word, words[i])) {
                visited[i] = true;
                q.push({words[i], cnt + 1});
            }
        }
    }
    
    return answer;
}