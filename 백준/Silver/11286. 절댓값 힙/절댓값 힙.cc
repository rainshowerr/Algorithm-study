#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, cmp> q;
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