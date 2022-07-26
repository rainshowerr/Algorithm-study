#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int score[5], sum = 0, i = 0;
    cin >> score[0] >> score[1] >> score[2] >> score[3] >> score[4];
    while(i < 5) {
        if (score[i] < 40)
            score[i] = 40;
        sum += score[i];
        i++;
    }
    cout << (double)sum / 5;
}