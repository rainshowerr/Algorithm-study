n = input()
arr = list(map(int, input().split()))
arr.sort()
res = 0
cnt = 0
for i in arr:
	cnt += 1
	if (cnt >= i) # 공포도 충족
		res += 1
		count = 0
print(res)