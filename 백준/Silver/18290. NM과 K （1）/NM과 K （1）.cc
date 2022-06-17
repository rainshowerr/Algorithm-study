#include <iostream>
using namespace std;

int n, m, k, maximum = -2147483648, num[10][10];
bool visited[10][10] = { false, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void go(int x, int y, int choice){
    if (choice == k){
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (visited[i][j])
                   sum += num[i][j]; 
            }
        }
        maximum = max(maximum, sum);
        return;
    }
    // 시간초과를 피하기 위해 i는 x부터 시작
    for(int i = x; i < n; i++){
        for(int j = 0; j < m; j++){
            if (!visited[i][j]){
               if (i >= 1 && visited[i - 1][j]) continue;
               if (i < n - 1 && visited[i + 1][j]) continue;
               if (j >= 1 && visited[i][j - 1]) continue;
               if (j < m - 1 && visited[i][j + 1]) continue;
               visited[i][j] = true;
               go(i, j, choice + 1);
               visited[i][j] = false;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> num[i][j];
    go(0, 0, 0);
    cout << maximum;
}