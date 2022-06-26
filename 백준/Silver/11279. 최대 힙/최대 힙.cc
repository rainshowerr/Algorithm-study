#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, less<int>> q;
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if (x == 0) {
            if (q.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << q.top() << '\n';
            q.pop();
        }
        else
            q.push(x);
    }
}