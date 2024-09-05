#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int divisor(int num) {
    set<int> divisors;
    for(int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0)
            divisors.insert(i);
    }
    for(auto div : divisors){
	    if (num % div == 0)
            divisors.insert(num / div);
    }
    return divisors.size();
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++) {
        if (divisor(i) <= limit) answer += divisor(i);
        else answer += power;
    }
    return answer;
}