#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int current_weight = 0;
    queue<int> bridge;

    // bridge를 [-1, -1, -1 ...]로 채움
    for(int i = 0; i < bridge_length; i++)
        bridge.push(-1);
    
    // 대기 트럭이 없고 bridge가 -1로 채워질 때까지 반복
    while(!(truck_weights.empty() && current_weight == 0)) {
        // 1초마다 bridge pop
        if (bridge.front() != -1) // -1이라면 빈 공간이므로 무게에 포함x
            current_weight -= bridge.front();
        bridge.pop();

        // 대기 트럭이 있고 다리를 건널 수 있다면 bridge에 넣음
        if (!truck_weights.empty() && current_weight + truck_weights.front() <= weight) {
            bridge.push(truck_weights.front());
            current_weight += truck_weights.front();
            truck_weights.erase(truck_weights.begin()); // 대기 트럭 벡터에서 삭제
        }
        // 대기 트럭이 없거나 다리를 건널 수 없다면 -1을 bridge에 넣음
        else
            bridge.push(-1);
        time++;
    }
    return time;
}