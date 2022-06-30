#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    else {
        int a_sum = 0, b_sum = 0;
        for(int i = 0; a[i]; i++) {
            if ('1' <= a[i] && a[i] <= '9') a_sum += a[i] - '0';
        }
        for(int i = 0; b[i]; i++) {
            if ('1' <= b[i] && b[i] <= '9') b_sum += b[i] - '0';
        }
        if (a_sum != b_sum) {
            return a_sum < b_sum;
        }
        else
            return a < b;
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<string> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    stable_sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << v[i] << '\n';
}