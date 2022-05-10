#include <stdio.h>
#include <string.h>

int main()
{
    int n, len, i, j;
    int flag;
    char arr[51][51];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%s", arr[i]);
    len = strlen(arr[0]);
    for(j = 0; j < len; j++)
    {
        flag = 1;
        for(i = 0; i < n; i++)
        {
            if (arr[0][j] != arr[i][j])
            {
                printf("?");
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%c", arr[--i][j]);
    }
}