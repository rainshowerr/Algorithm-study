#include <string>
#include <vector>

using namespace std;

int binary_cnt(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    for (int i = n + 1; ; i++) {
        if (binary_cnt(i) == binary_cnt(n))
            return i;
    }
}