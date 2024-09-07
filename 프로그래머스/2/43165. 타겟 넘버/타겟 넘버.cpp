#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int depth, int num) {
    if (depth == numbers.size()) {
        if (target == num) answer++;
        return;
    }
    
    dfs(numbers, target, depth + 1, num + numbers[depth]);
    dfs(numbers, target, depth + 1, num - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}