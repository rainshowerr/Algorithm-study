#include <iostream>
#include <vector>
#include <functional>
#include <queue>

#define INT_MAX 2147483647

using namespace std;

vector<int> sosu;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        int s;
        cin >> s;
        sosu.push_back(s);
        pq.push(s);
    }

	int top;
	int cnt = 0;
    int prev_top = 0;
    while(cnt < n) {
        top = pq.top();
        pq.pop();
        if (top == prev_top)
            continue;
        for(int i = 0; i < sosu.size(); i++) {
            long long s = (long long)sosu[i] * top;
            if (s <= INT_MAX)
                pq.push(s);
        }
		cnt++;
        prev_top = top;
    }
	cout << top;
}