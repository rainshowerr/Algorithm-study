#include <iostream>
#include <string>
using namespace std;

int ans[9];

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
		ans[idx] = i;
		go(idx + 1, n, m);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m; cin >> n; cin >> m;
	go(1, n, m);
}