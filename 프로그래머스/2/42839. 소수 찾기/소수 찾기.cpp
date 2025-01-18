#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int number) {
    if (number == 0 || number == 1) return false;
    for(int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> primes;

    for(int i = 1; i <= numbers.length(); i++) {
        sort(numbers.begin(), numbers.end());
        do {
            int temp = stoi(numbers.substr(0, i));
            if (is_prime(temp) && \
                find(primes.begin(), primes.end(), temp) == primes.end()) {
                primes.push_back(temp);
                answer++;
            }
        } while (next_permutation(numbers.begin(), numbers.end()));
    }
    return answer;
}