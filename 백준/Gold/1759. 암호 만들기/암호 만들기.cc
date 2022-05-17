#include <iostream>
#include <algorithm>
using namespace std;

char arr[16], ans[16];
int l, c;

void go(int idx, int mo, int ja)
{
	if ((idx == l) && (mo >= 1) && (ja >= 2))
	{
		for (int i = 0; i < l; i++)
			cout << ans[i];
		cout << '\n';
		return;
	}
	for (int i = 0; i < c; i++)
	{
		if (ans[idx - 1] < arr[i])
		{
			ans[idx] = arr[i];
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				go(idx + 1, mo + 1, ja);
			else
				go(idx + 1, mo, ja + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> l; cin >> c;
	int i;
	for (i = 0; i < c; i++)
		cin >> arr[i];
	sort(arr, arr + c);
	arr[i] = '\0';
	for (int i = 0; i < c; i++)
	{
		ans[0] = arr[i];
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			go(1, 1, 0);
		else
			go(1, 0, 1);
	}
}