#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, bool> > con; // 내구도, 로봇 존재 여부

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        con.push_back(make_pair(a, false));
    }
    for(int t = 1; ; t++) {
        // 컨베이어 벨트, 로봇 한 칸씩 옮기기
        pair<int, bool> temp;
        temp = con.back();
        con.pop_back();
        con.insert(con.begin(), temp);
        con[n-1].second = 0; // 내리는칸 로봇 내리기

        // (가능하다면) 로봇 한 칸 옮기기
        for(int i = n - 2; i >= 1; i--) {
            if (con[i].second == true && \
                con[i + 1].first >= 1 && con[i + 1].second == false) {
                con[i + 1].second = true;
                con[i].second = false;
                con[i + 1].first--;
            }
        }
        con[n-1].second = 0; // 내리는칸 로봇 내리기

        // 새로운 로봇 올리기
        if (con[0].first != 0) {
            con[0].second = true;
            con[0].first--;
        }

        // 내구도 확인 및 종료
        int cnt = 0;
        for(int i = 0; i < 2 * n; i++) {
            if (con[i].first == 0) cnt++;
        }
        if (cnt >= k) {
            cout << t;
            return 0;
        }
    }
}