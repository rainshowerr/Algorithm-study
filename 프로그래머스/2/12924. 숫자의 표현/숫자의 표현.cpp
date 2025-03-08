#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0, l = 1, r = 1, sum = 1;
    while(l <= r) {
        if (sum < n) {
            sum += ++r;
        }
        else if (sum > n) {
            sum -= l++;
        }
        else {
            answer++;
            sum += ++r;
        }
    }
    return answer;
}