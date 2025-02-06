#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    priority_queue<int, vector<int>, less<int> > max_pq; // 왼
    priority_queue<int, vector<int>, greater<int> > min_pq; // 오
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        // 왼쪽이 비어있으면 왼쪽에 추가
        if (max_pq.empty()) {
            max_pq.push(num);
        }
        // 오쪽이 비어있거나, 오탑보다 작거나 같다면 왼쪽 추가
        else if (min_pq.empty() || (!min_pq.empty() && num <= min_pq.top())) {
            max_pq.push(num);
        }
        // 오탑보다 크다면 오쪽 추가
        else {
            min_pq.push(num);
        }
        
        // 지각변동
        if (max_pq.size() > min_pq.size() + 1) { // 왼사이즈 > 오사이즈 + 1이면 왼탑 팝 후 오추
            int temp = max_pq.top();
            max_pq.pop();
            min_pq.push(temp);
        }
        else if (max_pq.size() < min_pq.size()) { // 왼사이즈 < 오사이즈이면 오탑 팝 후 왼추
            int temp = min_pq.top();
            min_pq.pop();
            max_pq.push(temp);
        }
        cout << max_pq.top() << '\n';
    }
}