#include <iostream>
#include <math.h>
using namespace std;

bool check(int k, int arr[])
{
    if (k == 0)
    {
        for(int i = 0; arr[i] != -1; i++)
        {
            if (k == arr[i])
            return false;
        }
    }
    while(k > 0)
    {
        for(int i = 0; arr[i] != -1; i++)
        {
            if (k % 10 == arr[i])
                return false;
        }
        k /= 10;
    }
    return true;
}

int numlen(int k)
{
    int i = 0;
    if (k == 0)
        return 1;
    while(k > 0)
    {
        i++;
        k = k / 10;
    }
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n; cin >> n;
    int broken; cin >> broken;
    int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int mini = abs(100 - n);
    for(int i = 0; i < broken; i++)
        cin >> arr[i];
    for(int nb = 0; nb <= 1000000; nb++)
    {
        if (check(nb, arr))
           mini = min(mini, abs(n - nb) + numlen(nb));
    }
    cout << mini;
}