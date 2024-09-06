#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> tryNum;
vector<int> failNum;

bool compare(int a, int b) {
    double failRateA = tryNum[a] == 0 ? 0 : (double)failNum[a] / tryNum[a];
    double failRateB = tryNum[b] == 0 ? 0 : (double)failNum[b] / tryNum[b];
    if (failRateA == failRateB) return a < b;
    return failRateA > failRateB;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    for(int i = 1; i <= N; i++)
        answer.push_back(i);
    tryNum.assign(N + 1, 0);
    failNum.assign(N + 1, 0);

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < stages.size(); j++) {
            if (i <= stages[j]) tryNum[i]++;
            if (stages[j] == i) failNum[i]++;
        }
    }
    sort(answer.begin(), answer.end(), compare);
    return answer;
}