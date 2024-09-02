#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int curr = n; // 현재 단계에 가지는 병의 개수
    int exchange, remain;
    while (curr >= a) {
        exchange = curr / a * b; // 교환받는 병
        remain = curr % a; // 교환받지 못하고 남는 병
        curr = exchange + remain;
        answer += exchange; // answer에 누적합
    }
    return answer;
}