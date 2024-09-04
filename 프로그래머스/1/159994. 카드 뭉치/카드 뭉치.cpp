#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int i = 0, j = 0;
    for (int k = 0; k < goal.size(); k++) {
        if (goal[k] == cards1[i]) i++;
        else if (goal[k] == cards2[j]) j++;
        else return "No";
    }
    return "Yes";
}