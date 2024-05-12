str = input()
res = int(str[0])
for i in range(1, len(str)):
	num = int(str[i])
	if (res <= 1 or num <= 1):
		res += num
	else:
		res *= num
print(res)

# 두 수 중 하나라도 '1'인 경우에도 곱하기보다 더하기를 수행하는 게 효율적