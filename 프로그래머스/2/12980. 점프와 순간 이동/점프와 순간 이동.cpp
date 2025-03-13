#include <iostream>
using namespace std;
int solution(int n)
{
    int ans = 0;
    if (n == 0) return 0;
    if (n % 2 == 1) {
        ans = solution(n / 2) + 1;
    }
    else {
        ans = solution(n / 2);
    }
    return ans;
}