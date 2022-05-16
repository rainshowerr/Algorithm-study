#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	int arr[10000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (prev_permutation(&arr[0], &arr[n]))
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i];
			if (i != n - 1)
				cout << ' ';
		}
	}
	else
		cout << "-1";
}