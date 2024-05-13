def dfs(x, y):
	if x < 0 or x > n - 1 or y < 0 or y > m - 1:
		return False
	if graph[x][y] == 0:
		graph[x][y] = 1
		dfs(x - 1, y)
		dfs(x + 1, y)
		dfs(x, y - 1)
		dfs(x, y + 1)
		return True
	return False

n, m = map(int, input().split())
graph = [] # 빈 리스트 선언
for i in range(n):
	graph.append(list(map(int, input())))

res = 0
for i in range(n):
	for j in range(m):
		if dfs(i, j) == True:
			res += 1

print(res)
