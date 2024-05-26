#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    int min = 2147483647, max = -2147483648;
    stringstream ss(s);
    string strnum;
    while (ss >> strnum) {
        if (stoi(strnum) > max)
            max = stoi(strnum);
        if (stoi(strnum) < min)
            min = stoi(strnum);
    }
    return to_string(min) + " " + to_string(max);
}