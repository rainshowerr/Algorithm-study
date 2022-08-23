#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k, a[10000][2];
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			cin >> a[i][j];
		}
	}
	cout << "비와이";
}