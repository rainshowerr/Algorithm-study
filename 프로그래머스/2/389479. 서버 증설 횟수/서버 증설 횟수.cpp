#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    vector<int> servers(players.size(), 0);
    int answer = 0;
    for(int i = 0; i < players.size(); i++) {
        while(players[i] >= (servers[i] + 1) * m) {
            answer++;
            for(int j = i; j < i + k && j < servers.size(); j++)
                servers[j]++;
        }
        
    }
    return answer;
}