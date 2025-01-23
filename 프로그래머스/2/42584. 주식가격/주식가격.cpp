#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--) {
        // 스택에서 현재 가격보다 큰 값 제거
        while (!s.empty() && prices[i] <= prices[s.top()]) {
            s.pop();
        }

        // 가격이 떨어진 시점 계산
        if (!s.empty()) {
            answer[i] = s.top() - i;
        } else {
            answer[i] = n - 1 - i;
        }

        s.push(i);
    }
    return answer;
}