#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    for(int i = 0; i < tangerine.size(); i++) {
        m[tangerine[i]]++;
    }
    vector<pair<int,  int>> v(m.begin(), m.end()); // map -> vector 변환
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        k -= v[i].second;
        answer++;
        if (k <= 0) return answer;
    }
}