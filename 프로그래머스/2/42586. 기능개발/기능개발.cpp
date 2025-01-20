#include <string>
#include <vector>

using namespace std;

int cal_date(int progress, int speed) {
    if ((100 - progress) % speed == 0) return (100 - progress) / speed;
    else return (100 - progress) / speed + 1;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> date;

    // 남은 일수 벡터 생성
    for(int i = 0; i < progresses.size(); i++)
        date.push_back(cal_date(progresses[i], speeds[i]));

    // 앞 일수보다 적은 일수까지 전부 pop 후 answer에 추가
    while (!date.empty()) {
        int bepo_num = 1;
        int bepo_date = date.front();
        date.erase(date.begin());
        while (!date.empty() && date.front() <= bepo_date) {
            bepo_num++;
            date.erase(date.begin());
        }
        answer.push_back(bepo_num);
    }
    return answer;
}