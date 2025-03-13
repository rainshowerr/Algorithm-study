#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 최소공배수 = 두 수의 곱 / 최대공약수

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solution(vector<int> arr) {
    int answer = 1;
    for(int i = 0; i < arr.size(); i++) {
        answer = answer * arr[i] / gcd(answer, arr[i]);
    }
    return answer;
}