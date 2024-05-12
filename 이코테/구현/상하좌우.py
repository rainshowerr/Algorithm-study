dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

size = int(input())
data = list(input().split())

nx = 1
ny = 1

for i in data:
	if i == 'L':
		if (ny + dy[2] >= 1):
			ny += dy[2]
	elif i == 'R':
		if (ny + dy[3] <= size):
			ny += dy[3]
	elif i == 'U':
		if (nx + dx[0] >= 1):
			nx += dx[0]
	elif i == 'D':
		if (nx + dx[1] <= size):
			nx += dx[1]

print(nx, ny)

# if nx < 1 or ny < 1 or nx > n or ny > n: continue로 하고 마지막에 업데이트해주면 편함