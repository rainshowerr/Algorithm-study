#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool sorting(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}
	sort(v.begin(), v.end(), sorting);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) {
		if (!q.empty() && q.top() <= v[i].first) {
			q.pop();
		}
		q.push(v[i].second);
	}
	cout << q.size();
}