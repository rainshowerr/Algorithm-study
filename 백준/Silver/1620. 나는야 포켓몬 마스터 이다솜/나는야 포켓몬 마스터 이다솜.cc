#include <iostream>
#include <unordered_map>
#include <ctype.h>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	unordered_map<string, int> map;
	int n, m;
	string number[100001];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string poke;
		cin >> poke;
		map[poke] = i;
		number[i] = poke;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (isdigit(s[0]))
			cout << number[stoi(s)] << '\n';
		else
			cout << map[s] << '\n';
	}
}