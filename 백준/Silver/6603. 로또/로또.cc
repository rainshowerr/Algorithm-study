#include <iostream>
#include <algorithm>

using namespace std;

void go(int idx, int n, int arr[], int ans[])
{
	if (idx == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > ans[idx - 1])
		{
			ans[idx] = arr[i];
			go(idx + 1, n, arr, ans);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int arr[12], ans[6];
	while (1)
	{
		int n; cin >> n;
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		for (int i = 0; i < n; i++)
		{
			ans[0] = arr[i];
			go(1, n, arr, ans);
		}
		cout << '\n';
	}
	return 0;
}