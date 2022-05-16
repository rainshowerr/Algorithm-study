#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, arr[10], mini = 10000001;
	cin >> n;
	// 도시 배열 생성
	for (int i = 0; i < n; i++)
		arr[i] = i;
	// 비용 배열 생성
	int cost[10][10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}
	// 순열을 수정해가며 최솟값 탐색
	do {
		int temp = 0;
		int i;
		bool flag = true;
		for (i = 0; i <= n - 2; i++)
		{
			if (cost[arr[i]][arr[i + 1]] != 0)
				temp += cost[arr[i]][arr[i + 1]];
			else
			{
				flag = false;
				break;
			}
		}
		if (cost[arr[i]][arr[0]] != 0)
			temp += cost[arr[i]][arr[0]];
		else
			flag = false;
		if (flag == false)
			continue;
		mini = min(mini, temp);
	} while (next_permutation(arr, arr + n));
	cout << mini;
}