#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, line;
	cin >> x;
	int n = x;
	for(line = 1; n > 0; line++)
		n -= line;
	line--;
	int temp = 0;
	for(int i = 1; i < line; i++) temp += i;
	if (line % 2 == 0) cout << x - temp << '/' << line + 1 - (x - temp) << '\n';
	else cout << line + 1 - (x - temp) << '/' << x - temp << '\n';
	return 0;
}