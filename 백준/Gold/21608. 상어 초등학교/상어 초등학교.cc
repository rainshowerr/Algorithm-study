#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> order;
vector<int> likes[401];
int jido[21][21] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef struct {
    int x;
    int y;
    int like;
    int empty;
} jari;

struct compare {
    bool operator()(const jari a, const jari b) {
        if (a.like == b.like) {
            if (a.empty == b.empty) {
                if (a.x == b.x) {
                    return a.y > b.y;
                }
                return a.x > b.x;
            }
            return a.empty < b.empty;
        }
        return a.like < b.like;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n * n; i++) {
        int a, b;
        cin >> a;
        order.push_back(a);
        for(int j = 0; j < 4; j++) {
            cin >> b;
            likes[a].push_back(b);
        }
    }

    for(int s = 0; s < order.size(); s++) {
        int student = order[s]; // 자리를 정할 학생 번호
        priority_queue<jari, vector<jari>, compare> pq;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (jido[i][j]) continue;
                // 상하좌우대각선으로 like, empty 개수 체크
                int l = 0, e = 0;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    for(int ll = 0; ll < 4; ll++) {
                        if (jido[nx][ny] == likes[student][ll]) l++; 
                    }
                    if (jido[nx][ny] == 0) e++;
                }
                jari temp;
                temp.x = i;
                temp.y = j;
                temp.like = l;
                temp.empty = e;
                pq.push(temp);
            }
        }
        jari choice = pq.top();
        // cout << choice.x << ' ' << choice.y << ' ' << choice.like << ' ' << choice.empty << '\n';
        jido[choice.x][choice.y] = student;
    }
    // 만족도 구하기
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int happy = 0;
            int student = jido[i][j];
            // cout << student << ' ';
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                for(int ll = 0; ll < 4; ll++) {
                    if (jido[nx][ny] == likes[student][ll]) happy++;
                }
            }
            if (happy == 1) ans += 1;
            else if (happy == 2) ans += 10;
            else if (happy == 3) ans += 100;
            else if (happy == 4) ans += 1000;
        }
        // cout << '\n';
    }
    cout << ans;
}