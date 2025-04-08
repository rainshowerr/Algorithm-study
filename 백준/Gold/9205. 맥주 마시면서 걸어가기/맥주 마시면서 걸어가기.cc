#include <iostream>
#include <vector>

using namespace std;

struct loc {
    int x;
    int y;
};

vector<loc> v; // 편의점 + goal
bool flag;

int beer_consume(loc a, loc b) {
	int dist = abs(a.x - b.x) + abs(a.y - b.y);
    return dist % 50 == 0 ? dist / 50 : dist / 50 + 1;
}

void dfs(int num, int beer, bool visited[]) {
	visited[num] = true;
	if (num == v.size() - 1) {
		flag = true;
		return;
	}
	for(int i = 0; i < v.size(); i++) {
		if (visited[i]) continue;
		if (beer_consume(v[num], v[i]) <= 20) {
			dfs(i, 20 - beer_consume(v[num], v[i]), visited);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, a, b;
    cin >> t;
    while(t--) {
		loc home, goal;
		bool visited[101] = {false,};
		flag = false;
        cin >> n;
        cin >> home.x >> home.y;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back({a, b});
        }
        cin >> goal.x >> goal.y;
        v.push_back(goal);

        for(int i = 0; i < v.size(); i++) {
			if (beer_consume(home, v[i]) <= 20) {
				dfs(i, 20 - beer_consume(home, v[i]), visited);
			}
		}
		v.clear();
		if (flag) cout << "happy\n";
		else cout << "sad\n";
    }
}