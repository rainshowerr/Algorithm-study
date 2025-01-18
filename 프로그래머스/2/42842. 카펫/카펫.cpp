#include <string>
#include <vector>

using namespace std;

bool check(int row, int col, int brown, int yellow) {
    int brown_should = row * 2 + col * 2 - 4;
    int yellow_should = (row - 2) * (col - 2);
    if (brown_should == brown && yellow_should == yellow) {
        return true;
    }
    return false;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int all = brown + yellow;
    for(int row = all / 2; row >= 3; row--) {
        int col = all / row;
        if (row * col == all && check(row, col, brown, yellow)) {
            answer.push_back(row);
            answer.push_back(col);
            break;
        }
    }
    return answer;
}