#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for(auto x : scoville)
        pq.push(x);
    while(pq.size() >= 2 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    if (pq.top() < K)
        return -1;
    return answer;
}