#include <iostream>
using namespace std;
int arr[10000001];
int prime[10000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 1000001; i++) {
		arr[i] = i;
	}
	for (int i = 2; i < 1000001; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = 2; i * j < 1000001; j++)
			arr[i * j] = 0;
	}
	for (int x = 3, y=0; x < 1000001; x++) {
		if (arr[x]) {
			prime[y] = arr[x];
			y++;
		}
	}
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		for (int z = 0;z<sizeof(prime)/sizeof(int);z++) {
			if (arr[n - prime[z]]) {
				cout << n << " = " << prime[z] << " + " << arr[n - prime[z]] << '\n';
				break;
			}
			if(z==(sizeof(prime)/sizeof(int))-1)
				cout << "'Goldbach's conjecture is wrong.";
		}
		
	}
	return 0;
}