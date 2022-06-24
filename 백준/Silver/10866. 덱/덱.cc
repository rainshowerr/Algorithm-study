#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    deque<int> d;
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int x; cin >> x;
            d.push_front(x);
        }
        else if (s == "push_back") {
            int x; cin >> x;
            d.push_back(x);
        }
        else if (s == "pop_front") {
            if (!d.empty()) {
                cout << d.front() << '\n';
                d.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if (s == "pop_back") {
            if (!d.empty()) {
                cout << d.back() << '\n';
                d.pop_back();
            }
            else
                cout << -1 << '\n';
        }
        else if (s == "size")
            cout << d.size() << '\n';
        else if (s == "empty") {
            if (d.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (s == "front") {
            if (!d.empty()) cout << d.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (s == "back") {
            if (!d.empty()) cout << d.back() << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}