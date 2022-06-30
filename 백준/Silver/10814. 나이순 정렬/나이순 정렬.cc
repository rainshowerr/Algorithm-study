#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<pair<int, string>> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({age, name});
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}