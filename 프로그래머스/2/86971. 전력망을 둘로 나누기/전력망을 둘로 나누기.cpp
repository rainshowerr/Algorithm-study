#include <string>
#include <vector>

using namespace std;

int min_diff = 100;

void dfs(int k, vector<vector<int>> wires, bool visited[101]) {
    visited[k] = true;
    for(int i = 0; i < wires.size(); i++) {
        if (wires[i][0] == k && !visited[wires[i][1]]) {
            dfs(wires[i][1], wires, visited);
        }
        else if (wires[i][1] == k && !visited[wires[i][0]]) {
            dfs(wires[i][0], wires, visited);
        }
    }    
}

void update_min(int n, bool visited[101]) {
    int piece = 0;
    for(int i = 1; i <= n; i++) {
        if (visited[i]) piece++;
    }
    int diff;
    if (piece >= n - piece) diff = piece - (n - piece);
    else diff = (n - piece) - piece;
    if (diff < min_diff) min_diff = diff;
}

int solution(int n, vector<vector<int>> wires) {
    for(int i = 0; i < n - 1; i++) {
        vector<int> temp = wires[i];
        wires.erase(wires.begin() + i);
        bool visited[101] = {false,};
        dfs(1, wires, visited);
        update_min(n, visited);
        wires.insert(wires.begin() + i, temp);
    }
    return min_diff;
}