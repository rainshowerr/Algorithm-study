#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>> q;
    for(int i = 1; i <= 5; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        q.push({ a + b + c + d, i });
    }
    cout << q.top().second << ' ' << q.top().first << '\n';
}