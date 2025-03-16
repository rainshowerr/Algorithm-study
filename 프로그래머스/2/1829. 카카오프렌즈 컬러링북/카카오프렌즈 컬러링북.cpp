#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int mm, nn;
int max_size_of_one_area = 0, size_of_one_area = 0;

void dfs(int i, int j, int color, vector<vector<int>> &picture) {
    picture[i][j] = 0;
    size_of_one_area++;
    for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx >= mm || ny < 0 || ny >= nn) continue;
        if (picture[nx][ny] == color) dfs(nx, ny, color, picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    max_size_of_one_area = 0;
    mm = m;
    nn = n;
    for(int i = 0; i < mm; i++) {
        for(int j = 0; j < nn; j++) {
            if (picture[i][j]) {
                size_of_one_area = 0;
                number_of_area++;
                dfs(i, j, picture[i][j], picture);
                max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}