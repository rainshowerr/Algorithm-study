#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int	check(int idx, int num, int chess[])
{
	int	p_idx;

	p_idx = 0;
	while (p_idx < idx)
	{
		if (chess[p_idx] == num)
			return (0);
		else if (chess[p_idx] + p_idx == num + idx)
			return (0);
		else if (chess[p_idx] - p_idx == num - idx)
			return (0);
		p_idx++;
	}
	return (1);
}

void	ft_reculsive(int idx, int n, int chess[], int* casenum)
{
	int		num;

	if (idx == n)
	{
		(*casenum)++;
		return;
	}
	num = -1;
	while (++num < n)
	{
		if (check(idx, num, chess))
		{
			chess[idx] = num;
			ft_reculsive(idx + 1, n, chess, casenum);
		}
	}
}

int	ft_ten_queens_puzzle(int n)
{
	int	i;
	int	chess[15];
	int	casenum;

	casenum = 0;
	i = 0;
	while (i < n)
	{
		chess[0] = i;
		ft_reculsive(1, n, chess, &casenum);
		i++;
	}
	return (casenum);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", ft_ten_queens_puzzle(n));
}