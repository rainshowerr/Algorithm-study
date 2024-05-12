loc = input()
x = ord(loc[0]) - ord('a') + 1 # 아스키코드 변환!
y = int(loc[1])

dx = [-1, -1, 1, 1, 2, 2]
dy = [-2, 2, -2, 2, -1, 1]

res = 0
for i in range(6):
	nx = x + dx[i]
	ny = y + dy[i]
	if (1 <= nx <= 8 and 1 <= ny <= 8):
		res += 1

print(res)