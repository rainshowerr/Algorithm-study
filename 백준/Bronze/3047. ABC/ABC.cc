#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int num[3];
	string str;
	cin >> num[0] >> num[1] >> num[2];
	sort(&num[0], &num[3]);
	cin >> str;
	for(int i = 0; i < str.length(); i++) {
		if (str[i] == 'A') cout << num[0] << ' ';
		else if (str[i] == 'B') cout << num[1] << ' ';
		else if (str[i] == 'C') cout << num[2] << ' ';
	}
}