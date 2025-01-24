#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int, vector<int>, less<>> max_heap;
    unordered_map<int, int> count; // 삭제된 값을 추적하기 위한 맵
    
    // I
    for(string s: operations) {
        stringstream ss(s);
        string op, num;
        ss >> op >> num;
        int n = stoi(num);

        if (op == "I") {
            min_heap.push(n);
            max_heap.push(n);
            count[n]++;
        }
        // D -1
        else if (op == "D" && n == -1) {
            while (!min_heap.empty() && count[min_heap.top()] == 0) // 삭제된 값이라면 지워줌
                min_heap.pop();
            if (!min_heap.empty()) {
                int minn = min_heap.top();
                min_heap.pop();
                count[minn]--;
            }
        }
        // D 1
        else if (op == "D" && n == 1) {
            while (!max_heap.empty() && count[max_heap.top()] == 0) // 삭제된 값이라면 지워줌
                max_heap.pop();
            if (!max_heap.empty()) {
                int maxx = max_heap.top();
                max_heap.pop();
                count[maxx]--;
            }
        }
    }

    while (!min_heap.empty() && count[min_heap.top()] == 0)
        min_heap.pop();
    while (!max_heap.empty() && count[max_heap.top()] == 0)
        max_heap.pop();
    
    if (min_heap.empty() || max_heap.empty()) return {0, 0};
    else return {max_heap.top(), min_heap.top()};
}