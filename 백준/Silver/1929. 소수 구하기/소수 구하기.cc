#include <iostream>
using namespace std;
int arr[1000000];
int main() {
	int a, b;
	cin >> a; cin >> b;
	for (int i = 0; i < b + 1; i++) {
		arr[i] = i;
	}
	arr[1] = 0;
	for (int i = 2; i < b + 1; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = 2; i*j<=b; j+=1)
			arr[i*j] = 0;
	}
	for (int i = a; i < b + 1; i++) {
		if (arr[i] != 0)
			cout << arr[i]<< ' ';
	}
	return 0;
}