#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, m, nbr = 1, map[1001][1001], numbering[1001][1001], ans[1001][1001] = { 0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> zero_size;

void bfs(int x, int y){
	queue<pair<int,int>> q;
	int cnt = 0; // 0 개수
	q.push({x, y});
	numbering[x][y] = nbr; 
	cnt++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && numbering[nx][ny] == 0 && map[nx][ny] == 0){
				q.push({nx, ny});
				numbering[nx][ny] = nbr;
				cnt++;
			}
		}
	}
	zero_size.push_back(cnt); // 그룹당 0 개수를 벡터에 넣어주기
	nbr++; // 그룹 번호 (1번부터 시작)
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	// 0인 그룹 넘버링
	zero_size.push_back(0); // 1번부터 넘버링 시작하니까 벡터도 한칸 밀어주기
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			if (map[i][j] == 0 && numbering[i][j] == 0)
				bfs(i, j);
		}
	}
	// 상하좌우에서 갈 수 있는 영역 개수 체크해서 ans 배열에 넣기
	set<int> s; // 같은 그룹을 중복해서 방문하지 않기 위해 set 사용
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (map[i][j] == 0) continue;
			ans[i][j] = 1; // 자기 자신 영역 포함
			for(int k = 0; k < 4; k++){
				int x = i + dx[k];
				int y = j + dy[k];
				if (0 <= x && x < n && 0 <= y && y < m && numbering[x][y] != 0)
					s.insert(numbering[x][y]);
			}
			for(auto a : s)
				ans[i][j] += zero_size[a];
			s.clear();
		}
	}
	// 출력
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			printf("%d", ans[i][j] % 10);
		printf("\n");
	}
	return 0;
}