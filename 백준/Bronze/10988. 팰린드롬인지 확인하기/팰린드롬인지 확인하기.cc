#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string word;
    cin >> word;
    int i = 0, j = word.length() - 1;
    while (i < j) {
        if (word[i] != word[j]) {
            cout << 0;
            return 0;
        }
        i++;
        j--;
    }
    cout << 1;
}