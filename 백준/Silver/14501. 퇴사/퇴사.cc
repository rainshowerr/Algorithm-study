#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0, t[15], p[15];

void go(int day, int money)
{
	if (day > n)
		return;
	if (day == n)
	{
		ans = max(money, ans);
		return;
	}
	go(day + t[day], money + p[day]); // 상담 ㄱㄱ
	go(day + 1, money); // 상담 ㄴㄴ
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		cin >> p[i];
	}
	go(0, 0);
	cout << ans;
	return 0;
}