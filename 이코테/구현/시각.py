# n = int(input())
# if (n >= 23):
# 	res = 3*60*60 + (n-2)*(15*60 + 45*15)
# elif (n >= 13):
# 	res = 2*60*60 + (n-1)*(15*60 + 45*15)
# elif (n >= 3):
# 	res = 1*60*60 + (n)*(15*60 + 45*15)
# else:
# 	res = (n+1)*(15*60 + 45*15)
# print(res)

# 위처럼 직접 계산하지말고 밑처럼풀자,,

n = int(input())
count=0
for i in range(n+1):
	for j in range(60):
		for k in range(60):
			if '3' in str(i) + str(j) + str(k):
				count += 1
print(count)