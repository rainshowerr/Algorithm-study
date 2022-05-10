#include <stdio.h>

int main()
{
	char str[7];
	int result = 0;
	char* hex = "0123456789ABCDEF";
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		for (int j = 0; hex[j]; j++)
		{
			if (str[i] == hex[j])
				result = 16 * result + j;
		}
	}
	printf("%d", result);
}