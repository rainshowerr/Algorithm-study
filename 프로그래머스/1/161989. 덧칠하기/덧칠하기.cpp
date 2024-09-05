#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, i, j;
    for(i = 0; i < section.size(); ) {
        for(j = i + 1; j < section.size(); j++) {
            int chill = section[j] - section[i] + 1;
            if (chill > m) break;
        }
        answer++;
        i = j;
    }
    return answer;
}