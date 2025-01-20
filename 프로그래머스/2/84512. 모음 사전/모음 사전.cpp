#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;
int order = 0;

void dfs(string s) {
    if (s.length() > 5)
        return;
    m[s] = order++;
    dfs(s + 'A');
    dfs(s + 'E');
    dfs(s + 'I');
    dfs(s + 'O');
    dfs(s + 'U');
}

int solution(string word) {
    dfs("");
    return m[word];
}