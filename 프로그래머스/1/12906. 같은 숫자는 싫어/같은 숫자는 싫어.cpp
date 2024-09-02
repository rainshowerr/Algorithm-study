#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int previous;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) answer.push_back(arr[i]);
        else {
            previous = arr[i - 1];
            if (previous != arr[i])
                answer.push_back(arr[i]);
        }
    }

    return answer;
}