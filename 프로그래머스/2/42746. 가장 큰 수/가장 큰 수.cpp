#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return (stoi(a + b) > stoi(b + a));
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    for(int i = 0; i < numbers.size(); i++)
        strings.push_back(to_string(numbers[i]));
    sort(strings.begin(), strings.end(), compare);
    for(int i = 0; i < strings.size(); i++)
        answer += strings[i];

    int i = 0;
    while(answer[i] == '0')
        i++;
    answer = answer.substr(i);
    if (answer == "")
        answer = "0";
    return answer;
}