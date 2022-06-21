#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans = 0;
    vector<pair<int, int>> v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    int temp = v[0].second;
    ans++;
    for(int i = 1; i < n; i++) {
        if (v[i].first >= temp) {
            temp = v[i].second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}