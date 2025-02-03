#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt;
int visitY[17];
int visitR[35]; // '합'이므로 범위가 2배가됨
int visitL[35]; // '차'이므로 음수 방지

//   1 2 3 4
// 1 o     x
// 2   o x
// 3   x o
// 4 x     o
// ↘ 대각선 (visitL)은 row-col이 같음
// ↙ 대각선 (visitR)은 row+col이 같음

void back(int x)
{
    int i;

    if (x == n + 1)
    {
        cnt++;
        return;
    }

    for (i = 1; i <= n; i++)
    {
        if (visitY[i] == 0 && visitR[x + i] == 0 && visitL[x - i + n] == 0)
        {
            visitY[i] = 1;
            visitR[x + i] = 1;
            visitL[x - i + n] = 1; // 음수 인덱스 방지
            back(x + 1);
            visitY[i] = 0;
            visitR[x + i] = 0;
            visitL[x - i + n] = 0;
        }
    }
}

int main()
{
    cin >> n;
    back(1);
    cout << cnt;

    return 0;
}