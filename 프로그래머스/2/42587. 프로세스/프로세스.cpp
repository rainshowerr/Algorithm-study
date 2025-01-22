#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<int> q; // 현재 수가 가장 큰 수인지 확인하기 위한 우선순위 큐
    
    for(auto x: priorities) {
        q.push(x);
        pq.push(x);
    }
    
    int initial_cnt = q.size();
    
    while(1) {
        // location번째 프로세스가 실행될 차례인 경우
        if (location == 0 && (q.front() == pq.top())) {
            q.pop();
            return initial_cnt - q.size();
        }
        // 맨 앞 프로세스가 실행될 차례인 경우
        if (q.front() == pq.top()) {
            q.pop();
            pq.pop();
        }
        // 맨 앞 프로세스가 실행될 차례가 아닌 경우
        else {
            int elem = q.front();
            q.pop();
            q.push(elem);
        }
        location = location == 0 ? q.size() - 1 : location - 1; // location 조정
    }
}