#include <iostream>
using namespace std;

void swap(char* a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int check(char arr[50][50], int n)
{
	int cnt, ans = 1;
	// 행 체크
	for (int i = 0; i < n; i++)
	{
		cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
				cnt++;
			else
			{
				if (ans < cnt)
					ans = cnt;
				cnt = 1;
			}
		}
		if (ans < cnt)
			ans = cnt;
	}
	// 열 체크
	for (int j = 0; j < n; j++)
	{
		cnt = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i][j] == arr[i + 1][j])
				cnt++;
			else
			{
				if (ans < cnt)
					ans = cnt;
				cnt = 1;
			}
		}
		if (ans < cnt)
			ans = cnt;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 1;
	char arr[50][50];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// 행 바꾸기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			swap(&arr[i][j], &arr[i][j + 1]);
			if (check(arr, n) > ans)
				ans = check(arr, n);
			swap(&arr[i][j], &arr[i][j + 1]);
		}
	}
	// 열 바꾸기
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			swap(&arr[i][j], &arr[i + 1][j]);				
			if (check(arr, n) > ans)
				ans = check(arr, n);
			swap(&arr[i][j], &arr[i + 1][j]);
		}
	}
	cout << ans << '\n';
}
