#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    vector<int> startday;
    
    startday.push_back(5); // 1월
    startday.push_back((startday.back() + 31) % 7); // 2월
    startday.push_back((startday.back() + 29) % 7); // 3월
    startday.push_back((startday.back() + 31) % 7); // 4월
    startday.push_back((startday.back() + 30) % 7); // 5월
    startday.push_back((startday.back() + 31) % 7); // 6월
    startday.push_back((startday.back() + 30) % 7); // 7월
    startday.push_back((startday.back() + 31) % 7); // 8월
    startday.push_back((startday.back() + 31) % 7); // 9월
    startday.push_back((startday.back() + 30) % 7); // 10월
    startday.push_back((startday.back() + 31) % 7); // 11월
    startday.push_back((startday.back() + 30) % 7); // 12월
    
    return day[(startday[a - 1] + b - 1) % 7];
}