#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> answer;
    
    for (int i = 0; i < score.size(); i++) {
        if (pq.size() < k) pq.push(score[i]);
        else if (score[i] > pq.top()){
            pq.pop();
            pq.push(score[i]);
        }
        answer.push_back(pq.top());
    }
    
    return answer;
}