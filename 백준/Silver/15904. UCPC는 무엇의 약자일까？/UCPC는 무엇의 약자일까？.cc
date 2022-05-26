#include <iostream>
#include <string>
using namespace std;

int main() {
	char UCPC[4] = { 'U', 'C', 'P', 'C'};
	string str;
	getline(cin, str);
	int i, j = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == UCPC[j]) {
			j++;
			if (j == 4) {
				cout << "I love UCPC";
				return 0;
			}
		}
	}
	cout << "I hate UCPC";
}