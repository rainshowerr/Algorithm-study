#include <iostream>
#include <string>
using namespace std;

int ans[9];
bool check[9];

void go(int idx, int n, int m)
{
	if (idx > m)
	{
		for (int i = 1; i <= m; i++)
		{
			cout << ans[i];
			if (i != m)
				cout << ' ';
			else
			{
				cout << '\n';
				return;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == true)
		{
			ans[idx] = i;
			check[i] = false;
			go(idx + 1, n, m);
			check[i] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m; cin >> n; cin >> m;
	for (int i = 1; i <= n; i++)
		check[i] = true;
	go(1, n ,m);
}