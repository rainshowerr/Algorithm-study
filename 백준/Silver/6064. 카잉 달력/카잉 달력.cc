#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, x, y;
	int t; cin >> t;
	while (t--)
	{
		cin >> m; cin >> n; cin >> x; cin >> y;
		int num;
		for (num = x; num <= m * n; num += m)
		{
			if (((num - x) % m == 0) && ((num - y) % n == 0))
			{
				cout << num << '\n';
				break;
			}
		}
		if (num > m * n)
			cout << "-1" << '\n';
	}
}