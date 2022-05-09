#include <stdio.h>

int e_check(int e, int n)
{
	if ((n - e) % 15 == 0)
		return 1;
	return 0;
}

int s_check(int s, int n)
{
	if ((n - s) % 28 == 0)
		return 1;
	return 0;
}

int m_check(int m, int n)
{
	if ((n - m) % 19 == 0)
		return 1;
	return 0;
}

int main()
{
	int e, s, m;
	scanf("%d", &e);
	scanf("%d", &s);
	scanf("%d", &m);
	int n = 1;
	while (1)
	{
		if (e_check(e, n) && s_check(s, n) && m_check(m, n))
		{
			printf("%d", n);
			break;
		}
		n++;
	}
	return 0;
}