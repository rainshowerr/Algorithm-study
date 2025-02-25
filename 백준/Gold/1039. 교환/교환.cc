#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int k, s_len, maxx = 0;
bool visit[1000001][11]; // j단계에 i를 방문했는지 여부를 저장
queue<pair<string, int>> q; // {string, cnt}

void bfs(string s, int cnt) {
    q.push({s, cnt});
    visit[stoi(s)][cnt] = true;
    while (q.empty() == false) {
        string curr_str = q.front().first;
        int curr_cnt = q.front().second;
        q.pop();
        if (curr_cnt == k) {
            maxx = max(maxx, stoi(curr_str));
            continue;
        }
        for(int i = 0; i < curr_str.length(); i++) {
            for(int j = i + 1; j < curr_str.length(); j++) {
                swap(curr_str[i], curr_str[j]);
                if (!visit[stoi(curr_str)][curr_cnt + 1] && to_string(stoi(curr_str)).length() == s_len) { // 이미 방문한 노드가 아니고 자릿수가 달라지지 않으면 push
                    q.push({curr_str, curr_cnt + 1});
                    visit[stoi(curr_str)][curr_cnt + 1] = true;
                }
                swap(curr_str[i], curr_str[j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s >> k;
    s_len = s.length();
    bfs(s, 0);
    if (maxx == 0) cout << -1;
    else cout << maxx;
}