from bisect import bisect_left, bisect_right

n, x = map(int, input().split())
data = list(map(int, input().split()))

# 라이브러리 이용
cnt = bisect_right(data, x) - bisect_left(data, x)
if cnt == 0:
	print(-1)
else:
	print(cnt)
