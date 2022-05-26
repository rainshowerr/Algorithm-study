#include <iostream>
#include <string.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	char board[51];
	cin >> board;
	for (int i = 0; board[i] != '\0';) {
		if (i + 3 < strlen(board) && board[i] == 'X' && board[i + 1] == 'X' && board[i + 2] == 'X' && board[i + 3] == 'X') {
			board[i] = 'A';
			board[i + 1] = 'A';
			board[i + 2] = 'A';
			board[i + 3] = 'A';
			i += 4;
		}
		else if (i + 1 < strlen(board) && board[i] == 'X' && board[i + 1] == 'X') {
			board[i] = 'B';
			board[i + 1] = 'B';
			i += 2;
		}
		else if (board[i] == '.')
			i++;
		else {
			cout << "-1";
			return 0;
		}
	}
	cout << board;
	return 0;
}