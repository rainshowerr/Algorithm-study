using namespace std;

int d[2001];

int solution(int n) {
    d[0] = 1;
    d[1] = 1;
    for(int i = 2; i <= n; i++) {
        d[i] = (d[i - 1] + d[i - 2]) % 1234567;
    }
    return d[n];
}