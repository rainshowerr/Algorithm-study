#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, max_n = 0, arr[8];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	do {
		int temp = 0;
		for (int i = 0; i <= n - 2; i++)
			temp += abs(arr[i] - arr[i + 1]);
		max_n = max(max_n, temp);
	} while (next_permutation(arr, arr + n));
	cout << max_n;
}
