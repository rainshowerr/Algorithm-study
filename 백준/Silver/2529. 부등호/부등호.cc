#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int k; char arr[9], ans[10], mini[11], maxi[11]; bool check[10];

void go(int index)
{
	if (index == k + 1)
	{
		if (strcmp(mini, ans) > 0)
			strcpy(mini, ans);
		if (strcmp(maxi, ans) < 0)
			strcpy(maxi, ans);
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if ((check[i] == true) 
			&& ((arr[index - 1] == '<') && (i + '0' > ans[index - 1])
			|| ((arr[index - 1] == '>') && (i + '0' < ans[index - 1]))))
		{
			ans[index] = i + '0';
			check[i] = false;
			go(index + 1);
			check[i] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> k;
	strcpy(mini, "9999999999");
	strcpy(maxi, "0");
	for (int i = 0; i < 10; i++)
		check[i] = true;
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	for (int i = 0; i < 10; i++)
	{
		check[i] = false;
		ans[0] = i + '0';
		go(1);
		check[i] = true;
	}
	cout << maxi << '\n';
	cout << mini << '\n';
}