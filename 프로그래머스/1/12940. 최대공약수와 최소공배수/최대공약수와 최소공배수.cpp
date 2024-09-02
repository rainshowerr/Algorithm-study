#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int big = max(n, m), small = min(n, m);
    for(int r = big % small; r; big = small, small = r, r = big % small);
    int gcd = small;
    answer.push_back(gcd);
    answer.push_back(n * m / gcd);
    return answer;
}