#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, arr[51][51];
vector<pair<int, int>> chicken;
bool visit[13] = {false, };

// 마을 전체 치킨거리의 합
int dist() {
    int d = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (arr[i][j] == 1) {
                int minn = 1e9;
                for(int k = 0; k < chicken.size(); k++) {
                    if (!visit[k]) { // 폐업시키지 않은 치킨집이라면 거리 계산
                        minn = min(minn, abs(i - chicken[k].first) + abs(j - chicken[k].second));
                    }
                }
                d += minn;
            }
        }
    }
    return d;
}

// 폐업시킬 치킨집의 조합을 완전탐색
int minn = 1e9;
void select(int last, int cnt) { // 마지막으로 방문한 치킨집, 선택한 개수
    if (last != -1) {
        visit[last] = true;
        arr[chicken[last].first][chicken[last].second] = 0;
    }

    if (cnt == m) {
        minn = min(minn, dist());
    }

    for(int i = last + 1; i < chicken.size(); i++) {
        if (!visit[i]) {
            select(i, cnt + 1);
        }
    }

    if (last != -1) {
        visit[last] = false;
        arr[chicken[last].first][chicken[last].second] = 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) chicken.push_back({i, j});
        }
    }
    m = chicken.size() - m; // m을 폐업시킬 치킨집의 개수로 변경
    select(-1, 0);
    cout << minn;
}