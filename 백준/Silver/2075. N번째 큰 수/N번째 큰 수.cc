#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int k;
            cin >> k;
            if (q.size() < n)
                q.push(k);
            else if (k > q.top()) {
                q.pop();
                q.push(k);
            }
        }
    }
    cout << q.top() << '\n';
}