#include <iostream>
using namespace std;

int arr[128][128];
int white = 0, blue = 0;

void go(int n, int x, int y) {
	bool flag = true;
	int color = arr[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[i][j] != color) {
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (!flag) {
		go(n / 2, x, y);
		go(n / 2, x, y + n / 2);
		go(n / 2, x + n / 2, y);
		go(n / 2, x + n / 2, y + n / 2);
	}
	else if (flag && color == 0)
		white++;
	else if (flag && color == 1)
		blue++;
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	go(n, 0, 0);
	cout << white << '\n' << blue << '\n';
}