#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

struct cmp_waiting {
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<1>(a) > get<1>(b)) return true;
        else if (get<1>(a) < get<1>(b)) return false;
        else {
            if (get<2>(a) > get<2>(b)) return true;
            else if (get<2>(a) < get<2>(b)) return false;
            else {
                if (get<0>(a) > get<0>(b)) return true;
                else return false;
            }
        }
    }
};

struct cmp_ready {
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
        if (get<2>(a) > get<2>(b)) return true;
        else if (get<2>(a) < get<2>(b)) return false;
        else {
            if (get<1>(a) > get<1>(b)) return true;
            else if (get<1>(a) < get<1>(b)) return false;
            else {
                if (get<0>(a) > get<0>(b)) return true;
                else return false;
            }
        }
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int jobs_num = jobs.size();
    int time = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp_waiting> waiting;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp_ready> ready;  // 실행 가능한 작업 큐
    
    // jobs를 waiting 큐에 삽입
    for(int i = 0; i < jobs.size(); i++)
        waiting.push(make_tuple(i, jobs[i][0], jobs[i][1]));

    
    while(!waiting.empty() || !ready.empty()) {
        // ready 큐가 차 있는 경우
        if (!ready.empty()) {
            // 작업 실행
            tuple<int, int, int> run = ready.top();
            ready.pop();
            time += get<2>(run);
            answer += time - get<1>(run);
            // 실행 가능해진 작업은 waiting 큐 -> ready 큐로 이동
            while(!waiting.empty() && time >= get<1>(waiting.top())) {
                ready.push(waiting.top());
                waiting.pop();
            }
        }
        // ready 큐가 비어있는 경우
        else {
            tuple<int, int, int> front = waiting.top(); // 대기 큐에서 하나 꺼냄
            waiting.pop();
            ready.push(front);
            time = get<1>(front); // 시간 밀어줌
        }
    }
    return answer / jobs_num;
}