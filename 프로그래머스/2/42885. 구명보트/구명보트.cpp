#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visit[50000];

int binary_search(vector<int>& people, int max) {
    int l = 0, r = people.size() - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if (people[mid] == max) {
            ans = mid;
            l = mid + 1; // 같은 수 더 있을수도 있으므로 오른쪽도 살펴보기
        }
        else if (people[mid] < max) {
            l = mid + 1;
            ans = mid;
        }
        else if (people[mid] > max) {
            r = mid - 1;
        }
    }
    return ans;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    for(int i = people.size() - 1; i >= 0; i--) {
        if (visit[i]) continue;
        visit[i] = true; // 몸무게 가장 큰 사람 선택
        int max = binary_search(people, limit - people[i]);
        if (max != -1) {
            for(int j = max; j >= 0; j--) {
                if (visit[j]) continue;
                visit[j] = true; // 두 번째로 큰 사람 선택
                break;
            }
        }
        answer++;
    }
    return answer;
}