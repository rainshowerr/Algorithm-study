# 절단기의 높이는 0~10억 -> 큰 탐색 범위 -> 이진 탐색 떠올리기

def binary_search(tteocks, start, end):
	if start > end:
		return start - 1 # 이전 mid 가 정답.. 인데 이 방법보단 밑에서 갱신해주는 게 나을 것 같다
	mid = (start + end) // 2 # 파이썬 나눗셈은 '//'
	len = 0
	for ttheock in tteocks:
		if ttheock > mid:
			len += ttheock - mid # 잘린 떡 길이
	print(mid, len)
	if len == m: # 알맞게 잘린 경우
		return mid
	elif m > len: # 적게 잘린 경우. 기준을 줄여야함
		return search(tteocks, start, mid - 1)
	else: # 더 많이 잘린 경우. 기준을 키워야함
		return search(tteocks, mid + 1, end)

n, m = map(int, input().split())

tteocks = list(map(int, input().split()))
print(binary_search(tteocks, 0, max(tteocks) - 1))